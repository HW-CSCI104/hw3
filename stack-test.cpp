#include "stack.h"
#include <iostream>

using namespace std;

int main() {
  Stack<int> s;
  try {
    cout << s.empty() << endl;
    s.push_back(7);
    s.push_back(9);
    s.push_back(14);
    cout << s.empty() << endl;
    cout << s.size() << endl;
    cout << s.top() << endl;
    s.pop();
    s.pop();
    s.pop();
    s.pop();
  } catch(underflow_error& e) {
    cout << e.what() << endl;
  }



  return 0;
}