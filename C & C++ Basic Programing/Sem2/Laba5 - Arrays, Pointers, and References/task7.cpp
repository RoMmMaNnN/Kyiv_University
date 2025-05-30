#include <iostream>
using namespace std;

class samp {
    int i, j;
public:
    samp(int a = 0, int b = 0) { i = a; j = b; }
    
    void set_ij(int a, int b) {
        i = a;
        j = b;
    }

    int get_product() const {
        return i * j;
    }
    ~samp() {
        cout << "Destructor called for object with i = " << i << " and j = " << j << endl;
    }
};

int main() {
    samp* ptr = new samp[10];

    for (int i = 0; i < 10; i++) {
        ptr[i].set_ij(i, 1);
    }

    for (int i = 0; i < 10; i++) {
        cout << "Product [" << i << "] is: " << ptr[i].get_product() << endl;
    }

    delete[] ptr;

    return 0;
}
