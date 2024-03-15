#include <gtest/gtest.h>

#include <iostream>
#include <vector>

#include "../s21_containers.h"

TEST(VectorMemberfunctions, TestDefault) {
  std::vector<int> std_vector;
  s21::vector<int> s21_vector;

  ASSERT_EQ(std_vector.size(), s21_vector.size());
  ASSERT_EQ(std_vector.capacity(), s21_vector.capacity());
}

TEST(VectorMemberfunctions, TestParam) {
  std::vector<unsigned> std_vector(12);
  s21::vector<unsigned> s21_vector(12);

  ASSERT_EQ(std_vector.size(), s21_vector.size());
  ASSERT_EQ(std_vector.capacity(), s21_vector.capacity());

  for (size_t i = 0; i < std_vector.size(); ++i) {
    ASSERT_EQ(std_vector[i], s21_vector[i]);
  }
}

TEST(VectorMemberfunctions, TestInitializeList) {
  std::vector<int> std_vector{1, 5, 3, 4, 55, 0};
  s21::vector<int> s21_vector{1, 5, 3, 4, 55, 0};

  ASSERT_EQ(std_vector.size(), s21_vector.size());
  ASSERT_EQ(std_vector.capacity(), s21_vector.capacity());

  for (size_t i = 0; i < std_vector.size(); ++i) {
    ASSERT_EQ(std_vector[i], s21_vector[i]);
  }
}

TEST(VectorMemberfunctions, TestCopy) {
  std::vector<double> std_vector{1.23, 5.44, 3, 4, 55.112, 0};
  s21::vector<double> s21_vector{1.23, 5.44, 3, 4, 55.112, 0};

  std::vector<double> std_copy(std_vector);
  s21::vector<double> s21_copy(s21_vector);

  ASSERT_EQ(std_copy.size(), s21_copy.size());
  ASSERT_EQ(std_copy.capacity(), s21_copy.capacity());

  for (size_t i = 0; i < std_vector.size(); ++i) {
    ASSERT_EQ(std_vector[i], s21_vector[i]);
    ASSERT_EQ(std_copy[i], s21_copy[i]);
  }
}

TEST(VectorMemberfunctions, TestMove) {
  std::vector<char> std_vector{'a', 'b', 'a', 'a', '!'};
  s21::vector<char> s21_vector{'a', 'b', 'a', 'a', '!'};

  std::vector<char> std_move(std::move(std_vector));
  s21::vector<char> s21_move(std::move(s21_vector));

  ASSERT_EQ(std_move.size(), s21_move.size());
  ASSERT_EQ(std_move.capacity(), s21_move.capacity());

  for (size_t i = 0; i < std_move.size(); ++i) {
    ASSERT_EQ(std_move[i], s21_move[i]);
  }
}

TEST(VectorMemberfunctions, TestDestructor) {
  std::vector<double>* std_vector = new std::vector<double>{1, 5, 3, 4, 55, 0};
  s21::vector<double>* s21_vector = new s21::vector<double>{1, 5, 3, 4, 55, 0};

  delete std_vector;
  delete s21_vector;
}

TEST(VectorMemberfunctions, TestCopyOperator) {
  std::vector<double> std_vector{1.23, 5.44, 3, 4, 55.112, 0};
  s21::vector<double> s21_vector{1.23, 5.44, 3, 4, 55.112, 0};

  std::vector<double> std_copy{5555555, 5, 1, 3, 4};
  s21::vector<double> s21_copy{123.333};

  std_copy = std_vector;
  s21_copy = s21_vector;

  ASSERT_EQ(std_copy.size(), s21_copy.size());
  ASSERT_EQ(std_copy.capacity(), s21_copy.capacity());

  for (size_t i = 0; i < std_vector.size(); ++i) {
    ASSERT_EQ(std_vector[i], s21_vector[i]);
    ASSERT_EQ(std_copy[i], s21_copy[i]);
  }
}

TEST(VectorMemberfunctions, TestMoveOperator) {
  std::vector<char> std_vector{'a', 'b', 'a', 'a', '!'};
  s21::vector<char> s21_vector{'a', 'b', 'a', 'a', '!'};

  std::vector<char> std_move{'c', 'f'};
  s21::vector<char> s21_move;

  std_move = std::move(std_vector);
  s21_move = std::move(s21_vector);

  ASSERT_EQ(std_move.size(), s21_move.size());
  ASSERT_EQ(std_move.capacity(), s21_move.capacity());

  for (size_t i = 0; i < std_move.size(); ++i) {
    ASSERT_EQ(std_move[i], s21_move[i]);
  }
}

TEST(VectorElementAccess, TestAt) {
  std::vector<std::string> std_vector{"alo", "kuku", "hihi", "haha"};
  s21::vector<std::string> s21_vector{"alo", "kuku", "hihi", "haha"};

  ASSERT_THROW(std_vector.at(4), std::out_of_range);
  ASSERT_THROW(s21_vector.at(4), std::out_of_range);

  std_vector.at(2) = "hehe";
  s21_vector.at(2) = "hehe";

  for (size_t i = 0; i < s21_vector.size(); ++i) {
    ASSERT_EQ(std_vector.at(i), s21_vector.at(i));
  }
}

TEST(VectorElementAccess, TestConstAt) {
  const std::vector<std::string> std_vector{"alo", "kuku", "hihi", "haha"};
  const s21::vector<std::string> s21_vector{"alo", "kuku", "hihi", "haha"};

  ASSERT_THROW(std_vector.at(4), std::out_of_range);
  ASSERT_THROW(s21_vector.at(4), std::out_of_range);

  // std_vector.at(2) = "hehe";
  // s21_vector.at(2) = "hehe";

  for (size_t i = 0; i < s21_vector.size(); ++i) {
    ASSERT_EQ(std_vector.at(i), s21_vector.at(i));
  }
}

TEST(VectorElementAccess, TestBracketOperator) {
  std::vector<std::string> std_vector{"alo", "kuku", "hihi", "haha"};
  s21::vector<std::string> s21_vector{"alo", "kuku", "hihi", "haha"};

  std_vector[2] = "hehe";
  s21_vector[2] = "hehe";

  for (size_t i = 0; i < s21_vector.size(); ++i) {
    ASSERT_EQ(std_vector[i], s21_vector[i]);
  }
}

TEST(VectorElementAccess, TestConstBracketOperator) {
  const std::vector<std::string> std_vector{"alo", "kuku", "hihi", "haha"};
  const s21::vector<std::string> s21_vector{"alo", "kuku", "hihi", "haha"};

  // std_vector[2] = "hehe";
  // s21_vector[2] = "hehe";

  for (size_t i = 0; i < s21_vector.size(); ++i) {
    ASSERT_EQ(std_vector[i], s21_vector[i]);
  }
}

TEST(VectorElementAccess, TestFront) {
  std::vector<std::string> std_vector{"llll", "aaaa"};
  s21::vector<std::string> s21_vector{"llll", "aaaa"};

  ASSERT_EQ(std_vector.front(), s21_vector.front());

  std_vector.front() = "hi";
  s21_vector.front() = std_vector.front();

  ASSERT_EQ(std_vector.front(), s21_vector.front());
}

TEST(VectorElementAccess, TestConstFront) {
  const std::vector<std::string> std_vector{"llll", "aaaa"};
  const s21::vector<std::string> s21_vector{"llll", "aaaa"};

  ASSERT_EQ(std_vector.front(), s21_vector.front());
}

TEST(VectorElementAccess, TestBack) {
  std::vector<std::string> std_vector{"llll", "aaaa"};
  s21::vector<std::string> s21_vector{"llll", "aaaa"};

  ASSERT_EQ(std_vector.back(), s21_vector.back());

  std_vector.back() = "hi";
  s21_vector.back() = std_vector.back();

  ASSERT_EQ(std_vector.back(), s21_vector.back());
}

TEST(VectorElementAccess, TestConstBack) {
  const std::vector<std::string> std_vector{"llll", "aaaa"};
  const s21::vector<std::string> s21_vector{"llll", "aaaa"};

  ASSERT_EQ(std_vector.back(), s21_vector.back());
}

TEST(VectorElementAccess, TestData) {
  std::vector<std::string> std_vector{"llll", "aaaa"};
  s21::vector<std::string> s21_vector{"llll", "aaaa"};

  ASSERT_EQ(*(std_vector.data()), *(s21_vector.data()));

  *(std_vector.data()) = "hi";
  *(s21_vector.data()) = *(std_vector.data());

  ASSERT_EQ(*(std_vector.data()), *(s21_vector.data()));
}

TEST(VectorElementAccess, TestConstData) {
  const std::vector<std::string> std_vector{"llll", "aaaa"};
  const s21::vector<std::string> s21_vector{"llll", "aaaa"};

  // *(std_vector.data()) = "hi";
  // *(s21_vector.data()) = *(std_vector.data());

  ASSERT_EQ(*(std_vector.data()), *(s21_vector.data()));
}

TEST(VectorIterators, TestBeginAndEnd) {
  std::vector<int> std_vector{1, 2, 5, 10, -3, 33};
  s21::vector<int> s21_vector{1, 2, 5, 10, -3, 33};
  auto std_itr = std_vector.begin();
  auto s21_itr = s21_vector.begin();
  ASSERT_EQ(*std_itr, *s21_itr);
  for (; s21_itr != s21_vector.end(); ++s21_itr, ++std_itr) {
    ASSERT_EQ(*std_itr, *s21_itr);
  }
  for (; s21_itr != s21_vector.begin(); --s21_itr, --std_itr) {
    if (s21_itr == s21_vector.end()) {
      continue;
    }
    ASSERT_EQ(*std_itr, *s21_itr);
  }
}

TEST(VectorIterators, TestConstBeginAndEnd) {
  const std::vector<int> std_vector{1, 2, 5, 10, -3, 33};
  const s21::vector<int> s21_vector{1, 2, 5, 10, -3, 33};
  std::vector<int>::const_iterator std_itr;
  std_itr = std_vector.begin();
  s21::vector<int>::const_iterator s21_itr;
  s21_itr = s21_vector.begin();
  ASSERT_EQ(*std_itr, *s21_itr);
  for (; s21_itr != s21_vector.end(); ++s21_itr, ++std_itr) {
    ASSERT_EQ(*std_itr, *s21_itr);
  }
  for (; s21_itr != s21_vector.begin(); --s21_itr, --std_itr) {
    if (s21_itr == s21_vector.end()) {
      continue;
    }
    ASSERT_EQ(*std_itr, *s21_itr);
  }
  s21::vector<int>::const_iterator s21_end(s21_itr);
  ASSERT_TRUE(s21_end == s21_vector.begin());
}

TEST(VectorCapacity, TestEmpty_1) {
  const std::vector<int> std_vector{1, 2, 5, 10, -3, 33};
  const s21::vector<int> s21_vector{1, 2, 5, 10, -3, 33};
  ASSERT_EQ(std_vector.empty(), s21_vector.empty());
}

TEST(VectorCapacity, TestEmpty_2) {
  std::vector<double> std_vector{-0.5, 2.23};
  s21::vector<double> s21_vector{-0.5, 2.23};
  ASSERT_EQ(std_vector.empty(), s21_vector.empty());

  std_vector.clear();
  s21_vector.clear();
  ASSERT_EQ(std_vector.empty(), s21_vector.empty());
}

TEST(VectorCapacity, TestEmpty_3) {
  std::vector<double> std_vector;
  s21::vector<double> s21_vector;
  ASSERT_EQ(std_vector.empty(), s21_vector.empty());

  std_vector.reserve(4);
  s21_vector.reserve(4);
  ASSERT_EQ(std_vector.empty(), s21_vector.empty());
}

TEST(VectorCapacity, TestMaxSize) {
  const std::vector<int> std_vector;
  const s21::vector<int> s21_vector;
  ASSERT_EQ(std_vector.max_size(), s21_vector.max_size());

  std::vector<double> std_second_vector;
  s21::vector<double> s21_second_vector;
  ASSERT_EQ(std_second_vector.max_size(), s21_second_vector.max_size());

  std::vector<std::string> std_third_vector;
  s21::vector<std::string> s21_third_vector;
  ASSERT_EQ(std_third_vector.max_size(), s21_third_vector.max_size());
}

TEST(VectorCapacity, TestReserve_1) {
  std::vector<int> std_vector;
  s21::vector<int> s21_vector;
  ASSERT_EQ(std_vector.capacity(), s21_vector.capacity());
  ASSERT_EQ(std_vector.size(), s21_vector.size());

  std_vector.reserve(0);
  s21_vector.reserve(0);
  ASSERT_EQ(std_vector.capacity(), s21_vector.capacity());
  ASSERT_EQ(std_vector.size(), s21_vector.size());

  std_vector.reserve(16);
  s21_vector.reserve(16);
  ASSERT_EQ(std_vector.capacity(), s21_vector.capacity());
  ASSERT_EQ(std_vector.size(), s21_vector.size());
}

TEST(VectorCapacity, TestReserve_2) {
  std::vector<double> std_vector{1, 4, 5};
  s21::vector<double> s21_vector{1, 4, 5};
  ASSERT_EQ(std_vector.capacity(), s21_vector.capacity());
  ASSERT_EQ(std_vector.size(), s21_vector.size());

  std_vector.reserve(4);
  s21_vector.reserve(4);
  ASSERT_EQ(std_vector.capacity(), s21_vector.capacity());
  ASSERT_EQ(std_vector.size(), s21_vector.size());

  std_vector.reserve(52);
  s21_vector.reserve(52);
  ASSERT_EQ(std_vector.capacity(), s21_vector.capacity());
  ASSERT_EQ(std_vector.size(), s21_vector.size());
}

TEST(VectorCapacity, TestShrinkToFit_1) {
  std::vector<int> std_vector{1, 2, 3, 4};
  s21::vector<int> s21_vector{1, 2, 3, 4};

  std_vector.shrink_to_fit();
  s21_vector.shrink_to_fit();
  ASSERT_EQ(std_vector.capacity(), s21_vector.capacity());
  ASSERT_EQ(std_vector.size(), s21_vector.size());

  std_vector.reserve(16);
  s21_vector.reserve(16);
  std_vector.shrink_to_fit();
  s21_vector.shrink_to_fit();

  ASSERT_EQ(std_vector.capacity(), s21_vector.capacity());
  ASSERT_EQ(std_vector.size(), s21_vector.size());
}

TEST(VectorCapacity, TestShrinkToFit_2) {
  std::vector<double> std_vector;
  s21::vector<double> s21_vector;

  std_vector.shrink_to_fit();
  s21_vector.shrink_to_fit();

  ASSERT_EQ(std_vector.capacity(), s21_vector.capacity());
  ASSERT_EQ(std_vector.size(), s21_vector.size());
}

TEST(VectorCapacity, TestResize_1) {
  std::vector<int> std_vector{1, 2, 3, 4};
  s21::vector<int> s21_vector{1, 2, 3, 4};
  std_vector.resize(4);
  s21_vector.resize(4);
  ASSERT_EQ(std_vector.capacity(), s21_vector.capacity());
  ASSERT_EQ(std_vector.size(), s21_vector.size());

  std_vector.resize(2);
  s21_vector.resize(2);
  ASSERT_EQ(std_vector.capacity(), s21_vector.capacity());
  ASSERT_EQ(std_vector.size(), s21_vector.size());

  std_vector.resize(12);
  s21_vector.resize(12);
  ASSERT_EQ(std_vector.capacity(), s21_vector.capacity());
  ASSERT_EQ(std_vector.size(), s21_vector.size());
}

TEST(VectorCapacity, TestResize_2) {
  std::vector<double> std_vector;
  s21::vector<double> s21_vector;

  std_vector.resize(1);
  s21_vector.resize(1);
  ASSERT_EQ(std_vector.capacity(), s21_vector.capacity());
  ASSERT_EQ(std_vector.size(), s21_vector.size());
}

TEST(VectorModifiers, TestClear_1) {
  std::vector<int> std_vector{1, 2, 3, 4};
  s21::vector<int> s21_vector{1, 2, 3, 4};
  std_vector.clear();
  s21_vector.clear();
  ASSERT_EQ(std_vector.capacity(), s21_vector.capacity());
  ASSERT_EQ(std_vector.size(), s21_vector.size());

  std_vector.resize(4);
  s21_vector.resize(4);
  std_vector.clear();
  s21_vector.clear();
  ASSERT_EQ(std_vector.capacity(), s21_vector.capacity());
  ASSERT_EQ(std_vector.size(), s21_vector.size());

  std_vector.clear();
  s21_vector.clear();
  ASSERT_EQ(std_vector.capacity(), s21_vector.capacity());
  ASSERT_EQ(std_vector.size(), s21_vector.size());

  std_vector.reserve(12);
  s21_vector.reserve(12);
  std_vector.clear();
  s21_vector.clear();
  ASSERT_EQ(std_vector.capacity(), s21_vector.capacity());
  ASSERT_EQ(std_vector.size(), s21_vector.size());
}

TEST(VectorModifiers, TestClear_2) {
  std::vector<double> std_vector;
  s21::vector<double> s21_vector;

  std_vector.clear();
  s21_vector.clear();
  ASSERT_EQ(std_vector.capacity(), s21_vector.capacity());
  ASSERT_EQ(std_vector.size(), s21_vector.size());
}

TEST(VectorModifiers, TestInsert) {
  std::vector<char> std_vector;
  s21::vector<char> s21_vector;
  std_vector.insert(std_vector.end(), '1');
  s21_vector.insert(s21_vector.end(), '1');

  std_vector.insert(std_vector.begin(), 'S');
  s21_vector.insert(s21_vector.begin(), 'S');

  std::vector<char>::iterator std_itr;
  std_itr = std_vector.insert(--(std_vector.end()), '2');
  s21::vector<char>::iterator s21_itr;
  s21_itr = s21_vector.insert(--(s21_vector.end()), '2');

  ASSERT_EQ(*std_itr, *s21_itr);
  ASSERT_EQ(std_vector.capacity(), s21_vector.capacity());
  ASSERT_EQ(std_vector.size(), s21_vector.size());

  for (size_t i = 0; i < s21_vector.size(); ++i) {
    ASSERT_EQ(std_vector[i], s21_vector[i]);
  }
}

TEST(VectorModifiers, TestErase) {
  std::vector<int> std_vector{2, 5, 6, 10, 0};
  s21::vector<int> s21_vector{2, 5, 6, 10, 0};

  std_vector.erase(std_vector.begin());
  s21_vector.erase(s21_vector.begin());

  std_vector.erase((++std_vector.begin()));
  s21_vector.erase((++s21_vector.begin()));

  for (size_t i = 0; i < s21_vector.size(); ++i) {
    ASSERT_EQ(std_vector[i], s21_vector[i]);
  }

  ASSERT_EQ(std_vector.capacity(), s21_vector.capacity());
  ASSERT_EQ(std_vector.size(), s21_vector.size());
}

TEST(VectorModifiers, TestPushBack_1) {
  std::vector<char> std_vector;
  s21::vector<char> s21_vector;

  std_vector.push_back('a');
  s21_vector.push_back('a');

  std_vector.push_back('a');
  s21_vector.push_back('a');

  for (size_t i = 0; i < s21_vector.size(); ++i) {
    ASSERT_EQ(std_vector[i], s21_vector[i]);
  }

  ASSERT_EQ(std_vector.capacity(), s21_vector.capacity());
  ASSERT_EQ(std_vector.size(), s21_vector.size());
}

TEST(VectorModifiers, TestPushBack_2) {
  std::vector<int> std_vector{2, 5, 6, 10, 0};
  s21::vector<int> s21_vector{2, 5, 6, 10, 0};

  std_vector.push_back(777);
  s21_vector.push_back(777);

  for (size_t i = 0; i < s21_vector.size(); ++i) {
    ASSERT_EQ(std_vector[i], s21_vector[i]);
  }

  ASSERT_EQ(std_vector.capacity(), s21_vector.capacity());
  ASSERT_EQ(std_vector.size(), s21_vector.size());
}

TEST(VectorModifiers, TestPopBack_1) {
  std::vector<char> std_vector;
  s21::vector<char> s21_vector;

  std_vector.push_back('a');
  s21_vector.push_back('a');

  std_vector.push_back('a');
  s21_vector.push_back('a');

  std_vector.pop_back();
  s21_vector.pop_back();

  for (size_t i = 0; i < s21_vector.size(); ++i) {
    ASSERT_EQ(std_vector[i], s21_vector[i]);
  }

  ASSERT_EQ(std_vector.capacity(), s21_vector.capacity());
  ASSERT_EQ(std_vector.size(), s21_vector.size());

  std_vector.pop_back();
  s21_vector.pop_back();

  for (size_t i = 0; i < s21_vector.size(); ++i) {
    ASSERT_EQ(std_vector[i], s21_vector[i]);
  }

  ASSERT_EQ(std_vector.capacity(), s21_vector.capacity());
  ASSERT_EQ(std_vector.size(), s21_vector.size());
}

TEST(VectorModifiers, TestPopBack_2) {
  std::vector<int> std_vector{2, 5, 6, 10, 0};
  s21::vector<int> s21_vector{2, 5, 6, 10, 0};

  std_vector.pop_back();
  s21_vector.pop_back();

  for (size_t i = 0; i < s21_vector.size(); ++i) {
    ASSERT_EQ(std_vector[i], s21_vector[i]);
  }

  ASSERT_EQ(std_vector.capacity(), s21_vector.capacity());
  ASSERT_EQ(std_vector.size(), s21_vector.size());
}

TEST(VectorModifiers, TestSwap) {
  std::vector<int> std_vector;
  s21::vector<int> s21_vector;

  std::vector<int> std_second_vector{2, 5, 6, 10, 0};
  s21::vector<int> s21_second_vector{2, 5, 6, 10, 0};

  std_vector.swap(std_second_vector);
  s21_vector.swap(s21_second_vector);

  for (size_t i = 0; i < s21_vector.size(); ++i) {
    ASSERT_EQ(std_vector[i], s21_vector[i]);
  }

  ASSERT_EQ(std_vector.capacity(), s21_vector.capacity());
  ASSERT_EQ(std_vector.size(), s21_vector.size());

  for (size_t i = 0; i < s21_second_vector.size(); ++i) {
    ASSERT_EQ(std_second_vector[i], s21_second_vector[i]);
  }

  ASSERT_EQ(std_second_vector.capacity(), s21_second_vector.capacity());
  ASSERT_EQ(std_second_vector.size(), s21_second_vector.size());
}

TEST(VectorInsertMany, TestInsertMany) {
  std::vector<char> std_vector;
  s21::vector<int> s21_vector;

  std_vector.push_back('s');
  std_vector.push_back('c');
  std_vector.push_back('h');

  s21_vector.insert_many(s21_vector.begin(), 's', 'c', 'h');

  for (size_t i = 0; i < s21_vector.size(); ++i) {
    ASSERT_EQ(std_vector[i], s21_vector[i]);
  }

  ASSERT_EQ(std_vector.capacity(), s21_vector.capacity());
  ASSERT_EQ(std_vector.size(), s21_vector.size());

  std_vector.push_back('o');
  std_vector.push_back('o');
  std_vector.push_back('l');
  std_vector.push_back('2');
  std_vector.push_back('1');
  std_vector.push_back('!');

  s21_vector.insert_many(s21_vector.end(), 'o', 'o', 'l', '2');
  s21_vector.insert_many(s21_vector.end(), '!');
  s21_vector.insert_many(--s21_vector.end(), '1');

  for (size_t i = 0; i < s21_vector.size(); ++i) {
    ASSERT_EQ(std_vector[i], s21_vector[i]);
  }

  ASSERT_EQ(std_vector.capacity(), s21_vector.capacity());
  ASSERT_EQ(std_vector.size(), s21_vector.size());
}

TEST(VectorInsertMany, TestInsertManyBack) {
  std::vector<char> std_vector;
  s21::vector<int> s21_vector;

  std_vector.push_back('s');
  std_vector.push_back('c');
  std_vector.push_back('h');

  s21_vector.insert_many_back('s', 'c', 'h');

  for (size_t i = 0; i < s21_vector.size(); ++i) {
    ASSERT_EQ(std_vector[i], s21_vector[i]);
  }

  ASSERT_EQ(std_vector.capacity(), s21_vector.capacity());
  ASSERT_EQ(std_vector.size(), s21_vector.size());

  std_vector.push_back('o');
  std_vector.push_back('o');
  std_vector.push_back('l');
  std_vector.push_back('2');
  std_vector.push_back('1');
  std_vector.push_back('!');

  s21_vector.insert_many_back('o', 'o', 'l', '2', '1');
  s21_vector.insert_many_back('!');

  for (size_t i = 0; i < s21_vector.size(); ++i) {
    ASSERT_EQ(std_vector[i], s21_vector[i]);
  }

  ASSERT_EQ(std_vector.capacity(), s21_vector.capacity());
  ASSERT_EQ(std_vector.size(), s21_vector.size());
}