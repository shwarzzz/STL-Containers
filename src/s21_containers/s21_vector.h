#ifndef S21_VECTOR_H_

#define S21_VECTOR_H_

namespace s21 {

template <typename T>
class vector {
 private:
  template <typename IT>
  class VectorIterator;

  template <typename IT>
  class VectorConstIterator;

 public:
  // Vector member type

  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using iterator = VectorIterator<value_type>;
  using const_iterator = VectorConstIterator<value_type>;
  using size_type = size_t;

  // Vector Member functions

  vector() noexcept {
    arr_ = nullptr;
    size_ = 0;
    capacity_ = 0;
  }

  vector(size_type n) {
    capacity_ = 0;
    size_ = 0;
    resize(n);
  }

  vector(const vector &other) : size_(other.size_), capacity_(other.capacity_) {
    size_type i = 0;
    try {
      arr_ = (T *)::operator new(capacity_ * sizeof(T));
      for (; i < size_; ++i) {
        new (arr_ + i) T(other.arr_[i]);
      }
    } catch (...) {
      for (size_type j = 0; j < i; ++j) {
        arr_[i].~T();
      }
      ::operator delete(arr_);
      throw;
    }
  }

  vector(vector &&other) noexcept
      : arr_(other.arr_), size_(other.size_), capacity_(other.capacity_) {
    other.arr_ = nullptr;
    other.size_ = 0;
    other.capacity_ = 0;
  }

  vector(std::initializer_list<value_type> const &items) {
    arr_ = (T *)::operator new(sizeof(T) * items.size());
    size_type index = 0;
    for (auto i = items.begin(); i != items.end(); ++i, ++index) {
      try {
        new (arr_ + index) T(*i);
      } catch (...) {
        for (size_type j = 0; j < index; ++j) {
          arr_[j].~T();
        }
        ::operator delete(arr_);
        throw;
      }
    }
    size_ = items.size();
    capacity_ = size_;
  }

  vector &operator=(const vector &other) {
    if (this != &other) {
      vector tmp(other);
      swap(tmp);
    }
    return *this;
  }

  vector &operator=(vector &&other) noexcept {
    if (this != &other) {
      DestroyAll();
      arr_ = other.arr_;
      size_ = other.size_;
      capacity_ = other.capacity_;
      other.arr_ = nullptr;
      other.size_ = 0;
      other.capacity_ = 0;
    }
    return *this;
  }

  ~vector() { DestroyAll(); }

  // Vector Element access

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

  T *data() noexcept {
    T *result = arr_;
    return result;
  }

  const T *data() const noexcept {
    const T *result = arr_;
    return result;
  }

  // Vector Iterators

  iterator begin() {
    iterator result(arr_);
    return result;
  }

  const_iterator begin() const {
    const_iterator result(arr_);
    return result;
  }

  iterator end() {
    iterator result(arr_ + size_);
    return result;
  }

  const_iterator end() const {
    const_iterator result(arr_ + size_);
    return result;
  }

  // Vector Capacity

  bool empty() const noexcept { return size_ == 0; }

  size_type max_size() const noexcept {
    return (std::numeric_limits<size_type>::max() / 2) / sizeof(T);
  }

  size_type size() const noexcept { return size_; }

  void reserve(size_type n) {
    if (n <= capacity_) {
      return;
    } else {
      T *new_arr = (T *)::operator new(n * sizeof(T));
      CopyData(new_arr);
      size_type tmp = size_;
      DestroyObjects();
      size_ = tmp;
      arr_ = new_arr;
      capacity_ = n;
    }
  }

  size_type capacity() const noexcept { return capacity_; }

  void shrink_to_fit() {
    if (size_ < capacity_) {
      T *new_arr = (T *)::operator new(size_ * sizeof(T));
      CopyData(new_arr);
      size_type tmp = size_;
      DestroyObjects();
      size_ = tmp;
      arr_ = new_arr;
      capacity_ = size_;
    }
  }

  void resize(size_type n, const T &value = T()) {
    if (size_ == n) {
      return;
    }
    if (n > max_size()) {
      throw std::length_error(
          "Error: The size requested is greater than the maximum size!");
    }
    if (capacity_ < n) {
      reserve(n);
      for (size_type i = size_; i < n; ++i) {
        try {
          new (arr_ + i) T(value);
        } catch (...) {
          for (size_type j = size_; j < i; ++j) {
            arr_[j].~T();
          }
          throw;
        }
      }
    } else {
      for (size_type i = size_; i >= n; --i) {
        arr_[i].~T();
      }
    }
    size_ = n;
  }

  // Vector Modifiers

  void clear() noexcept {
    for (size_type i = 0; i < size_; ++i) {
      arr_[i].~T();
    }
    size_ = 0;
  }

  iterator insert(iterator pos, const_reference value) {
    if (pos == end()) {
      push_back(value);
      iterator result(arr_ + size_ - 1);
      return result;
    }
    size_type zero = capacity_ == 0 ? 1 : 0;
    T *new_arr = (T *)::operator new(2 * capacity_ * sizeof(T) + zero);
    size_type j = 0;
    size_type new_pos = 0;
    for (iterator i = begin(); i != end(); ++i) {
      try {
        if (i == pos) {
          new (new_arr + j) T(value);
          new_pos = j;
          j++;
        }
        new (new_arr + j) T(*i);
        j++;
      } catch (...) {
        for (size_type k = 0; k < j; ++k) {
          new_arr[k].~T();
        }
        ::operator delete(new_arr);
        throw;
      }
    }
    size_type tmp = size_;
    DestroyObjects();
    size_ = tmp;
    arr_ = new_arr;
    capacity_ = capacity_ * 2 + zero;
    size_++;
    iterator result(arr_ + new_pos);
    return result;
  }

  void erase(iterator pos) {
    T *new_arr = (T *)::operator new(capacity_ * sizeof(T));
    size_type j = 0;
    for (iterator i = begin(); i != end(); ++i) {
      try {
        if (i == pos) {
          continue;
        }
        new (new_arr + j) T(*i);
        j++;
      } catch (...) {
        for (size_type k = 0; k < j; ++k) {
          new_arr[k].~T();
        }
        ::operator delete(new_arr);
        throw;
      }
    }
    DestroyObjects();
    arr_ = new_arr;
    size_ = j;
  }

  void push_back(const_reference value) {
    if (capacity_ == 0) {
      reserve(1);
    } else if (size_ == capacity_) {
      reserve(2 * capacity_);
    }
    new (arr_ + size_) T(value);
    size_++;
  }

  void pop_back() {
    size_--;
    arr_[size_].~T();
  }

  void swap(vector &other) {
    vector tmp = std::move(other);
    other = std::move(*this);
    *this = std::move(tmp);
  }

  // Vector Insert_many

  template <typename... Args>
  iterator insert_many(const iterator pos, Args &&...args) {
    iterator res = pos;
    if (sizeof...(args) > max_size()) {
      throw std::length_error(
          "Error: The size requested is greater than the maximum size!");
    } else if (sizeof...(args) != 0) {
      size_type new_capacity = capacity_;
      while (new_capacity < sizeof...(args) + size_) {
        if (new_capacity != 0) {
          new_capacity *= 2;
        } else {
          new_capacity = 1;
        }
      }
      T *new_arr = (T *)::operator new(new_capacity * sizeof(T));
      size_type index = 0;
      CopyBeforeIterator(pos, new_arr, index);
      AddArgsElements(new_arr, index, args...);
      res = new_arr + index;
      CopyAfterIterator(pos, new_arr, index);
      DestroyObjects();
      arr_ = new_arr;
      capacity_ = new_capacity;
      size_ = index;
    }
    return res;
  }

  template <typename... Args>
  void insert_many_back(Args &&...args) {
    if (size_ + sizeof...(args) > max_size()) {
      throw std::length_error(
          "Error: The size requested is greater than the maximum size!");
    } else {
      size_type new_capacity = capacity_;
      while (new_capacity < sizeof...(args) + size_) {
        if (new_capacity != 0) {
          new_capacity *= 2;
        } else {
          new_capacity = 1;
        }
      }
      T *new_arr = (T *)::operator new(new_capacity * sizeof(T));
      CopyData(new_arr);
      size_type index = size_;
      AddArgsElements(new_arr, index, args...);
      DestroyObjects();
      arr_ = new_arr;
      size_ = index;
      capacity_ = new_capacity;
    }
  }

 private:
  T *arr_;
  size_type size_;
  size_type capacity_;

  template <typename IT>
  class VectorIterator {
   public:
    VectorIterator() { ptr_ = nullptr; }

    VectorIterator(const VectorIterator &other) { ptr_ = other.ptr_; }

    VectorIterator(T *ptr) { ptr_ = ptr; }

    VectorIterator &operator=(const VectorIterator &other) {
      ptr_ = other.ptr_;
      return *this;
    }

    IT &operator*() { return *ptr_; }

    bool operator==(const VectorIterator &other) {
      bool result = false;
      if (ptr_ == other.ptr_) {
        result = true;
      }
      return result;
    }

    bool operator!=(const VectorIterator &other) {
      bool result = false;
      if (ptr_ != other.ptr_) {
        result = true;
      }
      return result;
    }

    VectorIterator &operator++() {
      ptr_++;
      return *this;
    }

    VectorIterator &operator--() {
      ptr_--;
      return *this;
    }

   private:
    IT *ptr_;
  };

  template <typename IT>
  class VectorConstIterator {
   public:
    VectorConstIterator() { ptr_ = nullptr; }

    VectorConstIterator(const VectorConstIterator &other) { ptr_ = other.ptr_; }

    VectorConstIterator(T *ptr) { ptr_ = ptr; }

    VectorConstIterator &operator=(const VectorConstIterator &other) {
      ptr_ = other.ptr_;
      return *this;
    }

    const IT &operator*() { return *ptr_; }

    bool operator==(const VectorConstIterator &other) {
      bool result = false;
      if (ptr_ == other.ptr_) {
        result = true;
      }
      return result;
    }

    bool operator!=(const VectorConstIterator &other) {
      bool result = false;
      if (ptr_ != other.ptr_) {
        result = true;
      }
      return result;
    }

    VectorConstIterator &operator++() {
      ptr_++;
      return *this;
    }

    VectorConstIterator &operator--() {
      ptr_--;
      return *this;
    }

   private:
    IT *ptr_;
  };

  void DestroyObjects() {
    if (capacity_ != 0) {
      clear();
      ::operator delete(arr_);
    }
  }

  void DestroyAll() {
    DestroyObjects();
    arr_ = nullptr;
    size_ = 0;
    capacity_ = 0;
  }

  void CopyData(T *new_arr) {
    for (size_type i = 0; i < size_; ++i) {
      try {
        new (new_arr + i) T(arr_[i]);
      } catch (...) {
        for (size_type j = 0; j < i; ++j) {
          new_arr[j].~T();
        }
        ::operator delete(new_arr);
        throw;
      }
    }
  }

  template <typename... Args>
  void AddArgsElements(T *new_arr, size_type &index, Args &&...args) {
    for (auto item : {std::forward<Args>(args)...}) {
      try {
        new (new_arr + index) T(item);
      } catch (...) {
        for (size_type i = 0; i < index; ++i) {
          new_arr[i].~T();
        }
        ::operator delete(new_arr);
        throw;
      }
      ++index;
    }
  }

  void CopyBeforeIterator(const iterator pos, T *new_arr, size_type &index) {
    iterator end_ = end();
    iterator i(arr_);
    for (; i != pos && i != end_; ++i, ++index) {
      try {
        new (new_arr + index) T(*i);
      } catch (...) {
        for (size_type j = 0; j < index; ++j) {
          new_arr[j].~T();
        }
        ::operator delete(new_arr);
        throw;
      }
    }
  }

  void CopyAfterIterator(const iterator pos, T *new_arr, size_type &index) {
    iterator end_ = end();
    iterator itr = pos;
    for (; itr != end_; ++itr, ++index) {
      try {
        new (new_arr + index) T(*itr);
      } catch (...) {
        for (size_type j = 0; j < index; ++j) {
          new_arr[j].~T();
        }
        ::operator delete(new_arr);
        throw;
      }
    }
  }
};
};  // namespace s21
#endif