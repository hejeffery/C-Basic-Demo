//
//  LinkedQueue.h
//  C-Basic-Demo
//
//  Created by HeJeffery on 2017/2/16.
//  Copyright © 2017年 HeJeffery. All rights reserved.
//

#ifndef LinkedQueue_h
#define LinkedQueue_h

#include <stdio.h>
#include <stdbool.h>

////////////////////////////////////////////////////////////////////////////////////
//                                                                                //
//                                       链式队列                                  //
//                                                                                //
////////////////////////////////////////////////////////////////////////////////////

typedef struct LQNode LinkedQueue;

struct LQNode {
    int data;
    LinkedQueue *next;
};

/**
 *  创建链式队列
 *
 *  @return 返回创建成功后的头结点
 */
LinkedQueue *createLinkedQueue();

/**
 *  判断队列是否为空
 *
 *  @param queue LinkedQueue的地址
 *  @return 空队列返回true，反之返回false
 */
bool isEmptyLinkedQueue(LinkedQueue *queue);

/**
 *  入队(头插法)
 *
 *  @param queue LinkedQueue地址的地址
 *  @param value 入队的元素
 *  @return 入队成功返回true，反之返回false
 */
bool enqueueLinked(LinkedQueue **queue, int value);

/**
 *  出队
 *
 *  @param queue LinkedQueue的地址
 *  @param value 出队元素的值
 *  @return 出队成功返回true，反之返回false
 */
bool dequeueLinked(LinkedQueue *queue, int *value);

/**
 *  获取队列的长度
 *
 *  @param queue LinkedQueue的地址
 *  @return 返回队列的长度
 */
int lengthLinkedQueue(LinkedQueue *queue);

/**
 *  获取队列头的数据
 *
 *  @param queue LinkedQueue的地址
 *  @return 返回队列头的值
 */
int headLinkedQueueElement(LinkedQueue *queue);

/**
 *  获取队列尾的数据
 *
 *  @param queue LinkedQueue的地址
 *  @return 返回队列尾的值
 */
int tailLinkedQueueElement(LinkedQueue *queue);

/**
 *  打印队列的数据
 *
 *  @param queue ArrayQueue的地址
 */
void showLinkedQueueData(LinkedQueue *queue);

#endif /* LinkedQueue_h */
