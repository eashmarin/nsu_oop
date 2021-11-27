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

TEST(OperatorTest, IteratorTest) {
	TritSet set(100);

	for (auto& trit: set)
		trit = Trit::False;

	for (auto trit: set)
		EXPECT_EQ(trit, Trit::False);
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

TEST(FunctionTest, CardinalityTest) {
	TritSet set(100);
	
	EXPECT_EQ(set.cardinality(Trit::Unknown), 0);
	EXPECT_EQ(set.cardinality(Trit::True), 0);
	EXPECT_EQ(set.cardinality(Trit::False), 0);

	set[0] = Trit::False;
	set[1] = Trit::True;
	set[2] = Trit::True;
	set[3] = Trit::True;
	set[4] = Trit::True;
	set[5] = Trit::True;
	set[6] = Trit::True;
	set[7] = Trit::True;
	set[8] = Trit::True;

	EXPECT_EQ(set.cardinality(Trit::False), 1);
	EXPECT_EQ(set.cardinality(Trit::True), 8);
	EXPECT_EQ(set.cardinality(Trit::Unknown), 0);

	set[50] = Trit::True;

	EXPECT_EQ(set.cardinality(Trit::Unknown), 49 - 8);
}

TEST(FunctionTest, TrimTest) {
	TritSet set(100);

	set[49] = Trit::False;
	set[50] = Trit::True;
	set[51] = Trit::True;
	set[90] = Trit::False;

	set.trim(50);

	EXPECT_TRUE(set[49] == Trit::False);
	EXPECT_TRUE(set[50] == Trit::Unknown);
	EXPECT_TRUE(set[51] == Trit::Unknown);
	EXPECT_TRUE(set[90] == Trit::Unknown);
}

TEST(FunctionTest, LengthTest) {
	TritSet set(100);

	set[50] = Trit::True;

	EXPECT_EQ(set.length(), 50 + 1);

	set[55] = Trit::False;

	EXPECT_EQ(set.length(), 55 + 1);

	set[55] = Trit::Unknown;

	EXPECT_EQ(set.length(), 50 + 1);
}
