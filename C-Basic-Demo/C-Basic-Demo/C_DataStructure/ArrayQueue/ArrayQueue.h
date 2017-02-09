//
//  ArrayQueue.h
//  C-Basic-Demo
//
//  Created by HeJeffery on 2017/1/11.
//  Copyright © 2017年 HeJeffery. All rights reserved.
//

#ifndef ArrayQueue_h
#define ArrayQueue_h

#include <stdio.h>
#include <stdbool.h>

#define QueueLength 100

////////////////////////////////////////////////////////////////////////////////////
//                                                                                //
//                                 队列，静态数组形式                                 //
//                                                                                //
////////////////////////////////////////////////////////////////////////////////////

typedef struct ArrayQueue Queue;

struct ArrayQueue {
    int data[QueueLength];// 数组的长度
    int head;// 队列头的索引，初始值为0
    int tail;// 队列尾的索引
    //     队列尾 |-----------------------------------------------------| 队列头
    //       --->|  8  |  7  |  6  |  5  |  4  |  3  |  2  |  1  |     |--->
    //           |-----------------------------------------------------|
    //              |                                               |
    //              |                                               |
    //            队列尾                                          队列头
    // 思路：队尾不动，队头移动
};

/**
 *  创建队列
 *
 *  @param queue 需要被初始化的ArrayQueue的地址
 */
void createQueue(Queue *queue);

/**
 *  判断队列是否为空
 *
 *  @param queue ArrayQueue的地址
 *  @return 空队列返回true，反之返回false
 */
bool isEmptyQueue(Queue *queue);

/**
 *  判断队列是否已满
 *
 *  @param queue ArrayQueue的地址
 *  @return 空队列返回true，反之返回false
 */
bool isFullQueue(Queue *queue);

/**
 *  入队
 *
 *  @param queue ArrayQueue的地址
 *  @param value 入队的元素
 *  @return 入队成功返回true，反之返回false
 */
bool enqueue(Queue *queue, int value);

/**
 *  出队
 *
 *  @param queue ArrayQueue的地址
 *  @param value 出队元素的值
 *  @return 出队成功返回true，反之返回false
 */
bool dequeue(Queue *queue, int *value);

/**
 *  获取队列头的数据
 *
 *  @param queue ArrayQueue的地址
 *  @return 返回队列头的值
 */
int headElement(Queue *queue);

/**
 *  获取队列尾的数据
 *
 *  @param queue ArrayQueue的地址
 *  @return 返回队列尾的值
 */
int tailElement(Queue *queue);

/**
 *  打印队列的数据
 *
 *  @param queue ArrayQueue的地址
 */
void showQueueData(Queue *queue);

#endif /* ArrayQueue_h */
