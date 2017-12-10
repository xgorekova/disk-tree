
#include "headers.h"
#include "cmd_Handlers.h"
#include "cmd_Parse.h"
#include "tree_Node.h"

#ifdef _DEBUG
#define new DBG_NEW
#endif

using namespace cmd;
using namespace tree;

Handler cmd::Help(const Options & options) //(tree::Node *, std::ostream & out)
{
	//todo: print command help
	//out << "help..." << std::endl;
	return[command = options.path](Node * node, std::ostream & out)
	{
		out << "help..." << std::endl;
		return true;

	};


	/* prerobit help podobne ako je size
	return[bFollow = options.bFollow, bRecursive = options.bRecursive, path = options.path](Node * node, std::ostream & out)
	{
	auto root = ParsePath(path, node);
	if (std::holds_alternative<std::string>(root))
	out << std::get<std::string>(root) << std::endl;
	if (std::holds_alternative<Node*>(root))
	out << "    " << std::get<Node*>(root)->Size(bFollow, bRecursive).toString() << std::endl;
	return true;

	};*/

}