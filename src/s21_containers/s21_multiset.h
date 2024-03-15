#ifndef S21_MULTISET_H_

#define S21_MULTISET_H_

#include "s21_tree.h"
#include "s21_vector.h"

namespace s21 {
template <typename Key, typename Compare = std::less<Key>>
class multiset {
 private:
  using tree_type = s21::BinaryTree<Key, Key, Compare, true>;
  using tr_iter = typename tree_type::tree_iterator;

  template <typename T>
  class MultisetIterator;

  template <typename T>
  class MultisetConstIterator;

 public:
  //  Multiset Member type

  using key_type = Key;
  using value_type = Key;
  using reference = value_type &;
  using const_reference = const value_type &;
  using iterator = MultisetIterator<Key>;
  using const_iterator = MultisetConstIterator<Key>;
  using size_type = size_t;

  // Multiset Member functions

  multiset() { tree_ = new tree_type(); }

  multiset(const multiset &ms) {
    tree_ = new tree_type();
    try {
      *tree_ = *(ms.tree_);
    } catch (...) {
      delete tree_;
      throw;
    }
  }

  multiset(multiset &&ms) noexcept : tree_(ms.tree_) { ms.tree_ = nullptr; }

  multiset(std::initializer_list<value_type> const &items) {
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

  multiset &operator=(multiset &&ms) noexcept {
    if (this != &ms) {
      clear();
      delete tree_;
      tree_ = ms.tree_;
      ms.tree_ = nullptr;
    }
    return *this;
  }

  multiset &operator=(const multiset &ms) {
    if (this != &ms) {
      multiset tmp(ms);
      *this = std::move(tmp);
    }
    return *this;
  }

  ~multiset() { delete tree_; }

  // Multiset Iterators

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

  //   Multiset Capacity

  bool empty() const noexcept { return tree_->Empty(); }

  size_type size() const noexcept { return tree_->Size(); }

  size_type max_size() const noexcept { return tree_->MaxSize(); }

  //   Multiset Modifiers

  void clear() noexcept { tree_->Clear(); }

  iterator insert(const value_type &value) {
    std::pair<tr_iter, bool> pair = tree_->AddNode(value, value);
    iterator tmp(pair.first);
    return tmp;
  }

  void erase(iterator pos) { tree_->DeleteNode(*pos); }

  void swap(multiset &other) noexcept {
    tree_type *tmp = tree_;
    tree_ = other.tree_;
    other.tree_ = tmp;
  }

  void merge(multiset &other) {
    if (this != &other) {
      if (tree_ == nullptr || tree_->Size() == 0) {
        swap(other);
      } else {
        tree_->Merge(*other.tree_);
      }
    }
  }

  // Multiset Lookup

  size_type count(const Key &key) const { return tree_->Count(key); }

  iterator find(const Key &key) {
    iterator itr(tree_->Find(key));
    return itr;
  }

  const_iterator find(const Key &key) const {
    const_iterator itr(tree_->Find(key));
    return itr;
  }

  bool contains(const Key &key) const noexcept { return tree_->Contains(key); }

  std::pair<iterator, iterator> equal_range(const Key &key) {
    std::pair<tr_iter, tr_iter> pair = tree_->EqualRange(key);
    iterator first_itr(pair.first);
    iterator second_itr(pair.second);
    std::pair<iterator, iterator> result(first_itr, second_itr);
    return result;
  }

  std::pair<const_iterator, const_iterator> equal_range(const Key &key) const {
    std::pair<tr_iter, tr_iter> pair = tree_->EqualRange(key);
    const_iterator first_itr(pair.first);
    const_iterator second_itr(pair.second);
    std::pair<const_iterator, const_iterator> result(first_itr, second_itr);
    return result;
  }

  iterator lower_bound(const Key &key) {
    iterator itr(tree_->LowerBound(key));
    return itr;
  }

  const_iterator lower_bound(const Key &key) const {
    const_iterator itr(tree_->LowerBound(key));
    return itr;
  }

  iterator upper_bound(const Key &key) {
    iterator itr(tree_->UpperBound(key));
    return itr;
  }

  const_iterator upper_bound(const Key &key) const {
    const_iterator itr(tree_->UpperBound(key));
    return itr;
  }

  // Multiset insert_many

  template <typename... Args>
  vector<iterator> insert_many(Args &&...args) {
    vector<iterator> result;
    for (auto item : {std::forward<Args>(args)...}) {
      try {
        iterator pair = insert(item);
        result.push_back(pair);
      } catch (...) {
        for (size_t i = 0; i < result.size(); ++i) {
          iterator tmp = result[i];
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
  class MultisetIterator {
   public:
    MultisetIterator() = default;

    MultisetIterator(const tr_iter &other) { itr_ = other; }

    MultisetIterator(const MultisetIterator &other) { itr_ = other.itr_; }

    MultisetIterator &operator=(const MultisetIterator &other) {
      itr_ = other.itr_;
      return *this;
    }

    const T &operator*() { return (*itr_).first; }

    MultisetIterator &operator++() {
      ++itr_;
      return *this;
    }

    MultisetIterator &operator--() {
      --itr_;
      return *this;
    }

    bool operator==(const MultisetIterator &other) {
      return itr_ == other.itr_;
    }

    bool operator!=(const MultisetIterator &other) {
      return itr_ != other.itr_;
    }

   private:
    tr_iter itr_;
  };

  template <typename T>
  class MultisetConstIterator {
   public:
    MultisetConstIterator() = default;

    MultisetConstIterator(const tr_iter &other) { itr_ = other; }

    MultisetConstIterator(const MultisetConstIterator &other) {
      itr_ = other.itr_;
    }

    MultisetConstIterator &operator=(const MultisetConstIterator &other) {
      itr_ = other.itr_;
      return *this;
    }

    const T &operator*() { return (*itr_).first; }

    MultisetConstIterator &operator++() {
      ++itr_;
      return *this;
    }

    MultisetConstIterator &operator--() {
      --itr_;
      return *this;
    }

    bool operator==(const MultisetConstIterator &other) {
      return itr_ == other.itr_;
    }

    bool operator!=(const MultisetConstIterator &other) {
      return itr_ != other.itr_;
    }

   private:
    tr_iter itr_;
  };
};
}  // namespace s21
#endif