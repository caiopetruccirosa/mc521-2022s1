#include <iostream>
#include <bits/stdc++.h>

#define INF 1000000

using namespace std;

int main() {
    int p, r;
    int n = 1;

    cin >> p >> r;
    while (p && r) {        
        vector<vector<int>> distances;
        distances.assign(p, vector<int>(p));

        for (int i = 0; i < p; i++) {
            for (int j = 0; j < p; j++) {
                if (i == j)
                    distances[i][j] = 0;
                else
                    distances[i][j] = INF;
            }
        }

        map<string, int> indexes;
        int k = 0;
        for (int i = 0; i < r; i++) {
            string a, b;
            cin >> a >> b;

            if (indexes.find(a) == indexes.end()) {
                indexes[a] = k;
                k++;
            }

            if (indexes.find(b) == indexes.end()) {
                indexes[b] = k;
                k++;
            }
    
            distances[indexes[a]][indexes[b]] = 1;
            distances[indexes[b]][indexes[a]] = 1;
        }

        for (int k = 0; k < p; k++)
            for (int i = 0; i < p; i++)
                for (int j = 0; j < p; j++)
                    if (distances[i][j] > distances[i][k] + distances[k][j])
                        distances[i][j] = distances[i][k] + distances[k][j];

        int max_dist = -1;
        for (int i = 0; i < p; i++)
            for (int j = 0; j < p; j++)
                if (distances[i][j] > max_dist)
                    max_dist = distances[i][j];

        cout << "Network " << n << ": ";
        if (max_dist < INF)
            cout << max_dist;
        else
            cout << "DISCONNECTED";
        cout << "\n\n";

        cin >> p >> r;
        n++;
    }

    return 0;
}