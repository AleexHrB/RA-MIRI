#include <iostream>
#include <set>
#include <cmath>
#include "xxhash32.h"
#include <random>
using namespace std;



int main(int argc, char**argv) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<unsigned int> dist(0, 4294967295);
    unsigned int seed = dist(gen);

    unsigned int k = atoi(argv[1]);
    XXHash32 h(seed);
    set<unsigned int> s;

    unsigned int i = 0;

    string elem;
    while (i < k and cin >> elem) {
        const char* prueba = elem.c_str();
        unsigned int hashVal = h.hash(prueba, elem.length(), seed);
        if (s.find(hashVal) == s.end()) {
            ++i;
            s.insert(hashVal);
        }
    }

    unsigned int r = k;
    while (cin >> elem) {
        const char* prueba = elem.c_str();
        unsigned int hashVal = h.hash(prueba, elem.length(), seed);
        if (hashVal > *(s.begin()) and s.find(hashVal) == s.end()) {
            s.erase(s.begin());
            ++r;
            s.insert(hashVal);
        }
    }

    cout << - 1 + k * pow(1 + 1.0/k, r - k + 1) << endl;
}
