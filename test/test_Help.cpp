#include "gtest/gtest.h"
#include "../cmd_Handler.h"
#include <sstream>


TEST(Help, Command)
{
	auto command = cmd::GetHandler("help");
	EXPECT_NE(command, nullptr);
	std::stringstream str;

	EXPECT_TRUE(command(nullptr, str));
	EXPECT_FALSE(str.str().empty());
	
	
	auto command_quit = cmd::GetHandler("help quit");
	EXPECT_NE(command_quit, nullptr);
	str.str(std::string());

	EXPECT_TRUE(command_quit(nullptr, str));
	EXPECT_FALSE(str.str().empty());
	


	auto command_list = cmd::GetHandler("help list");
	EXPECT_NE(command_list, nullptr);
	str.str(std::string());

	EXPECT_TRUE(command_list(nullptr, str));
	EXPECT_FALSE(str.str().empty());
	

	auto command_size = cmd::GetHandler("help size");
	EXPECT_NE(command_size, nullptr);
	str.str(std::string());

	EXPECT_TRUE(command_size(nullptr, str));
	EXPECT_FALSE(str.str().empty());
	

	auto command_rm = cmd::GetHandler("help rm");
	EXPECT_NE(command_rm, nullptr);
	str.str(std::string());

	EXPECT_TRUE(command_rm(nullptr, str));
	EXPECT_FALSE(str.str().empty());
	
	
	auto command_mkdir = cmd::GetHandler("help mkdir");
	EXPECT_NE(command_mkdir, nullptr);
	str.str(std::string());

	EXPECT_TRUE(command_mkdir(nullptr, str));
	EXPECT_FALSE(str.str().empty());


	auto command_link = cmd::GetHandler("help link");
	EXPECT_NE(command_link, nullptr);
	str.str(std::string());

	EXPECT_TRUE(command_link(nullptr, str));
	EXPECT_FALSE(str.str().empty());

	
	auto command_touch = cmd::GetHandler("help touch");
	EXPECT_NE(command_touch, nullptr);
	str.str(std::string());

	EXPECT_TRUE(command_touch(nullptr, str));
	EXPECT_FALSE(str.str().empty());


	auto command_bad = cmd::GetHandler("help adsvasdvc");
	EXPECT_NE(command_bad, nullptr);
	str.str(std::string());

	EXPECT_TRUE(command_bad(nullptr, str));
	EXPECT_FALSE(str.str().empty());

}