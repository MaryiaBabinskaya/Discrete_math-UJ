#include <iostream>
#include <fstream>
using namespace std;

const int kolumny = 3;
const int wierszy = 2;
int matrix[kolumny][kolumny];
int dodatkowa_tab[wierszy];      //generowanie all permutacji
int submatrix[wierszy][kolumny];

void swap(int i,int j){
    int tmp = dodatkowa_tab[i];
    dodatkowa_tab[i] = dodatkowa_tab[j];
    dodatkowa_tab[j] = tmp;
}
void reverse(int start, int stop){
    int i = start;
    int j = stop;
    while (i < j){
        swap(i, j);
        ++i;
        --j;
    }
}
int nextPermutation(){      //generujemy nextPermutation(jak w 1 zadaniu)
    int k = -1;
    for(int i = 0; i < wierszy - 1; i++){
        if( dodatkowa_tab[i] < dodatkowa_tab[i+1] ) k = i;
    }
    if(k == -1) return -1;
    int l;
    for(int j = k + 1; j < wierszy; j++){
        if(dodatkowa_tab[j] > dodatkowa_tab[k]) {
            l = j;
        }
    }
    swap(l, k);
    reverse(k + 1, wierszy - 1);
}
int permanent_podtablicy(){     //tutaj tez generujemy podzbiory PODzbioru jak w 2 zadaniu
    int permanent_podtablicy = 0;
    int tab[wierszy];
    for(int i = 0; i < wierszy; i++){
        tab[i] = i;
    }
    int p = wierszy - 1;
    while(p >= 0){
        for(int i = 0; i < wierszy; i++){
            dodatkowa_tab[i] = tab[i];    //dodatkowa_tab przechowuje wszystkie permutacje tablicy tab
            // 1) p1 = 1         2) p1 = 2
            //  01 / 02 / 12     01 / 02 / 12
            //  01 / 02 / 12
        }
        do{
            int iloczyn = 1;
            for(int i = 0; i < wierszy; i++){
                iloczyn *= submatrix[i][dodatkowa_tab[i]];      //iloczyn jednej czworki
                // submatrix
                //1) p1 = 1                                        2) p1 = 2
                //   1010/1100/1100/1111/1101/1101                 0101/0111/0111
                //   np. 0101 ->  0 0  (x1 y2 x2 y1 )    x1 x2
                //                1 1                    y1 y2
            }
            // iloczyn
            // 10 -> 0  11 -> 1  00 -> 0
            // np. 1010 - 00 1100 - 10
            permanent_podtablicy += iloczyn;
        } while(nextPermutation() != -1); //idziemy po wszystkich permutacjach
        if( tab[wierszy-1] == kolumny - 1 ) p--;
        else p = wierszy - 1;
        if( p >= 0){
            for(int i = wierszy - 1; i >= p; i--)
                tab[i] = tab[p] + i - p + 1;
        }
    }
    return permanent_podtablicy;
}
int generateSubmatrix(){        //generujemy podzbiory zbioru jak w 2 zadaniu
    int tab[wierszy];           //jakie wierszy bierzemy
    int glowny_permanent = 0;
    for(int i = 0; i < wierszy; i++){
        tab[i] = i;
    }
    int p = wierszy - 1;
    while(p >= 0){
        for(int i = 0; i < wierszy; i++){
            for(int j = 0; j < kolumny; j++){
                submatrix[i][j] = matrix[tab[i]][j];
                //1) p1 = 1    2) p1 = 2
                //   110         001
                //   001         111

                //   110
                //   111
            }
        }
        glowny_permanent += permanent_podtablicy();
        // if podtablica
        //1) p1 = 1    2) p1 = 2
        //    2 4          2
        if ( tab[wierszy - 1] == kolumny - 1) p--;
        else p = wierszy - 1;
        if(p >= 0){
            for(int i = wierszy - 1; i >= p; i--)
                tab[i] = tab[p] + i - p + 1;
        }
    }
    return glowny_permanent;
}
int main(){
    ifstream File;
    string line;
    File.open("C:\\Users\\User\\Desktop\\Dyskretna\\Lab\\1\\3\\Macierz.txt");
    int i = 0;
    while(getline(File, line)){
        for(int j = 0; j < kolumny; j++){
            matrix[i][j] = line[j] - 48;
            //Example
            //110
            //001
            //111
        }
        i++;
    }
    cout << generateSubmatrix() << endl;
    //8
    File.close();
}