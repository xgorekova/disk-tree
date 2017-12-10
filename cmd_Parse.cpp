#include "headers.h"
#include "cmd_Parse.h"
#include "tree_Folder.h"

#include <regex>

#ifdef _DEBUG
#define new DBG_NEW
#endif

using namespace cmd;
using namespace tree;


std::optional<std::pair<Command, Options>> cmd::ParseOptions(const std::string & line)
{
	std::regex rgx{ "^(help|list|size|quit|rm|mkdir|touch|link)(\\s-(recursive|follow)(\\s-(recursive|follow)){0,1}){0,1}(\\s+(.+)){0,1}$" };
	//na vytvorenie adresara, linku bude tiez cesta tak budu zacinat lomitkom ako size + zmena v testoch 
	std::smatch match;
	if (!std::regex_match(line, match, rgx))
		return {};

	bool bFollow = match[3] == "follow" || match[5] == "follow";
	bool bRecursive = match[3] == "recursive" || match[5] == "recursive";

	std::string path;

	Command command;

	if (match[1] == "help") {

		command = Command::Help;
		if (match[7].matched) {
			if (match[7].str()[0] == '/' || match[7].str()[0] == '-')
				return {};
			path = match[7].str();
		}
	}
	else if (match[1] == "list") {

		command = Command::List;
		if (match[7].matched) {

			if (match[7].str()[0] != '/')
				return {};
			path = match[7].str();
		}

		else {
			path = '/';
		}
	}
	else if (match[1] == "size") {
		command = Command::Size;
		if (match[7].matched) {

			if (match[7].str()[0] != '/')
				return {};
			path = match[7].str();
		}
		else {
			path = '/';
		}
	}

	else if (match[1] == "quit") {

		command = Command::Quit;
		if (match[7].matched)
			return {};
	}

	else if (match[1] == "rm")
	{
		command = Command::Remove;
		if (match[7].matched)
		{
			if (match[7].str()[0] == '/' || match[7].str()[0] == '-')
				return {};
			path = match[7].str();
		}

	}
	else if (match[1] == "mkdir")
	{
		command = Command::MkDir;
		if (match[7].matched)
		{
			if (match[7].str()[0] == '/' || match[7].str()[0] == '-')
				return {};
			path = match[7].str();
		}
	}
	else if (match[1] == "link")
	{
		command = Command::Link;

	}
	else if (match[1] == "touch")
	{
		command = Command::Touch;

	}
	else
		return {};

	return std::make_pair(command, Options{ bFollow, bRecursive, path });
}

std::variant<std::string, tree::Node *> cmd::ParsePath(const std::string & path, tree::Node * root)
{
	if (!path.empty() && path != "/")
	{
		auto * folder = dynamic_cast<Folder*>(root);
		if (!folder)
		{
			//todo: nice error message
			return "invalid root";
		}

		root = folder->Find(path);
		if (!root)
		{
			//todo: make nice error message
			return "invalid folder '" + path + "'";
		}
	}

	return root;
}