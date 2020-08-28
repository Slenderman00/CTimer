#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void sleep(int s) {

    //gets time
    time_t start, current;
    time(&start);
    //gets current time
    time(&current);

    //loop is true until current time is biggger than or equal to time + 60
    while((start + s) > current) {
        //updating current time
        time(&current);
    }
    //returns void
    return;
}

int main(int argc, char **argv) {
    //converts char array input to int
    int min = atoi(argv[1]);

    //runs one iteration for each specified min
    for(int i = 0; i < min; i++) {
        //prints minutes left, added whitespace to write over allready exsisting chars in the terminal
        printf("Minutes left: %d        ", (min - i));
        //flushes the standard out buffer
        fflush(stdout);
        //sleeps for 60 seconds, using the sleep function
        sleep(60);
        //carrage return
        printf("\r");
    }

    //prints times up to indicate that the specified time is up, added whitespace to write over allready exsisting chars in the terminal
    printf("Times up           \n");

    //returns 0 to idicate sucsessfull execution
    return 0;
}