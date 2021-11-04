#include "pch.h"
#include "../lab1/TritSet.h"
#include "../lab1/TritSet.cpp"
#include "../lab1/Trit.h"

//#include "..//lab1/main.cpp"

TEST(OperatorTest, Equality) {

  TritSet set(500);
  uint capacity = set.capacity();
  set[0] = Trit::False;
  set[1] = Trit::True;
  set[2] = Trit::True;
  set[7] = Trit::Unknown;
  set[450] = Trit::False;
  set[451] = Trit::False;

  EXPECT_TRUE(set[0] == Trit::False);
  EXPECT_TRUE(set[1] == Trit::True);
  EXPECT_TRUE(set[2] == Trit::True);
  EXPECT_TRUE(set[7] == Trit::Unknown);
  EXPECT_TRUE(set[450] == Trit::False);
  EXPECT_TRUE(set[451] == Trit::False);

  EXPECT_TRUE(set[1000] == Trit::Unknown);
  EXPECT_EQ(set.capacity(), capacity);

  EXPECT_FALSE(set[1000] == Trit::True);
  EXPECT_EQ(set.capacity(), capacity);
}

TEST(FunctionTest, ShrinkTest) {
	TritSet set(10'000);
	uint capacity = set.capacity();

	set[20'000] = Trit::True;
	set[20'000] = Trit::Unknown;
	set.shrink();

	EXPECT_EQ(set.capacity(), capacity);

	set[5000] = Trit::False;
	set.shrink();

	EXPECT_LT(set.capacity(), capacity);
	EXPECT_EQ(set.capacity(), uint_index(5000) + 1);
}
