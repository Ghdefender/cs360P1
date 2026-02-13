<<<<<<< HEAD
#include <iostream>
#include <unistd.h>
#include <sys/wait.h>


// returns the current time in nanoseconds
static long long getTime()
{
    const long long NS_PER_SEC = 1000000000LL;

    // timespec holds tv_sec(seconds) and tv_nsec(nanoseconds)
    timespec ts;

    // gets the current monotonic time
    clock_gettime(CLOCK_MONOTONIC, &ts);

    // converts (seconds + nanoseconds) to total nanoseconds
    return ts.tv_sec * NS_PER_SEC + ts.tv_nsec;
}

// sleep for a given number of nanoseconds
static void sleepNs(long long ns)
{
    // only sleep if given a positive number of nanoseconds
    if (ns > 0)
    {
        // timespec holds tv_sec(seconds) and tv_nsec(nanoseconds)
        timespec ts;

        // converts nanoseconds to seconds and nanoseconds
        ts.tv_sec = ns / 1000000000LL; // seconds
        ts.tv_nsec = ns % 1000000000LL; // nanoseconds

        bool done = false;
        // sleep for the given time, handling interruptions
        while (!done)
        {
            // nanosleep returns 0 if the sleep was successful, or -1 if it was interrupted
            int result = nanosleep(&ts, &ts);
            if (result == 0)
            {
                done = true; // sleep completed successfully
            }
            else
            {
                // if error is not EINTR (interrupted by signal), print error and exit loop
                if (errno != EINTR)
                {
                    std::cerr << "nanosleep failed" << std::endl;
                    done = true; // exit loop on error
                }
            }
    
        }
    }
}

int main(int argc, char* argv[])
{
    int exitNumber = 0; 

    // validate command-line arguments
    if (argc != 3)
    {
        std::cerr << "Usage: " << argv[0] << " <cpu_percentage 0-100>  <run_time_s>" << std::endl;
        exitNumber = 1; // set exit number to 1 for invalid arguments
    }

    int cpuPercentage = 0;
    int runTimeS = 0;

    if (exitNumber == 0)
    {
        cpuPercentage = std::atoi(argv[1]);
        runTimeS = std::atoi(argv[2]);

        // validate correct CPU percentage and runtime
        if (cpuPercentage < 0 || cpuPercentage > 100 || runTimeS <= 0)
        {
            std::cerr << "Usage: " << argv[0] << " <cpu_percentage 0-100>  <run_time_s>" << std::endl;
            exitNumber = 1;
        }
    }

    if (exitNumber == 0)
    {
        const long long nsPerSecond = 1000000000LL;
        long long runTimeNs = runTimeS * nsPerSecond; // total runtime in nanoseconds

        long long startTime = getTime(); // get the start time in nanoseconds

        const long long baseCycleTime = 10000000LL; // base cycle time of 10ms in nanoseconds
        long long busyTime = (baseCycleTime * cpuPercentage) / 100LL; // calculate busy time based on CPU percentage
        long long idleTime = baseCycleTime - busyTime; // calculate idle time

        int calculation = 0; // variable to perform calculations to keep CPU busy
        
        while (getTime() - startTime < runTimeNs)
        {
            long long cycleStartTime = getTime(); // get the start time of the current cycle
            while (getTime() - cycleStartTime < busyTime)
            {
                calculation = calculation * 2 + 1; // perform calculations to keep CPU busy
            }
            sleepNs(idleTime); // sleep for the idle time to achieve the desired CPU percentage
        }
    }

    return exitNumber;
=======
#include <iostream>
#include <unistd.h>
#include <sys/wait.h>


// returns the current time in nanoseconds
static long long getTime()
{
    const long long NS_PER_SEC = 1000000000LL;

    // timespec holds tv_sec(seconds) and tv_nsec(nanoseconds)
    timespec ts;

    // gets the current monotonic time
    clock_gettime(CLOCK_MONOTONIC, &ts);

    // converts (seconds + nanoseconds) to total nanoseconds
    return ts.tv_sec * NS_PER_SEC + ts.tv_nsec;
}

// sleep for a given number of nanoseconds
static void sleepNs(long long ns)
{
    // only sleep if given a positive number of nanoseconds
    if (ns > 0)
    {
        // timespec holds tv_sec(seconds) and tv_nsec(nanoseconds)
        timespec ts;

        // converts nanoseconds to seconds and nanoseconds
        ts.tv_sec = ns / 1000000000LL; // seconds
        ts.tv_nsec = ns % 1000000000LL; // nanoseconds

        bool done = false;
        // sleep for the given time, handling interruptions
        while (!done)
        {
            // nanosleep returns 0 if the sleep was successful, or -1 if it was interrupted
            int result = nanosleep(&ts, &ts);
            if (result == 0)
            {
                done = true; // sleep completed successfully
            }
            else
            {
                // if error is not EINTR (interrupted by signal), print error and exit loop
                if (errno != EINTR)
                {
                    std::cerr << "nanosleep failed" << std::endl;
                    done = true; // exit loop on error
                }
            }
    
        }
    }
}

int main(int argc, char* argv[])
{
    int exitNumber = 0; 

    // validate command-line arguments
    if (argc != 3)
    {
        std::cerr << "Usage: " << argv[0] << " <cpu_percentage 0-100>  <run_time_s>" << std::endl;
        exitNumber = 1; // set exit number to 1 for invalid arguments
    }

    int cpuPercentage = 0;
    int runTimeS = 0;

    if (exitNumber == 0)
    {
        cpuPercentage = std::atoi(argv[1]);
        runTimeS = std::atoi(argv[2]);

        // validate correct CPU percentage and runtime
        if (cpuPercentage < 0 || cpuPercentage > 100 || runTimeS <= 0)
        {
            std::cerr << "Usage: " << argv[0] << " <cpu_percentage 0-100>  <run_time_s>" << std::endl;
            exitNumber = 1;
        }
    }

    if (exitNumber == 0)
    {
        const long long nsPerSecond = 1000000000LL;
        long long runTimeNs = runTimeS * nsPerSecond; // total runtime in nanoseconds

        long long startTime = getTime(); // get the start time in nanoseconds

        
    }

    return exitNumber;
>>>>>>> ebff6c55deea9466937f9cbf9f2e2b573e702149
}