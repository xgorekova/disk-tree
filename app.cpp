#include "headers.h"
#include <iostream>
#include <fstream>

#include "tree_Disk.h"
#include "cmd_Handler.h"

#include "rapidjson/document.h"
#include "rapidjson/istreamwrapper.h"

#ifdef _DEBUG
#define new DBG_NEW
#endif


namespace
{
	// set db flag to dump memory leaks
	struct SetDbFlag
	{
		SetDbFlag()
		{
			_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
		}
	}__;
}


int main(int argc, char * argv[])
{
	if (argc > 2)
	{
		//todo: std::cout << "wrong args"
		return -1;
	}

	rapidjson::Document disk;
	if (argc == 2)
	{
		std::fstream f(argv[1], std::ios_base::in);
		if (f.bad())
		{
			//todo: std::cout << "file read error"
			return -1;
		}

		rapidjson::IStreamWrapper stream(f);

		rapidjson::ParseResult result = disk.ParseStream(stream);
		if (!result)
		{
			//todo: std::cout << "json parsing failed with error " << result.Code();
			return -1;
		}
	}
	else
	{
		disk.Parse("[]");
	}

	auto root = tree::ParseDisk(disk);
	if (!root)
	{
		//todo: std::cout << "error json values";
		return -1;
	}

	//todo: std::cout << "welcome message";

	while (true)
	{
		std::cout << ">";
		std::string line;
		std::getline(std::cin, line);

		auto handler = cmd::GetHandler(line);
		if (!handler)
		{
			// std::cout << "invalid command";
			std::cout << std::endl;
			continue;
		}

		if (!handler(root.get(), std::cout))
			break;

		std::cout << std::endl;
	}
	return 0;
}