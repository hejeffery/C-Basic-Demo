//
//  CPractice.c
//  C-Basic-Demo
//
//  Created by HeJeffery on 2017/2/6.
//  Copyright © 2017年 HeJeffery. All rights reserved.
//

#include "CPractice.h"

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void practiceOne() {
    
    struct QQInfo {
        long long qqnumber;
        char password[20];
    };
    
    struct QQInfos {
        struct QQInfo *infos;
        int length;
    };
    
    char str[1024] = "12345-qwerty,23456-wertyu,34567-ertyui,45678-rtyuio,56789-tyuiop,67890-yuiopa";
    
    // 计算有多少个12345-qwerty这样的数据
    int count = 0;
    for (char *pstr = strstr(str, "-"); pstr != NULL; pstr = strstr(pstr + 1, "-")) {
        count++;
    }
    
    // 初始化struct QQInfos
    struct QQInfos qqinfos;
    // 动态分配数组的内存
    qqinfos.infos = (struct QQInfo *)malloc(sizeof(struct QQInfo) * count);
    qqinfos.length = count;

//    // 做法1：先把','替换为'\0'，再处理每一个独立的字符串
//    // 把','替换为'\0'
//    unsigned long strLength = strlen(str);
//    for (char *pstr = str; pstr < str + strLength; pstr++) {
//        if (*pstr == ',') {
//            *pstr = '\0';
//        }
//    }
//    // 处理每一个独立的字符串, 类似"abcd\0efghj"
//    int i = 0;
//    for (char *p = str; p < str + strLength; p += strlen(p) + 1, i++) {
//
//        // 拷贝一个副本，防止修改str
//        char *pstrcpy = (char *)malloc(sizeof(char) * (strlen(p) + 1));
//        strcpy(pstrcpy, p);
//        
//        // 把"-"替换为'\0'
//        char *ptemp = strstr(pstrcpy, "-");
//        *ptemp = '\0';
//        
//        sscanf(pstrcpy, "%lld", &((qqinfos.infos + i)->qqnumber));// 把字符串扫描到qqnumber中
//        sprintf((qqinfos.infos + i)->password, "%s", ptemp + 1);
//        
//        free(pstrcpy);
//    }
    
    // 做法2：使用strtok
    int i = 0;
    for (char *pstr = strtok(str, ","); pstr != NULL; pstr = strtok(pstr + strlen(pstr) + 1, ","), i++) {

        // 拷贝一个副本，防止修改str
        char *pstrcpy = (char *)malloc(sizeof(char) * (strlen(pstr) + 1));
        strcpy(pstrcpy, pstr);
        
        // 把"-"替换为'\0'
        char *ptemp = strstr(pstrcpy, "-");
        *ptemp = '\0';
 
        sscanf(pstrcpy, "%lld", &((qqinfos.infos + i)->qqnumber));// 把字符串扫描到qqnumber中
        sprintf((qqinfos.infos + i)->password, "%s", ptemp + 1);

        free(pstrcpy);
    }
    
    // 打印
    for (int i = 0; i < qqinfos.length; i++) {
        printf("QQ号码：%lld, 密码：%s\n", qqinfos.infos[i].qqnumber, qqinfos.infos[i].password);
    }

    // 替换为'\0'的思路可以用在字符串分割上
}
