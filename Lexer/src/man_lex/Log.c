#include <stdio.h>
#include <time.h>
void logcat(char *com){
    time_t curtime;
    time(&curtime);
    printf("%s    %s\n", ctime(&curtime), com);
}
