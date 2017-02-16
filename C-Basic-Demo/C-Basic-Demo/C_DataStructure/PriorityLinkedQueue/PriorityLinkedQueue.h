//
//  PriorityLinkedQueue.h
//  C-Basic-Demo
//
//  Created by HeJeffery on 2017/2/16.
//  Copyright © 2017年 HeJeffery. All rights reserved.
//

#ifndef PriorityLinkedQueue_h
#define PriorityLinkedQueue_h

#include <stdio.h>
#include <stdbool.h>

////////////////////////////////////////////////////////////////////////////////////
//                                                                                //
//                                       优先队列                                  //
//                                                                                //
////////////////////////////////////////////////////////////////////////////////////

// 优先级
typedef enum Priority {
    PriorityLow = -1,// low
    PriorityDefault,// default
    PriorityHigh// high
} Priority;

typedef struct PLQNode PriorityLinkedQueue;

struct PLQNode {
    int data;
    PriorityLinkedQueue *next;
    Priority priority;
};

/**
 *  创建链式队列
 *
 *  @return 返回创建成功后的头结点
 */
PriorityLinkedQueue *createPriorityLinkedQueue();

/**
 *  判断队列是否为空
 *
 *  @param queue PriorityLinkedQueue的地址
 *  @return 空队列返回true，反之返回false
 */
bool isEmptyPriorityLinkedQueue(PriorityLinkedQueue *queue);

/**
 *  入队(尾插法)
 *
 *  @param queue PriorityLinkedQueue的地址
 *  @param value 入队的元素
 *  @param priority 优先级
 *  @return 入队成功返回true，反之返回false
 */
bool enqueuePriorityLinked(PriorityLinkedQueue *queue, int value, Priority priority);

/**
 *  出队
 *
 *  @param queue PriorityLinkedQueue的地址
 *  @param dequeueNode 出队的结点
 *  @return 出队成功返回true，反之返回false
 */
bool dequeuePriorityLinked(PriorityLinkedQueue *queue, PriorityLinkedQueue *dequeueNode);

/**
 *  获取队列的长度
 *
 *  @param queue PriorityLinkedQueue的地址
 *  @return 返回队列的长度
 */
int lengthPriorityLinkedQueue(PriorityLinkedQueue *queue);

/**
 *  获取队列头的数据
 *
 *  @param queue PriorityLinkedQueue的地址
 *  @return 返回队列头的值
 */
int headPriorityLinkedQueueElement(PriorityLinkedQueue *queue);

/**
 *  获取队列尾的数据
 *
 *  @param queue PriorityLinkedQueue的地址
 *  @return 返回队列尾的值
 */
int tailPriorityLinkedQueueElement(PriorityLinkedQueue *queue);

/**
 *  打印队列的数据
 *
 *  @param queue PriorityLinkedQueue的地址
 */
void showPriorityLinkedQueueData(PriorityLinkedQueue *queue);

#endif /* PriorityLinkedQueue_h */
