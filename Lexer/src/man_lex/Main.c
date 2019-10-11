#include "Main.h"
/**
 * @author: 丁志鹏(OliverDD)
 * @email: oliverdd@std.uestc.edu.cn
 * @date: 2019.10.10
 * @purpose: Java词法分析器手动实现
 * @todo:
 *            1. 预处理函数：消除注释(单行注释与多行注释)与空白字符(换行，制表与空格)
 *            2. 词法分析函数：
 *                
 */
int main(int argc, char *argv[]){
#ifdef LOCAL
    printf("LEXER: 开始执行\n");
#endif
    argc--;
    argv++;
    if(argc == 0){
        printf("致命错误:无输入文件\n");
        return 1;
    }else{
        while(argc > 0){
            if(preprocessor(argv[0]) == 1){
                printf("致命错误: 处理文件%s时出错\n", argv[0]);
                argc--;
                argv++;
                continue;
            }
            argc--;
            argv++;
        }
    }
#ifdef LOCAL
    printf("LEXER: 开始执行\n");
#endif
    return 0;
}
