//
//  CFile.h
//  C-Basic-Demo
//
//  Created by HeJeffery on 2017/2/23.
//  Copyright © 2017年 HeJeffery. All rights reserved.
//

#ifndef CFile_h
#define CFile_h

#include <stdio.h>

////////////////////////////////////////////////////////////////////////////////////
//                                                                                //
//                                      文件处理                                   //
//                                                                                //
////////////////////////////////////////////////////////////////////////////////////

/**
 *  文件拷贝(非二进制文件)
 *
 *  @param sourcePath 源文件的路径
 *  @param targetPath 目标文件的路径
 */
void copyFile(const char *sourcePath, const char *targetPath);

/**
 *  文件的简单加密(非二进制文件)
 *
 *  @param sourcePath 源文件的路径
 *  @param targetPath 目标文件的路径
 */
void fileSimpleEncrypt(const char *sourcePath, const char *targetPath);

/**
 *  文件的简单解密(非二进制文件)
 *
 *  @param sourcePath 源文件的路径
 *  @param targetPath 目标文件的路径
 */
void fileSimpleDecrypt(const char *sourcePath, const char *targetPath);

/**
 *  获取文件的大小
 *
 *  @param filePath 文件的路径
 */
long fileSize(const char *filePath);

#endif /* CFile_h */
