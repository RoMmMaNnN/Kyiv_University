#include <iostream>
#include <stdexcept>

template <typename T, std::size_t Size>
class SafeArray {
private:
    T arr[Size];

public:
    SafeArray() {
        for (std::size_t i = 0; i < Size; ++i) {
            arr[i] = T();
        }
    }

    T& operator[](std::size_t index) {
        if (index >= Size) {
            throw std::out_of_range("Index out of bounds");
        }
        return arr[index];
    }

    const T& operator[](std::size_t index) const {
        if (index >= Size) {
            throw std::out_of_range("Index out of bounds");
        }
        return arr[index];
    }

    std::size_t size() const {
        return Size;
    }
};

int main() {
    try {
        SafeArray<int, 5> arr;
        arr[0] = 10;
        arr[1] = 20;
        arr[2] = 30;
        arr[3] = 40;
        arr[4] = 50;

        std::cout << "Array elements:" << std::endl;
        for (std::size_t i = 0; i < arr.size(); ++i) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;

        std::cout << arr[5] << std::endl;
    } catch (const std::out_of_range& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    return 0;
}
