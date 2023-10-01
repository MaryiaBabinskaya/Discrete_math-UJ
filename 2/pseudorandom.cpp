#include <iostream>
#include <gmpxx.h>
using namespace std;
// Funkcja ma generowac ciag liczb pseudolosowych o dlugosci seqLength
// wg. algorytmu podanego na zajeciach.

long int pseudorandomSeq(long a, long c, long modulus, long seed, int seqLength){
           if ( seqLength == 0 ) return seed;
           else{
               long int x = pseudorandomSeq ( a, c, modulus, seed, seqLength - 1);
               if ( seqLength > 1 ) x = x << 15; // dla d podpunkta
               long number = (a * x + c)  % modulus;
               cout << number << " ";
               return number;
           }
}
int main(){
//    pseudorandomSeq(5,0,12,1,20);                  // a)
//    cout << endl << "==============" << endl;
//    pseudorandomSeq(17,0,512,1,20);               // b)
//    cout << endl << "==============" << endl;
//    pseudorandomSeq(22695477,1,4294967296,1,20);  // c)
//    cout << endl << "==============" << endl;
    pseudorandomSeq(22695477,1,4294967296,1,100);  // d)
    cout << endl << "==============" << endl;
}