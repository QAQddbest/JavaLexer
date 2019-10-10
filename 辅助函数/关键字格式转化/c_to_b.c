 /**
 * @author      : OliverDD
 * @email       : oliverdd@std.uestc.edu.cn
 * @file        : a
 * @created     : 09/10/2019 22:57:20 CST
 * @license     : MIT
 */

#include "stdio.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int main(){
    FILE *in=fopen("c.txt", "r");
    FILE *out=fopen("b.txt", "w");
    char *p = (char *)malloc(sizeof(char)*20);
    int temp;
    while(fscanf(in, "%s", p) != EOF){
    temp = strlen(p);
        p[temp+1]='\0';
        p[temp]='}';
        fprintf(out, "{%-27s|\n", p);
    }
}


