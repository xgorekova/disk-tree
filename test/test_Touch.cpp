#include "gtest/gtest.h"
#include "../cmd_Handler.h"
#include <sstream>

TEST(Touch, Command)
{
	auto command = cmd::GetHandler("touch");
	EXPECT_NE(command, nullptr);

	std::stringstream str;

	EXPECT_TRUE(command(nullptr, str));
}