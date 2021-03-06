#include "headers.h"
#include "tree_Folder.h"

#include <numeric>

#ifdef _DEBUG
#define new DBG_NEW
#endif

using namespace tree;

tree::Size Folder::Size(bool bFollow, bool bRecursive) const
{
	return std::accumulate(
		_content.begin(),
		_content.end(),
		.0,
		[bFollow, bRecursive](tree::Size size, auto & node)
	{
		auto * folder = dynamic_cast<const Folder*>(node.get());

		if (folder)
		{
			return size + (bRecursive ? folder->Size(bFollow, bRecursive) : 0.);
		}
		else
		{
			return size + node->Size(bFollow, bRecursive);
		}
	}
	);
}

void Folder::List(bool bFollow, bool bRecursive, const std::string & offset, std::ostream & out) const
{
	out << "[" << Name() << "]" << std::endl;
	for (auto & node : _content)
	{
		auto * folder = dynamic_cast<const Folder*>(node.get());
		if (!bRecursive && folder)
		{
			out << offset << "    " << "[" << folder->Name() << "]" << std::endl;
		}
		else
		{
			out << offset + "    ";
			node->List(bFollow, bRecursive, offset + "    ", out);
		}
	}
}

void Folder::Insert(std::unique_ptr<Node> && node)
{
	_content.push_back(std::move(node));
}

Node * Folder::Find(const std::string & path) const
{
	std::regex rgx{ "/" };
	auto start = path.begin();
	if (*start == '/')
		++start;

	return Find({ start, path.end(), rgx, -1 });
}

Node * Folder::Find(std::sregex_token_iterator iter) const
{
	if (iter == std::sregex_token_iterator())
		return nullptr;

	auto itNode = std::find_if(_content.begin(), _content.end(), [&iter](auto & node)
	{
		return node->Name() == *iter;
	}
	);

	if (itNode == _content.end())
		return nullptr;

	if (++iter == std::sregex_token_iterator())
		return itNode->get();

	auto * folder = dynamic_cast<Folder*>(itNode->get());

	return folder ? folder->Find(iter) : nullptr;
}

void Folder::Remove(const Node * node)
{
	_content.erase(std::remove_if(_content.begin(), _content.end(), [node](auto & ptr) { return ptr.get() == node; }), _content.end());
}

std::unique_ptr<Folder> Folder::Parse(rapidjson::Value & json)
{
	Folder * folder = nullptr;
	rapidjson::Value * content = nullptr;
	if (json.IsArray())
	{	// root
		content = &json;
		folder = new Folder("");
	}
	else
	{
		if (!json.HasMember("name") || !json.HasMember("content"))
			return nullptr;

		content = &(json["content"]);
		folder = new Folder(json["name"].GetString());
	}

	for (auto & elm : content->GetArray())
	{
		auto pNode = Node::Parse(elm);
		if (!pNode)
			return nullptr;

		folder->Insert(std::move(pNode));
	}

	return std::unique_ptr<Folder> { folder };
}


