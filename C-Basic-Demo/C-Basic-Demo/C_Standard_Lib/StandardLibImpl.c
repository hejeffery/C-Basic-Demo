//
//  StandardLibImpl.c
//  C-Basic-Demo
//
//  Created by HeJeffery on 2017/1/23.
//  Copyright © 2017年 HeJeffery. All rights reserved.
//

#include "StandardLibImpl.h"

unsigned long hjstrlen(const char *src) {
    
    if (src == NULL) {
        return 0;
    }
    
    unsigned long length = 0;
    while (*src++ != '\0') {
        length++;
    }
    
    return length;
}

char *hjstrcpy(char *dst, const char *src) {

    if (dst == NULL || src == NULL) {
        return NULL;
    }
    while ((*dst++ = *src++) != '\0');

    return dst;
}

char *hjstrcat(char *dst, const char *src) {
    if (dst == NULL || src == NULL) {
        return NULL;
    }
    
    char *result = dst;
    while (*dst != '\0') {
        dst++;
    }

    while (*src != '\0') {
        *dst = *src;
        dst++;
        src++;
    }
    return result;
}

char *hjstrncat(char *dst, const char *src, size_t n) {
    if (dst == NULL || src == NULL) {
        return NULL;
    }
    
    // 记录dst的首地址
    char *result = dst;
    while (*dst != '\0') {
        dst++;
    }
    
    // 记录src的首地址
    const char *srcTemp = src;
    // 先算出src的长度
    unsigned long srcLength = 0;
    while (*src++ != '\0') {
        srcLength++;
    }

    // 这里要判断一下，如果n >= srcLength，用srcLength作为结束的条件，反之用n作为结束的条件
    unsigned long num = n >= srcLength ? srcLength : n;
    for (int i = 0; i < num; i++) {
        *dst = *(srcTemp + i);
        dst++;
    }
    return result;
}
