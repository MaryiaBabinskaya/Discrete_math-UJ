#include <iostream>
#include <list>
using namespace std;
const int N = 8;              // liczba wierzcholkow
list <int> adj_list[N+1];     // listy sasiedztwa. Wierzcholki NUMERUJEMY OD 1
bool DOPUSZCZALNE[N + 1];
int X[N + 1];                  // X[1..k] zawiera sciezke X[1],X[2],...,X[k]
void add_edge (int u,int v){
    adj_list[u].push_back(v);adj_list[v].push_back(u);
}
void construct_graph(){
    add_edge(1,4);add_edge(1,5);add_edge(1,7);add_edge(1,8);
    add_edge(2,3);add_edge(2,4);add_edge(2,5);add_edge(2,6);add_edge(2,7);
    add_edge(3,8);
    add_edge(4,7);add_edge(4,8);
    add_edge(5,6);add_edge(5,8);
    add_edge(7,8);
}
bool hamilton(int k){
    if ( k == (N + 1) ){
        for(int u: adj_list[X[N]]){
            if( u == X[1]) return true;
        }
        return false;
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

    for (int i = 2;i <= N; ++i)
        DOPUSZCZALNE[i] = true;

    DOPUSZCZALNE[1] = false;
    X[1] = 1;

    if (hamilton(2)){
        for (int i = 1;i <= N; ++i)
            cout<<X[i]<<" ";
        cout<<X[1]<<endl;
    }
    else{
        cout<<"Graf nie ma cyklu Hamiltona"<<endl;
    }
    return 0;
}