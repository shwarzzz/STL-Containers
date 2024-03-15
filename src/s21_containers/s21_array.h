#ifndef S21_ARRAY_H_

#define S21_ARRAY_H_

#include <functional>
#include <limits>
#include <stdexcept>

namespace s21 {
template <typename T, std::size_t N>
class array {
 public:
  //  Array Member type

  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using iterator = T *;
  using const_iterator = const T *;
  using size_type = size_t;

  //   Array Member functions

  array() { size_ = N; }

  array(std::initializer_list<value_type> const &items) {
    size_type index = 0;
    for (auto i = items.begin(); i != items.end(); ++i, ++index) {
      arr_[index] = *i;
    }
  }

  array(const array &a) {
    for (size_type i = 0; i < size_; ++i) {
      arr_[i] = a.arr_[i];
    }
  }

  array(array &&a) {
    for (size_type i = 0; i < size_; ++i) {
      arr_[i] = std::move(a.arr_[i]);
    }
  }

  array &operator=(array &&a) {
    if (this != &a) {
      for (size_type i = 0; i < size_; ++i) {
        arr_[i] = std::move(a.arr_[i]);
      }
    }
    return *this;
  }

  ~array() {}

  //   Array Element access

  reference at(size_type pos) {
    if (pos >= size_) {
      throw std::out_of_range("Error: Index out of range!");
    }
    return arr_[pos];
  }

  const_reference at(size_type pos) const {
    if (pos >= size_) {
      throw std::out_of_range("Error: Index out of range!");
    }
    return arr_[pos];
  }

  reference operator[](size_type pos) { return arr_[pos]; }

  const_reference operator[](size_type pos) const { return arr_[pos]; }

  reference front() { return arr_[0]; }

  const_reference front() const { return arr_[0]; }

  reference back() { return arr_[size_ - 1]; }

  const_reference back() const { return arr_[size_ - 1]; }

  iterator data() { return arr_; }

  const_iterator data() const { return arr_; }

  //   Array Iterators

  iterator begin() { return arr_; }

  const_iterator begin() const { return arr_; }

  iterator end() { return arr_ + size_; }

  const_iterator end() const { return arr_ + size_; }

  //   Array Capacity

  bool empty() const noexcept { return N == 0; }

  size_type size() const noexcept { return size_; }

  size_type max_size() const noexcept { return size_; }

  //   Array Modifiers

  void swap(array &other) {
    for (size_type i = 0; i < size_; ++i) {
      value_type tmp = other.arr_[i];
      other.arr_[i] = arr_[i];
      arr_[i] = tmp;
    }
  }

  void fill(const_reference value) {
    for (size_type i = 0; i < size_; ++i) {
      arr_[i] = value;
    }
  }

 private:
  value_type arr_[N]{};
  size_type size_ = N;
};
}  // namespace s21

#endif