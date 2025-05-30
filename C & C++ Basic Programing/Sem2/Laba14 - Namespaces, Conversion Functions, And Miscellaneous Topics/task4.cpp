#include <iostream>
#include <cstring>
using namespace std;

class output {
    static char outbuf[255];
    static int inuse;
    static int oindex;

    char str[80];
    int i;
    int who;

public:
    output(int w, const char *s) { //const char *s це рядок
        strcpy(str, s);
        i = 0;
        who = w;
    }

    int putbuf() {
        if (!str[i]) {
            if (inuse == who) {
                inuse = 0;
            }
            return 0;
        }

        if (inuse != 0 && inuse != who) {
            cout << "Object " << who << " is waiting for buffer (occupied by " << inuse << ").\n";
            return -1;
        }

        if (inuse == 0) {
            inuse = who;
        }

        outbuf[oindex++] = str[i++];
        outbuf[oindex] = '\0';

        cout << "Object " << who << " writing: " << outbuf << '\n';

        return 1;
    }

    void show() {
        cout << "Final output: " << outbuf << '\n';
    }
};//звернення до статичних змін

char output::outbuf[255];
int output::inuse = 0;
int output::oindex = 0;

int main() {
    output obj1(1, "This is a test");
    output obj2(2, " of statics");

    while (obj1.putbuf() | obj2.putbuf());

    obj1.show();

    return 0;
}
