#include <gtest/gtest.h>

#include <iostream>
#include <map>
#include <vector>

#include "../s21_containers.h"

TEST(MapMemberfunctions, TestDefault) {
  std::map<int, char> std_map;
  s21::map<int, char> s21_map;

  ASSERT_EQ(std_map.size(), s21_map.size());
}

TEST(MapMemberfunctions, TestInitializerList) {
  std::map<int, char> std_map{{1, 'a'}, {15, 'b'}, {1, 'c'}, {0, 'a'}};
  s21::map<int, char> s21_map{{1, 'a'}, {15, 'b'}, {1, 'c'}, {0, 'a'}};

  ASSERT_EQ(std_map.size(), s21_map.size());

  std::map<int, char>::iterator std_itr(std_map.begin());
  s21::map<int, char>::iterator s21_itr(s21_map.begin());
  for (size_t i = 0; i < s21_map.size(); ++i) {
    ASSERT_EQ((*std_itr).first, (*s21_itr).first);
    ASSERT_EQ((*std_itr).second, (*s21_itr).second);
    ++std_itr;
    ++s21_itr;
  }
}

TEST(MapMemberfunctions, TestCopy_1) {
  std::map<int, char> std_map{{1, 'a'}, {15, 'b'}, {1, 'c'},
                              {0, 'a'}, {66, 'h'}, {-5, 'i'}};
  s21::map<int, char> s21_map{{1, 'a'}, {15, 'b'}, {1, 'c'},
                              {0, 'a'}, {66, 'h'}, {-5, 'i'}};

  std::map<int, char> std_copy(std_map);
  s21::map<int, char> s21_copy(s21_map);

  ASSERT_EQ(std_copy.size(), s21_copy.size());
  ASSERT_EQ(std_map.size(), s21_map.size());

  std::map<int, char>::iterator std_itr(std_copy.begin());
  s21::map<int, char>::iterator s21_itr(s21_copy.begin());

  for (; s21_itr != s21_copy.end(); ++std_itr, ++s21_itr) {
    ASSERT_EQ((*std_itr).first, (*s21_itr).first);
    ASSERT_EQ((*std_itr).second, (*s21_itr).second);
  }

  std_itr = std_map.begin();
  s21_itr = s21_map.begin();

  for (; s21_itr != s21_map.end(); ++std_itr, ++s21_itr) {
    ASSERT_EQ((*std_itr).first, (*s21_itr).first);
    ASSERT_EQ((*std_itr).second, (*s21_itr).second);
  }
}

TEST(MapMemberfunctions, TestCopy_2) {
  std::map<int, char> std_map;
  s21::map<int, char> s21_map;

  std::map<int, char> std_copy(std_map);
  s21::map<int, char> s21_copy(s21_map);

  ASSERT_EQ(std_copy.size(), s21_copy.size());
  ASSERT_EQ(std_copy.empty(), s21_copy.empty());
  ASSERT_EQ(std_map.size(), s21_map.size());
}

TEST(MapMemberfunctions, TestMove_1) {
  std::map<int, char> std_map{{1, 'a'}, {15, 'b'}, {1, 'c'},
                              {0, 'a'}, {66, 'h'}, {-5, 'i'}};
  s21::map<int, char> s21_map{{1, 'a'}, {15, 'b'}, {1, 'c'},
                              {0, 'a'}, {66, 'h'}, {-5, 'i'}};

  std::map<int, char> std_move(std::move(std_map));
  s21::map<int, char> s21_move(std::move(s21_map));

  ASSERT_EQ(std_move.size(), s21_move.size());

  std::map<int, char>::iterator std_itr(std_move.begin());
  s21::map<int, char>::iterator s21_itr(s21_move.begin());

  for (; s21_itr != s21_move.end(); ++std_itr, ++s21_itr) {
    ASSERT_EQ((*std_itr).first, (*s21_itr).first);
    ASSERT_EQ((*std_itr).second, (*s21_itr).second);
  }
}

TEST(MapMemberfunctions, TestMove_2) {
  std::map<int, char> std_map;
  s21::map<int, char> s21_map;

  std::map<int, char> std_move(std::move(std_map));
  s21::map<int, char> s21_move(std::move(s21_map));

  ASSERT_EQ(std_move.size(), s21_move.size());
  ASSERT_EQ(std_move.empty(), s21_move.empty());
}

TEST(MapMemberfunctions, TestDestructor) {
  std::map<int, char>* std_map = new std::map<int, char>();
  s21::map<int, char>* s21_map = new s21::map<int, char>();

  std::map<int, char>* std_second = new std::map<int, char>{
      {1, 'a'}, {15, 'b'}, {1, 'c'}, {0, 'a'}, {66, 'h'}, {-5, 'i'}};
  s21::map<int, char>* s21_second = new s21::map<int, char>{
      {1, 'a'}, {15, 'b'}, {1, 'c'}, {0, 'a'}, {66, 'h'}, {-5, 'i'}};

  delete std_map;
  delete s21_map;
  delete std_second;
  delete s21_second;
}

TEST(MapMemberfunctions, TestCopyOperator_1) {
  std::map<int, char> std_map{{1, 'a'}, {15, 'b'}, {1, 'c'},
                              {0, 'a'}, {66, 'h'}, {-5, 'i'}};
  s21::map<int, char> s21_map{{1, 'a'}, {15, 'b'}, {1, 'c'},
                              {0, 'a'}, {66, 'h'}, {-5, 'i'}};

  std::map<int, char> std_copy{{66, 'e'}};
  s21::map<int, char> s21_copy{{12, 'g'}, {3, 'h'}};

  std_copy = std_map;
  s21_copy = s21_map;

  ASSERT_EQ(std_copy.size(), s21_copy.size());
  ASSERT_EQ(std_map.size(), s21_map.size());

  std::map<int, char>::iterator std_itr(std_copy.begin());
  s21::map<int, char>::iterator s21_itr(s21_copy.begin());

  for (; s21_itr != s21_copy.end(); ++std_itr, ++s21_itr) {
    ASSERT_EQ((*std_itr).first, (*s21_itr).first);
    ASSERT_EQ((*std_itr).second, (*s21_itr).second);
  }

  std_itr = std_map.begin();
  s21_itr = s21_map.begin();

  for (; s21_itr != s21_map.end(); ++std_itr, ++s21_itr) {
    ASSERT_EQ((*std_itr).first, (*s21_itr).first);
    ASSERT_EQ((*std_itr).second, (*s21_itr).second);
  }
}

TEST(MapMemberfunctions, TestCopyOperator_2) {
  std::map<int, char> std_map;
  s21::map<int, char> s21_map;

  std::map<int, char> std_copy{{1, 'a'}, {2, 'b'}};
  s21::map<int, char> s21_copy{{99, 'f'}};

  std_copy = std_map;
  s21_copy = s21_map;

  ASSERT_EQ(std_copy.size(), s21_copy.size());
  ASSERT_EQ(std_copy.empty(), s21_copy.empty());
  ASSERT_EQ(std_map.size(), s21_map.size());
  ASSERT_EQ(std_map.empty(), s21_map.empty());
}

TEST(MapMemberfunctions, TestMoveOperator_1) {
  std::map<int, char> std_map{{1, 'a'}, {15, 'b'}, {1, 'c'},
                              {0, 'a'}, {66, 'h'}, {-5, 'i'}};
  s21::map<int, char> s21_map{{1, 'a'}, {15, 'b'}, {1, 'c'},
                              {0, 'a'}, {66, 'h'}, {-5, 'i'}};

  std::map<int, char> std_move;
  s21::map<int, char> s21_move;

  std_move = std::move(std_map);
  s21_move = std::move(s21_map);

  ASSERT_EQ(std_move.size(), s21_move.size());

  std::map<int, char>::iterator std_itr(std_move.begin());
  s21::map<int, char>::iterator s21_itr(s21_move.begin());

  for (; s21_itr != s21_move.end(); ++std_itr, ++s21_itr) {
    ASSERT_EQ((*std_itr).first, (*s21_itr).first);
    ASSERT_EQ((*std_itr).second, (*s21_itr).second);
  }
}

TEST(MapMemberfunctions, TestMoveOperator_2) {
  std::map<int, char> std_map;
  s21::map<int, char> s21_map;

  std::map<int, char> std_move{{0, '1'}};
  s21::map<int, char> s21_move{{9, '.'}, {55, '6'}};

  std_move = std::move(std_map);
  s21_move = std::move(s21_map);

  ASSERT_EQ(std_move.size(), s21_move.size());
  ASSERT_EQ(std_move.empty(), s21_move.empty());
}

TEST(MapElementAccess, TestAt_1) {
  std::map<int, double> std_map;
  s21::map<int, double> s21_map;

  ASSERT_THROW(std_map.at(0), std::out_of_range);
  ASSERT_THROW(s21_map.at(0), std::out_of_range);
}

TEST(MapElementAccess, TestAt_2) {
  std::map<int, double> std_map{{1, 1}, {2, 99.43}, {-2, 21.21}};
  s21::map<int, double> s21_map{{1, 1}, {2, 99.43}, {-2, 21.21}};

  ASSERT_EQ(std_map.at(1), s21_map.at(1));
  ASSERT_EQ(std_map.at(2), s21_map.at(2));
  ASSERT_EQ(std_map.at(-2), s21_map.at(-2));

  std_map.at(-2) = 100;
  s21_map.at(-2) = 100;
  ASSERT_EQ(std_map.at(-2), s21_map.at(-2));
}
TEST(MapElementAccess, TestConstAt_1) {
  const std::map<int, double> std_map;
  const s21::map<int, double> s21_map;

  ASSERT_THROW(std_map.at(0), std::out_of_range);
  ASSERT_THROW(s21_map.at(0), std::out_of_range);
}

TEST(MapElementAccess, TestConstAt_2) {
  const std::map<int, double> std_map{{1, 1}, {2, 99.43}, {-2, 21.21}};
  const s21::map<int, double> s21_map{{1, 1}, {2, 99.43}, {-2, 21.21}};

  ASSERT_EQ(std_map.at(1), s21_map.at(1));
  ASSERT_EQ(std_map.at(2), s21_map.at(2));
  ASSERT_EQ(std_map.at(-2), s21_map.at(-2));

  // std_map.at(-2) = 100;
  // s21_map.at(-2) = 100;
}

TEST(MapElementAccess, TestBrackets) {
  std::map<int, double> std_map{{1, 1}, {2, 99.43}, {-2, 21.21}};
  s21::map<int, double> s21_map{{1, 1}, {2, 99.43}, {-2, 21.21}};

  ASSERT_EQ(std_map[1], s21_map[1]);
  ASSERT_EQ(std_map[2], s21_map[2]);
  ASSERT_EQ(std_map[-2], s21_map[-2]);

  std_map[-2] = 100;
  s21_map[-2] = 100;

  ASSERT_EQ(std_map[-2], s21_map[-2]);
}

TEST(MapElementAccess, TestConstBrackets) {
  const s21::map<int, double> s21_map{{1, 1}, {2, 99.43}, {-2, 21.21}};

  ASSERT_DOUBLE_EQ(1, s21_map[1]);
  ASSERT_DOUBLE_EQ(99.43, s21_map[2]);
  ASSERT_DOUBLE_EQ(21.21, s21_map[-2]);

  // s21_map[-2] = 100;
}

TEST(MapIterators, TestBeginAndEnd) {
  std::map<std::string, int, std::greater<std::string>> std_map{
      {"aloha", 12},  {"hi", 99},        {"school", -90}, {"olala", 0},
      {"how", 123},   {".21.", 1232131}, {"<>", 543223},  {"88000", 44},
      {":6666:", 76}, {"nn", 44},        {"nn", 5555}};
  s21::map<std::string, int, std::greater<std::string>> s21_map{
      {"aloha", 12},  {"hi", 99},        {"school", -90}, {"olala", 0},
      {"how", 123},   {".21.", 1232131}, {"<>", 543223},  {"88000", 44},
      {":6666:", 76}, {"nn", 44},        {"nn", 5555}};

  ASSERT_EQ(std_map.size(), s21_map.size());

  std::map<std::string, int, std::greater<std::string>>::iterator std_itr;
  s21::map<std::string, int, std::greater<std::string>>::iterator s21_itr;

  std_itr = std_map.begin();
  s21_itr = s21_map.begin();

  for (; s21_itr != s21_map.end(); ++s21_itr, ++std_itr) {
    ASSERT_EQ((*s21_itr).first, (*std_itr).first);
    ASSERT_EQ((*s21_itr).second, (*std_itr).second);
  }

  std::map<std::string, int, std::greater<std::string>>::iterator std_s_itr(
      std_map.end());
  s21::map<std::string, int, std::greater<std::string>>::iterator s21_s_itr(
      s21_map.end());

  --s21_s_itr;
  --std_s_itr;

  for (; s21_s_itr != s21_map.begin(); --s21_s_itr, --std_s_itr) {
    ASSERT_EQ((*s21_s_itr).first, (*std_s_itr).first);
    ASSERT_EQ((*s21_s_itr).second, (*std_s_itr).second);
  }
}

TEST(MapIterators, TestConstBeginAndEnd) {
  const std::map<std::string, int, std::greater<std::string>> std_map{
      {"aloha", 12},  {"hi", 99},        {"school", -90}, {"olala", 0},
      {"how", 123},   {".21.", 1232131}, {"<>", 543223},  {"88000", 44},
      {":6666:", 76}, {"nn", 44},        {"nn", 5555}};
  const s21::map<std::string, int, std::greater<std::string>> s21_map{
      {"aloha", 12},  {"hi", 99},        {"school", -90}, {"olala", 0},
      {"how", 123},   {".21.", 1232131}, {"<>", 543223},  {"88000", 44},
      {":6666:", 76}, {"nn", 44},        {"nn", 5555}};

  ASSERT_EQ(std_map.size(), s21_map.size());

  std::map<std::string, int, std::greater<std::string>>::const_iterator std_itr;
  s21::map<std::string, int, std::greater<std::string>>::const_iterator s21_itr;

  std_itr = std_map.begin();
  s21_itr = s21_map.begin();

  for (; s21_itr != s21_map.end(); ++s21_itr, ++std_itr) {
    ASSERT_EQ((*s21_itr).first, (*std_itr).first);
    ASSERT_EQ((*s21_itr).second, (*std_itr).second);
  }

  std::map<std::string, int, std::greater<std::string>>::const_iterator
      std_s_itr(std_map.end());
  s21::map<std::string, int, std::greater<std::string>>::const_iterator
      s21_s_itr(s21_map.end());

  --s21_s_itr;
  --std_s_itr;

  for (; s21_s_itr != s21_map.begin(); --s21_s_itr, --std_s_itr) {
    ASSERT_EQ((*s21_s_itr).first, (*std_s_itr).first);
    ASSERT_EQ((*s21_s_itr).second, (*std_s_itr).second);
  }
}

TEST(MapCapacity, TestEmpty_1) {
  std::map<std::string, int, std::greater<std::string>> std_map{
      {"aloha", 12},  {"hi", 99},        {"school", -90}, {"olala", 0},
      {"how", 123},   {".21.", 1232131}, {"<>", 543223},  {"88000", 44},
      {":6666:", 76}, {"nn", 44},        {"nn", 5555}};
  s21::map<std::string, int, std::greater<std::string>> s21_map{
      {"aloha", 12},  {"hi", 99},        {"school", -90}, {"olala", 0},
      {"how", 123},   {".21.", 1232131}, {"<>", 543223},  {"88000", 44},
      {":6666:", 76}, {"nn", 44},        {"nn", 5555}};

  ASSERT_EQ(std_map.empty(), s21_map.empty());

  std_map.clear();
  s21_map.clear();

  ASSERT_EQ(std_map.empty(), s21_map.empty());

  std_map.insert({"again", 1});
  s21_map.insert({"again", 1});

  ASSERT_EQ(std_map.empty(), s21_map.empty());
}

TEST(MapCapacity, TestEmpty_2) {
  std::map<std::string, int, std::greater<std::string>> std_map;
  s21::map<std::string, int, std::greater<std::string>> s21_map;

  ASSERT_EQ(std_map.empty(), s21_map.empty());

  std_map.insert({"again", 1});
  s21_map.insert({"again", 1});

  ASSERT_EQ(std_map.empty(), s21_map.empty());
}

TEST(MapCapacity, TestMaxSize) {
  std::map<std::string, int, std::greater<std::string>> std_first;
  s21::map<std::string, int, std::greater<std::string>> s21_first;

  ASSERT_NE(std_first.max_size(), s21_first.max_size());

  std::map<int, int> std_second;
  s21::map<int, int> s21_second;

  ASSERT_NE(std_second.max_size(), s21_second.max_size());
}

TEST(MapModifiers, TestClear_1) {
  std::map<std::string, int, std::greater<std::string>> std_map;
  s21::map<std::string, int, std::greater<std::string>> s21_map;

  std_map.clear();
  s21_map.clear();

  ASSERT_EQ(std_map.size(), s21_map.size());
  ASSERT_EQ(std_map.empty(), s21_map.empty());
}

TEST(MapModifiers, TestClear_2) {
  std::map<std::string, int, std::greater<std::string>> std_map{
      {"aloha", 12},  {"hi", 99},        {"school", -90}, {"olala", 0},
      {"how", 123},   {".21.", 1232131}, {"<>", 543223},  {"88000", 44},
      {":6666:", 76}, {"nn", 44},        {"nn", 5555}};
  s21::map<std::string, int, std::greater<std::string>> s21_map{
      {"aloha", 12},  {"hi", 99},        {"school", -90}, {"olala", 0},
      {"how", 123},   {".21.", 1232131}, {"<>", 543223},  {"88000", 44},
      {":6666:", 76}, {"nn", 44},        {"nn", 5555}};

  std_map.clear();
  s21_map.clear();

  ASSERT_EQ(std_map.size(), s21_map.size());
  ASSERT_EQ(std_map.empty(), s21_map.empty());

  std_map.insert({"maybe", 1});
  s21_map.insert({"aaaa", 2});

  std_map.clear();
  s21_map.clear();

  ASSERT_EQ(std_map.size(), s21_map.size());
  ASSERT_EQ(std_map.empty(), s21_map.empty());
}

TEST(MapModifiers, TestInsert_1) {
  std::map<std::string, int, std::greater<std::string>> std_map{
      {"aloha", 12},  {"hi", 99},        {"school", -90}, {"olala", 0},
      {"how", 123},   {".21.", 1232131}, {"<>", 543223},  {"88000", 44},
      {":6666:", 76}, {"nn", 44},        {"nn", 5555}};
  s21::map<std::string, int, std::greater<std::string>> s21_map{
      {"aloha", 12},  {"hi", 99},        {"school", -90}, {"olala", 0},
      {"how", 123},   {".21.", 1232131}, {"<>", 543223},  {"88000", 44},
      {":6666:", 76}, {"nn", 44},        {"nn", 5555}};

  auto std_pair = std_map.insert({"<>", 11});
  auto s21_pair = s21_map.insert({"<>", 11});

  ASSERT_FALSE(s21_pair.second);
  ASSERT_FALSE(std_pair.second);

  (*(std_pair.first)).second = 2;
  (*(s21_pair.first)).second = 2;

  std_pair = std_map.insert({"right", 99999});
  s21_pair = s21_map.insert({"right", 99999});

  ASSERT_TRUE(s21_pair.second);
  ASSERT_TRUE(std_pair.second);

  ASSERT_EQ(std_map.size(), s21_map.size());

  std::map<std::string, int, std::greater<std::string>>::iterator std_itr(
      std_map.begin());
  s21::map<std::string, int, std::greater<std::string>>::iterator s21_itr(
      s21_map.begin());

  for (; s21_itr != s21_map.end(); ++s21_itr, ++std_itr) {
    ASSERT_EQ((*s21_itr).first, (*std_itr).first);
    ASSERT_EQ((*s21_itr).second, (*std_itr).second);
  }
}

TEST(MapModifiers, TestInsert_2) {
  std::map<int, int> std_map;
  s21::map<int, int> s21_map;

  std_map.insert({1, 11});
  auto std_pair = std_map.insert({2, 11});
  std_map.insert({3, 11});
  s21_map.insert({1, 11});
  auto s21_pair = s21_map.insert({2, 11});
  s21_map.insert({3, 11});

  ASSERT_EQ(std_map.size(), s21_map.size());

  (*(std_pair.first)).second = -999;
  (*(s21_pair.first)).second = -999;

  std::map<int, int>::iterator std_itr(std_map.begin());
  s21::map<int, int>::iterator s21_itr(s21_map.begin());

  for (; s21_itr != s21_map.end(); ++s21_itr, ++std_itr) {
    ASSERT_EQ((*s21_itr).first, (*std_itr).first);
    ASSERT_EQ((*s21_itr).second, (*std_itr).second);
  }
}

TEST(MapModifiers, TestInsert_3) {
  std::map<std::string, int, std::greater<std::string>> std_map{
      {"aloha", 12},  {"hi", 99},        {"school", -90}, {"olala", 0},
      {"how", 123},   {".21.", 1232131}, {"<>", 543223},  {"88000", 44},
      {":6666:", 76}, {"nn", 44},        {"nn", 5555}};
  s21::map<std::string, int, std::greater<std::string>> s21_map{
      {"aloha", 12},  {"hi", 99},        {"school", -90}, {"olala", 0},
      {"how", 123},   {".21.", 1232131}, {"<>", 543223},  {"88000", 44},
      {":6666:", 76}, {"nn", 44},        {"nn", 5555}};

  auto std_pair = std_map.insert({"<>", 11});
  auto s21_pair = s21_map.insert("<>", 11);

  ASSERT_FALSE(s21_pair.second);
  ASSERT_FALSE(std_pair.second);

  (*(std_pair.first)).second = 2;
  (*(s21_pair.first)).second = 2;

  std_pair = std_map.insert({"right", 99999});
  s21_pair = s21_map.insert("right", 99999);

  ASSERT_TRUE(s21_pair.second);
  ASSERT_TRUE(std_pair.second);

  ASSERT_EQ(std_map.size(), s21_map.size());

  std::map<std::string, int, std::greater<std::string>>::iterator std_itr(
      std_map.begin());
  s21::map<std::string, int, std::greater<std::string>>::iterator s21_itr(
      s21_map.begin());

  for (; s21_itr != s21_map.end(); ++s21_itr, ++std_itr) {
    ASSERT_EQ((*s21_itr).first, (*std_itr).first);
    ASSERT_EQ((*s21_itr).second, (*std_itr).second);
  }
}

TEST(MapModifiers, TestInsert_4) {
  std::map<int, int> std_map;
  s21::map<int, int> s21_map;

  std_map.insert({1, 11});
  auto std_pair = std_map.insert({2, 11});
  std_map.insert({3, 11});
  s21_map.insert(1, 11);
  auto s21_pair = s21_map.insert(2, 11);
  s21_map.insert(3, 11);

  ASSERT_EQ(std_map.size(), s21_map.size());

  (*(std_pair.first)).second = -999;
  (*(s21_pair.first)).second = -999;

  std::map<int, int>::iterator std_itr(std_map.begin());
  s21::map<int, int>::iterator s21_itr(s21_map.begin());

  for (; s21_itr != s21_map.end(); ++s21_itr, ++std_itr) {
    ASSERT_EQ((*s21_itr).first, (*std_itr).first);
    ASSERT_EQ((*s21_itr).second, (*std_itr).second);
  }
}

TEST(MapModifiers, TestInsertOrAssign_1) {
  std::map<int, int> std_map;
  s21::map<int, int> s21_map;

  std_map.insert_or_assign(1, 11);
  std_map.insert_or_assign(2, 11);
  std_map.insert_or_assign(3, 11);

  s21_map.insert_or_assign(1, 11);
  s21_map.insert_or_assign(2, 11);
  s21_map.insert_or_assign(3, 11);

  ASSERT_EQ(std_map.size(), s21_map.size());

  std::map<int, int>::iterator std_itr(std_map.begin());
  s21::map<int, int>::iterator s21_itr(s21_map.begin());

  auto std_pair = std_map.insert_or_assign(1, 5);
  auto s21_pair = s21_map.insert_or_assign(1, 5);

  ASSERT_EQ(std_pair.second, s21_pair.second);

  for (; s21_itr != s21_map.end(); ++s21_itr, ++std_itr) {
    ASSERT_EQ((*s21_itr).first, (*std_itr).first);
    ASSERT_EQ((*s21_itr).second, (*std_itr).second);
  }
}

TEST(MapModifiers, TestInsertOrAssign_2) {
  std::map<std::string, int, std::greater<std::string>> std_map{
      {"aloha", 12},  {"hi", 99},        {"school", -90}, {"olala", 0},
      {"how", 123},   {".21.", 1232131}, {"<>", 543223},  {"88000", 44},
      {":6666:", 76}, {"nn", 44},        {"nn", 5555}};
  s21::map<std::string, int, std::greater<std::string>> s21_map{
      {"aloha", 12},  {"hi", 99},        {"school", -90}, {"olala", 0},
      {"how", 123},   {".21.", 1232131}, {"<>", 543223},  {"88000", 44},
      {":6666:", 76}, {"nn", 44},        {"nn", 5555}};

  auto std_pair = std_map.insert_or_assign("<>", 0);
  auto s21_pair = s21_map.insert_or_assign("<>", 0);

  ASSERT_EQ(s21_pair.second, std_pair.second);

  (*(std_pair.first)).second = 2;
  (*(s21_pair.first)).second = 2;

  std_map.insert_or_assign("right", 99999);
  s21_map.insert_or_assign("right", 99999);

  std_map.insert_or_assign("aloha", 555555);
  s21_map.insert_or_assign("aloha", 555555);

  ASSERT_EQ(std_map.size(), s21_map.size());

  std::map<std::string, int, std::greater<std::string>>::iterator std_itr(
      std_map.begin());
  s21::map<std::string, int, std::greater<std::string>>::iterator s21_itr(
      s21_map.begin());

  for (; s21_itr != s21_map.end(); ++s21_itr, ++std_itr) {
    ASSERT_EQ((*s21_itr).first, (*std_itr).first);
    ASSERT_EQ((*s21_itr).second, (*std_itr).second);
  }
}

TEST(MapModifiers, TestErase) {
  std::map<std::string, int, std::greater<std::string>> std_map{
      {"aloha", 12},  {"hi", 99},        {"school", -90}, {"olala", 0},
      {"how", 123},   {".21.", 1232131}, {"<>", 543223},  {"88000", 44},
      {":6666:", 76}, {"nn", 44},        {"nn", 5555}};
  s21::map<std::string, int, std::greater<std::string>> s21_map{
      {"aloha", 12},  {"hi", 99},        {"school", -90}, {"olala", 0},
      {"how", 123},   {".21.", 1232131}, {"<>", 543223},  {"88000", 44},
      {":6666:", 76}, {"nn", 44},        {"nn", 5555}};

  std_map.erase(std_map.begin());
  s21_map.erase(s21_map.begin());

  std_map.erase(--std_map.end());
  s21_map.erase(--s21_map.end());

  ASSERT_EQ(std_map.size(), s21_map.size());

  std::map<std::string, int, std::greater<std::string>>::iterator std_itr(
      std_map.begin());
  s21::map<std::string, int, std::greater<std::string>>::iterator s21_itr(
      s21_map.begin());

  for (size_t i = s21_map.size(); i > 0;
       --i, s21_itr = s21_map.begin(), std_itr = std_map.begin()) {
    ASSERT_EQ((*s21_itr).first, (*std_itr).first);
    ASSERT_EQ((*s21_itr).second, (*std_itr).second);
    s21_map.erase(s21_itr);
    std_map.erase(std_itr);
  }

  ASSERT_EQ(std_map.size(), s21_map.size());
  ASSERT_EQ(std_map.empty(), s21_map.empty());
}

TEST(MapModifiers, TestSwap_1) {
  std::map<std::string, int, std::greater<std::string>> std_map{
      {"aloha", 12},  {"hi", 99},        {"school", -90}, {"olala", 0},
      {"how", 123},   {".21.", 1232131}, {"<>", 543223},  {"88000", 44},
      {":6666:", 76}, {"nn", 44},        {"nn", 5555}};
  s21::map<std::string, int, std::greater<std::string>> s21_map{
      {"aloha", 12},  {"hi", 99},        {"school", -90}, {"olala", 0},
      {"how", 123},   {".21.", 1232131}, {"<>", 543223},  {"88000", 44},
      {":6666:", 76}, {"nn", 44},        {"nn", 5555}};

  s21::map<std::string, int, std::greater<std::string>> s21_swap;
  std::map<std::string, int, std::greater<std::string>> std_swap;

  s21_swap.swap(s21_map);
  std_swap.swap(std_map);

  ASSERT_EQ(std_map.size(), s21_map.size());
  ASSERT_EQ(std_map.empty(), s21_map.empty());
  ASSERT_EQ(std_swap.size(), s21_swap.size());

  std::map<std::string, int, std::greater<std::string>>::iterator std_itr(
      std_swap.begin());
  s21::map<std::string, int, std::greater<std::string>>::iterator s21_itr(
      s21_swap.begin());

  for (; s21_itr != s21_swap.end(); ++s21_itr, ++std_itr) {
    ASSERT_EQ((*s21_itr).first, (*std_itr).first);
    ASSERT_EQ((*s21_itr).second, (*std_itr).second);
  }
}

TEST(MapModifiers, TestSwap_2) {
  std::map<std::string, int> std_map{
      {"aloha", 12},  {"hi", 99},        {"school", -90}, {"olala", 0},
      {"how", 123},   {".21.", 1232131}, {"<>", 543223},  {"88000", 44},
      {":6666:", 76}, {"nn", 44},        {"nn", 5555}};
  s21::map<std::string, int> s21_map{
      {"aloha", 12},  {"hi", 99},        {"school", -90}, {"olala", 0},
      {"how", 123},   {".21.", 1232131}, {"<>", 543223},  {"88000", 44},
      {":6666:", 76}, {"nn", 44},        {"nn", 5555}};

  s21::map<std::string, int> s21_swap{{"hhh", 222}, {"lolo", 99}, {"inc", -43}};
  std::map<std::string, int> std_swap{{"hhh", 222}, {"lolo", 99}, {"inc", -43}};

  s21_swap.swap(s21_map);
  std_swap.swap(std_map);

  ASSERT_EQ(std_map.size(), s21_map.size());
  ASSERT_EQ(std_swap.size(), s21_swap.size());

  std::map<std::string, int>::iterator std_itr(std_swap.begin());
  s21::map<std::string, int>::iterator s21_itr(s21_swap.begin());

  for (; s21_itr != s21_swap.end(); ++s21_itr, ++std_itr) {
    ASSERT_EQ((*s21_itr).first, (*std_itr).first);
    ASSERT_EQ((*s21_itr).second, (*std_itr).second);
  }

  std_itr = std_map.begin();
  s21_itr = s21_map.begin();
  for (; s21_itr != s21_map.end(); ++s21_itr, ++std_itr) {
    ASSERT_EQ((*s21_itr).first, (*std_itr).first);
    ASSERT_EQ((*s21_itr).second, (*std_itr).second);
  }
}

TEST(MapModifiers, TestSwap_3) {
  std::map<std::string, int> std_map;
  s21::map<std::string, int> s21_map;

  s21::map<std::string, int> s21_swap;
  std::map<std::string, int> std_swap;

  s21_swap.swap(s21_map);
  std_swap.swap(std_map);

  ASSERT_EQ(std_map.size(), s21_map.size());
  ASSERT_EQ(std_swap.size(), s21_swap.size());

  ASSERT_EQ(std_map.empty(), s21_map.empty());
  ASSERT_EQ(std_swap.empty(), s21_swap.empty());
}

TEST(MapModifiers, TestMerge_1) {
  std::map<std::string, int> std_map;
  s21::map<std::string, int> s21_map;

  s21::map<std::string, int> s21_merge;
  std::map<std::string, int> std_merge;

  s21_merge.merge(s21_map);
  std_merge.merge(std_map);

  ASSERT_EQ(std_map.size(), s21_map.size());
  ASSERT_EQ(std_merge.size(), s21_merge.size());

  ASSERT_EQ(std_map.empty(), s21_map.empty());
  ASSERT_EQ(std_merge.empty(), s21_merge.empty());
}

TEST(MapModifiers, TestMerge_2) {
  std::map<std::string, int> std_map{
      {"aloha", 12},  {"hi", 99},        {"school", -90}, {"olala", 0},
      {"how", 123},   {".21.", 1232131}, {"<>", 543223},  {"88000", 44},
      {":6666:", 76}, {"nn", 44},        {"nn", 5555}};
  s21::map<std::string, int> s21_map{
      {"aloha", 12},  {"hi", 99},        {"school", -90}, {"olala", 0},
      {"how", 123},   {".21.", 1232131}, {"<>", 543223},  {"88000", 44},
      {":6666:", 76}, {"nn", 44},        {"nn", 5555}};

  s21::map<std::string, int> s21_merge{{"boddy", 12},     {"yeah", 450},
                                       {"olala", 12},     {"nobody", 44},
                                       {":1:", 51521235}, {"go go go", 8800},
                                       {"nn", 55},        {".21.", 123456789}};
  std::map<std::string, int> std_merge{{"boddy", 12},     {"yeah", 450},
                                       {"olala", 12},     {"nobody", 44},
                                       {":1:", 51521235}, {"go go go", 8800},
                                       {"nn", 55},        {".21.", 123456789}};

  s21_merge.merge(s21_map);
  std_merge.merge(std_map);

  ASSERT_EQ(std_map.size(), s21_map.size());
  ASSERT_EQ(std_merge.size(), s21_merge.size());

  std::map<std::string, int>::iterator std_itr(std_merge.begin());
  s21::map<std::string, int>::iterator s21_itr(s21_merge.begin());

  for (; s21_itr != s21_merge.end(); ++s21_itr, ++std_itr) {
    ASSERT_EQ((*s21_itr).first, (*std_itr).first);
    ASSERT_EQ((*s21_itr).second, (*std_itr).second);
  }

  std_itr = std_map.begin();
  s21_itr = s21_map.begin();
  for (; s21_itr != s21_map.end(); ++s21_itr, ++std_itr) {
    ASSERT_EQ((*s21_itr).first, (*std_itr).first);
    ASSERT_EQ((*s21_itr).second, (*std_itr).second);
  }
}

TEST(MapModifiers, TestMerge_3) {
  std::map<std::string, int> std_map{
      {"aloha", 12},  {"hi", 99},        {"school", -90}, {"olala", 0},
      {"how", 123},   {".21.", 1232131}, {"<>", 543223},  {"88000", 44},
      {":6666:", 76}, {"nn", 44},        {"nn", 5555}};
  s21::map<std::string, int> s21_map{
      {"aloha", 12},  {"hi", 99},        {"school", -90}, {"olala", 0},
      {"how", 123},   {".21.", 1232131}, {"<>", 543223},  {"88000", 44},
      {":6666:", 76}, {"nn", 44},        {"nn", 5555}};

  s21::map<std::string, int> s21_merge;
  std::map<std::string, int> std_merge;

  s21_merge.merge(s21_map);
  std_merge.merge(std_map);

  ASSERT_EQ(std_map.size(), s21_map.size());
  ASSERT_EQ(std_map.empty(), s21_map.empty());
  ASSERT_EQ(std_merge.size(), s21_merge.size());

  std::map<std::string, int>::iterator std_itr(std_merge.begin());
  s21::map<std::string, int>::iterator s21_itr(s21_merge.begin());

  for (; s21_itr != s21_merge.end(); ++s21_itr, ++std_itr) {
    ASSERT_EQ((*s21_itr).first, (*std_itr).first);
    ASSERT_EQ((*s21_itr).second, (*std_itr).second);
  }
}

TEST(MapLookup, TestFind) {
  std::map<std::string, int> std_map{
      {"aloha", 12},  {"hi", 99},        {"school", -90}, {"olala", 0},
      {"how", 123},   {".21.", 1232131}, {"<>", 543223},  {"88000", 44},
      {":6666:", 76}, {"nn", 44},        {"nn", 5555}};
  s21::map<std::string, int> s21_map{
      {"aloha", 12},  {"hi", 99},        {"school", -90}, {"olala", 0},
      {"how", 123},   {".21.", 1232131}, {"<>", 543223},  {"88000", 44},
      {":6666:", 76}, {"nn", 44},        {"nn", 5555}};

  std::map<std::string, int>::iterator std_itr;
  s21::map<std::string, int>::iterator s21_itr;

  std_itr = std_map.find(".21.");
  s21_itr = s21_map.find(".21.");

  ASSERT_EQ((*std_itr).first, (*s21_itr).first);
  ASSERT_EQ((*std_itr).second, (*s21_itr).second);

  (*s21_itr).second = 12;
  (*std_itr).second = 12;

  std_itr = std_map.find("does not exist");
  s21_itr = s21_map.find("does not exist");

  ASSERT_EQ(std_itr == std_map.end(), s21_itr == s21_map.end());

  std_itr = std_map.begin();
  s21_itr = s21_map.begin();

  for (; s21_itr != s21_map.end(); ++s21_itr, ++std_itr) {
    ASSERT_EQ((*s21_itr).first, (*std_itr).first);
    ASSERT_EQ((*s21_itr).second, (*std_itr).second);
  }
}

TEST(MapLookup, TestFindConst) {
  const std::map<std::string, int> std_map{
      {"aloha", 12},  {"hi", 99},        {"school", -90}, {"olala", 0},
      {"how", 123},   {".21.", 1232131}, {"<>", 543223},  {"88000", 44},
      {":6666:", 76}, {"nn", 44},        {"nn", 5555}};
  const s21::map<std::string, int> s21_map{
      {"aloha", 12},  {"hi", 99},        {"school", -90}, {"olala", 0},
      {"how", 123},   {".21.", 1232131}, {"<>", 543223},  {"88000", 44},
      {":6666:", 76}, {"nn", 44},        {"nn", 5555}};

  std::map<std::string, int>::const_iterator std_itr;
  s21::map<std::string, int>::const_iterator s21_itr;

  std_itr = std_map.find(".21.");
  s21_itr = s21_map.find(".21.");

  ASSERT_EQ((*std_itr).first, (*s21_itr).first);
  ASSERT_EQ((*std_itr).second, (*s21_itr).second);

  // (*s21_itr).second = 12;
  // (*std_itr).second = 12;

  std_itr = std_map.find("does not exist");
  s21_itr = s21_map.find("does not exist");

  ASSERT_EQ(std_itr == std_map.end(), s21_itr == s21_map.end());

  std_itr = std_map.begin();
  s21_itr = s21_map.begin();

  for (; s21_itr != s21_map.end(); ++s21_itr, ++std_itr) {
    ASSERT_EQ((*s21_itr).first, (*std_itr).first);
    ASSERT_EQ((*s21_itr).second, (*std_itr).second);
  }
}

TEST(MapLookup, TestContains) {
  std::map<std::string, int> std_map{
      {"aloha", 12},  {"hi", 99},        {"school", -90}, {"olala", 0},
      {"how", 123},   {".21.", 1232131}, {"<>", 543223},  {"88000", 44},
      {":6666:", 76}, {"nn", 44},        {"nn", 5555}};
  s21::map<std::string, int> s21_map{
      {"aloha", 12},  {"hi", 99},        {"school", -90}, {"olala", 0},
      {"how", 123},   {".21.", 1232131}, {"<>", 543223},  {"88000", 44},
      {":6666:", 76}, {"nn", 44},        {"nn", 5555}};

  std::map<std::string, int>::iterator std_itr;

  std_itr = std_map.find(".21.");
  ASSERT_EQ(s21_map.contains(".21."), std_itr != std_map.end());

  std_itr = std_map.find("does not exist");

  ASSERT_EQ(!s21_map.contains("does not exist"), std_itr == std_map.end());

  std_itr = std_map.begin();
}

TEST(MapInsertMany, TestInsertMany) {
  std::map<std::string, int> std_map{
      {"aloha", 12},  {"hi", 99},        {"school", -90}, {"olala", 0},
      {"how", 123},   {".21.", 1232131}, {"<>", 543223},  {"88000", 44},
      {":6666:", 76}, {"nn", 44},        {"nn", 5555}};
  s21::map<std::string, int> s21_map;

  std::pair<std::string, int> pair_1("aloha", 12);
  std::pair<std::string, int> pair_2("hi", 99);
  std::pair<std::string, int> pair_3("school", -90);
  std::pair<std::string, int> pair_4("olala", 0);
  std::pair<std::string, int> pair_5("how", 123);
  std::pair<std::string, int> pair_6(".21.", 1232131);
  std::pair<std::string, int> pair_7("<>", 543223);
  std::pair<std::string, int> pair_8("88000", 44);
  std::pair<std::string, int> pair_9(":6666:", 76);
  std::pair<std::string, int> pair_10(":6666:", 76);
  s21_map.insert_many(pair_1, pair_2, pair_3, pair_4, pair_5, pair_6, pair_7,
                      pair_8, pair_9, pair_10);

  std::pair<std::string, int> pair_11("nn", 44);
  s21_map.insert_many(pair_11);

  std::map<std::string, int>::iterator std_itr(std_map.begin());
  s21::map<std::string, int>::iterator s21_itr(s21_map.begin());

  ASSERT_EQ(s21_map.size(), std_map.size());

  for (; s21_itr != s21_map.end(); ++s21_itr, ++std_itr) {
    ASSERT_EQ((*s21_itr).first, (*std_itr).first);
    ASSERT_EQ((*s21_itr).second, (*std_itr).second);
  }
}