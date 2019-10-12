/**
 * @author      : 丁志鹏(OliverDD)
 * @file        : preprocessor.h
 * @created     : 星期五 10月 11, 2019 19:55:15 CST
 */
#ifndef PREPROCESSOR_H
#define PREPROCESSOR_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "head.h"

#define LOCAL /* 开启本地调试模式 */

int preprocessor(const char *);
static void clear_comment(FILE* in, FILE* out);
static void get_nex_char(FILE *);

#endif /* end of include guard PREPROCESSOR_H */
