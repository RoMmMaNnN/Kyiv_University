#include <iostream>

using namespace std;

union IntBytes {
    int num;
    unsigned char bytes[sizeof(int)];
};

int main() {
    unsigned char temp;
    IntBytes data;
    data.num = 0x12345678;
    
    cout << "Original number: " << hex << data.num << endl;
    
    temp = data.bytes[0];
    data.bytes[0] = data.bytes[2];
    data.bytes[2] = temp;

    cout << "Modified number: " << hex << data.num << endl;

    return 0;
}
