/**
 * @author      : OliverDD
 * @email       : oliverdd@std.uestc.edu.cn
 * @file        : a
 * @created     : 27/09/2019 22:57:20 CST
 * @license     : MIT
 */

#include "stdio.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int main(){
    FILE *in=fopen("a.txt", "r");
    FILE *out=fopen("b.txt", "w");
    char *p = (char *)malloc(sizeof(char)*20);
    char *q = (char *)malloc(sizeof(char)*20);
    int len;
    while(fscanf(in, "%s", p) != EOF){
        //printf("Read in %s\n", p);
        memcpy(q, p, sizeof(char)*20);
        len = strlen(q)-1;
        while(len >= 0){
            q[len] = toupper(q[len]);
            len--;
        }
        //printf("\nTurn to %s\n", q);
        fprintf(out, "%-28s%s\n", q, p);
    }
}


