#include <iostream>
#include <gmpxx.h>
using namespace std;
using  bigInteger = mpz_class;

// Funkcja obliczajaca a^b mod n

bigInteger powerMod(const bigInteger& a, const bigInteger& b, const bigInteger& n){
    bigInteger modulus(n);
    bigInteger z = a % modulus;
    bigInteger y = 1;
    bigInteger m = b;
    while( m > 0 ){
        if( m % 2 != 0 ) y = (y * z) % modulus;
        m = m / 2;
        z = (z * z) % modulus;
    }
    return y;
}

int main(){
    bigInteger a("7");
    bigInteger n("624423990187"); //1 przypadek 624423990187 NIE
                                  // 2 przypadek 225898512559 TAK
    bigInteger b( n - 1 );
    cout << powerMod(a, b, n) << "\n";
    return 0;
}