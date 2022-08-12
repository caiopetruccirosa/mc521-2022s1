#include <bits/stdc++.h>
#include <stdio.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long

using namespace std;

int main() {_
    vector<int> scores(6, 0);
    for (int i = 0; i < 6; i++)
        cin >> scores[i];

    double sum = 0;
    for (int i = 0; i < 6; i++)
        sum += scores[i];

    for (int i = 0; i < 6; i++) {
        for (int j = i+1; j < 6; j++) {
            for (int k = j+1; k < 6; k++) {
                double half_sum = scores[i] + scores[j] + scores[k];
                if (half_sum == sum/2.0) {
                    cout << "YES\n";
                    return 0;
                }
            }
        }
    }

    cout << "NO\n";
    return 0;
}