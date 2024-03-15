#ifndef S21_SET_H_

#define S21_SET_H_

#include "s21_tree.h"
#include "s21_vector.h"

namespace s21 {

template <typename Key, typename Compare = std::less<Key>>
class set {
 private:
  using tree_type = s21::BinaryTree<Key, Key, Compare>;
  using tr_iter = typename tree_type::tree_iterator;

  template <typename T>
  class SetIterator;

  template <typename T>
  class SetConstIterator;

 public:
  // Set Member type

  using key_type = Key;
  using value_type = Key;
  using reference = value_type &;
  using const_reference = const value_type &;
  using iterator = SetIterator<Key>;
  using const_iterator = SetConstIterator<Key>;
  using size_type = size_t;

  // Set Member functions

  set() { tree_ = new tree_type(); }

  set(const set &s) {
    tree_ = new tree_type();
    try {
      *tree_ = *(s.tree_);
    } catch (...) {
      delete tree_;
      throw;
    }
  }

  set(set &&s) noexcept : tree_(s.tree_) { s.tree_ = nullptr; }

  set(std::initializer_list<value_type> const &items) {
    tree_ = new tree_type();
    for (auto i = items.begin(); i != items.end(); i++) {
      try {
        tree_->AddNode(*i, *i);
      } catch (...) {
        tree_->Clear();
        delete tree_;
        throw;
      }
    }
  }

  set &operator=(set &&s) noexcept {
    if (this != &s) {
      tree_->Clear();
      delete tree_;
      tree_ = s.tree_;
      s.tree_ = nullptr;
    }
    return *this;
  }

  set &operator=(const set &s) {
    if (this != &s) {
      set tmp(s);
      *this = std::move(tmp);
    }
    return *this;
  }

  ~set() { delete tree_; }

  // Set Iterators

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

  // Set Capacity

  bool empty() const noexcept { return tree_->Empty(); }

  size_type size() const noexcept { return tree_->Size(); }

  size_type max_size() const noexcept { return tree_->MaxSize(); }

  // Set Modifiers

  void clear() noexcept { tree_->Clear(); }

  std::pair<iterator, bool> insert(const value_type &value) {
    std::pair<tr_iter, bool> pair = tree_->AddNode(value, value);
    iterator tmp(pair.first);
    std::pair<iterator, bool> result(tmp, pair.second);
    return result;
  }

  void erase(iterator pos) { tree_->DeleteNode(*pos); }

  void swap(set &other) noexcept {
    tree_type *tmp = tree_;
    tree_ = other.tree_;
    other.tree_ = tmp;
  }

  void merge(set &other) {
    if (this != &other) {
      if (tree_ == nullptr || tree_->Size() == 0) {
        swap(other);
      } else {
        tree_->Merge(*other.tree_);
      }
    }
  }

  // Set Lookup

  iterator find(const Key &key) {
    iterator itr(tree_->Find(key));
    return itr;
  }

  const_iterator find(const Key &key) const {
    const_iterator itr(tree_->Find(key));
    return itr;
  }

  bool contains(const Key &key) const { return tree_->Contains(key); }

  // Set insert_many

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
  template <typename T>
  class SetIterator {
   public:
    SetIterator() = default;

    SetIterator(const tr_iter &other) { itr_ = other; }

    SetIterator(const SetIterator &other) { itr_ = other.itr_; }

    SetIterator &operator=(const SetIterator &other) {
      itr_ = other.itr_;
      return *this;
    }

    const T &operator*() { return (*itr_).first; }

    SetIterator &operator++() {
      ++itr_;
      return *this;
    }

    SetIterator &operator--() {
      --itr_;
      return *this;
    }

    bool operator==(const SetIterator &other) { return itr_ == other.itr_; }

    bool operator!=(const SetIterator &other) { return itr_ != other.itr_; }

   private:
    tr_iter itr_;
  };

  template <typename T>
  class SetConstIterator {
   public:
    SetConstIterator() = default;

    SetConstIterator(const tr_iter &other) { itr_ = other; }

    SetConstIterator(const SetConstIterator &other) { itr_ = other.itr_; }

    SetConstIterator &operator=(const SetConstIterator &other) {
      itr_ = other.itr_;
      return *this;
    }

    const T &operator*() { return (*itr_).first; }

    SetConstIterator &operator++() {
      ++itr_;
      return *this;
    }

    SetConstIterator &operator--() {
      --itr_;
      return *this;
    }

    bool operator==(const SetConstIterator &other) {
      return itr_ == other.itr_;
    }

    bool operator!=(const SetConstIterator &other) {
      return itr_ != other.itr_;
    }

   private:
    tr_iter itr_;
  };
};
}  // namespace s21

#endif