#include "pch.h"
#include "../ossavltree/set.h"
#include <gtest/gtest.h>
#include <iostream>
#include <stdexcept>

class SetTestFixture : public testing::Test {
public:
	SetTestFixture();
	virtual ~SetTestFixture();
	void SetUp() override;
	void TearDown() override;
	static void SetUpTestCase();
	static void TearDownTestCase();

protected:
	Int_AVLtree_set set;
};

SetTestFixture::SetTestFixture() {
	std::cout << "Constructor called\n";
}

SetTestFixture::~SetTestFixture() {
	std::cout << "Destructor called\n";
}

void SetTestFixture::SetUpTestCase() {
	std::cout << "SetUPTestCase called\n";
}

void SetTestFixture::TearDownTestCase() {
	std::cout << "TearDownTestCase called\n";
}

void SetTestFixture::SetUp() {
	std::cout << "SetUp called\n";
	set.Insert(10);
	set.Insert(5);
	set.Insert(15);
	set.Insert(2);
	set.Insert(7);
	set.Insert(12);
	set.Insert(17);
}

void SetTestFixture::TearDown() {
	std::cout << "TearDown called\n";
}

class LXRotateInsertFixture : public testing::TestWithParam<std::tuple<int, int>> {
public:
protected:
	Int_AVLtree_set set;
};

class RXRotateInsertFixture : public testing::TestWithParam<std::tuple<int, int>> {
public:
protected:
	Int_AVLtree_set set;
};

class MinimumFixture : public testing::TestWithParam<std::tuple<int, int, int>> {
public:
protected:
	Int_AVLtree_set set;
};

class MaximumFixture : public testing::TestWithParam<std::tuple<int, int, int>> {
public:
protected:
	Int_AVLtree_set set;
};

class RankFixture : public testing::TestWithParam<std::tuple<int, int, int>> {
public:
protected:
	Int_AVLtree_set set;
};

class FindFixture : public testing::TestWithParam<std::tuple<int, int>> {
public:
protected:
	Int_AVLtree_set set;
};




INSTANTIATE_TEST_CASE_P(
	LXRotateInsertTest, LXRotateInsertFixture,
	testing::Values(std::make_tuple(1, 1), std::make_tuple(4, 0)));

INSTANTIATE_TEST_CASE_P(
	RXRotateInsertTest, RXRotateInsertFixture,
	testing::Values(std::make_tuple(10, 1), std::make_tuple(7, 0)));

INSTANTIATE_TEST_CASE_P(
	MinimumTest, MinimumFixture,
	testing::Values(
		std::make_tuple(1, 1, 4), std::make_tuple(2, 1, 4), std::make_tuple(3, 3, 4), std::make_tuple(4, 1, 4), std::make_tuple(5, 5, 4), 
		std::make_tuple(6, 5, 4), std::make_tuple(7, 7, 4), std::make_tuple(8, 1, 4), std::make_tuple(9, 9, 4), std::make_tuple(10, 9, 4),
		std::make_tuple(11, 11, 4), std::make_tuple(12, 9, 4), std::make_tuple(13, 13, 4), std::make_tuple(14, 13, 4), std::make_tuple(15, 15, 4),
		std::make_tuple(16, 1, 4), std::make_tuple(17, 17, 4), std::make_tuple(18, 17, 4), std::make_tuple(19, 19, 4), std::make_tuple(20, 17, 4),
		std::make_tuple(21, 21, 4), std::make_tuple(22, 21, 4), std::make_tuple(23, 23, 4), std::make_tuple(24, 17, 4), std::make_tuple(25, 25, 5),
		std::make_tuple(26, 25, 5), std::make_tuple(27, 27, 5), std::make_tuple(28, 25, 5), std::make_tuple(29, 29, 5), std::make_tuple(30, 29, 5),
		std::make_tuple(31, 31, 5), std::make_tuple(32, 25, 5), std::make_tuple(33, 33, 5), std::make_tuple(34, 33, 5), std::make_tuple(35, 35, 5),
		std::make_tuple(36, 33, 5), std::make_tuple(37, 37, 4), std::make_tuple(38, 38, 5)));

INSTANTIATE_TEST_CASE_P(
	MinimumTest, MaximumFixture,
	testing::Values(
		std::make_tuple(1, 1, 4), std::make_tuple(2, 3, 4), std::make_tuple(3, 3, 4), std::make_tuple(4, 7, 4), std::make_tuple(5, 5, 4),
		std::make_tuple(6, 7, 4), std::make_tuple(7, 7, 4), std::make_tuple(8, 15, 4), std::make_tuple(9, 9, 4), std::make_tuple(10, 11, 4),
		std::make_tuple(11, 11, 4), std::make_tuple(12, 15, 4), std::make_tuple(13, 13, 4), std::make_tuple(14, 15, 4), std::make_tuple(15, 15, 4),
		std::make_tuple(16, 38, 5), std::make_tuple(17, 17, 4), std::make_tuple(18, 19, 4), std::make_tuple(19, 19, 4), std::make_tuple(20, 23, 4),
		std::make_tuple(21, 21, 4), std::make_tuple(22, 23, 4), std::make_tuple(23, 23, 4), std::make_tuple(24, 38, 5), std::make_tuple(25, 25, 5),
		std::make_tuple(26, 27, 5), std::make_tuple(27, 27, 5), std::make_tuple(28, 31, 5), std::make_tuple(29, 29, 5), std::make_tuple(30, 31, 5),
		std::make_tuple(31, 31, 5), std::make_tuple(32, 38, 5), std::make_tuple(33, 33, 5), std::make_tuple(34, 35, 5), std::make_tuple(35, 35, 5),
		std::make_tuple(36, 38, 5), std::make_tuple(37, 38, 5), std::make_tuple(38, 38, 5)));

INSTANTIATE_TEST_CASE_P(
	RankTest, RankFixture,
	testing::Values(
		std::make_tuple(1, 4, 1), std::make_tuple(2, 3, 2), std::make_tuple(3, 4, 3), std::make_tuple(4, 2, 4), std::make_tuple(5, 4, 5),
		std::make_tuple(6, 3, 6), std::make_tuple(7, 4, 7), std::make_tuple(8, 1, 8), std::make_tuple(9, 4, 9), std::make_tuple(10, 3, 10),
		std::make_tuple(11, 4, 11), std::make_tuple(12, 2, 12), std::make_tuple(13, 4, 13), std::make_tuple(14, 3, 14), std::make_tuple(15, 4, 15),
		std::make_tuple(16, 0, 16), std::make_tuple(17, 4, 17), std::make_tuple(18, 3, 18), std::make_tuple(19, 4, 19), std::make_tuple(20, 2, 20),
		std::make_tuple(21, 4, 21), std::make_tuple(22, 3, 22), std::make_tuple(23, 4, 23), std::make_tuple(24, 1, 24), std::make_tuple(25, 5, 25),
		std::make_tuple(26, 4, 26), std::make_tuple(27, 5, 27), std::make_tuple(28, 3, 28), std::make_tuple(29, 5, 29), std::make_tuple(30, 4, 30),
		std::make_tuple(31, 5, 31), std::make_tuple(32, 2, 32), std::make_tuple(33, 5, 33), std::make_tuple(34, 4, 34), std::make_tuple(35, 5, 35),
		std::make_tuple(36, 3, 36), std::make_tuple(37, 4, 37), std::make_tuple(38, 5, 38)));

INSTANTIATE_TEST_CASE_P(
	FindTest, FindFixture,
	testing::Values(
		std::make_tuple(1, 4), std::make_tuple(2, 3), std::make_tuple(3, 4), std::make_tuple(4, 2), std::make_tuple(5, 4),
		std::make_tuple(6, 3), std::make_tuple(7, 4), std::make_tuple(8, 1), std::make_tuple(9, 4), std::make_tuple(10, 3),
		std::make_tuple(11, 4), std::make_tuple(12, 2), std::make_tuple(13, 4), std::make_tuple(14, 3), std::make_tuple(15, 4),
		std::make_tuple(16, 0), std::make_tuple(17, 4), std::make_tuple(18, 3), std::make_tuple(19, 4), std::make_tuple(20, 2),
		std::make_tuple(21, 4), std::make_tuple(22, 3), std::make_tuple(23, 4), std::make_tuple(24, 1), std::make_tuple(25, 5),
		std::make_tuple(26, 4), std::make_tuple(27, 5), std::make_tuple(28, 3), std::make_tuple(29, 5), std::make_tuple(30, 4),
		std::make_tuple(31, 5), std::make_tuple(32, 2), std::make_tuple(33, 5), std::make_tuple(34, 4), std::make_tuple(35, 5),
		std::make_tuple(36, 3), std::make_tuple(37, 4), std::make_tuple(38, 5)));

TEST(InsertTest, TestInsertOnEmpty) {
	Int_AVLtree_set set;
	ASSERT_EQ(0, set.Insert(5));
}

TEST(EmptyTest, TestEmptyOnEmpty) {
	Int_AVLtree_set set;
	ASSERT_EQ(1, set.Empty());
}

TEST(EmptyTest, TestEmptyOnNotEmpty) {
	Int_AVLtree_set set;
	set.Insert(1);
	ASSERT_EQ(0, set.Empty());
}

TEST(SizeTest, TestSizeOnEmpty) {
	Int_AVLtree_set set;
	ASSERT_EQ(0, set.Size());
}

TEST(SizeTest, TestSize) {
	Int_AVLtree_set set;
	set.Insert(1);
	ASSERT_EQ(1, set.Size());
	set.Insert(5);
	ASSERT_EQ(2, set.Size());
	set.Insert(3);
	ASSERT_EQ(3, set.Size());
}

TEST(MaximumTest, TestMaximumXIsMax) {
	Int_AVLtree_set set;
	set.Insert(5);
	set.Insert(2);
	std::pair<int, int> pair = set.Maximum(5);
	int key = pair.first;
	int depth = pair.second;
	ASSERT_EQ(5, key);
	ASSERT_EQ(0, depth);
}

TEST(MinimumTest, TestMinimumXIsMin) {
	Int_AVLtree_set set;
	set.Insert(5);
	set.Insert(2);
	std::pair<int, int> pair = set.Maximum(2);
	int key = pair.first;
	int depth = pair.second;
	ASSERT_EQ(2, key);
	ASSERT_EQ(1, depth);
}

TEST(FindTest, TestFindOnEmpty) {
	Int_AVLtree_set set;
	ASSERT_EQ(0, set.Find(5));
}

TEST(FindTest, TestFindOnRoot) {
	Int_AVLtree_set set;
	set.Insert(5);
	ASSERT_EQ(0, set.Find(5));
}

TEST(EraseTest, TestEraseOnEmpty) {
	Int_AVLtree_set set;
	ASSERT_EQ(0, set.Erase(2));
}

TEST(EraseTest, TestEraseRoot) {
	Int_AVLtree_set set;
	set.Insert(5);
	ASSERT_EQ(0, set.Erase(5));
}

TEST(RankTest, TestRankRoot) {
	Int_AVLtree_set set;
	set.Insert(5);
	std::pair<int, int> pair = set.Rank(5);
	int depth = pair.first;
	int rank = pair.second;
	ASSERT_EQ(0, depth);
	ASSERT_EQ(1, rank);
}

TEST(AVLtreeTest, AVLtreeTest) {
	Int_AVLtree_set set;
	ASSERT_EQ(0, set.Insert(1));
	ASSERT_EQ(1, set.Insert(2));
	ASSERT_EQ(1, set.Insert(3));
	ASSERT_EQ(2, set.Insert(4));
	ASSERT_EQ(2, set.Insert(5));
	ASSERT_EQ(2, set.Insert(6));
	ASSERT_EQ(2, set.Insert(7));
	ASSERT_EQ(3, set.Insert(8));
	ASSERT_EQ(3, set.Insert(9));
	ASSERT_EQ(3, set.Insert(10));
	ASSERT_EQ(3, set.Insert(11));
	ASSERT_EQ(3, set.Insert(12));
	ASSERT_EQ(3, set.Insert(13));
	ASSERT_EQ(3, set.Insert(14));
	ASSERT_EQ(3, set.Insert(15));
	ASSERT_EQ(4, set.Insert(16));
	ASSERT_EQ(4, set.Insert(17));
	ASSERT_EQ(4, set.Insert(18));
	ASSERT_EQ(4, set.Insert(19));
	ASSERT_EQ(4, set.Insert(20));
	ASSERT_EQ(4, set.Insert(21));
	ASSERT_EQ(4, set.Insert(22));
	ASSERT_EQ(4, set.Insert(23));
	ASSERT_EQ(4, set.Insert(24));
	ASSERT_EQ(4, set.Insert(25));
	ASSERT_EQ(4, set.Insert(26));
	ASSERT_EQ(4, set.Insert(27));
	ASSERT_EQ(4, set.Insert(28));
	ASSERT_EQ(4, set.Insert(29));
	ASSERT_EQ(4, set.Insert(30));
	ASSERT_EQ(4, set.Insert(31));
	ASSERT_EQ(5, set.Insert(32));
	ASSERT_EQ(5, set.Insert(33));
	ASSERT_EQ(5, set.Insert(34));
	ASSERT_EQ(5, set.Insert(35));
	ASSERT_EQ(5, set.Insert(36));
	ASSERT_EQ(5, set.Insert(37));
	ASSERT_EQ(5, set.Insert(38));

	ASSERT_EQ(4, set.Erase(7));
	ASSERT_EQ(4, set.Erase(13));
	ASSERT_EQ(2, set.Erase(32));
	ASSERT_EQ(3, set.Erase(10));
	ASSERT_EQ(5, set.Erase(31));
	ASSERT_EQ(1, set.Erase(24));
	ASSERT_EQ(2, set.Erase(12));
	ASSERT_EQ(4, set.Erase(1));
	ASSERT_EQ(1, set.Erase(25));
	ASSERT_EQ(3, set.Erase(11));
	ASSERT_EQ(1, set.Erase(26));
	ASSERT_EQ(5, set.Erase(38));
	ASSERT_EQ(0, set.Erase(16));
	ASSERT_EQ(4, set.Erase(34));
	ASSERT_EQ(1, set.Erase(27));
	ASSERT_EQ(4, set.Erase(5));
	ASSERT_EQ(1, set.Erase(28));
	ASSERT_EQ(3, set.Erase(36));
	ASSERT_EQ(3, set.Erase(6));
	ASSERT_EQ(3, set.Erase(9));
	ASSERT_EQ(3, set.Erase(18));
	ASSERT_EQ(4, set.Erase(23));
	ASSERT_EQ(3, set.Erase(2));
	ASSERT_EQ(3, set.Erase(19));
	ASSERT_EQ(2, set.Erase(14));
	ASSERT_EQ(3, set.Erase(22));
	ASSERT_EQ(1, set.Erase(8));
	ASSERT_EQ(2, set.Erase(30));
	ASSERT_EQ(3, set.Erase(15));
	ASSERT_EQ(3, set.Erase(3));
	ASSERT_EQ(2, set.Erase(37));
	ASSERT_EQ(1, set.Erase(17));
	ASSERT_EQ(0, set.Erase(29));
	ASSERT_EQ(2, set.Erase(4));
	ASSERT_EQ(1, set.Erase(35));
	ASSERT_EQ(1, set.Erase(20));
	ASSERT_EQ(1, set.Erase(33));
	ASSERT_EQ(0, set.Erase(21));

}

TEST_F(SetTestFixture, TestInsertExist) {
	std::cout << "Test body\n";
	ASSERT_EQ(-1, set.Insert(5));
}


TEST_F(SetTestFixture, TestInsertLeftChild) {
	ASSERT_EQ(3, set.Insert(1));
}

TEST_F(SetTestFixture, TestInsertRightChild) {
	ASSERT_EQ(3, set.Insert(20));
}

TEST_F(SetTestFixture, TestMaximumXIsNotMAx) {
	std::pair<int, int> pair = set.Maximum(2);
	int key = pair.first;
	int depth = pair.second;
	ASSERT_EQ(2, key);
	ASSERT_EQ(2, depth);
}

TEST_F(SetTestFixture, TestMinimumXIsNotMAx) {
	std::pair<int, int> pair = set.Minimum(17);
	int key = pair.first;
	int depth = pair.second;
	ASSERT_EQ(17, key);
	ASSERT_EQ(2, depth);
}

TEST_F(SetTestFixture, TestFindLeaf) {
	ASSERT_EQ(2, set.Find(2));
	ASSERT_EQ(2, set.Find(17));
}

TEST_F(SetTestFixture, TestEraseUsingSuccessor) {
	ASSERT_EQ(1, set.Find(5));
	ASSERT_EQ(1, set.Find(15));
}

TEST_F(SetTestFixture, TestRankSetUp) {
	std::pair<int, int> pair = set.Rank(17);
	int depth = pair.first;
	int rank = pair.second;
	ASSERT_EQ(2, depth);
	ASSERT_EQ(7, rank);

	pair = set.Rank(2);
	depth = pair.first;
	rank = pair.second;
	ASSERT_EQ(2, depth);
	ASSERT_EQ(1, rank);

	pair = set.Rank(5);
	depth = pair.first;
	rank = pair.second;
	ASSERT_EQ(1, depth);
	ASSERT_EQ(2, rank);
}

TEST_P(LXRotateInsertFixture, LXRotateInsertTest) {
	set.Insert(5);
	set.Insert(3);
	std::tuple<int, int> x = GetParam();

	int param = std::get<0>(x);
	int expected_value = std::get<1>(x);
	int is_insert = set.Insert(param);

	ASSERT_EQ(expected_value, is_insert);
}

TEST_P(RXRotateInsertFixture, RXRotateInsertTest) {
	set.Insert(5);
	set.Insert(8);
	std::tuple<int, int> x = GetParam();

	int param = std::get<0>(x);
	int expected_value = std::get<1>(x);
	int is_insert = set.Insert(param);

	ASSERT_EQ(expected_value, is_insert);
}

TEST_P(MinimumFixture, MinimumTest) {
	set.Insert(1);
	set.Insert(2);
	set.Insert(3);
	set.Insert(4);
	set.Insert(5);
	set.Insert(6);
	set.Insert(7);
	set.Insert(8);
	set.Insert(9);
	set.Insert(10);
	set.Insert(11);
	set.Insert(12);
	set.Insert(13);
	set.Insert(14);
	set.Insert(15);
	set.Insert(16);
	set.Insert(17);
	set.Insert(18);
	set.Insert(19);
	set.Insert(20);
	set.Insert(21);
	set.Insert(22);
	set.Insert(23);
	set.Insert(24);
	set.Insert(25);
	set.Insert(26);
	set.Insert(27);
	set.Insert(28);
	set.Insert(29);
	set.Insert(30);
	set.Insert(31);
	set.Insert(32);
	set.Insert(33);
	set.Insert(34);
	set.Insert(35);
	set.Insert(36);
	set.Insert(37);
	set.Insert(38);
	std::tuple<int, int, int> x = GetParam();

	int param = std::get<0>(x);
	int expected_value_key = std::get<1>(x);
	int expected_value_depth = std::get<2>(x);
	std::pair<int, int> is_insert = set.Minimum(param);
	int key = is_insert.first;
	int depth = is_insert.second;

	ASSERT_EQ(expected_value_key, key);
	ASSERT_EQ(expected_value_depth, depth);
}

TEST_P(MaximumFixture, MaximumTest) {
	set.Insert(1);
	set.Insert(2);
	set.Insert(3);
	set.Insert(4);
	set.Insert(5);
	set.Insert(6);
	set.Insert(7);
	set.Insert(8);
	set.Insert(9);
	set.Insert(10);
	set.Insert(11);
	set.Insert(12);
	set.Insert(13);
	set.Insert(14);
	set.Insert(15);
	set.Insert(16);
	set.Insert(17);
	set.Insert(18);
	set.Insert(19);
	set.Insert(20);
	set.Insert(21);
	set.Insert(22);
	set.Insert(23);
	set.Insert(24);
	set.Insert(25);
	set.Insert(26);
	set.Insert(27);
	set.Insert(28);
	set.Insert(29);
	set.Insert(30);
	set.Insert(31);
	set.Insert(32);
	set.Insert(33);
	set.Insert(34);
	set.Insert(35);
	set.Insert(36);
	set.Insert(37);
	set.Insert(38);
	std::tuple<int, int, int> x = GetParam();

	int param = std::get<0>(x);
	int expected_value_key = std::get<1>(x);
	int expected_value_depth = std::get<2>(x);
	std::pair<int, int> is_insert = set.Maximum(param);
	int key = is_insert.first;
	int depth = is_insert.second;

	ASSERT_EQ(expected_value_key, key);
	ASSERT_EQ(expected_value_depth, depth);
}

TEST_P(RankFixture, RankTest) {
	set.Insert(1);
	set.Insert(2);
	set.Insert(3);
	set.Insert(4);
	set.Insert(5);
	set.Insert(6);
	set.Insert(7);
	set.Insert(8);
	set.Insert(9);
	set.Insert(10);
	set.Insert(11);
	set.Insert(12);
	set.Insert(13);
	set.Insert(14);
	set.Insert(15);
	set.Insert(16);
	set.Insert(17);
	set.Insert(18);
	set.Insert(19);
	set.Insert(20);
	set.Insert(21);
	set.Insert(22);
	set.Insert(23);
	set.Insert(24);
	set.Insert(25);
	set.Insert(26);
	set.Insert(27);
	set.Insert(28);
	set.Insert(29);
	set.Insert(30);
	set.Insert(31);
	set.Insert(32);
	set.Insert(33);
	set.Insert(34);
	set.Insert(35);
	set.Insert(36);
	set.Insert(37);
	set.Insert(38);
	std::tuple<int, int, int> x = GetParam();

	int param = std::get<0>(x);
	int expected_value_depth = std::get<1>(x);
	int expected_value_rank = std::get<2>(x);
	std::pair<int, int> is_insert = set.Rank(param);
	int depth = is_insert.first;
	int rank = is_insert.second;

	ASSERT_EQ(expected_value_depth, depth);
	ASSERT_EQ(expected_value_rank, rank);
}

TEST_P(FindFixture, FindTest) {
	set.Insert(1);
	set.Insert(2);
	set.Insert(3);
	set.Insert(4);
	set.Insert(5);
	set.Insert(6);
	set.Insert(7);
	set.Insert(8);
	set.Insert(9);
	set.Insert(10);
	set.Insert(11);
	set.Insert(12);
	set.Insert(13);
	set.Insert(14);
	set.Insert(15);
	set.Insert(16);
	set.Insert(17);
	set.Insert(18);
	set.Insert(19);
	set.Insert(20);
	set.Insert(21);
	set.Insert(22);
	set.Insert(23);
	set.Insert(24);
	set.Insert(25);
	set.Insert(26);
	set.Insert(27);
	set.Insert(28);
	set.Insert(29);
	set.Insert(30);
	set.Insert(31);
	set.Insert(32);
	set.Insert(33);
	set.Insert(34);
	set.Insert(35);
	set.Insert(36);
	set.Insert(37);
	set.Insert(38);
	std::tuple<int, int> x = GetParam();

	int param = std::get<0>(x);
	int expected_value = std::get<1>(x);
	int is_insert = set.Find(param);

	ASSERT_EQ(expected_value, is_insert);
}

