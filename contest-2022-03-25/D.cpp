#include <bits/stdc++.h>
#include <stdio.h>
#include <limits.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

// to submit
int main() {_
    int n;
    while (cin >> n && n) {
        map<set<int>, int> combinations_popularity;
        
        while (n--) {
            set<int> courses;
            for (int i = 0; i < 5; i++) {
                int c;
                cin >> c;
                courses.insert(c);
            }
            if (combinations_popularity.find(courses) != combinations_popularity.end()) {
                combinations_popularity[courses] += 1;
            } else {
                combinations_popularity[courses] = 1;
            }
        }

        int max_popularity = INT_MIN;
        for (auto combination: combinations_popularity) {
            if (combination.second > max_popularity) {
                max_popularity = combination.second;
            }
        }

        int count = 0;
        for (auto combination: combinations_popularity) {
            if (combination.second == max_popularity)
                count += combination.second;
        }
        cout << count << '\n';
    }

    return 0;
}