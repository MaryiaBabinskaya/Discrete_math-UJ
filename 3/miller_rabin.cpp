#include <iostream>
#include <gmpxx.h>
#include <time.h>

using namespace std;
using bigInteger = mpz_class;

// Funkcje dotyczace generowania wielkich liczb losowych

gmp_randclass rr(gmp_randinit_default);

void initalize_random(){
    rr.seed(time(NULL));
}

// Ponizsza funkcja zwraca losowa liczbe z przedzialu [0,...upper_bound)
bigInteger randomInt(bigInteger upper_bound){
    return rr.get_z_range(upper_bound);
}

// Funkcja powerMod z zajec

bigInteger powerMod(const bigInteger &a, const bigInteger &b, const bigInteger &n){
    bigInteger z = a % n, y = 1, m = b;
    while (m != 0){
        if ((m % 2) == 1)
            y = (y * z) % n;
        m = m / 2;
        z = (z * z) % n;
    }
    return y;
}

bool miller_rabin(bigInteger N, bigInteger trials){
    bigInteger a = 2 + randomInt(N-1);
    bigInteger x = powerMod(a, trials, N);

    if (x == 1  || x == N - 1)
       return true;
    while (trials != N - 1){
        x = (x * x) % N;
        trials *= 2;
        if (x == N - 1)    return true;
    }
    return false;
}

int main(){
    initalize_random();
    bigInteger N("221"); // liczba, ktora testujemy

    if (miller_rabin(N, 10))
        cout << "Pierwsza";
    else
        cout << "Zlozona";
}
