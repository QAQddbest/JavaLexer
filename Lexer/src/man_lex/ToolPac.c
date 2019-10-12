#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "head.h"

/**
 * @author      : 丁志鹏(OliverDD)
 * @file        : ToolPac.c
 * @created     : 星期五 10月 11, 2019 19:55:15 CST
 */

char *get_name_suffix(char *FILENAME){
    /*
     * 获取文件名的无后缀格式与其后缀并检验后缀正确性.将文件名的'.'改为'\0'，并返回第二段地址
     * para: java文件文件名
     * return: NULL - 失败 第二个参数的地址 - 成功
     */
    char *FILE[2] = {NULL, NULL};
    char a = '.';
    FILE[0] = (char *)strsep(&FILENAME, &a);
    FILE[1] = (char *)strsep(&FILENAME, &a);
    if(FILE[0] == NULL || FILE[1] == NULL){
         printf("\33[31m致命错误: java文件名处理失败\n\33[31m");
        return NULL;
    }else if(strncmp(FILE[1], "java\n", sizeof(char) * 4) != 0){
         printf("\33[31m致命错误: 无法识别后缀文件\n\33[31m");
        return NULL;
    }else{
        return FILE[1];
    }
}
