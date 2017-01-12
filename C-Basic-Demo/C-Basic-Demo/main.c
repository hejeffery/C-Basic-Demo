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

#include "ArrayStack.h"
#include "ArrayQueue.h"

// 递归实现斐波拉契数列
int fibonacciRecursion(int number) {
    if (number == 1 || number == 2) {
        return 1;
        
    } else {
        // 推理出递归的公式：f(n) = f(n - 1) + f(n - 2) (n >= 2)
        return fibonacciRecursion(number - 1) + fibonacciRecursion(number - 2);
    }
}

// 数组for循环实现斐波拉契数列
int fibonacciArrayFor(int number) {
    // 小于等于0就返回0
    if (number <= 0) {
        return 0;
    }
    
    int array[number];
    
    // for实现
    for (int i = 0; i < number; i++) {
        if (i == 0 || i == 1) {
            array[i] = 1;
            
        } else {
            array[i] = array[i - 1] + array[i - 2];
        }
    }
    return array[number - 1];
}

// 数组while循环实现斐波拉契数列
int fibonacciArrayWhile(int number) {
    // 小于等于0就返回0
    if (number <= 0) {
        return 0;
    }
    
    int array[number];
    
    // while实现
    int index = 0;
    while (index != number) {
        if (index == 0 || number == 1) {
            array[index] = 1;
            
        } else {
            array[index] = array[index - 1] + array[index - 2];
        }
        index++;
    }
    return array[index - 1];
}

// 递归实现1至100的加法
int recursionPlus(int number) {
    if (number < 0) {
        return 0;
    }
    return recursionPlus(number - 1) + number;
}

// 打印九九乘法表
void nineMultNine() {
    for (int i = 1; i < 10; i++) {
        for (int j = 1; j <= i; j++) {
            printf("%d*%d = %2d   ", i, j, i * j);
        }
        printf("\n");
    }
}

// 选择排序
void selectionSort(int *array, int count) {
    // 选择排序法的思想：每一趟都是找出最值(和找出一个数组中的最值算法类似)，然后交换。
    // 也就是第一个数和后面的数逐个扫描，第二个数和后面的数逐个扫描....
    for (int i = 0; i < count; i++) {
        for (int j = i + 1; j < count; j++) {
            if (array[i] < array[j]) {
                array[i] = array[i] ^ array[j];
                array[j] = array[i] ^ array[j];
                array[i] = array[i] ^ array[j];
            }
        }
    }
    
    for (int i = 0; i < count; i++) {
        printf("%d  \n", array[i]);
    }
}

// 冒泡排序
void bubbleSort(int *array, int count) {
    // 冒泡排序的思想：数字上浮或者下沉
    int loopNumber = count - 1;
    for (int i = 0; i < loopNumber; i++) {// 每循环一次就有一个数上浮或者下沉
        for (int j = 0; j < loopNumber - i; j++) {
            if (array[j] > array[j + 1]) {
                array[j] = array[j] ^ array[j + 1];
                array[j + 1] = array[j] ^ array[j + 1];
                array[j] = array[j] ^ array[j + 1];
            }
        }
    }
    for (int i = 0; i < count; i++) {
        printf("%d  \n", array[i]);
    }
}

// 插入排序
void insertSort(int *array, int count) {
    // 插入排序的思想：把数组分为n-1个数组序列。每次从数组的最后一个值往前插值
    // 从第二个元素开始
    for (int i = 1; i < count; i++) {
        // 用来记录数组序列的最后一个元素的位置
        int index = i;
        // 用来记录数组序列的最后一个元素
        int element = array[i];
        
        while (index > 0 && element < array[index - 1]) {
            array[index] = array[index - 1];// 往后移
            index--;
        }
        array[index] = element;
    }
    
    for (int i = 0; i < count; i++) {
        printf("%d  \n", array[i]);
    }
}

// 二分查找(折半查找)
int binarySearch(int *array, int count, int searchNumber) {
    int headIndex = 0;
    int tailIndex = count - 1;
    while (headIndex <= tailIndex) {
        int middleIndex = (headIndex + tailIndex) / 2;
        if (searchNumber < array[middleIndex]) {// 从上半部分查找
            tailIndex = middleIndex - 1;
            
        } else if (searchNumber > array[middleIndex]) {// 从下半部分查找
            headIndex = middleIndex + 1;
            
        } else if (searchNumber == array[middleIndex]) {// 找到了
            return middleIndex;
            
        }
    }
    return -1;// 没有找到返回-1
}

// 拉格朗日查找(二分查找的通用模式)
int lagrangeSearch(int *array, int count, int searchNumber) {
    int headIndex = 0;
    int tailIndex = count - 1;
    while (headIndex <= tailIndex) {
        // 比例
        float ratio = ((searchNumber - array[headIndex]) / (array[tailIndex] - array[headIndex])) * 1.0;
        int middleIndex = headIndex + (tailIndex - headIndex) * ratio;
        if (searchNumber < array[middleIndex]) {// 从上半部分查找
            tailIndex = middleIndex - 1;
            
        } else if (searchNumber > array[middleIndex]) {// 从下半部分查找
            headIndex = middleIndex + 1;
            
        } else if (searchNumber == array[middleIndex]) {// 找到了
            return middleIndex;
            
        }
    }
    return -1;// 没有找到返回-1
}

// 使一个有序的数组乱序
void outOfOrderArray(int *array, int count) {
    // 获取随机数种子
    // 思想：1.第1个元素和第1个元素后面的9个元素中的其中一个交换
    //      2.第2个元素和第2个元素后面的8个元素中的其中一个交换
    //      3.第3个元素和第3个元素后面的7个元素中的其中一个交换......
    time_t t;
    srand((unsigned int)time(&t));
    
    for (int i = 0; i < count - 1; i++) {
        int randomIndex = i + (rand() % (count - 1 - i));
        int temp = array[i];
        array[i] = array[randomIndex];
        array[randomIndex] = temp;
    }
    
    for (int i = 0; i < count; i++) {
        printf("%d  \n", array[i]);
    }
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

// 十进制转二进制
void decimalToBinary(int number) {
    if (number == 0) {
        return;

    } else {
        
        decimalToBinary(number / 2);
        printf("%d", number % 2);
    }
}

// 反转数字，如12345转为54321
int reverseNumber(int number) {
    int result = 0;
    
    // while实现
    if (number != 0) {
        while (number) {
            int temp = number % 10;
            result = result * 10 + temp;
            number /= 10;
        }
    }
    
//    // for实现
//    if (number != 0) {
//        for (; number > 0; number /= 10) {
//            int temp = number % 10;
//            result = result * 10 + temp;
//        }
//    }
    return result;
}

// 反转数字的递归实现
int reverseNumberByRecursion(int number, int *result) {
    if (number == 0) {
        return 1;

    } else {
        *result = *result * 10 + number % 10;
        return reverseNumberByRecursion(number / 10, result);
    }
}

// 计算数字的各个位数相加(递归实现)，比如12345，就是1 + 2 + 3 + 4 + 5 = 15
int numberToAddByRecursion(int number) {
    if (number == 0) {
        return 0;
        
    } else {
        return number % 10 + numberToAddByRecursion(number / 10);
    }
}

// 打印杨辉三角
void yangHuisTriangle() {
    int array[10][10] = {0};
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            // 第一列或者i == j时，都为1
            if (i == j || j == 0) {
                array[i][j] = 1;

            } else {
                array[i][j] = array[i - 1][j - 1] + array[i - 1][j];
            }
        }
    }
    
    int blankNum = 20;
    for (int i = 0; i < 10; i++) {
        printf("%*d", blankNum - 2 * i, array[i][0]);
        for (int j = 1; j <= i; j++) {
            printf("%4d", array[i][j]);
        }
        printf("\n");
    }
}

// 判断数组是不是一个递增数组，递归实现
bool isIncreasingArrayByRecursion(int *array, int count) {
    if (count == 1) {// 只有一个元素，递增
        return 1;

    } else if (count == 2) {
        // 只有两个元素，判断0和1
        return array[1] >= array[0];

    } else {
        return isIncreasingArrayByRecursion(array, count - 1) && array[count - 1] >= array[count - 2];
    }
}

// 打印环形的数组，类似下面的
//     1   2   3   4   5   6   7
//    24  25  26  27  28  29   8
//    23  40  41  42  43  30   9
//    22  39  48  49  44  31  10
//    21  38  47  46  45  32  11
//    20  37  36  35  34  33  12
//    19  18  17  16  15  14  13
#define NUM 7
void circleArray() {

    int array[NUM][NUM] = {0};
    
    int num = 1;
    for (int i = 0, j = 0, k = 0; k < ((NUM + 1)) / 2; k++, i = k, j = k) {
        
        while (i < NUM - j) {
            array[i][j] = num++;
            j++;
        }
        
        j--;
        i++;
        while (i < NUM - k) {
            array[i][j] = num++;
            i++;
        }

        i--;
        j--;
        while (j >= k) {
            array[i][j] = num++;
            j--;
        }

        j++;
        i--;
        while (i > k) {
            array[i][j] = num++;
            i--;
        }
    }
    
    for (int i = 0; i < NUM; i++) {
        for (int j = 0; j < NUM; j++) {
            printf("%4d", array[i][j]);
        }
        printf("\n");
    }
}

int main(int argc, const char * argv[]) {
    
//    // 递归实现斐波拉契数列
//    int fibonacciRecursionNum = fibonacciRecursion(7);
//    printf("fibonacciRecursionNum = %d\n", fibonacciRecursionNum);
//
//    // 数组for循环实现斐波拉契数列
//    int fibonacciArrayForNum = fibonacciArrayFor(7);
//    printf("fibonacciArrayForNum = %d\n", fibonacciArrayForNum);
//
//    // 数组while循环实现斐波拉契数列
//    int fibonacciArrayWhileNum = fibonacciArrayFor(7);
//    printf("fibonacciArrayWhileNum = %d\n", fibonacciArrayWhileNum);
//
//    // 递归实现1至100的加法
//    int recursionPlusResult = recursionPlus(100);
//    printf("recursionPlusResult = %d\n", recursionPlusResult);
//
//    // 打印九九乘法表
//    nineMultNine();
//
//    // 选择排序
//    int array[10] = {4, 5, 88, 3, 1, 7, 45, 78, 9, 23};
//    selectionSort(array, 10);
//
//    // 冒泡排序
//    int array[10] = {4, 5, 88, 3, 1, 7, 45, 78, 9, 23};
//    bubbleSort(array, 10);
//
//    // 插入排序
//    int array[10] = {4, 5, 88, 3, 1, 7, 45, 78, 9, 23};
//    insertSort(array, 10);
//
//    // 二分查找
//    int array[10] = {1, 3, 4, 6, 7, 9, 13, 15, 33, 64};
//    int index = binarySearch(array, 10, 13);
//    if (index == -1) {
//        printf("没有找到\n");
//    } else {
//        printf("找到了，位置是 index = %d\n", index);
//    }
//
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
    
    return 0;
}
