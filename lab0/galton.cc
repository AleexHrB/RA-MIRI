#include <iostream>
#include <random>
using namespace std;



int main(int argc, char** argv) {
    unsigned int n = atoi(argv[1]);
    unsigned int m = atoi(argv[2]);

    unsigned int galton[n];
    for (unsigned int i = 0; i < n; ++i) galton[i] = 0;

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distr(0, 1);

    //Simulate all balls
    for (unsigned int ball = 0; ball < m; ++ball) {

        unsigned int i = 0;
        unsigned int j = 0;

        for (unsigned int k = 0; k < n; ++k) {
            unsigned int rnd_num = distr(gen);
            i = i + 1 - rnd_num;
            j = j + rnd_num;
        }
        ++galton[i];
    }

    cout << "i,n" << endl;
    for (unsigned int i = 0; i < n; ++i) cout << i << "," << galton[i] << endl;
}
