#include "gtest/gtest.h"
#include "../cmd_Handler.h"
#include <sstream>

TEST(MkDir, Command)
{
	auto command = cmd::GetHandler("mkdir");
	EXPECT_NE(command, nullptr);

	std::stringstream str;

	EXPECT_TRUE(command(nullptr, str));
	EXPECT_FALSE(str.str().empty());
}