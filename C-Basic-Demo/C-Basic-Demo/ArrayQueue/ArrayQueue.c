//
//  ArrayQueue.c
//  C-Basic-Demo
//
//  Created by HeJeffery on 2017/1/11.
//  Copyright © 2017年 HeJeffery. All rights reserved.
//

#include "ArrayQueue.h"
#include <memory.h>

// 创建队列
void createQueue(Queue *queue) {
    queue->head = 0;
    queue->tail = 0;
    memset(queue->data, 0, sizeof(int) * QueueLength);
    
}

// 判断队列是否为空
bool isEmptyQueue(Queue *queue) {
    // 如果队尾的值为0，说明该队列是空队列
    return queue->tail == 0 ? true : false;
}

// 判断队列是否已满
bool isFullQueue(Queue *queue) {
    // 如果队尾的值是QueueLength - 1，说明该队列已满
    return queue->tail == QueueLength - 1 ? true : false;
}

// 入队
bool enqueue(Queue *queue, int value) {
    // 如果是空队列
    if (isEmptyQueue(queue)) {
        queue->data[queue->head] = value;
        queue->tail++;
        return true;

    } else {
        // 如果队列已经满了，不能入队
        if (isFullQueue(queue)) {
            return false;

        } else {// 队列没满
            // 所有的数据往后移动一位
            for (int i = queue->tail; i > 0; i--) {
                queue->data[i] = queue->data[i - 1];
            }
            // 队尾的index自增
            queue->tail++;
            // 队头赋值为新值
            queue->data[queue->head] = value;
            return true;
        }
    }
    return false;
}

// 出队
bool dequeue(Queue *queue, int *value) {
    // 如果队列为空队列，出队失败
    if (isEmptyQueue(queue)) {
        return false;
    }
    
    // 赋值出队的数据
    *value = queue->data[queue->tail - 1];
    // 队尾自减
    queue->tail--;
    return true;
}

// 获取队列头的数据
int headElement(Queue *queue) {
    if (isEmptyQueue(queue)) {
        return -1;
    }
    return queue->data[queue->head];
}

// 获取队列尾的数据
int tailElement(Queue *queue) {
    if (isEmptyQueue(queue)) {
        return -1;
    }
    return queue->data[queue->tail - 1];
}

// 打印队列的数据
void showQueueData(Queue *queue) {
    if (isEmptyQueue(queue)) {
        return;
    }
    
    printf("=================队列数据遍历开始==================\n");
    for (int i = 0; i < queue->tail; i++) {
        printf("%d  \n", queue->data[i]);
    }
    printf("=================队列数据遍历结束==================\n");
    
}
