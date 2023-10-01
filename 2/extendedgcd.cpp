#include <iostream>
#include <gmpxx.h>
using namespace std;

using bigInteger =  mpz_class;

// Struktura reprezentująca trójkę
struct triple{
        bigInteger d, x, y;
};

triple extendedGCD(const bigInteger& a, const bigInteger& b){
    triple result;
    bigInteger modulus(b);
    if(b == 0) {
        result.x = 1;
        result.y = 0;
        result.d = a;
        return result;
    }
    else {
        result = extendedGCD(b, a%modulus);
    }
    bigInteger y1 = result.y;
    bigInteger x1 = result.x;
    result.x = y1;
    result.y = x1 - a/b * y1;
    return result;
}

int main(){
    bigInteger a("949802333333324698768392543852");
    bigInteger b("2504024333333333333349479973");
    triple result = extendedGCD(a, b);
    cout << "GCD(" << a << "," << b << ")=" << result.d << "\n";
    cout << "x=" << result.x << "\n";
    cout << "y=" << result.y << "\n";
    

    return 0;
}