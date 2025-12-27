#include <iostream>
#include <set>
#include <cmath>
#include "xxhash32.h"
using namespace std;



int main(int argc, char**argv) {
    unsigned int k = atoi(argv[1]);
    XXHash32 h(0);
    set<unsigned int> s;

    unsigned int i = 0;

    string elem;
    while (i < k and cin >> elem) {
        const char* prueba = elem.c_str();
        unsigned int hashVal = h.hash(prueba, elem.length(), 0);
        if (s.find(hashVal) == s.end()) {
            ++i;
            s.insert(hashVal);
        }
    }

    unsigned int r = k;
    while (cin >> elem) {
        const char* prueba = elem.c_str();
        unsigned int hashVal = h.hash(prueba, elem.length(), 0);
        if (hashVal > *(s.begin()) and s.find(hashVal) == s.end()) {
            s.erase(s.begin());
            ++r;
            cout << r << endl;
            s.insert(hashVal);
        }
    }

    cout << - 1 + k * pow(1 + 1.0/k, r - k + 1) << endl;
}
