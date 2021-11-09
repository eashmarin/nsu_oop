#include "pch.h"
#include "../lab1/TritSet.cpp"
#include "../lab1/Trit.h"

TEST(OperatorTest, EqualTest) {
	TritSet set(10);
	uint capacity = set.capacity();
	set[399] = Trit::Unknown;

	EXPECT_EQ(set.capacity(), capacity);

	set[399] = Trit::False;

	EXPECT_EQ(set.capacity(), trits2size(400));
}
TEST(OperatorTest, EqualityTest) {

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

TEST(OperatorTest, And) {
	TritSet setA(1000);
	TritSet setB(2000);

	setA[496] = Trit::False;
	setB[496] = Trit::True;
	setA[497] = Trit::True;
	setB[497] = Trit::True;
	setA[498] = Trit::Unknown;
	setB[498] = Trit::True;
	setA[499] = Trit::False;
	setB[499] = Trit::False;

	TritSet setC = (setA & setB);

	EXPECT_TRUE(setC[496] == Trit::False);
	EXPECT_TRUE(setC[497] == Trit::True);
	EXPECT_TRUE(setC[498] == Trit::Unknown);
	EXPECT_TRUE(setC[499] == Trit::False);

	EXPECT_TRUE(setC.capacity() == setB.capacity());
}

TEST(OperatorTest, Or) {
	TritSet setA(2000);
	TritSet setB(1000);

	setA[496] = Trit::False;
	setB[496] = Trit::True;
	setA[497] = Trit::True;
	setB[497] = Trit::True;
	setA[498] = Trit::Unknown;
	setB[498] = Trit::True;
	setA[499] = Trit::False;
	setB[499] = Trit::False;

	TritSet setC = (setA | setB);

	EXPECT_TRUE(setC[496] == Trit::True);
	EXPECT_TRUE(setC[497] == Trit::True);
	EXPECT_TRUE(setC[498] == Trit::True);
	EXPECT_TRUE(setC[499] == Trit::False);

	EXPECT_TRUE(setC.capacity() == setA.capacity());
}

TEST(OperatorTest, Not) {
	TritSet set(10);

	set[0] = Trit::True;
	set[3] = Trit::False;
	set[9] = Trit::Unknown;

	TritSet set2 = !set;

	EXPECT_TRUE(set2[0] == Trit::False);
	EXPECT_TRUE(set2[3] == Trit::True);
	EXPECT_TRUE(set2[5] == Trit::Unknown);

	EXPECT_TRUE(set2.capacity() == set.capacity());
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

	EXPECT_EQ(set.capacity(), trits2size(5000 + 1));
}
