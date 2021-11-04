#include "pch.h"
#include "../lab1/TritSet.h"
#include "../lab1/TritSet.cpp"
#include "../lab1/Trit.h"

//#include "..//lab1/main.cpp"

TEST(OperatorTest, Equality) {

  TritSet set(500);
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
  //trit2str(2));
  EXPECT_TRUE(true);
  /*std::cout << "capacity before = " << set.capacity() << std::endl;
  set[0] = Trit::False;
  set[1] = Trit::True;
  set[3] = Trit::True;
  set[447] = Trit::True;
  set.shrink();
  std::cout << "capacity after shrink = " << set.capacity() << std::endl;
  if (set[55500] == Unknown)
	  std::cout << "TRUE!" << std::endl;
  std::cout << "set[447] = " << set[447] << std::endl;*/
}

TEST(FunctionTest, ShrinkTest) {
	TritSet set(10'000);
	set[20'000] = Trit::True;
	set[20'000] = Trit::Unknown;
	set.shrink();
	EXPECT_EQ(set.capacity(), uint_index(10'000) + 1);

	set[5000] = Trit::False;
	set.shrink();
	EXPECT_EQ(set.capacity(), uint_index(5000) + 1);
}
