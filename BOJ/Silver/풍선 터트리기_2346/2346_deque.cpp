#include <iostream>
#include <deque>
using namespace std;

int main() {
  deque<pair<int, int>> dq;
  int n, num, cur;
  cin >> n;

  for(int i = 0; i < n; i++) {
    cin >> num;
    dq.push_back(make_pair(num, i+1));
  }

  while(!dq.empty()) {
    cur = dq.front().first;
    cout << dq.front().second << " ";
    dq.pop_front();

    if(dq.empty())
      break;

    if(cur > 0) {
      for(int i = 0; i < cur-1; i++) {
        dq.push_back(dq.front());
        dq.pop_front();
      }
    } else {
      for(int i = 0; i < (-1)*cur; i++) {
        dq.push_front(dq.back());
        dq.pop_back();
      }
    }
  }
}
