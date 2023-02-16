#include "heap.h"
#include <iostream>

using namespace std;

int main() {
  Heap<int> h(3);
  h.push(0);
	h.push(5);
	h.push(10);
	h.push(15);
	h.push(20);

  h.print();
  cout << h.top() << endl;
  h.pop();
  h.print();
  cout << h.top() << endl;
  h.pop();
  h.print();
  cout << h.top() << endl;
  h.pop();
  h.print();

  return 0;
}