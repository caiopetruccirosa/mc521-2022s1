#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> candies(m, 0);
    while (n > 0) {
        for (int i = 0; i < m && n > 0; i++) {
            candies[i]++;
            n--;
        }
    }

    for (int i = 0; i < m; i++) {
        cout << candies[i];
        if (i < m-1)
            cout << ' ';
    }
    cout << '\n';

    return 0;
}