#include <iostream>
using namespace std;

const int N = 8; //stala N - numer wierzcholkow
int sasiedzi[N + 2][N + 2]; //lista sasiadow

void add_edge (int u,int v){
    sasiedzi[u][v] = 1;
    sasiedzi[v][u] = 1;
}

void TreeEdges(int prufer[]){

    for(int i = 1; i <= N + 2; i++){   //inicjalizacja
        for(int j = 1; j <= N + 2; j++)
            sasiedzi[i][j] = 0;
    }

    int vertices = N + 2;
    int vertex_set[vertices];

    for (int i = 0; i < vertices; i++) //inicjalizacja
        vertex_set[i] = 0;

    for (int i = 0; i < vertices - 2; i++) //Liczba wystąpień wierzchołka w kodzie
        vertex_set[prufer[i] - 1] += 1;
    //69859241
    //1101110120

    //szukamy min liczbe, ktora nie byla w naszym kodzie prufera
    int j;
    for (int i = 0; i < vertices - 2; i++) {
        for (j = 0; j < vertices; j++) {
            if (vertex_set[j] == 0) { //jesli liczba nie wystepuje w kodzie prufera
                vertex_set[j] = -1;
                add_edge(j+1, prufer[i]);
                cout << "(" << (j + 1) << ", " << prufer[i] << ") ";
                vertex_set[prufer[i] - 1]--; //w vertex_set mniejszymy liczbe
                break;
            }
        }
    }

    j = 0;
    //dla ostatniej pary
    int x, y;
    for (int i = 0; i < vertices; i++) {
        if (vertex_set[i] == 0 && j == 0) {
            cout << "(" << (i + 1) << ", ";
            x = i + 1;
            j++;
        }
        else if (vertex_set[i] == 0 && j == 1)
            cout << (i + 1) << ")\n";
        y = i + 1;
    }
    add_edge(x,y);
}

int main(){
    int prufer [N];
    //random
    for(int i = 0; i < N; i++) {
        int n = 1 + rand() % 9;;
        cout << n << " ";
        prufer [i] = n;
    }
    cout << "\n" ;
    TreeEdges(prufer);
    //tabelka sasiadow (1 - relacja, 0 - nie ma relacji)
//    cout << "1 2 3 4 5 6 7 8 9 10" << "\n";
//    for(int i = 1; i <= N + 2; i++){
//        for(int j = 1; j <= N + 2; j++)
//            cout << sasiedzi[i][j] << " ";
//        cout << "\n" ;
//    }
      for(int i = 1; i <= N + 2; i++){
          cout << "Sasiedzi wierzcholka " << i << ": ";
          for(int j = 1; j <= N + 2; j++){
              if(sasiedzi[i][j] == 1) cout << j << " ";
          }
          cout << "\n";
      }

    return 0;
}