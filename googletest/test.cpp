#include "pch.h"
#include "../ossavltree/avltree.h"
#include <gtest/gtest.h>
#include <iostream>
#include <stdexcept>

class AVLtreeTestFixture : public testing::Test {
public:
	AVLtreeTestFixture();
	void SetUp() override;
protected:
	AVLtree avltree_;
};
AVLtreeTestFixture::AVLtreeTestFixture() {
	std::cout << "Constructor called\n";
}

void AVLtreeTestFixture::SetUp() {
	std::cout << "SetUp called\n";
	avltree_.insert(10);
}

TEST(AVLtreeTest, NULLInsert) {
	AVLtree avltree;
	ASSERT_EQ(0, avltree.insert(10));
}

TEST_F(AVLtreeTestFixture, LeftChildInsert) {
	std::cout << "Test body\n";
	
	ASSERT_EQ(1, avltree_.insert(2));
}

TEST_F(AVLtreeTestFixture, LLRotateInsert) {
	std::cout << "Test body\n";
	avltree_.insert(5);
	ASSERT_EQ(1, avltree_.insert(2));
}

TEST_F(AVLtreeTestFixture, LRRotateInsert) {
	std::cout << "Test body\n";
	avltree_.insert(5);
	ASSERT_EQ(1, avltree_.insert(7));
}

TEST_F(AVLtreeTestFixture, RRRotateInsert) {
	std::cout << "Test body\n";
	avltree_.insert(15);
	ASSERT_EQ(1, avltree_.insert(20));
}

TEST_F(AVLtreeTestFixture, RLRotateInsert) {
	std::cout << "Test body\n";
	avltree_.insert(15);
	ASSERT_EQ(1, avltree_.insert(12));
}

TEST_F(AVLtreeTestFixture, RightChildInsert) {
	std::cout << "Test body\n";
	ASSERT_EQ(1, avltree_.insert(15));
}