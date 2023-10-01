#include <iostream>
#include <cmath>
#include <gmpxx.h>
using namespace std;
using bigInteger = mpz_class;
// Funkcja powerMod z zajec
bigInteger powerMod(const bigInteger& a, const bigInteger& b, const bigInteger& n){
    bigInteger z = a % n, y = 1, m = b;
    while (m != 0){
        if ((m % 2) == 1)
            y = (y * z) % n;
        m = m / 2;
        z = (z * z) % n;
    }
    return y;
}
// Funkcja extendedGCD
struct triple{
    bigInteger d, x, y;
};
triple extendedGCD(const bigInteger& a, const bigInteger& b){
    triple result;
    if (b == 0){
        result.d = a;
        result.x = 1;
        result.y = 0;
        return result;
    }
    else{
        triple temporary = extendedGCD(b, a % b);
        result.d = temporary.d;
        result.x = temporary.y;
        result.y = temporary.x - (a / b) * temporary.y;
        return result;
    }
}

// ponizsza funkcja zwraca true jesli liczba N>=2 jest pierwsza
// oraz false w przeciwnym przypadku.

bool isPrime(int N){
    if (N == 2)
        return true;
    float limit = sqrt(N);
    for (int i = 3; i <= limit; i +=2){
        if ((N % i) == 0)
            return false;
    }
    return true;
}
bool isCarmichael(int N){
      if ( isPrime(N) )
        return false;
      else{
          for(int i = 1; i < N; i++){
             if(extendedGCD(i,N).d == 1){
                 if( powerMod ( i, N - 1, N) != 1 ){
                   return false;
                 }
             }
           }
           return true;
      }
}
void generateCarmichaels(int start, int stop){
    int counter = 1;
    for (int i = start; i <= stop; ++i)
        if (isCarmichael(i)){
            cout << counter << ": " << i << endl;
            ++counter;
        }
}
int main(){
    generateCarmichaels(2, 100000); //9562
    return 0;
}
//1: 561
//2: 1105
//3: 1729
//4: 2465
//5: 2821
//6: 6601
//7: 8911
//8: 10585
//9: 15841
//10: 29341
//11: 41041
//12: 46657
//13: 52633
//14: 62745
//15: 63973
//16: 75361