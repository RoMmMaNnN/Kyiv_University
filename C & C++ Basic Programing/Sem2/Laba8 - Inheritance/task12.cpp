#include <iostream>
using namespace std;

class coord {
public:
    int x, y;
    coord() : x(0), y(0) {}
    coord(int i, int j) : x(i), y(j) {}
    void get_xy(int &i, int &j) { i = x; j = y; }
    
    coord operator+(const coord& ob2) {
        coord temp;
        temp.x = x + ob2.x;
        temp.y = y + ob2.y;
        return temp;
    }

    coord operator-(const coord& ob2) {
        coord temp;
        temp.x = x - ob2.x;
        temp.y = y - ob2.y;
        return temp;
    }

    coord& operator=(const coord& ob2) {
        x = ob2.x;
        y = ob2.y;
        return *this;
    }
};

class quad : public coord {
public:
    int quadrant;
    quad() : coord(0, 0), quadrant(0) {}
    quad(int x, int y) : coord(x, y) {
        if (x >= 0 && y >= 0)
            quadrant = 1;
        else if (x < 0 && y >= 0)
            quadrant = 2;
        else if (x < 0 && y < 0)
            quadrant = 3;
        else
            quadrant = 4;
    }
    
    void showq() {
        cout << "Point in Quadrant: " << quadrant << endl;
    }
    
    quad operator+(const coord& ob2) {
        quad temp;
        temp.x = x + ob2.x;
        temp.y = y + ob2.y;

        if (temp.x >= 0 && temp.y >= 0)
            temp.quadrant = 1;
        else if (temp.x < 0 && temp.y >= 0)
            temp.quadrant = 2;
        else if (temp.x < 0 && temp.y < 0)
            temp.quadrant = 3;
        else
            temp.quadrant = 4;

        return temp;
    }

    quad operator-(const coord& ob2) {
        quad temp;
        temp.x = x - ob2.x;
        temp.y = y - ob2.y;

        if (temp.x >= 0 && temp.y >= 0)
            temp.quadrant = 1;
        else if (temp.x < 0 && temp.y >= 0)
            temp.quadrant = 2;
        else if (temp.x < 0 && temp.y < 0)
            temp.quadrant = 3;
        else
            temp.quadrant = 4;

        return temp;
    }
};

int main() {
    quad o1(10, 10), o2(15, 3), o3;
    int x, y;

    o3 = o1 + o2;
    o3.get_xy(x, y);
    cout << "(o1 + o2) X: " << x << " Y: " << y << endl;
    o3.showq();

    o3 = o1 - o2;
    o3.get_xy(x, y);
    cout << "(o1 - o2) X: " << x << " Y: " << y << endl;
    o3.showq();

    o3 = o1;
    o3.get_xy(x, y);
    cout << "(o3 = o1) X: " << x << " Y: " << y << endl;
    o3.showq();

    return 0;
}
