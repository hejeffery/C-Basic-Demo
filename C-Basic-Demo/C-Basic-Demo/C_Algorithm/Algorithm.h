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

#endif /* Algorithm_h */
