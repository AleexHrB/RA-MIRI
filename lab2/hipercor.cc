#include <iostream>
#include <set>
#include <cmath>
#include "xxhash32.h"
#include <vector>
using namespace std;

unsigned int firstBit(unsigned int x) {
    unsigned int i = 1;
    if (x == 0) return 33;
    while (!(x & (1 << (32 - i)))) {
        ++i;
    }

    return i;
}


int main(int argc, char**argv) {
    unsigned int k = atoi(argv[1]);
    XXHash32 h(k);
    unsigned int p = h.hash(&k, sizeof(k), 0);

    string elem;
    unsigned int b = 4;
    unsigned int m = 1 << b;
    vector<unsigned int> R(m,0);
    double alphas[8] = {0.0438992,0.133109,0.312804355469,0.673102023868, 1.39424526760, 2.8368338114801, 5.7221695197, 11.4929222111};


    while(cin >> elem) {
        const char* prueba = elem.c_str();
        unsigned int hashVal = h.hash(prueba, elem.length(), k);
        unsigned int j = hashVal >> (sizeof(int)*8 - b);
        unsigned int w = hashVal << b;
            
        unsigned int firstOne = firstBit(w);
        R[j] = firstOne > R[j] ? firstOne : R[j];
    
    }
    double Z = 0.0;
    for (unsigned int j = 0; j < m; ++j) {
       Z += 1.0/pow(2,R[j]);
    }
    Z = 1.0/Z;

    //double alpha = tgamma(-1.0/m) * ((1 - pow(2.0,1.0/m))/log(2));
    //alpha = 1/pow(alpha,m);

    double alpha = alphas[b - 1];
    double E = m*m*Z * alpha;
    
    cout << E << endl;
}

