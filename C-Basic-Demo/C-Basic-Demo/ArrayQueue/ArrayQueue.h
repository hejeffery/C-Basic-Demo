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

typedef struct ArrayQueue Queue;

// 队列，数组形式
struct ArrayQueue {
    int data[QueueLength];
    int head;
    int tail;
};

// 创建队列
void createQueue(Queue *queue);

// 判断队列是否为空
bool isEmptyQueue(Queue *queue);

// 判断队列是否已满
bool isFullQueue(Queue *queue);

// 入队
bool enqueue(Queue *queue, int value);

// 出队
bool dequeue(Queue *queue, int *value);

// 获取队列头的数据
int headElement(Queue *queue);

// 获取队列尾的数据
int tailElement(Queue *queue);

// 打印队列的数据
void showQueueData(Queue *queue);

#endif /* ArrayQueue_h */
