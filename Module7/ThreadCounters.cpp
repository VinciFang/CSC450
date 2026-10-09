#include <exception>
#include <iostream>
#include <thread>

namespace {
constexpr int MIN_COUNT = 0;
constexpr int MAX_COUNT = 20;

void countUp() {
    std::cout << "Thread 1: Counting up\n";
    for (int counter = MIN_COUNT; counter <= MAX_COUNT; ++counter) {
        std::cout << counter << '\n';
    }
    std::cout << "Thread 1 completed.\n\n";
}

void countDown() {
    std::cout << "Thread 2: Counting down\n";
    for (int counter = MAX_COUNT; counter >= MIN_COUNT; --counter) {
        std::cout << counter << '\n';
    }
    std::cout << "Thread 2 completed.\n";
}
} // namespace

int main() {
    try {
        std::cout << "Two-Thread Counter Application\n\n";

        // Finish the first worker before starting the second.
        std::thread firstThread(countUp);
        firstThread.join();

        std::thread secondThread(countDown);
        secondThread.join();

        std::cout << "\nBoth threads finished successfully.\n";
        std::cout.flush();
        if (!std::cout) {
            std::cerr << "Error: Console output failed.\n";
            return 1;
        }
    } catch (const std::exception& exception) {
        std::cerr << "Application error: " << exception.what() << '\n';
        return 1;
    }

    return 0;
}
