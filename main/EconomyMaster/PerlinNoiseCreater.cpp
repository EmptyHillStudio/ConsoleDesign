#include "PerlinNoiseCreater.h"
#include <iostream>
#include <math.h>

double fade(double t) {
    return 6 * pow(t, 5) - 15 * pow(t, 4) + 10 * pow(t, 3);
}

double PerlinNoiseCreater::RandomNumber(unsigned seed) {
    srand(seed);
    return sin(rand() % 100);
}
PerlinNoiseCreater::PerlinNoiseCreater(double Oct, double Per) {
    this->Octaves = Oct;
    this->Persistence = Per;
    double temp[2] = { RandomNumber(time(0)) ,RandomNumber(time(0) % 113) };
    this->PerlinList.insert(PerlinList.begin(), temp[0]);
    this->PerlinList.insert(PerlinList.begin(), temp[1]);
}

double PerlinNoiseCreater::Interpolate(double x1, double x2, int in) {
    return x1 + in * (x2 - x1);
}

double PerlinNoiseCreater::getNoiseData(int Data,int Random) {
    double sum = 0, frequency = 1, amplitude = 1, maxValue = 0;
    if (Data<=(this->PerlinList.size() - 1 )*50) {
        sum = temp(sum, frequency, amplitude, maxValue, Data);
    }
    else {
        this->PerlinList.insert(PerlinList.begin(), RandomNumber(time(0)));
        sum = temp(sum, frequency, amplitude, maxValue, Data);
    }
    sum *= cos(Random);
    return sum;
}
PerlinNoiseCreater::~PerlinNoiseCreater() {
    this->PerlinList.clear();
}
double PerlinNoiseCreater::temp(double sum, double frequency, double amplitude, double maxValue, int Data) {
    double temp = sum;
    double x[2];
    list<double>::iterator it = PerlinList.begin();
    for (int k = 0;k < 2;k++, it++) {
        x[k] = *it;
        cout << x[k] << endl;
    }
    cout << "\n";
    for (int j = 0;j < this->Persistence; j++) {
        for (int i = 0;i < this->Octaves;i++, frequency *= 2.0, amplitude *= 0.5) {
            temp += (Interpolate(fade(x[1] * frequency), fade(x[0] * frequency), Data) * amplitude);
            maxValue += amplitude;
        }
        temp /= maxValue;
    }
    return temp;
}
