//
//  StringTool.h
//  C-Basic-Demo
//
//  Created by HeJeffery on 2017/1/26.
//  Copyright © 2017年 HeJeffery. All rights reserved.
//

#ifndef StringTool_h
#define StringTool_h

#include <stdio.h>

////////////////////////////////////////////////////////////////////////////////////
//                                                                                //
//                                  string的处理工具                                //
//                                                                                //
////////////////////////////////////////////////////////////////////////////////////

/**
 *  删除字符串中的某个字符
 *
 *  @param str 需要处理的字符串
 *  @param chr 需要删除的字符
 */
void deleteCharInString(char *str, char chr);

/**
 *  删除字符串中的某个字符串
 *
 *  @param str 需要处理的字符串
 *  @param delStr 需要删除的字符串
 */
void deleteStrInString(char *str, const char *delStr);

/**
 *  删除字符串中的所有delStr
 *
 *  @param str 需要处理的字符串
 *  @param delStr 需要删除的字符串
 */
void deleteAllStrInString(char *str, const char *delStr);

#endif /* StringTool_h */
