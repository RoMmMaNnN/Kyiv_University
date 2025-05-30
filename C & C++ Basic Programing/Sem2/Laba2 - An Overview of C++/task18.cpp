#include <iostream>
using namespace std;

class mybox {
private:
    double length, width, height;
    double volume_result;

public:
    mybox(double l, double w, double h) {
        length = l;
        width = w;
        height = h;
        volume_result = length * width * height;
    }
    void volume() {
        cout << "Volume of the box: " << volume_result << endl;
    }
};

int main() {
    double length, width, height;
    
    cout << "Enter length, width, and height of the box: ";
    cin >> length >> width >> height;
    mybox box(length, width, height);
    box.volume();

    return 0;
}
