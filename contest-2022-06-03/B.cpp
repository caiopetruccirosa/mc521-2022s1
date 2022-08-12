#include <bits/stdc++.h>
#include <stdio.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define pii pair<int, int>

using namespace std;

bool is_attacked(pii a, pii b) {
    if (a.first == b.first || a.second == b.second)
        return true;

    return abs(a.first-b.first) == abs(a.second-b.second);
}

bool has_path(map<pii, bool>& visited, pii queen, pii current, pii target, int n) {
    if (current == target)
        return true;

    visited[current] = true;

    if (is_attacked(queen, current))
        return false;

    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            pii adj = make_pair(current.first+i, current.second+j);
            if (adj.first >= 0 && adj.second >= 0 && adj.first < n && adj.second < n)
                if (visited.find(adj) == visited.end())
                    if (has_path(visited, queen, adj, target, n))
                        return true;
        }
    }

    return false;
}

int main() {_
    int n;
    cin >> n;

    int ax, ay, bx, by, cx, cy;
    cin >> ax >> ay >> bx >> by >> cx >> cy;

    map<pii, bool> visited;
    pii queen, king, target;
    
    queen = make_pair(ax-1, ay-1); 
    king = make_pair(bx-1, by-1);
    target = make_pair(cx-1, cy-1);

    if (has_path(visited, queen, king, target, n))
        cout << "YES\n";
    else
        cout << "NO\n";

    return 0;
}