#include <iostream>
#include <set>
#include <cmath>
#include "xxhash32.h"
#include <vector>
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
    //unsigned int p = h.hash(&k, sizeof(k), 0);

    string elem;
    unsigned int b = 4;
    unsigned int rest = 32 - b;
    unsigned int m = 1 << b;
    vector<unsigned int> R(m);


    while(cin >> elem) {
        const char* prueba = elem.c_str();
        unsigned int hashVal = h.hash(prueba, elem.length(), 0);
        unsigned int j = hashVal >> rest;
        unsigned int w = hashVal << rest;
            
        unsigned int firstOne = firstBit(w);
        R[j] = firstOne > R[j] ? firstOne : R[j];
    }
    double Z = 0.0;
    for (unsigned int j = 0; j < m; ++j) {
       Z += 1.0/double(1 << R[j]); 
    }
    Z = 1.0/Z;

    double E = m*m*Z;
    cout << E << endl;
}

