#pragma once

#include "cmd_defs.h"

#include <ostream>

namespace tree
{
	class Node;
}

namespace cmd
{
	Handler Help(const Options & options);
	bool Quit(tree::Node *, std::ostream & out);
	Handler Remove(const Options & options);
	Handler MkDir(const Options & options);
	Handler Link(const Options & options);
	Handler Touch(const Options & options);
	Handler Size(const Options & options);
	Handler List(const Options & options);
}

