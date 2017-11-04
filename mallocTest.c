#include "types.h"
#include "stat.h"
#include "user.h"

int main() {
    int *a;
    a = (int *)malloc(sizeof(int));
    free(a);
    exit();
}