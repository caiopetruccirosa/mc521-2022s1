#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int main() {_
    int n;
    cin >> n;

    pair<vector<int>, vector<int>> info = make_pair(vector<int>(), vector<int>()); // <even, odd>
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        // check if number is even
        if (x % 2) {
            info.second.push_back(i+1);
        } else {
            info.first.push_back(i+1);
        }

        if (info.first.size() >= 2 && info.second.size() == 1) {
            cout << (info.second[0]) << '\n';
            break;
        } else if (info.second.size() >= 2 && info.first.size() == 1) {
            cout << (info.first[0]) << '\n';
            break;
        }
    }

    return 0;
}