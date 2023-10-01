//Skonstruowałam graf i zastosowałam algorytm Hamiltona.
//W grafie wierzchołki to pola szachownicy
//(numerowałam ich na taki sposób: np.32, czyli 3 rzad 2 kolumna),
//krawędzi dodawałam tak, jak chodzi skoczek (czyli dla kazdego wierzchołka mamy max 8 krawędzi)
//ale t.j. to była szachownica na torusie, nie tak łatwo to było połączyć,
//dlatego rozpatrywałam to przypadkami (niżej są komentarzy)
#include <iostream>
#include <list>
using namespace std;
const int N = 5;                     // rozmiar szachownicy
list <int> adj_list[N * 11 + 1];     // listy sasiedztwa. Wierzcholki NUMERUJEMY OD 1
bool DOPUSZCZALNE[N * 11 + 1];
int X[N * N + 1];                    // X[1..k] zawiera sciezke X[1],X[2],...,X[k]
void add_edge (int u,int v){
    adj_list[u].push_back(v);
   //adj_list[v].push_back(u); //żeby nie było podwójnych krawędzi
}
void construct_graph(){
    for(int i = 1; i < N + 1; i++){
        for(int j = 1; j < N + 1; j++){
            //ponizej fraza "problem z ..." oznacza
            //że będziemy skakać po 1) tylko po rzędach // 2) tylko po kolumnach // 3) i tam i tam
            //więc każdy przypadek rozważałam osobnie
////////////////////////////////////////////////////////////////////////////////
            // up
            if( i < 3 ) { // problem z i
                 if( j > N - 1 || j < 2 ){ // problem z j
                     int q = N + (i - 2);
                     if( j > N - 1 ) {
                         add_edge(i * 10 + j, q * 10 + (j - 1));
                         add_edge(i * 10 + j, q * 10 + 1);
                     }
                     else {
                         add_edge(i * 10 + j, q * 10 + N);
                         add_edge(i * 10 + j, q * 10 + (j + 1));
                     }
                 }
                 else { //nie ma problem z j
                     int q = N + (i - 2);
                     add_edge(i * 10 + j, q * 10 + (j - 1));
                     add_edge(i * 10 + j, q * 10 + (j + 1));
                 }
            }
            else { //nie ma problemu z i
                if( j > N - 1 || j < 2 ){ // problem z j
                        if( j > N - 1 ) {
                            add_edge(i * 10 + j, (i - 2) * 10 + (j - 1));
                            add_edge(i * 10 + j, (i - 2) * 10 + 1);
                        }
                        else {
                            add_edge(i * 10 + j, (i - 2) * 10 + N);
                            add_edge(i * 10 + j, (i - 2) * 10 + (j + 1));
                        }
                }
                else { //nie ma problem z j
                    add_edge(i * 10 + j, (i - 2) * 10 + (j - 1));
                    add_edge(i * 10 + j, (i - 2) * 10 + (j + 1));
                }
            }
////////////////////////////////////////////////////////////////////////////////
            // down
            if( i > N - 2 ) { // problem z i
                if( j > N - 1 || j < 2 ){ // problem z j
                    int q = (i + 2) - N;
                    if( j > N - 1 ) {
                        add_edge(i * 10 + j, q * 10 + (j - 1));
                        add_edge(i * 10 + j, q * 10 + 1);
                    }
                    else {
                        add_edge(i * 10 + j, q * 10 + N);
                        add_edge(i * 10 + j, q * 10 + (j + 1));
                    }
                }
                else { //nie ma problem z j
                    int q = (i + 2) - N;
                    add_edge(i * 10 + j, q * 10 + (j - 1));
                    add_edge(i * 10 + j, q * 10 + (j + 1));
                }
            }
            else { //nie ma problemu z i
                if (j > N - 1 || j < 2) { // problem z j
                    if (j > N - 1) {
                        add_edge(i * 10 + j, (i + 2) * 10 + (j - 1));
                        add_edge(i * 10 + j, (i + 2) * 10 + 1);
                    } else {
                        add_edge(i * 10 + j, (i + 2) * 10 + N);
                        add_edge(i * 10 + j, (i + 2) * 10 + (j + 1));
                    }
                } else { //nie ma problem z j
                    add_edge(i * 10 + j, (i + 2) * 10 + (j - 1));
                    add_edge(i * 10 + j, (i + 2) * 10 + (j + 1));
                }
            }
//////////////////////////////////////////////////////////////////////////////////
            // right
            if( j > N - 2 ) { // problem z j
                if( i > N - 1 || i < 2 ){ // problem z i
                    int q = (j + 2) - N;
                    if( i > N - 1 ) {
                        add_edge( i*10+j,(i-1)*10+q );
                        add_edge( i*10+j,1*10+q );
                    }
                    else {
                        add_edge( i*10+j,N*10+q );
                        add_edge( i*10+j,(i+1)*10+q );
                    }
                }
                else { //nie ma problem z i
                    int q = (j + 2) - N;
                    add_edge( i*10+j,(i-1)*10+q );
                    add_edge( i*10+j,(i+1)*10+q );
                }
            }
            else { //nie ma problemu z j
                if (i > N - 1 || i < 2 ) { // problem z i
                    if (i > N - 1 ) {
                        add_edge( i*10+j,(i-1)*10+(j+2) );
                        add_edge( i*10+j,1*10+(j+2) );
                    } else {
                        add_edge( i*10+j,N*10+(j+2) );
                        add_edge( i*10+j,(i+1)*10+(j+2) );
                    }
                } else { //nie ma problem z i
                    add_edge( i*10+j,(i-1)*10+(j+2) );
                    add_edge( i*10+j,(i+1)*10+(j+2) );
                }
            }
//////////////////////////////////////////////////////////////////////////////////
            // left
            if( j < 3 ) { // problem z j
                if( i > N - 1 || i < 2 ){ // problem z i
                    int q = N + (j - 2);
                    if( i > N - 1 ) {
                        add_edge( i*10+j,(i-1)*10+q );
                        add_edge( i*10+j,1*10+q );
                    }
                    else {
                        add_edge( i*10+j,N*10+q );
                        add_edge( i*10+j,(i+1)*10+q );
                    }
                }
                else { //nie ma problem z i
                    int q = N + (j - 2);
                    add_edge( i*10+j,(i-1)*10+q );
                    add_edge( i*10+j,(i+1)*10+q );
                }
            }
            else { //nie ma problemu z j
                if (i > N - 1 || i < 2 ) { // problem z i
                    if (i > N - 1 ) {
                        add_edge( i*10+j,(i-1)*10+(j-2) );
                        add_edge( i*10+j,1*10+(j-2) );
                    } else {
                        add_edge( i*10+j,N*10+(j-2) );
                        add_edge( i*10+j,(i+1)*10+(j-2) );
                    }
                } else { //nie ma problem z i
                add_edge( i*10+j,(i-1)*10+(j-2) );
                add_edge( i*10+j,(i+1)*10+(j-2) );
                }
            }
////////////////////////////////////////////////////////////////////////////////
        }
    }
}
bool hamilton(int k){
    if ( k == (N * N + 1) ){
        for(int u: adj_list[X[N * N]]){
            if( u == X[1]) return true;
        }
        return false;
    }
    else{
        for(int u : adj_list[X[k-1]]){
            if(DOPUSZCZALNE[u]) {
                X[k] = u;
                DOPUSZCZALNE[u] = false;
                if (hamilton(k + 1)) return true;
                DOPUSZCZALNE[u] = true;
            }
        }
        return false;
    }
}

int main(){
    construct_graph();

    for (int i = 1; i < N * 11 + 1; i++)
        DOPUSZCZALNE[i] = true;

    DOPUSZCZALNE[11] = false;
    X[1] = 11;

    for(int u: adj_list[X[1]]){
        DOPUSZCZALNE[u] = false;
        X[2] = u;
        if (hamilton(3)){
            for (int i = 1; i < N * N + 1; i++)
                cout << X[i] << " ";
            cout << X[1] << endl;
        }
        else{
            cout<<"Drogi takiej nie ma"<<endl;
        }
        for (int i = 1; i < N * 11 + 1; i++){
            DOPUSZCZALNE[i] = true;
            DOPUSZCZALNE[11] = false;
        }
    }
    return 0;
}