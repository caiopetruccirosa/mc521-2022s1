#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> plane_crush(n, -1);
    for (int i = 0; i < n; i++) {
        int l;
        cin >> l;
        plane_crush[i] = l-1;
    }

    for (int i  = 0; i < n; i++) {
        int a = plane_crush[i];
        int b = plane_crush[a];
        int c = plane_crush[b];

        if (c == i) {
            cout << "YES\n";
            return 0;
        }
    }

    cout << "NO\n";
    return 0;
}