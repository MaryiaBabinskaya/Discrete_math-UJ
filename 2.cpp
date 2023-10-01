#include <iostream>
using namespace std;

const int N = 5;        // generujemy podzbiory zbioru A[1],A[2],A[2],...,A[N]
int A[N+1];
/* ************** FUNKCJE POMOCNICZNE ***************************** */
void printTab(int k){
  for (int i= 1; i <= k; ++i)
    cout << A[i] << " ";
  cout << endl;
}
/* ************** FUNKCJE POMOCNICZNE ***************************** */

/* Funkcja generuje wszystkie k-elementowe podzbiory zbioru N elementowego i
 * na kazdym z nich wykonuje funkcje fun.
 */
void generateSubsets(int k, void (fun)(int)) {
    for (int i = 1; i <= k; i++) {
        A[i] = i;
    }
    int p = k;
    while (p >= 1) {
        fun(k);
        if (A[k] == N) {
            p--;
        }
        else p = k;
        if (p >= 1) {
            for (int i = k; i >= p; i--) {
                A[i] = A[p] + i - p + 1;
            }
        }
    }
}
int main(){
    generateSubsets(3,printTab);
    return 0;
}