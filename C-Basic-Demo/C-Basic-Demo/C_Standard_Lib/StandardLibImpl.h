//
//  StandardLibImpl.h
//  C-Basic-Demo
//
//  Created by HeJeffery on 2017/1/23.
//  Copyright © 2017年 HeJeffery. All rights reserved.
//

#ifndef StandardLibImpl_h
#define StandardLibImpl_h

#include <stdio.h>

////////////////////////////////////////////////////////////////////////////////////
//                                                                                //
//           c语言标准库的部分实现，实现的方式全部用指针，不用任何现有库函数                  //
//                                                                                //
////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////
//                                                                                //
//                                  string的部分实现                                //
//                                                                                //
////////////////////////////////////////////////////////////////////////////////////
// strlen的实现
unsigned long hjstrlen(const char *src);

// strcpy的实现
char *hjstrcpy(char *dst, const char *src);

// strncpy的实现
char *hjstrncpy(char *dst, const char *src, size_t n);

// strcat的实现
char *hjstrcat(char *dst, const char *src);

// strncat的实现
char *hjstrncat(char *dst, const char *src, size_t n);

// strchr的实现
char *hjstrchr(const char *src, int chr);

// strcmp的实现
int hjstrcmp(const char *src1, const char *src2);

// strncmp的实现
int hjstrncmp(const char *src1, const char *src2, size_t n);

// strstr的实现
char *hjstrstr(const char *bigstr, const char *littlestr);

// strdup的实现
char *hjstrdup(const char *src);

// strpbrk的实现
char *hjstrpbrk(const char *src, const char *charset);

// strrchr的实现
char *hjstrrchr(const char *src, int chr);

////////////////////////////////////////////////////////////////////////////////////
//                                                                                //
//                                   mem的部分实现                                  //
//                                                                                //
////////////////////////////////////////////////////////////////////////////////////
// memset的实现
void *hjmemset(void *p, int chr, size_t len);

#endif /* StandardLibImpl_h */
