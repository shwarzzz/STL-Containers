#ifndef S21_MAP_H_

#define S21_MAP_H_

#include <stdexcept>

#include "s21_tree.h"
#include "s21_vector.h"

namespace s21 {
template <typename Key, typename T, typename Compare = std::less<Key>>
class map {
 private:
  using tree_type = s21::BinaryTree<Key, T, Compare>;
  using tr_iter = typename tree_type::tree_iterator;

  template <typename KeyItr, typename TItr>
  class MapIterator;

  template <typename KeyItr, typename TItr>
  class MapConstIterator;

 public:
  //   Map Member type

  using key_type = Key;
  using mapped_type = T;
  using value_type = std::pair<const key_type, mapped_type>;
  using reference = value_type &;
  using const_reference = const value_type &;
  using iterator = MapIterator<Key, T>;
  using const_iterator = MapConstIterator<Key, T>;
  using size_type = size_t;

  //   Map Member functions

  map() { tree_ = new tree_type(); }

  map(const map &m) {
    tree_ = new tree_type();
    try {
      *tree_ = *(m.tree_);
    } catch (...) {
      delete tree_;
      throw;
    }
  }

  map(map &&m) noexcept : tree_(m.tree_) { m.tree_ = nullptr; }

  map(std::initializer_list<value_type> const &items) {
    tree_ = new tree_type();
    for (auto i = items.begin(); i != items.end(); i++) {
      try {
        tree_->AddNode((*i).first, (*i).second);
      } catch (...) {
        tree_->Clear();
        delete tree_;
        throw;
      }
    }
  }

  map &operator=(map &&m) noexcept {
    if (this != &m) {
      clear();
      delete tree_;
      tree_ = m.tree_;
      m.tree_ = nullptr;
    }
    return *this;
  }

  map &operator=(const map &m) {
    if (this != &m) {
      map tmp(m);
      *this = std::move(tmp);
    }
    return *this;
  }

  ~map() { delete tree_; }

  //   Map Element access

  T &at(const Key &key) {
    iterator tmp = find(key);
    if (tmp == end()) {
      throw std::out_of_range("Error: key does not exists!");
    } else {
      return (*tmp).second;
    }
  }

  const T &at(const Key &key) const {
    const_iterator tmp = find(key);
    if (tmp == end()) {
      throw std::out_of_range("Error: key does not exists!");
    } else {
      return (*tmp).second;
    }
  }

  T &operator[](const Key &key) { return (*find(key)).second; }

  const T &operator[](const Key &key) const { return (*find(key)).second; }

  //   Map Iterators

  iterator begin() {
    iterator itr(tree_->Begin());
    return itr;
  }

  const_iterator begin() const {
    const_iterator itr(tree_->Begin());
    return itr;
  }

  iterator end() {
    iterator itr(tree_->End());
    return itr;
  }

  const_iterator end() const {
    const_iterator itr(tree_->End());
    return itr;
  }

  //   Map Capacity

  bool empty() const noexcept { return tree_->Empty(); }

  size_type size() const noexcept { return tree_->Size(); }

  size_type max_size() const noexcept { return tree_->MaxSize(); }

  //   Map Modifiers

  void clear() noexcept { tree_->Clear(); }

  std::pair<iterator, bool> insert(const value_type &value) {
    std::pair<tr_iter, bool> pair = tree_->AddNode(value.first, value.second);
    iterator itr(pair.first);
    std::pair<iterator, bool> result(itr, pair.second);
    return result;
  }

  std::pair<iterator, bool> insert(const Key &key, const T &obj) {
    std::pair<tr_iter, bool> pair = tree_->AddNode(key, obj);
    iterator itr(pair.first);
    std::pair<iterator, bool> result(itr, pair.second);
    return result;
  }

  std::pair<iterator, bool> insert_or_assign(const Key &key, const T &obj) {
    std::pair<tr_iter, bool> pair = tree_->EmplaceNode(key, obj);
    iterator itr(pair.first);
    std::pair<iterator, bool> result(itr, pair.second);
    return result;
  }

  void erase(iterator pos) { tree_->DeleteNode((*pos).first); }

  void swap(map &other) noexcept {
    tree_type *tmp = tree_;
    tree_ = other.tree_;
    other.tree_ = tmp;
  }

  void merge(map &other) {
    if (this != &other) {
      if (tree_ == nullptr || tree_->Size() == 0) {
        swap(other);
      } else {
        tree_->Merge(*other.tree_);
      }
    }
  }

  //   Map Lookup

  bool contains(const Key &key) const { return tree_->Contains(key); }

  iterator find(const Key &key) {
    iterator res(tree_->Find(key));
    return res;
  }

  const_iterator find(const Key &key) const {
    const_iterator res(tree_->Find(key));
    return res;
  }

  // Map insert_many

  template <typename... Args>
  vector<std::pair<iterator, bool>> insert_many(Args &&...args) {
    vector<std::pair<iterator, bool>> result;
    for (auto item : {std::forward<Args>(args)...}) {
      try {
        std::pair<iterator, bool> pair = insert(item);
        result.push_back(pair);
      } catch (...) {
        for (size_t i = 0; i < result.size(); ++i) {
          iterator tmp = (result[i]).first;
          erase(tmp);
        }
        result.clear();
        throw;
      }
    }
    return result;
  }

 private:
  tree_type *tree_;

 private:
  template <typename KeyItr, typename TItr>
  class MapIterator {
   public:
    MapIterator() = default;

    MapIterator(const tr_iter &other) { itr_ = other; }

    MapIterator(const MapIterator &other) { itr_ = other.itr_; }

    MapIterator &operator=(const MapIterator &other) {
      itr_ = other.itr_;
      return *this;
    }

    std::pair<const KeyItr &, TItr &> operator*() {
      std::pair<const KeyItr &, TItr &> pair((*itr_).first, (*itr_).second);
      return pair;
    }

    MapIterator &operator++() {
      ++itr_;
      return *this;
    }

    MapIterator &operator--() {
      --itr_;
      return *this;
    }

    bool operator==(const MapIterator &other) { return itr_ == other.itr_; }

    bool operator!=(const MapIterator &other) { return itr_ != other.itr_; }

   private:
    tr_iter itr_;
  };

  template <typename KeyItr, typename TItr>
  class MapConstIterator {
   public:
    MapConstIterator() = default;

    MapConstIterator(const tr_iter &other) { itr_ = other; }

    MapConstIterator(const MapConstIterator &other) { itr_ = other.itr_; }

    MapConstIterator &operator=(const MapConstIterator &other) {
      itr_ = other.itr_;
      return *this;
    }

    const std::pair<const KeyItr &, const TItr &> operator*() {
      std::pair<const KeyItr &, const TItr &> pair((*itr_).first,
                                                   (*itr_).second);
      return pair;
    }

    MapConstIterator &operator++() {
      ++itr_;
      return *this;
    }

    MapConstIterator &operator--() {
      --itr_;
      return *this;
    }

    bool operator==(const MapConstIterator &other) {
      return itr_ == other.itr_;
    }

    bool operator!=(const MapConstIterator &other) {
      return itr_ != other.itr_;
    }

   private:
    tr_iter itr_;
  };
};
}  // namespace s21
#endif