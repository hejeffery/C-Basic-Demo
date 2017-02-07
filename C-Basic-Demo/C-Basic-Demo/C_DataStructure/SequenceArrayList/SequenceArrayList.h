//
//  SequenceArrayList.h
//  C-Basic-Demo
//
//  Created by HeJeffery on 2017/1/19.
//  Copyright © 2017年 HeJeffery. All rights reserved.
//

#ifndef SequenceArrayList_h
#define SequenceArrayList_h

#include <stdio.h>
#include <stdbool.h>

typedef struct SequenceArrayList ArrayList;

////////////////////////////////////////////////////////////////////////////////////
//                                                                                //
//                                    数组的顺序存储                                 //
//                                                                                //
////////////////////////////////////////////////////////////////////////////////////

struct SequenceArrayList {
    int *list;// 数组
    int length;// 顺序表的总长度
    int currentIndex;// 当前顺序表的索引
};

/**
 *  创建数组
 *
 *  @param arrayList 需要被初始化的ArrayList的地址
 *  @param length 长度
 *  @return 创建成功返回true，创建失败返回false
 */
bool createArrayList(ArrayList *arrayList, int length);

/**
 *  创建数组
 *
 *  @param arrayList 需要被初始化的ArrayList的地址
 *  @param data 初始化的数据
 *  @param length 长度
 *  @return 创建成功返回true，创建失败返回false
 */
bool createArrayListWithData(ArrayList *arrayList, int data, int length);

/**
 *  创建数组
 *
 *  @param arrayList 需要被初始化的ArrayList的地址
 *  @param array 数组
 *  @param length 长度
 *  @return 创建成功返回true，创建失败返回false
 */
bool createArrayListWithArray(ArrayList *arrayList, int *array, int length);

/**
 *  判断是不是满数组
 *
 *  @param arrayList ArrayList的地址
 *  @return 满数组返回true，反之返回false
 */
bool isFullArrayList(ArrayList *arrayList);

/**
 *  判断是不是空数组
 *
 *  @param arrayList ArrayList的地址
 *  @return 空数组返回true，反之返回false
 */
bool isEmptyArrayList(ArrayList *arrayList);

/**
 *  在数组的末尾添加元素
 *
 *  @param arrayList ArrayList的地址
 *  @param value 添加的元素
 *  @return 添加成功返回true，反之返回false
 */
bool append(ArrayList *arrayList, int value);

/**
 *  插入元素
 *
 *  @param arrayList ArrayList的地址
 *  @param index 插入的位置
 *  @param value 添加的元素
 *  @return 插入成功返回true，反之返回false
 */
bool insert(ArrayList *arrayList, int index, int value);

/**
 *  删除元素
 *
 *  @param arrayList ArrayList的地址
 *  @param index 删除的元素的位置
 *  @param value 删除的元素值
 *  @return 删除成功返回true，反之返回false
 */
bool deleteValue(ArrayList *arrayList, int index, int *value);

/**
 *  查询index位置的元素
 *
 *  @param arrayList ArrayList的地址
 *  @param index 删除的元素的位置
 *  @param item 查询到的元素值
 *  @return 查询成功返回true，反之返回false
 */
bool indexOfItem(ArrayList *arrayList, int index, int *item);

/**
 *  清空数组
 *
 *  @param arrayList ArrayList的地址
 */
void clearAll(ArrayList *arrayList);

/**
 *  打印数组
 *
 *  @param arrayList ArrayList的地址
 */
void showArrayList(ArrayList *arrayList);

#endif /* SequenceArrayList_h */
