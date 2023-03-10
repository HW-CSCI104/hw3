#include "llrec.h"
using namespace std;

//*********************************************
// Provide your implementation of llpivot below
//*********************************************
void findLastElementNode(Node*& head) {
  if (head->next != nullptr) {
    head = head->next;
    findLastElementNode(head);
  }
}

void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot) {
  if (smaller == nullptr || smaller->val > 100) {
    smaller = nullptr;
  }
  if (larger == nullptr || larger->val > 100) {
    larger = nullptr;
  }
  if (head == nullptr) {
    smaller = nullptr;
    larger = nullptr;
    return;
  }
  if (head->val > pivot) {
    if (larger == nullptr) {
      Node* temp = head;
      head = head->next;
      larger = temp;
      larger->next = nullptr;
    } else {
      Node* temp = larger;
      findLastElementNode(temp);
      Node* temp2 = head;
      head = head->next;
      temp->next = temp2;
      temp->next->next = nullptr;
    }
  } else {
    if (smaller == nullptr) {
      Node* temp = head;
      head = head->next;
      smaller = temp;
      smaller->next = nullptr;
    } else {
      Node* temp = smaller;
      findLastElementNode(temp);
      Node* temp2 = head;
      head = head->next;
      temp->next = temp2;
      temp->next->next = nullptr;
    }
  }
  if (head == nullptr) {
    return;
  }
  llpivot(head, smaller, larger, pivot);
}
