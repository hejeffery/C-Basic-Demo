//
//  DynamicSequenceArrayList.c
//  C-Basic-Demo
//
//  Created by HeJeffery on 2017/2/6.
//  Copyright © 2017年 HeJeffery. All rights reserved.
//

#include "DynamicSequenceArrayList.h"
#include <stdlib.h>
#include <memory.h>

bool createDynamicArrayList(DynamicArrayList *arrayList) {
    
    arrayList->list = (int *)malloc(sizeof(int));
    if (arrayList->list == NULL) {
        return false;
    }
    
    arrayList->length = 0;
    arrayList->tailIndex = -1;
    
    return true;
}

bool createDynamicArrayListWithData(DynamicArrayList *arrayList, int data) {
    
    arrayList->list = (int *)malloc(sizeof(int));
    if (arrayList->list == NULL) {
        return false;
    }
    
    arrayList->length = 1;
    arrayList->tailIndex = 0;
    arrayList->list[arrayList->tailIndex] = data;

    return true;
}

bool createDynamicArrayListWithArray(DynamicArrayList *arrayList, int *array, int length) {
    
    arrayList->list = (int *)malloc(sizeof(int) * length);
    if (arrayList->list == NULL) {
        return false;
    }
    
    arrayList->length = length;
    arrayList->tailIndex = length - 1;
    memcpy(arrayList->list, array, sizeof(int) * length);
    
    return true;
}

bool isEmptyDynamicArrayList(DynamicArrayList *arrayList) {
    if (arrayList->tailIndex == -1) {
        return true;
    }
    return false;
}

bool addValue(DynamicArrayList *arrayList, int value) {
    
    if (arrayList->list == NULL) {
        return false;
    }
    
    // 扩展内存
    arrayList->list = (int *)realloc(arrayList->list, sizeof(int) * (arrayList->length + 1));
    if (arrayList->list == NULL) {
        return false;
    }

    arrayList->length++;
    arrayList->tailIndex++;
    arrayList->list[arrayList->tailIndex] = value;

    return true;
}

bool addValues(DynamicArrayList *arrayList, int *array, int length) {
    
    if (arrayList->list == NULL) {
        return false;
    }
    
    // 扩展内存
    arrayList->list = (int *)realloc(arrayList->list, sizeof(int) * (arrayList->length + length));
    if (arrayList->list == NULL) {
        return false;
    }
    
    memcpy(arrayList->list + arrayList->length, array, sizeof(int) * length);
    arrayList->length += length;
    arrayList->tailIndex += length;
    return true;
}

bool insertValue(DynamicArrayList *arrayList, int index, int value) {
    
    if (arrayList->list == NULL) {
        return false;
    }
    
    // 插入数据的index不合法，直接返回
    if (index > (arrayList->length + 1) || index < 0) {
        return false;
    }
    
    // 扩展内存
    arrayList->list = (int *)realloc(arrayList->list, sizeof(int) *  (arrayList->length + 1));
    if (arrayList->list == NULL) {
        return false;
    }
    
    int tempIndex = arrayList->tailIndex;
    while (tempIndex >= index) {
        // 往后移
        arrayList->list[tempIndex + 1] = arrayList->list[tempIndex];
        tempIndex--;
    }
    
    arrayList->list[index] = value;
    arrayList->length++;
    arrayList->tailIndex++;
    
    return true;
}

bool insertValues(DynamicArrayList *arrayList, int index, int *array, int length) {
    
    if (arrayList->list == NULL) {
        return false;
    }
    
    // 插入数据的index不合法，直接返回
    if (index > (arrayList->length + 1) || index < 0) {
        return false;
    }
    
    // 扩展内存
    arrayList->list = (int *)realloc(arrayList->list, sizeof(int) * (arrayList->length + length));
    if (arrayList->list == NULL) {
        return false;
    }
    
    int tempIndex = arrayList->tailIndex;
    while (tempIndex >= index) {
        // 往后移
        arrayList->list[tempIndex + length] = arrayList->list[tempIndex];
        tempIndex--;
    }

    // 赋值
    for (int *p = arrayList->list + index, i = 0; p < arrayList->list + index + length; p++, i++) {
        *p = array[i];
    }
    arrayList->length += length;
    arrayList->tailIndex += length;
    
    return true;
}

bool deleteListValue(DynamicArrayList *arrayList, int index, int *value) {
    
    if (isEmptyDynamicArrayList(arrayList)) {
        return false;
    }
    
    // 删除数据的index不合法，直接返回
    if (index < 0 || index > arrayList->tailIndex) {
        return false;
    }
    
    // 保存最后一个值
    int lastValue = arrayList->list[arrayList->tailIndex];
    // 压缩内存
    arrayList->list = (int *)realloc(arrayList->list, sizeof(int) *(arrayList->length - 1));
    if (arrayList->list == NULL) {
        return false;
    }
    
    *value = arrayList->list[index];
    
    int tempIndex = index;
    while (tempIndex <= arrayList->tailIndex) {
        arrayList->list[tempIndex] = arrayList->list[tempIndex + 1];
        tempIndex++;
    }
    
    arrayList->length--;
    arrayList->tailIndex--;
    arrayList->list[arrayList->tailIndex] = lastValue;

    return true;
}

bool indexOfListItem(DynamicArrayList *arrayList, int index, int *item) {
    
    if (isEmptyDynamicArrayList(arrayList)) {
        return false;
    }
    
    if (index < 0 || index > arrayList->tailIndex) {
        return false;
    }
    
    *item = arrayList->list[index];
    return true;
}

void clearAllList(DynamicArrayList *arrayList) {
    
    if (isEmptyDynamicArrayList(arrayList)) {
        return;
    }
    
    arrayList->list = (int *)realloc(arrayList->list, sizeof(int));
    if (arrayList->list == NULL) {
        return;
    }

    arrayList->length = 0;
    arrayList->tailIndex = -1;
    printf("DynamicArrayList被清空了\n");
}

void showDynamicArrayList(DynamicArrayList *arrayList) {
    
    if (isEmptyDynamicArrayList(arrayList)) {
        return;
    }
    
    for (int *p = arrayList->list; p < arrayList->list + arrayList->length; p++) {
        printf("%4d", *p);
    }
    printf("\n");
}
