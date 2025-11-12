#include <iostream>
#include <random>
#include <algorithm>
using namespace std;



int main(int argc, char** argv) {

    if (argc != 4) {
        cout << "Please introduce n,m,k" << endl;
    }

    //Balls
    unsigned int numBalls = atoi(argv[1]);
    //Bins
    unsigned int numBins = atoi(argv[2]);
    //Questions
    unsigned int k = atoi(argv[3]);

    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<float> distr(0.00, 1.00);
    uniform_int_distribution<unsigned int> binDistr(0, numBins - 1);

    vector<unsigned int>config(numBins, 0);

    unsigned int med = numBins / 2;
    unsigned int medVal = 0;

    for (unsigned int i = 0; i < numBalls; ++i) {
        if (i > med) {
            nth_element(config.begin(), config.begin() + med, config.end());
            medVal = config[med];
        }

        unsigned int firstBin = binDistr(gen);
        unsigned int secondBin = binDistr(gen);
        bool firstChoice = config[firstBin] < medVal;
        bool secondChoice = config[secondBin] < medVal;

        if (firstChoice == secondChoice) {

            if (k == 2) {
                vector<unsigned int>clownFig(med);
                for (unsigned int i = 0; i < med ; ++i) clownFig[i] = config[i + med*(not firstChoice)];
                nth_element(clownFig.begin(), clownFig.begin() + numBins/4, clownFig.end());
                firstChoice = config[firstBin] < clownFig[numBins/4];
                secondChoice = config[secondBin] < clownFig[numBins/4];

                if (firstChoice == secondChoice) {
                    firstChoice = distr(gen) < 0.50f;
                    secondChoice = not firstChoice;
                }
            
            }

            else {
                firstChoice = distr(gen) < 0.50f;
                secondChoice = not firstChoice;
            }
        }


        if (firstChoice) ++config[firstBin];
        else ++config[secondBin];
    }

    unsigned int max = 0;
    for (unsigned int i = 0; i < numBins; ++i) max = max > config[i] ? max : config[i];
    cout << max - float(numBalls)/float(numBins) << endl;
    //for (unsigned int i = 0; i < numBins; ++i) cout << i << " " << config[i] << endl;
}
