#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int main() {_
    // n: quantidade de viagens
    // m: quantas viagens um ticket especial cobre
    // a: custo de uma passagem de uma viagem
    // b: custo de uma passagem de m viagens
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    
    if (m*a<b) {
        int total_unitario = n*a;
        cout << total_unitario << '\n';
    } else {
        int total_especial_exato = (n/m)*b + (n%m)*a;
        int total_especial_sobrando = (n/m)*b + b;
        if (total_especial_exato < total_especial_sobrando) {
            cout << total_especial_exato << '\n';
        } else {
            cout << total_especial_sobrando << '\n';
        }
    }

    return 0;
}