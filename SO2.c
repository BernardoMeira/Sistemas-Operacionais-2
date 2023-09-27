#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
  
int main()
{
    int x, y, z;
    x = fork();
    if (x > 0){
        printf("ID Pai: %d\n",getpid());
    }
    if (x == 0) {
       sleep(1);
        printf("ID Filho 1: %d, ID Pai: %d\n", getpid(), getppid());
    } else if(x == -1){
        printf("Impossivel criar Filho\n");
    } else {
        y = fork();
        if (y == 0) {
            sleep(2);
            printf("ID Filho 2: %d, ID Pai: %d\n", getpid(), getppid());
        } else {
            z = fork();
            if (z== 0) {
                sleep(3);
                printf("ID Filho 3: %d, ID Pai: %d\n", getpid(), getppid());
            }
        }
    }
    sleep(4);
    return 0;
}