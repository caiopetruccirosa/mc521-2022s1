#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int main() {_
    int n, m;
    cin >> n >> m;
    
    deque<int> q1, q2, q3, q4;

    int r = n;
    int i = 1;
    while (r-- && i <= m) {
        if (i <= m) {
            q2.push_back(i);
            i++;
        }
        if (i <= m) {
            q4.push_back(i);
            i++;
        }
    }

    r = n;
    while (r-- && i <= m) {
        if (i <= m) {
            q1.push_back(i);
            i++;
        }
        if (i <= m) {
            q3.push_back(i);
            i++;
        }
    }

    i = 1;
    while (!q1.empty() || !q2.empty() || !q3.empty() || !q4.empty()) {
        if (!q1.empty()) {
            cout << q1.front() << ' ';
            q1.pop_front();
        }
        if (!q2.empty()) {
            cout << q2.front() << ' ';
            q2.pop_front();
        }
        if (!q3.empty()) {
            cout << q3.front() << ' ';
            q3.pop_front();
        }
        if (!q4.empty()) {
            cout << q4.front() << ' ';
            q4.pop_front();
        }
    }
    cout << '\n';

    return 0;
}