#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * @author      : 丁志鹏(OliverDD)
 * @file        : ToolPac.c
 * @created     : 星期五 10月 11, 2019 19:55:15 CST
 */

char **get_name_suffix(const char *FILENAME){
    /*
     * 获取文件名的无后缀格式与其后缀并检验后缀正确性
     * para: java文件文件名
     * return: NULL - 失败 char ** - 成功
     */
    char *FILE[2] = {NULL, NULL};
    char *FILENAME_TEMP = (char *)calloc(strlen(FILENAME), sizeof(char));
    memcpy(FILENAME_TEMP, FILENAME, strlen(FILENAME) * sizeof(char));
    char a[] = ".";
    FILE[0] = (char *)strsep(&FILENAME_TEMP, &a);
    FILE[1] = (char *)strsep(&FILENAME_TEMP, &a);
    if(FILE[0] == NULL || FILE[1] == NULL){
        printf("致命错误: java文件名处理失败\n");
        return NULL;
    }else if(strncmp(FILE[1], "java", sizeof(char) * 4) != 0){
        printf("致命错误: 无法识别后缀文件\n");
        return NULL;
    }else{
        return FILE;
    }
}
