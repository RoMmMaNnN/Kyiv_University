#include <iostream>
using namespace std;

int dif(int a, int b) { return a - b; }
float dif(float a, float b) { return a - b; }

int main() {
    int (*intDif)(int, int) = dif;
    float (*floatDif)(float, float) = dif;
    cout << intDif(7, 9) << endl;
    cout << floatDif(7.9f, 7.4f) << endl;

    return 0;
}
