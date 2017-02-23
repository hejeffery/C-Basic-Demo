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
    
    long fileLength = fileSize(sourcePath);
    unsigned long passwordLength = strlen(password);
    
    long number = fileLength / passwordLength;
    
    for (long i = 0; i < number; i++) {
        
        for (int j = 0; j < passwordLength; j++) {
            int ch = fgetc(rfile);// 防止溢出，用int
            ch = ch ^ (*(password + j));
            fputc(ch, wfile);
        }
    }
    
    long molNumber = fileLength % passwordLength;
    for (long i = 0; i < molNumber; i++) {
        int ch = fgetc(rfile);// 防止溢出，用int
        ch = ch ^ (*(password + i));
        fputc(ch, wfile);
    }
    
    fclose(rfile);
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
    
    // ftell：计算文件头到当前文件指针的位置的长度
    return ftell(file);
}



