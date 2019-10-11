/**
 * @author      : 丁志鹏(OliverDD)
 * @file        : ToolPac.c
 * @created     : 星期五 10月 11, 2019 19:55:15 CST
 */
#include <stdio.h>
#include <string.h>
char **get_name_suffix(const char *FILENAME){
	/*
	 * 获取文件名的无后缀格式与其后缀并检验后缀正确性
	 * para: char *
	 * return: char **
	 */
    char **FILE;
	char *FILENAME_TEMP = (char *)calloc(strlen(FILENAME), sizeof(char));
	memcpy(FILENAME_TEMP, FILENAME, strlen(FILENAME) * sizeof(char));
	FILE[0] = (char *)calloc(strlen(FILENAME) - 4, sizeof(char));
	FILE[1] = (char *)calloc(5,sizeof(char));
	FILE[0] = strsep(&FILENAME_TEMP, ".");
	FILE[1] = strsep(&FILENAME_TEMP, ".");
	if(FILE[0] == NULL || FILE[1] == NULL){
		return NULL;	
	}else if(strncmp(FILE[1], "java", sizeof(char) * 4) != 0){
		printf("致命错误: 无法识别后缀文件\n");
		return NULL;
	}else{
		return FILE;
	}
}