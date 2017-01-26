//
//  StringTool.c
//  C-Basic-Demo
//
//  Created by HeJeffery on 2017/1/26.
//  Copyright © 2017年 HeJeffery. All rights reserved.
//

#include "StringTool.h"

#include <string.h>

void deleteCharInString(char *str, char chr) {
    
    if (str == NULL) {
        return;
    }
    
    char *pstr1 = str;
    char *pstr2 = str;
    
    while (*pstr1 != '\0') {
        *pstr1 = *pstr2;
        if (*pstr1 != chr) {
            pstr1++;
        }
        pstr2++;
    }
}

void deleteStrInString(char *str, const char *delStr) {

    if (str == NULL || delStr == NULL) {
        return;
    }
    
    char *pstr = strstr(str, delStr);
    
    if (pstr != NULL) {
        unsigned long delStrLength = strlen(delStr);
        while ((*pstr = *(pstr + delStrLength))) {
            pstr++;
        }
    }
}
