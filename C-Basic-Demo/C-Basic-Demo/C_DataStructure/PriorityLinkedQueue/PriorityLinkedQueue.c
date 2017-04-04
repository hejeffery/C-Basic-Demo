//
//  PriorityLinkedQueue.c
//  C-Basic-Demo
//
//  Created by HeJeffery on 2017/2/16.
//  Copyright © 2017年 HeJeffery. All rights reserved.
//

#include "PriorityLinkedQueue.h"

#include <stdlib.h>
#include <memory.h>

PriorityLinkedQueue *createPriorityLinkedQueue() {
    
    PriorityLinkedQueue *queue = (PriorityLinkedQueue *)malloc(sizeof(PriorityLinkedQueue));
    if (queue == NULL) {
        return NULL;
    }
    
    queue->next = NULL;
    queue->priority = PriorityDefault;
    
    return queue;
}

bool isEmptyPriorityLinkedQueue(PriorityLinkedQueue *queue) {
    
    return queue->next == NULL ? true : false;
}

bool enqueuePriorityLinked(PriorityLinkedQueue *queue, int value, Priority priority) {
    
    // 思路：根据优先级插入队列。插入的思路类似插入排序的思路
    if (queue == NULL) {
        return false;
    }
    
    PriorityLinkedQueue *pnew = (PriorityLinkedQueue *)malloc(sizeof(PriorityLinkedQueue));
    if (pnew == NULL) {
        return false;
    }

    pnew->data = value;
    pnew->priority = priority;
    
    if (queue->next == NULL) {// 插入的是第一个结点
        pnew->next = NULL;
        queue->next = pnew;

        return true;

    } else {// 插入的不是第一个结点。在中间插入和最后插入，都是根据优先级来进行插入位置的判断
        
        // 双指针处理
        PriorityLinkedQueue *pnode1 = queue->next;
        PriorityLinkedQueue *pnode2 = queue;
        while (pnode1 != NULL) {
            // 在中间插入
            // 插入的结点的优先级比当前的结点的优先级高，插入
            if (pnode1->priority < pnew->priority) {
                // 新结点插入pnode2 和 pnode1的中间
                pnode2->next = pnew;
                pnew->next = pnode1;
                
                return true;
                
            }
            pnode2 = pnode1;
            pnode1 = pnode1->next;
        }
        
        if (pnode2->next == NULL) {// 在最后插入
            pnode2->next = pnew;
            pnew->next = NULL;
            return true;
        }
    }

    return false;
}

bool dequeuePriorityLinked(PriorityLinkedQueue *queue, PriorityLinkedQueue *dequeueNode) {
    
    if (isEmptyPriorityLinkedQueue(queue)) {
        return false;
    }
    
    PriorityLinkedQueue *pnode = queue->next;
    if (pnode != NULL) {
        queue->next = pnode->next;
    }

    (*dequeueNode).data = pnode->data;
    (*dequeueNode).priority = pnode->priority;
    free(pnode);
    
    return true;
}

int lengthPriorityLinkedQueue(PriorityLinkedQueue *queue) {
    
    if (isEmptyPriorityLinkedQueue(queue)) {
        return 0;
    }
    
    int length = 0;
    PriorityLinkedQueue *pnode = queue;
    while (pnode->next != NULL) {
        length++;
        pnode = pnode->next;
    }
    
    return length;
}

int headPriorityLinkedQueueElement(PriorityLinkedQueue *queue) {
    
    if (queue == NULL) {
        return 0;
    }
    
    PriorityLinkedQueue *pnode = queue;
    while (pnode->next->next != NULL) {
        pnode = pnode->next;
    }
    
    return pnode->data;
}

int tailPriorityLinkedQueueElement(PriorityLinkedQueue *queue) {
    
    if (queue == NULL) {
        return 0;
    }
    
    return queue->data;
}

void showPriorityLinkedQueueData(PriorityLinkedQueue *queue) {
    
    if (queue == NULL) {
        return;
    }
    
    printf("=================队列数据遍历开始==================\n");
    PriorityLinkedQueue *pnode = queue->next;
    while (pnode != NULL) {
        printf("%4d     priority = %d\n", pnode->data, pnode->priority);
        pnode = pnode->next;
    }
    printf("=================队列数据遍历结束==================\n");
    printf("\n");
    
}
