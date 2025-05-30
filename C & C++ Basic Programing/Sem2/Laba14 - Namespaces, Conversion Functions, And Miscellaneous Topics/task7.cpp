#include <iostream>
#include <cstdlib>
using namespace std;

class myclass {
    int a;
public:
    explicit myclass(int x) { a = x; }          // explicit для int
    myclass(const char* str) { a = atoi(str); } // не explicit для const char*
    int geta() { return a; }
};

void print_myclass(myclass obj) {
    cout << obj.geta() << endl;
}

int main() {
    // myclass obj1 = 5;   // не можна неявно конвертувати int у myclass (explicit)
    myclass obj2 = "123";   // неявне перетворення з const char* на myclass працює
    print_myclass("456");   // неявне перетворення з const char* працює

    // print_myclass(789);  // explicit конструктор забороняє неявне перетворення int->myclass

    myclass obj3(789);      // прямий виклик конструктора explicit

    cout << "obj2: " << obj2.geta() << endl;
    cout << "obj3: " << obj3.geta() << endl;

    return 0;
}
