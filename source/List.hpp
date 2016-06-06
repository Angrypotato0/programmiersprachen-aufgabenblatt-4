

#ifndef BUW_LIST_HPP 
#define BUW_LIST_HPP

#include <cstddef> 
#include <utility>

template <typename T>
class List;

template <typename T>
struct ListNode
 {
  ListNode() : m_value {}, m_prev {nullptr}, m_next {nullptr} {}
  ListNode(T const& v, ListNode* prev, ListNode* next) : 
  m_value{v}, m_prev{prev}, m_next{next} {}

  T m_value; 
  ListNode* m_prev; 
  ListNode* m_next; 
};

template <typename T>
struct ListIterator 
{
  typedef ListIterator<T> Self;
  typedef T value_type; 
  typedef T* pointer; 
  typedef T& reference; 
  typedef ptrdiff_t difference_type;
  typedef std::forward_iterator_tag iterator_category;

  friend class List<T>;

  ListIterator() : m_node {nullptr} {}
  ListIterator(ListNode<T>* n) : m_node {n} {}

  reference operator * () const {
    return m_node -> m_value; 
  } 

    
  pointer operator -> () const { 
    return &(m_node -> m_value); 
  } 

    
  Self& operator ++ () {
    if (m_node) {
      m_node = m_node -> m_next; 
    }
    return *this; 
  } 

  Self& operator--() 
    {
      m_node = m_node->m_prev;
      return *this;
    }

     
  Self operator ++ (int) {  
    Self temp = *this; 
    ++(*this);  
    return temp;   
  } 

    
  bool operator == (const Self& x) const { 
    return m_node == x.m_node;
  } 

     
  bool operator != (const Self& x) const {
    return m_node != x.m_node;
  } 

  Self next() const {
    if (m_node)
      return ListIterator(m_node -> m_next);
    else
      return ListIterator(nullptr);
  }

  Self prev() const {
    if (m_node)
      return ListIterator(m_node -> m_prev);
    else
      return ListIterator(nullptr);
  }

private:
     
  ListNode<T>* m_node = nullptr;
};

template <typename T>
struct ListConstIterator {
  friend class List<T>;

private:
  ListNode<T>* m_node = nullptr;
};

template <typename T>
class List {
public: 
  
  typedef T value_type;
  typedef T* pointer;
  typedef const T* const_pointer;
  typedef T& reference; 
  typedef const T& const_reference;
  typedef ListIterator<T> iterator; 
  typedef ListConstIterator<T> const_iterator;

  friend class ListIterator<T>;
  friend class ListConstIterator<T>;

    
  List(): m_size {0}, m_first {nullptr}, m_last {nullptr} {} 


  List(List<T> const& listC): m_size {0}, m_first {nullptr}, m_last {nullptr} {
    for (iterator i = listC.begin(); i != listC.end(); ++i) {
      push_back(*i); 
    }
  }

    
  List(List&& listM): m_size {listM.m_size}, m_first {listM.m_first}, m_last {listM.m_last} { // steals list elements from listM
    listM.m_size = 0;
    listM.m_first = nullptr;
    listM.m_last = nullptr; 
  }

    
  List<T>& operator = (List<T> list) { 
    swap(list); 
    return *this; 
  }

    
  void swap(List<T>& list) {
      std::swap(m_size, list.m_size);
      std::swap(m_first, list.m_first);
      std::swap(m_last, list.m_last);
  }

    
  friend void swap(List<T>& l1, List<T>& l2) {
    l1.swap(l2);
  }

     
  ~List() {
    clear(); 
  }

     
  bool empty() const {
    return m_size == 0;
  }

    
  std::size_t size() const {
    return m_size;
  }

    
  T const& front() const {
    return (*m_first).m_value; 
  }

  T& front() {
    return (*m_first).m_value; 
  }

    
  void push_front(T const& a) {
    if (m_size == 0) {
      m_first = new ListNode<T>{a, nullptr, nullptr};
      m_last = m_first;
    }

    else if (m_size >= 1) {
      m_first = new ListNode<T>{a, nullptr, m_first};
      m_first -> m_next -> m_prev = m_first;
    }

    ++m_size;
  }

    
  void pop_front() {
    if (m_size == 1) {
      assert(m_first != nullptr);
      delete m_first;
      m_first = nullptr;
      m_size = 0;
    }

    else if (m_size > 1) {
      assert(m_first != nullptr);
      delete m_first;
      m_first = m_first -> m_next;
      --m_size;
    }
  }

    
  T const& last() const {
    return (*m_last).m_value; 
  }

  T& last() {
    return (*m_last).m_value; 
  }

    
  void push_back(T const& a) {
    if (m_size == 0) {
      m_last = new ListNode<T>{a, nullptr, nullptr};
      m_first = m_last;
    }

    else if (m_size >= 1) {
      m_last = new ListNode<T>{a, m_last, nullptr};
      m_last -> m_prev -> m_next = m_last;
    }

    ++m_size;
  }

    
  void pop_back() {
    if (m_size == 1) {
      assert(m_last != nullptr);
      delete m_last;
      m_last = nullptr;
      m_size = 0;
    }

    else if (m_size > 1) {
      assert(m_last != nullptr);
      delete m_last;
      m_last = m_last -> m_prev;
      --m_size;
    }
  }

    
  void clear() {
    while (m_size > 0) {
      pop_front();
    }
  }

  	
  iterator begin() const {
  	return iterator {m_first};
  }

  	
  iterator end() const {
  	return iterator {};
  }

    
  void insert(iterator pos, T const& value) {

    if (pos == begin()) { 
      push_front(value);
    }

    else if (pos == end()) { 
      push_back(value);
    }

    else {
      ListNode <T>* insertNode = new ListNode<T> {value, pos.prev().m_node, pos.m_node};

      pos.prev().m_node -> m_next = insertNode;
      pos.m_node -> m_prev = insertNode;
      ++m_size; 
    }
  }

    
  void reverse() {
    List<T> tmp{*this}; 
    clear(); 
    for (iterator it = tmp.begin(); it != tmp.end(); ++it) {
      push_front(*it); 
    }
  }


private:
  std::size_t m_size = 0;
  ListNode<T>* m_first = nullptr;
  ListNode<T>* m_last = nullptr;
};


   
template<typename T>
bool operator == (List<T> const& xs, List<T> const& ys) {
	bool result = true;

	if (xs.size() != ys.size()) { 
		result = false;
	}

	else {
    std::cout << "SIZE CONFIRMED. START SCANNING."<<"\n";
		ListIterator<T> xs_it = xs.begin(); 
		ListIterator<T> ys_it = ys.begin();

		while (xs_it != xs.end() && ys_it != ys.end()) { 
    std::cout << *ys_it <<"   " << *xs_it << "\n"; 
			if (*xs_it != *ys_it) { 
				result = false;
        break;
			}

			++xs_it; 
			++ys_it;
		}
	}

	return result;
}

  
template<typename T>
bool operator != (List<T> const& xs, List<T> const& ys) {
	return !(xs == ys);
}
  
  
template<typename T>
List<T> reverse (List<T> revList) {
  revList.reverse();
  return revList; 
}


#endif // #define BUW_LIST_HPP