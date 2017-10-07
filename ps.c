// A simple program that just calls the procState() system call

#include "types.h"
#include "stat.h"
#include "user.h"

int
main(void)
{
    procState();
    exit();
}