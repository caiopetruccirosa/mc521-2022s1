#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int main() {_
    int n;
    cin >> n;

    map<string, int> database;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        if (database.find(s) != database.end()) {
            int j = database[s];

            string aux;
            do {
                j++;
                aux = s+to_string(j);
            } while (database.find(aux) != database.end());
            
            database.insert(make_pair(aux, 0));
            database[s] = j;

            cout << aux << '\n';
        } else {
            database.insert(make_pair(s, 0));
            cout << "OK" << '\n';
        }
    }

    return 0;
}