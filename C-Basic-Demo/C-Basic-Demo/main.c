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

#include "Algorithm.h"
#include "StandardLibImpl.h"
#include "StringTool.h"
#include "ArrayStack.h"
#include "ArrayQueue.h"
#include "SequenceArrayList.h"
#include "DynamicQueue.h"
#include "DynamicStack.h"

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

// 一些数组容易混淆的知识点
void someArrayConfusion() {
    printf("*********一维数组*********\n");
    // 一维数组
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    // a和&a的区别
    printf("a = %p, &a = %p\n", a, &a);
    // 1.a是数组的首地址，指向数组元素的第一个元素；
    // 2.&a是数组的地址，指向一个一维数组。此时可以把数组当成一个类型，改类型的大小是4(int是4个字节) * 10，所以&a + 1代表移动该数组类型的1个长度，在此也就是移动40字节
    // 它们的本质就是指针的类型不一样
    // 下面的+1就是加上一个类型的大小
    printf("a + 1 = %p, &a + 1 = %p\n", a + 1, &a + 1);
    printf("sizeof(a) = %lu, sizeof(*(&a)) = %lu, sizeof(&a) = %lu\n", sizeof(a), sizeof(*(&a)), sizeof(&a));
    
    printf("\n*********二维数组*********\n");
    // 二维数组
    int b[3][4] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    // b、&b，*b的区别
    printf("b = %p, &b = %p, *b = %p\n", b, &b, *b);
    // 1.b是二维数组的首行地址，相当于行指针
    // 2.&b是数组的地址，指向一个二维数组。此时可以把数组当成一个类型，改类型的大小是4(int是4个字节) * 3 * 4，所以&b + 1代表移动该数组类型的1个长度，在此也就是移动48字节
    // 3.*b是首行首列的地址，相当于列指针，*b + 1往后移动一个元素，就是首行第1列的地址
    printf("b + 1= %p, &b + 1 = %p, *b + 1 = %p\n", b + 1, &b + 1, *b + 1);
    printf("sizeof(b) = %lu, sizeof(*b) = %lu, sizeof(&b) = %lu\n", sizeof(b), sizeof(*b), sizeof(&b));
    
    // 数组指针
    printf("\n*********数组指针*********\n");
    int (*p)[10];
    // 可以判断这里的p的类型是数组
    printf("p = %p, p + 1 = %p", p, p + 1);
}

// 二维数组和指针的总结
void twoDimensionalArray() {
    int array[4][4] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%p, %2d, ", &array[i][j], array[i][j]);
        }
        printf("\n");
    }
    
    printf("\n");
    
    printf("\n*********打印行*********\n");
    for (int i = 0; i < 4; i++) {
        printf("%p, %2d\n", array + i, *array[i]);
    }
    
    printf("\n*********打印列*********\n");
    for (int i = 0; i < 4; i++) {
        printf("%p, %2d\n", *array + i, *(*array + i));
    }
    printf("\n");
    
    // 二维数组总结：类型的转换是关键
    // array是行指针，类型是int (*p)[4]；*(array + i) + j是列指针，类型是 int *p
    // array + i === &array[i]，表示第i行
    // *(array + i) === array[i] 表示第i行第0列的地址
    // *(array + i) + j === array[i] + j === &array[i][j] 表示第i行第j列的地址
    // *(*(array + i) + j) === *(array[i] + j) === array[i][j] 表示第i行第j列
}

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

// 用动态分配内存打印
// 1
// 1 2
// 1 2 3
// 1 2 3 4
// 1 2 3 4 5
void dynamicPrintArray() {
    int count = 5;
    int **array = (int **)malloc(sizeof(int *) * count);
    for (int i = 0; i < count; i++) {
        *(array + i) = malloc(sizeof(int) * (i + 1));
        for (int j = 0; j <= i; j++) {
            *(*(array + i) + j) = j + 1;
            printf("%4d", *(*(array + i) + j));
        }
        printf("\n");
    }
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

    // mem的部分实现
    // 标准库memset的实现
    char memsets[10];
    hjmemset(memsets, 0, 10);
    for (int i = 0; i < 10; i++) {
        printf("memsets[%d] = %c\n", i, memsets[i]);
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
    
//    // 动态数组队列
//    dynamicQueueImpl();
    
//    // 动态数组栈
//    dynamicStackImpl();
    
//    // 用动态分配内存打印
//    dynamicPrintArray();
    
    // 部分标准库实现测试
    standardLibImplTest();
    
//    // StringTool的处理
//    stringToolTest();
    
    return 0;
}
