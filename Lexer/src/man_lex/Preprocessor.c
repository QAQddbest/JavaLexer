#include "preprocessor.h"
static char word;
static char word_nex;
/**
 * @author      : 丁志鹏(OliverDD)
 * @file        : preprocessor.c
 * @created     : 星期五 10月 11, 2019 19:49:42 CST
 */
int preprocessor(const char *FILENAME){
	/*
	 * @purpose: 预处理函数，消除文件中的注释，产生临时文件(${FILENAME}.temp)存储调整过的文件
     * para: java文件文件名
     * return: 1 - 失败 0 - 成功
	 */
#ifdef LOCAL
    logcat("预处理器: 开始执行");
#endif
    char *FILENAME_TEMP0 = (char *)calloc(strlen(FILENAME), sizeof(char));
    memcpy(FILENAME_TEMP0, FILENAME, strlen(FILENAME) * sizeof(char));
    char *FILENAME_TEMP1 = get_name_suffix(FILENAME_TEMP0);
    if(FILENAME_TEMP1 == NULL || FILENAME_TEMP0 == NULL){
        printf("\33[31m预处理器: 无法处理文件名%s\n\33[31m", FILENAME);
        return 1;
    }else{
        FILENAME_TEMP0[strlen(FILENAME_TEMP0)] = '.';
        memcpy(FILENAME_TEMP1, "temp", 5*sizeof(char));
        FILENAME_TEMP1 = NULL;
        FILE *in = fopen(FILENAME, "r");
        if(in == NULL){
            printf("\33[31m预处理器: 打开文件%s出错\n\33[31m", FILENAME);
            return 1;
        }else{
            FILE *out = fopen(FILENAME_TEMP0, "w");
            if(out == NULL){
                printf("\33[31m预处理器: 打开文件%s出错\33[31m", FILENAME_TEMP0);
                return 1;
            }
            clear_comment(in, out);
        }
    }
    free(FILENAME_TEMP0);
#ifdef LOCAL
    logcat("预处理器: 执行成功");
#endif
    return 0;
}

static void clear_comment(FILE *in, FILE *out){
    if(!feof(in)){//预先载入一个字符
        get_nex_char(in);
    }
    while(!feof(in)){
        get_nex_char(in);
        if(word == '"'){//检测到'"',判断为字符串，准备跳过此段
            fputc(word, out);
            while(!feof(in)){
                get_nex_char(in);
                fputc(word, out);
                if((word_nex == '"') && (word != '\\')){//字符串结束（避免'\"'情况）
                    fputc(word_nex, out);
                    get_nex_char(in);//将双引号吃掉
                    break;
                }
            }
            if(feof(in)){//到达文件尾部
                break;
            }
        }else if(word == '/'){//捕捉到'/',准备判断注释并消除
            switch(word_nex){
                case '/':
                    while(!feof(in)){
                        get_nex_char(in);
                        if(word == '\n'){
                            fputc(word, out);
                            break;
                        }
                    }
                    break;
                case '*':
                    while(!feof(in)){
                        get_nex_char(in);
                        if(word_nex == '/' && word == '*'){
                            get_nex_char(in);//吃掉'/'
                            break;
                        }
                    }
                    break;
                default:
                    fputc(word, out);
                    break;
            }
        }else{//其他字符
            fputc(word, out);
        }
    }
}
static void get_nex_char(FILE *in){
    word = word_nex;
    word_nex = fgetc(in);
}
