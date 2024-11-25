#include <iostream>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    pid_t pid = fork(); // Create a new process

    if (pid < 0) {
        std::cerr << "Fork failed\n";
        return 1;
    }

    if (pid == 0) { 
        // Child process
        std::cout << "Child Process, PID: " << getpid() << "\n";
        sleep(2); // Simulate work
        std::cout << "Child Task Done\n";
    } 
    else { 
        // Parent process
        std::cout << "Parent Process, PID: " << getpid() << "\n";
        wait(NULL); // Wait for the child to complete
        std::cout << "Parent Task Done\n";
    }

    return 0;
}
