import os
import time

def main():
    pid = os.fork()  # Create a new process

    if pid == 0:
        # Child Process
        print(f"Child Process, PID: {os.getpid()}")  # Child prints its PID
        time.sleep(2)  # Simulate work with sleep
        print("Child Task Done")
    else:
        # Parent Process
        print(f"Parent Process, PID: {os.getpid()}")  # Parent prints its PID
        os.wait()  # Wait for the child process to finish
        print("Parent Task Done")

if __name__ == "__main__":
    main()
