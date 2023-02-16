#ifndef STACK_H
#define STACK_H

#include <vector>
#include <stdexcept>

using namespace std;

// Use inheritance from std::vector (choose public/private) as appropriate
template <typename T>
class Stack : public vector<T>
{
public:
    Stack();
    ~Stack();
    bool empty() const;
    size_t size() const;
    void push(const T& item);
    void pop();  // throws std::underflow_error if empty
    const T& top() const; // throws std::underflow_error if empty
    // Add other members only if necessary
};

template <typename T>
Stack<T>::Stack(){

}

template <typename T>
Stack<T>::~Stack() {

}

template <typename T>
size_t Stack<T>::size() const {
  return vector<T>::vector::size();
}

template <typename T>
bool Stack<T>::empty() const {
  return vector<T>::vector::empty();
}

template <typename T>
void Stack<T>::push(const T& item) {
  vector<T>::vector::push_back(item);
}

template <typename T>
void Stack<T>::pop() {
  if (empty()) {
    throw underflow_error("Stack Underflow");
  } else {
    vector<T>::vector::pop_back();
  }
}

template <typename T>
T const& Stack<T>::top() const {
  if (empty()) {
    throw underflow_error("Stack Underflow");
  } else {
    return vector<T>::vector::back();
  }
}
#endif