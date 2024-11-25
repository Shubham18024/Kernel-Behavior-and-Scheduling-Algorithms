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
        std::cout << "Child process, PID: " << getpid() << " executing 'ls -l'\n";
        execlp("ls", "ls", "-l", NULL); // Replace the child process with "ls -l" command
        std::cerr << "Error executing 'ls -l'\n";
    } 
    else { 
        // Parent process
        std::cout << "Parent process, PID: " << getpid() << "\n";
        wait(NULL); // Wait for the child to complete
        std::cout << "Parent Task Done\n";
    }

    return 0;
}
