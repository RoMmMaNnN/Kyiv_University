#include <iostream>

using namespace std;

class PrinterManager {
public:
    static bool printer_busy;
};

bool PrinterManager::printer_busy = false;

class Pr2;

class Pr1 {
private:
    bool using_printer;

public:
    Pr1() { using_printer = false; }

    bool set_print(int status) {
        if (status == 1) {
            if (PrinterManager::printer_busy) {
                cout << "Pr1 cann't use printer, he already in use! Wait please..." << endl;
                return false;
            } else {
                PrinterManager::printer_busy = true;
                using_printer = true;
                cout << "Pr1 is using printer" << endl;
            }
        } else {
            PrinterManager::printer_busy = false;
            using_printer = false;
            cout << "Pr1 isn't using printer" << endl;
        }
        return true;
    }

    friend bool inuse(const Pr1 &p1, const Pr2 &p2);
};

class Pr2 {
private:
    bool using_printer;

public:
    Pr2() { using_printer = false; }

    bool set_print(int status) {
        if (status == 1) {
            if (PrinterManager::printer_busy) {
                cout << "Pr2 cann't use printer, he already in use! Wait please..." << endl;
                return false;
            } else {
                PrinterManager::printer_busy = true;
                using_printer = true;
                cout << "Pr2 is using printer" << endl;
            }
        } else {
            PrinterManager::printer_busy = false;
            using_printer = false;
            cout << "Pr2 isn't using printer" << endl;
        }
        return true;
    }

    friend bool inuse(const Pr1 &p1, const Pr2 &p2);
};

bool inuse(const Pr1 &p1, const Pr2 &p2) {
    return PrinterManager::printer_busy;
}

int main() {
    Pr1 o1;
    Pr2 o2;

    cout << "Is printer busy? " << (inuse(o1, o2) ? "Yes" : "No") << endl;
    o1.set_print(1);

    cout << "Is printer busy? " << (inuse(o1, o2) ? "Yes" : "No") << endl;
    o2.set_print(1);

    cout << "Is printer busy? " << (inuse(o1, o2) ? "Yes" : "No") << endl;
    o1.set_print(0);

    cout << "Is printer busy? " << (inuse(o1, o2) ? "Yes" : "No") << endl;
    o2.set_print(1);

    cout << "Is printer busy? " << (inuse(o1, o2) ? "Yes" : "No") << endl;
    o2.set_print(0);

    cout << "Is printer busy? " << (inuse(o1, o2) ? "Yes" : "No") << endl;

    return 0;
}
