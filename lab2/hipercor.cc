#include <iostream>
#include <set>
#include <cmath>
#include "xxhash32.h"
using namespace std;

unsigned int firstBit(unsigned int x) {
    unsigned int i = 1;
    if (x == 0) return 33;
    while (!(x & 0x80000000)) {
        x <<= 1;
        ++i;
    }

    return i;
}


int main(int argc, char**argv) {
    unsigned int k = atoi(argv[1]);
    XXHash32 h(0);
    unsigned int p = h.hash(&k, sizeof(k), 0);
    cout << p << endl;

    string elem;
    unsigned int r = 0;
    
    while(cin >> elem) {
        const char* prueba = elem.c_str();
        unsigned int hashVal = h.hash(prueba, elem.length(), 0);
        unsigned int firstOne = firstBit(hashVal);
        r = firstOne > r ? firstOne : r;
    }

    cout << r << endl;
}

