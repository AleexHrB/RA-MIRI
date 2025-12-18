#include <iostream>
#include <random>
#include <vector>
#include <cmath>
using namespace std;




int main(int argc, char**argv) {

    unsigned int distinctElems = atoi(argv[1]);
    unsigned int zSize = atoi(argv[2]);
    float alpha = atof(argv[3]);

    float cn = 0;
    for (unsigned int i = 1; i <= distinctElems; ++i) cn += pow(i, -alpha);
    cn = 1.0/cn;

    vector<unsigned int> elems(distinctElems);
    vector<float> weights(distinctElems);
    for (unsigned int i = 0; i < distinctElems; ++i) {
        elems[i] = i;
        weights[i] = cn / (pow(i+1, alpha));
    }

    random_device rd;
    mt19937 gen(rd());
    discrete_distribution<unsigned int> dist(weights.begin(), weights.end());

    for (unsigned int i = 0; i < zSize; ++i) cout << dist(gen) << endl;
}
