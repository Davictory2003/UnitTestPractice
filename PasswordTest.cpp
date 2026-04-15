/**
 * Unit Tests for Password class
 **/

#include <gtest/gtest.h>
#include "Password.h"

class PasswordTest : public ::testing::Test
{
protected:
	PasswordTest() {}		   // constructor runs before each test
	virtual ~PasswordTest() {} // destructor cleans up after tests
	virtual void SetUp() {}	   // sets up before each test (after constructor)
	virtual void TearDown() {} // clean up after each test, (before destructor)
};
/*
TEST(PasswordTest, single_letter_password)
{
	Password my_password;
	ASSERT_EQ(1, my_password.count_leading_characters("Z"));
}

TEST(PasswordTest, multi_letter_password)
{
	Password my_password;
	ASSERT_EQ(2, my_password.count_leading_characters("ZZz"));
}

TEST(PasswordTest, empty_password)
{
	Password my_password;
	ASSERT_EQ(0, my_password.count_leading_characters(""));
}

TEST(PasswordTest, mixed_case_valid)
{
	Password my_password;
	ASSERT_TRUE(my_password.has_mixed_case("aB"));
}

TEST(PasswordTest, mixed_case_all_lower)
{
	Password my_password;
	ASSERT_FALSE(my_password.has_mixed_case("abcd"));
}

TEST(PasswordTest, mixed_case_all_upper)
{
	Password my_password;
	ASSERT_FALSE(my_password.has_mixed_case("ABCD"));
}
*/
TEST(PasswordTest, unique_chars_empty)
{
	Password my_password;
	ASSERT_EQ(0, my_password.unique_characters(""));
}

TEST(PasswordTest, unique_chars_single)
{
	Password my_password;
	ASSERT_EQ(1, my_password.unique_characters("z"));
}

TEST(PasswordTest, unique_chars_repeating)
{
	Password my_password;
	ASSERT_EQ(1, my_password.unique_characters("zzzzzz"));
}

TEST(PasswordTest, unique_chars_mixed_case)
{
	Password my_password;
	// 'z' and 'Z' have distinct ASCII values and thus should count as 2 distinct characters
	ASSERT_EQ(2, my_password.unique_characters("zZ"));
}

TEST(PasswordTest, unique_chars_multiple)
{
	Password my_password;
	ASSERT_EQ(5, my_password.unique_characters("aAbBcCabc"));
}

TEST(PasswordTest, unique_chars_numbers)
{
	Password my_password;
	ASSERT_EQ(4, my_password.unique_characters("1223334444"));
}

TEST(PasswordTest, unique_chars_specials)
{
	Password my_password;
	ASSERT_EQ(3, my_password.unique_characters("!@#"));
}

TEST(PasswordTest, unique_chars_spaces)
{
	Password my_password;
	ASSERT_EQ(1, my_password.unique_characters("   "));
}

TEST(PasswordTest, unique_chars_extended)
{
	Password my_password;
	ASSERT_EQ(4, my_password.unique_characters("A a B b"));
}
