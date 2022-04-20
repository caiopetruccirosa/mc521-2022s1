#include <bits/stdc++.h>
#include <set> 

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

struct jogador {
    string nome;
    int score;
    int ultima_rodada;
};

bool compararJogadores(pair<string, jogador> j1, pair<string, jogador> j2) {
    if (j1.second.score != j2.second.score) {
        return j1.second.score > j2.second.score;
    }
    
    return j1.second.ultima_rodada < j2.second.ultima_rodada;
}

int main() {_
    int n;
    cin >> n;

    map<string, jogador> jogadores {};
    for (int i = 0; i < n; i++) {
        string nome;
        int score;
        cin >> nome >> score;
        if (jogadores.find(nome) != jogadores.end()) {
            if (!jogadores[nome].score >= 0) {
                jogadores[nome].score += score;
                jogadores[nome].ultima_rodada = i;
            }
        } else {
            jogador j = {nome, score, i};
            jogadores[nome] = j;
        }
    }

    vector<pair<string, jogador>> ordenado = vector<pair<string, jogador>>(jogadores.begin(), jogadores.end());
    sort(ordenado.begin(), ordenado.end(), compararJogadores);

    cout << ordenado[0].first << '\n';

    return 0;
}