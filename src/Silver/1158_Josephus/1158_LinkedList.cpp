#include <deque>
#include <iostream>
#include <sstream>
using namespace std;

struct Node {
  int index;
  Node *prev;
  Node *next;
};

class DLinkedList {
public:
  Node *head;
  Node *tail;
  DLinkedList() : head(nullptr), tail(nullptr) {}

  void append(int index) {
    Node *newNode = new Node{index, tail, head};
    if (!head) {
      head = tail = newNode;
      head->prev = head->next = head;
    } else {
      tail->next = newNode;
      head->prev = newNode;
      tail = newNode;
    }
  }

  void erase(Node *node) {
    if (node->next == node) {
      delete node;
      head = tail = nullptr;
    } else {
      node->next->prev = node->prev;
      node->prev->next = node->next;
      if (head == node)
        head = node->next;
      if (tail == node)
        tail = node->prev;
      delete node;
    }
  }

  bool isEmpty() { return head == nullptr; }
};

int main() {
  int n, k;
  cin >> n >> k;
  DLinkedList list;

  for (int i = 0; i < n; i++)
    list.append(i + 1);

  Node *cur = list.head;

  cout << "<";
  while (!list.isEmpty()) {
    for (int i = 0; i < k - 1; i++) {
      cur = cur->next;
    }
    cout << cur->index;
    Node *tmp = cur;
    cur = cur->next;
    list.erase(tmp);
    if (!list.isEmpty())
      cout << ", ";
  }
  cout << ">";

  return 0;
}
