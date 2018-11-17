// Copyright 2018 Avsyankaa <Avsyankaa@gmail.com>

#include <gtest/gtest.h>

#include <stack.hpp>

TEST(StackTest, Test1) {
    stack<int> st;
    st.push(5);
    st.push(7);
    st.push(9);
    st.push(12);
    EXPECT_EQ(st.head(), 5);
 }

TEST(StackTest, Test2) {
    stack<int> st;
    int a = 8;
    st.push(a);
    EXPECT_EQ(st.head(), 8);
 }

TEST(StackTest, Test3) {
    stack<int> st;
    int a = 8;
    st.push(a);
    st.push(10);
    st.push(78);
    st.push(23);
    EXPECT_EQ(st.get_element(2), 78);
 }

TEST(StackTest, Test4) {
    stack<int> st;
    int a = 8;
    st.push(a);
    st.push(10);
    st.push(78);
    st.push(23);
    st.pop();
    EXPECT_EQ(st.get_capacity(), 3);
    EXPECT_EQ(st.head(), 8);
    EXPECT_EQ(st.get_element(1), 10);
    EXPECT_EQ(st.get_element(2), 78);
 }

TEST(StackTest, Test5)  {
    stack<int> st;
    int a = 8;
    st.push(a);
    st.push(10);
    st.pop();
    st.pop();
    EXPECT_EQ(st.get_capacity(), 0);
}

TEST(Stack1Test, Test6) {
    stack<std::pair<int, std::string>> st;
    st.push_emplace(4, "hello");
    std::pair<int, std::string> pair1 = st.get_element(0);
    std::pair<int, std::string> result{4, "hello"};
    EXPECT_EQ(pair1, result);
}


TEST(Stack1Test, Test7) {
    stack<std::pair<int, std::string>> st;
    stack<std::pair<int, std::string>> st1;
    st.push_emplace(4, "hello");
    st.push_emplace(5, "hi");
    st.push_emplace(6, "hoy");
    st1.push_emplace(st.get_element(0));
    std::pair<int, std::string> result{4, "hello"};
    EXPECT_EQ(result, st1.get_element(0));
}

TEST(Stack1Test, Test8) {
    stack<std::pair<int, std::string>> st;
    st.push({4, "hello"});
    std::pair<int, std::string> pair1 = st.get_element(0);
    std::pair<int, std::string> result{4, "hello"};
    EXPECT_EQ(pair1, result);
}

TEST(Stack1Test, Test9) {
    stack<std::pair<int, std::string>> st;
    st.push_emplace(4, "hello");
    st.push_emplace(5, "hi");
    st.push_emplace(6, "hoy");
    st.push_emplace(st.get_element(0));
    std::pair<int, std::string> pair = st.head();
    std::pair<int, std::string> result = {4, "hello"};
    EXPECT_EQ(pair, result);
}

TEST(Stack1Test, Test10) {
    stack<std::pair<int, std::string>> st;
    st.push_emplace(4, "hello");
    st.push_emplace(5, "hi");
    st.push_emplace(6, "hoy");
    st.push_emplace(st.get_element(0));
    std::size_t capacity1 = st.get_capacity();
    st.pop();
    std::size_t capacity2 = st.get_capacity();
    EXPECT_EQ(capacity1-1, capacity2);
    std::pair<int, std::string> pair = st.get_element(2);
    std::pair<int, std::string> result = {6, "hoy"};
    EXPECT_EQ(pair, result);
}
