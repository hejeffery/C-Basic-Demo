//
//  StandardLibImpl.c
//  C-Basic-Demo
//
//  Created by HeJeffery on 2017/1/23.
//  Copyright © 2017年 HeJeffery. All rights reserved.
//

#include "StandardLibImpl.h"

char *hjstrcpy(char *dst, const char *src) {

    if (dst == NULL || src == NULL) {
        return NULL;
    }
    while ((*dst++ = *src++) != '\0');

    return dst;
}

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
