//
//  CircleDoubleLinkedList.h
//  C-Basic-Demo
//
//  Created by HeJeffery on 2017/2/19.
//  Copyright © 2017年 HeJeffery. All rights reserved.
//

#ifndef CircleDoubleLinkedList_h
#define CircleDoubleLinkedList_h

#include <stdio.h>
#include <stdbool.h>

////////////////////////////////////////////////////////////////////////////////////
//                                                                                //
//                                     环形双链表                                   //
//                                                                                //
////////////////////////////////////////////////////////////////////////////////////

typedef struct CircleDoubleLinkedList CircleDoubleLinkedList;
typedef struct CDLNode CDLNode;

struct CDLNode {
    int data;
    struct CDLNode *prior;// 前驱结点
    struct CDLNode *next;// 后继结点
};

struct CircleDoubleLinkedList {
    struct CDLNode *phead;// 头结点
    struct CDLNode *ptail;// 尾结点
};

/**
 *  创建环形双链表
 *
 *  @return 返回创建成功后的头结点
 */
CircleDoubleLinkedList *createCircleDoubleLinkedList();


/**
 *  添加元素到双链表(使用的是尾插法)
 *
 *  @param list CircleDoubleLinkedList的地址
 *  @param value 添加的元素
 *  @return 添加成功返回true，反之返回false
 */
bool appendCircleDoubleLinkedList(CircleDoubleLinkedList *list, int value);

/**
 *  插入元素到双链表
 *
 *  @param list CircleDoubleLinkedList的地址
 *   @param position 插入的位置
 *  @param value 添加的元素
 *  @return 添加成功返回true，反之返回false
 */
bool insertCircleDoubleLinkedList(CircleDoubleLinkedList *list, int position, int value);

/**
 *  删除双链表中某个位置的元素
 *
 *  @param list CircleDoubleLinkedList的地址
 *  @param position 删除的位置
 *  @param value 删除的元素的值
 *  @return 删除成功返回true，反之返回false
 */
bool deleteCircleDoubleListWithPosition(CircleDoubleLinkedList *list, int position, int *value);

/**
 *  删除双链表中某个位置的元素(双指针来实现)
 *
 *  @param list CircleDoubleLinkedList的地址
 *  @param item 删除的元素的值
 *  @param position 删除的位置
 *  @return 删除成功返回true，反之返回false
 */
bool deleteCircleDoubleListWithItem(CircleDoubleLinkedList *list, int item, int *position);

/**
 *  找出双链表中的某个元素
 *
 *  @param list CircleDoubleLinkedList的地址
 *  @param item 需要查找的元素
 *  @param position 找到的位置
 *  @return 找到成功返回true，反之返回false
 */
bool findCircleDoubleListItem(CircleDoubleLinkedList *list, int item, int *position);

/**
 *  根据某个元素，找出双链表中的该元素的结点
 *
 *  @param list CircleDoubleLinkedList的地址
 *  @param item 需要查找的元素
 *  @return 找到返回该元素的结点
 */
CDLNode *findCircleDoubleListNodeWithItem(CircleDoubleLinkedList *list, int item);

/**
 *  返回链表的长度
 *
 *  @param list CircleDoubleLinkedList的地址
 *  @return 返回链表的长度
 */
int lengthCircleDoubleLinkedList(CircleDoubleLinkedList *list);

/**
 *  判断是否是空的双链表
 *
 *  @param list CircleDoubleLinkedList的地址
 *  @return 空双链表返回true，反之返回false
 */
bool isEmptyCircleDoubleLinkedList(CircleDoubleLinkedList *list);

/**
 *  顺序打印双链表的数据
 *
 *  @param list CircleDoubleLinkedList的地址
 */
void showCircleDoubleLinkedList(CircleDoubleLinkedList *list);

/**
 *  逆序打印双链表的数据
 *
 *  @param list CircleDoubleLinkedList的地址
 */
void showRevCircleDoubleLinkedList(CircleDoubleLinkedList *list);

#endif /* CircleDoubleLinkedList_h */
