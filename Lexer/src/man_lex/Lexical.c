
#include "lexical.h"
/*
 * @author: 丁志鹏(OliverDD)
 * @email: oliverdd@std.uestc.edu.cn
 * @date: 2019.10.10
 * @descritpion:
 *                变量：
 *                      1. character - 存放读入变量
 *                      2. token - 存放读入字符序列
 *                函数：
 *                      1. getchara() - 从文件中读入一个字符到character变量内
 *                      2. clear_blank_chara() - 检查character是否是空白字符（空格、制表符、回车），并不断读入直到非空白字符
 *                      3. con_cha_to_token() - 将character内容续接在token后
 *                      4. is_keyword() - 判断token是否是关键字
 *                      5. is_numlet() - 判断token是否是常数
 *                      6. is_calsym() - 判断token是否是运算符
 *                      7. is_dilm() - 判断token是否是分界符
 *                      8. symbol() - 判断是否符合标识符
 *                      9. reserve() - 回退character中的字符，并置白character
 */
/*
 * todo:
 * 每一个函数都要更改
 * 认真思考如何实现自动机
 * 
 */
void print_key_val(char *key){
#ifdef LOCAL
    printf("<%5s><%s> 长度为%lu\n", key, token, strlen(token));
#endif
#ifndef LOCAL
    printf("< %5s , %10s >\n", key, token);
#endif
}
void clear_token(){
    memset(token, '\0', LEN_TOKEN * sizeof(char));
}
int lexical_analysis(const char *FILENAME){
    /*
	 * @purpose: java语言的词法分析对外接口
     * para: 指向经过预处理后的文件（以temp为后缀的文件）的文件指针
     * return: 1 - 失败 0 - 成功
	 */
#ifdef LOCAL
    logcat("词法分析: 开始执行");
#endif
    token  = (char *)calloc(LEN_TOKEN, sizeof(char));
    FILE *in;
    /* 获取temp文件名称，并打开temp文件 */
    char *FILENAME_TEMP0 = (char *)calloc(strlen(FILENAME), sizeof(char));
    memcpy(FILENAME_TEMP0, FILENAME, strlen(FILENAME) * sizeof(char));
    char *FILENAME_TEMP1 = get_name_suffix(FILENAME_TEMP0);
    if(FILENAME_TEMP1 == NULL || FILENAME_TEMP0 == NULL){
        printf("\33[31m词法分析: 无法处理文件名%s\n\33[31m", FILENAME);
        return 1;
    }else{
        FILENAME_TEMP0[strlen(FILENAME_TEMP0)] = '.';
        memcpy(FILENAME_TEMP1, "temp", 5*sizeof(char));
        FILENAME_TEMP1 = NULL;
        in = fopen(FILENAME_TEMP0, "r");
#ifdef LOCAL
        if(in != NULL)
            logcat("词法分析: 打开temp文件成功");
#endif
    }
    /* 开始词法分析 */
    while(!feof(in)){
        clear_token();
        getchara(in);
        clear_blank_chara(in);
        switch(character){
            /* 以下处理常数 */
            case '"':/* 处理字符串 */
                con_cha_to_token();
                while(!feof(in)){
                    getchara(in);
                    con_cha_to_token(in);
                    if(character == '\\'){//直接快进2个字符，避免"\""情况
                        getchara(in);
                        con_cha_to_token(in);
                    }else if(character == '"'){
                        break;
                    }
                }
                if(is_numlet() == 0){
                    print_key_val("  常数  ");
                }else{
                    printf("\33[31m词法分析: 处理%s时出错\n\33[31m", token);
                    return 1;
                }
                break;
            case '\'':/* 处理字符 */
                con_cha_to_token();
                getchara(in);//获取字符
                con_cha_to_token(in);
                getchara(in);//获取第二个'\''
                con_cha_to_token(in);
                if(is_numlet() == 0){
                    print_key_val("  常数  ");
                    clear_token();
                }else{
                    printf("\33[31m词法分析: 处理%s时出错\n\33[31m", token);
                }
                break;
            case '0':/* 处理数字 */
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
                while(isdigit(character) || character == '.'){
                    con_cha_to_token(in);
                    getchara(in);
                }
                print_key_val("  常数  ");
                reserve(in);//多读一位
                break;
            /* 以上处理常数 */
            /* 以下处理运算符 */
            case '?':
            case ':':
                con_cha_to_token(in);
                print_key_val(" 运算符 ");
                break;
            case '|':
                con_cha_to_token(in);
                getchara(in);
                if(character == '|'){
                    con_cha_to_token(in);
                    print_key_val(" 运算符 ");
                }else{
                    printf("\33[31m词法分析: 处理符号%s时出错\n\33[31m", token);
                    return 1;
                }
                break;
            case '&':
                con_cha_to_token(in);
                getchara(in);
                if(character == '&'){
                    con_cha_to_token(in);
                    print_key_val(" 运算符 ");
                }else{
                    printf("\33[31m词法分析: 处理符号%s时出错\n\33[31m", token);
                    return 1;
                }
                break;
            case '=':
            case '+':
            case '-':
            case '*':
            case '/':
            case '!':
                con_cha_to_token(in);
                getchara(in);
                if(character == '='){
                    con_cha_to_token(in);
                    print_key_val(" 运算符 ");
                }else{
                    reserve(in);
                    print_key_val(" 运算符 ");
                }
                break;
            /* 以上处理运算符 */
            /* 以下处理分界符 */
            case '{':
            case '}':
            case '(':
            case ')':
            case '[':
            case ']':
            case ';':
            case ',':
            case '@':
            case '.':
                con_cha_to_token(in);
                print_key_val(" 分界符 ");
                break;
            /* 以上处理分界符 */
            /* 以上处理关键字 */
            default:
                break;
        }
    }
    
}
static int getchara(FILE *in){
    /*
    * @purpose: 获取下一个字符
     * para: 指向经过预处理后的文件（以temp为后缀的文件）的文件指针
     * return: 1 - 到达文件尾 0 - 成功
     */
    if(!feof(in))
        character = fgetc(in);
    else
        return 1;
    return 0;
}
static int clear_blank_chara(FILE *in){
    /*
     * @purpose: 检查character是否是空白字符（空格、制表符、回车），并不断读入直到非空白字符
     * para: 指向经过预处理后的文件（以temp为后缀的文件）的文件指针
     * return: 1 - 失败 0 - 成功
     */
    if(character == ' ' || character == '\t' || character == '\n'){
        while(!feof(in) && character ){
            getchara(in);
            if(character != ' ' && character != '\t' && character != '\n')
                return 0;
        }
    }else{
        return 0;
    }
    return 1;
}
static int con_cha_to_token(){
    /*
     * @purpose: 将character内容续接在token后
     * para: NULL
     * return: 1 - 失败 0 - 成功
     */
    int len = strlen(token);
    if(len >= LEN_TOKEN - 1)
        return 1;
    strncat(token, &character, sizeof(char));
    token[len + 1] = '\0';
    return 0;
}
static int is_keyword(){
    /*
     * @purpose: 判断token是否是关键字
     * para: NULL
     * return: 1 - 不是 0 - 是的
     */
    int token_len = strlen(token);
    if(token_len <= 1){
        return 1;
    }
    for(int i=0;i < LEN_TAB0;i++){
        int tab_len = strlen(TAB0[i]);
        if(token_len == tab_len && strncmp(TAB0[i], token, token_len*sizeof(char)) == 0){//比较每一个关键字
//             printf("< 关键字 , %10s >", token);
            return 0;
        }
    }
    return 1;
}
static int is_numlet(){
    /*
     * @purpose: 判断token是否是常数（字符串，整数，浮点数）
     * para: NULL
     * return: 1 - 不是 0 - 是的
     */
    int token_len = strlen(token);
    if(token_len == 0){
        return 1;
    }
    if(token[0] == '"'){// "字符串"
        if(token[token_len - 1] != '"')
            return 1;
    }else if(isdigit(token[0]) != 0 || (token[0] == '-' && isdigit(token[1]))){// 数字
        for(int i=0;i < token_len;i++){
            if(token[i] == '.')
                continue;
            if(isdigit(token[i]) == 0){
                return 1;
            }
        }
    }else if(token[0] == '\''){// '字符'
        if(token[2] != '\'')
            return 1;
    }else{// true/false
        if((strncmp(token, "true", 4*sizeof(char)) != 0) && (strncmp(token, "false", 4*sizeof(char))))
            return 1;
    }
//     printf("<  常数  , %10s >", token);
    return 0;
}
static int is_calsym(){
    /*
     * @purpose: 判断token是否是运算符
     * para: NULL
     * return: 1 - 不是 0 - 是的
     */
    int token_len = strlen(token);
    if(token_len >= 3){
        return 1;
    }
    for(int i=0;i < LEN_TAB1;i++){
        int tab_len = strlen(TAB1[i]);
        if(token_len == tab_len && strncmp(TAB1[i], token, token_len*sizeof(char)) == 0){//比较每一个关键字
//             printf("< 运算符 , %10s >", token);
            return 0;
        }
    }
    return 1;
}
static int is_dilm(){
    /*
     * @purpose: 判断token是否是分界符
     * para: NULL
     * return: 1 - 不是 0 - 是的
     */
    int token_len = strlen(token);
    if(token_len != 1){
        return 1;
    }
    for(int i=0;i < LEN_TAB2;i++){
        int tab_len = strlen(TAB2[i]);
        if(token_len == tab_len && strncmp(TAB2[i], token, token_len*sizeof(char)) == 0){//比较每一个关键字
//             printf("< 分界符 , %10s >", token);
            return 0;
        }
    }
    return 1;
}
static int symbol(){
    /*
     * @purpose: 判断是否符合标识符
     * para: NULL
     * return: 1 - 不是 0 - 是的
     */
    if(!isalpha(token[0]) && token[0] != '_' && token[0] != '$'){
        return 1;
    }
    for(int i=1;i < strlen(token);i++){
        if((!isalpha(token[i])) && (isdigit(token[i])) && (token[i] != '$') && (token[i] != '_')){
            return 1;
        }
    }
//     printf("< 标识符 , %10s >", token);
    return 0;
}
static void reserve(FILE *in){
    character = ' ';
    fseek(in, -1*sizeof(char), SEEK_CUR);
}

