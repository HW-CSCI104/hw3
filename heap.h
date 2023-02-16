#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>
#include <iostream>

template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;
  void print();

private:
  /// Add whatever helper functions and data members you need below
  std::vector<T> v;
  size_t mary;
  PComparator comp;
};

template <typename T, typename PComparator>
void Heap<T,PComparator>::print() {
  for (size_t i = 0; i < v.size(); i++) {
    std::cout << v[i] << " ";
  }
  std::cout << std::endl;
}


template <typename T, typename PComparator>
Heap<T,PComparator>::Heap(int m, PComparator c) : mary(m), comp(c) {

}

template <typename T, typename PComparator>
Heap<T,PComparator>::~Heap() {

}

// Add implementation of member functions here
template <typename T, typename PComparator>
void Heap<T,PComparator>::push(const T& item) {
  v.push_back(item);

  // sort heap
  size_t current = v.size() - 1;
  while (true) {
    if (!(current)) {
      break;
    }
    size_t parent = (current-1)/mary;
    if (comp(v[current], v[parent])) {
      std::swap(v[current], v[parent]);
      current = parent;
    } else {
      break;
    }
  }
}

template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("Stack Underflow");
  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
  return v[0];

}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("Stack Underflow");
  }
  std::swap(v[0], v[v.size() - 1]);
  v.pop_back();
  // sort heap
  size_t current = 0;
  while (true) {

    size_t num = mary * current + 1;

    if (num >= v.size()) {
      break;
    }
    size_t swapIndex = v.size();
    size_t i = 0;
    while (i < mary && (num+i) < v.size()) {
      int child = (num+i);
      if (comp(v[child], v[current])) {
        if ((swapIndex == v.size()) || (swapIndex < v.size() && comp(v[child], v[swapIndex]))) {
          swapIndex = child;
        }
      }
      i++;
    }
    if (swapIndex != v.size()) {
      std::swap(v[current], v[swapIndex]);
      current = swapIndex;
    } else {
      break;
    }
  }

}

template <typename T, typename PComparator>
bool Heap<T,PComparator>::empty() const {
  return v.empty();
}

template <typename T, typename PComparator>
size_t Heap<T,PComparator>::size() const {
  return v.size();
}

#endif

