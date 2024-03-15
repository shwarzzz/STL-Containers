#include <gtest/gtest.h>

#include <queue>

#include "../s21_containers.h"

TEST(QueueMemberFunctions, TestDefault) {
  std::queue<int> std_queue;
  s21::queue<int> s21_queue;
  ASSERT_EQ(std_queue.size(), std_queue.size());
  ASSERT_EQ(std_queue.empty(), std_queue.empty());
}

TEST(QueueMemberFunctions, TestInitializerQueue_1) {
  s21::queue<int> s21_queue{55, 234, 1, 6};
  std::queue<int> std_queue;
  std_queue.push(55);
  std_queue.push(234);
  std_queue.push(1);
  std_queue.push(6);
  ASSERT_EQ(std_queue.size(), std_queue.size());
  while (!s21_queue.empty()) {
    ASSERT_EQ(s21_queue.front(), std_queue.front());
    s21_queue.pop();
    std_queue.pop();
  }
}

TEST(QueueMemberFunctions, TestInitializerQueue_2) {
  s21::queue<int> s21_queue{55};
  std::queue<int> std_queue;
  std_queue.push(55);
  ASSERT_EQ(std_queue.size(), std_queue.size());
  while (!s21_queue.empty()) {
    ASSERT_EQ(s21_queue.front(), std_queue.front());
    s21_queue.pop();
    std_queue.pop();
  }
}

TEST(QueueMemberFunctions, TestInitializerQueue_3) {
  s21::queue<int> s21_queue{55, 234, 1, 6};
  s21_queue.push(11);
  std::queue<int> std_queue;
  std_queue.push(55);
  std_queue.push(234);
  std_queue.push(1);
  std_queue.push(6);
  std_queue.push(11);
  ASSERT_EQ(std_queue.size(), std_queue.size());
  while (!s21_queue.empty()) {
    ASSERT_EQ(s21_queue.front(), std_queue.front());
    s21_queue.pop();
    std_queue.pop();
  }
}

TEST(QueueMemberFunctions, TestCopy_1) {
  s21::queue<int> s21_queue{1};
  std::queue<int> std_queue;
  std_queue.push(1);

  s21::queue<int> s21_copy(s21_queue);
  std::queue<int> std_copy(std_queue);

  ASSERT_EQ(s21_queue.size(), std_queue.size());
  ASSERT_EQ(s21_copy.size(), std_copy.size());

  while (!s21_queue.empty()) {
    ASSERT_EQ(s21_queue.front(), std_queue.front());
    s21_queue.pop();
    std_queue.pop();

    ASSERT_EQ(s21_copy.front(), std_copy.front());
    s21_copy.pop();
    std_copy.pop();
  }
}

TEST(QueueMemberFunctions, TestCopy_2) {
  s21::queue<int> s21_queue;
  std::queue<int> std_queue;

  s21::queue<int> s21_copy(s21_queue);
  std::queue<int> std_copy(std_queue);

  ASSERT_EQ(s21_queue.size(), std_queue.size());
  ASSERT_EQ(s21_copy.size(), std_copy.size());

  ASSERT_EQ(s21_queue.empty(), std_queue.empty());
  ASSERT_EQ(s21_copy.empty(), std_copy.empty());
}

TEST(QueueMemberFunctions, TestCopy_3) {
  s21::queue<int> s21_queue{1, 5, 2, 3, 4, 5, 5, 11};
  std::queue<int> std_queue;

  std_queue.push(1);
  std_queue.push(5);
  std_queue.push(2);
  std_queue.push(3);
  std_queue.push(4);
  std_queue.push(5);
  std_queue.push(5);
  std_queue.push(11);

  s21::queue<int> s21_copy(s21_queue);
  std::queue<int> std_copy(std_queue);

  ASSERT_EQ(s21_queue.size(), std_queue.size());
  ASSERT_EQ(s21_copy.size(), std_copy.size());

  while (!s21_queue.empty()) {
    ASSERT_EQ(s21_queue.front(), std_queue.front());
    s21_queue.pop();
    std_queue.pop();

    ASSERT_EQ(s21_copy.front(), std_copy.front());
    s21_copy.pop();
    std_copy.pop();
  }
}

TEST(QueueMemberFunctions, TestMove_1) {
  s21::queue<int> s21_queue{1};
  std::queue<int> std_queue;
  std_queue.push(1);

  s21::queue<int> s21_move = std::move(s21_queue);
  std::queue<int> std_move = std::move(std_queue);

  ASSERT_EQ(s21_move.size(), std_move.size());

  while (!s21_move.empty()) {
    ASSERT_EQ(s21_move.front(), std_move.front());
    s21_move.pop();
    std_move.pop();
  }
}

TEST(QueueMemberFunctions, TestMove_2) {
  s21::queue<int> s21_queue;
  std::queue<int> std_queue;

  s21::queue<int> s21_move = std::move(s21_queue);
  std::queue<int> std_move = std::move(std_queue);

  ASSERT_EQ(s21_move.size(), std_move.size());
  ASSERT_EQ(s21_move.empty(), std_move.empty());
}

TEST(QueueMemberFunctions, TestMove_3) {
  s21::queue<int> s21_queue{1, 5, 2, 3, 4, 5, 5, 11};
  std::queue<int> std_queue;

  std_queue.push(1);
  std_queue.push(5);
  std_queue.push(2);
  std_queue.push(3);
  std_queue.push(4);
  std_queue.push(5);
  std_queue.push(5);
  std_queue.push(11);

  s21::queue<int> s21_move = std::move(s21_queue);
  std::queue<int> std_move = std::move(std_queue);

  ASSERT_EQ(s21_move.size(), std_move.size());

  while (!s21_move.empty()) {
    ASSERT_EQ(s21_move.front(), std_move.front());
    s21_move.pop();
    std_move.pop();
  }
}

TEST(QueueMemberFunctions, TestCopyOperator_1) {
  s21::queue<int> s21_queue{1, 5, 2, 3, 4, 5, 5, 11};
  std::queue<int> std_queue;

  std_queue.push(1);
  std_queue.push(5);
  std_queue.push(2);
  std_queue.push(3);
  std_queue.push(4);
  std_queue.push(5);
  std_queue.push(5);
  std_queue.push(11);

  s21::queue<int> s21_copy;
  s21_copy = s21_queue;
  std::queue<int> std_copy;
  std_copy = std_queue;

  ASSERT_EQ(s21_copy.size(), std_copy.size());
  ASSERT_EQ(s21_queue.size(), std_queue.size());

  while (!s21_queue.empty()) {
    ASSERT_EQ(s21_queue.front(), std_queue.front());
    s21_queue.pop();
    std_queue.pop();

    ASSERT_EQ(s21_copy.front(), std_copy.front());
    s21_copy.pop();
    std_copy.pop();
  }
}

TEST(QueueMemberFunctions, TestCopyOperator_2) {
  s21::queue<int> s21_queue{1, 5, 2, 3, 4, 5, 5, 11};
  std::queue<int> std_queue;

  std_queue.push(1);
  std_queue.push(5);
  std_queue.push(2);
  std_queue.push(3);
  std_queue.push(4);
  std_queue.push(5);
  std_queue.push(5);
  std_queue.push(11);

  s21::queue<int> s21_copy{5, 5, 11};
  s21_copy = s21_queue;
  std::queue<int> std_copy;

  std_copy.push(5);
  std_copy.push(5);
  std_copy.push(11);

  std_copy = std_queue;

  ASSERT_EQ(s21_copy.size(), std_copy.size());
  ASSERT_EQ(s21_queue.size(), std_queue.size());

  while (!s21_queue.empty()) {
    ASSERT_EQ(s21_queue.front(), std_queue.front());
    s21_queue.pop();
    std_queue.pop();

    ASSERT_EQ(s21_copy.front(), std_copy.front());
    s21_copy.pop();
    std_copy.pop();
  }
}

TEST(QueueMemberFunctions, TestCopyOperator_3) {
  s21::queue<int> s21_queue;
  std::queue<int> std_queue;

  s21::queue<int> s21_copy{5, 5, 11};
  s21_copy = s21_queue;

  std::queue<int> std_copy;
  std_copy.push(5);
  std_copy.push(5);
  std_copy.push(11);
  std_copy = std_queue;

  ASSERT_EQ(s21_copy.size(), std_copy.size());
  ASSERT_EQ(s21_queue.size(), std_queue.size());
  ASSERT_EQ(s21_copy.empty(), std_copy.empty());
  ASSERT_EQ(s21_queue.empty(), std_queue.empty());
}

TEST(QueueMemberFunctions, TestCopyOperator_4) {
  s21::queue<int> s21_queue;
  std::queue<int> std_queue;

  s21::queue<int> s21_copy;
  s21_copy = s21_queue;

  std::queue<int> std_copy;
  std_copy = std_queue;

  ASSERT_EQ(s21_copy.size(), std_copy.size());
  ASSERT_EQ(s21_queue.size(), std_queue.size());
  ASSERT_EQ(s21_copy.empty(), std_copy.empty());
  ASSERT_EQ(s21_queue.empty(), std_queue.empty());
}

TEST(QueueMemberFunctions, TestMoveOperator_1) {
  s21::queue<int> s21_queue{1, 5, 2, 3, 4, 5, 5, 11};
  std::queue<int> std_queue;

  std_queue.push(1);
  std_queue.push(5);
  std_queue.push(2);
  std_queue.push(3);
  std_queue.push(4);
  std_queue.push(5);
  std_queue.push(5);
  std_queue.push(11);

  s21::queue<int> s21_move;
  s21_move = std::move(s21_queue);
  std::queue<int> std_move;
  std_move = std::move(std_queue);

  ASSERT_EQ(s21_move.size(), std_move.size());

  while (!s21_move.empty()) {
    ASSERT_EQ(s21_move.front(), std_move.front());
    s21_move.pop();
    std_move.pop();
  }
}

TEST(QueueMemberFunctions, TestMoveOperator_2) {
  s21::queue<int> s21_queue{1, 5, 2, 3, 4, 5, 5, 11};
  std::queue<int> std_queue;

  std_queue.push(1);
  std_queue.push(5);
  std_queue.push(2);
  std_queue.push(3);
  std_queue.push(4);
  std_queue.push(5);
  std_queue.push(5);
  std_queue.push(11);

  s21::queue<int> s21_move{5, 5, 11};
  s21_move = std::move(s21_queue);
  std::queue<int> std_move;

  std_move.push(5);
  std_move.push(5);
  std_move.push(11);

  std_move = std::move(std_queue);

  ASSERT_EQ(s21_move.size(), std_move.size());

  while (!s21_move.empty()) {
    ASSERT_EQ(s21_move.front(), std_move.front());
    s21_move.pop();
    std_move.pop();
  }
}

TEST(QueueMemberFunctions, TestMoveOperator_3) {
  s21::queue<int> s21_queue;
  std::queue<int> std_queue;

  s21::queue<int> s21_move{5, 5, 11};
  s21_move = std::move(s21_queue);

  std::queue<int> std_move;
  std_move.push(5);
  std_move.push(5);
  std_move.push(11);
  std_move = std::move(std_queue);

  ASSERT_EQ(s21_move.size(), std_move.size());
  ASSERT_EQ(s21_move.empty(), std_move.empty());
}

TEST(QueueMemberFunctions, TestMoveOperator_4) {
  s21::queue<int> s21_queue;
  std::queue<int> std_queue;

  s21::queue<int> s21_move;
  s21_move = std::move(s21_queue);

  std::queue<int> std_move;
  std_move = std::move(std_queue);

  ASSERT_EQ(s21_move.size(), std_move.size());
  ASSERT_EQ(s21_move.empty(), std_move.empty());
}

TEST(QueueMemberFunctions, TestDestructor) {
  s21::queue<int>* s21_queue = new s21::queue<int>{1, 5, 2, 3, 4, 5, 5, 11};
  std::queue<int>* std_queue = new std::queue<int>;

  std_queue->push(1);
  std_queue->push(5);
  std_queue->push(2);
  std_queue->push(3);
  std_queue->push(4);
  std_queue->push(5);
  std_queue->push(5);
  std_queue->push(11);

  delete s21_queue;
  delete std_queue;
}

TEST(QueueCapacity, TestSize_1) {
  std::queue<int> std_queue;
  s21::queue<int> s21_queue;
  ASSERT_EQ(std_queue.size(), s21_queue.size());
}

TEST(QueueCapacity, TestSize_2) {
  std::queue<int> std_queue;
  s21::queue<int> s21_queue;
  std_queue.push(213);
  std_queue.push(2);
  std_queue.push(13);
  std_queue.push(21);
  s21_queue.push(213);
  s21_queue.push(2);
  s21_queue.push(13);
  s21_queue.push(21);
  ASSERT_EQ(std_queue.size(), s21_queue.size());
}

TEST(QueueCapacity, TestSize_3) {
  std::queue<char> std_queue;
  s21::queue<char> s21_queue;
  std_queue.push('r');
  std_queue.push('t');
  std_queue.push('e');
  std_queue.push('s');
  s21_queue.push('r');
  s21_queue.push('t');
  s21_queue.push('e');
  s21_queue.push('s');
  std_queue.pop();
  std_queue.pop();
  std_queue.pop();
  s21_queue.pop();
  s21_queue.pop();
  s21_queue.pop();
  ASSERT_EQ(std_queue.size(), s21_queue.size());
}

TEST(QueueCapacity, TestEmpty_1) {
  std::queue<char> std_queue;
  s21::queue<char> s21_queue;
  std::queue<char> std_queue2 = std_queue;
  s21::queue<char> s21_queue2 = s21_queue2;
  ASSERT_EQ(std_queue2.empty(), s21_queue2.empty());
}

TEST(QueueCapacity, TestEmpty_2) {
  std::queue<char> std_queue;
  s21::queue<char> s21_queue{'1', '3', '2'};
  std_queue.push('1');
  std_queue.push('3');
  std_queue.push('2');
  std::queue<char> std_queue2 = std_queue;
  s21::queue<char> s21_queue2 = std::move(s21_queue);
  ASSERT_EQ(std_queue2.empty(), s21_queue2.empty());
}

TEST(QueueCapacity, TestEmpty_3) {
  std::queue<int> std_queue;
  s21::queue<int> s21_queue{66, 55, 44};
  std_queue.push(66);
  std_queue.push(55);
  std_queue.push(44);
  std::queue<int> std_queue2;
  std_queue2 = std_queue;
  s21::queue<int> s21_queue2;
  s21_queue2 = s21_queue;
  ASSERT_EQ(std_queue2.empty(), s21_queue2.empty());
}

TEST(QueueAccess, TestFront_1) {
  std::queue<double> std_queue;
  s21::queue<double> s21_queue;
  std::queue<double> std_queue2;
  s21::queue<double> s21_queue2;
  std_queue.push(11.1);
  std_queue.push(22.1);
  std_queue.push(33.1);
  s21_queue.push(11.1);
  s21_queue.push(22.1);
  s21_queue.push(33.1);
  s21_queue2 = s21_queue;
  std_queue2 = std_queue;
  ASSERT_EQ(std_queue2.front(), s21_queue2.front());
}

TEST(QueueAccess, TestFront_2) {
  std::queue<char> std_queue;
  s21::queue<char> s21_queue{'b', 'n'};
  std_queue.push('b');
  std_queue.push('n');
  ASSERT_EQ(std_queue.front(), s21_queue.front());
}

TEST(QueueAccess, TestFront_3) {
  std::queue<int> std_queue;
  s21::queue<int> s21_queue{978, 987};
  std_queue.push(978);
  std_queue.push(987);
  std::queue<int> std_queue2 = std::move(std_queue);
  s21::queue<int> s21_queue2 = std::move(s21_queue);
  ASSERT_EQ(std_queue2.front(), s21_queue2.front());
}

TEST(QueueAccess, TestBack_1) {
  std::queue<std::string> std_queue;
  s21::queue<std::string> s21_queue{"wwq", "eew", "r",   "d", "f",
                                    "qqq", "d",   "qwe", "d"};
  std_queue.push("wwq");
  std_queue.push("eew");
  std_queue.push("r");
  std_queue.push("d");
  std_queue.push("f");
  std_queue.push("qqq");
  std_queue.push("d");
  std_queue.push("qwe");
  std_queue.push("d");
  ASSERT_EQ(s21_queue.back(), std_queue.back());
}

TEST(QueueAccess, TestBack_2) {
  std::queue<char> std_queue;
  s21::queue<char> s21_queue{'z', 'x', 'c', 'f', '9'};
  std_queue.push('z');
  std_queue.push('x');
  std_queue.push('c');
  std_queue.push('f');
  std_queue.push('9');
  std::queue<char> std_queue2;
  s21::queue<char> s21_queue2;
  s21_queue2 = s21_queue;
  std_queue2 = std_queue;
  ASSERT_EQ(s21_queue2.back(), std_queue2.back());
  ASSERT_EQ(s21_queue.back(), std_queue.back());
}

TEST(QueueAccess, TestBack_3) {
  std::queue<int> std_queue;
  s21::queue<int> s21_queue;
  std_queue.push(11111);
  s21_queue.push(11111);
  std::queue<int> std_queue2 = std_queue;
  s21::queue<int> s21_queue2 = s21_queue;
  ASSERT_EQ(s21_queue2.back(), std_queue2.back());
  ASSERT_EQ(s21_queue.back(), std_queue.back());
}

TEST(QueueModifiers, TestPush_1) {
  std::queue<double> std_queue;
  s21::queue<double> s21_queue;
  s21_queue.push(3.12);
  std_queue.push(3.12);
  std::queue<double> std_queue2 = std_queue;
  s21::queue<double> s21_queue2 = s21_queue;
  std_queue2.push(1.12);
  s21_queue2.push(1.12);
  ASSERT_EQ(s21_queue2.back(), std_queue2.back());
  ASSERT_EQ(s21_queue2.front(), std_queue2.front());
}

TEST(QueueModifiers, TestPush_2) {
  std::queue<int> std_queue;
  s21::queue<int> s21_queue;
  s21_queue.push(123);
  std_queue.push(123);
  s21_queue.push(234);
  std_queue.push(234);
  s21_queue.push(345);
  std_queue.push(345);
  std::queue<int> std_queue2;
  std_queue2 = std::move(std_queue);
  s21::queue<int> s21_queue2;
  s21_queue2 = std::move(s21_queue);
  std_queue2.push(192048);
  s21_queue2.push(192048);
  for (size_t i = 0; i < s21_queue2.size(); i++) {
    ASSERT_EQ(s21_queue2.front(), std_queue2.front());
    s21_queue2.pop();
    std_queue2.pop();
  }
}

TEST(QueueModifiers, TestPush_3) {
  std::queue<char> std_queue;
  s21::queue<char> s21_queue{83};
  std_queue.push('S');
  ASSERT_EQ(std_queue.back(), std_queue.front());
  ASSERT_EQ(s21_queue.back(), s21_queue.front());
}

TEST(QueueModifiers, TestPop_1) {
  std::queue<int> std_queue;
  s21::queue<int> s21_queue{55, 66, 77, 123, 45,  123,
                            77, 88, 99, 111, 122, 133};
  std_queue.push(55);
  std_queue.push(66);
  std_queue.push(77);
  std_queue.push(123);
  std_queue.push(45);
  std_queue.push(123);
  std_queue.push(77);
  std_queue.push(88);
  std_queue.push(99);
  std_queue.push(111);
  std_queue.push(122);
  std_queue.push(133);
  s21_queue.pop();
  s21_queue.pop();
  std_queue.pop();
  std_queue.pop();
  ASSERT_EQ(s21_queue.size(), std_queue.size());
  for (size_t i = 0; i < s21_queue.size(); i++) {
    ASSERT_EQ(s21_queue.front(), std_queue.front());
    s21_queue.pop();
    std_queue.pop();
  }
}

TEST(QueueModifiers, TestPop_2) {
  std::queue<std::string> std_queue;
  s21::queue<std::string> s21_queue{
      "hhhhhhhhhheeeeeeeeeeeeellllllllllloooooooo"
      "_world)))))))))))))))))))))))"};
  std_queue.push(
      "hhhhhhhhhheeeeeeeeeeeeellllllllllloooooooo_world)))))))))))))"
      "))))))))))");
  s21_queue.pop();
  std_queue.pop();
  ASSERT_EQ(s21_queue.empty(), std_queue.empty());
  ASSERT_EQ(s21_queue.size(), std_queue.size());
}

TEST(QueueModifiers, TestPop_3) {
  std::queue<char> std_queue;
  s21::queue<char> s21_queue;
  std_queue.push('2');
  s21_queue.push('2');
  std_queue.pop();
  s21_queue.pop();
  std_queue.push(111);
  s21_queue.push(111);
  std_queue.pop();
  s21_queue.pop();
  std_queue.push(88);
  s21_queue.push(88);
  std_queue.pop();
  s21_queue.pop();
  std_queue.push('8');
  s21_queue.push('8');
  std_queue.pop();
  s21_queue.pop();
  ASSERT_EQ(s21_queue.empty(), std_queue.empty());
  ASSERT_EQ(s21_queue.size(), std_queue.size());
}

TEST(QueueModifiers, TestSwap_1) {
  std::queue<char> std_queue;
  s21::queue<char> s21_queue;
  std::queue<char> std_queue2;
  s21::queue<char> s21_queue2;
  std_queue2 = std_queue;
  s21_queue2 = s21_queue;
  s21_queue2.swap(s21_queue);
  std_queue2.swap(std_queue);
  ASSERT_EQ(s21_queue.empty(), std_queue.empty());
  ASSERT_EQ(s21_queue.size(), std_queue.size());
}

TEST(QueueModifiers, TestSwap_2) {
  std::queue<int> std_queue;
  s21::queue<int> s21_queue{1, 2, 3, 4};
  std::queue<int> std_queue2;
  s21::queue<int> s21_queue2;
  std_queue.push(1);
  std_queue.push(2);
  std_queue.push(3);
  std_queue.push(4);
  s21_queue2.swap(s21_queue);
  std_queue2.swap(std_queue);
  ASSERT_EQ(s21_queue.empty(), std_queue.empty());
  ASSERT_EQ(s21_queue.size(), std_queue.size());
}

TEST(QueueModifiers, TestSwap_3) {
  std::queue<std::string> std_queue;
  s21::queue<std::string> s21_queue{"Rock", "em",
                                    ","
                                    "sock",
                                    "em"};
  std::queue<std::string> std_queue2;
  s21::queue<std::string> s21_queue2;
  std_queue.push("Rock");
  std_queue.push("em");
  std_queue.push(",");
  std_queue.push("sock");
  std_queue.push("em");
  s21_queue2.swap(s21_queue);
  std_queue2.swap(std_queue);
  s21_queue2.pop();
  s21_queue2.pop();
  s21_queue2.pop();
  std_queue2.pop();
  std_queue2.pop();
  std_queue2.pop();
  for (size_t i = 0; i < s21_queue.size(); i++) {
    ASSERT_EQ(s21_queue2.front(), std_queue2.front());
    s21_queue2.pop();
    std_queue2.pop();
  }
}

TEST(QueueInsertMany, TestInsertManyBack_1) {
  std::queue<char> std_queue;
  s21::queue<char> s21_queue;
  std_queue.push('2');
  std_queue.push('r');
  std_queue.push('t');
  std_queue.push('y');
  std_queue.push('k');
  s21_queue.insert_many_back('2', 'r', 't', 'y', 'k');
  for (size_t i = 0; i < s21_queue.size(); i++) {
    ASSERT_EQ(s21_queue.front(), std_queue.front());
    s21_queue.pop();
    std_queue.pop();
  }
}

TEST(QueueInsertMany, TestInsertManyBack_2) {
  std::queue<int> std_queue;
  s21::queue<int> s21_queue{505};
  std_queue.push(505);
  std_queue.push(506);
  s21_queue.insert_many_back(505);
  for (size_t i = 0; i < s21_queue.size(); i++) {
    ASSERT_EQ(s21_queue.front(), std_queue.front());
    s21_queue.pop();
    std_queue.pop();
  }
}

TEST(QueueInsertMany, TestInsertManyBack_3) {
  std::queue<double> std_queue;
  s21::queue<double> s21_queue;
  s21_queue.push(55.44);
  s21_queue.push(66.55);
  s21_queue.push(77.66);
  s21_queue.push(88.77);
  std_queue.push(55.44);
  std_queue.push(66.55);
  std_queue.push(77.66);
  std_queue.push(88.77);
  std::queue<double> std_queue2 = std_queue;
  s21::queue<double> s21_queue2 = s21_queue;
  std_queue2.push(11.22);
  std_queue2.push(22.33);
  std_queue2.push(44.55);
  s21_queue2.insert_many_back(11.22, 22.33, 44.55);
  for (size_t i = 0; i < s21_queue.size(); i++) {
    ASSERT_EQ(s21_queue.front(), std_queue.front());
    s21_queue.pop();
    std_queue.pop();
  }
}

TEST(QueueCombo, Test_1) {
  std::queue<double> std_queue;
  s21::queue<double> s21_queue{1.1};
  std::queue<double> std_queue2;
  s21::queue<double> s21_queue2;
  std_queue.push(1.1);
  std_queue2 = std_queue;
  s21_queue2 = s21_queue;
  std_queue.push(11.11);
  std_queue.push(22.22);
  s21_queue.push(11.11);
  s21_queue.push(22.22);
  s21_queue2.swap(s21_queue);
  std_queue2.swap(std_queue);
  s21_queue2.pop();
  std_queue2.pop();
  ASSERT_EQ(s21_queue.empty(), std_queue.empty());
  ASSERT_EQ(s21_queue.size(), std_queue.size());
}

TEST(QueueCombo, Test_2) {
  std::queue<int> std_queue;
  s21::queue<int> s21_queue;
  std::queue<int> std_queue2;
  s21::queue<int> s21_queue2;
  std_queue.push(1111);
  std_queue.push(2222);
  s21_queue.push(1111);
  s21_queue.push(2222);
  std_queue2.push(3333);
  std_queue2.push(4444);
  s21_queue2.push(3333);
  s21_queue2.push(4444);
  s21_queue2.swap(s21_queue);
  std_queue2.swap(std_queue);
  s21_queue2.pop();
  std_queue2.pop();
  s21_queue2.push(s21_queue.front() + s21_queue2.size() + 111);
  std_queue2.push(std_queue.front() + std_queue2.size() + 111);
  for (size_t i = 0; i < s21_queue2.size(); i++) {
    ASSERT_EQ(s21_queue2.front(), std_queue2.front());
    s21_queue2.pop();
    std_queue2.pop();
  }
}

TEST(QueueCombo, Test_3) {
  std::queue<std::string> std_queue;
  s21::queue<std::string> s21_queue{"qwerty", "asdfg", "zxcvb", "qazwsx",
                                    "edcrfv"};
  s21::queue<std::string> s21_queue2{"add1"};
  s21::queue<std::string> s21_queue3{"add2"};
  s21::queue<std::string> s21_queue4{"add3"};
  std_queue.push("qwerty");
  std_queue.push("asdfg");
  std_queue.push("zxcvb");
  std_queue.push("qazwsx");
  std_queue.push("edcrfv");
  std_queue.push("add1");
  std_queue.push("add2");
  std_queue.push("add3");
  s21_queue.insert_many_back(s21_queue2.front(), s21_queue3.front(),
                             s21_queue4.back());
  s21_queue.pop();
  std_queue.pop();
  for (size_t i = 0; i < s21_queue.size(); i++) {
    ASSERT_EQ(s21_queue.front(), std_queue.front());
    s21_queue.pop();
    std_queue.pop();
  }
}