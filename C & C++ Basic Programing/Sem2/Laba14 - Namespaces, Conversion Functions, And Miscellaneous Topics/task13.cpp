#include <iostream>

// Функція користувача з ім’ям cout у глобальному просторі імен
void cout() {
    std::cout << "User function cout\n";
}

int main() {
    // Якщо стандартна бібліотека була б у глобальному просторі,
    // то тут був би конфлікт між std::cout та cout()
    std::cout << "Standard output\n"; // Чітко вказуємо std::cout
    cout(); // Викликаємо користувацьку функцію cout без конфліктів

    return 0;
}
