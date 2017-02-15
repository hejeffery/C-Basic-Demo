//
//  main.c
//  C-Basic-Demo
//
//  Created by HeJeffery on 2017/1/9.
//  Copyright © 2017年 HeJeffery. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#include "CBasic.h"
#include "CPractice.h"
#include "Algorithm.h"
#include "StandardLibImpl.h"
#include "StringTool.h"
#include "ArrayStack.h"
#include "ArrayQueue.h"
#include "SequenceArrayList.h"
#include "DynamicSequenceArrayList.h"
#include "DynamicQueue.h"
#include "DynamicStack.h"
#include "LinkedList.h"
#include "CircleLinkedList.h"


// 函数指针的接口功能
int add(int a, int b) {
    return a + b;
}

int sub(int a, int b) {
    return a - b;
}

// 计算函数，参数是函数指针
int calculation(int (*p)(int, int), int a, int b) {
    // 函数的类型要一致：返回值，参数要一一对应
    return p(a, b);
}

// 返回值是函数指针的函数
int (*returnFuncPoint())(int, int) {
    return sub;
}

// 栈，数组实现
void stackArrayImpl() {
    Stack stack;
    createStack(&stack);
    
    // 判断是否是空栈
    bool isEmpty = isEmptyStack(&stack);
    if (isEmpty) {
        printf("是空栈\n");
    }
    
    // 判断是否是满栈
    bool isFull = isFullStack(&stack);
    if (isFull) {
        printf("是满栈\n");
    } else {
        printf("不是满栈\n");
    }
    
    // 压栈
    int array[5] = {1, 2, 3, 4, 5};
    for (int i = 0; i < 5; i++) {
        push(&stack, array[i]);
    }
    
    // 显示栈的数据
    showStackData(&stack);
    
    // 出栈
    while (!isEmptyStack(&stack)) {
        int popNumber = 0;
        int popIndex = 0;
        bool popSuccess = pop(&stack, &popNumber, &popIndex);
        if (popSuccess) {
            printf("出栈：popNumber = %d, popIndex = %d\n", popNumber, popIndex);
        }
        
        // 显示栈的数据
        showStackData(&stack);
    }
}

// 队列，数组实现
void queueArrayImpl() {
    Queue queue;
    createQueue(&queue);
    
    bool isEmpty = isEmptyQueue(&queue);
    if (isEmpty) {
        printf("是空队列\n");
    }
    
    // 判断是否是满栈
    bool isFull = isFullQueue(&queue);
    if (isFull) {
        printf("是满队列\n");
    } else {
        printf("不是满队列\n");
    }
    
    // 入队
    int array[5] = {1, 2, 3, 4, 5};
    for (int i = 0; i < 5; i++) {
        enqueue(&queue, array[i]);
    }
    
    int headData = headElement(&queue);
    int tailData = tailElement(&queue);
    
    printf("headData = %d, tailData = %d\n", headData, tailData);
    
    // 显示队列的数据
    showQueueData(&queue);
    
    // 出队
    while (!isEmptyQueue(&queue)) {
        int value = 0;
        dequeue(&queue, &value);
        printf("出队列的值 value = %d\n", value);
        
        // 显示队列的数据
        showQueueData(&queue);
    }
    
    printf("\n");
}

// 数组的顺序存储
void sequenceArrayListImpl() {
    ArrayList arrayList;
    createArrayList(&arrayList, 10);
    
    append(&arrayList, 1);
    append(&arrayList, 2);
    append(&arrayList, 3);
    insert(&arrayList, 3, 4);
    insert(&arrayList, 4, 5);
    append(&arrayList, 6);
    append(&arrayList, 7);
    append(&arrayList, 8);
    append(&arrayList, 9);
    append(&arrayList, 10);
    showArrayList(&arrayList);
    
    // 删除数据
    int deletedValue = 0;
    deleteValue(&arrayList, 2, &deletedValue);
    
    showArrayList(&arrayList);
    
    // 获取数据
    int item = 0;
    indexOfItem(&arrayList, 3, &item);
    printf("item = %d\n", item);
    
    // 清除数据
    clearAll(&arrayList);
    
    // 使用createArrayListWithData创建
    printf("\n-----使用createArrayListWithData创建-----\n");
    ArrayList arrayList1;
    createArrayListWithData(&arrayList1, 10, 10);
    showArrayList(&arrayList1);
    
    // 使用createArrayListWithArray创建
    printf("\n-----使用createArrayListWithArray创建-----\n");
    ArrayList arrayList2;
    int tempArray[5] = {1, 2, 3, 4, 5};
    createArrayListWithArray(&arrayList2, tempArray, 5);
    showArrayList(&arrayList2);
}

// 动态数组队列
void dynamicQueueImpl() {
    DynamicQueue queue;
    createDynamicQueue(&queue, 3);

    bool isEmpty = isEmptyDynamicQueue(&queue);
    if (isEmpty) {
        printf("是空队列\n");
    }

    DynamicQueue *pQueue = &queue;
    enqueueDynamic(&pQueue, 1);
    showDynamicQueueData(&queue);
    
    enqueueDynamic(&pQueue, 2);
    showDynamicQueueData(&queue);
    
    enqueueDynamic(&pQueue, 3);
    showDynamicQueueData(&queue);
    
    enqueueDynamic(&pQueue, 4);
    showDynamicQueueData(&queue);
    
    enqueueDynamic(&pQueue, 5);
    showDynamicQueueData(&queue);

    printf("队头的数据是 = %d\n", headDynamicElement(&queue));
    printf("队尾的数据是 = %d\n", tailDynamicElement(&queue));

    // 出队
    while (!isEmptyDynamicQueue(&queue)) {
        int value = 0;
        dequeueDynamic(&queue, &value);
        printf("出队列的值 value = %d\n", value);
        // 显示队列的数据
        showDynamicQueueData(&queue);
    }
}

// 动态数组栈
void dynamicStackImpl() {
    DynamicStack stack;
    createDynamicStack(&stack, 3);
    
    bool isEmpty = isEmptyDynamicStack(&stack);
    if (isEmpty) {
        printf("是空栈\n");
    }
    
    DynamicStack *pStack = &stack;
    pushDynamicStack(&pStack, 1);
    showDynamicStackData(&stack);
    
    pushDynamicStack(&pStack, 2);
    showDynamicStackData(&stack);
    
    pushDynamicStack(&pStack, 3);
    showDynamicStackData(&stack);
    
    pushDynamicStack(&pStack, 4);
    showDynamicStackData(&stack);
    
    pushDynamicStack(&pStack, 5);
    showDynamicStackData(&stack);
    
    // 出栈
    while (!isEmptyDynamicStack(&stack)) {
        int value = 0;
        int index = 0;
        popDynamicStack(&stack, &value, &index);
        printf("出栈的值 value = %d， index = %d\n", value, index);
        // 显示队列的数据
        showDynamicStackData(&stack);
    }
}

// 数组的顺序存储，动态数组
void dynamicSequenceArrayListImpl() {
    
    DynamicArrayList arrayList;
    createDynamicArrayList(&arrayList);
    addValue(&arrayList, 1);
    addValue(&arrayList, 3);
    addValue(&arrayList, 5);
    addValue(&arrayList, 7);
    addValue(&arrayList, 9);
    showDynamicArrayList(&arrayList);

    int addArrays[5] = {2, 4, 6, 8, 10};
    addValues(&arrayList, addArrays, 5);
    showDynamicArrayList(&arrayList);
    
    insertValue(&arrayList, 0, 100);
    showDynamicArrayList(&arrayList);
    
    int insertArrays[3] = {81, 82, 83};
    insertValues(&arrayList, 1, insertArrays, 3);
    showDynamicArrayList(&arrayList);
    
    printf("\n");
    int deleteValue = 0;
    deleteListWithIndex(&arrayList, 4, &deleteValue);
    printf("deleteValue = 删除的值是：%d\n", deleteValue);
    showDynamicArrayList(&arrayList);
    
    printf("\n");
    int itemValue = 0;
    indexOfListItem(&arrayList, 2, &itemValue);
    printf("itemValue = %d\n", itemValue);
    
    printf("\n");
    int deleteIndex = 0;
    deleteListWithValue(&arrayList, 2, &deleteIndex);
    printf("deleteIndex = 删除的是第%d个\n", deleteIndex);
    showDynamicArrayList(&arrayList);
    
    printf("\n");
    printf("clear before arrayList->list = %p\n", (&arrayList)->list);
    clearAllList(&arrayList);
    printf("clear after  arrayList->list = %p\n", (&arrayList)->list);
    showDynamicArrayList(&arrayList);
}

// 链式存储
void linkedListImpl() {
    
    LinkedList *list = createLinkedList();
    
    appendList(list, 1);
    appendList(list, 2);
    appendList(list, 3);
    appendList(list, 4);
    appendList(list, 5);
    appendList(list, 6);
    appendList(list, 7);
    appendList(list, 8);
    showLinkedList(list);
    
    printf("\n插入数据\n");
    bool insertSuccess = insertList(list, 7, 99);
    if (insertSuccess) {
        printf("插入成功\n");

    } else {
        printf("插入失败\n");
    }
    showLinkedList(list);
    
    printf("\n查找链表中间位置的结点\n");
    LinkedList *centerNode = findCenterNode(list);
    if (centerNode != NULL) {
        printf("找到了中间位置的结点，该结点的值是 = %d\n", centerNode->data);
    } else {
        printf("没有找到中间位置的结点\n");
    }

    int deleteNodeValue = 0;
    bool isDeleteSuccess = deleteListWithPosition(list, 6, &deleteNodeValue);
    if (isDeleteSuccess) {
        printf("\n删除结点成功，该结点的值是 = %d\n", deleteNodeValue);

    } else {
        printf("删除结点失败\n");
    }
    showLinkedList(list);

    printf("\n");
    int findPosition = -1;
    bool isFindItem = findListItem(list, 2, &findPosition);
    if (isFindItem) {
        printf("找到元素，位置是 = %d\n", findPosition);

    } else {
        printf("没有找到元素\n");
    }
    
    printf("\n");
    int deletePosition = -1;
    bool isDeleteItemSuccess = deleteListWithItem(list, 5, &deletePosition);
    if (isDeleteItemSuccess) {
        printf("删除元素成功，元素的位置是 = %d\n", deletePosition);

    } else {
        printf("删除元素失败\n");
    }
    showLinkedList(list);

    printf("\n");
    LinkedList *findNode = findNodeWithItem(list, 3);
    if (findNode != NULL) {
        printf("找到结点了\n");
        
    } else {
        printf("没有找到结点\n");
    }
    
    // 反向打印链表中的值
    printf("\n反向打印链表中的值\n");
    reversePrintList(list);
    printf("\n");
    
    printf("\n链表反转\n");
    reverseList(list);
    showLinkedList(list);
    
    printf("\n");
    bool hasCircle = hasCircleList(list);
    if (hasCircle) {
        printf("链表有环\n");

    } else {
        printf("链表无环\n");
    }

    printf("\n");
    bool clearSuccess = clearList(list);
    if (clearSuccess) {
        printf("链表清空成功\n");
        
        bool isEmptyList = isEmptyLinkedList(list);
        if (isEmptyList) {
            printf("是空链表\n");

        } else {
            printf("不是空链表\n");
        }
        
        showLinkedList(list);

    } else {
        printf("链表清空失败\n");
        showLinkedList(list);
    }
    
    // 链表的合并
    printf("\n链表的合并\n");
    LinkedList *list1 = createLinkedList();
    appendList(list1, 1);
    appendList(list1, 3);
    appendList(list1, 5);
    appendList(list1, 7);
    
    LinkedList *list2 = createLinkedList();
    appendList(list2, 2);
    appendList(list2, 4);
    appendList(list2, 6);
    appendList(list2, 8);
    
    LinkedList *mergeResult = mergeList(list1, list2);
    showLinkedList(mergeResult);
}

// 环形链式存储
void circleLinkedListImpl() {
    
    CircleLinkedList *list = createCircleLinkedList();
    appendCircleList(list, 1);
    appendCircleList(list, 2);
    appendCircleList(list, 3);
    appendCircleList(list, 4);
    appendCircleList(list, 5);
    showCircleList(list);
    
    printf("\n");
    bool isEmptyList = isEmptyCircleLinkedList(list);
    if (isEmptyList) {
        printf("是空循环链表\n");

    } else {
        printf("不是空循环链表\n");
    }
    
    printf("\n");
    bool hasCircle = hasCircleLinkedList(list);
    if (hasCircle) {
        printf("链表有环\n");
        
    } else {
        printf("链表无环\n");
    }
    
    printf("\n");
    int length = circleListLength(list);
    printf("环形链表的长度 = %d\n", length);
    
    printf("\n");
    int findPosition = -1;
    bool findItemSuccess = findCircleListItem(list, 100, &findPosition);
    if (findItemSuccess) {
        printf("找到了，位置是 = %d\n", findPosition);

    } else {
        printf("没有找到\n");
    }
    
    printf("\n");
    CircleLinkedList *findNode = findCircleNodeWithItem(list, 4);
    if (findNode) {
        printf("找到了结点，结点的值是 = %d\n", findNode->data);
    }
    
    printf("\n");
    bool insertSuccess = insertCircleList(list, 0, 99);
    if (insertSuccess) {
        printf("插入数据成功\n");

    } else {
        printf("插入数据失败\n");
    }
    showCircleList(list);
    
    bool insertSuccess1 = insertCircleList(list, 4, 89);
    if (insertSuccess1) {
        printf("插入数据成功\n");

    } else {
        printf("插入数据失败\n");
    }
    showCircleList(list);

    printf("\n");
    int deleteValue = 0;
    bool isDeleteSuccess = deleteCircleListWithPosition(list, 0, &deleteValue);
    if (isDeleteSuccess) {
        printf("删除成功，删除的值是 = %d\n", deleteValue);
    } else {
        printf("删除失败\n");
    }
    showCircleList(list);

    printf("\n");
    int deletePostion = -1;
    bool isDeleteItemSuccess = deleteCircleListWithItem(list, 5, &deletePostion);
    if (isDeleteItemSuccess) {
        printf("删除成功，删除的位置是 = %d\n", deletePostion);

    } else {
        printf("删除失败\n");
    }
    showCircleList(list);
}

// 部分标准库实现测试
void standardLibImplTest() {
    
    // string的部分实现
    // 标准库strlen的实现
    char *sourcestr = "hello c";
    unsigned long strLength = hjstrlen(sourcestr);
    printf("hjstrlen：length = %lu\n", strLength);

    // 标准库strcpy的实现
    char strcpystr1[10] = {0};
    char *strcpystr2 = "hello c";
    hjstrcpy(strcpystr1, strcpystr2);
    printf("hjstrcpy：strcpystr1 = %s\n", strcpystr1);

    // 标准库strncpy的实现
    char strncpystr1[10] = {0};
    char *strncpystr2 = "hello c";
    hjstrncpy(strncpystr1, strncpystr2, 5);
    printf("hjstrncpy：strncpystr1 = %s\n", strncpystr1);
    
    // 标准库strcat的实现
    char strcatstr1[20] = "hello";
    char strcatstr2[10] = " world";
    char *strcatresult = hjstrcat(strcatstr1, strcatstr2);
    printf("hjstrcat：strcatresult = %s\n", strcatresult);
    
    // 标准库strncat的实现
    char strncatstr1[20] = "hello";
    char strncatstr2[10] = " shanghai";
    char *strncatresult = hjstrncat(strncatstr1, strncatstr2, 10);
    printf("hjstrncat：strncatresult = %s\n", strncatresult);
    
    // 标准库strchr的实现
    char strchrstr[10] = "hello";
    char *strchrresult = hjstrchr(strchrstr, 'e');
    if (strchrresult == NULL) {
        printf("没有找到\n");

    } else {
        printf("找到了，s = %s\n", strchrresult);
    }
    
    // 标准库strcmp的实现
    char strcmpstr1[10] = "hello2";
    char strcmpstr2[10] = "hello1123";
    int isequalcmp = hjstrcmp(strcmpstr1, strcmpstr2);
    if (isequalcmp == 0) {
        printf("相等\n");

    } else if (isequalcmp > 0) {
        printf("不相等：strcmpstr1 > strcmpstr2\n");

    } else {
        printf("不相等：strcmpstr1 < strcmpstr2\n");
    }
    
    // 标准库strncmp的实现
    char strncmpstr1[10] = "hello2";
    char strncmpstr2[10] = "hello1123";
    int isequalncmp = hjstrncmp(strncmpstr1, strncmpstr2, 5);
    if (isequalncmp == 0) {
        printf("相等\n");
        
    } else if (isequalncmp > 0) {
        printf("不相等：strncmpstr1 > strncmpstr2\n");
        
    } else {
        printf("不相等：strncmpstr1 < strncmpstr2\n");
    }
    
    // 标准库strstr的实现
    char strstrStr1[20] = "hello world";
    char strstrStr2[20] = "ld";
    char *strstrResult = hjstrstr(strstrStr1, strstrStr2);
    if (strstrResult == NULL) {
        printf("没有搜索到\n");
    } else {
        printf("搜索到了，%s\n", strstrResult);
    }
    
    // 标准库strdup的实现
    char *strdupStr = "hello shanghai";
    char *strdupResult = hjstrdup(strdupStr);
    printf("hjstrdup：strdupResult = %s\n", strdupResult);
    // 要释放strdupResult的内存
    free(strdupResult);
    
    // 标准库strpbrk的实现
    char *strpbrkStr1 = "hello chongqing";
    char *strpbrkStr2 = "chong";
    char *strpbrkResult = hjstrpbrk(strpbrkStr1, strpbrkStr2);
    printf("hjstrpbrk：strpbrkResult = %c\n", *strpbrkResult);
    
    // 标准库strrchr的实现
    char *strrchrStr1 = "hello shanghai";
    char *strrchrResult = hjstrrchr(strrchrStr1, 'h');
    printf("hjstrrchr：strrchrResultChar = %c, strrchrResult = %s\n", *strrchrResult, strrchrResult);
    
    // 标准库strrev的实现
    char strrevStr1[20] = "hello shanghai";
    char *strrevResult = hjstrrev(strrevStr1);
    printf("hjstrrev：strrevResult = %s\n", strrevResult);
    
    // 标准库strlwr的实现
    char strlwrStr[30] = "HelLo ChOngQiNG重庆";
    hjstrlwr(strlwrStr);
    printf("hjstrlwr：strlwrStr = %s\n", strlwrStr);
    
    // 标准库strupr的实现
    char struprStr[30] = "HelLo ChOngQiNG重庆";
    hjstrupr(struprStr);
    printf("hjstrupr：struprStr = %s\n", struprStr);

    // mem的部分实现
    // 标准库memset的实现
    char memsets[10];
    hjmemset(memsets, 0, 10);
    for (int i = 0; i < 10; i++) {
        printf("memsets[%d] = %c\n", i, memsets[i]);
    }
    
    // 标准库memcpy的实现
    int memcpys[5] = {1, 2, 3, 4, 5};
    int *memcpyInts = (int *)malloc(sizeof(int) * 5);
    hjmemcpy(memcpyInts, memcpys, sizeof(int) * 5);
    for (int i = 0; i < 5; i++) {
        printf("memcpy：memcpyInts[%d] = %d\n", i, memcpyInts[i]);
    }
    free(memcpyInts);
    
    // 标准库memccpy的实现
    char memccpys1[100] = "hejeffery shanghai chongqing";
    char memccpys2[100] = {0};
    hjmemccpy(memccpys2, memccpys1, 'f', 30);
    printf("memccpy：memccpys2 = %s\n", memccpys2);

    // 标准库memmove的实现
    int memmoves[5] = {1, 2, 3, 4, 5};
    int *memmoveInts = (int *)malloc(sizeof(int) * 5);
    hjmemmove(memmoveInts, memmoves, sizeof(int) * 5);
    for (int i = 0; i < 5; i++) {
        printf("memmove：memmoveInts[%d] = %d\n", i, memmoveInts[i]);
    }
    
    // 标准库memcmp的实现
    char memcmps1[5] = "abcde";
    char memcmps2[5] = "abcdE";
    int memcmpResult = hjmemcmp(memcmps1, memcmps2, 5);
    printf("memcmp：memcmpResult = %d\n", memcmpResult);
    
    // 标准库memchr的实现
    char *memchrs = "abcdefg";
    char *memchrResult = hjmemchr(memchrs, 'g', hjstrlen(memchrs) + 1);
    if (memchrResult == NULL) {
        printf("memchr：没有找到\n");
    } else {
        printf("memchr：找到了，memchrResult = %c\n", *memchrResult);
    }
}

// StringTool的处理
void stringToolTest() {
    
    // 删除字符串中的某个字符
    char deleteStringChr[40] = "abccdefgchicjklmnopqrstuvwxyz";
    printf("deleteStringChr before = %s\n", deleteStringChr);
    deleteCharInString(deleteStringChr, 'c');
    printf("deleteStringChr after  = %s\n", deleteStringChr);
    
    // 删除字符串中的某个字符串
    char deleteString[40] = "abcdefghijklmnopqrstuvwxyz";
    printf("deleteString before = %s\n", deleteString);
    deleteStrInString(deleteString, "fgh");
    printf("deleteString after  = %s\n", deleteString);
    
    // 删除字符串中的所有delStr
    char deleteAllString[40] = "hj hj hejeffery jeffery hj";
    printf("deleteAllString before = %s\n", deleteAllString);
    deleteAllStrInString(deleteAllString, "hj");
    printf("deleteAllString after  = %s\n", deleteAllString);
}

// 简单的压缩/解压字符串(不考虑内存，考虑时间，不能处理超过10个)
void simpleZipStrTime() {
    // 简单的压缩字符串(不考虑内存，考虑时间，不能处理超过10个)
    char *simpleZipStr = "hjjjjjjjjjsssshhhhh";
    printf("被压缩的字符串---simpleZipStr：%s\n", simpleZipStr);
    char *simpleZipResult = simpleZipStringTime(simpleZipStr);
    printf("压缩后的字符串---simpleZipString：%s\n", simpleZipResult);
    // 简单的解压字符串(不考虑内存，考虑时间，不能处理超过10个)
    char *simpleUnzipResult = simpleUnzipStringTime(simpleZipResult);
    printf("解压后的字符串---simpleUnzipResult：%s\n", simpleUnzipResult);
    free(simpleZipResult);
    free(simpleUnzipResult);
}

// 简单的压缩/解压字符串(不考虑时间，考虑空间，不能处理超过10个)
void simpleZipStrSpace() {
    // 简单的压缩字符串(不考虑时间，考虑内存，不能处理超过10个)
    char simpleZipStr[1024] = "hjjjjjjjjjsssshhhhh";
    printf("被压缩的字符串---simpleZipStr：%s\n", simpleZipStr);
    char *simpleZipResult = simpleZipStringSpace(simpleZipStr);
    printf("压缩后的字符串---simpleZipString：%s\n", simpleZipResult);
    // 简单的解压字符串(不考虑时间，考虑内存，不能处理超过10个)
    char *simpleUnzipResult = simpleUnzipStringSpace(simpleZipResult);
    printf("解压后的字符串---simpleUnzipResult：%s\n", simpleUnzipResult);
}

// C Practice
void cpractice() {
    practiceOne();
}

int main(int argc, const char * argv[]) {
    
//    // 递归实现斐波拉契数列
//    int fibonacciRecursionNum = fibonacciRecursion(7);
//    printf("fibonacciRecursionNum = %d\n", fibonacciRecursionNum);

//    // 数组for循环实现斐波拉契数列
//    int fibonacciArrayForNum = fibonacciArrayFor(7);
//    printf("fibonacciArrayForNum = %d\n", fibonacciArrayForNum);

//    // 数组while循环实现斐波拉契数列
//    int fibonacciArrayWhileNum = fibonacciArrayFor(7);
//    printf("fibonacciArrayWhileNum = %d\n", fibonacciArrayWhileNum);

//    // 递归实现1至100的加法
//    int recursionPlusResult = recursionPlus(100);
//    printf("recursionPlusResult = %d\n", recursionPlusResult);

//    // 打印九九乘法表
//    nineMultNine();

//    // 选择排序
//    int array[10] = {4, 5, 88, 3, 1, 7, 45, 78, 9, 23};
//    selectionSort(array, 10);

//    // 冒泡排序
//    int array[10] = {4, 5, 88, 3, 1, 7, 45, 78, 9, 23};
//    bubbleSort(array, 10);

//    // 插入排序
//    int array[10] = {4, 5, 88, 3, 1, 7, 45, 78, 9, 23};
//    insertSort(array, 10);

//    // 插入排序
//    int array[10] = {4, 5, 88, 3, 1, 7, 45, 78, 9, 23};
//    quickSort(array, 0, 9);
//    for (int i = 0; i < 10; i++) {
//        printf("%d  ", array[i]);
//    }
//    printf("\n");
    
//    // 二分查找
//    int array[10] = {1, 3, 4, 6, 7, 9, 13, 15, 33, 64};
//    int index = binarySearch(array, 10, 13);
//    if (index == -1) {
//        printf("没有找到\n");
//    } else {
//        printf("找到了，位置是 index = %d\n", index);
//    }

//    // 拉格朗日查找(二分查找的通用模式)
//    int array[10] = {1, 3, 4, 6, 7, 9, 13, 15, 33, 64};
//    int index = lagrangeSearch(array, 10, 13);
//    if (index == -1) {
//        printf("没有找到\n");
//    } else {
//        printf("找到了，位置是 index = %d\n", index);
//    }
    
//    // 使一个有序的数组乱序
//    int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//    outOfOrderArray(array, 10);
    
//    // 栈，数组实现
//    stackArrayImpl();
    
//    // 队列，数组实现
//    queueArrayImpl();
    
//    // 十进制转二进制
//    decimalToBinary(10);
    
//    // 反转数字，如12345转为54321
//    int result = reverseNumber(12345);
//    printf("result = %d\n", result);
    
//    // 反转数字的递归实现
//    int result = 0;
//    reverseNumberByRecursion(12345, &result);
//    printf("result = %d\n", result);
    
//    // 计算数字的各个位数相加(递归实现)
//    int result = numberToAddByRecursion(123456);
//    printf("result = %d\n", result);
    
//    // 打印杨辉三角
//    yangHuisTriangle();
    
//    // 判断数组是不是一个递增数组，递归实现
//    int array[5] = {1, 2, 3, 3, 5};
//    bool isIncreasing = isIncreasingArrayByRecursion(array, 5);
//    if (isIncreasing) {
//        printf("递增\n");
//    } else {
//        printf("不是递增\n");
//    }
    
//    // 打印环形的数组
//    circleArray();
    
////    int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//    int array[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
//    int count = sizeof(array) / sizeof(array[0]);
//    reverseArray(array, count);
//    for (int i = 0; i < count; i++) {
//        printf("%d   ", array[i]);
//    }
    
//    // 递归解决台阶问题
//    int result = stepProblemByRecursion(20);
//    printf("result = %d\n", result);
    
//    // 求数组的交集
//    arrayIntersection();
    
//    // 求数组的并集
//    arrayUnion();
    
//    // 数组去重
//    int array[15] = {1, 2, 3, 4, 4, 4, 5, 6, 6, 7, 7, 7, 7, 8, 8};
//    duplicateArray(array, 15);
    
//    // 计算数组中数字出现的次数
//    int array[15] = {1, 1, 2, 3, 4, 4, 4, 5, 6, 6, 7, 7, 7, 8, 8};
//    repeatNumberCountInArray(array, 15);
    
//    // 位运算的部分操作
//    bitOperation();
    
//    // 一些数组容易混淆的知识点
//    someArrayConfusion();
    
//    // 二维数组和指针
//    twoDimensionalArray();
    
//    // 函数指针的接口功能
//    int resultAdd = calculation(add, 2, 2);
//    int resultSub = calculation(sub, 9, 1);
//    printf("resultAdd = %d, resultSub = %d\n", resultAdd, resultSub);
//    
//    // 返回值是函数指针的函数
//    int funcPointResult = returnFuncPoint()(9, 2);
//    printf("funcPointResult = %d\n", funcPointResult);
    
//    // 数组的顺序存储
//    sequenceArrayListImpl();
    
//    // 数组的顺序存储，动态数组
//    dynamicSequenceArrayListImpl();
    
//    // 链式存储
//    linkedListImpl();
    
//    // 环形链式存储
//    circleLinkedListImpl();
    
//    // 动态数组队列
//    dynamicQueueImpl();
    
//    // 动态数组栈
//    dynamicStackImpl();
    
//    // 用动态分配内存打印
//    dynamicPrintArray();
    
//    // 部分标准库实现测试
//    standardLibImplTest();
    
//    // StringTool的处理
//    stringToolTest();
    
//    // 简单的压缩/解压字符串(不考虑内存，考虑时间，不能处理超过10个)
//    simpleZipStrTime();
    
//    // 简单的压缩/解压字符串(不考虑时间，考虑内存，不能处理超过10个)
//    simpleZipStrSpace();
    
//    // 通过位域把数字转换为二进制
//    structBit(1);
    
//    // C Practice
//    cpractice();

    return 0;
}
