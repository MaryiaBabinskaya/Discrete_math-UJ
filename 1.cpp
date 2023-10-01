#include <iostream>
using namespace std;
const int N = 5;   // rozmiar tablicy do permutowania
int tab[N+1];	 // permutujemy tablice t[1..N] (dla wygody indeksujemy od 1)
/* Pomocnicze funkcje:
 * initTab()     -> tab={1,2,...,N}
 * printTab()    -> wyswietla tablice
 * swap(i,j)     -> tab[i] <-> tab[j]
 * reverse (...) -> odwraca podtablice tab[start...stop]
 */
/* *************************** FUNKCJE POMOCNICZE **********************/
void initTab(){
//    for (int i = 1;i <= N; ++i)
//        tab[i] = i;
      tab[1]=3;
      tab[2]=2;
      tab[3]=5;
      tab[4]=6;
      tab[5]=1;
}
void printTab(){
    for (int i = 1;i <= N; ++i)
        cout << tab[i] <<" ";
    cout << endl;
}
void swap(int i,int j){
    int tmp = tab[i];
    tab[i] = tab[j];
    tab[j] = tmp;
}
void reverse(int start, int stop){
    int i = start;
    int j = stop;
    while (i < j){
        swap(i, j);
        ++i;--j;
    }
}
/* *************************** FUNKCJE POMOCNICZE *********************/

/* **************************** TODO *********************************/
int nextPermutation(){
//    int k = N - 1;
//    int l = N;
//    while( tab[k] > tab[k+1] )
//        if ( k > 1 ) k--;
//        else return 0;
//    while( tab[l] < tab[k] ) l--;
//    swap(l,k);
//    reverse(k+1,N);
//    return 1;
 int k;
 for(int i = 0; i < N; i++){
    if( tab[i] < tab[i+1]) k = i;
 }
 if(k == 0) return 0;
 int l;
 for(int j = k + 1; j < N + 1; j++){
     if( tab[j] > tab[k] ){
         l = j;
     }
 }
 swap(l,k);
 reverse(k+1,N);
 }
/* Funkcja fun to funkcja, ktora ma byc wykonywana na kazdej permutacji.
 * w funkcji main przyjeto akurat, ze bedzie to po prostu wypisywanie
 * permutacji
*/
int generateAllPermutations(void (fun)()){
    while (true) {
        fun ();
        if ( nextPermutation() == 0 ) break;
    }
    return 0;
}
/* ****************************  TODO ******************************* */
int main(){
    initTab();
    generateAllPermutations(printTab);
    return 0;
}