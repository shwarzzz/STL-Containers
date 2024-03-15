#include <gtest/gtest.h>

#include <iostream>
#include <set>
#include <vector>

#include "../s21_containersplus.h"

TEST(MultisetMemberFunctions, TestDefault) {
  std::multiset<int> std_multiset;
  s21::multiset<int> s21_multiset;

  ASSERT_EQ(std_multiset.size(), s21_multiset.size());
}

TEST(MultisetMemberFunctions, TestInitializerList_1) {
  std::multiset<int> std_multiset{1, 5, 2, 3};
  s21::multiset<int> s21_multiset{1, 5, 2, 3};
  ASSERT_EQ(std_multiset.size(), s21_multiset.size());

  std::multiset<int>::iterator std_itr(std_multiset.begin());
  s21::multiset<int>::iterator s21_itr(s21_multiset.begin());
  for (size_t i = 0; i < s21_multiset.size(); ++i) {
    ASSERT_EQ(*std_itr, *s21_itr);
    ++std_itr;
    ++s21_itr;
  }
}

TEST(MultisetMemberFunctions, TestInitializerList_2) {
  std::multiset<std::string> std_multiset{
      "alo", "alo", "alo", "alo", "alo", "alo",
      "alo", "alo", "alo", "alo", "alo", "alo",
  };
  s21::multiset<std::string> s21_multiset{
      "alo", "alo", "alo", "alo", "alo", "alo",
      "alo", "alo", "alo", "alo", "alo", "alo",
  };
  ASSERT_EQ(std_multiset.size(), s21_multiset.size());

  std::multiset<std::string>::iterator std_itr(std_multiset.begin());
  s21::multiset<std::string>::iterator s21_itr(s21_multiset.begin());
  for (size_t i = 0; i < s21_multiset.size(); ++i) {
    ASSERT_EQ(*std_itr, *s21_itr);
    ++std_itr;
    ++s21_itr;
  }
}

TEST(MultisetMemberFunctions, TestCopy) {
  std::multiset<char, std::greater<char>> std_multiset{'e', 'a', 'h', 'r', 'e'};
  s21::multiset<char, std::greater<char>> s21_multiset{'e', 'a', 'h', 'r', 'e'};
  ASSERT_EQ(std_multiset.size(), s21_multiset.size());

  std::multiset<char, std::greater<char>> std_copy(std_multiset);
  s21::multiset<char, std::greater<char>> s21_copy(s21_multiset);
  ASSERT_EQ(std_copy.size(), s21_copy.size());

  std::multiset<char, std::greater<char>>::iterator std_itr(std_copy.begin());
  s21::multiset<char, std::greater<char>>::iterator s21_itr(s21_copy.begin());
  for (size_t i = 0; i < s21_copy.size(); ++i) {
    ASSERT_EQ(*std_itr, *s21_itr);
    ++std_itr;
    ++s21_itr;
  }
}

TEST(MultisetMemberFunctions, TestMove) {
  std::multiset<char, std::greater<char>> std_multiset{'a', 'b', 'c', 'd', 'e'};
  s21::multiset<char, std::greater<char>> s21_multiset{'a', 'b', 'c', 'd', 'e'};
  ASSERT_EQ(std_multiset.size(), s21_multiset.size());

  std::multiset<char, std::greater<char>> std_move(std::move(std_multiset));
  s21::multiset<char, std::greater<char>> s21_move(std::move(s21_multiset));
  ASSERT_EQ(std_move.size(), s21_move.size());

  std::multiset<char, std::greater<char>>::iterator std_itr(std_move.begin());
  s21::multiset<char, std::greater<char>>::iterator s21_itr(s21_move.begin());
  for (size_t i = 0; i < s21_move.size(); ++i) {
    ASSERT_EQ(*std_itr, *s21_itr);
    ++std_itr;
    ++s21_itr;
  }
}

TEST(MultisetMemberFunctions, TestDestructor_1) {
  std::multiset<char, std::greater<char>>* std_multiset =
      new std::multiset<char, std::greater<char>>();
  s21::multiset<char, std::greater<char>>* s21_multiset =
      new s21::multiset<char, std::greater<char>>();

  delete std_multiset;
  delete s21_multiset;
}

TEST(MultisetMemberFunctions, TestDestructor_2) {
  std::multiset<char, std::greater<char>>* std_multiset =
      new std::multiset<char, std::greater<char>>{'a', 'b', 'c', 'd', 'e'};
  s21::multiset<char, std::greater<char>>* s21_multiset =
      new s21::multiset<char, std::greater<char>>{'a', 'b', 'c', 'd', 'e'};

  delete std_multiset;
  delete s21_multiset;
}

TEST(MultisetMemberFunctions, TestMoveOperator) {
  std::multiset<char, std::greater<char>> std_multiset{'a', 'b', 'c', 'd', 'e'};
  s21::multiset<char, std::greater<char>> s21_multiset{'a', 'b', 'c', 'd', 'e'};
  ASSERT_EQ(std_multiset.size(), s21_multiset.size());

  std::multiset<char, std::greater<char>> std_move{'f', 'a', 'e', '1',
                                                   '2', '.', 'l'};
  s21::multiset<char, std::greater<char>> s21_move{'f', 'a', 'e', '1',
                                                   '2', '.', 'l'};

  std_move = std::move(std_multiset);
  s21_move = std::move(s21_multiset);
  ASSERT_EQ(std_move.size(), s21_move.size());

  std::multiset<char, std::greater<char>>::iterator std_itr(std_move.begin());
  s21::multiset<char, std::greater<char>>::iterator s21_itr(s21_move.begin());
  for (size_t i = 0; i < s21_move.size(); ++i) {
    ASSERT_EQ(*std_itr, *s21_itr);
    ++std_itr;
    ++s21_itr;
  }
}

TEST(MultisetMemberFunctions, TestCopyOperator) {
  std::multiset<char, std::greater<char>> std_multiset{'e', 'a', 'h', 'r', 'e'};
  s21::multiset<char, std::greater<char>> s21_multiset{'e', 'a', 'h', 'r', 'e'};
  ASSERT_EQ(std_multiset.size(), s21_multiset.size());

  std::multiset<char, std::greater<char>> std_copy;
  s21::multiset<char, std::greater<char>> s21_copy;

  std_copy = std_multiset;
  s21_copy = s21_multiset;
  ASSERT_EQ(std_copy.size(), s21_copy.size());

  std::multiset<char, std::greater<char>>::iterator std_itr(std_copy.begin());
  s21::multiset<char, std::greater<char>>::iterator s21_itr(s21_copy.begin());
  for (size_t i = 0; i < s21_copy.size(); ++i) {
    ASSERT_EQ(*std_itr, *s21_itr);
    ++std_itr;
    ++s21_itr;
  }
}

TEST(MultisetIterators, TestBeginEnd) {
  std::multiset<unsigned> std_multiset{55, 16, 3, 0,   99,  15, 2, 88,
                                       14, 9,  8, 155, 123, 1,  13};
  s21::multiset<unsigned> s21_multiset{55, 16, 3, 0,   99,  15, 2, 88,
                                       14, 9,  8, 155, 123, 1,  13};
  ASSERT_EQ(std_multiset.size(), s21_multiset.size());

  std::multiset<unsigned>::iterator std_itr;
  std_itr = std_multiset.begin();
  s21::multiset<unsigned>::iterator s21_itr;
  s21_itr = s21_multiset.begin();
  for (; s21_itr != s21_multiset.end() && std_itr != std_multiset.end();
       ++std_itr, ++s21_itr) {
    ASSERT_EQ(*std_itr, *s21_itr);
  }
  --std_itr;
  --s21_itr;
  for (; s21_itr != s21_multiset.begin() && std_itr != std_multiset.begin();
       --std_itr, --s21_itr) {
    ASSERT_EQ(*std_itr, *s21_itr);
  }

  s21::multiset<unsigned>::iterator s21_end(s21_multiset.end());
  ++s21_end;
  ASSERT_TRUE(s21_end == s21_multiset.begin());
  --s21_end;
  ASSERT_TRUE(s21_end == s21_multiset.end());
}

TEST(MultisetIterators, TestConstBeginEnd) {
  const std::multiset<unsigned> std_multiset{55, 16, 3, 0,   99,  15, 2, 88,
                                             14, 9,  8, 155, 123, 1,  13};
  const s21::multiset<unsigned> s21_multiset{55, 16, 3, 0,   99,  15, 2, 88,
                                             14, 9,  8, 155, 123, 1,  13};
  ASSERT_EQ(std_multiset.size(), s21_multiset.size());

  std::multiset<unsigned>::const_iterator std_itr;
  std_itr = std_multiset.begin();
  s21::multiset<unsigned>::const_iterator s21_itr;
  s21_itr = s21_multiset.begin();
  for (; s21_itr != s21_multiset.end() && std_itr != std_multiset.end();
       ++std_itr, ++s21_itr) {
    ASSERT_EQ(*std_itr, *s21_itr);
  }
  --std_itr;
  --s21_itr;
  for (; s21_itr != s21_multiset.begin() && std_itr != std_multiset.begin();
       --std_itr, --s21_itr) {
    ASSERT_EQ(*std_itr, *s21_itr);
  }

  s21::multiset<unsigned>::const_iterator s21_end(s21_multiset.end());
  ++s21_end;
  ASSERT_TRUE(s21_end == s21_multiset.begin());
  --s21_end;
  ASSERT_TRUE(s21_end == s21_multiset.end());
}

TEST(MultisetCapacity, TestSizeAndEmpty_1) {
  std::multiset<unsigned> std_multiset{55, 16, 3, 0,   99,  15, 2, 88,
                                       14, 9,  8, 155, 123, 1,  13};
  s21::multiset<unsigned> s21_multiset{55, 16, 3, 0,   99,  15, 2, 88,
                                       14, 9,  8, 155, 123, 1,  13};
  ASSERT_EQ(std_multiset.empty(), s21_multiset.empty());
  ASSERT_EQ(std_multiset.size(), s21_multiset.size());

  std_multiset.clear();
  s21_multiset.clear();

  ASSERT_EQ(std_multiset.empty(), s21_multiset.empty());
  ASSERT_EQ(std_multiset.size(), s21_multiset.size());
}

TEST(MultisetCapacity, TestSizeAndEmpty_2) {
  std::multiset<int> std_multiset;
  s21::multiset<int> s21_multiset;

  ASSERT_EQ(std_multiset.empty(), s21_multiset.empty());
  ASSERT_EQ(std_multiset.size(), s21_multiset.size());

  std_multiset.insert(1);
  s21_multiset.insert(1);

  ASSERT_EQ(std_multiset.empty(), s21_multiset.empty());
  ASSERT_EQ(std_multiset.size(), s21_multiset.size());
}

TEST(MultisetCapacity, TestMaxSize_1) {
  std::multiset<unsigned> std_multiset;
  s21::multiset<unsigned> s21_multiset;
  ASSERT_NE(std_multiset.max_size(), s21_multiset.max_size());
}

TEST(MultisetCapacity, TestMaxSize_2) {
  s21::multiset<std::string, std::greater_equal<std::string>> s21_multiset;
  std::multiset<std::string, std::greater_equal<std::string>> std_multiset;
  ASSERT_NE(std_multiset.max_size(), s21_multiset.max_size());
}

TEST(multisetModifiers, TestClear_1) {
  std::multiset<unsigned, std::greater<unsigned>> std_multiset{
      55, 16, 3, 0, 99, 15, 2, 88, 14, 9, 8, 155, 123, 1, 13};
  s21::multiset<unsigned, std::greater<unsigned>> s21_multiset{
      55, 16, 3, 0, 99, 15, 2, 88, 14, 9, 8, 155, 123, 1, 13};
  ASSERT_EQ(std_multiset.empty(), s21_multiset.empty());
  ASSERT_EQ(std_multiset.size(), s21_multiset.size());

  std_multiset.clear();
  s21_multiset.clear();

  ASSERT_EQ(std_multiset.empty(), s21_multiset.empty());
  ASSERT_EQ(std_multiset.size(), s21_multiset.size());
}

TEST(MultisetModifiers, TestClear_2) {
  std::multiset<int> std_multiset;
  s21::multiset<int> s21_multiset;

  std_multiset.clear();
  s21_multiset.clear();

  ASSERT_EQ(std_multiset.empty(), s21_multiset.empty());
  ASSERT_EQ(std_multiset.size(), s21_multiset.size());

  std_multiset.insert(1);
  s21_multiset.insert(1);

  std_multiset.clear();
  s21_multiset.clear();

  ASSERT_EQ(std_multiset.empty(), s21_multiset.empty());
  ASSERT_EQ(std_multiset.size(), s21_multiset.size());
}

TEST(MultisetModifiers, TestInsert_1) {
  std::multiset<unsigned, std::greater<unsigned>> std_multiset{
      55, 16, 3, 0, 99, 15, 2, 88, 14, 9, 8, 155, 123, 1, 13};
  s21::multiset<unsigned, std::greater<unsigned>> s21_multiset{
      55, 16, 3, 0, 99, 15, 2, 88, 14, 9, 8, 155, 123, 1, 13};

  auto std_itr = std_multiset.insert(1000);
  auto s21_itr = s21_multiset.insert(1000);

  std_itr = std_multiset.insert(1000);
  s21_itr = s21_multiset.insert(1000);

  ASSERT_EQ(*std_itr, *std_itr);
  ASSERT_EQ(std_multiset.size(), s21_multiset.size());

  std_itr = std_multiset.begin();
  s21_itr = s21_multiset.begin();

  for (; s21_itr != s21_multiset.end(); ++std_itr, ++s21_itr) {
    ASSERT_EQ(*std_itr, *std_itr);
  }
}

TEST(MultisetModifiers, TestInsert_2) {
  std::multiset<int> std_multiset;
  s21::multiset<int> s21_multiset;

  auto std_itr = std_multiset.insert(1);
  auto s21_itr = s21_multiset.insert(1);
  ASSERT_EQ(*std_itr, *s21_itr);
}

TEST(MultisetModifiers, TestInsert_3) {
  std::multiset<std::string> std_multiset;
  s21::multiset<std::string> s21_multiset;
  std_multiset.insert("suda");
  s21_multiset.insert("suda");
  std_multiset.insert("suda");
  s21_multiset.insert("suda");
  std_multiset.insert("suda");
  s21_multiset.insert("suda");
  std_multiset.insert("suda");
  s21_multiset.insert("suda");
  std_multiset.insert("suda");
  s21_multiset.insert("suda");
  std_multiset.insert("suda");
  s21_multiset.insert("suda");
  std_multiset.insert("suda");
  s21_multiset.insert("suda");

  auto std_itr = std_multiset.begin();
  auto s21_itr = s21_multiset.begin();

  for (; s21_itr != s21_multiset.end(); ++std_itr, ++s21_itr) {
    ASSERT_EQ(*std_itr, *std_itr);
  }
}

TEST(MultisetModifiers, TestErase_1) {
  std::multiset<unsigned, std::greater<unsigned>> std_multiset{
      55, 16, 3, 0, 99, 15, 2, 88, 14, 9, 8, 155, 123, 1, 13};
  s21::multiset<unsigned, std::greater<unsigned>> s21_multiset{
      55, 16, 3, 0, 99, 15, 2, 88, 14, 9, 8, 155, 123, 1, 13};

  std_multiset.erase(std_multiset.begin());
  s21_multiset.erase(s21_multiset.begin());

  auto std_itr = std_multiset.begin();
  auto s21_itr = s21_multiset.begin();

  ++std_itr;
  ++s21_itr;

  std_multiset.erase(std_itr);
  s21_multiset.erase(s21_itr);

  ASSERT_EQ(std_multiset.size(), s21_multiset.size());

  std_itr = std_multiset.begin();
  s21_itr = s21_multiset.begin();

  for (; s21_itr != s21_multiset.end(); ++s21_itr, ++std_itr) {
    ASSERT_EQ(*std_itr, *s21_itr);
  }
}

TEST(MultisetModifiers, TestErase_2) {
  std::multiset<std::string> std_multiset{"2", "1", "3"};
  s21::multiset<std::string> s21_multiset{"2", "1", "3"};

  std_multiset.erase(++(std_multiset.begin()));
  s21_multiset.erase(++(s21_multiset.begin()));

  auto std_s_itr = std_multiset.begin();
  auto s21_s_itr = s21_multiset.begin();
  ASSERT_EQ(std_multiset.size(), s21_multiset.size());
  for (; s21_s_itr != s21_multiset.end(); ++s21_s_itr, ++std_s_itr) {
    ASSERT_EQ(*std_s_itr, *s21_s_itr);
  }

  std_multiset.erase(std_multiset.begin());
  s21_multiset.erase(s21_multiset.begin());

  std_s_itr = std_multiset.begin();
  s21_s_itr = s21_multiset.begin();
  ASSERT_EQ(std_multiset.size(), s21_multiset.size());
  for (; s21_s_itr != s21_multiset.end(); ++s21_s_itr, ++std_s_itr) {
    ASSERT_EQ(*std_s_itr, *s21_s_itr);
  }
}

TEST(MultisetModifiers, TestErase_3) {
  std::multiset<std::string> std_multiset{"2", "2", "2"};
  s21::multiset<std::string> s21_multiset{"2", "2", "2"};

  std_multiset.erase(++(std_multiset.begin()));
  s21_multiset.erase(++(s21_multiset.begin()));

  auto std_s_itr = std_multiset.begin();
  auto s21_s_itr = s21_multiset.begin();
  ASSERT_EQ(std_multiset.size(), s21_multiset.size());
  for (; s21_s_itr != s21_multiset.end(); ++s21_s_itr, ++std_s_itr) {
    ASSERT_EQ(*std_s_itr, *s21_s_itr);
  }

  std_multiset.erase(std_multiset.begin());
  s21_multiset.erase(s21_multiset.begin());

  std_s_itr = std_multiset.begin();
  s21_s_itr = s21_multiset.begin();
  ASSERT_EQ(std_multiset.size(), s21_multiset.size());
  for (; s21_s_itr != s21_multiset.end(); ++s21_s_itr, ++std_s_itr) {
    ASSERT_EQ(*std_s_itr, *s21_s_itr);
  }
}

TEST(MultisetModifiers, TestSwap_1) {
  std::multiset<unsigned, std::greater<unsigned>> std_multiset;
  s21::multiset<unsigned, std::greater<unsigned>> s21_multiset;

  std::multiset<unsigned, std::greater<unsigned>> std_swap;
  s21::multiset<unsigned, std::greater<unsigned>> s21_swap;

  std_multiset.swap(std_swap);
  s21_multiset.swap(s21_swap);

  ASSERT_EQ(std_multiset.size(), s21_multiset.size());
  ASSERT_EQ(std_swap.size(), s21_swap.size());
}

TEST(MultisetModifiers, TestSwap_2) {
  std::multiset<unsigned, std::greater<unsigned>> std_multiset;
  s21::multiset<unsigned, std::greater<unsigned>> s21_multiset;

  std::multiset<unsigned, std::greater<unsigned>> std_swap{
      55, 16, 3, 0, 99, 15, 2, 88, 14, 9, 8, 155, 123, 1, 13};
  s21::multiset<unsigned, std::greater<unsigned>> s21_swap{
      55, 16, 3, 0, 99, 15, 2, 88, 14, 9, 8, 155, 123, 1, 13};

  std_multiset.swap(std_swap);
  s21_multiset.swap(s21_swap);

  ASSERT_EQ(std_multiset.size(), s21_multiset.size());
  ASSERT_EQ(std_swap.size(), s21_swap.size());
  ASSERT_EQ(std_swap.empty(), s21_swap.empty());

  auto std_itr = std_multiset.begin();
  auto s21_itr = s21_multiset.begin();

  for (; s21_itr != s21_multiset.end(); ++s21_itr, ++std_itr) {
    ASSERT_EQ(*std_itr, *s21_itr);
  }
}

TEST(MultisetModifiers, TestSwap_3) {
  std::multiset<unsigned, std::greater<unsigned>> std_multiset{
      55, 16, 3, 0, 99, 15, 2, 88, 14, 9, 8, 155, 123, 1, 13};
  s21::multiset<unsigned, std::greater<unsigned>> s21_multiset{
      55, 16, 3, 0, 99, 15, 2, 88, 14, 9, 8, 155, 123, 1, 13};

  std::multiset<unsigned, std::greater<unsigned>> std_swap{99, 1, 2234312,
                                                           5123512, 11};
  s21::multiset<unsigned, std::greater<unsigned>> s21_swap{99, 1, 2234312,
                                                           5123512, 11};

  std_multiset.swap(std_swap);
  s21_multiset.swap(s21_swap);

  ASSERT_EQ(std_multiset.size(), s21_multiset.size());
  ASSERT_EQ(std_swap.size(), s21_swap.size());

  auto std_itr = std_multiset.begin();
  auto s21_itr = s21_multiset.begin();

  for (; s21_itr != s21_multiset.end(); ++s21_itr, ++std_itr) {
    ASSERT_EQ(*std_itr, *s21_itr);
  }

  auto std_swap_itr = std_swap.begin();
  auto s21_swap_itr = s21_swap.begin();

  for (; s21_swap_itr != s21_swap.end(); ++s21_swap_itr, ++std_swap_itr) {
    ASSERT_EQ(*std_swap_itr, *s21_swap_itr);
  }
}

TEST(MultisetModifiers, TestMerge_1) {
  s21::multiset<int> s21_multiset{1, 2, 3, 4};
  s21::multiset<int> s21_merge{5, 3, 4, 6};
  std::multiset<int> std_multiset{1, 2, 3, 4};
  std::multiset<int> std_merge{5, 3, 4, 6};

  s21_merge.merge(s21_multiset);
  std_merge.merge(std_multiset);

  ASSERT_EQ(s21_merge.size(), std_merge.size());
  ASSERT_EQ(s21_multiset.size(), std_multiset.size());

  auto std_itr = std_merge.begin();
  auto s21_itr = s21_merge.begin();

  for (; s21_itr != s21_merge.end(); ++s21_itr, ++std_itr) {
    ASSERT_EQ(*std_itr, *s21_itr);
  }

  std_itr = std_multiset.begin();
  s21_itr = s21_multiset.begin();

  for (; s21_itr != s21_multiset.end(); ++s21_itr, ++std_itr) {
    ASSERT_EQ(*std_itr, *s21_itr);
  }
}

TEST(MultisetModifiers, TestMerge_2) {
  s21::multiset<int> s21_multiset{5, 3, 4, 6, 1, 2};
  std::multiset<int> std_multiset{5, 3, 4, 6, 1, 2};
  std::multiset<int> std_merge;
  s21::multiset<int> s21_merge;

  std_merge.merge(std_multiset);
  s21_merge.merge(s21_multiset);

  ASSERT_EQ(s21_multiset.size(), std_multiset.size());
  ASSERT_EQ(s21_multiset.empty(), std_multiset.empty());
  ASSERT_EQ(s21_merge.size(), std_merge.size());

  auto std_itr = std_multiset.begin();
  auto s21_itr = s21_multiset.begin();

  ASSERT_TRUE(std_itr == std_multiset.end());
  ASSERT_TRUE(s21_itr == s21_multiset.end());

  std_itr = std_merge.begin();
  s21_itr = s21_merge.begin();

  for (; s21_itr != s21_merge.end(); ++s21_itr, ++std_itr) {
    ASSERT_EQ(*std_itr, *s21_itr);
  }
}

TEST(MultisetModifiers, TestMerge_3) {
  std::multiset<int> std_merge;
  s21::multiset<int> s21_merge;

  std::multiset<int> std_multiset;
  s21::multiset<int> s21_multiset;

  std_merge.merge(std_multiset);
  s21_merge.merge(s21_multiset);

  ASSERT_EQ(s21_merge.size(), std_merge.size());
  ASSERT_EQ(s21_merge.empty(), std_merge.empty());
  ASSERT_EQ(s21_multiset.size(), std_multiset.size());
  ASSERT_EQ(s21_multiset.empty(), std_multiset.empty());
}

TEST(MultisetModifiers, TestMerge_4) {
  s21::multiset<int> s21_merge{5, 3, 4, 6, 1, 2};
  std::multiset<int> std_merge{5, 3, 4, 6, 1, 2};
  std::multiset<int> std_multiset;
  s21::multiset<int> s21_multiset;

  std_merge.merge(std_multiset);
  s21_merge.merge(s21_multiset);

  auto std_itr = std_merge.begin();
  auto s21_itr = s21_merge.begin();

  ASSERT_EQ(s21_merge.size(), std_merge.size());
  ASSERT_EQ(s21_multiset.size(), std_multiset.size());
  ASSERT_EQ(s21_multiset.empty(), std_multiset.empty());

  for (; s21_itr != s21_merge.end(); ++s21_itr, ++std_itr) {
    ASSERT_EQ(*std_itr, *s21_itr);
  }
}

TEST(MultisetModifiers, TestMerge_5) {
  std::multiset<unsigned, std::greater<unsigned>> std_merge{
      55, 16, 3, 0, 99, 15, 2, 88, 14, 9, 8, 155, 123, 1, 13};
  s21::multiset<unsigned, std::greater<unsigned>> s21_merge{
      55, 16, 3, 0, 99, 15, 2, 88, 14, 9, 8, 155, 123, 1, 13};

  std::multiset<unsigned, std::greater<unsigned>> std_multiset{
      1000, 5, 1, 222, 33, 0, 19, 17, 21, 555555, 1, 123, 90, 91};
  s21::multiset<unsigned, std::greater<unsigned>> s21_multiset{
      1000, 5, 1, 222, 33, 0, 19, 17, 21, 555555, 1, 123, 90, 91};

  std_merge.merge(std_multiset);
  s21_merge.merge(s21_multiset);

  ASSERT_EQ(s21_merge.size(), std_merge.size());
  ASSERT_EQ(s21_multiset.size(), std_multiset.size());

  auto std_itr = std_merge.begin();
  auto s21_itr = s21_merge.begin();

  for (; s21_itr != s21_merge.end(); ++s21_itr, ++std_itr) {
    ASSERT_EQ(*std_itr, *s21_itr);
  }

  std_itr = std_multiset.begin();
  s21_itr = s21_multiset.begin();

  for (; s21_itr != s21_multiset.end(); ++s21_itr, ++std_itr) {
    ASSERT_EQ(*std_itr, *s21_itr);
  }
}

TEST(MultisetLookup, TestCount_1) {
  std::multiset<unsigned, std::greater<unsigned>> std_multiset{
      55, 16, 3, 0, 99, 15, 2, 88, 14, 9, 8, 155, 123, 1, 13, 1, 1};
  s21::multiset<unsigned, std::greater<unsigned>> s21_multiset{
      55, 16, 3, 0, 99, 15, 2, 88, 14, 9, 8, 155, 123, 1, 13, 1, 1};

  ASSERT_EQ(std_multiset.count(55), s21_multiset.count(55));
  ASSERT_EQ(std_multiset.count(0), s21_multiset.count(0));
  ASSERT_EQ(std_multiset.count(155), s21_multiset.count(155));
  ASSERT_EQ(std_multiset.count(1), s21_multiset.count(1));
  ASSERT_EQ(std_multiset.count(16), s21_multiset.count(16));
}

TEST(MultisetLookup, TestCount_2) {
  std::multiset<unsigned, std::greater<unsigned>> std_multiset{55, 55, 55, 5,
                                                               1,  5,  55};
  s21::multiset<unsigned, std::greater<unsigned>> s21_multiset{55, 55, 55, 5,
                                                               1,  5,  55};

  ASSERT_EQ(std_multiset.count(55), s21_multiset.count(55));
  ASSERT_EQ(std_multiset.count(1), s21_multiset.count(1));
  ASSERT_EQ(std_multiset.count(5), s21_multiset.count(5));

  s21_multiset.erase(s21_multiset.begin());
  std_multiset.erase(std_multiset.begin());

  ASSERT_EQ(std_multiset.count(55), s21_multiset.count(55));
  ASSERT_EQ(std_multiset.count(1), s21_multiset.count(1));
  ASSERT_EQ(std_multiset.count(5), s21_multiset.count(5));
}

TEST(MultisetLookup, TestCount_3) {
  std::multiset<unsigned, std::greater<unsigned>> std_multiset{55, 55, 55, 5,
                                                               1,  5,  55};
  s21::multiset<unsigned, std::greater<unsigned>> s21_multiset{55, 55, 55, 5,
                                                               1,  5,  55};

  ASSERT_EQ(std_multiset.count(55), s21_multiset.count(55));
  ASSERT_EQ(std_multiset.count(1), s21_multiset.count(1));
  ASSERT_EQ(std_multiset.count(5), s21_multiset.count(5));

  s21_multiset.clear();
  std_multiset.clear();

  ASSERT_EQ(std_multiset.count(55), s21_multiset.count(55));
  ASSERT_EQ(std_multiset.count(1), s21_multiset.count(1));
  ASSERT_EQ(std_multiset.count(5), s21_multiset.count(5));
}

TEST(MultisetLookup, TestCount_4) {
  std::multiset<unsigned, std::greater<unsigned>> std_multiset;
  s21::multiset<unsigned, std::greater<unsigned>> s21_multiset;

  ASSERT_EQ(std_multiset.count(55), s21_multiset.count(55));
  ASSERT_EQ(std_multiset.count(1), s21_multiset.count(1));
  ASSERT_EQ(std_multiset.count(5), s21_multiset.count(5));
}

TEST(MultisetLookup, TestCount_5) {
  std::multiset<unsigned, std::greater<unsigned>> std_multiset;
  s21::multiset<unsigned, std::greater<unsigned>> s21_multiset;

  ASSERT_EQ(std_multiset.count(155), s21_multiset.count(155));
  ASSERT_EQ(std_multiset.count(1), s21_multiset.count(1));
  ASSERT_EQ(std_multiset.count(5), s21_multiset.count(5));

  s21_multiset.insert(155);
  s21_multiset.insert(155);
  s21_multiset.insert(155);
  std_multiset.insert(155);
  std_multiset.insert(155);
  std_multiset.insert(155);

  ASSERT_EQ(std_multiset.count(155), s21_multiset.count(155));
  ASSERT_EQ(std_multiset.count(1), s21_multiset.count(1));
  ASSERT_EQ(std_multiset.count(5), s21_multiset.count(5));
}

TEST(MultisetLookup, TestFind_1) {
  std::multiset<unsigned, std::greater<unsigned>> std_multiset{
      55, 16, 3, 0, 99, 15, 2, 88, 14, 9, 8, 155, 123, 1, 13};
  s21::multiset<unsigned, std::greater<unsigned>> s21_multiset{
      55, 16, 3, 0, 99, 15, 2, 88, 14, 9, 8, 155, 123, 1, 13};

  ASSERT_EQ(*std_multiset.find(55), *s21_multiset.find(55));
  ASSERT_EQ(*std_multiset.find(0), *s21_multiset.find(0));
  ASSERT_EQ(*std_multiset.find(155), *s21_multiset.find(155));
  ASSERT_EQ(*std_multiset.find(16), *s21_multiset.find(16));

  ASSERT_TRUE(std_multiset.find(1001) == std_multiset.end());
  ASSERT_TRUE(s21_multiset.find(1001) == s21_multiset.end());
}

TEST(MultisetLookup, TestFind_2) {
  std::multiset<unsigned, std::greater<unsigned>> std_multiset;
  s21::multiset<unsigned, std::greater<unsigned>> s21_multiset;

  ASSERT_TRUE(std_multiset.find(1) == std_multiset.end());
  ASSERT_TRUE(s21_multiset.find(1) == s21_multiset.end());
}

TEST(MultisetLookup, TestFindConst_1) {
  const std::multiset<unsigned, std::greater<unsigned>> std_multiset{
      55, 16, 3, 0, 99, 15, 2, 88, 14, 9, 8, 155, 123, 1, 13};
  const s21::multiset<unsigned, std::greater<unsigned>> s21_multiset{
      55, 16, 3, 0, 99, 15, 2, 88, 14, 9, 8, 155, 123, 1, 13};

  ASSERT_EQ(*std_multiset.find(55), *s21_multiset.find(55));
  ASSERT_EQ(*std_multiset.find(0), *s21_multiset.find(0));
  ASSERT_EQ(*std_multiset.find(155), *s21_multiset.find(155));
  ASSERT_EQ(*std_multiset.find(16), *s21_multiset.find(16));

  ASSERT_TRUE(std_multiset.find(1001) == std_multiset.end());
  ASSERT_TRUE(s21_multiset.find(1001) == s21_multiset.end());
}

TEST(MultisetLookup, TestFindConst_2) {
  const std::multiset<unsigned, std::greater<unsigned>> std_multiset;
  const s21::multiset<unsigned, std::greater<unsigned>> s21_multiset;

  ASSERT_TRUE(std_multiset.find(1) == std_multiset.end());
  ASSERT_TRUE(s21_multiset.find(1) == s21_multiset.end());
}

TEST(MultisetLookup, TestContains_1) {
  const std::multiset<unsigned, std::greater<unsigned>> std_multiset{
      55, 16, 3, 0, 99, 15, 2, 88, 14, 9, 8, 155, 123, 1, 13};
  const s21::multiset<unsigned, std::greater<unsigned>> s21_multiset{
      55, 16, 3, 0, 99, 15, 2, 88, 14, 9, 8, 155, 123, 1, 13};

  ASSERT_TRUE(*std_multiset.find(55) == 55);
  ASSERT_TRUE(*std_multiset.find(0) == 0);
  ASSERT_TRUE(*std_multiset.find(155) == 155);
  ASSERT_TRUE(*std_multiset.find(16) == 16);

  ASSERT_TRUE(s21_multiset.contains(55));
  ASSERT_TRUE(s21_multiset.contains(0));
  ASSERT_TRUE(s21_multiset.contains(155));
  ASSERT_TRUE(s21_multiset.contains(16));

  ASSERT_TRUE(std_multiset.find(1001) == std_multiset.end());
  ASSERT_TRUE(!s21_multiset.contains(1001));
}

TEST(MultisetLookup, TestContains_2) {
  const std::multiset<unsigned, std::greater<unsigned>> std_multiset;
  const s21::multiset<unsigned, std::greater<unsigned>> s21_multiset;

  ASSERT_TRUE(std_multiset.find(1) == std_multiset.end());
  ASSERT_TRUE(!s21_multiset.contains(1));
}

TEST(MultisetLookup, TestEqualRange_1) {
  std::multiset<int> std_multiset;
  s21::multiset<int> s21_multiset;

  auto std_pair = std_multiset.equal_range(5);
  auto s21_pair = s21_multiset.equal_range(5);

  ASSERT_TRUE(s21_pair.first == s21_multiset.end());
  ASSERT_TRUE(s21_pair.second == s21_multiset.end());
  ASSERT_TRUE(std_pair.first == std_multiset.end());
  ASSERT_TRUE(std_pair.second == std_multiset.end());
}

TEST(MultisetLookup, TestEqualRange_2) {
  std::multiset<int> std_multiset{5};
  s21::multiset<int> s21_multiset{5};

  auto std_pair = std_multiset.equal_range(5);
  auto s21_pair = s21_multiset.equal_range(5);

  ASSERT_TRUE(*s21_pair.first == *std_pair.first);
  ASSERT_TRUE(s21_pair.second == s21_multiset.end());
  ASSERT_TRUE(std_pair.second == std_multiset.end());
}

TEST(MultisetLookup, TestEqualRange_3) {
  const std::multiset<int> std_multiset{55, 16, 3, 0,   99,  15, 2, 88,
                                        14, 9,  8, 155, 123, 1,  13};
  const s21::multiset<int> s21_multiset{55, 16, 3, 0,   99,  15, 2, 88,
                                        14, 9,  8, 155, 123, 1,  13};

  auto std_pair = std_multiset.equal_range(17);
  auto s21_pair = s21_multiset.equal_range(17);

  ASSERT_TRUE(*s21_pair.first == *std_pair.first);
  ASSERT_TRUE(*std_pair.second == *s21_pair.second);
}

TEST(MultisetLookup, TestEqualRange_4) {
  std::multiset<int> std_multiset{55, 16, 3,   0,  99,  15, 2,  88, 14,
                                  9,  8,  155, 16, 123, 1,  13, 16};
  s21::multiset<int> s21_multiset{55, 16, 3,   0,  99,  15, 2,  88, 14,
                                  9,  8,  155, 16, 123, 1,  13, 16};

  auto std_pair = std_multiset.equal_range(16);
  auto s21_pair = s21_multiset.equal_range(16);

  auto std_itr = std_pair.first;
  auto s21_itr = s21_pair.first;

  for (; s21_itr != s21_pair.second; ++std_itr, ++s21_itr) {
    ASSERT_EQ(*std_itr, *s21_itr);
  }
  ASSERT_TRUE(*std_pair.second == *s21_pair.second);
}

TEST(MultisetLookup, TestEqualRange_5) {
  std::multiset<int> std_multiset{55, 16, 3,   0,  99,  15, 2,  88, 14,
                                  9,  8,  155, 16, 123, 1,  13, 16, 155};
  s21::multiset<int> s21_multiset{55, 16, 3,   0,  99,  15, 2,  88, 14,
                                  9,  8,  155, 16, 123, 1,  13, 16, 155};

  auto std_pair = std_multiset.equal_range(155);
  auto s21_pair = s21_multiset.equal_range(155);

  auto std_itr = std_pair.first;
  auto s21_itr = s21_pair.first;

  for (; s21_itr != s21_pair.second; ++std_itr, ++s21_itr) {
    ASSERT_EQ(*std_itr, *s21_itr);
  }
  ASSERT_TRUE(s21_pair.second == s21_multiset.end());
  ASSERT_TRUE(std_pair.second == std_multiset.end());
}

TEST(MultisetLookup, TestLowerBound_1) {
  std::multiset<int> std_multiset{55, 16, 3,   0,  99,  15, 2,  88, 14,
                                  9,  8,  155, 16, 123, 1,  13, 16, 155};
  s21::multiset<int> s21_multiset{55, 16, 3,   0,  99,  15, 2,  88, 14,
                                  9,  8,  155, 16, 123, 1,  13, 16, 155};

  auto std_itr = std_multiset.lower_bound(155);
  auto s21_itr = s21_multiset.lower_bound(155);

  for (; s21_itr != s21_multiset.end(); ++std_itr, ++s21_itr) {
    ASSERT_EQ(*std_itr, *s21_itr);
  }
}

TEST(MultisetLookup, TestLowerBound_2) {
  const std::multiset<int> std_multiset{
      55, 16, 3, 0, 99, 15, 2, 88, 14, 9, 8, 155, 16, 123, 1, 13, 16, 155, 0};
  const s21::multiset<int> s21_multiset{
      55, 16, 3, 0, 99, 15, 2, 88, 14, 9, 8, 155, 16, 123, 1, 13, 16, 155, 0};

  auto std_itr = std_multiset.lower_bound(16);
  auto s21_itr = s21_multiset.lower_bound(16);

  for (; s21_itr != s21_multiset.end(); ++std_itr, ++s21_itr) {
    ASSERT_EQ(*std_itr, *s21_itr);
  }
}

TEST(MultisetLookup, TestLowerBound_3) {
  std::multiset<int, std::greater<int>> std_multiset{
      55, 16, 3, 0, 99, 15, 2, 88, 14, 9, 8, 155, 16, 123, 1, 13, 16, 155, 17};
  s21::multiset<int, std::greater<int>> s21_multiset{
      55, 16, 3, 0, 99, 15, 2, 88, 14, 9, 8, 155, 16, 123, 1, 13, 16, 155, 17};

  auto std_itr = std_multiset.lower_bound(19);
  auto s21_itr = s21_multiset.lower_bound(19);

  for (; s21_itr != s21_multiset.end(); ++std_itr, ++s21_itr) {
    ASSERT_EQ(*std_itr, *s21_itr);
  }
}

TEST(MultisetLookup, TestLowerBound_4) {
  std::multiset<int> std_multiset;
  s21::multiset<int> s21_multiset;

  auto std_itr = std_multiset.lower_bound(19);
  auto s21_itr = s21_multiset.lower_bound(19);

  ASSERT_EQ(s21_itr == s21_multiset.end(), std_itr == std_multiset.end());
}

TEST(MultisetLookup, TestUpperBound_1) {
  std::multiset<int> std_multiset{55, 16, 3,   0,  99,  15, 2,  88, 14,
                                  9,  8,  155, 16, 123, 1,  13, 16, 155};
  s21::multiset<int> s21_multiset{55, 16, 3,   0,  99,  15, 2,  88, 14,
                                  9,  8,  155, 16, 123, 1,  13, 16, 155};

  auto std_itr = std_multiset.upper_bound(155);
  auto s21_itr = s21_multiset.upper_bound(155);

  for (; s21_itr != s21_multiset.end(); ++std_itr, ++s21_itr) {
    ASSERT_EQ(*std_itr, *s21_itr);
  }
}

TEST(MultisetLookup, TestUpperBound_2) {
  const std::multiset<int> std_multiset{
      55, 16, 3, 0, 99, 15, 2, 88, 14, 9, 8, 155, 16, 123, 1, 13, 16, 155, 0};
  const s21::multiset<int> s21_multiset{
      55, 16, 3, 0, 99, 15, 2, 88, 14, 9, 8, 155, 16, 123, 1, 13, 16, 155, 0};

  auto std_itr = std_multiset.upper_bound(16);
  auto s21_itr = s21_multiset.upper_bound(16);

  for (; s21_itr != s21_multiset.end(); ++std_itr, ++s21_itr) {
    ASSERT_EQ(*std_itr, *s21_itr);
  }
}

TEST(MultisetLookup, TestUpperBound_3) {
  std::multiset<int, std::greater<int>> std_multiset{
      55, 16, 3, 0, 99, 15, 2, 88, 14, 9, 8, 155, 16, 123, 1, 13, 16, 155, 17};
  s21::multiset<int, std::greater<int>> s21_multiset{
      55, 16, 3, 0, 99, 15, 2, 88, 14, 9, 8, 155, 16, 123, 1, 13, 16, 155, 17};

  auto std_itr = std_multiset.upper_bound(19);
  auto s21_itr = s21_multiset.upper_bound(19);

  for (; s21_itr != s21_multiset.end(); ++std_itr, ++s21_itr) {
    ASSERT_EQ(*std_itr, *s21_itr);
  }
}

TEST(MultisetLookup, TestUpperBound_4) {
  std::multiset<int> std_multiset;
  s21::multiset<int> s21_multiset;

  auto std_itr = std_multiset.upper_bound(19);
  auto s21_itr = s21_multiset.upper_bound(19);

  ASSERT_EQ(s21_itr == s21_multiset.end(), std_itr == std_multiset.end());
}

TEST(MultisetInsertMany, TestInsertMany_1) {
  std::multiset<int> std_multiset{55, 16, 3, 0,   99,  15, 2, 88,
                                  14, 9,  8, 155, 123, 1,  13};
  s21::multiset<int> s21_multiset{55, 16, 3, 0,   99,  15, 2, 88,
                                  14, 9,  8, 155, 123, 1,  13};

  std::vector<std::multiset<int>::iterator> std_vector;
  s21::vector<s21::multiset<int>::iterator> s21_vector;
  std_vector.push_back(std_multiset.insert(1001));
  std_vector.push_back(std_multiset.insert(55));
  std_vector.push_back(std_multiset.insert(600));
  std_vector.push_back(std_multiset.insert(-14));
  std_vector.push_back(std_multiset.insert(10));
  std_vector.push_back(std_multiset.insert(9));
  std_vector.push_back(std_multiset.insert(8));
  std_vector.push_back(std_multiset.insert(999));
  std_vector.push_back(std_multiset.insert(55));
  std_vector.push_back(std_multiset.insert(55));

  s21_vector =
      s21_multiset.insert_many(1001, 55, 600, -14, 10, 9, 8, 999, 55, 55);
  ASSERT_EQ(s21_multiset.size(), std_multiset.size());
  auto s21_itr = s21_multiset.begin();
  auto std_itr = std_multiset.begin();

  for (; s21_itr != s21_multiset.end(); ++s21_itr, ++std_itr) {
    ASSERT_EQ(*s21_itr, *std_itr);
  }
}

TEST(MultisetInsertMany, TestInsertMany_2) {
  std::multiset<unsigned, std::greater<unsigned>> std_multiset{
      1, 2, 3, 4, 5, 5, 6, 6, 10, 9, 100};
  s21::multiset<unsigned, std::greater<unsigned>> s21_multiset;
  s21_multiset.insert_many(1, 2, 3, 4, 5, 5, 6, 6, 10, 9, 100);

  ASSERT_TRUE(std_multiset.size() == std_multiset.size());

  auto s21_s_itr = s21_multiset.begin();
  auto std_s_itr = std_multiset.begin();

  for (; s21_s_itr != s21_multiset.end(); ++s21_s_itr, ++std_s_itr) {
    ASSERT_EQ(*s21_s_itr, *std_s_itr);
  }
}