#include <iostream>
#include <list>
#include <algorithm>
#include <fstream>
using namespace std;
int *colors;  //przechowywanie "kolorowan czesciowych"
int N; //liczba wierzcholkow

bool checkColors(int col, int k, list<int> adj_list[]){
    return !any_of(adj_list[k].cbegin(), adj_list[k].cend(), [&col](int i){ return col == colors[i];});
}

bool colorGraph(int k, int no_of_cols,  list<int> adj_list[]){
    if(k == N + 1) return true;
    for(int col = 1; col <= no_of_cols; col++)
        if(checkColors(col, k, adj_list)){ //sprawdzenie, czy mozemy uzyc koloru col dla wierzcholka k(czyli sprawdzamy sasiadow)
            colors[k] = col;
            if(colorGraph(k + 1, no_of_cols, adj_list))
                return true;
            colors[k] = 0;
        }
    return false;
}

bool isColorable(int no_of_cols, list<int> adj_list[]){
    colors[1] = 1;
    for(int i = 2; i <= N; i++) colors[i] = 0;
    if(colorGraph(2, no_of_cols, adj_list)) return true;
    else return false;
}

int Min(int j, list<int> adj_list[]){
    for(int i = 1; i <= N; i++)
        if(checkColors(i, j, adj_list))
            return i;
    return -1;
}

void Colors2(list<int> adj_list[]){ //algorytm zachlany
    colors[1] = 1;
    for(int i = 2; i <= N; i++)
        colors[i] = 0;
    for(int i = 2; i <= N; i++)
        colors[i] = Min(i, adj_list); //najmniejsza  liczba naturalna, ktora nie wystepuje jako kolor zadnego
                                         //sasiada
}

int main() {
    ifstream file("C:\\Users\\User\\Desktop\\Dyskretna\\Lab\\7\\1\\zwiazki.txt");
    file >> N;
    int v;
    int u;
    colors = new int [N +  1];
    list <int> adj_list[N + 1];
    while( !file.eof() ){
        file >> v;
        file >> u;
        adj_list[v].push_back(u);
        adj_list[u].push_back(v);
    }
    int n_color = 1;
    while( !isColorable(n_color, adj_list)) n_color++;
    for(int i = 1; i <= N; i++) cout << colors[i] << " ";
    cout << endl;
        for (int i = 1; i <= n_color; i++) {
            cout << "Samochod " << i << ": ";
            for (int j = 1; j <= N; j++) {
                if(colors[j] == i){
                    cout << j << " ";
                    colors[j] = 0;
                }
            }
            cout << endl;
        }
    cout << "=========================" << endl;
    Colors2(adj_list);
    int max = 1;
    for(int i = 1; i <= N; i++) if (max < colors[i]) max = colors[i];
    for(int i = 1; i <= N; i++) cout << colors[i] << " ";
    cout << endl;
    for (int i = 1; i <= max; i++) {
        cout << "Samochod " << i << ": ";
        for (int j = 1; j <= N; j++) {
            if(colors[j] == i){
                cout << j << " ";
                colors[j] = 0;
            }
        }
        cout << endl;
    }
    delete [] colors;
    return 0;
}