#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;

        vector<int> guessed_dists;
        for (int j = 0; j < n; j++) {
            int d;
            cin >> d;

            guessed_dists.push_back(d);
        }

        cout << "\n";
    }

    return 0;
}