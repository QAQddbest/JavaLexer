/**
 * @author      : 丁志鹏(OliverDD)
 * @file        : Main.h
 * @created     : 星期五 10月 11, 2019 19:55:15 CST
 */

#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "head.h"

#define LOCAL /* 开启本地调试模式 */

int preprocessor(const char *);
int lexical_analysis(const char *);

#endif /* end of include guard MAIN_H */

