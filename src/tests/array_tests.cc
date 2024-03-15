#include <gtest/gtest.h>

#include <array>
#include <iostream>

#include "../s21_containersplus.h"

TEST(ArrayMemberFunctions, TestDefault_1) {
  std::array<int, 0> std_array;
  s21::array<int, 0> s21_array;

  ASSERT_EQ(std_array.size(), s21_array.size());
}

TEST(ArrayMemberFunctions, TestDefault_2) {
  std::array<std::string, 12> std_array;
  s21::array<std::string, 12> s21_array;

  ASSERT_EQ(std_array.size(), s21_array.size());
}

TEST(ArrayMemberFunctions, TestInitializerList_1) {
  std::array<int, 2> std_array{};
  s21::array<int, 2> s21_array{};

  ASSERT_EQ(std_array.size(), s21_array.size());
  for (size_t i = 0; i < s21_array.size(); ++i) {
    ASSERT_EQ(std_array[i], s21_array[i]);
  }
}

TEST(ArrayMemberFunctions, TestInitializerList_2) {
  std::array<std::string, 12> std_array{"s21 school", "is", "cool"};
  s21::array<std::string, 12> s21_array{"s21 school", "is", "cool"};

  ASSERT_EQ(std_array.size(), s21_array.size());
  for (size_t i = 0; i < s21_array.size(); ++i) {
    ASSERT_EQ(std_array[i], s21_array[i]);
  }
}

TEST(ArrayMemberFunctions, TestCopy_1) {
  std::array<int, 0> std_array{};
  s21::array<int, 0> s21_array{};

  std::array<int, 0> std_copy(std_array);
  s21::array<int, 0> s21_copy(s21_array);

  ASSERT_EQ(std_copy.size(), s21_copy.size());
}

TEST(ArrayMemberFunctions, TestCopy_2) {
  std::array<std::string, 12> std_array{"s21 school", "is", "cool"};
  s21::array<std::string, 12> s21_array{"s21 school", "is", "cool"};

  std::array<std::string, 12> std_copy(std_array);
  s21::array<std::string, 12> s21_copy(s21_array);

  ASSERT_EQ(std_copy.size(), s21_copy.size());
  for (size_t i = 0; i < s21_copy.size(); ++i) {
    ASSERT_EQ(std_copy[i], s21_copy[i]);
  }
}

TEST(ArrayMemberFunctions, TestMove_1) {
  std::array<int, 0> std_array{};
  s21::array<int, 0> s21_array{};

  std::array<int, 0> std_move(std::move(std_array));
  s21::array<int, 0> s21_move(std::move(s21_array));

  ASSERT_EQ(std_move.size(), s21_move.size());
}

TEST(ArrayMemberFunctions, TestMove_2) {
  std::array<std::string, 12> std_array{"s21 school", "is", "cool"};
  s21::array<std::string, 12> s21_array{"s21 school", "is", "cool"};

  std::array<std::string, 12> std_move(std::move(std_array));
  s21::array<std::string, 12> s21_move(std::move(s21_array));

  ASSERT_EQ(std_move.size(), s21_array.size());
  for (size_t i = 0; i < s21_move.size(); ++i) {
    ASSERT_EQ(std_move[i], s21_move[i]);
  }

  for (size_t i = 0; i < s21_array.size(); ++i) {
    ASSERT_EQ(std_array[i], s21_array[i]);
  }
}

TEST(ArrayMemberFunctions, TestMoveOperator_1) {
  std::array<int, 0> std_array{};
  s21::array<int, 0> s21_array{};

  std::array<int, 0> std_move;
  s21::array<int, 0> s21_move;
  std_move = std::move(std_array);
  s21_move = std::move(s21_array);

  ASSERT_EQ(std_move.size(), s21_move.size());
}

TEST(ArrayMemberFunctions, TestMoveOperator_2) {
  std::array<std::string, 12> std_array{"s21 school", "is", "cool"};
  s21::array<std::string, 12> s21_array{"s21 school", "is", "cool"};

  std::array<std::string, 12> std_move{"a", "b", "c", "d", "e", "f"};
  s21::array<std::string, 12> s21_move{"a", "b", "c", "d", "e", "f"};

  std_move = std::move(std_array);
  s21_move = std::move(s21_array);

  ASSERT_EQ(std_move.size(), s21_array.size());
  for (size_t i = 0; i < s21_move.size(); ++i) {
    ASSERT_EQ(std_move[i], s21_move[i]);
  }

  for (size_t i = 0; i < s21_array.size(); ++i) {
    ASSERT_EQ(std_array[i], s21_array[i]);
  }
}

TEST(ArrayElementAccess, TestAt_1) {
  std::array<int, 0> std_array{};
  s21::array<int, 0> s21_array{};

  ASSERT_THROW(std_array.at(0), std::out_of_range);
  ASSERT_THROW(s21_array.at(0), std::out_of_range);
}

TEST(ArrayElementAccess, TestAt_2) {
  const std::array<char, 5> std_array{'a', 'b', 'c', 'd'};
  const s21::array<char, 5> s21_array{'a', 'b', 'c', 'd'};

  ASSERT_THROW(std_array.at(5), std::out_of_range);
  ASSERT_THROW(s21_array.at(5), std::out_of_range);

  ASSERT_EQ(s21_array.at(0), std_array.at(0));

  // std_array.at(0) = 'e';
  // s21_array.at(0) = 'e';
}

TEST(ArrayElementAccess, TestAt_3) {
  std::array<int, 2> std_array{1, 5};
  s21::array<int, 2> s21_array{1, 5};

  std_array.at(1) = 17;
  s21_array.at(1) = 17;

  for (size_t i = 0; i < s21_array.size(); ++i) {
    ASSERT_EQ(std_array.at(i), s21_array.at(i));
  }
}

TEST(ArrayElementAccess, TestBrackets_1) {
  const std::array<char, 5> std_array{'a', 'b', 'c', 'd'};
  const s21::array<char, 5> s21_array{'a', 'b', 'c', 'd'};

  ASSERT_EQ(s21_array[0], std_array[0]);

  // std_array[0] = 'e';
  // s21_array[0] = 'e';
}

TEST(ArrayElementAccess, TestBrackets_2) {
  std::array<int, 2> std_array{1, 5};
  s21::array<int, 2> s21_array{1, 5};

  std_array[1] = 17;
  s21_array[1] = 17;

  for (size_t i = 0; i < s21_array.size(); ++i) {
    ASSERT_EQ(std_array[i], s21_array[i]);
  }
}

TEST(ArrayElementAccess, TestFrontAndBack_1) {
  std::array<int, 1> std_array{12};
  s21::array<int, 1> s21_array{36};

  std_array.front() = 4;
  s21_array.back() = 4;

  ASSERT_EQ(std_array.front(), s21_array.front());
}

TEST(ArrayElementAccess, TestFrontAndBack_2) {
  const std::array<char, 5> std_array{'a', 'b', 'c', 'd'};
  const s21::array<char, 5> s21_array{'a', 'b', 'c', 'd'};

  ASSERT_EQ(s21_array.front(), std_array.front());
  ASSERT_EQ(s21_array.back(), std_array.back());

  // std_array.front() = 'e';
  // s21_array.front() = 'e';

  // std_array.back() = 'e';
  // s21_array.back() = 'e';
}

TEST(ArrayElementAccess, TestFrontAndBack_3) {
  std::array<int, 2> std_array{1, 5};
  s21::array<int, 2> s21_array{1, 5};

  std_array.front() = 17;
  s21_array.front() = 17;

  std_array.back() = 21;
  s21_array.back() = 21;

  for (size_t i = 0; i < s21_array.size(); ++i) {
    ASSERT_EQ(std_array[i], s21_array[i]);
  }
}

TEST(ArrayElementAccess, TestData_1) {
  std::array<int, 1> std_array{12};
  s21::array<int, 1> s21_array{36};

  *std_array.data() = 4;
  *s21_array.data() = 4;

  ASSERT_EQ(std_array.front(), s21_array.front());
}

TEST(ArrayElementAccess, TestData_2) {
  const std::array<char, 5> std_array{'a', 'b', 'c', 'd'};
  const s21::array<char, 5> s21_array{'a', 'b', 'c', 'd'};

  ASSERT_EQ(*s21_array.data(), *std_array.data());
  ASSERT_EQ(*(s21_array.data() + 2), *(s21_array.data() + 2));

  // *std_array.data() = 'e';
  // *s21_array.data() = 'e';
}

TEST(ArrayIterators, TestBegin_1) {
  std::array<int, 1> std_array{12};
  s21::array<int, 1> s21_array{36};

  auto std_itr = std_array.begin();
  auto s21_itr = s21_array.begin();

  *std_itr = 4;
  *s21_itr = 4;

  ASSERT_EQ(std_array.front(), s21_array.front());
}

TEST(ArrayIterators, TestBegin_2) {
  const std::array<char, 5> std_array{'a', 'b', 'c', 'd'};
  const s21::array<char, 5> s21_array{'a', 'b', 'c', 'd'};

  ASSERT_EQ(*s21_array.begin(), *std_array.begin());
  ASSERT_EQ(*(s21_array.begin() + 4), *(std_array.begin() + 4));

  // *std_array.begin() = 'e';
  // *s21_array.begin() = 'e';
}

TEST(ArrayIterators, TestEnd_1) {
  std::array<int, 1> std_array{12};
  s21::array<int, 1> s21_array{36};

  auto std_itr = std_array.end();
  auto s21_itr = s21_array.end();

  *(std_itr - 1) = 4;
  *(s21_itr - 1) = 4;

  ASSERT_EQ(std_array.back(), s21_array.back());
}

TEST(ArrayIterators, TestEnd_2) {
  const std::array<char, 5> std_array{'a', 'b', 'c', 'd'};
  const s21::array<char, 5> s21_array{'a', 'b', 'c', 'd'};

  ASSERT_EQ(*(s21_array.end() - 4), *(std_array.end() - 4));
  ASSERT_EQ(*(s21_array.end() - 2), *(std_array.end() - 2));

  // *std_array.end() = 'e';
  // *s21_array.end() = 'e';
}

TEST(ArrayCapacity, TestEmpty_1) {
  std::array<int, 1> std_array{12};
  s21::array<int, 1> s21_array{36};

  ASSERT_EQ(std_array.empty(), s21_array.empty());
}

TEST(ArrayCapacity, TestEmpty_2) {
  std::array<char, 12> std_array;
  s21::array<char, 12> s21_array;

  ASSERT_EQ(std_array.empty(), s21_array.empty());
}

TEST(ArrayCapacity, TestEmpty_3) {
  std::array<char, 0> std_array;
  s21::array<char, 0> s21_array;

  ASSERT_EQ(std_array.empty(), s21_array.empty());
}

TEST(ArrayCapacity, TestMaxSize_1) {
  std::array<int, 1> std_array{12};
  s21::array<int, 1> s21_array{36};

  ASSERT_EQ(std_array.max_size(), s21_array.max_size());
}

TEST(ArrayCapacity, TestMaxSize_2) {
  std::array<char, 12> std_array;
  s21::array<char, 12> s21_array;

  ASSERT_EQ(std_array.max_size(), s21_array.max_size());
}
TEST(ArrayCapacity, TestMaxSize_3) {
  std::array<char, 0> std_array;
  s21::array<char, 0> s21_array;

  ASSERT_EQ(std_array.max_size(), s21_array.max_size());
}

TEST(ArrayModifiers, TestSwap_1) {
  std::array<int, 5> std_array{12, 1, 2, 3, 99};
  s21::array<int, 5> s21_array{12, 1, 2, 3, 99};

  std::array<int, 5> std_swap{};
  s21::array<int, 5> s21_swap{};

  std_array.swap(std_swap);
  s21_array.swap(s21_swap);

  for (size_t i = 0; i < s21_swap.size(); ++i) {
    ASSERT_EQ(std_array[i], s21_array[i]);
    ASSERT_EQ(std_swap[i], s21_swap[i]);
  }
}

TEST(ArrayModifiers, TestSwap_2) {
  std::array<char, 0> std_array;
  s21::array<char, 0> s21_array;

  std::array<char, 0> std_swap;
  s21::array<char, 0> s21_swap;

  std_array.swap(std_swap);
  s21_array.swap(s21_swap);
}

TEST(ArrayModifiers, TestFill_1) {
  std::array<int, 5> std_array{12, 1, 2, 3, 99};
  s21::array<int, 5> s21_array{12, 1, 2, 3, 99};

  std_array.fill(19);
  s21_array.fill(19);

  for (size_t i = 0; i < s21_array.size(); ++i) {
    ASSERT_EQ(std_array[i], s21_array[i]);
  }
}

TEST(ArrayModifiers, TestFill_2) {
  std::array<double, 16> std_array;
  s21::array<double, 16> s21_array;

  std_array.fill(3.14);
  s21_array.fill(3.14);

  for (size_t i = 0; i < s21_array.size(); ++i) {
    ASSERT_EQ(std_array[i], s21_array[i]);
  }
}

TEST(ArrayModifiers, TestFill_3) {
  std::array<char, 0> std_array;
  s21::array<char, 0> s21_array;

  std_array.fill('s');
  s21_array.fill('s');

  for (size_t i = 0; i < s21_array.size(); ++i) {
    ASSERT_EQ(std_array[i], s21_array[i]);
  }
}