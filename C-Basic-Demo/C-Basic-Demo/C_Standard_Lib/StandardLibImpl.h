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
//           c语言标准库的部分实现，实现的方式全部用指针，不用任何库函数                     //
//                                                                                //
////////////////////////////////////////////////////////////////////////////////////

// strlen的实现
unsigned long hjstrlen(const char *src);

// strcpy的实现
char *hjstrcpy(char *dst, const char *src);

// strcat的实现
char *hjstrcat(char *dst, const char *src);

// strncat的实现
char *hjstrncat(char *dst, const char *src, size_t n);

// strchr的实现
char *hjstrchr(const char *src, int chr);

#endif /* StandardLibImpl_h */
