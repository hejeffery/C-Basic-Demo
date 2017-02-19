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
    
    DLNode *phead = (DLNode *)malloc(sizeof(DLNode));
    if (phead == NULL) {
        return NULL;
    }
    
    DLNode *ptail = (DLNode *)malloc(sizeof(DLNode));
    if (ptail == NULL) {
        return NULL;
    }
    
    phead->next = ptail;
    phead->prior = NULL;

    ptail->prior = phead;
    ptail->next = NULL;
    
    list->phead = phead;
    list->ptail = ptail;
    
    return list;
}


bool appendDoubleLinkedList(DoubleLinkedList *list, int value) {
    
    if (list == NULL) {
        return false;
    }
    
    DLNode *pnew = (DLNode *)malloc(sizeof(DLNode));
    if (pnew == NULL) {
        return false;
    }
    
    DLNode *plast = list->ptail->prior;
    
    pnew->data = value;
    pnew->next = list->ptail;
    pnew->prior = plast;
    
    list->ptail->prior->next = pnew;
    list->ptail->prior = pnew;
    
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

    int i = 0;
    DLNode *pnode = list->phead->next;
    while (pnode != NULL && pnode != list->ptail && i < position) {
        i++;
        pnode = pnode->next;
    }
    
    DLNode *pnew = (DLNode *)malloc(sizeof(DLNode));
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

bool deleteDoubleListWithPosition(DoubleLinkedList *list, int position, int *value) {
    
    if (list == NULL) {
        return false;
    }
    
    int length = lengthDoubleLinkedList(list);
    if (position < 0 || position > length) {
        return false;
    }

    int i = 0;
    DLNode *pnode = list->phead->next;
    while (pnode != NULL && i < position) {
        i++;
        pnode = pnode->next;
    }
    
    DLNode *deleteNode = pnode;
    *value = deleteNode->data;
    pnode->prior->next = pnode->next;
    pnode->next->prior = pnode->prior;
    
    free(deleteNode);
    
    return true;
}

bool deleteDoubleListWithItem(DoubleLinkedList *list, int item, int *position) {
    
    if (list == NULL || list->phead == NULL) {
        return false;
    }

    DLNode *pnode = list->phead->next;
    
    int i = 0;
    while (pnode != NULL) {
        
        if (pnode->data != item) {
            i++;
            pnode = pnode->next;

        } else {
            
            break;
        }
    }
    
    if (pnode != list->phead) {

        pnode->prior->next = pnode->next;
        pnode->next->prior = pnode->prior;
        *position = i;
        free(pnode);
        return true;
        
    } else {
        *position = -1;
        return false;
    }
}

bool findDoubleListItem(DoubleLinkedList *list, int item, int *position) {
    
    if (list == NULL) {
        return false;
    }
    
    int i = 0;
    DLNode *pnode = list->phead->next;
    while (pnode != NULL) {
        
        if (pnode->data == item) {
            *position = i;
            return true;
        }

        i++;
        pnode = pnode->next;
    }
    
    return false;
}

DLNode *findDoubleListNodeWithItem(DoubleLinkedList *list, int item) {
    
    if (list == NULL) {
        return false;
    }
    
    DLNode *pnode = list->phead->next;
    while (pnode != NULL) {
        
        if (pnode->data == item) {
            return pnode;
        }

        pnode = pnode->next;
    }
    
    return NULL;
}

int lengthDoubleLinkedList(DoubleLinkedList *list) {
    
    if (list == NULL) {
        return 0;
    }
    
    int length = 0;
    DLNode *pnode = list->phead->next;
    while (pnode != NULL && pnode != list->ptail) {
        length++;
        pnode = pnode->next;
    }
    
    return length;
}

bool isEmptyDoubleLinkedList(DoubleLinkedList *list) {
    
    if (list == NULL || (list->phead->next == list->ptail)) {
        return true;
    }
    
    return false;
}

void showDoubleLinkedList(DoubleLinkedList *list) {

    if (list == NULL || list->phead == NULL) {
        return;
    }
    
    DLNode *pnode = list->phead->next;
    while (pnode != NULL && pnode != list->ptail) {
        printf("%4d", pnode->data);
        pnode = pnode->next;
    }

    printf("\n");
}

void showRevDoubleLinkedList(DoubleLinkedList *list) {
    
    if (list == NULL || list->ptail == NULL) {
        return;
    }
    
    DLNode *pnode = list->ptail->prior;
    while (pnode != NULL && pnode != list->phead) {
        printf("%4d", pnode->data);
        pnode = pnode->prior;
    }
    
    printf("\n");
}

