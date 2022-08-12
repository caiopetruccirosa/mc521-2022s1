#include <bits/stdc++.h>
#include <stdio.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long

using namespace std;

int main() {_
    int q, c = 1;
    cin >> q;

    queue<pair<int, int>> monocarp;
    priority_queue<pair<int, int>> polycarp;
    set<pair<int, int>> served;
    while (q--) {
        pair<int, int> pc;
        int t; cin >> t;
        if (t == 1) {
            int m; cin >> m;
            pc = make_pair(m, -c);
            monocarp.push(pc);
            polycarp.push(pc);
            c++;
        } else  {
            if (t == 2) {
                do {
                    pc = monocarp.front();
                    monocarp.pop();
                } while (served.find(pc) != served.end());
            } else if (t == 3) {
                do {
                    pc = polycarp.top();
                    polycarp.pop();
                } while (served.find(pc) != served.end());
            }
            if (served.size() > 0)
                cout << ' ';
            cout << -pc.second;
            served.insert(pc);
        }
    }
    cout << '\n';

    return 0;
}