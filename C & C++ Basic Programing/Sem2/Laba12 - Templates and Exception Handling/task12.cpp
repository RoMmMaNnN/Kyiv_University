#include <iostream>
#include <new>

int* allocateMemoryWithNull(int size) {
    int* ptr = new(std::nothrow) int[size];
    if (ptr == nullptr) {
        std::cout << "Memory allocation failed!" << std::endl;
    }
    return ptr;
}

int* allocateMemoryWithException(int size) {
    int* ptr = new int[size];
    return ptr;
}

int main() {
    int* arr1 = allocateMemoryWithNull(100000000);
    if (arr1 != nullptr) {
        std::cout << "Memory allocated successfully (with null check)!" << std::endl;
        delete[] arr1;
    }

    try {
        int* arr2 = allocateMemoryWithException(100000000);
        std::cout << "Memory allocated successfully (with exception)!" << std::endl;
        delete[] arr2;
    } catch (const std::bad_alloc& e) {
        std::cout << "Memory allocation failed (with exception): " << e.what() << std::endl;
    }

    return 0;
}
