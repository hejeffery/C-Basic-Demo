//
//  CircleDoubleLinkedList.c
//  C-Basic-Demo
//
//  Created by HeJeffery on 2017/2/19.
//  Copyright © 2017年 HeJeffery. All rights reserved.
//

#include "CircleDoubleLinkedList.h"

#include <stdlib.h>
#include <memory.h>

CircleDoubleLinkedList *createCircleDoubleLinkedList() {
    
    CircleDoubleLinkedList *list = (CircleDoubleLinkedList *)malloc(sizeof(CircleDoubleLinkedList));
    if (list == NULL) {
        return NULL;
    }
    
    CDLNode *phead = (CDLNode *)malloc(sizeof(CDLNode));
    if (phead == NULL) {
        return false;
    }
    
    CDLNode *ptail = (CDLNode *)malloc(sizeof(CDLNode));
    if (ptail == NULL) {
        return false;
    }
    
    phead->next = ptail;
    phead->prior = ptail;
    
    ptail->next = phead;
    ptail->prior = phead;
    
    list->phead = phead;
    list->ptail = ptail;
    
    return list;
}

bool appendCircleDoubleLinkedList(CircleDoubleLinkedList *list, int value) {
    
    if (list == NULL) {
        return false;
    }
    
    CDLNode *pnew = (CDLNode *)malloc(sizeof(CDLNode));
    if (pnew == NULL) {
        return false;
    }
    
    pnew->data = value;
    pnew->next = list->ptail;
    pnew->prior = list->ptail->prior;
    
    // 下面的顺序不能颠倒
    list->ptail->prior->next = pnew;
    list->ptail->prior = pnew;
    
    return true;
}

bool insertCircleDoubleLinkedList(CircleDoubleLinkedList *list, int position, int value) {
    
    if (list == NULL) {
        return false;
    }
    
    int length = lengthCircleDoubleLinkedList(list);
    if (position < 0 || position > length) {
        return false;
    }
    
    int i = 0;
    CDLNode *pnode = list->phead->next;
    while (pnode != NULL && pnode != list->ptail && i < position) {
        i++;
        pnode = pnode->next;
    }
    
    CDLNode *pnew = (CDLNode *)malloc(sizeof(CDLNode));
    if (pnew == NULL) {
        return false;
    }
    
    pnew->data = value;
    pnew->next = pnode;
    pnew->prior = pnode->prior;
    
    pnode->prior->next = pnew;
    pnode->prior = pnew;
    
    return true;
}

bool deleteCircleDoubleListWithPosition(CircleDoubleLinkedList *list, int position, int *value) {
    
    if (isEmptyCircleDoubleLinkedList(list)) {
        return false;
    }
    
    int length = lengthCircleDoubleLinkedList(list);
    if (position < 0 || position > length) {
        return false;
    }
    
    int i = 0;
    CDLNode *pnode = list->phead->next;
    while (pnode != NULL && pnode != list->ptail && i < position) {
        i++;
        pnode = pnode->next;
    }
    
    CDLNode *deleteNode = pnode;
    *value = deleteNode->data;
    pnode->prior->next = pnode->next;
    pnode->next->prior = pnode->prior;
    
    free(deleteNode);
    
    return true;
}

bool deleteCircleDoubleListWithItem(CircleDoubleLinkedList *list, int item, int *position) {
    
    if (isEmptyCircleDoubleLinkedList(list)) {
        return false;
    }
    
    int i = 0;
    CDLNode *pnode = list->phead->next;
    while (pnode != NULL && pnode != list->ptail) {
        
        if (pnode->data != item) {
            i++;
            pnode = pnode->next;

        } else {
            break;
        }
    }
    
    if (pnode != list->ptail) {// 找到的情况
        
        pnode->prior->next = pnode->next;
        pnode->next->prior = pnode->prior;
        *position = i;
        free(pnode);
        return true;
        
    } else {// 找不到情况
        *position = -1;
        return false;
    }
}

bool findCircleDoubleListItem(CircleDoubleLinkedList *list, int item, int *position) {
    
    if (isEmptyCircleDoubleLinkedList(list)) {
        return NULL;
    }
    
    int i = 0;
    CDLNode *pnode = list->phead->next;
    while (pnode != NULL && pnode != list->ptail) {
        
        if (pnode->data == item) {
            *position = i;
            return true;
        }
        
        i++;
        pnode = pnode->next;
    }
    
    return false;
    
}

CDLNode *findCircleDoubleListNodeWithItem(CircleDoubleLinkedList *list, int item) {
    
    if (isEmptyCircleDoubleLinkedList(list)) {
        return NULL;
    }

    CDLNode *pnode = list->phead->next;
    while (pnode != NULL && pnode != list->ptail) {
        
        if (pnode->data == item) {
            return pnode;
        }
        
        pnode = pnode->next;
    }
    
    return NULL;
}

int lengthCircleDoubleLinkedList(CircleDoubleLinkedList *list) {
    
    if (isEmptyCircleDoubleLinkedList(list)) {
        return 0;
    }
    
    int length = 0;
    CDLNode *pnode = list->phead->next;
    while (pnode != NULL && pnode != list->ptail) {
        
        length++;
        pnode = pnode->next;
    }
    
    return length;
}

bool isEmptyCircleDoubleLinkedList(CircleDoubleLinkedList *list) {
    
    if (list == NULL || (list->phead->next == list->ptail && list->ptail->prior == list->phead)) {
        return true;
    }

    return false;
}

void showCircleDoubleLinkedList(CircleDoubleLinkedList *list) {
    
    if (isEmptyCircleDoubleLinkedList(list)) {
        return;
    }
    
    CDLNode *pnode = list->phead->next;
    while (pnode != NULL && pnode != list->ptail) {
        
        printf("%4d", pnode->data);
        pnode = pnode->next;
    }
    printf("\n");
}

void showRevCircleDoubleLinkedList(CircleDoubleLinkedList *list) {
    
    if (isEmptyCircleDoubleLinkedList(list)) {
        return;
    }
    
    CDLNode *pnode = list->ptail->prior;
    while (pnode != NULL && pnode != list->phead) {

        printf("%4d", pnode->data);
        pnode = pnode->prior;
    }
    printf("\n");
}
