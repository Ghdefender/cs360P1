// run_serial file
#include <iostream>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char* argv[])
{
    int exitNumber = 0; 

    // check the argument count 
    if(argc < 3)
    {
        std::cout << "ERROR - Example input: run_serial <# to run> <program> <program arguments>" << std::endl;
        exitNumber = 1;
    }
    else
    {
        int nbRuns = std::atoi(argv[1]);

        // validates run count
        if(nbRuns <= 0)
        {
            std::cout << "ERROR: # of runs must be > 0" << std::endl;
            exitNumber = 1;
        }
        else
        {
            // run the program 
            for(int i = 0; i < nbRuns && exitNumber == 0; i++)
            {
                pid_t pid = fork();

                // if the fork() fails
                if(pid < 0)
                {
                    std::cerr << "Fork Failed." << std::endl;
                }
                // child process
                else if(pid == 0)
                {
                    execvp(argv[2], &argv[2]);

                    std::cerr << "Exec Failed." << std::endl;

                    std::exit(1);
                }
                // parent process
                else
                {
                    int status = 0;

                    //std::cout << "I am the parent my PID is: " << getpid() << " and my child pid is: " << pid << std::endl;

                    pid_t waitpid = wait(&status);
                    // wait for any child to finish
                    if(waitpid < 0)
                    {
                        std::cerr << "Wait Failed." << std::endl;
                        exitNumber = 1;
                    }
                }
            }
        }
        
    }

    return exitNumber;
}