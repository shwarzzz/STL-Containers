#include <gtest/gtest.h>

#include <stack>

#include "../s21_containers.h"

TEST(StackMemberFunctions, TestDefault) {
  s21::stack<int> s21_stack;
  std::stack<int> std_stack;

  ASSERT_EQ(s21_stack.size(), std_stack.size());
  ASSERT_EQ(s21_stack.empty(), std_stack.empty());
}

TEST(StackMemberFunctions, TestInitializerList_1) {
  s21::stack<int> s21_stack{1, 5, 2, 3, 4, 5, 5, 11};
  std::stack<int> std_stack;

  std_stack.push(1);
  std_stack.push(5);
  std_stack.push(2);
  std_stack.push(3);
  std_stack.push(4);
  std_stack.push(5);
  std_stack.push(5);
  std_stack.push(11);

  ASSERT_EQ(s21_stack.size(), std_stack.size());

  while (!s21_stack.empty()) {
    ASSERT_EQ(s21_stack.top(), std_stack.top());
    s21_stack.pop();
    std_stack.pop();
  }
}

TEST(StackMemberFunctions, TestInitializerList_2) {
  s21::stack<int> s21_stack{1};
  std::stack<int> std_stack;

  std_stack.push(1);

  ASSERT_EQ(s21_stack.size(), std_stack.size());

  while (!s21_stack.empty()) {
    ASSERT_EQ(s21_stack.top(), std_stack.top());
    s21_stack.pop();
    std_stack.pop();
  }
}

TEST(StackMemberFunctions, TestCopy_1) {
  s21::stack<int> s21_stack{1};
  std::stack<int> std_stack;
  std_stack.push(1);

  s21::stack<int> s21_copy(s21_stack);
  std::stack<int> std_copy(std_stack);

  ASSERT_EQ(s21_stack.size(), std_stack.size());
  ASSERT_EQ(s21_copy.size(), std_copy.size());

  while (!s21_stack.empty()) {
    ASSERT_EQ(s21_stack.top(), std_stack.top());
    s21_stack.pop();
    std_stack.pop();

    ASSERT_EQ(s21_copy.top(), std_copy.top());
    s21_copy.pop();
    std_copy.pop();
  }
}

TEST(StackMemberFunctions, TestCopy_2) {
  s21::stack<int> s21_stack;
  std::stack<int> std_stack;

  s21::stack<int> s21_copy(s21_stack);
  std::stack<int> std_copy(std_stack);

  ASSERT_EQ(s21_stack.size(), std_stack.size());
  ASSERT_EQ(s21_copy.size(), std_copy.size());

  ASSERT_EQ(s21_stack.empty(), std_stack.empty());
  ASSERT_EQ(s21_copy.empty(), std_copy.empty());
}

TEST(StackMemberFunctions, TestCopy_3) {
  s21::stack<int> s21_stack{1, 5, 2, 3, 4, 5, 5, 11};
  std::stack<int> std_stack;

  std_stack.push(1);
  std_stack.push(5);
  std_stack.push(2);
  std_stack.push(3);
  std_stack.push(4);
  std_stack.push(5);
  std_stack.push(5);
  std_stack.push(11);

  s21::stack<int> s21_copy(s21_stack);
  std::stack<int> std_copy(std_stack);

  ASSERT_EQ(s21_stack.size(), std_stack.size());
  ASSERT_EQ(s21_copy.size(), std_copy.size());

  while (!s21_stack.empty()) {
    ASSERT_EQ(s21_stack.top(), std_stack.top());
    s21_stack.pop();
    std_stack.pop();

    ASSERT_EQ(s21_copy.top(), std_copy.top());
    s21_copy.pop();
    std_copy.pop();
  }
}

TEST(StackMemberFunctions, TestMove_1) {
  s21::stack<int> s21_stack{1};
  std::stack<int> std_stack;
  std_stack.push(1);

  s21::stack<int> s21_move = std::move(s21_stack);
  std::stack<int> std_move = std::move(std_stack);

  ASSERT_EQ(s21_move.size(), std_move.size());

  while (!s21_move.empty()) {
    ASSERT_EQ(s21_move.top(), std_move.top());
    s21_move.pop();
    std_move.pop();
  }
}

TEST(StackMemberFunctions, TestMove_2) {
  s21::stack<int> s21_stack;
  std::stack<int> std_stack;

  s21::stack<int> s21_move = std::move(s21_stack);
  std::stack<int> std_move = std::move(std_stack);

  ASSERT_EQ(s21_move.size(), std_move.size());
  ASSERT_EQ(s21_move.empty(), std_move.empty());
}

TEST(StackMemberFunctions, TestMove_3) {
  s21::stack<int> s21_stack{1, 5, 2, 3, 4, 5, 5, 11};
  std::stack<int> std_stack;

  std_stack.push(1);
  std_stack.push(5);
  std_stack.push(2);
  std_stack.push(3);
  std_stack.push(4);
  std_stack.push(5);
  std_stack.push(5);
  std_stack.push(11);

  s21::stack<int> s21_move = std::move(s21_stack);
  std::stack<int> std_move = std::move(std_stack);

  ASSERT_EQ(s21_move.size(), std_move.size());

  while (!s21_move.empty()) {
    ASSERT_EQ(s21_move.top(), std_move.top());
    s21_move.pop();
    std_move.pop();
  }
}

TEST(StackMemberFunctions, TestCopyOperator_1) {
  s21::stack<int> s21_stack{1, 5, 2, 3, 4, 5, 5, 11};
  std::stack<int> std_stack;

  std_stack.push(1);
  std_stack.push(5);
  std_stack.push(2);
  std_stack.push(3);
  std_stack.push(4);
  std_stack.push(5);
  std_stack.push(5);
  std_stack.push(11);

  s21::stack<int> s21_copy;
  s21_copy = s21_stack;
  std::stack<int> std_copy;
  std_copy = std_stack;

  ASSERT_EQ(s21_copy.size(), std_copy.size());
  ASSERT_EQ(s21_stack.size(), std_stack.size());

  while (!s21_stack.empty()) {
    ASSERT_EQ(s21_stack.top(), std_stack.top());
    s21_stack.pop();
    std_stack.pop();

    ASSERT_EQ(s21_copy.top(), std_copy.top());
    s21_copy.pop();
    std_copy.pop();
  }
}

TEST(StackMemberFunctions, TestCopyOperator_2) {
  s21::stack<int> s21_stack{1, 5, 2, 3, 4, 5, 5, 11};
  std::stack<int> std_stack;

  std_stack.push(1);
  std_stack.push(5);
  std_stack.push(2);
  std_stack.push(3);
  std_stack.push(4);
  std_stack.push(5);
  std_stack.push(5);
  std_stack.push(11);

  s21::stack<int> s21_copy{5, 5, 11};
  s21_copy = s21_stack;
  std::stack<int> std_copy;

  std_copy.push(5);
  std_copy.push(5);
  std_copy.push(11);

  std_copy = std_stack;

  ASSERT_EQ(s21_copy.size(), std_copy.size());
  ASSERT_EQ(s21_stack.size(), std_stack.size());

  while (!s21_stack.empty()) {
    ASSERT_EQ(s21_stack.top(), std_stack.top());
    s21_stack.pop();
    std_stack.pop();

    ASSERT_EQ(s21_copy.top(), std_copy.top());
    s21_copy.pop();
    std_copy.pop();
  }
}

TEST(StackMemberFunctions, TestCopyOperator_3) {
  s21::stack<int> s21_stack;
  std::stack<int> std_stack;

  s21::stack<int> s21_copy{5, 5, 11};
  s21_copy = s21_stack;

  std::stack<int> std_copy;
  std_copy.push(5);
  std_copy.push(5);
  std_copy.push(11);
  std_copy = std_stack;

  ASSERT_EQ(s21_copy.size(), std_copy.size());
  ASSERT_EQ(s21_stack.size(), std_stack.size());
  ASSERT_EQ(s21_copy.empty(), std_copy.empty());
  ASSERT_EQ(s21_stack.empty(), std_stack.empty());
}

TEST(StackMemberFunctions, TestCopyOperator_4) {
  s21::stack<int> s21_stack;
  std::stack<int> std_stack;

  s21::stack<int> s21_copy;
  s21_copy = s21_stack;

  std::stack<int> std_copy;
  std_copy = std_stack;

  ASSERT_EQ(s21_copy.size(), std_copy.size());
  ASSERT_EQ(s21_stack.size(), std_stack.size());
  ASSERT_EQ(s21_copy.empty(), std_copy.empty());
  ASSERT_EQ(s21_stack.empty(), std_stack.empty());
}

TEST(StackMemberFunctions, TestMoveOperator_1) {
  s21::stack<int> s21_stack{1, 5, 2, 3, 4, 5, 5, 11};
  std::stack<int> std_stack;

  std_stack.push(1);
  std_stack.push(5);
  std_stack.push(2);
  std_stack.push(3);
  std_stack.push(4);
  std_stack.push(5);
  std_stack.push(5);
  std_stack.push(11);

  s21::stack<int> s21_move;
  s21_move = std::move(s21_stack);
  std::stack<int> std_move;
  std_move = std::move(std_stack);

  ASSERT_EQ(s21_move.size(), std_move.size());

  while (!s21_move.empty()) {
    ASSERT_EQ(s21_move.top(), std_move.top());
    s21_move.pop();
    std_move.pop();
  }
}

TEST(StackMemberFunctions, TestMoveOperator_2) {
  s21::stack<int> s21_stack{1, 5, 2, 3, 4, 5, 5, 11};
  std::stack<int> std_stack;

  std_stack.push(1);
  std_stack.push(5);
  std_stack.push(2);
  std_stack.push(3);
  std_stack.push(4);
  std_stack.push(5);
  std_stack.push(5);
  std_stack.push(11);

  s21::stack<int> s21_move{5, 5, 11};
  s21_move = std::move(s21_stack);
  std::stack<int> std_move;

  std_move.push(5);
  std_move.push(5);
  std_move.push(11);

  std_move = std::move(std_stack);

  ASSERT_EQ(s21_move.size(), std_move.size());

  while (!s21_move.empty()) {
    ASSERT_EQ(s21_move.top(), std_move.top());
    s21_move.pop();
    std_move.pop();
  }
}

TEST(StackMemberFunctions, TestMoveOperator_3) {
  s21::stack<int> s21_stack;
  std::stack<int> std_stack;

  s21::stack<int> s21_move{5, 5, 11};
  s21_move = std::move(s21_stack);

  std::stack<int> std_move;
  std_move.push(5);
  std_move.push(5);
  std_move.push(11);
  std_move = std::move(std_stack);

  ASSERT_EQ(s21_move.size(), std_move.size());
  ASSERT_EQ(s21_move.empty(), std_move.empty());
}

TEST(StackMemberFunctions, TestMoveOperator_4) {
  s21::stack<int> s21_stack;
  std::stack<int> std_stack;

  s21::stack<int> s21_move;
  s21_move = std::move(s21_stack);

  std::stack<int> std_move;
  std_move = std::move(std_stack);

  ASSERT_EQ(s21_move.size(), std_move.size());
  ASSERT_EQ(s21_move.empty(), std_move.empty());
}

TEST(StackMemberFunctions, TestDestructor) {
  s21::stack<int>* s21_stack = new s21::stack<int>{1, 5, 2, 3, 4, 5, 5, 11};
  std::stack<int>* std_stack = new std::stack<int>;

  std_stack->push(1);
  std_stack->push(5);
  std_stack->push(2);
  std_stack->push(3);
  std_stack->push(4);
  std_stack->push(5);
  std_stack->push(5);
  std_stack->push(11);

  delete s21_stack;
  delete std_stack;
}

TEST(StackElementAccess, TestTop_1) {
  s21::stack<int> s21_stack{1, 5, 2, 3, 4, 5, 5, 11};
  std::stack<int> std_stack;

  std_stack.push(1);
  std_stack.push(5);
  std_stack.push(2);
  std_stack.push(3);
  std_stack.push(4);
  std_stack.push(5);
  std_stack.push(5);
  std_stack.push(11);

  while (!s21_stack.empty()) {
    ASSERT_EQ(s21_stack.top(), std_stack.top());
    s21_stack.pop();
    std_stack.pop();
  }
}

TEST(StackElementAccess, TestTop_2) {
  std::stack<int> std_stack;
  s21::stack<int> s21_stack{33, 11, 22, 44};
  std_stack.push(33);
  std_stack.push(11);
  std_stack.push(22);
  std_stack.push(44);
  ASSERT_EQ(std_stack.top(), s21_stack.top());
}

TEST(StackElementAccess, TestTop_3) {
  std::stack<int> std_stack;
  s21::stack<int> s21_stack{33, 11, 22, 44};
  s21::stack<int> s21_stack2 = s21_stack;
  std_stack.push(33);
  std_stack.push(11);
  std_stack.push(22);
  std_stack.push(44);
  ASSERT_EQ(std_stack.top(), s21_stack2.top());
}

TEST(StackCapacity, TestSize_1) {
  std::stack<int> std_stack;
  s21::stack<int> s21_stack;
  std_stack.push(1);
  std_stack.push(2);
  std_stack.push(3);
  s21_stack.push(1);
  s21_stack.push(2);
  s21_stack.push(3);
  ASSERT_EQ(s21_stack.size(), std_stack.size());
}

TEST(StackCapacity, TestSize_2) {
  std::stack<double> std_stack;
  s21::stack<double> s21_stack;
  ASSERT_EQ(s21_stack.size(), std_stack.size());
}

TEST(StackCapacity, TestSize_3) {
  std::stack<int> std_stack;
  s21::stack<int> s21_stack;
  std_stack.push(1);
  std_stack.push(2);
  std_stack.push(109238);
  s21_stack.push(1);
  s21_stack.push(2);
  s21_stack.push(109238);
  std_stack.pop();
  s21_stack.pop();
  ASSERT_EQ(s21_stack.size(), std_stack.size());
  ASSERT_EQ(s21_stack.top(), std_stack.top());
}

TEST(StackCapacity, TestSize_4) {
  std::stack<char> std_stack;
  s21::stack<char> s21_stack;
  std_stack.push('k');
  s21_stack.push('k');
  std_stack.push('i');
  s21_stack.push('i');
  std_stack.pop();
  s21_stack.pop();
  ASSERT_EQ(s21_stack.size(), std_stack.size());
  ASSERT_EQ(s21_stack.top(), std_stack.top());
}

TEST(StackCapacity, TestSize_5) {
  std::stack<double> std_stack;
  s21::stack<double> s21_stack;
  std_stack.push(1.222211);
  s21_stack.push(1.222211);
  std_stack.push(2.333318);
  s21_stack.push(2.333318);
  std_stack.push(3.312314);
  s21_stack.push(3.312314);
  std_stack.pop();
  s21_stack.pop();
  std_stack.pop();
  s21_stack.pop();
  std_stack.pop();
  s21_stack.pop();
  ASSERT_EQ(s21_stack.size(), std_stack.size());
}

TEST(StackCapacity, TestEmpty_1) {
  std::stack<char> std_stack;
  s21::stack<char> s21_stack;
  std_stack.push('1');
  std_stack.push('1');
  std_stack.push('2');
  s21_stack.push('2');
  s21_stack.push('3');
  s21_stack.push('3');
  ASSERT_EQ(s21_stack.empty(), std_stack.empty());
}

TEST(StackCapacity, TestEmpty_2) {
  std::stack<char> std_stack;
  s21::stack<char> s21_stack;
  ASSERT_EQ(s21_stack.empty(), std_stack.empty());
}

TEST(StackCapacity, TestEmpty_3) {
  std::stack<char> std_stack;
  s21::stack<char> s21_stack{1, 2, 3};
  std_stack.push(1);
  std_stack.push(2);
  std_stack.push(3);
  ASSERT_EQ(s21_stack.empty(), std_stack.empty());
}

TEST(StackModifiers, TestPush_1) {
  std::stack<double> std_stack;
  s21::stack<double> s21_stack{33.1, 22.1, 5.111, 8.888, 9.01};
  s21::stack<double> s21_stack2;
  s21_stack2 = std::move(s21_stack);
  std_stack.push(33.1);
  std_stack.push(22.1);
  std_stack.push(5.111);
  std_stack.push(8.888);
  std_stack.push(9.01);
  ASSERT_EQ(std_stack.top(), s21_stack2.top());
}

TEST(StackModifiers, TestPush_2) {
  std::stack<char> std_stack;
  s21::stack<char> s21_stack{'1', 'w', 't', 'j'};
  s21::stack<char> s21_stack2 = std::move(s21_stack);
  std_stack.push('1');
  std_stack.push('w');
  std_stack.push('t');
  std_stack.push('j');
  ASSERT_EQ(std_stack.top(), s21_stack2.top());
}

TEST(StackModifiers, TestPush_3) {
  std::stack<int> std_stack;
  s21::stack<int> s21_stack{1};
  s21::stack<int> s21_stack2 = std::move(s21_stack);
  s21_stack2.push(5);
  s21_stack2.push(10);
  s21_stack2.push(15);
  std_stack.push(1);
  std_stack.push(5);
  std_stack.push(10);
  std_stack.push(15);
  ASSERT_EQ(std_stack.top(), s21_stack2.top());
}

TEST(StackModifiers, TestPush_4) {
  std::stack<int> std_stack;
  s21::stack<int> s21_stack{1, 5, 15};
  std_stack.push(1);
  std_stack.push(5);
  std_stack.push(15);
  while (!s21_stack.empty()) {
    ASSERT_EQ(std_stack.top(), s21_stack.top());
    s21_stack.pop();
    std_stack.pop();
  }
  std_stack.push(60);
  s21_stack.push(60);
  std_stack.push(-55);
  s21_stack.push(-55);
  std_stack.push(15);
  s21_stack.push(15);
  while (!s21_stack.empty()) {
    ASSERT_EQ(std_stack.top(), s21_stack.top());
    s21_stack.pop();
    std_stack.pop();
  }
}

TEST(StackModifiers, TestPop_1) {
  std::stack<double> std_stack;
  s21::stack<double> s21_stack{1.1};
  s21::stack<double> s21_stack2;
  s21_stack2 = std::move(s21_stack);
  s21_stack2.push(2.2);
  s21_stack2.push(3.3);
  s21_stack2.push(4.4);
  s21_stack2.pop();
  std_stack.push(1.1);
  std_stack.push(2.2);
  std_stack.push(3.3);
  std_stack.push(4.4);
  std_stack.pop();
  ASSERT_EQ(std_stack.top(), s21_stack2.top());
}

TEST(StackModifiers, TestPop_2) {
  std::stack<double> std_stack;
  s21::stack<double> s21_stack;
  std_stack.push(1.1);
  s21_stack.push(1.1);
  std_stack.pop();
  s21_stack.pop();
  ASSERT_EQ(std_stack.empty(), s21_stack.empty());
}

TEST(StackModifiers, TestSwap_1) {
  std::stack<double> std_stack;
  s21::stack<double> s21_stack;
  std::stack<double> std_stack2;
  s21::stack<double> s21_stack2;
  s21_stack.push(1.1);
  s21_stack.push(2.2);
  s21_stack.push(3.3);
  s21_stack.push(4.4);
  std_stack.push(1.1);
  std_stack.push(2.2);
  std_stack.push(3.3);
  std_stack.push(4.4);
  s21_stack2.swap(s21_stack);
  std_stack2.swap(std_stack);
  for (size_t i = 0; i < s21_stack.size(); i++) {
    ASSERT_EQ(s21_stack2.top(), std_stack2.top());
    s21_stack2.pop();
    std_stack2.pop();
  }
}

TEST(StackModifiers, TestSwap_2) {
  std::stack<char> std_stack;
  s21::stack<char> s21_stack;
  std::stack<char> std_stack2;
  s21::stack<char> s21_stack2;
  s21_stack.push('1');
  s21_stack.push('3');
  std_stack.push('1');
  std_stack.push('3');
  s21_stack2.swap(s21_stack);
  std_stack2.swap(std_stack);
  for (size_t i = 0; i < s21_stack.size(); i++) {
    ASSERT_EQ(s21_stack2.top(), std_stack2.top());
    s21_stack2.pop();
    std_stack2.pop();
  }
}

TEST(StackModifiers, TestSwap_3) {
  std::stack<int> std_stack;
  s21::stack<int> s21_stack;
  std::stack<int> std_stack2;
  s21::stack<int> s21_stack2;
  s21_stack2.push(1);
  s21_stack2.push(3);
  std_stack2.push(1);
  std_stack2.push(3);
  s21_stack2.swap(s21_stack);
  std_stack2.swap(std_stack);
  ASSERT_EQ(s21_stack.empty(), std_stack.empty());
}

TEST(StackInsertMany, TestInsertManyFront_1) {
  std::stack<int> std_stack;
  s21::stack<int> s21_stack;
  std_stack.push(1);
  std_stack.push(2);
  std_stack.push(3);
  s21_stack.insert_many_front(1, 2, 3);
  for (size_t i = 0; i < s21_stack.size(); i++) {
    ASSERT_EQ(s21_stack.top(), std_stack.top());
    s21_stack.pop();
    std_stack.pop();
  }
}

TEST(StackInsertMany, TestInsertManyFront_2) {
  std::stack<double> std_stack;
  s21::stack<double> s21_stack;
  std_stack.push(1.11);
  s21_stack.insert_many_front(1.11);
  ASSERT_EQ(s21_stack.top(), std_stack.top());
}

TEST(StackInsertMany, TestInsertManyFront_3) {
  std::stack<int> std_stack;
  s21::stack<int> s21_stack;
  s21::stack<int> s21_stack2;
  std_stack.push(999);
  std_stack.push(888);
  std_stack.push(777);
  s21_stack2.insert_many_front(999, 888, 777);
  s21_stack.swap(s21_stack2);
  for (size_t i = 0; i < s21_stack.size(); i++) {
    ASSERT_EQ(s21_stack.top(), std_stack.top());
    s21_stack.pop();
    std_stack.pop();
  }
}

TEST(StackInsertMany, TestInsertManyFront_4) {
  std::stack<char> std_stack;
  s21::stack<char> s21_stack;
  s21::stack<char> s21_stack2;
  std_stack.push('f');
  std_stack.push('g');
  s21_stack2.insert_many_front('f', 'g');
  s21_stack = s21_stack2;
  for (size_t i = 0; i < s21_stack.size(); i++) {
    ASSERT_EQ(s21_stack.top(), std_stack.top());
    s21_stack.pop();
    std_stack.pop();
  }
}

TEST(StackCombo, Test_1) {
  std::stack<double> std_stack;
  s21::stack<double> s21_stack;
  std::stack<double> std_stack2;
  s21::stack<double> s21_stack2;
  std_stack.push(1);
  s21_stack.push(1);
  std_stack2.swap(std_stack);
  s21_stack2.swap(s21_stack);
  std_stack2.push((double)std_stack2.size() + 1.2);
  s21_stack2.push((double)s21_stack2.size() + 1.2);
  ASSERT_EQ(s21_stack2.top(), std_stack2.top());
}

TEST(StackCombo, Test_2) {
  s21::stack<int> s21_stack;
  std::stack<int> std_stack;
  ASSERT_EQ(s21_stack.empty(), std_stack.empty());
  s21_stack.push(987651);
  std_stack.push(987651);
  ASSERT_EQ(s21_stack.top(), std_stack.top());
  ASSERT_EQ(s21_stack.empty(), std_stack.empty());
  ASSERT_EQ(s21_stack.size(), std_stack.size());
  s21_stack.pop();
  std_stack.pop();
  ASSERT_EQ(s21_stack.size(), std_stack.size());
}

TEST(StackCombo, Test_3) {
  s21::stack<int> s21_stack;
  s21::stack<int> s21_stack2;
  std::stack<int> std_stack;
  std::stack<int> std_stack2;
  s21_stack.push(123);
  s21_stack.push(12);
  s21_stack.push(1);
  s21_stack.push(3);
  s21_stack.push(4);
  std_stack.push(123);
  std_stack.push(12);
  std_stack.push(1);
  std_stack.push(3);
  std_stack.push(4);
  for (size_t i = 0; i < s21_stack.size(); i++) {
    ASSERT_EQ(s21_stack.top(), std_stack.top());
    s21_stack.pop();
    std_stack.pop();
  }
  ASSERT_EQ(s21_stack.size(), std_stack.size());
  s21_stack2.push(999);
  std_stack2.push(999);
  std_stack.swap(std_stack2);
  s21_stack.swap(s21_stack2);
  ASSERT_EQ(std_stack2.top(), s21_stack2.top());
}