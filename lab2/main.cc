#include <iostream>
#include <set>
#include <cmath>
#include "xxhash32.h"
using namespace std;



int main(int argc, char**argv) {
    unsigned int k = atoi(argv[1]);
    XXHash32 h(0);
    //cout << h.hash(&n, sizeof(n), 0) << endl;
    set<unsigned int> s;

    unsigned int i = 0;

    while (i < k) {
        string elem;
        cin >> elem;
        const char* prueba = elem.c_str();
        unsigned int hashVal = h.hash(prueba, elem.length(), 0);
        cout << hashVal << endl;
        if (s.find(hashVal) == s.end()) {
            ++i;
            s.insert(hashVal);
        }
    }

    unsigned int r = k;
    string elem;
    while (cin >> elem) {
        unsigned int hashVal = h.hash(&elem, sizeof(elem), 0);
        if (hashVal > *(s.begin()) and s.find(hashVal) == s.end()) {
            s.erase(s.begin());
            ++r;
            cout << r << endl;
            s.insert(hashVal);
        }
    }

    cout << - 1 + k * pow(1 + 1.0/k, r - k + 1) << endl;
}
