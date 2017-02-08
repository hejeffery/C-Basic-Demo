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

typedef struct Node Node;

struct Node {
    int data;
    Node *next;
};

/**
 *  创建链表
 *
 *  @return 返回创建成功后的链表的头结点
 */
Node *createLinkedList();

/**
 *  添加元素到链表(使用的是尾插法)
 *
 *  @param node LinkedList的地址
 *  @param value 添加的元素
 *  @return 添加成功返回true，反之返回false
 */
bool appendList(Node *node, int value);

/**
 *  判断是不是空链表
 *
 *  @param node LinkedList的地址
 *  @return 空链表返回true，反之返回false
 */
bool isEmptyLinkedList(Node *node);

/**
 *  返回链表的长度
 *
 *  @param node LinkedList的地址
 *  @return 返回链表的长度
 */
int length(Node *node);

/**
 *  打印链表
 *
 *  @param node LinkedList的地址
 */
void showLinkedList(Node *node);

#endif /* LinkedList_h */
