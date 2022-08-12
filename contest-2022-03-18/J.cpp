#include <bits/stdc++.h>
#include <limits>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long

using namespace std;

int main() {_
    ll n;
    cin >> n;

    map<string, ll> scores;
    vector<pair<string, ll>> rounds(n, pair<string, ll>());
    for (ll i = 0; i < n; i++) {
        string name;
        ll score;
        cin >> name >> score;
        if (scores.find(name) != scores.end())
            scores[name] += score;
        else
            scores[name] = score;
        rounds[i] = make_pair(name, scores[name]);
    }

    ll max_score = LLONG_MIN;
    for (auto score: scores)
        if (score.second > max_score)
            max_score = score.second;

    map<string, ll> winners;
    for (auto score: scores)
        if (max_score == score.second)
            winners[score.first] = score.second;

    for (ll i = 0; i < n; i++) {
        if (rounds[i].second >= max_score && winners.find(rounds[i].first) != winners.end()) {
            cout << rounds[i].first << '\n';
            return 0;
        }
    }

    return 0;
}