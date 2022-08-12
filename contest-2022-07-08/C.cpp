#include <iostream>
#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define pii pair<int, int>

using namespace std;

int main() {_
    ll t; cin >> t;

    while (t--) {
        ll n; cin >> n;

        vector<int> wishes(n, -1), idx(n, -1), arr(n, -1);
        set<int> wished;
        for (int i = 0; i < n; i++) {
            int w; cin >> w; w--;
            wishes[i] = w;
            if (wished.find(w) != wished.end()) {
                arr[i] = -1;
            } else {
                arr[i] = w;
                idx[w] = i;
                wished.insert(w);
            }
        }

        vector<int> not_wished;
        for (int i = 0; i < n; i++)
            if (wished.find(i) == wished.end())
                not_wished.push_back(i);

        int k = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] == -1) {
                int j = not_wished[k];
                if (j != i) {
                    arr[i] = j;
                } else {
                    arr[i] = wishes[i];
                    arr[idx[wishes[i]]] = j;
                    idx[wishes[i]] = i;
                }
                k++;
            }
        }

        cout << wished.size() << '\n';
        for (int i = 0; i < n; i++) {
            cout << arr[i]+1;
            if (i < n-1)
                cout << ' ';
        }
        cout << '\n';
    }

    return 0;
}