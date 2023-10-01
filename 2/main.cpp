#include <iostream>
using namespace std;

int N;

void Sito_Eratostenesa (int tab_par[]){
    int tab [N + 1];
    for (int i = 0; i < N + 1; i++) tab[i] = i; //zapisujemy liczby w tablice
    int j = 0;
    for (int p = 2; p < N + 1; p++){
        if (tab[p] != 0){
            cout << tab[p] << endl;
            tab_par [j++] = tab[p];
            for (int j = p * p; j < N + 1; j += p)  tab[j] = 0;  //Sqrt(N)
        }
    }
}

void Lista_Par (int tab_par[]){
    int max_dlugosc = 0;
    for(int i = 0; i < N; i++){
        if(tab_par[i+1] != 0){
            if( max_dlugosc < tab_par[i+1] - tab_par[i] - 1) max_dlugosc = tab_par[i+1] - tab_par[i] - 1;
            if( tab_par[i+1] == tab_par[i] + 2 )
                cout << "(" << tab_par[i] << "," << tab_par[i+1] << ")" << endl;
        }
    }
    cout << max_dlugosc;
}

int main(){
    cin >> N;
    int tab_par [N+1];
    for (int i = 0; i < N + 1; i++)  tab_par[i] = 0;
    Sito_Eratostenesa(tab_par);
    Lista_Par(tab_par);
}