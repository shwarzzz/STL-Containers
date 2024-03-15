#ifndef S21_TREE_H_

#define S21_TREE_H_

#include <functional>
#include <limits>

namespace s21 {

template <typename Key, typename T = Key, typename Comparator = std::less<Key>,
          bool IsMulty = false>
class BinaryTree {
 private:
  class Node;
  class TreeIterator;

 public:
  // Tree Member type

  using node = Node;
  using size_type = size_t;
  using key_value = Key;
  using const_key_value = const Key&;
  using value_type = T;
  using reference = value_type&;
  using const_reference = const value_type&;
  using tree_iterator = TreeIterator;

  // Tree Member functions

  BinaryTree() {
    root_ = nullptr;
    size_ = 0;
  }

  BinaryTree(const BinaryTree& other) : size_(other.size_) {
    root_ = CopyTree(other.root_, root_);
  }

  BinaryTree(BinaryTree&& other) : root_(other.root_), size_(other.size_) {
    other.root_ = nullptr;
    other.size_ = 0;
  }

  BinaryTree& operator=(BinaryTree&& other) {
    Clear();
    root_ = other.root_;
    size_ = other.size_;
    other.root_ = nullptr;
    other.size_ = 0;
    return *this;
  }

  BinaryTree& operator=(const BinaryTree& other) {
    BinaryTree tmp(other);
    *this = std::move(tmp);
    return *this;
  }

  ~BinaryTree() { Clear(); }

  // Tree Iterators

  tree_iterator Begin() {
    if (root_ != nullptr) {
      tree_iterator itr = BinaryTree::GetGlobalMin(root_);
      return itr;
    }
    tree_iterator itr(nullptr);
    return itr;
  }

  tree_iterator End() {
    if (root_ != nullptr) {
      tree_iterator itr(BinaryTree::GetGlobalMax(root_)->right_,
                        BinaryTree::GetGlobalMax(root_));
      return itr;
    }
    tree_iterator itr(nullptr);
    return itr;
  }

  // Tree Capacity

  bool Empty() const noexcept { return root_ == nullptr; }

  size_type Size() const noexcept { return size_; }

  size_type MaxSize() const noexcept {
    return (std::numeric_limits<size_type>::max() / 2) / (sizeof(node));
  }

  // Tree Modifiers

  void Clear() noexcept {
    DestroyTree(root_);
    root_ = nullptr;
    size_ = 0;
  }

  std::pair<tree_iterator, bool> AddNode(const_key_value key,
                                         const_reference value) {
    node** current = &root_;
    node* parent = *current;
    bool is_inserted = true;
    while (*current != nullptr &&
           (IsMulty == true || !std::equal_to<Key>()(key, *(**current).key_))) {
      parent = *current;
      node& cur_node = **current;
      if (Comparator()(key, *cur_node.key_)) {
        current = &cur_node.left_;
      } else {
        current = &cur_node.right_;
      }
    }
    if (*current == nullptr) {
      node tmp(value, key, parent);
      *current = (node*)::operator new(sizeof(node));
      try {
        new (*current) node(tmp);
      } catch (...) {
        ::operator delete(*current);
        throw;
      }
      size_++;
    } else {
      is_inserted = false;
    }
    UpdateTreeHeight(*current);
    tree_iterator itr(*current);
    std::pair<tree_iterator, bool> pair(itr, is_inserted);
    return pair;
  }

  std::pair<tree_iterator, bool> EmplaceNode(const_key_value key,
                                             const_reference value) {
    std::pair<tree_iterator, bool> res = AddNode(key, value);
    if (res.second == false) {
      node* tmp = res.first.GetNode();
      tmp->value_->~value_type();
      new (tmp->value_) value_type(value);
    }
    return res;
  }

  void DeleteNode(const_key_value elem) {
    node* ptr = root_;
    while (ptr != nullptr && !std::equal_to<Key>()(elem, *(ptr->key_))) {
      if (Comparator()(elem, *ptr->key_)) {
        ptr = ptr->left_;
      } else {
        ptr = ptr->right_;
      }
    }
    if (ptr) {
      SwapBeforeDelete(ptr);
      if (ptr == root_) {
        root_ = nullptr;
      }
      ptr->~Node();
      ::operator delete(ptr);
    }
  }

  void Merge(BinaryTree& other) {
    tree_iterator itr = other.Begin();
    while (itr != other.End()) {
      std::pair<tree_iterator, bool> pair = FindPointer((*itr).first);
      if (!pair.second) {
        node* tmp = itr.GetNode();
        node* ptr = pair.first.GetNode();
        ++itr;
        other.SwapBeforeDelete(tmp);
        if (Comparator()(*(tmp->key_), *(ptr->key_))) {
          ptr->left_ = tmp;
        } else {
          ptr->right_ = tmp;
        }
        tmp->prev_ = ptr;
        size_++;
      } else {
        ++itr;
      }
    }
    if (other.size_ == 0) {
      other.root_ = nullptr;
    }
  }

  std::pair<tree_iterator, bool> FindPointer(const_key_value key) {
    bool is_exits = true;
    node* parent = nullptr;
    node* ptr = root_;
    while (ptr != nullptr &&
           (IsMulty == true || !std::equal_to<Key>()(key, *ptr->key_))) {
      parent = ptr;
      if (Comparator()(key, *ptr->key_)) {
        ptr = ptr->left_;
      } else {
        ptr = ptr->right_;
      }
    }
    if (!ptr) {
      is_exits = false;
    }
    tree_iterator tmp(parent);
    std::pair<tree_iterator, bool> pair(tmp, is_exits);
    return pair;
  }

  void SwapBeforeDelete(node* ptr) {
    node* change = FindNodeToReplace(ptr);
    ptr->Swap(change);
    node* tmp = ptr->prev_;
    UpdateRoot();
    ptr->ClearPrevPointer();
    UpdateTreeHeight(tmp);
    size_--;
  }

  // Tree Lookup

  size_type Count(const Key& key) {
    size_type count = 0;
    tree_iterator itr = LowerBound(key);
    tree_iterator end = End();
    for (; itr != end && std::equal_to()((*itr).first, key); ++itr) {
      ++count;
    }
    return count;
  }

  tree_iterator Find(const Key& key) {
    node* ptr = root_;
    while (ptr != nullptr && !std::equal_to<Key>()(key, *ptr->key_)) {
      if (Comparator()(key, *ptr->key_)) {
        ptr = ptr->left_;
      } else {
        ptr = ptr->right_;
      }
    }
    if (ptr == nullptr) {
      return End();
    }
    tree_iterator itr(ptr);
    return itr;
  }

  bool Contains(const Key& key) { return Find(key) != End(); }

  tree_iterator LowerBound(const Key& key) {
    tree_iterator end = End();
    tree_iterator itr = end;
    for (tree_iterator i = Begin(); i != end; ++i) {
      if (std::equal_to<Key>()((*i).first, key) ||
          !Comparator()((*i).first, key)) {
        itr = i;
        break;
      }
    }
    return itr;
  }

  tree_iterator UpperBound(const Key& key) {
    tree_iterator end = End();
    tree_iterator itr = end;
    for (tree_iterator i = Begin(); i != end; ++i) {
      if (!std::equal_to<Key>()((*i).first, key) &&
          !Comparator()((*i).first, key)) {
        itr = i;
        break;
      }
    }
    return itr;
  }

  std::pair<tree_iterator, tree_iterator> EqualRange(const Key& key) {
    tree_iterator end = End();
    tree_iterator first_itr = end;
    tree_iterator second_itr = end;
    bool first_flag = false;
    bool second_flag = false;
    for (tree_iterator i = Begin(); i != end; ++i) {
      if (std::greater_equal<Key>()((*i).first, key)) {
        if (!first_flag || std::less<Key>()((*i).first, (*first_itr).first)) {
          first_itr = i;
          first_flag = true;
        }
      }
      if (std::greater<Key>()((*i).first, key)) {
        if (!second_flag || std::less<Key>()((*i).first, (*second_itr).first)) {
          second_itr = i;
          second_flag = true;
        }
      }
    }
    std::pair<tree_iterator, tree_iterator> pair(first_itr, second_itr);
    return pair;
  }

 private:
  static node* GetGlobalMax(node* current) {
    node* max = current;
    while (max->prev_ != nullptr) {
      max = max->prev_;
    }
    return BinaryTree::GetLocalMax(max);
  }

  static node* GetLocalMax(node* current) {
    node* max = current;
    while (max->right_ != nullptr) {
      max = max->right_;
    }
    return max;
  }

  static node* GetGlobalMin(node* current) {
    node* min = current;
    while (min->prev_ != nullptr) {
      min = min->prev_;
    }
    return BinaryTree::GetLocalMin(min);
  }

  static node* GetLocalMin(node* current) {
    node* min = current;
    while (min->left_ != nullptr) {
      min = min->left_;
    }
    return min;
  }

  node* CopyTree(node* src, node* dst) {
    node* ptr = nullptr;
    if (src) {
      try {
        ptr = (node*)::operator new(sizeof(node));
      } catch (...) {
        Clear();
        throw;
      }
      try {
        new (ptr) node(*src);
      } catch (...) {
        ::operator delete(ptr);
        Clear();
        throw;
      }
      dst = ptr;
      dst->left_ = CopyTree(src->left_, dst->left_);
      dst->right_ = CopyTree(src->right_, dst->right_);
    }
    return ptr;
  }

  void DestroyTree(node* elem) noexcept {
    if (elem) {
      DestroyTree(elem->left_);
      DestroyTree(elem->right_);
      elem->~node();
      ::operator delete(elem);
    }
  }

  void UpdateTreeHeight(node* elem) {
    node* ptr = elem;
    while (ptr != nullptr) {
      UpdateNodeHeight(ptr);
      Balancing(ptr);
      ptr = ptr->prev_;
    }
  }

  node* FindNodeToReplace(node* ptr) const {
    node* change = ptr;
    if (change->left_ == nullptr && change->right_ == nullptr) {
      return change;
    } else if (change->left_ == nullptr || change->right_ == nullptr) {
      return change->left_ == nullptr ? change->right_ : change->left_;
    }
    return BinaryTree::GetLocalMax(change->left_);
  }

  int GetBalance(node* ptr) {
    return ptr == nullptr ? 0 : GetHeight(ptr->right_) - GetHeight(ptr->left_);
  }

  int GetHeight(node* ptr) { return ptr == nullptr ? -1 : ptr->height_; }

  void UpdateNodeHeight(node* ptr) {
    ptr->height_ = std::max(GetHeight(ptr->left_), GetHeight(ptr->right_)) + 1;
  }

  void RotateRight(node* ptr) {
    ptr->Swap(ptr->left_);
    ptr = ptr->prev_;
    node* tmp = ptr->right_;
    ptr->right_ = ptr->left_;
    ptr->left_ = ptr->right_->left_;
    ptr->right_->left_ = ptr->right_->right_;
    ptr->right_->right_ = tmp;
    if (ptr->left_ != nullptr) {
      ptr->left_->prev_ = ptr;
    }
    if (tmp != nullptr) {
      tmp->prev_ = ptr->right_;
    }
    UpdateNodeHeight(ptr->right_);
    UpdateNodeHeight(ptr);
  }

  void RotateLeft(node* ptr) {
    ptr->Swap(ptr->right_);
    ptr = ptr->prev_;
    node* tmp = ptr->left_;
    ptr->left_ = ptr->right_;
    ptr->right_ = ptr->left_->right_;
    ptr->left_->right_ = ptr->left_->left_;
    ptr->left_->left_ = tmp;
    if (ptr->right_ != nullptr) {
      ptr->right_->prev_ = ptr;
    }
    if (tmp != nullptr) {
      tmp->prev_ = ptr->left_;
    }
    UpdateNodeHeight(ptr->left_);
    UpdateNodeHeight(ptr);
  }

  void Balancing(node* ptr) {
    int balance = GetBalance(ptr);
    if (balance == -2) {
      if (GetBalance(ptr->left_) == 1) {
        RotateLeft(ptr->left_);
      }
      RotateRight(ptr);
      UpdateRoot();
    } else if (balance == 2) {
      if (GetBalance(ptr->right_) == -1) {
        RotateRight(ptr->right_);
      }
      RotateLeft(ptr);
      UpdateRoot();
    }
  }

  void UpdateRoot() {
    if (root_) {
      for (; root_->prev_ != nullptr;) {
        root_ = root_->prev_;
      }
    }
  }

 private:
  size_type size_ = 0;
  node* root_ = nullptr;

 private:
  class Node {
   public:
    using node_value_type = T;
    using node_key_type = Key;

    using const_node_key_value = const Key&;
    using node_key_pointer = Key*;

    using node_value_reference = T&;
    using const_node_value_reference = const T&;
    using node_value_pointer = T*;

    node_value_pointer value_;
    node_key_pointer key_;
    size_type height_;
    Node* prev_;
    Node* left_;
    Node* right_;

    Node() noexcept {
      value_ = nullptr;
      key_ = nullptr;
      height_ = 0;
      prev_ = nullptr;
      left_ = nullptr;
      right_ = nullptr;
    }

    Node(const_node_value_reference val, const_node_key_value key,
         Node* parent) {
      CreateObjects(val, key);
      height_ = 0;
      prev_ = parent;
      left_ = nullptr;
      right_ = nullptr;
    }

    Node(const Node& other)
        : height_(other.height_),
          prev_(other.prev_),
          left_(other.left_),
          right_(other.right_) {
      CreateObjects(*other.value_, *other.key_);
    }

    Node(Node&& other)
        : key_(other.key_),
          value_(other.value_),
          left_(other.left_),
          right_(other.right_),
          prev_(other.prev_),
          height_(other.height_) {
      other.value_ = nullptr;
      other.key_ = nullptr;
      other.left_ = nullptr;
      other.right_ = nullptr;
      other.prev_ = nullptr;
    }

    ~Node() {
      height_ = 0;
      left_ = nullptr;
      right_ = nullptr;
      DeleteNodeObjects();
    }

    Node& operator=(const Node& other) {
      DeleteNodeObjects();
      CreateObjects(other.value_, other.key_);
      return *this;
    }

    Node& operator=(Node&& other) {
      Node tmp = std::move(other);
      DeleteNodeObjects();
      Swap(tmp);
      return *this;
    }

    void Swap(Node* other) {
      SwapPointers(other);
      SwapChildPointers();
      other->SwapChildPointers();
      SwapPrevPointers(other);
      other->SwapPrevPointers(this);
      size_type tmp = height_;
      height_ = other->height_;
      other->height_ = tmp;
    }

    void SwapValues(Node* other) {
      node_key_pointer key_tmp = key_;
      node_value_pointer value_tmp = value_;
      key_ = other->key_;
      value_ = other->value_;
      other->key_ = key_tmp;
      other->value_ = value_tmp;
    }

    void SwapPointers(Node* other) {
      node* left_tmp = left_;
      node* right_tmp = right_;
      node* prev_tmp = prev_;
      left_ = other->left_;
      right_ = other->right_;
      prev_ = other->prev_;
      other->left_ = left_tmp;
      other->right_ = right_tmp;
      other->prev_ = prev_tmp;
      CheckPointers(other);
      other->CheckPointers(this);
    }

    void CheckPointers(Node* other) {
      if (left_ == this) {
        left_ = other;
      } else if (right_ == this) {
        right_ = other;
      } else if (prev_ == this) {
        prev_ = other;
      }
    }

    void SwapPrevPointers(Node* other) {
      if (prev_ != nullptr) {
        if (prev_->left_ == other) {
          prev_->left_ = this;
        } else if (prev_->right_ == other) {
          prev_->right_ = this;
        }
      }
    }

    void SwapChildPointers() {
      if (right_) {
        right_->prev_ = this;
      }
      if (left_) {
        left_->prev_ = this;
      }
    }

    void ClearPrevPointer() {
      if (prev_ != nullptr) {
        if (this == prev_->right_) {
          prev_->right_ = nullptr;
        } else {
          prev_->left_ = nullptr;
        }
      }
      prev_ = nullptr;
    }

   private:
    void CreateObjects(const_node_value_reference val,
                       const_node_key_value key) {
      value_ = (node_value_pointer)::operator new(sizeof(val));
      try {
        new (value_) T(val);
      } catch (...) {
        ::operator delete(value_);
        throw;
      }
      key_ = (node_key_pointer)::operator new(sizeof(key));
      try {
        new (key_) Key(key);
      } catch (...) {
        ::operator delete(value_);
        value_->~node_value_type();
        ::operator delete(key_);
        throw;
      }
    }

    void DeleteNodeObjects() {
      value_->~node_value_type();
      key_->~node_key_type();
      ::operator delete(value_);
      ::operator delete(key_);
    }
  };

  class TreeIterator {
   public:
    TreeIterator() {
      elem_ = nullptr;
      last_ = nullptr;
      leftmost_ = nullptr;
      rightmost_ = nullptr;
    }

    TreeIterator(const TreeIterator& other) {
      elem_ = other.elem_;
      last_ = other.last_;
      leftmost_ = other.leftmost_;
      rightmost_ = other.rightmost_;
    }

    TreeIterator& operator=(const TreeIterator& other) {
      elem_ = other.elem_;
      last_ = other.last_;
      leftmost_ = other.leftmost_;
      rightmost_ = other.rightmost_;
      return *this;
    }

    TreeIterator(node* elem) {
      elem_ = elem;
      last_ = nullptr;
      leftmost_ = nullptr;
      rightmost_ = nullptr;
    }

    TreeIterator(node* elem, node* parent) {
      elem_ = elem;
      last_ = parent;
      leftmost_ = nullptr;
      rightmost_ = nullptr;
    }

    TreeIterator& operator++() {
      if (elem_ == nullptr && last_ != nullptr) {
        CheckMinMax(last_);
        last_ = elem_;
        elem_ = leftmost_;
      } else {
        if (elem_->right_ != nullptr && last_ != elem_->right_) {
          last_ = elem_;
          elem_ = elem_->right_;
          while (elem_->left_ != nullptr) {
            last_ = elem_;
            elem_ = elem_->left_;
          }
        } else {
          CheckMinMax(elem_);
          if (elem_ == rightmost_) {
            last_ = elem_;
            elem_ = elem_->right_;
          } else {
            node* tmp = elem_;
            while (elem_->prev_ != nullptr && !CheckStop(tmp)) {
              last_ = elem_;
              elem_ = elem_->prev_;
            }
            if (elem_->prev_ != nullptr) {
              last_ = elem_;
              elem_ = elem_->prev_;
            }
          }
        }
      }
      return *this;
    }

    TreeIterator& operator--() {
      if (elem_ == nullptr && last_ != nullptr) {
        CheckMinMax(last_);
        elem_ = rightmost_;
      } else if (elem_->left_ != nullptr && last_ != elem_->left_) {
        last_ = elem_;
        elem_ = elem_->left_;
        while (elem_->right_ != nullptr) {
          last_ = elem_;
          elem_ = elem_->right_;
        }
      } else {
        CheckMinMax(elem_);
        if (elem_ == leftmost_) {
          last_ = elem_;
          elem_ = elem_->left_;
        } else {
          node* tmp = elem_;
          while (elem_->prev_ != nullptr && CheckStop(tmp)) {
            last_ = elem_;
            elem_ = elem_->prev_;
          }
          if (elem_->prev_ != nullptr) {
            last_ = elem_;
            elem_ = elem_->prev_;
          }
        }
      }
      return *this;
    }

    std::pair<const_key_value, reference> operator*() {
      std::pair<const_key_value, reference> pair(*(elem_->key_),
                                                 *(elem_->value_));
      return pair;
    }

    bool operator==(const tree_iterator& other) { return elem_ == other.elem_; }

    bool operator!=(const tree_iterator& other) { return elem_ != other.elem_; }

    node* GetNode() { return elem_; }

   private:
    node* leftmost_;
    node* rightmost_;
    node* elem_;
    node* last_;

    void CheckMinMax(node* current) {
      if (leftmost_ == nullptr || leftmost_->left_ != nullptr) {
        leftmost_ = BinaryTree::GetGlobalMin(current);
      }
      if (rightmost_ == nullptr || rightmost_->right_ != nullptr) {
        rightmost_ = BinaryTree::GetGlobalMax(current);
      }
    }

    bool CheckStop(node* tmp) {
      bool is_stopped = false;
      if (!Comparator()(*elem_->prev_->key_, *tmp->key_)) {
        if (std::equal_to()(*elem_->prev_->key_, *tmp->key_)) {
          if (elem_->prev_->right_ != nullptr) {
            if (!Comparator()(*elem_->prev_->right_->key_, *tmp->key_)) {
              if (elem_->prev_->right_ != elem_) {
                is_stopped = true;
              }
            }
          } else if (elem_->prev_->left_ != nullptr) {
            if (!Comparator()(*elem_->prev_->left_->key_, *tmp->key_)) {
              if (elem_->prev_->left_ != elem_) {
                is_stopped = true;
              }
            }
          }
        } else {
          is_stopped = true;
        }
      }
      return is_stopped;
    }
  };
};
};  // namespace s21
#endif