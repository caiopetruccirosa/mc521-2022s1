#include <bits/stdc++.h>
#include <stdio.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long

using namespace std;

int main() {_
    int n; cin >> n;

    vector<int> reports(n, 0);
    for (int i = 0; i < n; i++)
        cin >> reports[i];

    vector<int> amount_per_folder;

    int consecutive_days = 0;
    int losses = 0;
    for (int i = 0; i < n; i++) {
        if (reports[i] < 0) {
            losses++;
        }

        if (losses == 3) {
            amount_per_folder.push_back(consecutive_days);
            consecutive_days = 1;
            losses = 1;
        } else {
            consecutive_days++;
        }
    }
    amount_per_folder.push_back(consecutive_days);

    cout << amount_per_folder.size() << '\n';
    for (int i = 0; i < amount_per_folder.size(); i++) {
        cout << amount_per_folder[i];
        if (i < amount_per_folder.size()-1)
            cout << ' ';
    }
    cout << '\n';

    return 0;
}