//
//  SequenceArrayList.c
//  C-Basic-Demo
//
//  Created by HeJeffery on 2017/1/19.
//  Copyright © 2017年 HeJeffery. All rights reserved.
//

#include "SequenceArrayList.h"
#include <stdlib.h>
#include <memory.h>

bool createArrayList(ArrayList *arrayList, int length) {
    arrayList->list = (int *)calloc(length, sizeof(int));
    if (arrayList->list == NULL) {
        return false;
    }
    arrayList->currentIndex = -1;
    arrayList->length = length;
    return true;
}

bool isFullArrayList(ArrayList *arrayList) {
    if (arrayList->currentIndex == (arrayList->length - 1)) {
        return true;
    }
    return false;
}

bool isEmptyArrayList(ArrayList *arrayList) {
    if (arrayList->list == NULL || arrayList->currentIndex == -1) {
        return true;
    }
    return false;
}

bool append(ArrayList *arrayList, int value) {
    // 满的list，直接返回false
    if (isFullArrayList(arrayList)) {
        return false;
    }
    arrayList->currentIndex++;
    arrayList->list[arrayList->currentIndex] = value;
    return true;
}

bool insert(ArrayList *arrayList, int index, int value) {
    // 满的list，直接返回false
    if (isFullArrayList(arrayList)) {
        return false;
    }
    
    printf("current = %d\n", arrayList->currentIndex);
    
    // 插入数据的index不合法，直接返回
    if (index > (arrayList->currentIndex + 1) || index < 0) {
        return false;
    }
    
    int tempIndex = arrayList->currentIndex;
    while (tempIndex >= index) {
        // 往后移
        arrayList->list[tempIndex + 1] = arrayList->list[tempIndex];
        tempIndex--;
    }
    arrayList->list[index] = value;
    arrayList->currentIndex++;
    return true;
}

bool deleteValue(ArrayList *arrayList, int index, int *value) {
    // 空的list，直接返回false
    if (isEmptyArrayList(arrayList)) {
        return false;
    }
    
    // 删除数据的index不合法，直接返回
    if (index > arrayList->currentIndex || index < 0) {
        return false;
    }
    
    *value = arrayList->list[index];
    
    int tempIndex = index;
    while (tempIndex <= arrayList->currentIndex) {
        arrayList->list[tempIndex] = arrayList->list[tempIndex + 1];
        tempIndex++;
    }
    arrayList->currentIndex--;
    return true;
}

bool indexOfItem(ArrayList *arrayList, int index, int *item) {
    // 空的list，直接返回false
    if (isEmptyArrayList(arrayList)) {
        return false;
    }
    
    if (index > arrayList->currentIndex || index < 0) {
        return false;
    }
    
    *item = arrayList->list[index];
    return true;
}

void clearAll(ArrayList *arrayList) {
    if (isEmptyArrayList(arrayList)) {
        return;
    }
    memset(arrayList->list, 0, sizeof(int) * arrayList->length);
    arrayList->currentIndex = -1;
    arrayList->length = 0;
    printf("ArrayList被清空了\n");
}

void showArrayList(ArrayList *arrayList) {
    if (isEmptyArrayList(arrayList)) {
        return;
    }
    
    for (int *p = arrayList->list; p < arrayList->list + arrayList->length; p++) {
        printf("%4d", *p);
    }
    printf("\n");
}
