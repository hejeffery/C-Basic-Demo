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
    
    /* 计算字符串的长度 */

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

    /* 拷贝字符串 */

    if (dst == NULL || src == NULL) {
        return NULL;
    }
    
    char *dstTemp = dst;
    while ((*dstTemp++ = *src++) != '\0');

    // 末尾添加'\0'
    *dstTemp = '\0';
    return dst;
}

char *hjstrncpy(char *dst, const char *src, size_t n) {

    /* 拷贝字符串，n是需要拷贝的个数 */

    if (dst == NULL || src == NULL) {
        return NULL;
    }
    
    char *tempSrc = (char *)src;
    unsigned long srcLength = 0;
    while (*tempSrc++ != '\0') {
        srcLength++;
    }
    
    unsigned long num = n > srcLength ? srcLength : n;
    
    char *dstTemp = dst;
    while (num > 0) {
        *dstTemp = *src;
        dstTemp++;
        src++;
        num--;
    }

    // 添加'\0'
    *dstTemp = '\0';
    return dst;
}

char *hjstrcat(char *dst, const char *src) {

    /* 字符串的连接 */

    if (dst == NULL || src == NULL) {
        return NULL;
    }
    
    char *result = dst;
    // dst先移动到尾部
    while (*dst != '\0') {
        dst++;
    }

    // 再在dst的尾部添加src
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
    
    /* 字符串的连接，连接的个数是n */

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
    
    /* 字符串中查找chr，找到了返回chr的地址 */

    if (src == NULL) {
        return NULL;
    }
    
    char *result = NULL;
    while (*src != '\0') {
        if (*src == chr) {
            result = (char *)src;
            return result;
        }
        src++;
    }
    return result;
}

int hjstrcmp(const char *src1, const char *src2) {
    
    /* 比较两个字符串，相等返回0，src1 > src2返回1，src1 > src2返回-1 */
    
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
    
    /* 比较两个字符串，比较n个字符，相等返回0，src1 > src2返回1，src1 > src2返回-1 */
    
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
    
    /* 字符串搜索 */
    
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

    /* 字符串拷贝，动态分配了内存，返回字符串需要使用free函数来释放内存 */
    
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
    
    /* 判断src中，是不是含有charset中的任意一个字符 */
    
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
    
    /* 反向查找src中是否含有chr字符 */
    
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

char *hjstrrev(char *src) {
    
    /* 反转字符串 */
    
    if (src == NULL) {
        return NULL;
    }
    
    char *head = src;
    char *tail = src + hjstrlen(src) - 1;

    while (head < tail) {
        *head = *head ^ *tail;
        *tail = *head ^ *tail;
        *head = *head ^ *tail;
        head++;
        tail--;
    }
    return src;
}

char *hjstrlwr(char *src) {
    
    /* 字符串大写转小写 */
    
    if (src == NULL) {
        return NULL;
    }
    
    char *psrc = src;
    while (*psrc != '\0') {
        if (*psrc >= 'A' && *psrc <= 'Z') {
            *psrc += 32;
        }
        psrc++;
    }
    
    return src;
}

char *hjstrupr(char *src) {
    
    /* 字符串小写转大写 */
    
    if (src == NULL) {
        return NULL;
    }
    
    char *psrc = src;
    while (*psrc != '\0') {
        if (*psrc >= 'a' && *psrc <= 'z') {
            *psrc -= 32;
        }
        psrc++;
    }
    
    return src;
}

void *hjmemset(void *dst, int chr, size_t len) {
    
    if (dst == NULL) {
        return NULL;
    }
    
    // 转换为char *，逐个处理
    char *pchr = (char *)dst;

    int i = 0;
    while (i < len) {
        *pchr = (char)chr;
        pchr++;
        i++;
    }
    return dst;
}

void *hjmemcpy(void *dst, const void *source, size_t len) {
    
    if (dst == NULL || source == NULL) {
        return NULL;
    }
    
    // 按照字节逐个拷贝
    char *pdst = (char *)dst;
    char *psource = (char *)source;
    
    int i = 0;
    while (i < len) {
        *pdst = *psource;
        pdst++;
        psource++;
        i++;
    }
    return dst;
}

void *hjmemccpy(void *dst, const void *source, int chr, size_t len) {
    
    if (dst == NULL || source == NULL || len == 0) {
        return NULL;
    }
    
    // 按照字节逐个拷贝
    char *pdst = (char *)dst;
    char *psource = (char *)source;
    
    int i = 0;
    while (*psource != chr && i < len) {
        *pdst = *psource;
        pdst++;
        psource++;
        i++;
    }
    
    return dst;
}

void *hjmemmove(void *dst, const void *source, size_t len) {
    
    if (dst == NULL || source == NULL) {
        return NULL;
    }
    
    // 整体拷贝
    void *psource = (void *)malloc(len);
    hjmemcpy(psource, source, len);// 整体拷贝到临时内存
    hjmemcpy(dst, psource, len);// 临时内存拷贝到dst
    free(psource);
    
    return dst;
}

int hjmemcmp(const void *source1, const void *source2, size_t len) {
    
    if (source1 == NULL || source2 == NULL || len == 0) {
        return 0;
    }
    
    // 按照字节逐个处理
    char *psource1 = (char *)source1;
    char *psource2 = (char *)source2;
    
    int i = 0;
    while ((*psource1 == *psource2) && i < len) {
        psource1++;
        psource2++;
        i++;
    }
    
    if (i == len) {
        return 0;

    } else {
        if (*psource1 > *psource2) {
            return 1;

        } else {
            return -1;
        }
    }
}

void *hjmemchr(const void *dst, int chr, size_t len) {
    
    if (dst == NULL) {
        return NULL;
    }
    
    char *pdst = (char *)dst;
    
    int i = 0;
    while (*pdst != chr && i < len) {
        i++;
        pdst++;
    }
    
    if (*pdst == chr) {
        return pdst;

    } else {
        return NULL;
    }
}




