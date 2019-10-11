/**
 * @author      : 丁志鹏(OliverDD)
 * @file        : preprocessor.c
 * @created     : 星期五 10月 11, 2019 19:49:42 CST
 */
#include "preprocessor.h"

int preprocessor(const char *FILENAME){
	/*
	 * @purpose: 预处理函数，消除文件中的注释，产生临时文件(${FILENAME}.temp)存储调整过的文件
	 */
	
	FILE *in = fopen(*FILENAME, "r");
	FILE *out = fopen()
}
