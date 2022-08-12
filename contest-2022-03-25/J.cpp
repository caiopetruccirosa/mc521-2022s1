#include <bits/stdc++.h>
#include <stdio.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int main() {_
    int n;
    while (cin >> n) {
        bool possibilities[3] = { true, true, true };

        stack<int> s;
        queue<int> q;
        priority_queue<int> pq;

        while (n--) {
            int c, x;
            cin >> c >> x;

            if (c == 1) {
                s.push(x);
                q.push(x);
                pq.push(x);
            } else if (c == 2) {
                int sx = -1;
                if (!s.empty()) {
                    sx = s.top(); s.pop();
                }
                
                int qx = -1;
                if (!q.empty()) {
                    qx = q.front(); q.pop();
                }

                int pqx = -1;
                if (!pq.empty()) {
                    pqx = pq.top(); pq.pop();
                }
                
                if (sx != x && possibilities[0])
                    possibilities[0] = false;

                if (qx != x && possibilities[1])
                    possibilities[1] = false;

                if (pqx != x && possibilities[2])
                    possibilities[2] = false;
            }
        }

        int truth_count = 0;
        for (int i = 0; i < 3; i++)
            if (possibilities[i])
                truth_count++;

        if (truth_count > 1)
            cout << "not sure\n";
        else if (truth_count == 0)
            cout << "impossible\n";
        else if (possibilities[0])
            cout << "stack\n";
        else if (possibilities[1])
            cout << "queue\n";
        else if (possibilities[2])
            cout << "priority queue\n";
    }

    return 0;
}