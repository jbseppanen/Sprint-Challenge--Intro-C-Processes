**1. List all of the main states a process may be in at any point in time on a standard Unix system. Briefly explain what each of these states means.**

    1. Active/Running - This is a process that is currently running.
    2. Sleeping/Waiting - This is a process that is waiting on something else, perhaps user input or something from another process.
    3. Stopped - Process that is stopped.
    4. Zombie - This is a process that is dead/complete abut not cleaned up yet.

**2. What is a zombie process?**

    This is a process that is dead/complete but not yet cleaned up.

**3. How does a zombie process get created? How does one get destroyed?**

    Processes go into this state briefly when complete.  The parent process destroys it and/or cleans it up.  If the parent process is destroyed before the child process, that child process becomes a zombie that is "adopted" by a higher process that will take care of cleaning it up as needed.

**4. What are some of the benefits of working in a compiled language versus a non-compiled language? More specifically, what benefits are there to be had from taking the extra time to compile our code?**
    The complied code is more performant since it is already compiled into a form that is close to machine code.  Non-compiled code has to go through an interpreter while it is running before it can be executed.
