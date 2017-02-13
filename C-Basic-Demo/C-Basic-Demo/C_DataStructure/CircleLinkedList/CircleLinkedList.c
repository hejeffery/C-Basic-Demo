//
//  CircleLinkedList.c
//  C-Basic-Demo
//
//  Created by HeJeffery on 2017/2/13.
//  Copyright © 2017年 HeJeffery. All rights reserved.
//

#include "CircleLinkedList.h"

#include <stdlib.h>
#include <memory.h>

CircleLinkedList *createCircleLinkedList() {
    
    CircleLinkedList *phead = (CircleLinkedList *)malloc(sizeof(CircleLinkedList));
    
    if (phead == NULL) {
        return NULL;
    }
    
    phead->next = phead;
    return phead;
}

bool appendCircleList(CircleLinkedList *list, int value) {
    
    if (list == NULL) {
        return false;
    }
    
    // 找到“最后一个结点”
    CircleLinkedList *pnode = list;
    while (pnode->next != NULL && pnode->next != list) {
        pnode = pnode->next;
    }
    
    CircleLinkedList *pnew = (CircleLinkedList *)malloc(sizeof(CircleLinkedList));
    if (pnew == NULL) {
        return false;
    }
    
    pnew->next = list;
    pnew->data = value;

    pnode->next = pnew;
    
    return true;
}

int circleListLength(CircleLinkedList *list) {
    
    if (list == NULL || list->next == NULL) {
        return 0;
    }
    
    int length = 0;
    CircleLinkedList *pnode = list->next;
    while (pnode != list) {
        length++;
        pnode = pnode->next;
    }

    return length;
}

bool hasCircleLinkedList(CircleLinkedList *list) {
    
    if (list == NULL || list->next == NULL) {
        return false;
    }
    
    // 前进一个
    CircleLinkedList *pnode1 = list->next;
    
    // 前进两个
    CircleLinkedList *pnode2 = list->next;
    
    while (pnode1 != NULL && pnode2 != NULL) {

        pnode1 = pnode1->next;
        pnode2 = pnode2->next;
        if (pnode2->next != NULL) {
            pnode2 = pnode2->next;
        }
        
        // 如果相等，就说明有环
        if (pnode1 == pnode2) {
            return true;
        }
    }
    
    return false;
}

void showCircleList(CircleLinkedList *list) {
    
    if (list == NULL) {
        return;
    }
    
    CircleLinkedList *pnode = list->next;
    while (pnode != list) {
        printf("%4d", pnode->data);
        pnode = pnode->next;
    }
    printf("\n");
}



