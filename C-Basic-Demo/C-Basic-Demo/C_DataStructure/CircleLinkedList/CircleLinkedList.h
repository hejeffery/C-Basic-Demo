//
//  CircleLinkedList.h
//  C-Basic-Demo
//
//  Created by HeJeffery on 2017/2/13.
//  Copyright © 2017年 HeJeffery. All rights reserved.
//

#ifndef CircleLinkedList_h
#define CircleLinkedList_h

#include <stdio.h>
#include <stdbool.h>

////////////////////////////////////////////////////////////////////////////////////
//                                                                                //
//                                    环形链式存储                                  //
//                                                                                //
////////////////////////////////////////////////////////////////////////////////////

typedef struct CNode CircleLinkedList;

struct CNode {
    int data;
    CircleLinkedList *next;
};

/**
 *  创建环形链表
 *
 *  @return 返回创建成功后的链表的头结点
 */
CircleLinkedList *createCircleLinkedList();

/**
 *  添加元素到链表(使用的是尾插法)
 *
 *  @param list CircleLinkedList的地址
 *  @param value 添加的元素
 *  @return 添加成功返回true，反之返回false
 */
bool appendCircleList(CircleLinkedList *list, int value);

/**
 *  插入元素到环形链表
 *
 *  @param list CircleLinkedList的地址
 *   @param position 插入的位置
 *  @param value 添加的元素
 *  @return 添加成功返回true，反之返回false
 */
bool insertCircleList(CircleLinkedList *list, int position, int value);

/**
 *  删除环形链表中某个位置的元素
 *
 *  @param list CircleLinkedList的地址
 *  @param position 删除的位置
 *  @param value 删除的元素的值
 *  @return 删除成功返回true，反之返回false
 */
bool deleteCircleListWithPosition(CircleLinkedList *list, int position, int *value);

/**
 *  删除环形链表中某个位置的元素
 *
 *  @param list LinkedList的地址
 *  @param item 删除的元素的值
 *  @param position 删除的位置
 *  @return 删除成功返回true，反之返回false
 */
bool deleteCircleListWithItem(CircleLinkedList *list, int item, int *position);

/**
 *  获取环形链表的长度
 *
 *  @param list CircleLinkedList的地址
 *  @return 返回环形链表的长度
 */
int circleListLength(CircleLinkedList *list);

/**
 *  找出环形链表中的某个元素
 *
 *  @param list CircleLinkedList的地址
 *  @param item 需要查找的元素
 *  @param position 找到的位置
 *  @return 找到成功返回true，反之返回false
 */
bool findCircleListItem(CircleLinkedList *list, int item, int *position);

/**
 *  根据某个元素，找出环形链表中的该元素的结点
 *
 *  @param list CircleLinkedList的地址
 *  @param item 需要查找的元素
 *  @return 找到返回该元素的结点
 */
CircleLinkedList *findCircleNodeWithItem(CircleLinkedList *list, int item);

/**
 *  判断是不是空循环链表
 *
 *  @param list CircleLinkedList的地址
 *  @return 空链表返回true，反之返回false
 */
bool isEmptyCircleLinkedList(CircleLinkedList *list);

/**
 *  判断链表是否有环
 *
 *  @param list CircleLinkedList的地址
 *  @return 有环返回true，反之返回false
 */
bool hasCircleLinkedList(CircleLinkedList *list);

/**
 *  打印环形链表
 *
 *  @param list CircleLinkedList的地址
 */
void showCircleList(CircleLinkedList *list);


#endif /* CircleLinkedList_h */
