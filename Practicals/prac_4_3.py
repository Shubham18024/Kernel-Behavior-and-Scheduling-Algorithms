import os

def main():
    pid = os.fork()  # Fork to create a new process

    if pid == 0:
        # Child process: executing the same program but with different code
        print(f"Child process, PID: {os.getpid()} executing 'ls -l'")
        # Replace the child process with 'ls -l' command
        os.execvp("ls", ["ls", "-l"])
    else:
        # Parent process
        print(f"Parent process, PID: {os.getpid()} - Waiting for child to finish")
        os.wait()  # Parent waits for the child to finish
        print("Parent Task Done, Child has finished")

if __name__ == "__main__":
    main()
