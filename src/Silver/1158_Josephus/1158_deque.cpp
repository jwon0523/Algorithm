#include <iostream>
#include <deque>
#include <sstream>
using namespace std;

int main() {
    deque<int> dq;
    int n, k;
    cin >> n >> k;

    for(int i = 0; i < n; i++) {
        dq.push_back(i + 1);
    }

    stringstream ss;
    ss << "<";

    while(!dq.empty()) {
        for(int i = 0; i < k - 1; i++) {
            dq.push_back(dq.front());
            dq.pop_front();
        }
        ss << dq.front();
        dq.pop_front();
        if (!dq.empty()) {
            ss << ", ";
        }
    }
    ss << ">";

    cout << ss.str() << endl;
    return 0;
}
