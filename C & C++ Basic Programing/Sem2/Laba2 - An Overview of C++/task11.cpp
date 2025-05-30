#include <iostream>
#include <thread>
#include <chrono>
#include <string>

void sleep(int seconds);
void sleep(const std::string& seconds_str);

int main() {
    sleep(3);
    sleep("2");

    return 0;
}

void sleep(int seconds) {
    std::this_thread::sleep_for(std::chrono::seconds(seconds));
    std::cout << "Sleeping during " << seconds << " seconds" << std::endl;
}

void sleep(const std::string& seconds_str) {
    int seconds = std::stoi(seconds_str);
    sleep(seconds);
}

