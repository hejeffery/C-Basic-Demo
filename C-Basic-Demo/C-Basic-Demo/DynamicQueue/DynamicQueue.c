//
//  DynamicQueue.c
//  C-Basic-Demo
//
//  Created by HeJeffery on 2017/1/19.
//  Copyright © 2017年 HeJeffery. All rights reserved.
//

#include "DynamicQueue.h"
#include <stdlib.h>
#include <memory.h>

bool createDynamicQueue(DynamicQueue *queue, int length) {
    queue->data = (int *)calloc(length, sizeof(int));
    if (queue->data == NULL) {
        return false;
    }
    
    queue->head = 0;
    queue->tail = 0;
    queue->currentSize = length;
    queue->baseLength = length;
    return true;
}

bool isEmptyDynamicQueue(DynamicQueue *queue) {
    return queue->tail == 0 ? true : false;
}

bool enqueueDynamic(DynamicQueue *queue, int value) {
    // 已经满了，再分配空间
    if (queue->tail == queue->currentSize - 1) {
        queue->data = realloc(queue->data, sizeof(int) * queue->baseLength);
        if (queue->data == NULL) {
            printf("入队失败，分配空间失败\n");
            return false;

        } else {
            queue->currentSize += queue->baseLength;
        }
    }
    
    for (int i = queue->tail; i > 0; i--) {
        queue->data[i] = queue->data[i - 1];
    }
    queue->tail++;
    queue->data[queue->head] = value;
    return true;
}

/**
 *  出队
 *
 *  @param queue DynamicQueue的地址
 *  @param value 出队元素的值
 *  @return 出队成功返回true，反之返回false
 */
bool dequeueDynamic(DynamicQueue *queue, int *value) {
    // 空队列，直接返回
    if (isEmptyDynamicQueue(queue)) {
        return false;
    }
    
    *value = queue->data[queue->tail - 1];
    queue->tail--;
    return true;
}

int headDynamicElement(DynamicQueue *queue) {
    return queue->data[queue->head];
}

int tailDynamicElement(DynamicQueue *queue) {
    return queue->data[queue->tail - 1];
}

int currentSize(DynamicQueue *queue) {
    return queue->currentSize;
}

void showDynamicQueueData(DynamicQueue *queue) {
    if (isEmptyDynamicQueue(queue)) {
        return;
    }
    
    printf("=================队列数据遍历开始==================\n");
    for (int i = 0; i < queue->tail; i++) {
        printf("%d  \n", queue->data[i]);
    }
    printf("队列当前的size = %d\n", currentSize(queue));
    printf("=================队列数据遍历结束==================\n\n");
}
