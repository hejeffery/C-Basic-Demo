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

typedef struct DLNode DoubleLinkedList;

struct DLNode {
    int date;
    DoubleLinkedList *prior;
    DoubleLinkedList *next;
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
 *  返回链表的长度
 *
 *  @param list DoubleLinkedList的地址
 *  @return 返回链表的长度
 */
int lengthDoubleLinkedList(DoubleLinkedList *list);

/**
 *  打印双链表的数据
 *
 *  @param list DoubleLinkedList的地址
 */
void showDoubleLinkedList(DoubleLinkedList *list);

#endif /* DoubleLinkedList_h */
