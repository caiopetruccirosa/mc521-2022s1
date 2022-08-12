#include <bits/stdc++.h>
#include <stdio.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long

using namespace std;

int main() {_
    int t;
    cin >> t;

    while (t--) {
        int n; cin >> n;

        vector<int> pieces(n, 0);
        for (int i = 0; i < n; i++)
            cin >> pieces[i];

        int max_tastiness = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j && max_tastiness < pieces[i]+pieces[j]) {
                    max_tastiness = pieces[i]+pieces[j];
                }
            }
        }

        cout << max_tastiness << '\n';
    }

    return 0;
}