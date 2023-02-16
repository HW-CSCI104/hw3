#include "llrec.h"
using namespace std;

//*********************************************
// Provide your implementation of llpivot below
//*********************************************

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
      while (temp->next != nullptr && temp->next != larger) {
        temp = temp->next;
      }
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
      while (temp->next != nullptr && temp->next != smaller) {
        temp = temp->next;
      }
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
