#ifndef LEXICAL_H
#define LEXICAL_H

#include "head.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include <ctype.h>

#define LOCAL

static char character;
static char *token;

#define LEN_TAB0 51
#define LEN_TAB1 20
#define LEN_TAB2 11
#define LEN_TOKEN 200

#define MIN(x,y) ((x)<(y))?(x):(y)

static char TAB0[LEN_TAB0][11] = {"abstract","default","goto","null","switch","boolean","do","if","package","nchronzed","break","double","implements","private","this","byte","else","import","protected","throw","throws","case","extends","instanceof","public","transient","catch","int","return","char","final","interface","short","try","class","finally","long","static","void","const","float","native","strictfp","volatile","continue","for","new","super","while","assert","enum"};
static char TAB1[LEN_TAB1][3] = {"=","+","-","*","/","+=","-=","*=","/=","<",">","<=",">=","==","!=","&&","||","!","?",":"};
static char TAB2[LEN_TAB2][2] = {"{","}","(",")","[","]",";",",","@","."};

void print_key_val(char *);
static void reserve(FILE *);
static int getchara(FILE *);
static int clear_blank_chara(FILE *);
static int con_cha_to_token();
static int is_keyword();
static int is_numlet();
static int is_calsym();
static int is_dilm();
static int symbol();

#endif // LEXICAL_H
