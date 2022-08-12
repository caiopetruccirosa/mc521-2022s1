#include <bits/stdc++.h>
#include <stdio.h>
#include <limits.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long

using namespace std;

int calculate_height(vector<vector<int>> tree, int root) {
    int max_height = 0;
    for (auto child: tree[root]) {
        int height_i = calculate_height(tree, child);
        if (height_i > max_height)
            max_height = height_i;
    }
    return max_height + 1;
}

int main() {_
    int n;
    cin >> n;

    vector<int> managers;
    vector<vector<int>> employees(n, vector<int>());
    for (int i = 0; i < n; i++) {
        int p; cin >> p;
        if (p > 0) {
            employees[p-1].push_back(i);
        } else {
            managers.push_back(i);
        }
    }

    int min_groups = 0;
    for (auto manager: managers) {
        int groups = calculate_height(employees, manager);
        if (groups > min_groups)
            min_groups = groups;
    }

    cout << min_groups << '\n';

    return 0;
}