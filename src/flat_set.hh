#include <vector>
#include <algorithm>
#include <functional>

template <
  class Key,
  class Compare = std::less<Key>,
  class Allocator = std::allocator<Key>
  > class flat_set {

  typedef typename std::vector<Key, Allocator>::const_iterator iterator;

public:
  std::vector<Key, Allocator> v_;

  Compare key_compare;
  Allocator allocator_type;

  explicit flat_set (const Compare& comp = key_compare(),
                const Allocator& alloc = allocator_type())
    : key_compare(comp)
    , allocator_type(allocator_type)
    {
      v_ = new std::vector<Key, Allocator>();
    }

  explicit flat_set (const Allocator& alloc)
  : allocator_type(alloc)
    {
      v_ = new std::vector<Key, Allocator>();
    }

  template <class InputIterator>
  flat_set (InputIterator first, InputIterator last,
       const Compare& comp = key_compare(),
       const Allocator& alloc = allocator_type())
    : v_(alloc)
    , key_compare(comp)
    {
      v_.insert(v_.begin(), first, last);
      std::sort(v_.begin(), v_.end(), comp);
    }

  flat_set (const flat_set& x)
  : v_(x.v_)
  , key_compare(x.key_compare)
    {}

  flat_set (const flat_set& x, const Allocator& alloc)
    : v_(x.v_)
    , key_compare(x.key_compare)
    , allocator_type(x.allocator_type)
    {}

  flat_set (flat_set&& x)
  : v_(std::forward<
         std::vector<Key, Allocator>
         >(x.v_))
  , key_compare(x.key_compare)
    {}

  flat_set (flat_set&& x, const Allocator& alloc)
  : v_(std::forward<
         std::vector<Key, Allocator>
         >(x.v_))
  , key_compare(x.key_compare)
  , allocator_type(x.allocator_type)
    {}

  flat_set (initializer_list<value_type> il,
       const Compare& comp = key_compare(),
       const Allocator& alloc = allocator_type())
    : v_(alloc)
    , key_compare(comp)
    {
      v_.insert(v_.begin(), il.begin(), il.end());
      std::sort(v_.begin(), v_.end(), comp);
    }

  flat_set& operator= (const flat_set& x)
    {
      v_ = x.v_;
      return *this;
    }

  flat_set& operator= (flat_set&& x)
    {
      this->clear();
      this->swap(x);
      return *this;
    }

  flat_set& operator= (initializer_list<value_type> il)
    {
      this->clear();
      this->insert(il.begin(), il.end());
      std::sort(v_.begin(), v_.end(), key_compare);
    }

  Compare key_comp() const
    { return key_compare; }
  Compare value_comp() const
    { return key_compare; }
  Allocator get_allocator()
    { return allocator_type; }

  std::vector<Key, Allocator>::const_iterator begin()
    { return v_.begin(); }

  std::vector<Key, Allocator>::const_iterator end()
    { return v_.end(); }

  std::vector<Key, Allocator>::const_iterator rbegin()
    { return v_.rbegin(); }

  std::vector<Key, Allocator>::const_iterator rend()
    { return v_.rend(); }

  std::vector<Key, Allocator>::const_iterator cbegin()
    { return v_.cbegin(); }

  std::vector<Key, Allocator>::const_iterator cend()
    { return v_.cend(); }

  std::vector<Key, Allocator>::const_iterator crbegin()
    { return v_.crbegin(); }

  std::vector<Key, Allocator>::const_iterator crend()
    { return v_.crend(); }

  bool empty() const
    { return v_.empty(); }

  std::vector<Key, Allocator>::size_type size() const
    { return v_.size(); }

  std::vector<Key, Allocator>::size_type max_size() const
    { return v_.max_size(); }

  void swap(flat_set& x)
    { v_.swap(x.v_); }

  std::pair<iterator, bool>
  insert(const Key x)
    {
      std::pair<iterator, bool> p = v_.insert(x);
      std::sort(v_.begin(), v_.end(), key_compare);
      return std::pair<iterator, bool>(p.first, p.second);
    }

  iterator
  insert(iterator pos, const Key& x)
    {
      iterator i = v_.insert(pos, x);
      std::sort(v_.begin(), v_.end(), key_compare);
      return i;
    }

  template <typename InputIterator>
  void insert(InputIterator first, InputIterator last)
    {
      v_.insert(v_.begin(), first, last);
      std::sort(v_.begin(), v_.end(), key_compare);
    }

  void insert(initializer_list<Key> l)
    { this->insert(l.begin(), l.end()); }

  void erase(iterator pos)
    { v_.erase(pos); }

  std::vector<Key, Allocator>::size_type
  erase(const Key& x)
    { this->erase(this->find(x)); }

  void erase(iterator first, iterator last)
    { v_.erase(first, last); }

  void clear()
    { v_.clear(); }

  std::vector<Key, Allocator>::size_type
  count(const Key& x) const
    { return find(x) == v_.end() ? 0 : 1; }

  iterator find(const Key& x)
    { return std::find(v_.begin(), v_.end(), x); }

  iterator find(const Key& x) const
    { return std::find(v_.begin(), v_.end(), x); }

  iterator lower_bound(const Key& x)
    { return std::lower_bound(v_.begin(), v_.end(), x); }

  iterator lower_bound(const Key& x) const
    { return std::lower_bound(v_.begin(), v_.end(), x); }

  iterator upper_bound(const Key& x)
    { return std::upper_bound(v_.begin(), v_.end(), x); }

  iterator upper_bound(const Key& x) const
    { return std::upper_bound(v_.begin(), v_.end(), x); }

  std::pair<iterator, iterator>
  equal_range(const Key& x)
    { return std::make_pair(lower_bound(x), upper_bound(x)); }

  std::pair<iterator, iterator>
  equal_range(const Key& x) const
    { return std::make_pair(lower_bound(x), upper_bound(x)); }

};
