#include <iostream>
#include <unistd.h>

int main() {
    pid_t pid = fork(); // Create a new process

    if (pid < 0) {
        std::cerr << "Fork failed\n";
        return 1;
    }

    // Both parent and child execute the same code after fork()
    std::cout << "Process ID: " << getpid() << ", Parent ID: " << getppid() << "\n";

    // Simulating work common to both processes
    sleep(1); // Both parent and child will sleep for 1 second
    std::cout << "Task Done by Process ID: " << getpid() << "\n";

    return 0;
}
