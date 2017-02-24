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
 *  文件拷贝(文本文件，非二进制文件)
 *
 *  @param sourcePath 源文件的路径
 *  @param targetPath 目标文件的路径
 */
void copyFile(const char *sourcePath, const char *targetPath);

/**
 *  文件的简单加密(文本文件，非二进制文件)
 *
 *  @param sourcePath 源文件的路径
 *  @param targetPath 目标文件的路径
 */
void fileSimpleEncrypt(const char *sourcePath, const char *targetPath);

/**
 *  文件的简单解密(文本文件，非二进制文件)
 *
 *  @param sourcePath 源文件的路径
 *  @param targetPath 目标文件的路径
 */
void fileSimpleDecrypt(const char *sourcePath, const char *targetPath);

/**
 *  文件的加密解密(文本文件，非二进制文件)
 *
 *  @param sourcePath 源文件的路径
 *  @param targetPath 目标文件的路径
 */
void fileSimpleEncryptDecrypt(const char *sourcePath, const char *targetPath);

/**
 *  文件的加密解密
 *
 *  @param sourcePath 源文件的路径
 *  @param targetPath 目标文件的路径
 *  @param password 密码
 */
void fileEncryptDecryptWithPassword(const char *sourcePath, const char *targetPath, const char *password);

/**
 *  二进制文件的切割
 *
 *  @param sourcePath 源文件的路径
 *  @param cutNumber 切割的数量
 */
void binaryFileCutting(const char *sourcePath, int cutNumber);

/**
 *  二进制文件的合并
 *
 *  @param sourcePath 文件的路径
 *  @param targetPath 目标路径
 *  @param mergeNumber 合并的数量
 */
void binaryFMerge(const char *sourcePath, const char *targetPath, int mergeNumber);

/**
 *  获取文件的大小
 *
 *  @param filePath 文件的路径
 */
long fileSize(const char *filePath);

#endif /* CFile_h */
