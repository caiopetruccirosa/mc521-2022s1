#include <bits/stdc++.h>
#include <stdio.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long

using namespace std;

int main() {_
    int n; cin >> n;

    vector<int> balls(n, 0);
    for (int i = 0; i < n; i++)
        cin >> balls[i];

    for (int i = 0; i < 6; i++) {
        for (int j = i+1; j < 6; j++) {
            for (int k = j+1; k < 6; k++) {
                if (abs(balls[i]-balls[j]) <= 2 && abs(balls[i]-balls[j]) > 0 &&
                    abs(balls[j]-balls[k]) <= 2 && abs(balls[j]-balls[k]) > 0 &&
                    abs(balls[k]-balls[i]) <= 2 && abs(balls[k]-balls[i]) > 0) {
                    cout << "YES\n";
                    return 0;
                }
            }
        }
    }

    cout << "NO\n";
    return 0;
}