#include <iostream>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

char* standard_reverse(const char* str, const int& count) {
    int length = strlen(str);
    char* temp = new char[length + 1];
    strcpy(temp, str);

    for (int i = 0; i < count; i++) {
        int idx1 = i;
        int idx2 = length - i - 1;

        char swap = temp[idx1];
        temp[idx1] = temp[idx2];
        temp[idx2] = swap;
    }

    return temp;
}

char* random_reverse(const char* str, const int& count) {
    int length = strlen(str);
    char* temp = new char[length + 1];
    strcpy(temp, str);

    vector<int> swappedIndices;

    for (int i = 0; i < count; i++) {
        int idx1 = rand() % length;
        int idx2 = rand() % length;

        while (find(swappedIndices.begin(), swappedIndices.end(), idx1) != swappedIndices.end() ||
               find(swappedIndices.begin(), swappedIndices.end(), idx2) != swappedIndices.end() ||
               idx1 == idx2) {
            idx1 = rand() % length;
            idx2 = rand() % length;
        }

        swap(temp[idx1], temp[idx2]);

        swappedIndices.push_back(idx1);
        swappedIndices.push_back(idx2);
    }

    return temp;
}

char* reverse(const char* str, const int& count = -1) {
    int length = strlen(str) / 2;

    if (count == -1) {
        return standard_reverse(str, length);
    }

    if (count > length) {
        cout << "Error: count exceeds string length." << endl;
        return nullptr;
    }

    return random_reverse(str, count);
}

int main() {
    const char str[] = "Hello my favourite beautiful world!";
    
    cout << "Original string: " << str << endl;

    char* rev1 = reverse(str, 5);
    cout << "Count = 5: " << rev1 << endl;
    delete[] rev1;

    char* rev2 = reverse(str);
    cout << "Without count: " << rev2 << endl;
    delete[] rev2;

    return 0;
}
