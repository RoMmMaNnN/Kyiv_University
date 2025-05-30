#include <iostream>
#include <cctype>
#include <cstdlib>

using namespace std;

long mystrtol(const char *start, char **end = nullptr, int base = 0) {
    if (!start) return 0;

    const char *ptr = start;
    while (isspace(*ptr)) ptr++;

    int sign = 1;
    if (*ptr == '-' || *ptr == '+') {
        if (*ptr == '-') sign = -1;
        ptr++;
    }

    if (base == 0) {
        if (*ptr == '0') {
            if (*(ptr + 1) == 'x' || *(ptr + 1) == 'X') {
                base = 16; ptr += 2;
            } else {
                base = 8;
            }
        } else {
            base = 10;
        }
    }

    long result = 0;
    while (*ptr) {
        int digit;
        if (isdigit(*ptr)) digit = *ptr - '0';
        else if (isalpha(*ptr)) digit = toupper(*ptr) - 'A' + 10;
        else break;

        if (digit >= base) break;

        result = result * base + digit;
        ptr++;
    }

    if (end) *end = (char *)ptr;
    return sign * result;
}

int main() {
    const char *str1 = "77777";
    const char *str2 = "0101010";
    const char *str3 = "0x3E7D";
    char *endptr;

    cout << "Base 10: " << mystrtol(str1, &endptr, 0) << " (Expected: " << strtol(str1, &endptr, 0) << ")" << endl;
    cout << "Base 8: " << mystrtol(str2, &endptr, 0) << " (Expected: " << strtol(str2, &endptr, 0) << ")" << endl;
    cout << "Base 16: " << mystrtol(str3, &endptr, 0) << " (Expected: " << strtol(str3, &endptr, 0) << ")" << endl;

    return 0;
}
