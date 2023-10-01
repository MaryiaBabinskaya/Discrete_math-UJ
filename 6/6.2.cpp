#include <iostream>
#include <list>
using namespace std;
const int N = 10;              // liczba wierzcholkow
list <int> adj_list[N+1];      // listy sasiedztwa. Wierzcholki NUMERUJEMY OD 1
bool DOPUSZCZALNE[N + 1];
int X[N + 1];                  // X[1..k] zawiera sciezke X[1],X[2],...,X[k]
void add_edge (int u,int v){
    adj_list[u].push_back(v);adj_list[v].push_back(u);
}
void construct_graph(){
    add_edge(1,3);add_edge(1,4);add_edge(1,6);
    add_edge(2,4);add_edge(2,5);add_edge(2,7);
    add_edge(3,5);add_edge(3,8);
    add_edge(4,9);add_edge(5,10);
    add_edge(6,7);add_edge(6,10);
    add_edge(7,8);add_edge(8,9);add_edge(9,10);
}
bool hamilton(int k){
    if ( k == (N + 1) ) {
        return true;
    }
    else{
        for(int u : adj_list[X[k-1]]){
            if(DOPUSZCZALNE[u]) {
                X[k] = u;
                DOPUSZCZALNE[u] = false;
                if (hamilton(k + 1) == true) return true;
                DOPUSZCZALNE[u] = true;
            }
        }
        return false;
    }
}
int main(){
    construct_graph();

    for (int i = 1; i <= N; i++)
        DOPUSZCZALNE[i] = true;

    DOPUSZCZALNE[4] = false;
    X[1] = 4;

    if (hamilton(2)){
        for (int i = 1;i <= N; i++)
            cout << X[i] << " ";
    }
    else{
        cout << "Graf nie ma sciezki Hamiltona" << endl;
    }
    return 0;
}
