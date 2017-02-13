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
 *  获取环形链表的长度
 *
 *  @param list CircleLinkedList的地址
 *  @return 返回环形链表的长度
 */
int circleListLength(CircleLinkedList *list);

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
