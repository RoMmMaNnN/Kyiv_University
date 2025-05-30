#include <iostream>
#include <exception>
#include <cstdlib>

void myTerminate() {
    std::cerr << "Program terminated due to an unhandled exception.\n";
    std::abort();
}

int main() {
    std::set_terminate(myTerminate);

    try {
        throw std::runtime_error("Some error occurred!");
    } catch (const std::exception& e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    throw 42;

    return 0;
}
