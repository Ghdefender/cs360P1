#include <iostream>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char* argv[])
{
    int exitNumber = 0; 

    // check the argument count 
    if(argc < 3)
    {
        std::cout << "ERROR - Usage: run_concurrent <# to run> <program> <program arguments>" << std::endl;
        exitNumber = 1;
    }
   

    int nbRuns = 0;
    if(exitNumber == 0)
    {
        nbRuns = std::atoi(argv[1]);

        // validates run count
        if(nbRuns <= 0)
        {
            std::cout << "ERROR: # of runs must be > 0" << std::endl;
            exitNumber = 1;
        }
    }

    int childStarted = 0;

    // launch the child processes
    if(exitNumber == 0)
    {
        for(int i = 0; i < nbRuns && exitNumber == 0; i++)
        {
            pid_t pid = fork();

            // if the fork() fails
            if(pid < 0)
            {
                std::cerr << "Fork Failed. Usage: run_concurrent <# to run> <program> <program arguments>" << std::endl;
                exitNumber = 1;
            }
            // child process
            else if(pid == 0)
            {
                execvp(argv[2], &argv[2]);

                std::cerr << "Exec Failed. Usage: run_concurrent <# to run> <program> <program arguments>" << std::endl;

                std::exit(1);
            }
            else
            {
                childStarted++; // counts if the chjild process was successfully started
            }
        }
    }

    if(exitNumber == 0)
    {
        // wait for all child processes to finish
        for(int i = 0; i < childStarted; i++)
        {
            wait(NULL);
        }
    }

    return exitNumber;
}