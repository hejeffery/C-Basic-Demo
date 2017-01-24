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
//                                 c语言标准库的部分实现                              //
//                                                                                //
////////////////////////////////////////////////////////////////////////////////////

// strcpy的实现
char *hjstrcpy(char *dst, const char *src);

// strlen的实现
unsigned long hjstrlen(const char *src);

#endif /* StandardLibImpl_h */
