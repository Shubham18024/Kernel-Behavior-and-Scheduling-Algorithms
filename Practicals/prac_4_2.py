import os

def main():
    pid = os.fork()  # Fork to create a new process

    if pid == 0:
        # Child process executes a different program using os.exec
        print(f"Child process, PID: {os.getpid()} executing 'ls -l'")
        # Replace the child process with 'ls -l' command
        os.execvp("ls", ["ls", "-l"])
    else:
        # Parent process
        print(f"Parent process, PID: {os.getpid()}")
        os.wait()  # Wait for the child process to finish
        print("Parent Task Done")

if __name__ == "__main__":
    main()
