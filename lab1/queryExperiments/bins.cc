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
    unsigned int seventyFive = numBins * 3 / 4;

    for (unsigned int i = 0; i < numBalls; ++i) {

        unsigned int firstChoice = binDistr(gen);
        unsigned int secondChoice = binDistr(gen);

        vector<unsigned int>clownFig = config;
        nth_element(clownFig.begin(), clownFig.begin() + med, clownFig.end());

        bool aboveMedianFirst = config[firstChoice] > clownFig[med];
        bool aboveMedianSecond = config[secondChoice] > clownFig[med];
        if (aboveMedianFirst != aboveMedianSecond) {
            if (aboveMedianFirst) ++config[secondChoice];
            else ++config[firstChoice];
        }

        else if (k == 2) {
            nth_element(clownFig.begin(), clownFig.begin() + seventyFive, clownFig.end());
            bool aboveSeventyFiveFirst = config[firstChoice] > clownFig[seventyFive];
            bool aboveSeventyFiveSecond = config[secondChoice] > clownFig[seventyFive];

            if (aboveSeventyFiveFirst != aboveSeventyFiveSecond) {
                if (aboveSeventyFiveFirst) ++config[secondChoice];
                else ++config[firstChoice];
            }

            else {
                if (distr(gen) < 0.50f) ++config[firstChoice];
                else ++config[secondChoice];
            }
        }

        else {
            if (distr(gen) < 0.50f) ++config[firstChoice];
            else ++config[secondChoice];
        }

    }

    unsigned int max = 0;
    for (unsigned int i = 0; i < numBins; ++i) max = max > config[i] ? max : config[i];
    cout << max - float(numBalls)/float(numBins) << endl;
    //for (unsigned int i = 0; i < numBins; ++i) cout << i << " " << config[i] << endl;
}
