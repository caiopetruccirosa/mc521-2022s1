#include <iostream>
#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long

using namespace std;

int main() {_
    int t; cin >> t;

    while (t--) {
        int n; cin >> n;

        vector<bool> married_daughters(n+1, false);
        vector<bool> married_princes(n+1, false);

        for (int i = 1; i <= n; i++) {
            int k; cin >> k;
            while (k--) {
                int p; cin >> p;
                if (!married_daughters[i] && !married_princes[p]) {
                    married_daughters[i] = true;
                    married_princes[p] = true;
                }
            }
        }

        int unmarried_daughter = -1;
        int unmarried_prince = -1;
        for (int i = 1; i <= n; i++) {
            if (unmarried_daughter == -1 && !married_daughters[i])
                unmarried_daughter = i;
            if (unmarried_prince == -1 && !married_princes[i])
                unmarried_prince = i;
            if (unmarried_daughter > 0 && unmarried_prince > 0)
                break;
        }

        if (unmarried_daughter == -1 || unmarried_prince == -1) {
            cout << "OPTIMAL\n";
        } else {
            cout << "IMPROVE\n";
            cout << unmarried_daughter << ' ' << unmarried_prince << '\n';
        }
    }

    return 0;
}