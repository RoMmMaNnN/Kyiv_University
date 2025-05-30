#include <iostream>
using namespace std;

template <class T>
T mostFrequent(T* arr, int size) {
    int maxCount = 0;
    T mostFreq = arr[0];

    for (int i = 0; i < size; i++) {
        int count = 1;
        for (int j = i + 1; j < size; j++) {
            if (arr[i] == arr[j]) {
                count++;
            }
        }
        if (count > maxCount) {
            maxCount = count;
            mostFreq = arr[i];
        }
    }

    return mostFreq;
}

int main() {
    int a[] = {1, 2, 2, 3, 4, 2, 5};
    char b[] = {'a', 'b', 'a', 'c', 'a', 'b'};

    cout << "Most frequent in int array: " << mostFrequent(a, 7) << endl;
    cout << "Most frequent in char array: " << mostFrequent(b, 6) << endl;

    return 0;
}
