#include <iostream>
#include <string>
#include <gmpxx.h>
using  bigInteger = mpz_class;
using namespace std;
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
int main() {
    bigInteger tekst("924824081784193");
    bigInteger N("1125907426181141");
    bigInteger p("1048583");
    bigInteger q("1073741827");
    bigInteger e("65537");
    bigInteger fi_n = (p - 1) * (q - 1);
    triple result = extendedGCD(fi_n, e);
    bigInteger d = (result.y + fi_n) % fi_n;
    bigInteger M1 = bigInteger("32393252822481");
    bigInteger M2 = bigInteger(tekst);
    bigInteger part1 = powerMod(M1, d, N);
    bigInteger part2 = powerMod(M2, d, N);
    string str1 = part1.get_str();
    string str2 = part2.get_str();
    string res = "";
    for(int i = 0; i < str1.size(); i += 2){
        string substring = str1.substr(i, 2);
        if(stoi(substring) != 36)
            res += (char) stoi(substring)+55;
        else
            res += " ";
    }
    for(int i = 0; i < str2.size(); i += 2){
        string substring = str2.substr(i, 2);
        if(stoi(substring) != 36)
            res += (char) stoi(substring)+55;
        else
            res += " ";
    }
    cout << res << endl;
    return 0;
}
