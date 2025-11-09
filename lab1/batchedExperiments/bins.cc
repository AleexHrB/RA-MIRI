#include <iostream>
#include <random>
using namespace std;



int main(int argc, char** argv) {

    if (argc != 5) {
        cout << "Please introduce n,m ,beta and batched percentage" << endl;
    }

    //Balls
    unsigned int numBalls = atoi(argv[1]);
    //Bins
    unsigned int numBins = atoi(argv[2]);
    float beta = atof(argv[3]);
    float perc = atof(argv[4]);

    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<float> distr(0.00, 1.00);
    uniform_int_distribution<unsigned int> binDistr(0, numBins - 1);

    vector<unsigned int>config(numBins, 0);

    unsigned int batched = round(perc*numBalls);

    for (unsigned int i = 0; i < numBalls; i += batched) {
        vector<unsigned int>outConfig(batched);

        for (unsigned int j = 0; j < batched; ++j) {
            //Apply two-choice
            if (distr(gen) < beta) {
                unsigned int firstBin = binDistr(gen);
                unsigned int secondBin = binDistr(gen);
                if (config[firstBin] != config[secondBin]) {
                    bool firstChoice = config[firstBin] < config[secondBin];
                    outConfig[j] = firstChoice ? firstBin : secondBin;
                }

                else {
                    bool firstChoice = distr(gen) < 0.50f;
                    outConfig[j] = firstChoice ? firstBin : secondBin;
                }
            }

            else outConfig[j] = binDistr(gen);
        }

        for (unsigned int x: outConfig) ++config[x];
    }

    unsigned int max = 0;
    for (unsigned int i = 0; i < numBins; ++i) max = max > config[i] ? max : config[i];
    cout << max - float(numBalls)/float(numBins) << endl;
    //for (unsigned int i = 0; i < numBins; ++i) cout << i << " " << config[i] << endl;
}
