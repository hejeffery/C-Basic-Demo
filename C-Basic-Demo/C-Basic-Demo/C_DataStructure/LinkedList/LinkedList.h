//
//  LinkedList.h
//  C-Basic-Demo
//
//  Created by HeJeffery on 2017/2/8.
//  Copyright © 2017年 HeJeffery. All rights reserved.
//

#ifndef LinkedList_h
#define LinkedList_h

#include <stdio.h>
#include <stdbool.h>

////////////////////////////////////////////////////////////////////////////////////
//                                                                                //
//                                      链式存储                                   //
//                                                                                //
////////////////////////////////////////////////////////////////////////////////////

typedef struct Node LinkedList;

struct Node {
    int data;
    LinkedList *next;
};

/**
 *  创建链表
 *
 *  @return 返回创建成功后的链表的头结点
 */
LinkedList *createLinkedList();

/**
 *  添加元素到链表(使用的是尾插法)
 *
 *  @param list LinkedList的地址
 *  @param value 添加的元素
 *  @return 添加成功返回true，反之返回false
 */
bool appendList(LinkedList *list, int value);

/**
 *  插入元素到链表
 *
 *  @param list LinkedList的地址
*   @param position 插入的位置
 *  @param value 添加的元素
 *  @return 添加成功返回true，反之返回false
 */
bool insertList(LinkedList *list, int position, int value);

/**
 *  删除链表中某个位置的元素
 *
 *  @param list LinkedList的地址
 *  @param position 删除的位置
 *  @param value 删除的元素的值
 *  @return 删除成功返回true，反之返回false
 */
bool deleteListWithPosition(LinkedList *list, int position, int *value);

/**
 *  删除链表中某个位置的元素(双指针来实现)
 *
 *  @param list LinkedList的地址
 *  @param item 删除的元素的值
 *  @param position 删除的位置
 *  @return 删除成功返回true，反之返回false
 */
bool deleteListWithItem(LinkedList *list, int item, int *position);

/**
 *  找出链表中的某个元素
 *
 *  @param list LinkedList的地址
 *  @param item 需要查找的元素
 *  @param position 找到的位置
 *  @return 找到成功返回true，反之返回false
 */
bool findListItem(LinkedList *list, int item, int *position);

/**
 *  根据某个元素，找出链表中的该元素的结点
 *
 *  @param list LinkedList的地址
 *  @param item 需要查找的元素
 *  @return 找到返回该元素的结点
 */
LinkedList *findNodeWithItem(LinkedList *list, int item);

/**
 *  找出链表中间位置的结点
 *
 *  @param list LinkedList的地址
 *  @return 返回链表中间位置的结点
 */
LinkedList *findCenterNode(LinkedList *list);

/**
 *  判断是不是空链表
 *
 *  @param list LinkedList的地址
 *  @return 空链表返回true，反之返回false
 */
bool isEmptyLinkedList(LinkedList *list);

/**
 *  返回链表的长度
 *
 *  @param list list的地址
 *  @return 返回链表的长度
 */
int length(LinkedList *list);

/**
 *  反转链表
 *
 *  @param list list的地址
 */
void reverseList(LinkedList *list);

/**
 *  顺序的合并两个链表。
 *  比如链表1: 1, 3, 5, 7, 9
 *
 *  比如链表2: 2, 4, 6, 8, 10
 *  
 *  链表1和链表2合并为，1，2，3，4，5，6，7，8，9，10
 *
 *  @param list1 链表1
 *  @param list2 链表2
 *
 */
LinkedList *mergeList(LinkedList *list1, LinkedList *list2);

/**
 *  判断链表是否有环
 *
 *  @param list LinkedList的地址
 *  @return 有环返回true，反之返回false
 */
bool hasCircleList(LinkedList *list);

/**
 *  清空链表
 *
 *  @param list LinkedList的地址
 *  @return 清空成功返回true，反之返回false
 */
bool clearList(LinkedList *list);

/**
 *  打印链表
 *
 *  @param list LinkedList的地址
 */
void showLinkedList(LinkedList *list);

/**
 *  反向打印链表中的值(递归实现)
 *
 *  @param list LinkedList的地址
 */
void reversePrintList(LinkedList *list);

#endif /* LinkedList_h */
