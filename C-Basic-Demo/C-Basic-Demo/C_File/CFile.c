//
//  CFile.c
//  C-Basic-Demo
//
//  Created by HeJeffery on 2017/2/23.
//  Copyright © 2017年 HeJeffery. All rights reserved.
//

#include "CFile.h"

#include <stdio.h>
#include <strings.h>
#include <stdlib.h>

#include "StringTool.h"

void copyFile(const char *sourcePath, const char *targetPath) {
    
    if (sourcePath == NULL || targetPath == NULL) {
        return;
    }
    
    FILE *rfile = fopen(sourcePath, "r");
    FILE *wfile = fopen(targetPath, "w");
    
    if (rfile == NULL || wfile == NULL) {
        return;
    }
    
    // 都要去掉文件最后的EOF，EOF不能用来处理二进制文件
//    // 第一种方式
//    int ch = 0;// 防止溢出，用int
//    while ((ch = fgetc(rfile)) != EOF) {
//        fputc(ch, wfile);
//    }
    
    // 第二种方式
    while (!feof(rfile)) {
        int ch = fgetc(rfile);// 防止溢出，用int
        if (ch != EOF) {
            fputc(ch, wfile);
        }
    }
}

void fileSimpleEncrypt(const char *sourcePath, const char *targetPath) {
    
    if (sourcePath == NULL || targetPath == NULL) {
        return;
    }
    
    FILE *rfile = fopen(sourcePath, "r");
    FILE *wfile = fopen(targetPath, "w");
    
    if (rfile == NULL || wfile == NULL) {
        return;
    }
    
//    // 第一种方式
//    int ch = 0;// 防止溢出，用int
//    while ((ch = fgetc(rfile)) != EOF) {
//        ch += 1;
//        fputc(ch, wfile);
//    }
    
    // 第二种方式
    while (!feof(rfile)) {
        int ch = fgetc(rfile);// 防止溢出，用int
        if (ch != EOF) {
            ch += 1;
            fputc(ch, wfile);
        }
    }
}

void fileSimpleDecrypt(const char *sourcePath, const char *targetPath) {
    
    if (sourcePath == NULL || targetPath == NULL) {
        return;
    }
    
    FILE *rfile = fopen(sourcePath, "r");
    FILE *wfile = fopen(targetPath, "w");
    
    if (rfile == NULL || wfile == NULL) {
        return;
    }
    
//    // 第一种方式
//    int ch = 0;// 防止溢出，用int
//    while ((ch = fgetc(rfile)) != EOF) {
//        ch -= 1;
//        fputc(ch, wfile);
//    }
    
    // 第二种方式
    while (!feof(rfile)) {
        int ch = fgetc(rfile);// 防止溢出，用int
        if (ch != EOF) {
            ch -= 1;
            fputc(ch, wfile);
        }
    }
}

void fileSimpleEncryptDecrypt(const char *sourcePath, const char *targetPath) {
    
    if (sourcePath == NULL || targetPath == NULL) {
        return;
    }
    
    FILE *rfile = fopen(sourcePath, "r");
    FILE *wfile = fopen(targetPath, "w");
    
    if (rfile == NULL || wfile == NULL) {
        return;
    }
    
    int ch;// 防止溢出，用int
    while ((ch = fgetc(rfile)) != EOF) {
        
        ch ^= 10;
        fputc(ch, wfile);
    }
}

void fileEncryptDecryptWithPassword(const char *sourcePath, const char *targetPath, const char *password) {
    
    if (sourcePath == NULL || targetPath == NULL || password == NULL) {
        return;
    }
    
    FILE *rfile = fopen(sourcePath, "rb");
    FILE *wfile = fopen(targetPath, "wb");
    
    if (rfile == NULL || wfile == NULL) {
        return;
    }
    
    // 第一种方式：for
//    long fileLength = fileSize(sourcePath);
//    unsigned long passwordLength = strlen(password);
//    
//    long number = fileLength / passwordLength;
//    
//    for (long i = 0; i < number; i++) {
//        
//        for (int j = 0; j < passwordLength; j++) {
//            int ch = fgetc(rfile);// 防止溢出，用int
//            ch = ch ^ (*(password + j));
//            fputc(ch, wfile);
//        }
//    }
//    
//    long molNumber = fileLength % passwordLength;
//    for (long i = 0; i < molNumber; i++) {
//        int ch = fgetc(rfile);// 防止溢出，用int
//        ch = ch ^ (*(password + i));
//        fputc(ch, wfile);
//    }
    
    // 第二种方式：while
    unsigned long passwordLength = strlen(password);
    
    int i = 0;
    int ch;
    while ((ch = fgetc(rfile)) != EOF) {

        ch = ch ^ (password[i % passwordLength]);
        fputc(ch, wfile);
        i++;
    }
    
    fclose(rfile);
    fclose(wfile);
}

void binaryFileCutting(const char *sourcePath, int cutNumber) {
    
    if (sourcePath == NULL || cutNumber == 0) {
        return;
    }
    
    char **targetPaths = (char **)malloc(sizeof(char *) * cutNumber);
    
    for (int i = 0; i < cutNumber; i++) {
        // 处理路径
        char *tempPath = (char *)malloc(sizeof(char) * strlen(sourcePath));
        strcpy(tempPath, sourcePath);
        
        const char *suffix = strrchr(sourcePath, '.');
        deleteStrInString(tempPath, suffix);
        
        sprintf(tempPath, "%s%i%s", tempPath, i + 1, suffix);
        
        targetPaths[i] = (char *)malloc(sizeof(char) * strlen(tempPath));
        
        strcpy(targetPaths[i], tempPath);
        
        free(tempPath);
    }
    
    long filesize = fileSize(sourcePath);

    int mod = filesize % cutNumber;
    
    FILE *rfile = fopen(sourcePath, "rb");
    if (mod == 0) {// 能被整除

        int perSize = (int)(filesize / cutNumber);
        for (int i = 0; i < cutNumber; i++) {

            FILE *wfile = fopen(targetPaths[i], "wb");

            for (int j = 0; j < perSize; j++) {
                fputc(fgetc(rfile), wfile);
            }
            
            fclose(wfile);
        }
        
    } else {// 不能被整除
        
        int perSize = (int)(filesize / (cutNumber - 1));
        for (int i = 0; i < (cutNumber - 1); i++) {

            FILE *wfile = fopen(targetPaths[i], "wb");

            for (int j = 0; j < perSize; j++) {
                fputc(fgetc(rfile), wfile);
            }
            
            fclose(wfile);
        }
        
        for (int k = 0; k < mod; k++) {
            FILE *wfile = fopen(targetPaths[cutNumber - 1], "wb");
            fputc(fgetc(rfile), wfile);
            fclose(wfile);
        }
    }
    
    fclose(rfile);
    
    free(targetPaths);
}

void binaryFileMerge(const char *sourcePath, const char *targetPath, int mergeNumber) {
    
    if (sourcePath == NULL || mergeNumber == 0) {
        return;
    }
    
    char **targetPaths = (char **)malloc(sizeof(char *) * mergeNumber);
    
    for (int i = 0; i < mergeNumber; i++) {
        // 处理路径
        char *tempPath = (char *)malloc(sizeof(char) * strlen(sourcePath));
        strcpy(tempPath, sourcePath);
        
        const char *suffix = strrchr(sourcePath, '.');
        deleteStrInString(tempPath, suffix);
        
        sprintf(tempPath, "%s%i%s", tempPath, i + 1, suffix);
        
        targetPaths[i] = (char *)malloc(sizeof(char) * strlen(tempPath));
        
        strcpy(targetPaths[i], tempPath);
        
        free(tempPath);
    }
    
    FILE *wfile = fopen(targetPath, "wb");

    for (int i = 0; i < mergeNumber; i++) {
        
        long length = fileSize(targetPaths[i]);
        if (length == -1) {
            return;
        }
        
        FILE *rfile = fopen(targetPaths[i], "rb");
        for (int j = 0; j < length; j++) {
            fputc(fgetc(rfile), wfile);
        }
        
        fclose(rfile);
    }

    fclose(wfile);
}

long fileSize(const char *filePath) {
    
    if (filePath == NULL) {
        return -1;
    }
    
    FILE *file = fopen(filePath, "rb");
    if (file == NULL) {
        return -1;
    }
    
    // 文件的指针移动到文件末尾
    fseek(file, 0, SEEK_END);
    
    // ftell：获取文件指针当前位置相对文件首地的长度
    long length = -1;
    length = ftell(file);
    
    fclose(file);
    
    return length;
}



