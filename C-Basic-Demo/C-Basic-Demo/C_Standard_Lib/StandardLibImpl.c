//
//  StandardLibImpl.c
//  C-Basic-Demo
//
//  Created by HeJeffery on 2017/1/23.
//  Copyright © 2017年 HeJeffery. All rights reserved.
//

#include "StandardLibImpl.h"

#include <stdlib.h>

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

    // 添加'\0'
    *dst = '\0';
    return dst;
}

char *hjstrncpy(char *dst, const char *src, size_t n) {

    if (dst == NULL || src == NULL) {
        return NULL;
    }
    
    char *tempSrc = (char *)src;
    unsigned long srcLength = 0;
    while (*tempSrc != '\0') {
        srcLength++;
        tempSrc++;
    }
    
    unsigned long num = n > srcLength ? srcLength : n;
    while (num > 0) {
        *dst = *src;
        dst++;
        src++;
        num--;
    }

    // 添加'\0'
    *dst = '\0';
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

    // 添加'\0'
    *dst = '\0';
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

    // 添加'\0'
    *dst = '\0';
    return result;
}

char *hjstrchr(const char *src, int chr) {

    if (src == NULL) {
        return NULL;
    }
    
    char *result = NULL;
    while (*src != '\0') {
        if (*src == chr) {
            result = src;
            return result;
        }
        src++;
    }
    return result;
}

int hjstrcmp(const char *src1, const char *src2) {
    
    if (src1 == NULL || src2 == NULL) {
        return 1;
    }
    
    unsigned long srcLength1 = hjstrlen(src1);
    unsigned long srcLength2 = hjstrlen(src2);
    
    // 长度取最大
    unsigned long length = srcLength1 >= srcLength2 ? srcLength1 : srcLength2;

    for (int i = 0; i < length; i++) {
        if (*(src1 + i) != *(src2 + i)) {
            if (*(src1 + i) > *(src2 + i)) {
                return 1;

            } else if (*(src1 + i) < *(src2 + i)) {
                return -1;
            }
        }
    }

    return 0;
}

int hjstrncmp(const char *src1, const char *src2, size_t n) {
    
    if (src1 == NULL || src2 == NULL) {
        return 1;
    }
    
    unsigned long srcLength1 = hjstrlen(src1);
    unsigned long srcLength2 = hjstrlen(src2);
    
    // 取最大值
    unsigned long length = srcLength1 >= srcLength2 ? srcLength1 : srcLength2;
    // 取最小值
    unsigned long count = length > n ? n : length;
    
    for (int i = 0; i < count; i++) {
        if (*(src1 + i) != *(src2 + i)) {
            if (*(src1 + i) > *(src2 + i)) {
                return 1;
                
            } else if (*(src1 + i) < *(src2 + i)) {
                return -1;
            }
        }
    }

    return 0;
}

char *hjstrstr(const char *bigstr, const char *littlestr) {
    
    if (bigstr == NULL || littlestr == NULL) {
        return NULL;
    }
    
    long bigStrLength = (long)hjstrlen(bigstr);
    long littleStrLength = (long)hjstrlen(littlestr);
    
    long deltaLength = bigStrLength - littleStrLength;
    if (deltaLength > 0) {
        for (int i = 0; i <= deltaLength; i++) {
            // 默认相等
            int isequal = 1;
            for (int j = 0; j < littleStrLength; j++) {
                if (*(bigstr + i + j) != *(littlestr + j)) {
                    isequal = 0;
                    break;
                }
            }
            
            if (isequal) {
                return (char *)littlestr;
            }
        }
    }
    return NULL;
}

char *hjstrdup(const char *src) {

    if (src == NULL) {
        return NULL;
    }
    
    char *pstr = (char *)malloc(sizeof(char) * hjstrlen(src) + 1);
    char *presult = pstr;
    while ((*pstr++ = *src++) != '\0');
    *pstr = '\0';

    return presult;
}

char *hjstrpbrk(const char *src, const char *charset) {
    
    if (src == NULL || charset == NULL) {
        return NULL;
    }

    while (*src != '\0') {
        
        char *presult = (char *)charset;
        while (*presult != '\0') {
            if (*src == *presult) {
                return presult;
            }
            presult++;
        }
        src++;
    }
    
    return NULL;
}

char *hjstrrchr(const char *src, int chr) {
    
    if (src == NULL) {
        return NULL;
    }

    for (const char *p = src + hjstrlen(src); p >= src; p--) {
        if (*p == chr) {
            return (char *)p;
            break;
        }
    }
    return NULL;
}

void *hjmemset(void *p, int chr, size_t len) {
    
    if (p == NULL) {
        return NULL;
    }
    
    char *pchr = (char *)p;
    int i = 0;
    while (i < len) {
        *pchr = (char)chr;
        pchr++;
        i++;
    }
    return p;
}





