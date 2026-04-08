#include <iostream>
using namespace std;

struct Node {
  int index;
  int move;
  Node *prev;
  Node *next;
};

class DLinkedList {
public:
  Node *head;
  Node *tail;

  DLinkedList() : head(nullptr), tail(nullptr) {}
  void append(int index, int move) {
    Node* newNode = new Node{index, move, nullptr, nullptr};
    if(!head) {
      head = tail = newNode;
      head->next = head;
      head->prev = head;
    } else {
      newNode->prev = tail;
      newNode->next = head;
      tail->next = newNode;
      head->prev = newNode;
      tail = newNode;
    }
  }

  void erase(Node* node) {
    if(node->next == node) {
      delete node;
      head = tail = nullptr;
    } else {
      node->prev->next = node->next;
      node->next->prev = node->prev;
      if(node == head) head = node->next;
      if(node == tail) tail = node->prev;
      delete node;
    }
  }

  bool isEmpty() {
    return head == nullptr;
  }
};

int main() {
  int n, num;
  cin >> n;

  DLinkedList balloons;

  for(int i = 0; i < n; i++) {
    cin >> num;
    balloons.append(i+1, num);
  }

  Node* cur = balloons.head;
  
  while(!balloons.isEmpty()) {
    int idx = cur->index;
    int move = cur->move;
    cout << idx << " ";

    if(balloons.isEmpty())
      break;

    Node *tmp = cur;
    cur = (move > 0) ? cur->next : cur->prev;
    balloons.erase(tmp);

    if(balloons.isEmpty())
      break;

    if(move > 0) {
      for(int i = 0; i < move-1; i++) {
        cur = cur->next;
      }
    } else {
      for(int i = 0; i < -move - 1; i++) {
        cur = cur->prev;
      }
    }
  }

  return 0;
}
