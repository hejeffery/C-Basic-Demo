//
//  Algorithm.h
//  C-Basic-Demo
//
//  Created by HeJeffery on 2017/1/23.
//  Copyright © 2017年 HeJeffery. All rights reserved.
//

#ifndef Algorithm_h
#define Algorithm_h

#include <stdio.h>
#include <stdbool.h>

////////////////////////////////////////////////////////////////////////////////////
//                                                                                //
//                                    部分算法的实现                                 //
//                                                                                //
////////////////////////////////////////////////////////////////////////////////////

/**
 *  选择排序
 *
 *  @param array 需要排序的数组
 *  @param count 数组的个数
 */
void selectionSort(int *array, int count);

/**
 *  冒泡排序
 *
 *  @param array 需要排序的数组
 *  @param count 数组的个数
 */
void bubbleSort(int *array, int count);

/**
 *  插入排序
 *
 *  @param array 需要排序的数组
 *  @param count 数组的个数
 */
void insertSort(int *array, int count);

/**
 *  二分查找(折半查找)
 *
 *  @param array 需要查找的数组
 *  @param count 数组的个数
 *  @param searchNumber 查找的元素
 */
int binarySearch(int *array, int count, int searchNumber);

/**
 *  拉格朗日查找(二分查找的通用模式)
 *
 *  @param array 需要查找的数组
 *  @param count 数组的个数
 *  @param searchNumber 查找的元素
 */
int lagrangeSearch(int *array, int count, int searchNumber);

/**
 *  使一个有序的数组乱序
 *
 *  @param array 需要乱序的数组
 *  @param count 数组的个数
 */
void outOfOrderArray(int *array, int count);

/**
 *  递归实现斐波拉契数列
 *
 *  @param number 第几个数
 */
int fibonacciRecursion(int number);

/**
 *  数组for循环实现斐波拉契数列
 *
 *  @param number 第几个数
 */
int fibonacciArrayFor(int number);

/**
 *  数组while循环实现斐波拉契数列
 *
 *  @param number 第几个数
 */
int fibonacciArrayWhile(int number);

/**
 *  递归实现1至100的加法
 *
 *  @param number 第几个数
 */
int recursionPlus(int number);

/**
 *  打印九九乘法表
 *
 */
void nineMultNine();

/**
 *  十进制转二进制
 *
 *  @param number 需要转换的数字
 */
void decimalToBinary(int number);

/**
 *  反转数字，如12345转为54321
 *
 *  @param number 需要转换的数字
 */
int reverseNumber(int number);

/**
 *  反转数字的递归实现
 *
 *  @param number 需要转换的数字
 *  @param result 反转后的结果
 */
int reverseNumberByRecursion(int number, int *result);

/**
 *  计算数字的各个位数相加(递归实现)，比如12345，就是1 + 2 + 3 + 4 + 5 = 15
 *
 *  @param number 数字
 */
int numberToAddByRecursion(int number);

/**
 *  打印杨辉三角
 *
 */
void yangHuisTriangle();

/**
 *  判断数组是不是一个递增数组，递归实现
 *
 *  @param array 需要判断的数组
 *  @param count 数组的个数
 */
bool isIncreasingArrayByRecursion(int *array, int count);

/**
 *  打印环形的数组，类似下面的
 //     1   2   3   4   5   6   7
 //    24  25  26  27  28  29   8
 //    23  40  41  42  43  30   9
 //    22  39  48  49  44  31  10
 //    21  38  47  46  45  32  11
 //    20  37  36  35  34  33  12
 //    19  18  17  16  15  14  13
 *
 */
void circleArray();

/**
 *  数组的反转
 *
 *  @param array 需要判断的数组
 *  @param count 数组的个数
 */
void reverseArray(int *array, int count);

/**
 *  递归解决台阶问题
 *  台阶问题的描述：楼梯有20阶台阶，上楼可以一步上1阶、2阶或3阶三种走法，计算共有多少种不同的走法
 *  思路：stepNumber = 1，有1中走法；stepNumber = 2，有2中走法(11和2)；stepNumber = 3，有4种走法(111, 12, 12, 3)...
 *  @param stepNumber 台阶数
 */
int stepProblemByRecursion(int stepNumber);

/**
 *  求数组的交集
 *
 */
void arrayIntersection();

/**
 *  求数组的并集
 *
 */
void arrayUnion();

/**
 *  数组去重
 *
 *  @param array 需要去重的数组
 *  @param count 数组的个数
 */
void duplicateArray(int *array, int count);

/**
 *  计算数组中数字出现的次数
 *
 *  @param array 需要处理的数组
 *  @param count 数组的个数
 */
void repeatNumberCountInArray(int *array, int count);

/**
 *  位运算的部分操作
 *
 */
void bitOperation();

#endif /* Algorithm_h */
