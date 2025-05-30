#include <iostream>
#include <cstdlib>

using namespace std;

double my_atof(const char *s);
int my_atoi(const char *s);
long my_atol(const char *s);

int main() {
    const char* str = "123";

    cout << "Using standard atof: " << atof(str) << endl;
    cout << "Using standard atoi: " << atoi(str) << endl;
    cout << "Using standard atol: " << atol(str) << endl;

    return 0;
}

double my_atof(const char *s) {
    cout << "Custom atof() called\n";
    return 0.0;
}

int my_atoi(const char *s) {
    cout << "Custom atoi() called\n";
    return 0;
}

long my_atol(const char *s) {
    cout << "Custom atol() called\n";
    return 0L;
}
