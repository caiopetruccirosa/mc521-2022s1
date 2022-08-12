#include <bits/stdc++.h>
#include <stdio.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long

using namespace std;

int longest_line(
    map<pair<int, bool>, int>& answers,
    pair<int, bool>& p,
    vector<int>& cars, 
    int prev_weight, 
    int current, 
    int n
) {
    if (current >= n)
        return 0;

    int included, not_included;

    p.first = current;
    p.second = false;
    if (answers.find(p) != answers.end())
        not_included = answers[p];
    else
        not_included = longest_line(answers, p, cars, prev_weight, current+1, n);

    if (cars[current] > prev_weight) {
        p.first = current;
        p.second = true;
        if (answers.find(p) != answers.end())
            included = answers[p];
        else
            included = longest_line(answers, p, cars, cars[current], current+1, n)+1;
        
        return max(included, not_included);
    } else {
        return not_included;
    }
}

int main() {_
    int t; cin >> t;

    while (t--) {
        int n; cin >> n;

        vector<int> cars(n, 0);
        for (int i = 0; i < n; i++)
            cin >> cars[i];
        
        map<pair<int, bool>, int> answers;
        pair<int, bool> p;

        cout << longest_line(answers, p, cars, -1, 0, n) << '\n';
    }

    return 0;
}