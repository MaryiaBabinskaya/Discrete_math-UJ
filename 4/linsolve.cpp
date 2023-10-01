#include <iostream>
#include <gmpxx.h>
using bigInteger =  mpz_class;
using namespace std;
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

//Funckja obliczajaca odwrotnosc, prosze zalozyc, ze
// a bedzie zawsze wzglednie pierwsze z N

bigInteger inverse(const bigInteger& a, const bigInteger& N){
    bigInteger x0 = extendedGCD(N,a%N).y;
    if(x0 < 0) x0 = N + x0;
    return x0;
}

// Procedura wypisujaca na standardowe wyjscie wszystkie rozwiazania rownania ax = b mod n

void linsolve(const bigInteger& a, const bigInteger& b, const bigInteger& n){
    bigInteger d = extendedGCD(a,n).d; // d = NWD(a,n)
    if(b % d != 0) cout << "BRAK"<< endl;  // if d /| b
    else{
        bigInteger a1 = a/d;
        bigInteger b1 = b/d;
        bigInteger n1 = n/d;
        bigInteger x0 = inverse(a1,n1);  //rozwiazanie a1x = b1 w Zn1
        x0 = x0 * b1;
        for(int i = 0; i < d; i++){
            cout << (x0 + i * n1) % n << endl;
        }
    }
}
// Procedura wypisujaca na standardowe wyjscie wszystkie rozwiazania rownania ax=b mod n

int main(){
//    linsolve(15, 9, 21);   // 9 16 2
//    linsolve(6, 20, 33);   // BRAK
    return 0;
}
