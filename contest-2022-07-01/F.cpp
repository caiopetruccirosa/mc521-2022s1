#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> bids(n);
    for (int i = 1; i <= n; i++) {
        int p;
        cin >> p;
        bids.push_back(make_pair(p, i));
    }

    sort(bids.begin(), bids.end());

    int winner_bid = bids[bids.size()-2].first;
    int winner_idx = bids[bids.size()-1].second;

    cout << winner_idx << ' ' << winner_bid << '\n';

    return 0;
}