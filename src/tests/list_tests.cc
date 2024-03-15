#include <gtest/gtest.h>

#include <iostream>
#include <list>

#include "../s21_containers.h"

TEST(ListMemberFunctions, TestDefault) {
  s21::list<int> s21_list;
  std::list<int> std_list;
  ASSERT_EQ(s21_list.empty(), std_list.empty());
  ASSERT_EQ(s21_list.size(), std_list.size());
}

TEST(ListMemberFunctions, TestInitializerList_1) {
  s21::list<int> s21_list{1, 2, 3, 4, 5, 6};
  std::list<int> std_list{1, 2, 3, 4, 5, 6};
  s21::list<int>::iterator s21_itr = s21_list.begin();
  std::list<int>::iterator std_itr = std_list.begin();
  for (; s21_itr != s21_list.end(); ++s21_itr, ++std_itr) {
    ASSERT_EQ(*s21_itr, *std_itr);
  }
  ASSERT_EQ(s21_list.empty(), std_list.empty());
  ASSERT_EQ(s21_list.size(), std_list.size());
}

TEST(ListMemberFunctions, TestInitializerList_2) {
  s21::list<std::string> s21_list{"a", "bobo", "hello"};
  std::list<std::string> std_list{"a", "bobo", "hello"};
  s21::list<std::string>::iterator s21_itr = s21_list.begin();
  std::list<std::string>::iterator std_itr = std_list.begin();
  for (; s21_itr != s21_list.end(); ++s21_itr, ++std_itr) {
    ASSERT_EQ(*s21_itr, *std_itr);
  }
  ASSERT_EQ(s21_list.empty(), std_list.empty());
  ASSERT_EQ(s21_list.size(), std_list.size());
}

TEST(ListMemberFunctions, TestParametrized_1) {
  s21::list<std::string> s21_list(12);
  std::list<std::string> std_list(12);
  s21::list<std::string>::iterator s21_itr = s21_list.begin();
  std::list<std::string>::iterator std_itr = std_list.begin();
  for (; s21_itr != s21_list.end(); ++s21_itr, ++std_itr) {
    ASSERT_EQ(*s21_itr, *std_itr);
  }
  ASSERT_EQ(s21_list.empty(), std_list.empty());
  ASSERT_EQ(s21_list.size(), std_list.size());
}

TEST(ListMemberFunctions, TestParametrized_2) {
  s21::list<std::string> s21_list(6, "privet");
  std::list<std::string> std_list(6, "privet");
  s21::list<std::string>::iterator s21_itr = s21_list.begin();
  std::list<std::string>::iterator std_itr = std_list.begin();
  for (; s21_itr != s21_list.end(); ++s21_itr, ++std_itr) {
    ASSERT_EQ(*s21_itr, *std_itr);
  }
  ASSERT_EQ(s21_list.empty(), std_list.empty());
  ASSERT_EQ(s21_list.size(), std_list.size());
}

TEST(ListMemberFunctions, TestParametrized_3) {
  s21::list<int> s21_list(100, 5);
  std::list<int> std_list(100, 5);
  s21::list<int>::iterator s21_itr = s21_list.begin();
  std::list<int>::iterator std_itr = std_list.begin();
  for (; s21_itr != s21_list.end(); ++s21_itr, ++std_itr) {
    ASSERT_EQ(*s21_itr, *std_itr);
  }
  ASSERT_EQ(s21_list.empty(), std_list.empty());
  ASSERT_EQ(s21_list.size(), std_list.size());
}

TEST(ListMemberFunctions, TestParametrized_4) {
  s21::list<int> s21_list(1);
  std::list<int> std_list(1);
  s21::list<int>::iterator s21_itr = s21_list.begin();
  std::list<int>::iterator std_itr = std_list.begin();
  for (; s21_itr != s21_list.end(); ++s21_itr, ++std_itr) {
    ASSERT_EQ(*s21_itr, *std_itr);
  }
  ASSERT_EQ(s21_list.empty(), std_list.empty());
  ASSERT_EQ(s21_list.size(), std_list.size());
}

TEST(ListMemberFunctions, TestParametrized_5) {
  s21::list<int> s21_list(0);
  std::list<int> std_list(0);
  s21::list<int>::iterator s21_itr = s21_list.begin();
  std::list<int>::iterator std_itr = std_list.begin();
  for (; s21_itr != s21_list.end(); ++s21_itr, ++std_itr) {
    ASSERT_EQ(*s21_itr, *std_itr);
  }
  ASSERT_EQ(s21_list.empty(), std_list.empty());
  ASSERT_EQ(s21_list.size(), std_list.size());
}

TEST(ListMemberFunctions, TestCopy_1) {
  s21::list<int> s21_list{1, 2, 3};
  s21::list<int> s21_copy(s21_list);
  std::list<int> std_list{1, 2, 3};
  std::list<int> std_copy(std_list);

  ASSERT_EQ(s21_list.size(), std_list.size());
  ASSERT_EQ(s21_copy.size(), std_copy.size());

  s21::list<int>::iterator s21_itr = s21_list.begin();
  std::list<int>::iterator std_itr = std_list.begin();
  for (; s21_itr != s21_list.end(); ++s21_itr, ++std_itr) {
    ASSERT_EQ(*s21_itr, *std_itr);
  }
  s21_itr = s21_copy.begin();
  std_itr = std_copy.begin();
  for (; s21_itr != s21_copy.end(); ++s21_itr, ++std_itr) {
    ASSERT_EQ(*s21_itr, *std_itr);
  }
}

TEST(ListMemberFunctions, TestCopy_2) {
  s21::list<int> s21_list{1, 2, 3};
  s21::list<int> s21_copy(s21_list);
  std::list<int> std_list{1, 2, 3};
  std::list<int> std_copy(std_list);

  ASSERT_EQ(s21_list.size(), std_list.size());
  ASSERT_EQ(s21_copy.size(), std_copy.size());
  ASSERT_EQ(s21_list.empty(), std_list.empty());
  ASSERT_EQ(s21_copy.empty(), std_copy.empty());
}

TEST(ListMemberFunctions, TestMove_1) {
  s21::list<int> s21_list{1, 2, 3};
  s21::list<int> s21_move = std::move(s21_list);
  std::list<int> std_list{1, 2, 3};
  std::list<int> std_move = std::move(std_list);

  ASSERT_EQ(s21_move.size(), std_move.size());

  s21::list<int>::iterator s21_itr = s21_move.begin();
  std::list<int>::iterator std_itr = std_move.begin();
  for (; s21_itr != s21_move.end(); ++s21_itr, ++std_itr) {
    ASSERT_EQ(*s21_itr, *std_itr);
  }
}

TEST(ListMemberFunctions, TestMove_2) {
  s21::list<int> s21_list;
  s21::list<int> s21_move = std::move(s21_list);
  std::list<int> std_list;
  std::list<int> std_move = std::move(std_list);

  ASSERT_EQ(s21_move.size(), std_move.size());
  ASSERT_EQ(s21_move.empty(), std_move.empty());
}

TEST(ListMemberFunctions, TestCopyOperator_1) {
  s21::list<int> s21_list;
  s21::list<int> s21_copy;
  std::list<int> std_list;
  std::list<int> std_copy;

  s21_copy = s21_list;
  std_copy = std_list;

  ASSERT_EQ(s21_list.size(), std_list.size());
  ASSERT_EQ(s21_list.empty(), std_list.empty());

  ASSERT_EQ(s21_copy.size(), std_copy.size());
  ASSERT_EQ(s21_copy.empty(), std_copy.empty());
}

TEST(ListMemberFunctions, TestCopyOperator_2) {
  s21::list<int> s21_list{5, 5, 223, 55, 1};
  s21::list<int> s21_copy{1, 5, 6, 7, 8, 1111, 23, 5, 6};
  std::list<int> std_list{5, 5, 223, 55, 1};
  std::list<int> std_copy{1, 5, 6, 7, 8, 1111, 23, 5, 6};

  s21_copy = s21_list;
  std_copy = std_list;

  ASSERT_EQ(s21_list.size(), std_list.size());
  ASSERT_EQ(s21_copy.size(), std_copy.size());

  s21::list<int>::iterator s21_itr = s21_list.begin();
  std::list<int>::iterator std_itr = std_list.begin();
  for (; s21_itr != s21_list.end(); ++s21_itr, ++std_itr) {
    ASSERT_EQ(*s21_itr, *std_itr);
  }
  s21_itr = s21_copy.begin();
  std_itr = std_copy.begin();
  for (; s21_itr != s21_copy.end(); ++s21_itr, ++std_itr) {
    ASSERT_EQ(*s21_itr, *std_itr);
  }
}

TEST(ListMemberFunctions, TestCopyOperator_3) {
  s21::list<int> s21_list;
  s21::list<int> s21_copy{1, 5, 6, 7, 8, 1111, 23, 5, 6};
  std::list<int> std_list;
  std::list<int> std_copy{1, 5, 6, 7, 8, 1111, 23, 5, 6};

  s21_copy = s21_list;
  std_copy = std_list;

  ASSERT_EQ(s21_list.size(), std_list.size());
  ASSERT_EQ(s21_list.empty(), std_list.empty());

  ASSERT_EQ(s21_copy.size(), std_copy.size());
  ASSERT_EQ(s21_copy.empty(), std_copy.empty());
}

TEST(ListMemberFunctions, TestMoveOperator_1) {
  s21::list<int> s21_list;
  s21::list<int> s21_move;
  std::list<int> std_list;
  std::list<int> std_move;

  s21_move = std::move(s21_list);
  std_move = std::move(std_list);

  ASSERT_EQ(s21_move.size(), std_move.size());
  ASSERT_EQ(s21_move.empty(), std_move.empty());
}

TEST(ListMemberFunctions, TestMoveOperator_2) {
  s21::list<int> s21_list{5, 5, 223, 55, 1};
  s21::list<int> s21_move{1, 5, 6, 7, 8, 1111, 23, 5, 6};
  std::list<int> std_list{5, 5, 223, 55, 1};
  std::list<int> std_move{1, 5, 6, 7, 8, 1111, 23, 5, 6};

  s21_move = std::move(s21_list);
  std_move = std::move(std_list);

  ASSERT_EQ(s21_move.size(), std_move.size());

  s21::list<int>::iterator s21_itr = s21_move.begin();
  std::list<int>::iterator std_itr = std_move.begin();
  for (; s21_itr != s21_move.end(); ++s21_itr, ++std_itr) {
    ASSERT_EQ(*s21_itr, *std_itr);
  }
}

TEST(ListMemberFunctions, TestMoveOperator_3) {
  s21::list<int> s21_list;
  s21::list<int> s21_move{1, 5, 6, 7, 8, 1111, 23, 5, 6};
  std::list<int> std_list;
  std::list<int> std_move{1, 5, 6, 7, 8, 1111, 23, 5, 6};

  s21_move = s21_list;
  std_move = std_list;

  ASSERT_EQ(s21_move.size(), std_move.size());
  ASSERT_EQ(s21_move.empty(), std_move.empty());
}

TEST(ListMemberFunctions, TestDestructor) {
  s21::list<int>* s21_list = new s21::list<int>{1, 5, 6, 7, 8, 1111, 23, 5, 6};
  std::list<int>* std_list = new std::list<int>{1, 5, 6, 7, 8, 1111, 23, 5, 6};

  delete s21_list;
  delete std_list;
}

TEST(ListElementAccess, TestFront_1) {
  s21::list<int> s21_list{1, 5, 6, 7, 8, 1111, 23, 5, 6};
  std::list<int> std_list{1, 5, 6, 7, 8, 1111, 23, 5, 6};

  ASSERT_EQ(s21_list.front(), std_list.front());

  s21_list.push_front(55);
  std_list.push_front(55);

  ASSERT_EQ(s21_list.front(), std_list.front());

  s21::list<int>::iterator s21_itr = s21_list.begin();
  std::list<int>::iterator std_itr = std_list.begin();
  for (; s21_itr != s21_list.end(); ++s21_itr, ++std_itr) {
    ASSERT_EQ(*s21_itr, *std_itr);
  }
}

TEST(ListElementAccess, TestFront_2) {
  const s21::list<int> s21_list{1, 5, 6, 7, 8, 1111, 23, 5, 6};
  const std::list<int> std_list{1, 5, 6, 7, 8, 1111, 23, 5, 6};

  ASSERT_EQ(s21_list.front(), std_list.front());

  s21::list<int>::const_iterator s21_itr = s21_list.begin();
  std::list<int>::const_iterator std_itr = std_list.begin();
  for (; s21_itr != s21_list.end(); ++s21_itr, ++std_itr) {
    ASSERT_EQ(*s21_itr, *std_itr);
  }
}

TEST(ListElementAccess, TestBack_1) {
  s21::list<int> s21_list{1, 5, 6, 7, 8, 1111, 23, 5, 6};
  std::list<int> std_list{1, 5, 6, 7, 8, 1111, 23, 5, 6};

  ASSERT_EQ(s21_list.back(), std_list.back());

  s21_list.push_back(55);
  std_list.push_back(55);

  ASSERT_EQ(s21_list.back(), std_list.back());

  s21::list<int>::iterator s21_itr = s21_list.begin();
  std::list<int>::iterator std_itr = std_list.begin();
  for (; s21_itr != s21_list.end(); ++s21_itr, ++std_itr) {
    ASSERT_EQ(*s21_itr, *std_itr);
  }
}

TEST(ListElementAccess, TestBack_2) {
  const s21::list<int> s21_list{1, 5, 6, 7, 8, 1111, 23, 5, 6};
  const std::list<int> std_list{1, 5, 6, 7, 8, 1111, 23, 5, 6};

  ASSERT_EQ(s21_list.back(), std_list.back());

  s21::list<int>::const_iterator s21_itr = s21_list.begin();
  std::list<int>::const_iterator std_itr = std_list.begin();
  for (; s21_itr != s21_list.end(); ++s21_itr, ++std_itr) {
    ASSERT_EQ(*s21_itr, *std_itr);
  }
}

TEST(ListElementAccess, TestBack_3) {
  s21::list<int> s21_list{1};
  std::list<int> std_list{1};

  ASSERT_EQ(s21_list.back() == s21_list.front(),
            std_list.back() == s21_list.back());
}

TEST(ListIterators, TestBegin_1) {
  s21::list<int> s21_list{1};
  std::list<int> std_list{1};

  ASSERT_EQ(*s21_list.begin(), *std_list.begin());
}

TEST(ListIterators, TestBegin_2) {
  s21::list<int> s21_list;
  std::list<int> std_list;

  ASSERT_EQ(s21_list.begin() == s21_list.end(),
            std_list.begin() == std_list.end());
}

TEST(ListIterators, TestBegin_3) {
  s21::list<int> s21_list{1, 5, 3, 2, 1, 66, 7, 8};
  std::list<int> std_list{1, 5, 3, 2, 1, 66, 7, 8};

  s21::list<int>::iterator s21_itr = s21_list.begin();
  std::list<int>::iterator std_itr = std_list.begin();

  for (size_t i = 0; i <= 2 * s21_list.size(); ++s21_itr, ++std_itr, ++i) {
    if (s21_itr == s21_list.end()) {
      continue;
    }
    ASSERT_EQ(*s21_itr, *std_itr);
  }

  for (size_t i = 0; i <= 2 * s21_list.size(); --s21_itr, --std_itr, ++i) {
    if (s21_itr == s21_list.end()) {
      continue;
    }
    ASSERT_EQ(*s21_itr, *std_itr);
  }
}

TEST(ListIterators, TestBegin_4) {
  const s21::list<int> s21_list{1, 5, 3, 2, 1, 66, 7, 8};
  const std::list<int> std_list{1, 5, 3, 2, 1, 66, 7, 8};

  s21::list<int>::const_iterator s21_itr = s21_list.begin();
  std::list<int>::const_iterator std_itr = std_list.begin();

  for (size_t i = 0; i <= 2 * s21_list.size(); ++s21_itr, ++std_itr, ++i) {
    if (s21_itr == s21_list.end()) {
      continue;
    }
    ASSERT_EQ(*s21_itr, *std_itr);
  }

  for (size_t i = 0; i <= 2 * s21_list.size(); --s21_itr, --std_itr, ++i) {
    if (s21_itr == s21_list.end()) {
      continue;
    }
    ASSERT_EQ(*s21_itr, *std_itr);
  }
}

TEST(ListIterators, TestEnd_1) {
  const s21::list<int> s21_list{1, 5, 3, 2, 1, 66, 7, 8};
  const std::list<int> std_list{1, 5, 3, 2, 1, 66, 7, 8};

  s21::list<int>::const_iterator s21_itr = s21_list.end();
  std::list<int>::const_iterator std_itr = std_list.end();

  for (size_t i = 0; i <= 2 * s21_list.size(); ++s21_itr, ++std_itr, ++i) {
    if (s21_itr == s21_list.end()) {
      continue;
    }
    ASSERT_EQ(*s21_itr, *std_itr);
  }

  s21_itr = s21_list.end();
  std_itr = std_list.end();

  for (size_t i = 0; i <= 2 * s21_list.size(); --s21_itr, --std_itr, ++i) {
    if (s21_itr == s21_list.end()) {
      continue;
    }
    ASSERT_EQ(*s21_itr, *std_itr);
  }
}

TEST(ListIterators, TestEnd_2) {
  s21::list<int> s21_list{1, 5, 3, 2, 1, 66, 7, 8};
  std::list<int> std_list{1, 5, 3, 2, 1, 66, 7, 8};

  s21::list<int>::iterator s21_itr = s21_list.end();
  std::list<int>::iterator std_itr = std_list.end();

  for (size_t i = 0; i <= 2 * s21_list.size(); ++s21_itr, ++std_itr, ++i) {
    if (s21_itr == s21_list.end()) {
      continue;
    }
    ASSERT_EQ(*s21_itr, *std_itr);
  }

  for (size_t i = 0; i <= 2 * s21_list.size(); --s21_itr, --std_itr, ++i) {
    if (s21_itr == s21_list.end()) {
      continue;
    }
    ASSERT_EQ(*s21_itr, *std_itr);
  }
}

TEST(ListIterators, TestEnd_3) {
  const s21::list<int> s21_list;
  const std::list<int> std_list;

  ASSERT_EQ(s21_list.end() == s21_list.begin(),
            std_list.end() == std_list.begin());
}

TEST(ListCapacity, TestSize_1) {
  s21::list<int> s21_size{2, 1, 3, 5, 4, 3, 4, 5};
  std::list<int> std_size{2, 1, 3, 5, 4, 3, 4, 5};
  ASSERT_EQ(s21_size.size(), std_size.size());
}

TEST(ListCapacity, TestSize_2) {
  s21::list<int> s21_size;
  std::list<int> std_size;
  ASSERT_EQ(s21_size.size(), std_size.size());
}

TEST(ListCapacity, TestEmpty_1) {
  s21::list<int> s21_empty;
  std::list<int> std_empty;
  ASSERT_EQ(s21_empty.empty(), std_empty.empty());
}

TEST(ListCapacity, TestEmpty_2) {
  s21::list<int> s21_test{2, 1, 3, 5, 4, 3, 4, 5};
  std::list<int> numbers{2, 1, 3, 5, 4, 3, 4, 5};
  ASSERT_EQ(s21_test.empty(), numbers.empty());
}

TEST(ListCapacity, TestEmpty_3) {
  s21::list<int> s21_test{2, 1, 3, 5, 4, 3, 4, 5};
  std::list<int> numbers{2, 1, 3, 5, 4, 3, 4, 5};
  s21_test.clear();
  numbers.clear();
  ASSERT_EQ(s21_test.empty(), numbers.empty());
}

TEST(ListCapacity, TestMaxSize_1) {
  s21::list<int> s21_test{2, 1, 3, 5, 4, 3, 4, 5};
  std::list<int> numbers{2, 1, 3, 5, 4, 3, 4, 5};
  ASSERT_EQ(s21_test.max_size(), numbers.max_size());
}

TEST(ListCapacity, TestMaxSize_2) {
  s21::list<double> s21_test;
  std::list<double> numbers;
  ASSERT_EQ(s21_test.max_size(), numbers.max_size());
}

TEST(ListCapacity, TestMaxSize_3) {
  s21::list<char> s21_test;
  std::list<char> numbers;
  ASSERT_EQ(s21_test.max_size(), numbers.max_size());
}

TEST(ListModifiers, TestClear_1) {
  s21::list<int> s21_list{2, 1, 3, 5, 4, 3, 4, 5};
  std::list<int> std_list{2, 1, 3, 5, 4, 3, 4, 5};

  s21_list.clear();
  std_list.clear();

  ASSERT_EQ(s21_list.size(), std_list.size());
  ASSERT_EQ(s21_list.empty(), std_list.empty());
}

TEST(ListModifiers, TestClear_2) {
  s21::list<int> s21_list{2, 1, 3, 5, 4, 3, 4, 5};
  std::list<int> std_list{2, 1, 3, 5, 4, 3, 4, 5};

  s21_list.clear();
  std_list.clear();

  s21_list.clear();
  std_list.clear();

  ASSERT_EQ(s21_list.size(), std_list.size());
  ASSERT_EQ(s21_list.empty(), std_list.empty());
}

TEST(ListModifiers, TestClear_3) {
  s21::list<int> s21_list;
  std::list<int> std_list;

  s21_list.clear();
  std_list.clear();

  ASSERT_EQ(s21_list.size(), std_list.size());
  ASSERT_EQ(s21_list.empty(), std_list.empty());
}

TEST(ListModifiers, TestPushBack_1) {
  s21::list<int> s21_push{2, 1, 3, 5, 4, 3, 4, 5};
  std::list<int> std_push{2, 1, 3, 5, 4, 3, 4, 5};
  s21_push.push_back(123);
  std_push.push_back(123);
  auto itr_s21 = s21_push.begin();
  auto itr_std = std_push.begin();
  for (; itr_s21 != s21_push.end(); itr_s21++, itr_std++) {
    ASSERT_EQ(*itr_s21, *itr_std);
  }
}

TEST(ListModifiers, TestPushBack_2) {
  s21::list<double> s21_push{123.3, 443.1, 0.001};
  std::list<double> std_push{123.3, 443.1, 0.001};
  s21_push.push_back(11.11);
  std_push.push_back(11.11);
  auto itr_s21 = s21_push.begin();
  auto itr_std = std_push.begin();
  for (; itr_s21 != s21_push.end(); itr_s21++, itr_std++) {
    ASSERT_EQ(*itr_s21, *itr_std);
  }
}

TEST(ListModifiers, TestPushBack_3) {
  s21::list<double> s21_push;
  std::list<double> std_push;
  s21_push.push_back(11.11);
  std_push.push_back(11.11);
  auto itr_s21 = s21_push.begin();
  auto itr_std = std_push.begin();
  for (; itr_s21 != s21_push.end(); itr_s21++, itr_std++) {
    ASSERT_EQ(*itr_s21, *itr_std);
  }
}

TEST(ListModifiers, TestPushFront_1) {
  s21::list<unsigned> s21_push{123333, 8976, 1, 2, 3, 4, 5, 6, 8};
  std::list<unsigned> std_push{123333, 8976, 1, 2, 3, 4, 5, 6, 8};
  s21_push.push_front(1111);
  std_push.push_front(1111);
  auto itr_s21 = s21_push.begin();
  auto itr_std = std_push.begin();
  for (; itr_s21 != s21_push.end(); itr_s21++, itr_std++) {
    ASSERT_EQ(*itr_s21, *itr_std);
  }
}

TEST(ListModifiers, TestPushFront_2) {
  s21::list<char> s21_push{'1', 'l'};
  std::list<char> std_push{'1', 'l'};
  s21_push.push_front('q');
  std_push.push_front('q');
  auto itr_s21 = s21_push.begin();
  auto itr_std = std_push.begin();
  for (; itr_s21 != s21_push.end(); itr_s21++, itr_std++) {
    ASSERT_EQ(*itr_s21, *itr_std);
  }
}

TEST(ListModifiers, TestPushFront_3) {
  s21::list<char> s21_push;
  std::list<char> std_push;
  s21_push.push_front('q');
  std_push.push_front('q');
  auto itr_s21 = s21_push.begin();
  auto itr_std = std_push.begin();
  for (; itr_s21 != s21_push.end(); itr_s21++, itr_std++) {
    ASSERT_EQ(*itr_s21, *itr_std);
  }
}

TEST(ListModifiers, TestPushCombo_1) {
  s21::list<char> s21_push;
  std::list<char> std_push;
  s21_push.push_front('1');
  std_push.push_front('1');
  s21_push.push_back('q');
  std_push.push_back('q');
  auto itr_s21 = s21_push.begin();
  auto itr_std = std_push.begin();
  for (; itr_s21 != s21_push.end(); itr_s21++, itr_std++) {
    ASSERT_EQ(*itr_s21, *itr_std);
  }
}

TEST(ListModifiers, TestPushCombo_2) {
  s21::list<char> s21_push;
  std::list<char> std_push;
  s21_push.push_back('q');
  std_push.push_back('q');
  s21_push.push_front('1');
  std_push.push_front('1');
  auto itr_s21 = s21_push.begin();
  auto itr_std = std_push.begin();
  for (; itr_s21 != s21_push.end(); itr_s21++, itr_std++) {
    ASSERT_EQ(*itr_s21, *itr_std);
  }
}

TEST(ListModifiers, TestInsert_1) {
  s21::list<int> s21_insert{1, 2, 3, 4};
  std::list<int> std_insert{1, 2, 3, 4};
  auto itr_s21 = s21_insert.begin();
  auto itr_std = std_insert.begin();
  itr_s21++;
  itr_std++;
  s21_insert.insert(itr_s21, 555);
  std_insert.insert(itr_std, 555);
  for (itr_s21 = s21_insert.begin(), itr_std = std_insert.begin();
       itr_s21 != s21_insert.end(); itr_s21++, itr_std++) {
    ASSERT_EQ(*itr_s21, *itr_std);
  }
}

TEST(ListModifiers, TestInsert_2) {
  s21::list<double> s21_insert{1.1};
  std::list<double> std_insert{1.1};
  auto itr_s21 = s21_insert.begin();
  auto itr_std = std_insert.begin();
  s21_insert.insert(itr_s21, 111111.222);
  std_insert.insert(itr_std, 111111.222);
  for (itr_s21 = s21_insert.begin(), itr_std = std_insert.begin();
       itr_s21 != s21_insert.end(); itr_s21++, itr_std++) {
    ASSERT_EQ(*itr_s21, *itr_std);
  }
}

TEST(ListModifiers, TestInsert_3) {
  s21::list<char> s21_insert{'q', 'h', 'q'};
  std::list<char> std_insert{'q', 'h', 'q'};
  auto itr_s21 = s21_insert.begin();
  auto itr_std = std_insert.begin();
  s21_insert.insert(itr_s21, 'm');
  std_insert.insert(itr_std, 'm');
  for (itr_s21 = s21_insert.begin(), itr_std = std_insert.begin();
       itr_s21 != s21_insert.end(); itr_s21++, itr_std++) {
    ASSERT_EQ(*itr_s21, *itr_std);
  }
}

TEST(ListModifiers, TestInsert_4) {
  s21::list<char> s21_insert{'q', 'h', 'q'};
  std::list<char> std_insert{'q', 'h', 'q'};
  auto itr_s21 = s21_insert.end();
  auto itr_std = std_insert.end();
  s21_insert.insert(itr_s21, 'm');
  std_insert.insert(itr_std, 'm');
  for (itr_s21 = s21_insert.begin(), itr_std = std_insert.begin();
       itr_s21 != s21_insert.end(); itr_s21++, itr_std++) {
    ASSERT_EQ(*itr_s21, *itr_std);
  }
}

TEST(ListModifiers, TestInsert_5) {
  s21::list<char> s21_insert;
  std::list<char> std_insert;
  auto itr_s21 = s21_insert.begin();
  auto itr_std = std_insert.begin();
  s21_insert.insert(itr_s21, 'm');
  std_insert.insert(itr_std, 'm');
  for (itr_s21 = s21_insert.begin(), itr_std = std_insert.begin();
       itr_s21 != s21_insert.end(); itr_s21++, itr_std++) {
    ASSERT_EQ(*itr_s21, *itr_std);
  }
}

TEST(ListModifiers, TestErase_1) {
  s21::list<char> s21_erase{'q', 'h', 'q'};
  std::list<char> std_erase{'q', 'h', 'q'};
  auto itr_s21 = s21_erase.begin();
  auto itr_std = std_erase.begin();
  s21_erase.erase(itr_s21);
  std_erase.erase(itr_std);
  for (itr_s21 = s21_erase.begin(), itr_std = std_erase.begin();
       itr_s21 != s21_erase.end(); itr_s21++, itr_std++) {
    ASSERT_EQ(*itr_s21, *itr_std);
  }
}

TEST(ListModifiers, TestErase_2) {
  s21::list<char> s21_erase{'h', 'e', 'l'};
  std::list<char> std_erase{'h', 'e', 'l'};
  auto itr_s21 = s21_erase.begin();
  auto itr_std = std_erase.begin();
  itr_s21++;
  itr_std++;
  s21_erase.erase(itr_s21);
  std_erase.erase(itr_std);
  for (itr_s21 = s21_erase.begin(), itr_std = std_erase.begin();
       itr_s21 != s21_erase.end(); itr_s21++, itr_std++) {
    ASSERT_EQ(*itr_s21, *itr_std);
  }
}

TEST(ListModifiers, TestErase_3) {
  s21::list<int> s21_erase{9, 3, 2};
  std::list<int> std_erase{9, 3, 2};
  auto itr_s21 = s21_erase.begin();
  auto itr_std = std_erase.begin();
  itr_s21++;
  itr_std++;
  itr_s21++;
  itr_std++;
  s21_erase.erase(itr_s21);
  std_erase.erase(itr_std);
  for (itr_s21 = s21_erase.begin(), itr_std = std_erase.begin();
       itr_s21 != s21_erase.end(); itr_s21++, itr_std++) {
    ASSERT_EQ(*itr_s21, *itr_std);
  }
}

TEST(ListModifiers, TestErase_4) {
  s21::list<int> s21_erase{9};
  std::list<int> std_erase{9};
  auto itr_s21 = s21_erase.begin();
  auto itr_std = std_erase.begin();
  s21_erase.erase(itr_s21);
  std_erase.erase(itr_std);
  s21_erase.insert(s21_erase.begin(), 5);
  std_erase.insert(std_erase.begin(), 5);
  for (itr_s21 = s21_erase.begin(), itr_std = std_erase.begin();
       itr_s21 != s21_erase.end(); itr_s21++, itr_std++) {
    ASSERT_EQ(*itr_s21, *itr_std);
  }
}

TEST(ListModifiers, TestPopBack_1) {
  s21::list<int> s21_pop{1, 1, 1, 1, 1, 1, 1};
  std::list<int> std_pop{1, 1, 1, 1, 1, 1, 1};
  auto itr_s21 = s21_pop.begin();
  auto itr_std = std_pop.begin();
  s21_pop.pop_back();
  std_pop.pop_back();
  for (; itr_s21 != s21_pop.end(); itr_s21++, itr_std++) {
    ASSERT_EQ(*itr_s21, *itr_std);
  }
}

TEST(ListModifiers, TestPopBack_2) {
  s21::list<char> s21_pop{'1'};
  std::list<char> std_pop{'1'};
  s21_pop.pop_back();
  std_pop.pop_back();
  ASSERT_EQ(s21_pop.size(), std_pop.size());
}

TEST(ListModifiers, TestPopBack_3) {
  s21::list<char> s21_pop{'1'};
  std::list<char> std_pop{'1'};
  s21_pop.pop_back();
  std_pop.pop_back();
  s21_pop.push_front('a');
  std_pop.push_front('a');
  ASSERT_EQ(*s21_pop.begin(), *std_pop.begin());
  ASSERT_EQ(s21_pop.size(), std_pop.size());
}

TEST(ListModifiers, TestPopFront_1) {
  s21::list<int> s21_pop{1, 12, 1, 12, 1, 12};
  std::list<int> std_pop{1, 12, 1, 12, 1, 12};
  s21_pop.pop_front();
  std_pop.pop_front();
  auto itr_s21 = s21_pop.begin();
  auto itr_std = std_pop.begin();
  for (; itr_s21 != s21_pop.end(); itr_s21++, itr_std++) {
    ASSERT_EQ(*itr_s21, *itr_std);
  }
}

TEST(ListModifiers, TestPopFront_2) {
  s21::list<char> s21_pop{'b'};
  std::list<char> std_pop{'b'};
  s21_pop.pop_front();
  std_pop.pop_front();
  ASSERT_EQ(s21_pop.size(), std_pop.size());
}

TEST(ListModifiers, TestPopFront_3) {
  s21::list<char> s21_pop{'b'};
  std::list<char> std_pop{'b'};
  s21_pop.pop_front();
  std_pop.pop_front();
  s21_pop.push_front('a');
  std_pop.push_front('a');
  ASSERT_EQ(*s21_pop.begin(), *std_pop.begin());
  ASSERT_EQ(s21_pop.size(), std_pop.size());
}

TEST(ListModifiers, TestSwap_1) {
  s21::list<int> s21_swap{1, 2, 3};
  s21::list<int> s21_swap2{3, 2, 1};
  std::list<int> std_swap{1, 2, 3};
  std::list<int> std_swap2{3, 2, 1};
  s21_swap.swap(s21_swap2);
  std_swap.swap(std_swap2);
  auto itr_s21 = s21_swap.begin();
  auto itr_std = std_swap.begin();
  for (; itr_s21 != s21_swap.end(); itr_s21++, itr_std++) {
    ASSERT_EQ(*itr_s21, *itr_std);
  }
  itr_s21 = s21_swap2.begin();
  itr_std = std_swap2.begin();
  for (; itr_s21 != s21_swap2.end(); itr_s21++, itr_std++) {
    ASSERT_EQ(*itr_s21, *itr_std);
  }
}

TEST(ListModifiers, TestSwap_2) {
  s21::list<double> s21_swap{1.5, 5.1, 5.5};
  s21::list<double> s21_swap2{8.8, 9.1, 10.11, 14.4};
  std::list<double> std_swap{1.5, 5.1, 5.5};
  std::list<double> std_swap2{8.8, 9.1, 10.11, 14.4};
  s21_swap.swap(s21_swap2);
  std_swap.swap(std_swap2);
  auto itr_s21 = s21_swap.begin();
  auto itr_std = std_swap.begin();
  for (; itr_s21 != s21_swap.end(); itr_s21++, itr_std++) {
    ASSERT_EQ(*itr_s21, *itr_std);
  }
  itr_s21 = s21_swap2.begin();
  itr_std = std_swap2.begin();
  for (; itr_s21 != s21_swap2.end(); itr_s21++, itr_std++) {
    ASSERT_EQ(*itr_s21, *itr_std);
  }
}

TEST(ListModifiers, TestSwap_3) {
  s21::list<char> s21_swap{'1', '9', '4'};
  s21::list<char> s21_swap2{'3'};
  std::list<char> std_swap{'1', '9', '4'};
  std::list<char> std_swap2{'3'};
  s21_swap.swap(s21_swap2);
  std_swap.swap(std_swap2);
  auto itr_s21 = s21_swap.begin();
  auto itr_std = std_swap.begin();
  for (; itr_s21 != s21_swap.end(); itr_s21++, itr_std++) {
    ASSERT_EQ(*itr_s21, *itr_std);
  }
  itr_s21 = s21_swap2.begin();
  itr_std = std_swap2.begin();
  for (; itr_s21 != s21_swap2.end(); itr_s21++, itr_std++) {
    ASSERT_EQ(*itr_s21, *itr_std);
  }
}

TEST(ListModifiers, TestSwap_4) {
  s21::list<char> s21_swap;
  s21::list<char> s21_swap2{'3'};
  std::list<char> std_swap;
  std::list<char> std_swap2{'3'};
  s21_swap.swap(s21_swap2);
  std_swap.swap(std_swap2);
  auto itr_s21 = s21_swap.begin();
  auto itr_std = std_swap.begin();
  for (; itr_s21 != s21_swap.end(); itr_s21++, itr_std++) {
    ASSERT_EQ(*itr_s21, *itr_std);
  }
  itr_s21 = s21_swap2.begin();
  itr_std = std_swap2.begin();
  ASSERT_EQ(itr_s21 == s21_swap2.end(), itr_std == std_swap2.end());
}

TEST(ListModifiers, TestSwap_5) {
  s21::list<char> s21_swap;
  s21::list<char> s21_swap2;
  std::list<char> std_swap;
  std::list<char> std_swap2;
  s21_swap.swap(s21_swap2);
  std_swap.swap(std_swap2);
  auto itr_s21 = s21_swap.begin();
  auto itr_std = std_swap.begin();
  ASSERT_EQ(itr_s21 == s21_swap.end(), itr_std == std_swap.end());
  itr_s21 = s21_swap2.begin();
  itr_std = std_swap2.begin();
  ASSERT_EQ(itr_s21 == s21_swap2.end(), itr_std == std_swap2.end());
}

TEST(ListModifiers, TestSort_1) {
  s21::list<int> s21_sort{1, 2, 3, 4, 5};
  std::list<int> std_sort{1, 2, 3, 4, 5};
  s21_sort.sort();
  std_sort.sort();
  auto itr_s21 = s21_sort.begin();
  auto itr_std = std_sort.begin();
  for (; itr_s21 != s21_sort.end(); itr_s21++, itr_std++) {
    ASSERT_EQ(*itr_s21, *itr_std);
  }
}

TEST(ListModifiers, TestSort_2) {
  s21::list<char> s21_sort{'4', '5', '4'};
  std::list<char> std_sort{'4', '5', '4'};
  s21_sort.sort();
  std_sort.sort();
  auto itr_s21 = s21_sort.begin();
  auto itr_std = std_sort.begin();
  for (; itr_s21 != s21_sort.end(); itr_s21++, itr_std++) {
    ASSERT_EQ(*itr_s21, *itr_std);
  }
}

TEST(ListModifiers, TestSort_3) {
  s21::list<double> s21_sort{1.2, 0.1, 0.2, 0.11};
  std::list<double> std_sort{1.2, 0.1, 0.2, 0.11};
  s21_sort.sort();
  std_sort.sort();
  auto itr_s21 = s21_sort.begin();
  auto itr_std = std_sort.begin();
  for (; itr_s21 != s21_sort.end(); itr_s21++, itr_std++) {
    ASSERT_EQ(*itr_s21, *itr_std);
  }
}

TEST(ListModifiers, TestSort_4) {
  s21::list<double> s21_sort;
  std::list<double> std_sort;
  s21_sort.sort();
  std_sort.sort();
  auto itr_s21 = s21_sort.begin();
  auto itr_std = std_sort.begin();
  for (; itr_s21 != s21_sort.end(); itr_s21++, itr_std++) {
    ASSERT_EQ(*itr_s21, *itr_std);
  }
}

TEST(ListModifiers, TestUnique_1) {
  s21::list<int> s21_unique{1, 1, 1, 2, 1, 2, 2, 1, 1, 2, 1};
  std::list<int> std_unique{1, 1, 1, 2, 1, 2, 2, 1, 1, 2, 1};
  s21_unique.unique();
  std_unique.unique();
  auto itr_s21 = s21_unique.begin();
  auto itr_std = std_unique.begin();
  for (; itr_s21 != s21_unique.end(); itr_s21++, itr_std++) {
    ASSERT_EQ(*itr_s21, *itr_std);
  }
}

TEST(ListModifiers, TestUnique_2) {
  s21::list<double> s21_unique{1.0, 0, 0, 0, 0, 1.0, 1.0, 1.0, 0, 1.0, 2.3};
  std::list<double> std_unique{1.0, 0, 0, 0, 0, 1.0, 1.0, 1.0, 0, 1.0, 2.3};
  s21_unique.unique();
  std_unique.unique();
  auto itr_s21 = s21_unique.begin();
  auto itr_std = std_unique.begin();
  for (; itr_s21 != s21_unique.end(); itr_s21++, itr_std++) {
    ASSERT_EQ(*itr_s21, *itr_std);
  }
}

TEST(ListModifiers, TestUnique_3) {
  s21::list<char> s21_unique{'-', '+', '-', '-', '-', '+', '+'};
  std::list<char> std_unique{'-', '+', '-', '-', '-', '+', '+'};
  s21_unique.unique();
  std_unique.unique();
  auto itr_s21 = s21_unique.begin();
  auto itr_std = std_unique.begin();
  for (; itr_s21 != s21_unique.end(); itr_s21++, itr_std++) {
    ASSERT_EQ(*itr_s21, *itr_std);
  }
}

TEST(ListModifiers, TestUnique_4) {
  s21::list<char> s21_unique{'-', 'z', '2', '3', 'a', '.', '+'};
  std::list<char> std_unique{'-', 'z', '2', '3', 'a', '.', '+'};
  s21_unique.unique();
  std_unique.unique();
  auto itr_s21 = s21_unique.begin();
  auto itr_std = std_unique.begin();
  for (; itr_s21 != s21_unique.end(); itr_s21++, itr_std++) {
    ASSERT_EQ(*itr_s21, *itr_std);
  }
}

TEST(ListModifiers, TestUnique_5) {
  s21::list<char> s21_unique;
  std::list<char> std_unique;
  s21_unique.unique();
  std_unique.unique();
  auto itr_s21 = s21_unique.begin();
  auto itr_std = std_unique.begin();
  for (; itr_s21 != s21_unique.end(); itr_s21++, itr_std++) {
    ASSERT_EQ(*itr_s21, *itr_std);
  }
}

TEST(ListModifiers, TestReverse_1) {
  s21::list<char> s21_reverse{'-', 'r', '1', '3'};
  std::list<char> std_reverse{'-', 'r', '1', '3'};
  s21_reverse.reverse();
  std_reverse.reverse();
  auto itr_s21 = s21_reverse.begin();
  auto itr_std = std_reverse.begin();
  for (; itr_s21 != s21_reverse.end(); itr_s21++, itr_std++) {
    ASSERT_EQ(*itr_s21, *itr_std);
  }
}

TEST(ListModifiers, TestReverse_2) {
  s21::list<int> s21_reverse{1, 2, 3, 8897, 13, 532};
  std::list<int> std_reverse{1, 2, 3, 8897, 13, 532};
  s21_reverse.reverse();
  std_reverse.reverse();
  auto itr_s21 = s21_reverse.begin();
  auto itr_std = std_reverse.begin();
  for (; itr_s21 != s21_reverse.end(); itr_s21++, itr_std++) {
    ASSERT_EQ(*itr_s21, *itr_std);
  }
}

TEST(ListModifiers, TestReverse_3) {
  s21::list<double> s21_reverse{1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7};
  std::list<double> std_reverse{1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7};
  s21_reverse.reverse();
  std_reverse.reverse();
  auto itr_s21 = s21_reverse.begin();
  auto itr_std = std_reverse.begin();
  for (; itr_s21 != s21_reverse.end(); itr_s21++, itr_std++) {
    ASSERT_EQ(*itr_s21, *itr_std);
  }
}

TEST(ListModifiers, TestReverse_4) {
  s21::list<double> s21_reverse{1.1};
  std::list<double> std_reverse{1.1};
  s21_reverse.reverse();
  std_reverse.reverse();
  auto itr_s21 = s21_reverse.begin();
  auto itr_std = std_reverse.begin();
  for (; itr_s21 != s21_reverse.end(); itr_s21++, itr_std++) {
    ASSERT_EQ(*itr_s21, *itr_std);
  }
}

TEST(ListModifiers, TestReverse_5) {
  s21::list<double> s21_reverse;
  std::list<double> std_reverse;
  s21_reverse.reverse();
  std_reverse.reverse();
  auto itr_s21 = s21_reverse.begin();
  auto itr_std = std_reverse.begin();
  for (; itr_s21 != s21_reverse.end(); itr_s21++, itr_std++) {
    ASSERT_EQ(*itr_s21, *itr_std);
  }
}

TEST(ListModifiers, TestMerge_1) {
  s21::list<int> s21_merge{5, 9, 1, 3, 3};
  s21::list<int> s21_merge2{8, 7, 2, 3, 4, 4};
  std::list<int> std_merge{5, 9, 1, 3, 3};
  std::list<int> std_merge2{8, 7, 2, 3, 4, 4};
  s21_merge.sort();
  s21_merge2.sort();
  std_merge.sort();
  std_merge2.sort();
  s21_merge.merge(s21_merge2);
  std_merge.merge(std_merge2);
  auto itr_s21 = s21_merge.begin();
  auto itr_std = std_merge.begin();
  for (; itr_s21 != s21_merge.end(); itr_s21++, itr_std++) {
    ASSERT_EQ(*itr_s21, *itr_std);
  }
}

TEST(ListModifiers, TestMerge_2) {
  s21::list<char> s21_merge{'1', '2', '3'};
  s21::list<char> s21_merge2{'4', '5', '6'};
  std::list<char> std_merge{'1', '2', '3'};
  std::list<char> std_merge2{'4', '5', '6'};
  s21_merge.sort();
  s21_merge2.sort();
  std_merge.sort();
  std_merge2.sort();
  s21_merge.merge(s21_merge2);
  std_merge.merge(std_merge2);
  auto itr_s21 = s21_merge.begin();
  auto itr_std = std_merge.begin();
  for (; itr_s21 != s21_merge.end(); itr_s21++, itr_std++) {
    ASSERT_EQ(*itr_s21, *itr_std);
  }
}

TEST(ListModifiers, TestMerge_3) {
  s21::list<char> s21_merge;
  s21::list<char> s21_merge2{'7', '8', '1'};
  std::list<char> std_merge;
  std::list<char> std_merge2{'7', '8', '1'};
  s21_merge2.sort();
  std_merge2.sort();
  s21_merge.merge(s21_merge2);
  std_merge.merge(std_merge2);
  auto itr_s21 = s21_merge.begin();
  auto itr_std = std_merge.begin();
  for (; itr_s21 != s21_merge.end(); itr_s21++, itr_std++) {
    ASSERT_EQ(*itr_s21, *itr_std);
  }
}

TEST(ListModifiers, TestMerge_4) {
  s21::list<int> s21_merge{1, 5, 5, 1, 5, 5};
  s21::list<int> s21_merge2{8, 9, 1};
  std::list<int> std_merge{1, 5, 5, 1, 5, 5};
  std::list<int> std_merge2{8, 9, 1};
  s21_merge.sort();
  s21_merge2.sort();
  std_merge.sort();
  std_merge2.sort();
  s21_merge.merge(s21_merge2);
  std_merge.merge(std_merge2);
  auto itr_s21 = s21_merge.begin();
  auto itr_std = std_merge.begin();
  for (; itr_s21 != s21_merge.end(); itr_s21++, itr_std++) {
    ASSERT_EQ(*itr_s21, *itr_std);
  }
}

TEST(ListModifiers, TestMerge_5) {
  s21::list<int> s21_merge;
  s21::list<int> s21_merge2;
  std::list<int> std_merge;
  std::list<int> std_merge2;
  s21_merge.sort();
  s21_merge2.sort();
  std_merge.sort();
  std_merge2.sort();
  s21_merge.merge(s21_merge2);
  std_merge.merge(std_merge2);
  auto itr_s21 = s21_merge.begin();
  auto itr_std = std_merge.begin();
  for (; itr_s21 != s21_merge.end(); itr_s21++, itr_std++) {
    ASSERT_EQ(*itr_s21, *itr_std);
  }
}

TEST(ListModifiers, TestMerge_6) {
  s21::list<int> s21_merge{5, 3, 4, 6};
  s21::list<int> s21_merge2{1, 2, 3, 4};
  std::list<int> std_merge{5, 3, 4, 6};
  std::list<int> std_merge2{1, 2, 3, 4};
  s21_merge.sort();
  s21_merge2.sort();
  std_merge.sort();
  std_merge2.sort();
  s21_merge.merge(s21_merge2);
  std_merge.merge(std_merge2);
  auto itr_s21 = s21_merge.begin();
  auto itr_std = std_merge.begin();
  for (; itr_s21 != s21_merge.end(); itr_s21++, itr_std++) {
    ASSERT_EQ(*itr_s21, *itr_std);
  }
}

TEST(ListModifiers, TestMerge_7) {
  s21::list<int> s21_merge{5, 3, 4, 6};
  s21::list<int> s21_merge2;
  std::list<int> std_merge{5, 3, 4, 6};
  std::list<int> std_merge2;
  s21_merge.sort();
  s21_merge2.sort();
  std_merge.sort();
  std_merge2.sort();
  s21_merge.merge(s21_merge2);
  std_merge.merge(std_merge2);
  auto itr_s21 = s21_merge.begin();
  auto itr_std = std_merge.begin();
  for (; itr_s21 != s21_merge.end(); itr_s21++, itr_std++) {
    ASSERT_EQ(*itr_s21, *itr_std);
  }
}

TEST(ListModifiers, TestMerge_8) {
  s21::list<int> s21_merge{55, 16, 3, 0,   99,  15, 2, 88,
                           14, 9,  8, 155, 123, 1,  13};
  s21::list<int> s21_merge2{1000, 5,  1,      222, 33,  0,  19,
                            17,   21, 555555, 1,   123, 90, 91};
  std::list<int> std_merge{55, 16, 3, 0,   99,  15, 2, 88,
                           14, 9,  8, 155, 123, 1,  13};
  std::list<int> std_merge2{1000, 5,  1,      222, 33,  0,  19,
                            17,   21, 555555, 1,   123, 90, 91};
  s21_merge.sort();
  s21_merge2.sort();
  std_merge.sort();
  std_merge2.sort();
  s21_merge.merge(s21_merge2);
  std_merge.merge(std_merge2);
  auto itr_s21 = s21_merge.begin();
  auto itr_std = std_merge.begin();
  for (; itr_s21 != s21_merge.end(); itr_s21++, itr_std++) {
    ASSERT_EQ(*itr_s21, *itr_std);
  }
}

TEST(ListModifiers, TestSplice_1) {
  s21::list<double> s21_splice{1, 5, 5, 1, 5, 5};
  s21::list<double> s21_splice2{8, 9, 1};
  std::list<double> std_splice{1, 5, 5, 1, 5, 5};
  std::list<double> std_splice2{8, 9, 1};
  auto itr_s21 = s21_splice.begin();
  itr_s21++;
  itr_s21++;
  auto itr_std = std_splice.begin();
  itr_std++;
  itr_std++;
  s21_splice.splice(itr_s21, s21_splice2);
  std_splice.splice(itr_std, std_splice2);
  for (; itr_s21 != s21_splice.end(); itr_s21++, itr_std++) {
    ASSERT_EQ(*itr_s21, *itr_std);
  }
}

TEST(ListModifiers, TestSplice_2) {
  s21::list<int> s21_splice{5, 5, 5, 5, 5, 5};
  s21::list<int> s21_splice2{1, 2, 3, 4, 5};
  std::list<int> std_splice{5, 5, 5, 5, 5, 5};
  std::list<int> std_splice2{1, 2, 3, 4, 5};
  auto itr_s21 = s21_splice.begin();
  itr_s21++;
  auto itr_std = std_splice.begin();
  itr_std++;
  s21_splice.splice(itr_s21, s21_splice2);
  std_splice.splice(itr_std, std_splice2);
  for (; itr_s21 != s21_splice.end(); itr_s21++, itr_std++) {
    ASSERT_EQ(*itr_s21, *itr_std);
  }
}

TEST(ListModifiers, TestSplice_3) {
  s21::list<int> s21_splice{5, 5, 5, 5, 5, 5};
  s21::list<int> s21_splice2{1, 2, 3, 4, 5};
  std::list<int> std_splice{5, 5, 5, 5, 5, 5};
  std::list<int> std_splice2{1, 2, 3, 4, 5};
  auto itr_s21 = s21_splice.end();
  auto itr_std = std_splice.end();
  s21_splice.splice(itr_s21, s21_splice2);
  std_splice.splice(itr_std, std_splice2);
  for (itr_std = std_splice.begin(), itr_s21 = s21_splice.begin();
       itr_s21 != s21_splice.end(); itr_s21++, itr_std++) {
    ASSERT_EQ(*itr_s21, *itr_std);
  }
}

TEST(ListModifiers, TestSplice_4) {
  s21::list<char> s21_splice{'g', 'g', 'r', 't', 'y', '2', '`'};
  s21::list<char> s21_splice2{'1', ',', 'n'};
  std::list<char> std_splice{'g', 'g', 'r', 't', 'y', '2', '`'};
  std::list<char> std_splice2{'1', ',', 'n'};
  auto itr_s21 = s21_splice.begin();
  auto itr_std = std_splice.begin();
  s21_splice.splice(itr_s21, s21_splice2);
  std_splice.splice(itr_std, std_splice2);
  for (itr_std = std_splice.begin(), itr_s21 = s21_splice.begin();
       itr_s21 != s21_splice.end(); itr_s21++, itr_std++) {
    ASSERT_EQ(*itr_s21, *itr_std);
  }
}

TEST(ListModifiers, TestSplice_5) {
  s21::list<char> s21_splice;
  s21::list<char> s21_splice2{'1', ',', 'n'};
  std::list<char> std_splice;
  std::list<char> std_splice2{'1', ',', 'n'};
  auto itr_s21 = s21_splice.begin();
  auto itr_std = std_splice.begin();
  s21_splice.splice(itr_s21, s21_splice2);
  std_splice.splice(itr_std, std_splice2);
  for (itr_std = std_splice.begin(), itr_s21 = s21_splice.begin();
       itr_s21 != s21_splice.end(); itr_s21++, itr_std++) {
    ASSERT_EQ(*itr_s21, *itr_std);
  }
}

TEST(ListModifiers, TestSplice_6) {
  s21::list<char> s21_splice{'1', ',', 'n'};
  s21::list<char> s21_splice2;
  std::list<char> std_splice{'1', ',', 'n'};
  std::list<char> std_splice2;
  auto itr_s21 = s21_splice.begin();
  auto itr_std = std_splice.begin();
  s21_splice.splice(itr_s21, s21_splice2);
  std_splice.splice(itr_std, std_splice2);
  for (itr_std = std_splice.begin(), itr_s21 = s21_splice.begin();
       itr_s21 != s21_splice.end(); itr_s21++, itr_std++) {
    ASSERT_EQ(*itr_s21, *itr_std);
  }
}

TEST(ListModifiers, TestSplice_7) {
  s21::list<char> s21_splice;
  s21::list<char> s21_splice2;
  std::list<char> std_splice;
  std::list<char> std_splice2;
  auto itr_s21 = s21_splice.begin();
  auto itr_std = std_splice.begin();
  s21_splice.splice(itr_s21, s21_splice2);
  std_splice.splice(itr_std, std_splice2);
  for (itr_std = std_splice.begin(), itr_s21 = s21_splice.begin();
       itr_s21 != s21_splice.end(); itr_s21++, itr_std++) {
    ASSERT_EQ(*itr_s21, *itr_std);
  }
}

TEST(ListInsertMany, TestInsertMany_1) {
  s21::list<int> s21_list;
  std::list<int> std_list{1, 2, 3, 4, 5, 6, 222, 441, 55};

  s21_list.insert_many(s21_list.begin(), 1, 2, 3, 4, 5, 6, 222, 441, 55);
  auto s21_itr = s21_list.begin();
  auto std_itr = std_list.begin();
  for (; s21_itr != s21_list.end(); ++s21_itr, ++std_itr) {
    ASSERT_EQ(*s21_itr, *std_itr);
  }
}

TEST(ListInsertMany, TestInsertMany_2) {
  s21::list<int> s21_list{1, 3, 5000};
  std::list<int> std_list{1, 3, 1, 2, 3, 4, 5, 6, 222, 441, 55, 5000};

  auto s21_itr = s21_list.begin();
  ++s21_itr;
  ++s21_itr;

  s21_itr = s21_list.insert_many(s21_itr, 1, 2, 3, 4, 5, 6, 222, 441, 55);
  ASSERT_EQ(*s21_itr, s21_list.back());
  s21_itr = s21_list.begin();
  auto std_itr = std_list.begin();
  for (; s21_itr != s21_list.end(); ++s21_itr, ++std_itr) {
    ASSERT_EQ(*s21_itr, *std_itr);
  }
}

TEST(ListInsertMany, TestInsertMany_3) {
  s21::list<int> s21_list{-1, 0};
  std::list<int> std_list{-1, 1, 2, 3, 4, 5, 6, 222, 441, 55, 0};

  auto s21_itr = s21_list.begin();
  ++s21_itr;

  s21_itr = s21_list.insert_many(s21_itr, 1, 2, 3, 4, 5, 6, 222, 441, 55);
  ASSERT_EQ(*s21_itr, s21_list.back());
  s21_itr = s21_list.begin();
  auto std_itr = std_list.begin();
  for (; s21_itr != s21_list.end(); ++s21_itr, ++std_itr) {
    ASSERT_EQ(*s21_itr, *std_itr);
  }
}

TEST(ListInsertMany, TestInsertMany_4) {
  s21::list<int> s21_list{-1, 0};
  std::list<int> std_list{-1, 0, 1, 2, 3, 4, 5, 6, 222, 441, 55};

  auto s21_itr = s21_list.end();

  s21_itr = s21_list.insert_many(s21_itr, 1, 2, 3, 4, 5, 6, 222, 441, 55);
  ASSERT_TRUE(s21_itr == s21_list.end());
  s21_itr = s21_list.begin();
  auto std_itr = std_list.begin();
  for (; s21_itr != s21_list.end(); ++s21_itr, ++std_itr) {
    ASSERT_EQ(*s21_itr, *std_itr);
  }
}

TEST(ListInsertMany, TestInsertMany_5) {
  s21::list<int> s21_list{-1, 0};
  std::list<int> std_list{1, 2, 3, 4, 5, 6, 222, 441, 55, -1, 0};

  auto s21_itr = s21_list.begin();

  s21_itr = s21_list.insert_many(s21_itr, 1, 2, 3, 4, 5, 6, 222, 441, 55);
  ASSERT_TRUE((*(++s21_itr)) == s21_list.back());
  s21_itr = s21_list.begin();
  auto std_itr = std_list.begin();
  for (; s21_itr != s21_list.end(); ++s21_itr, ++std_itr) {
    ASSERT_EQ(*s21_itr, *std_itr);
  }
}

TEST(ListInsertMany, TestInsertManyBack_1) {
  s21::list<int> s21_list;
  std::list<int> std_list{1, 2, 3, 4, 5, 6, 222, 441, 55};

  s21_list.insert_many_back(1, 2, 3, 4, 5, 6, 222, 441, 55);
  auto s21_itr = s21_list.begin();
  auto std_itr = std_list.begin();
  for (; s21_itr != s21_list.end(); ++s21_itr, ++std_itr) {
    ASSERT_EQ(*s21_itr, *std_itr);
  }
  ASSERT_EQ(s21_list.size(), std_list.size());
}

TEST(ListInsertMany, TestInsertManyBack_2) {
  s21::list<int> s21_list{5, 1, 2, 3};
  std::list<int> std_list{5, 1, 2, 3, 441};

  s21_list.insert_many_back(441);
  auto s21_itr = s21_list.begin();
  auto std_itr = std_list.begin();
  for (; s21_itr != s21_list.end(); ++s21_itr, ++std_itr) {
    ASSERT_EQ(*s21_itr, *std_itr);
  }
  ASSERT_EQ(s21_list.size(), std_list.size());
}

TEST(ListInsertMany, TestInsertManyBack_3) {
  s21::list<char> s21_list{'a'};
  std::list<char> std_list{'a', 'b', '/', '+', '0'};

  s21_list.insert_many_back('b', '/', '+', '0');
  auto s21_itr = s21_list.begin();
  auto std_itr = std_list.begin();
  for (; s21_itr != s21_list.end(); ++s21_itr, ++std_itr) {
    ASSERT_EQ(*s21_itr, *std_itr);
  }
  ASSERT_EQ(s21_list.size(), std_list.size());
}

TEST(ListInsertMany, TestInsertManyFront_1) {
  s21::list<int> s21_list;
  std::list<int> std_list{1, 2, 3, 4, 5, 6, 222, 441, 55};
  std_list.reverse();

  s21_list.insert_many_front(1, 2, 3, 4, 5, 6, 222, 441, 55);
  auto s21_itr = s21_list.begin();
  auto std_itr = std_list.begin();
  for (; s21_itr != s21_list.end(); ++s21_itr, ++std_itr) {
    ASSERT_EQ(*s21_itr, *std_itr);
  }
  ASSERT_EQ(s21_list.size(), std_list.size());
}

TEST(ListInsertMany, TestInsertManyFront_2) {
  s21::list<int> s21_list{5, 1, 2, 3};
  std::list<int> std_list{441, 5, 1, 2, 3};

  s21_list.insert_many_front(441);
  auto s21_itr = s21_list.begin();
  auto std_itr = std_list.begin();
  for (; s21_itr != s21_list.end(); ++s21_itr, ++std_itr) {
    ASSERT_EQ(*s21_itr, *std_itr);
  }
  ASSERT_EQ(s21_list.size(), std_list.size());
}

TEST(ListInsertMany, TestInsertManyFront_3) {
  s21::list<char> s21_list{'a'};
  std::list<char> std_list{'0', '+', '/', 'b', 'a'};

  s21_list.insert_many_front('b', '/', '+', '0');
  auto s21_itr = s21_list.begin();
  auto std_itr = std_list.begin();
  for (; s21_itr != s21_list.end(); ++s21_itr, ++std_itr) {
    ASSERT_EQ(*s21_itr, *std_itr);
  }
  ASSERT_EQ(s21_list.size(), std_list.size());
}

TEST(ListCombo, TestCombo_1) {
  const s21::list<int> s21_combo(5, 6);
  std::list<int> std_combo(5, 6);
  const s21::list<int> s21_combo2 = s21_combo;
  auto itr_s21 = s21_combo2.begin();
  auto itr_std = std_combo.begin();
  for (; itr_s21 != s21_combo2.end(); itr_s21++, itr_std++) {
    ASSERT_EQ(*itr_s21, *itr_std);
  }
}

TEST(ListCombo, TestCombo_2) {
  const s21::list<int> s21_combo(10, 10);
  std::list<int> std_combo(10, 10);
  const s21::list<int> s21_combo2 = s21_combo;
  s21::list<int>::const_iterator itr_s21 = s21_combo2.end();
  auto itr_std = std_combo.end();
  itr_std--;
  itr_s21--;
  for (itr_std = std_combo.begin(), itr_s21 = s21_combo2.begin();
       itr_s21 != s21_combo2.end(); itr_s21++, itr_std++) {
    ASSERT_EQ(*itr_s21, *itr_std);
  }
}

TEST(ListCombo, TestCombo_3) {
  s21::list<double> s21_combo(5, 11.1);
  std::list<double> std_combo(5, 11.1);
  auto s21_front = s21_combo.front();
  auto std_front = std_combo.front();
  ASSERT_EQ(s21_front, std_front);
  s21_front = s21_combo.back();
  std_front = std_combo.back();
  ASSERT_EQ(s21_front, std_front);
}

TEST(ListCombo, TestCombo_4) {
  s21::list<int> s21_combo(5, 6);
  std::list<int> std_combo(5, 6);
  s21::list<int> s21_combo2 = std::move(s21_combo);
  auto itr_s21 = s21_combo2.begin();
  auto itr_std = std_combo.begin();
  for (; itr_s21 != s21_combo2.end(); itr_s21++, itr_std++) {
    ASSERT_EQ(*itr_s21, *itr_std);
  }
}

TEST(ListCombo, TestCombo_5) {
  const s21::list<int> s21_combo(2, 9);
  std::list<int> std_combo(2, 9);
  const s21::list<int> s21_combo2 = std::move(s21_combo);
  s21::list<int>::const_iterator itr_s21;
  itr_s21 = s21_combo2.begin();
  auto itr_std = std_combo.begin();
  for (; itr_s21 != s21_combo2.end(); itr_s21++, itr_std++) {
    ASSERT_EQ(*itr_s21, *itr_std);
  }
  itr_s21 = s21_combo2.begin();
  auto itr2_s21 = s21_combo2.begin();
  ASSERT_EQ(itr_s21 == itr2_s21, 1);
  ASSERT_EQ(*itr_s21 == *itr2_s21, 1);
}

TEST(ListCombo, TestCombo_6) {
  s21::list<std::string> s21_combo{"123", "hello"};
  std::list<std::string> std_combo{"123", "hello"};
  s21::list<std::string> s21_combo2 = std::move(s21_combo);
  s21::list<std::string>::iterator itr_s21;
  itr_s21 = s21_combo2.end();
  itr_s21--;
  itr_s21--;
  auto itr_std = std_combo.begin();
  for (; itr_s21 != s21_combo2.end(); itr_s21++, itr_std++) {
    ASSERT_EQ(*itr_s21, *itr_std);
  }
}

TEST(ListCombo, TestCombo_7) {
  s21::list<char> s21_combo{'1', '2'};
  std::list<char> std_combo{'1', '2'};
  s21::list<char> s21_combo2 = std::move(s21_combo);
  s21::list<char>::iterator itr_s21;
  itr_s21 = s21_combo2.begin();
  itr_s21++;
  itr_s21++;
  auto itr_std = std_combo.begin();
  for (; itr_s21 != s21_combo2.end(); itr_s21++, itr_std++) {
    ASSERT_EQ(*itr_s21, *itr_std);
  }
}
