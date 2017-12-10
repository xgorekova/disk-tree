#include <iostream>
#include "headers.h"
#include "cmd_Handlers.h"
#include "cmd_Parse.h"
#include "tree_Node.h"


#ifdef _DEBUG
#define new DBG_NEW
#endif

using namespace cmd;
using namespace tree;

Handler cmd::Touch(const Options & options)
{
	return[path = options.path](Node * node, std::ostream & out)
	{
		return true;
	};
}