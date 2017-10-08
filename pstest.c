// This program is designed to test the procState() system call
// by forking many copies of itself and calling procState()

#include "types.h"
#include "stat.h"
#include "user.h"

int
main(void)
{
    procState();
    if (fork() == 0){
        printf(1, "child\n");
        procState();
        if (fork() == 0){
            printf(1, "child's child\n");
            procState();
            exit();
        }
        wait();
        printf(1, "end of child\n");
        procState();
    }
    else{
        wait();
        printf(1, "back to parent\n");
        procState();
        if (fork() == 0){
            printf(1, "parent's child\n");
            procState();
            exit();
        }
        wait();
        printf(1, "end of parent\n");
        procState();
    }
    wait();
    printf(1, "state just before uncontrolled fork\n");
    procState();
    fork(); //Intentially let both processes call procState() to watch the interaction
    printf(1, "Insanity!\n");
    procState();
    wait(); //Needed to make sure child finishes before the shell prompt again
    exit();
}