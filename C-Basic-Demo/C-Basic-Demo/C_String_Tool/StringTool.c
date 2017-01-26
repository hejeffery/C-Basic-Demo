//
//  StringTool.c
//  C-Basic-Demo
//
//  Created by HeJeffery on 2017/1/26.
//  Copyright © 2017年 HeJeffery. All rights reserved.
//

#include "StringTool.h"

#include <string.h>
#include <stdbool.h>

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

void deleteAllStrInString(char *str, const char *delStr) {
    
    if (str == NULL || delStr == NULL) {
        return;
    }
    
    int i = 0;
    int j = 0;
    
    while ((*(str + i) = *(str + j))) {
        
        bool isFind = true;
        unsigned long delStrLength = strlen(delStr);
        
        for (int k = 0; k < delStrLength; k++) {
            if ((*(str + j + k) != *(delStr + k)) || *(str + j + k) == '\0') {
                isFind = false;
                break;
            }
        }
        
        if (isFind) {
            j += delStrLength;
            
        } else {
            i++;
            j++;
        }
    }
}


