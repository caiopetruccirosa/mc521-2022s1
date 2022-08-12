#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> computers(n, 0);
    for (int i = 0; i < n; i++)
        cin >> computers[i];

    sort(computers.begin(), computers.end());

    int min_capacity = INT_MAX;
    for (int i = 1; i <= k; i++)
        if (computers[n-i] < min_capacity)
            min_capacity = computers[n-i];

    cout << min_capacity << '\n';         

    return 0;
}