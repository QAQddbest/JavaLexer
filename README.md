# JAVA词法分析器

## 切分TOKENS

![思维导图](./src/pic1.png)

原本是将常量这划分成了所有的类型，还特别标注了byte、boolean与String是要自己实现的

还想好了，用结构与联合实现存储不定长度内容的东西

突然想起来，这是词法分析

## flex自动生成

简单展示分类

```C
/* 关键字定义 */
ABSTRACT                    abstract
DEFAULT                     default
GOTO                        goto
NULL                        null
SWITCH                      switch
BOOLEAN                     boolean
DO                          do
IF                          if
PACKAGE                     package
NCHRONZED                   nchronzed
BREAK                       break
DOUBLE                      double
IMPLEMENTS                  implements
PRIVATE                     private
THIS                        this
BYTE                        byte
ELSE                        else
IMPORT                      import
PROTECTED                   protected
THROW                       throw
THROWS                      throws
CASE                        case
EXTENDS                     extends
INSTANCEOF                  instanceof
PUBLIC                      public
TRANSIENT                   transient
CATCH                       catch
INT                         int
RETURN                      return
CHAR                        char
FINAL                       final
INTERFACE                   interface
SHORT                       short
TRY                         try
CLASS                       class
FINALLY                     finally
LONG                        long
STATIC                      static
VOID                        void
CONST                       const
FLOAT                       float
NATIVE                      native
STRICTFP                    strictfp
VOLATILE                    volatile
CONTINUE                    continue
FOR                         for
NEW                         new
SUPER                       super
WHILE                       while
ASSERT                      assert
ENUM                        enum
/* 关键字定义结束 */

/* 运算符定义 */
QUES                        \?
COLON                       [:]
ASSIGNOP                    [=]
RELOP                       [>]|[<]|[>][=]|[<][=]|[=][=]|[!][=]
PLUS                        [+]
SUB                         [-]
MUL                         [*]
DIV                         [/]
AND                         [&][&]
OR                          [|][|]
/* 运算符定义结束 */

/* 分界符定义 */
ATT                         \@
DOT                         [.]
COMMA                       [,]
NOT                         [!]
SEM                         [;]
LP                          \(
RP                          \)
LB                          \[
RB                          \]
LC                          \{
RC                          \}
/* 分界符定义结束 */

/* 常数定义 */
STA_INT                         (-?[1-9][0-9]*|0)
STA_FLOAT                       -?(0|[1-9]+)\.[0-9]*
STA_CHAR                        \'[a-zA-Z]\'
STA_STRING                      \".*\"
STA_BOOLEAN                     (true|false)
/* 常数定义结束 */

/* 标识符定义 */
ID                          [a-zA-Z_$][a-zA-Z_$]*
/* 标识符定义结束 */

LINECOMMENT                 \/\/.*

COMMENT                     ((\/\*((\*[^\/]+)|[^\*])+\*\/)|(\/\/))

%option noyywrap
%%
{ABSTRACT}                  |
{DEFAULT}                   |
{GOTO}                      |
{NULL}                      |
{SWITCH}                    |
{BOOLEAN}                   |
{DO}                        |
{IF}                        |
{PACKAGE}                   |
{NCHRONZED}                 |
{BREAK}                     |
{DOUBLE}                    |
{IMPLEMENTS}                |
{PRIVATE}                   |
{THIS}                      |
{BYTE}                      |
{ELSE}                      |
{IMPORT}                    |
{PROTECTED}                 |
{THROW}                     |
{THROWS}                    |
{CASE}                      |
{EXTENDS}                   |
{INSTANCEOF}                |
{PUBLIC}                    |
{TRANSIENT}                 |
{CATCH}                     |
{INT}                       |
{RETURN}                    |
{CHAR}                      |
{FINAL}                     |
{INTERFACE}                 |
{SHORT}                     |
{TRY}                       |
{CLASS}                     |
{FINALLY}                   |
{LONG}                      |
{STATIC}                    |
{VOID}                      |
{CONST}                     |
{FLOAT}                     |
{NATIVE}                    |
{STRICTFP}                  |
{VOLATILE}                  |
{CONTINUE}                  |
{FOR}                       |
{NEW}                       |
{SUPER}                     |
{WHILE}                     |
{ASSERT}                    |
{ENUM}                      {
                                printf("< 关键字 , %10s >\n", yytext);
                            }
{QUES}                      |
{COLON}                     |
{ASSIGNOP}                  |
{RELOP}                     |
{PLUS}                      |
{SUB}                       |
{MUL}                       |
{DIV}                       |
{AND}                       |
{OR}                        {
                                printf("< 运算符 , %10s >\n", yytext);
                            }
{ATT}                       |
{COMMA}                     |
{DOT}                       |
{NOT}                       |
{SEM}                       |
{LP}                        |
{RP}                        |
{LB}                        |
{RB}                        |
{LC}                        |
{RC}                        {
                                printf("< 分界符 , %10s >\n", yytext);
                            }
{STA_INT}                   |
{STA_FLOAT}                 |
{STA_CHAR}                  |
{STA_STRING}                |
{STA_BOOLEAN}               {
                                printf("<  常数  , %10s >\n", yytext);
                            }
{ID}                        {
                                printf("< 标识符 , %10s >\n", yytext);
                            }
{LINECOMMENT}               |
{COMMENT}                   |
[ \n\t]                       //eat the white space
```

---

注意yywrap()这个函数

具体可以参看[flex manual手册](https://westes.github.io/flex/manual/Generated-Scanner.html#Generated-Scanner)

有三种方法：

1. 在`definition`部分，添加如下内容
```
%{
    #define yywrap() 1
%}```
2. 在`user code`部分，添加函数
```
    int yywrap(){
        return 1;
    }```
3. 在`definition`部分添加`%option noyywrap`

---


##  手动实现
