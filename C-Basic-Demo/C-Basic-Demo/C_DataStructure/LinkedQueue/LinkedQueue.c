//
//  LinkedQueue.c
//  C-Basic-Demo
//
//  Created by HeJeffery on 2017/2/16.
//  Copyright © 2017年 HeJeffery. All rights reserved.
//

#include "LinkedQueue.h"

#include <stdlib.h>
#include <memory.h>

LinkedQueue *createLinkedQueue() {
    
    LinkedQueue *queue = (LinkedQueue *)malloc(sizeof(LinkedQueue));
    if (queue == NULL) {
        return NULL;
    }
    
    queue->next = NULL;
    
    return queue;
}

bool isEmptyLinkedQueue(LinkedQueue *queue) {
    
    return queue->next == NULL ? true : false;
}

bool enqueueLinked(LinkedQueue **queue, int value) {
    
    if (*queue == NULL) {
        return false;
    }
    
    LinkedQueue *pnew = (LinkedQueue *)malloc(sizeof(LinkedQueue));
    if (pnew == NULL) {
        return false;
    }
    
    pnew->data = value;
    pnew->next = *queue;
    
    *queue = pnew;
    
    return true;
}


bool dequeueLinked(LinkedQueue *queue, int *value) {
    
    if (isEmptyLinkedQueue(queue)) {
        return false;
    }
    
    // 双指针
    LinkedQueue *pnode1 = queue;
    LinkedQueue *pnode2 = queue;
    while (pnode1->next != NULL) {
        
        pnode2 = pnode1;
        pnode1 = pnode1->next;
    }
    
    *value = pnode2->data;
    pnode2->next = pnode1->next;
    free(pnode1);
    
    return true;
}

int lengthLinkedQueue(LinkedQueue *queue) {
    
    if (isEmptyLinkedQueue(queue)) {
        return 0;
    }
    
    int length = 0;
    LinkedQueue *pnode = queue;
    while (pnode->next != NULL) {
        length++;
        pnode = pnode->next;
    }
    
    return length;
}

int headLinkedQueueElement(LinkedQueue *queue) {
    
    if (queue == NULL) {
        return 0;
    }
    
    LinkedQueue *pnode = queue;
    while (pnode->next->next != NULL) {
        pnode = pnode->next;
    }

    return pnode->data;
}

int tailLinkedQueueElement(LinkedQueue *queue) {
    
    if (queue == NULL) {
        return 0;
    }
    
    return queue->data;
}

void showLinkedQueueData(LinkedQueue *queue) {
    
    if (queue == NULL || queue->next == NULL) {
        return;
    }
    
    printf("=================队列数据遍历开始==================\n");
    LinkedQueue *pnode = queue;
    while (pnode->next != NULL) {
        printf("%4d", pnode->data);
        pnode = pnode->next;
    }
    printf("\n=================队列数据遍历结束==================\n");
    printf("\n");
}

