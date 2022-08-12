#include <bits/stdc++.h>
#include <stdio.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long

using namespace std;

int main() {_
    int n, k;
    cin >> n >> k;

    vector<int> heights(n, 0);
    for (int i = 0; i < n; i++)
        cin >> heights[i];

    int j = 0;
    int min_sum = 0;
    for (int i = 0; i < k; i++)
        min_sum += heights[i];

    int sum = min_sum;
    int i = 0;
    while (i+k < n) {
        sum -= heights[i];
        sum += heights[i+k];
        i++;
        if (sum < min_sum) {
            min_sum = sum;
            j = i;
        }
    }

    cout << j+1 << '\n';

    return 0;
}