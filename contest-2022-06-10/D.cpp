#include <bits/stdc++.h>
#include <stdio.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long

using namespace std;

/*vector<string> build_path(map<pii, pii> previous, pi  start, pii target) {
    stack<pii> reversed_path;
    int pos = target;
    while (pos != start) {
        reversed_path.push(pos);
        pos = 
    }
    
    vector<string> path;

    return path;
}

vector<string> shortest_path(pii start, pii target, int n) {
    map<pii, bool> visited;
    map<pii, pii> previous;
    queue<pii> q;

    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        pii pos = s.front();
        s.pop();
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                pii pos_i = make_pair(pos.first+i, pos.second+j);
                if (pos_i.first >= 0 && pos_i.second >= 0 && pos_i.first < n && pos_i.second < n) {
                    if (visited.find(pos_i) == visited.end()) {
                        visited[pos_i] = true;
                        previous[pos_i] = pos;
                        s.push(pos_i);
                        if (pos_i == target)
                            return true;
                    }
                }
            }
        }
    }

    return false;
}*/

int main() {_
    string s, t;
    cin >> s >> t;

    int sx = s[0]-'a', sy=s[1]-'1';
    int tx = t[0]-'a', ty=t[1]-'1';

    int diffx = tx-sx, diffy = ty-sy;

    // diffx == 0 :
    // diffx > 0 : R
    // diffx < 0 : L

    // diffy == 0 :
    // diffy > 0 : U
    // diffy < 0 : D

    cout << max(diffx, diffy) << '\n';
    while (diffx != 0 && diffy != 0) {
        if (diffx < 0 && diffy < 0) {
            cout << "LD\n";
            diffx++;
            diffy++;
        } else if (diffx < 0 && diffy > 0) {
            cout << "LU\n";
            diffx++;
            diffy--;
        } else if (diffx > 0 && diffy < 0) {
            cout << "RD\n";
            diffx--;
            diffy++;
        } else if (diffx > 0 && diffy > 0) {
            cout << "RU\n";
            diffx--;
            diffy--;
        } else if (diffx < 0 && diffy == 0) {
            cout << "L\n";
            diffx++;
        } else if (diffx > 0 && diffy == 0) {
            cout << "R\n";
            diffx--;
        } else if (diffx == 0 && diffy < 0) {
            cout << "D\n";
            diffy++;
        } else if (diffx == 0 && diffy > 0) {
            cout << "U\n";
            diffy--;
        }
    }

    //pair<int, int> start = make_pair(s[0]-'a', s[1]-'1');
    //pair<int, int> target = make_pair(t[0]-'a', t[1]-'1');

    //vector<string> moves = shortest_path(start, target);

    //cout << moves.size() << '\n';
    //for (int i = 0; i < moves.size(); i++)
    //    cout << moves[i] << '\n';

    return 0;
}