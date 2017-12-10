#include "gtest/gtest.h"
#include "../cmd_Handler.h"
#include <sstream>


TEST(Remove, Command)
{
	auto command = cmd::GetHandler("rm");
	EXPECT_NE(command, nullptr);

	std::stringstream str;

	EXPECT_TRUE(command(nullptr, str));
	EXPECT_FALSE(str.str().empty());
}