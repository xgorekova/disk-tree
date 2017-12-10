#include "headers.h"
#include "cmd_Handlers.h"
#include "cmd_Parse.h"
#include "tree_Node.h"
#include <iostream>
#include <direct.h>

#ifdef _DEBUG
#define new DBG_NEW
#endif

using namespace cmd;
using namespace tree;

Handler cmd::MkDir(const Options & options)
{
	return[path = options.path](Node * node, std::ostream & out)
	{
		mkdir(path.c_str());
		return true;
	};
}