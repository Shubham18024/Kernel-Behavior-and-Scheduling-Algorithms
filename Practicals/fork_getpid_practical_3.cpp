#include <iostream>
#include <unistd.h>

int main() {
    pid_t pid = fork();

    if (pid > 0) {
        std::cout << "Parent process, PID: " << getpid() << std::endl;
    } else if (pid == 0) {
        std::cout << "Child process, PID: " << getpid() << std::endl;
    } else {
        std::cout << "Fork failed." << std::endl;
    }

    return 0;
}

