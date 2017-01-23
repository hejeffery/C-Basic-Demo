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
    return queue->head == 0 ? true : false;
}

bool enqueueDynamic(DynamicQueue **queue, int value) {
    // 已经满了，再分配空间
    if ((*queue)->head == (*queue)->currentSize - 1) {
        // realloc如果空间不足，会重新分配一块内存，这时原来的内存会被释放。所以传递**queue
        (*queue)->data = realloc((*queue)->data, sizeof(int) * (*queue)->baseLength);
        if ((*queue)->data == NULL) {
            printf("入队失败，分配空间失败\n");
            return false;

        } else {
            (*queue)->currentSize += (*queue)->baseLength;
        }
    }
    
    for (int i = (*queue)->head; i > 0; i--) {
        (*queue)->data[i] = (*queue)->data[i - 1];
    }
    (*queue)->head++;
    (*queue)->data[(*queue)->tail] = value;
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
    
    *value = queue->data[queue->head - 1];
    queue->head--;
    return true;
}

int headDynamicElement(DynamicQueue *queue) {
    return queue->data[queue->head - 1];
}

int tailDynamicElement(DynamicQueue *queue) {
    return queue->data[queue->tail];
}

int currentQueueSize(DynamicQueue *queue) {
    return queue->currentSize;
}

void showDynamicQueueData(DynamicQueue *queue) {
    if (isEmptyDynamicQueue(queue)) {
        return;
    }
    
    printf("=================队列数据遍历开始==================\n");
    for (int i = 0; i < queue->head; i++) {
        printf("%d  \n", queue->data[i]);
    }
    printf("队列当前的size = %d\n", currentQueueSize(queue));
    printf("=================队列数据遍历结束==================\n\n");
}
