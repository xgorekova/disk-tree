#pragma once
#include <memory>
#include "tree_Folder.h"

namespace tree
{
	//std::unique_ptr<tree::Folder> tree::ParseDisk(rapidjson::Value & json);
	tree::Folder * ParseDisk(rapidjson::Value & json);
}
