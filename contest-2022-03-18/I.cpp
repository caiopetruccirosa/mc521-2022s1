#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int main() {_
    int n, l;
    cin >> n >> l;

    vector<int> lanternas = {};
    for (int i = 0; i < n; i++) {
        int ai;
        cin >> ai;

        lanternas.push_back(ai);
    }
    sort(lanternas.begin(), lanternas.end());

    double max_dist_lanternas = -1.0;
    for (int i = 1; i < n; i++) {
        double aux_dist = lanternas[i] - lanternas[i-1];
        if (aux_dist > max_dist_lanternas) {
            max_dist_lanternas = aux_dist;
        }
    }

    double max_dist_pontas = lanternas[0];
    if (max_dist_pontas < l - lanternas[n-1]) {
        max_dist_pontas = l - lanternas[n-1];
    }

    double d = max_dist_lanternas/2.0;
    if (max_dist_pontas > d) {
        d = max_dist_pontas;
    }

    printf("%.10lf\n", d);

    return 0;
}