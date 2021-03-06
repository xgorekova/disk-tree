#include "headers.h"
#include "cmd_Handlers.h"
#include "cmd_Parse.h"
#include "tree_Node.h"
#include <iostream>
#include <direct.h>
#include <cstdio>

#ifdef _DEBUG
#define new DBG_NEW
#endif

using namespace cmd;
using namespace tree;

Handler cmd::Remove(const Options & options)
{
	return[path = options.path](Node * node, std::ostream & out)
	{
		RemoveDirectory(path.c_str());
		return true;
	};
}