//
//  DoubleLinkedList.h
//  C-Basic-Demo
//
//  Created by HeJeffery on 2017/2/17.
//  Copyright © 2017年 HeJeffery. All rights reserved.
//

#ifndef DoubleLinkedList_h
#define DoubleLinkedList_h

#include <stdio.h>
#include <stdbool.h>

////////////////////////////////////////////////////////////////////////////////////
//                                                                                //
//                                        双链表                                   //
//                                                                                //
////////////////////////////////////////////////////////////////////////////////////

typedef struct DoubleLinkedList DoubleLinkedList;
typedef struct DLNode DLNode;

struct DLNode {
    int data;
    struct DLNode *prior;// 前驱结点
    struct DLNode *next;// 后继结点
};

struct DoubleLinkedList {
    struct DLNode *phead;// 头结点
    struct DLNode *ptail;// 尾结点
};

/**
 *  创建双链表
 *
 *  @return 返回创建成功后的头结点
 */
DoubleLinkedList *createDoubleLinkedList();

/**
 *  添加元素到双链表(使用的是尾插法)
 *
 *  @param list DoubleLinkedList的地址
 *  @param value 添加的元素
 *  @return 添加成功返回true，反之返回false
 */
bool appendDoubleLinkedList(DoubleLinkedList *list, int value);

/**
 *  插入元素到双链表
 *
 *  @param list DoubleLinkedList的地址
 *   @param position 插入的位置
 *  @param value 添加的元素
 *  @return 添加成功返回true，反之返回false
 */
bool insertDoubleLinkedList(DoubleLinkedList *list, int position, int value);

/**
 *  删除双链表中某个位置的元素
 *
 *  @param list DoubleLinkedList的地址
 *  @param position 删除的位置
 *  @param value 删除的元素的值
 *  @return 删除成功返回true，反之返回false
 */
bool deleteDoubleListWithPosition(DoubleLinkedList *list, int position, int *value);

/**
 *  删除双链表中某个位置的元素
 *
 *  @param list DoubleLinkedList的地址
 *  @param item 删除的元素的值
 *  @param position 删除的位置
 *  @return 删除成功返回true，反之返回false
 */
bool deleteDoubleListWithItem(DoubleLinkedList *list, int item, int *position);

/**
 *  找出双链表中的某个元素
 *
 *  @param list DoubleLinkedList的地址
 *  @param item 需要查找的元素
 *  @param position 找到的位置
 *  @return 找到成功返回true，反之返回false
 */
bool findDoubleListItem(DoubleLinkedList *list, int item, int *position);

/**
 *  根据某个元素，找出双链表中的该元素的结点
 *
 *  @param list DoubleLinkedList的地址
 *  @param item 需要查找的元素
 *  @return 找到返回该元素的结点
 */
DLNode *findDoubleListNodeWithItem(DoubleLinkedList *list, int item);

/**
 *  返回链表的长度
 *
 *  @param list DoubleLinkedList的地址
 *  @return 返回链表的长度
 */
int lengthDoubleLinkedList(DoubleLinkedList *list);

/**
 *  判断是否是空的双链表
 *
 *  @param list DoubleLinkedList的地址
 *  @return 空双链表返回true，反之返回false
 */
bool isEmptyDoubleLinkedList(DoubleLinkedList *list);

/**
 *  顺序打印双链表的数据
 *
 *  @param list DoubleLinkedList的地址
 */
void showDoubleLinkedList(DoubleLinkedList *list);

/**
 *  逆序打印双链表的数据
 *
 *  @param list DoubleLinkedList的地址
 */
void showRevDoubleLinkedList(DoubleLinkedList *list);

#endif /* DoubleLinkedList_h */
