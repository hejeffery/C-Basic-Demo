//
//  DynamicSequenceArrayList.h
//  C-Basic-Demo
//
//  Created by HeJeffery on 2017/2/6.
//  Copyright © 2017年 HeJeffery. All rights reserved.
//

#ifndef DynamicSequenceArrayList_h
#define DynamicSequenceArrayList_h

#include <stdio.h>
#include <stdbool.h>

typedef struct DynamicSequenceArrayList DynamicArrayList;

////////////////////////////////////////////////////////////////////////////////////
//                                                                                //
//                            数组的顺序存储，动态数组                                 //
//                                                                                //
////////////////////////////////////////////////////////////////////////////////////

struct DynamicSequenceArrayList {
    int *list;// 数组
    int length;// 动态数组的长度
    int tailIndex;// 尾部的索引，从0开始。没有元素是从-1开始
};

/**
 *  创建数组
 *
 *  @param arrayList 需要被初始化的DynamicArrayList的地址
 *  @return 创建成功返回true，创建失败返回false
 */
bool createDynamicArrayList(DynamicArrayList *arrayList);

/**
 *  创建数组
 *
 *  @param arrayList 需要被初始化的DynamicArrayList的地址
 *  @param data 初始化的数据
 *  @return 创建成功返回true，创建失败返回false
 */
bool createDynamicArrayListWithData(DynamicArrayList *arrayList, int data);

/**
 *  创建数组
 *
 *  @param arrayList 需要被初始化的DynamicArrayList的地址
 *  @param array 数组
 *  @param length 长度
 *  @return 创建成功返回true，创建失败返回false
 */
bool createDynamicArrayListWithArray(DynamicArrayList *arrayList, int *array, int length);

/**
 *  判断是不是空数组
 *
 *  @param arrayList DynamicArrayList的地址
 *  @return 空数组返回true，反之返回false
 */
bool isEmptyDynamicArrayList(DynamicArrayList *arrayList);

/**
 *  在数组的末尾添加元素
 *
 *  @param arrayList DynamicArrayList的地址
 *  @param value 添加的元素
 *  @return 添加成功返回true，反之返回false
 */
bool addValue(DynamicArrayList *arrayList, int value);

/**
 *  在数组的末尾添加数组
 *
 *  @param arrayList DynamicArrayList的地址
 *  @param array 需要添加的数组
 *  @param length 添加数组的长度
 *  @return 添加成功返回true，反之返回false
 */
bool addValues(DynamicArrayList *arrayList, int *array, int length);

/**
 *  插入单个数据
 *
 *  @param arrayList DynamicArrayList的地址
 *  @param index 插入的位置
 *  @param value 插入的值
 *  @return 插入成功返回true，反之返回false
 */
bool insertValue(DynamicArrayList *arrayList, int index, int value);

/**
 *  插入数组
 *
 *  @param arrayList DynamicArrayList的地址
 *  @param index 插入的位置
 *  @param array 需要添加的数组
 *  @param length 添加数组的长度
 *  @return 插入成功返回true，反之返回false
 */
bool insertValues(DynamicArrayList *arrayList, int index, int *array, int length);

/**
 *  删除元素
 *
 *  @param arrayList DynamicArrayList的地址
 *  @param index 删除的元素的位置
 *  @param value 删除的元素值
 *  @return 删除成功返回true，反之返回false
 */
bool deleteListValue(DynamicArrayList *arrayList, int index, int *value);

/**
 *  查询index位置的元素
 *
 *  @param arrayList DynamicArrayList的地址
 *  @param index 删除的元素的位置
 *  @param item 查询到的元素值
 *  @return 查询成功返回true，反之返回false
 */
bool indexOfListItem(DynamicArrayList *arrayList, int index, int *item);

/**
 *  清空数组
 *
 *  @param arrayList DynamicArrayList的地址
 */
void clearAllList(DynamicArrayList *arrayList);

/**
 *  打印数组
 *
 *  @param arrayList DynamicArrayList的地址
 */
void showDynamicArrayList(DynamicArrayList *arrayList);

#endif /* DynamicSequenceArrayList_h */
