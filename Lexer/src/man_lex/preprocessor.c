/**
 * @author      : 丁志鹏(OliverDD)
 * @file        : preprocessor.c
 * @created     : 星期五 10月 11, 2019 19:49:42 CST
 */
#include "preprocessor.h"

int preprocessor(const char *FILENAME){
	/*
	 * @purpose: 预处理函数，消除文件中的注释，产生临时文件(${FILENAME}.temp)存储调整过的文件
     * para: java文件文件名
     * return: 1 - 失败 0 - 成功
	 */
#ifdef LOCAL
    printf("预处理器: 开始执行\n");
#endif
	
// 	FILE *in = fopen(FILENAME, "r");
//     if(in == NULL){
//         return 1;
//     }
    char **FILE = get_name_suffix(FILENAME);
    if(FILE == NULL){
        printf("预处理器: 无法处理文件名%s\n", FILENAME);
        return 1;
    }
#ifdef LOCAL
    printf("预处理器: 执行失败\n");
#endif
    return 0;
}
