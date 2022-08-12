#include <bits/stdc++.h>
#include <stdio.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

bool isJolly(vector<int> numbers) {
    int n = numbers.size();
    
    vector<bool> dists(n, false);
    for (int i = 0; i < n-1; i++) {
        int dist = abs(numbers[i]-numbers[i+1]);
        if (dist > n || dist < 1 || dists[dist]) {
            return false;
        }
        dists[dist] = true;
    }

    for (int i = 1; i < n; i++) {
        if (!dists[i]) {
            return false;
        }
    }

    return true;
}

int main() {_
    int n;
    while (cin >> n) {
        vector<int> numbers(n, 0);
        for (int i = 0; i < n; i++) {
            cin >> numbers[i];
        }

        if (isJolly(numbers)) {
            cout << "Jolly\n";
        } else {
            cout << "Not jolly\n";
        }
    }

    return 0;
}