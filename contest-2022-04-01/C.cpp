#include <bits/stdc++.h>
#include <stdio.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int main() {_
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        map<int, int> frequencies;
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            if (frequencies.find(a) != frequencies.end())
                frequencies[a] += 1;
            else
                frequencies[a] = 1;
        }
        
        vector<int> combination;
        combination.reserve(n);
        for (auto freq: frequencies) {
            frequencies[freq.first] -= 1;
            combination.push_back(freq.first);
        }

        for (auto freq: frequencies) {
            for (int i = 0; i < frequencies[freq.first]; i++) {
                combination.push_back(freq.first);
            }
        }

        for (int i = 0; i < n; i++) {
            cout << combination[i];
            if (i < n-1)
                cout << ' ';
        }
        cout << '\n';
    }

    return 0;
}