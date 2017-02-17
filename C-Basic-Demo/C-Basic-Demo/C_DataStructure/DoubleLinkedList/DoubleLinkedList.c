//
//  DoubleLinkedList.c
//  C-Basic-Demo
//
//  Created by HeJeffery on 2017/2/17.
//  Copyright © 2017年 HeJeffery. All rights reserved.
//

#include "DoubleLinkedList.h"

#include <stdlib.h>
#include <memory.h>

DoubleLinkedList *createDoubleLinkedList() {
    
    DoubleLinkedList *list = (DoubleLinkedList *)malloc(sizeof(DoubleLinkedList));
    if (list == NULL) {
        return NULL;
    }
    
    list->prior = NULL;
    list->next = NULL;
    
    return list;
}


bool appendDoubleLinkedList(DoubleLinkedList *list, int value) {
    
    if (list == NULL) {
        return false;
    }
    
    DoubleLinkedList *pnode = list;
    while (pnode->next != NULL) {
        pnode = pnode->next;
    }
    
    DoubleLinkedList *pnew = (DoubleLinkedList *)malloc(sizeof(DoubleLinkedList));
    if (pnew == NULL) {
        return false;
    }
    
    pnew->date = value;
    pnew->next = NULL;
    pnew->prior = pnode;
    
    pnode->next = pnew;
    
    return true;
}

bool insertDoubleLinkedList(DoubleLinkedList *list, int position, int value) {
    
    if (list == NULL) {
        return false;
    }
    
    int length = lengthDoubleLinkedList(list);
    if (position < 0 || position > length) {
        return false;
    }
    
    // 双指针
    int i = 0;
    DoubleLinkedList *pnode1 = list->next;
    DoubleLinkedList *pnode2 = list;
    while (pnode1 != NULL && i < position) {
        
        i++;
        pnode2 = pnode1;
        pnode1 = pnode1->next;
    }
    
    DoubleLinkedList *pnew = (DoubleLinkedList *)malloc(sizeof(DoubleLinkedList));
    if (pnew == NULL) {
        return false;
    }
    
    pnew->date = value;
    pnew->next = pnode1;
    pnew->prior = pnode2;

    pnode2->next = pnew;
    pnode1->prior = pnew;

    return true;
}

int lengthDoubleLinkedList(DoubleLinkedList *list) {
    
    if (list == NULL) {
        return 0;
    }
    
    int length = 0;
    DoubleLinkedList *pnode = list->next;
    while (pnode != NULL) {
        length++;
        pnode = pnode->next;
    }
    
    return length;
}

void showDoubleLinkedList(DoubleLinkedList *list) {

    if (list == NULL) {
        return;
    }
    
    DoubleLinkedList *pnode = list->next;
    while (pnode != NULL) {
        printf("%4d", pnode->date);
        pnode = pnode->next;
    }
    
    printf("\n");
}

