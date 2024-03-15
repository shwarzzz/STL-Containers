#include <gtest/gtest.h>

#include <iostream>
#include <set>
#include <vector>

#include "../s21_containers.h"

TEST(SetMemberFunctions, TestDefault) {
  std::set<int> std_set;
  s21::set<int> s21_set;

  ASSERT_EQ(std_set.size(), s21_set.size());
}

TEST(SetMemberFunctions, TestInitializerList) {
  std::set<int> std_set{1, 5, 2, 3};
  s21::set<int> s21_set{1, 5, 2, 3};
  ASSERT_EQ(std_set.size(), s21_set.size());

  std::set<int>::iterator std_itr(std_set.begin());
  s21::set<int>::iterator s21_itr(s21_set.begin());
  for (size_t i = 0; i < s21_set.size(); ++i) {
    ASSERT_EQ(*std_itr, *s21_itr);
    ++std_itr;
    ++s21_itr;
  }
}

TEST(SetMemberFunctions, TestCopy) {
  std::set<char, std::greater<char>> std_set{'e', 'a', 'h', 'r', 'e'};
  s21::set<char, std::greater<char>> s21_set{'e', 'a', 'h', 'r', 'e'};
  ASSERT_EQ(std_set.size(), s21_set.size());

  std::set<char, std::greater<char>> std_copy(std_set);
  s21::set<char, std::greater<char>> s21_copy(s21_set);
  ASSERT_EQ(std_copy.size(), s21_copy.size());

  std::set<char, std::greater<char>>::iterator std_itr(std_copy.begin());
  s21::set<char, std::greater<char>>::iterator s21_itr(s21_copy.begin());
  for (size_t i = 0; i < s21_copy.size(); ++i) {
    ASSERT_EQ(*std_itr, *s21_itr);
    ++std_itr;
    ++s21_itr;
  }
}

TEST(SetMemberFunctions, TestMove) {
  std::set<char, std::greater<char>> std_set{'a', 'b', 'c', 'd', 'e'};
  s21::set<char, std::greater<char>> s21_set{'a', 'b', 'c', 'd', 'e'};
  ASSERT_EQ(std_set.size(), s21_set.size());

  std::set<char, std::greater<char>> std_move(std::move(std_set));
  s21::set<char, std::greater<char>> s21_move(std::move(s21_set));
  ASSERT_EQ(std_move.size(), s21_move.size());

  std::set<char, std::greater<char>>::iterator std_itr(std_move.begin());
  s21::set<char, std::greater<char>>::iterator s21_itr(s21_move.begin());
  for (size_t i = 0; i < s21_move.size(); ++i) {
    ASSERT_EQ(*std_itr, *s21_itr);
    ++std_itr;
    ++s21_itr;
  }
}

TEST(SetMemberFunctions, TestDestructor_1) {
  std::set<char, std::greater<char>>* std_set =
      new std::set<char, std::greater<char>>();
  s21::set<char, std::greater<char>>* s21_set =
      new s21::set<char, std::greater<char>>();

  delete std_set;
  delete s21_set;
}

TEST(SetMemberFunctions, TestDestructor_2) {
  std::set<char, std::greater<char>>* std_set =
      new std::set<char, std::greater<char>>{'a', 'b', 'c', 'd', 'e'};
  s21::set<char, std::greater<char>>* s21_set =
      new s21::set<char, std::greater<char>>{'a', 'b', 'c', 'd', 'e'};

  delete std_set;
  delete s21_set;
}

TEST(SetMemberFunctions, TestMoveOperator) {
  std::set<char, std::greater<char>> std_set{'a', 'b', 'c', 'd', 'e'};
  s21::set<char, std::greater<char>> s21_set{'a', 'b', 'c', 'd', 'e'};
  ASSERT_EQ(std_set.size(), s21_set.size());

  std::set<char, std::greater<char>> std_move{'f', 'a', 'e', '1',
                                              '2', '.', 'l'};
  s21::set<char, std::greater<char>> s21_move{'f', 'a', 'e', '1',
                                              '2', '.', 'l'};

  std_move = std::move(std_set);
  s21_move = std::move(s21_set);
  ASSERT_EQ(std_move.size(), s21_move.size());

  std::set<char, std::greater<char>>::iterator std_itr(std_move.begin());
  s21::set<char, std::greater<char>>::iterator s21_itr(s21_move.begin());
  for (size_t i = 0; i < s21_move.size(); ++i) {
    ASSERT_EQ(*std_itr, *s21_itr);
    ++std_itr;
    ++s21_itr;
  }
}

TEST(SetMemberFunctions, TestCopyOperator) {
  std::set<char, std::greater<char>> std_set{'e', 'a', 'h', 'r', 'e'};
  s21::set<char, std::greater<char>> s21_set{'e', 'a', 'h', 'r', 'e'};
  ASSERT_EQ(std_set.size(), s21_set.size());

  std::set<char, std::greater<char>> std_copy;
  s21::set<char, std::greater<char>> s21_copy;

  std_copy = std_set;
  s21_copy = s21_set;
  ASSERT_EQ(std_copy.size(), s21_copy.size());

  std::set<char, std::greater<char>>::iterator std_itr(std_copy.begin());
  s21::set<char, std::greater<char>>::iterator s21_itr(s21_copy.begin());
  for (size_t i = 0; i < s21_copy.size(); ++i) {
    ASSERT_EQ(*std_itr, *s21_itr);
    ++std_itr;
    ++s21_itr;
  }
}

TEST(SetIterators, TestBeginEnd) {
  std::set<unsigned> std_set{55, 16, 3, 0,   99,  15, 2, 88,
                             14, 9,  8, 155, 123, 1,  13};
  s21::set<unsigned> s21_set{55, 16, 3, 0,   99,  15, 2, 88,
                             14, 9,  8, 155, 123, 1,  13};
  ASSERT_EQ(std_set.size(), s21_set.size());

  std::set<unsigned>::iterator std_itr;
  std_itr = std_set.begin();
  s21::set<unsigned>::iterator s21_itr;
  s21_itr = s21_set.begin();
  for (; s21_itr != s21_set.end() && std_itr != std_set.end();
       ++std_itr, ++s21_itr) {
    ASSERT_EQ(*std_itr, *s21_itr);
  }
  --std_itr;
  --s21_itr;
  for (; s21_itr != s21_set.begin() && std_itr != std_set.begin();
       --std_itr, --s21_itr) {
    ASSERT_EQ(*std_itr, *s21_itr);
  }

  s21::set<unsigned>::iterator s21_end(s21_set.end());
  ++s21_end;
  ASSERT_TRUE(s21_end == s21_set.begin());
  --s21_end;
  ASSERT_TRUE(s21_end == s21_set.end());
}

TEST(SetIterators, TestConstBeginEnd) {
  const std::set<unsigned> std_set{55, 16, 3, 0,   99,  15, 2, 88,
                                   14, 9,  8, 155, 123, 1,  13};
  const s21::set<unsigned> s21_set{55, 16, 3, 0,   99,  15, 2, 88,
                                   14, 9,  8, 155, 123, 1,  13};
  ASSERT_EQ(std_set.size(), s21_set.size());

  std::set<unsigned>::const_iterator std_itr;
  std_itr = std_set.begin();
  s21::set<unsigned>::const_iterator s21_itr;
  s21_itr = s21_set.begin();
  for (; s21_itr != s21_set.end() && std_itr != std_set.end();
       ++std_itr, ++s21_itr) {
    ASSERT_EQ(*std_itr, *s21_itr);
  }
  --std_itr;
  --s21_itr;
  for (; s21_itr != s21_set.begin() && std_itr != std_set.begin();
       --std_itr, --s21_itr) {
    ASSERT_EQ(*std_itr, *s21_itr);
  }

  s21::set<unsigned>::const_iterator s21_end(s21_set.end());
  ++s21_end;
  ASSERT_TRUE(s21_end == s21_set.begin());
  --s21_end;
  ASSERT_TRUE(s21_end == s21_set.end());
}

TEST(SetCapacity, TestSizeAndEmpty_1) {
  std::set<unsigned> std_set{55, 16, 3, 0,   99,  15, 2, 88,
                             14, 9,  8, 155, 123, 1,  13};
  s21::set<unsigned> s21_set{55, 16, 3, 0,   99,  15, 2, 88,
                             14, 9,  8, 155, 123, 1,  13};
  ASSERT_EQ(std_set.empty(), s21_set.empty());
  ASSERT_EQ(std_set.size(), s21_set.size());

  std_set.clear();
  s21_set.clear();

  ASSERT_EQ(std_set.empty(), s21_set.empty());
  ASSERT_EQ(std_set.size(), s21_set.size());
}

TEST(SetCapacity, TestSizeAndEmpty_2) {
  std::set<int> std_set;
  s21::set<int> s21_set;

  ASSERT_EQ(std_set.empty(), s21_set.empty());
  ASSERT_EQ(std_set.size(), s21_set.size());

  std_set.insert(1);
  s21_set.insert(1);

  ASSERT_EQ(std_set.empty(), s21_set.empty());
  ASSERT_EQ(std_set.size(), s21_set.size());
}

TEST(SetCapacity, TestMaxSize_1) {
  std::set<unsigned> std_set;
  s21::set<unsigned> s21_set;
  ASSERT_NE(std_set.max_size(), s21_set.max_size());
}

TEST(SetCapacity, TestMaxSize_2) {
  s21::set<std::string, std::greater_equal<std::string>> s21_set;
  std::set<std::string, std::greater_equal<std::string>> std_set;
  ASSERT_NE(std_set.max_size(), s21_set.max_size());
}

TEST(SetModifiers, TestClear_1) {
  std::set<unsigned, std::greater<unsigned>> std_set{
      55, 16, 3, 0, 99, 15, 2, 88, 14, 9, 8, 155, 123, 1, 13};
  s21::set<unsigned, std::greater<unsigned>> s21_set{
      55, 16, 3, 0, 99, 15, 2, 88, 14, 9, 8, 155, 123, 1, 13};
  ASSERT_EQ(std_set.empty(), s21_set.empty());
  ASSERT_EQ(std_set.size(), s21_set.size());

  std_set.clear();
  s21_set.clear();

  ASSERT_EQ(std_set.empty(), s21_set.empty());
  ASSERT_EQ(std_set.size(), s21_set.size());
}

TEST(SetModifiers, TestClear_2) {
  std::set<int> std_set;
  s21::set<int> s21_set;

  std_set.clear();
  s21_set.clear();

  ASSERT_EQ(std_set.empty(), s21_set.empty());
  ASSERT_EQ(std_set.size(), s21_set.size());

  std_set.insert(1);
  s21_set.insert(1);

  std_set.clear();
  s21_set.clear();

  ASSERT_EQ(std_set.empty(), s21_set.empty());
  ASSERT_EQ(std_set.size(), s21_set.size());
}

TEST(SetModifiers, TestInsert_1) {
  std::set<unsigned, std::greater<unsigned>> std_set{
      55, 16, 3, 0, 99, 15, 2, 88, 14, 9, 8, 155, 123, 1, 13};
  s21::set<unsigned, std::greater<unsigned>> s21_set{
      55, 16, 3, 0, 99, 15, 2, 88, 14, 9, 8, 155, 123, 1, 13};

  auto std_pair = std_set.insert(1000);
  auto s21_pair = s21_set.insert(1000);

  ASSERT_EQ(std_pair.second, s21_pair.second);
  ASSERT_EQ(*std_pair.first, *s21_pair.first);

  std_pair = std_set.insert(1000);
  s21_pair = s21_set.insert(1000);

  ASSERT_EQ(std_pair.second, s21_pair.second);
  ASSERT_EQ(*std_pair.first, *s21_pair.first);
  ASSERT_EQ(std_set.size(), s21_set.size());
}

TEST(SetModifiers, TestInsert_2) {
  std::set<int> std_set;
  s21::set<int> s21_set;

  auto std_pair = std_set.insert(1);
  auto s21_pair = s21_set.insert(1);
  ASSERT_EQ(std_pair.second, s21_pair.second);
  ASSERT_EQ(*std_pair.first, *s21_pair.first);
  ASSERT_EQ(std_set.size(), s21_set.size());
}

TEST(SetModifiers, TestErase_1) {
  std::set<unsigned, std::greater<unsigned>> std_set{
      55, 16, 3, 0, 99, 15, 2, 88, 14, 9, 8, 155, 123, 1, 13};
  s21::set<unsigned, std::greater<unsigned>> s21_set{
      55, 16, 3, 0, 99, 15, 2, 88, 14, 9, 8, 155, 123, 1, 13};

  std_set.erase(std_set.begin());
  s21_set.erase(s21_set.begin());

  auto std_itr = std_set.begin();
  auto s21_itr = s21_set.begin();

  ++std_itr;
  ++s21_itr;

  std_set.erase(std_itr);
  s21_set.erase(s21_itr);

  ASSERT_EQ(std_set.size(), s21_set.size());

  std_itr = std_set.begin();
  s21_itr = s21_set.begin();

  for (; s21_itr != s21_set.end(); ++s21_itr, ++std_itr) {
    ASSERT_EQ(*std_itr, *s21_itr);
  }
}

TEST(SetModifiers, TestErase_2) {
  std::set<std::string> std_set{"2", "1", "3"};
  s21::set<std::string> s21_set{"2", "1", "3"};

  std_set.erase(++(std_set.begin()));
  s21_set.erase(++(s21_set.begin()));

  auto std_s_itr = std_set.begin();
  auto s21_s_itr = s21_set.begin();
  ASSERT_EQ(std_set.size(), s21_set.size());
  for (; s21_s_itr != s21_set.end(); ++s21_s_itr, ++std_s_itr) {
    ASSERT_EQ(*std_s_itr, *s21_s_itr);
  }

  std_set.erase(std_set.begin());
  s21_set.erase(s21_set.begin());

  std_s_itr = std_set.begin();
  s21_s_itr = s21_set.begin();
  ASSERT_EQ(std_set.size(), s21_set.size());
  for (; s21_s_itr != s21_set.end(); ++s21_s_itr, ++std_s_itr) {
    ASSERT_EQ(*std_s_itr, *s21_s_itr);
  }
}

TEST(SetModifiers, TestSwap_1) {
  std::set<unsigned, std::greater<unsigned>> std_set;
  s21::set<unsigned, std::greater<unsigned>> s21_set;

  std::set<unsigned, std::greater<unsigned>> std_swap;
  s21::set<unsigned, std::greater<unsigned>> s21_swap;

  std_set.swap(std_swap);
  s21_set.swap(s21_swap);

  ASSERT_EQ(std_set.size(), s21_set.size());
  ASSERT_EQ(std_swap.size(), s21_swap.size());
}

TEST(SetModifiers, TestSwap_2) {
  std::set<unsigned, std::greater<unsigned>> std_set;
  s21::set<unsigned, std::greater<unsigned>> s21_set;

  std::set<unsigned, std::greater<unsigned>> std_swap{
      55, 16, 3, 0, 99, 15, 2, 88, 14, 9, 8, 155, 123, 1, 13};
  s21::set<unsigned, std::greater<unsigned>> s21_swap{
      55, 16, 3, 0, 99, 15, 2, 88, 14, 9, 8, 155, 123, 1, 13};

  std_set.swap(std_swap);
  s21_set.swap(s21_swap);

  ASSERT_EQ(std_set.size(), s21_set.size());
  ASSERT_EQ(std_swap.size(), s21_swap.size());
  ASSERT_EQ(std_swap.empty(), s21_swap.empty());

  auto std_itr = std_set.begin();
  auto s21_itr = s21_set.begin();

  for (; s21_itr != s21_set.end(); ++s21_itr, ++std_itr) {
    ASSERT_EQ(*std_itr, *s21_itr);
  }
}

TEST(SetModifiers, TestSwap_3) {
  std::set<unsigned, std::greater<unsigned>> std_set{
      55, 16, 3, 0, 99, 15, 2, 88, 14, 9, 8, 155, 123, 1, 13};
  s21::set<unsigned, std::greater<unsigned>> s21_set{
      55, 16, 3, 0, 99, 15, 2, 88, 14, 9, 8, 155, 123, 1, 13};

  std::set<unsigned, std::greater<unsigned>> std_swap{99, 1, 2234312, 5123512,
                                                      11};
  s21::set<unsigned, std::greater<unsigned>> s21_swap{99, 1, 2234312, 5123512,
                                                      11};

  std_set.swap(std_swap);
  s21_set.swap(s21_swap);

  ASSERT_EQ(std_set.size(), s21_set.size());
  ASSERT_EQ(std_swap.size(), s21_swap.size());

  auto std_itr = std_set.begin();
  auto s21_itr = s21_set.begin();

  for (; s21_itr != s21_set.end(); ++s21_itr, ++std_itr) {
    ASSERT_EQ(*std_itr, *s21_itr);
  }

  auto std_swap_itr = std_swap.begin();
  auto s21_swap_itr = s21_swap.begin();

  for (; s21_swap_itr != s21_swap.end(); ++s21_swap_itr, ++std_swap_itr) {
    ASSERT_EQ(*std_swap_itr, *s21_swap_itr);
  }
}

TEST(SetModifiers, TestMerge_1) {
  s21::set<int> s21_set{1, 2, 3, 4};
  s21::set<int> s21_merge{5, 3, 4, 6};
  std::set<int> std_set{1, 2, 3, 4};
  std::set<int> std_merge{5, 3, 4, 6};

  s21_merge.merge(s21_set);
  std_merge.merge(std_set);

  ASSERT_EQ(s21_merge.size(), std_merge.size());
  ASSERT_EQ(s21_set.size(), std_set.size());

  auto std_itr = std_merge.begin();
  auto s21_itr = s21_merge.begin();

  for (; s21_itr != s21_merge.end(); ++s21_itr, ++std_itr) {
    ASSERT_EQ(*std_itr, *s21_itr);
  }

  std_itr = std_set.begin();
  s21_itr = s21_set.begin();

  for (; s21_itr != s21_set.end(); ++s21_itr, ++std_itr) {
    ASSERT_EQ(*std_itr, *s21_itr);
  }
}

TEST(SetModifiers, TestMerge_2) {
  s21::set<int> s21_set{5, 3, 4, 6, 1, 2};
  std::set<int> std_set{5, 3, 4, 6, 1, 2};
  std::set<int> std_merge;
  s21::set<int> s21_merge;

  std_merge.merge(std_set);
  s21_merge.merge(s21_set);

  ASSERT_EQ(s21_set.size(), std_set.size());
  ASSERT_EQ(s21_set.empty(), std_set.empty());
  ASSERT_EQ(s21_merge.size(), std_merge.size());

  auto std_itr = std_set.begin();
  auto s21_itr = s21_set.begin();

  ASSERT_TRUE(std_itr == std_set.end());
  ASSERT_TRUE(s21_itr == s21_set.end());

  std_itr = std_merge.begin();
  s21_itr = s21_merge.begin();

  for (; s21_itr != s21_merge.end(); ++s21_itr, ++std_itr) {
    ASSERT_EQ(*std_itr, *s21_itr);
  }
}

TEST(SetModifiers, TestMerge_3) {
  std::set<int> std_merge;
  s21::set<int> s21_merge;

  std::set<int> std_set;
  s21::set<int> s21_set;

  std_merge.merge(std_set);
  s21_merge.merge(s21_set);

  ASSERT_EQ(s21_merge.size(), std_merge.size());
  ASSERT_EQ(s21_merge.empty(), std_merge.empty());
  ASSERT_EQ(s21_set.size(), std_set.size());
  ASSERT_EQ(s21_set.empty(), std_set.empty());
}

TEST(SetModifiers, TestMerge_4) {
  s21::set<int> s21_merge{5, 3, 4, 6, 1, 2};
  std::set<int> std_merge{5, 3, 4, 6, 1, 2};
  std::set<int> std_set;
  s21::set<int> s21_set;

  std_merge.merge(std_set);
  s21_merge.merge(s21_set);

  auto std_itr = std_merge.begin();
  auto s21_itr = s21_merge.begin();

  ASSERT_EQ(s21_merge.size(), std_merge.size());
  ASSERT_EQ(s21_set.size(), std_set.size());
  ASSERT_EQ(s21_set.empty(), std_set.empty());

  for (; s21_itr != s21_merge.end(); ++s21_itr, ++std_itr) {
    ASSERT_EQ(*std_itr, *s21_itr);
  }
}

TEST(SetModifiers, TestMerge_5) {
  std::set<unsigned, std::greater<unsigned>> std_merge{
      55, 16, 3, 0, 99, 15, 2, 88, 14, 9, 8, 155, 123, 1, 13};
  s21::set<unsigned, std::greater<unsigned>> s21_merge{
      55, 16, 3, 0, 99, 15, 2, 88, 14, 9, 8, 155, 123, 1, 13};

  std::set<unsigned, std::greater<unsigned>> std_set{
      1000, 5, 1, 222, 33, 0, 19, 17, 21, 555555, 1, 123, 90, 91};
  s21::set<unsigned, std::greater<unsigned>> s21_set{
      1000, 5, 1, 222, 33, 0, 19, 17, 21, 555555, 1, 123, 90, 91};

  std_merge.merge(std_set);
  s21_merge.merge(s21_set);

  ASSERT_EQ(s21_merge.size(), std_merge.size());
  ASSERT_EQ(s21_set.size(), std_set.size());

  auto std_t_itr = std_merge.begin();
  auto s21_t_itr = s21_merge.begin();

  for (; s21_t_itr != s21_merge.end(); ++s21_t_itr, ++std_t_itr) {
    ASSERT_EQ(*std_t_itr, *s21_t_itr);
  }

  auto std_f_itr = std_set.begin();
  auto s21_f_itr = s21_set.begin();

  for (; s21_f_itr != s21_set.end(); ++s21_f_itr, ++std_f_itr) {
    ASSERT_EQ(*std_f_itr, *s21_f_itr);
  }
}

TEST(SetLookup, TestFind_1) {
  std::set<unsigned, std::greater<unsigned>> std_set{
      55, 16, 3, 0, 99, 15, 2, 88, 14, 9, 8, 155, 123, 1, 13};
  s21::set<unsigned, std::greater<unsigned>> s21_set{
      55, 16, 3, 0, 99, 15, 2, 88, 14, 9, 8, 155, 123, 1, 13};

  ASSERT_EQ(*std_set.find(55), *s21_set.find(55));
  ASSERT_EQ(*std_set.find(0), *s21_set.find(0));
  ASSERT_EQ(*std_set.find(155), *s21_set.find(155));
  ASSERT_EQ(*std_set.find(16), *s21_set.find(16));

  ASSERT_TRUE(std_set.find(1001) == std_set.end());
  ASSERT_TRUE(s21_set.find(1001) == s21_set.end());
}

TEST(SetLookup, TestFind_2) {
  std::set<unsigned, std::greater<unsigned>> std_set;
  s21::set<unsigned, std::greater<unsigned>> s21_set;

  ASSERT_TRUE(std_set.find(1) == std_set.end());
  ASSERT_TRUE(s21_set.find(1) == s21_set.end());
}

TEST(SetLookup, TestFindConst_1) {
  const std::set<unsigned, std::greater<unsigned>> std_set{
      55, 16, 3, 0, 99, 15, 2, 88, 14, 9, 8, 155, 123, 1, 13};
  const s21::set<unsigned, std::greater<unsigned>> s21_set{
      55, 16, 3, 0, 99, 15, 2, 88, 14, 9, 8, 155, 123, 1, 13};

  ASSERT_EQ(*std_set.find(55), *s21_set.find(55));
  ASSERT_EQ(*std_set.find(0), *s21_set.find(0));
  ASSERT_EQ(*std_set.find(155), *s21_set.find(155));
  ASSERT_EQ(*std_set.find(16), *s21_set.find(16));

  ASSERT_TRUE(std_set.find(1001) == std_set.end());
  ASSERT_TRUE(s21_set.find(1001) == s21_set.end());
}

TEST(SetLookup, TestFindConst_2) {
  const std::set<unsigned, std::greater<unsigned>> std_set;
  const s21::set<unsigned, std::greater<unsigned>> s21_set;

  ASSERT_TRUE(std_set.find(1) == std_set.end());
  ASSERT_TRUE(s21_set.find(1) == s21_set.end());
}

TEST(SetLookup, TestContains_1) {
  const std::set<unsigned, std::greater<unsigned>> std_set{
      55, 16, 3, 0, 99, 15, 2, 88, 14, 9, 8, 155, 123, 1, 13};
  const s21::set<unsigned, std::greater<unsigned>> s21_set{
      55, 16, 3, 0, 99, 15, 2, 88, 14, 9, 8, 155, 123, 1, 13};

  ASSERT_TRUE(*std_set.find(55) == 55);
  ASSERT_TRUE(*std_set.find(0) == 0);
  ASSERT_TRUE(*std_set.find(155) == 155);
  ASSERT_TRUE(*std_set.find(16) == 16);

  ASSERT_TRUE(s21_set.contains(55));
  ASSERT_TRUE(s21_set.contains(0));
  ASSERT_TRUE(s21_set.contains(155));
  ASSERT_TRUE(s21_set.contains(16));

  ASSERT_TRUE(std_set.find(1001) == std_set.end());
  ASSERT_TRUE(!s21_set.contains(1001));
}

TEST(SetLookup, TestContains_2) {
  const std::set<unsigned, std::greater<unsigned>> std_set;
  const s21::set<unsigned, std::greater<unsigned>> s21_set;

  ASSERT_TRUE(std_set.find(1) == std_set.end());
  ASSERT_TRUE(!s21_set.contains(1));
}

TEST(SetInsertMany, TestInsertMany_1) {
  std::set<int> std_set{55, 16, 3, 0, 99, 15, 2, 88, 14, 9, 8, 155, 123, 1, 13};
  s21::set<int> s21_set{55, 16, 3, 0, 99, 15, 2, 88, 14, 9, 8, 155, 123, 1, 13};

  std::vector<std::pair<std::set<int>::iterator, bool>> std_vector;
  s21::vector<std::pair<s21::set<int>::iterator, bool>> s21_vector;
  std_vector.push_back(std_set.insert(1001));
  std_vector.push_back(std_set.insert(55));
  std_vector.push_back(std_set.insert(600));
  std_vector.push_back(std_set.insert(-14));
  std_vector.push_back(std_set.insert(10));
  std_vector.push_back(std_set.insert(9));
  std_vector.push_back(std_set.insert(8));
  std_vector.push_back(std_set.insert(999));

  s21_vector = s21_set.insert_many(1001, 55, 600, -14, 10, 9, 8, 999);

  ASSERT_EQ(s21_set.size(), std_set.size());

  for (size_t i = 0; i < s21_vector.size(); ++i) {
    ASSERT_EQ(s21_vector[i].second, std_vector[i].second);
  }

  auto s21_itr = s21_set.begin();
  auto std_itr = std_set.begin();

  for (; s21_itr != s21_set.end(); ++s21_itr, ++std_itr) {
    ASSERT_EQ(*s21_itr, *std_itr);
  }
}

TEST(SetInsertMany, TestInsertMany_2) {
  std::set<unsigned, std::greater<unsigned>> std_set{1, 2, 3,  4, 5,  5,
                                                     6, 6, 10, 9, 100};
  s21::set<unsigned, std::greater<unsigned>> s21_set;
  s21_set.insert_many(1, 2, 3, 4, 5, 5, 6, 6, 10, 9, 100);

  ASSERT_TRUE(std_set.size() == std_set.size());

  auto s21_s_itr = s21_set.begin();
  auto std_s_itr = std_set.begin();

  for (; s21_s_itr != s21_set.end(); ++s21_s_itr, ++std_s_itr) {
    ASSERT_EQ(*s21_s_itr, *std_s_itr);
  }
}