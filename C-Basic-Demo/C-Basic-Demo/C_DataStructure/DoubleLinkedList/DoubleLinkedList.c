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
    
    pnew->data = value;
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

    int i = 0;
    DoubleLinkedList *pnode = list->next;
    while (pnode != NULL && i < position) {
        
        i++;
        pnode = pnode->next;
    }
    
    DoubleLinkedList *pnew = (DoubleLinkedList *)malloc(sizeof(DoubleLinkedList));
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
    DoubleLinkedList *pnode = list->next;
    while (pnode != NULL && i < position) {
        i++;
        pnode = pnode->next;
    }
    
    DoubleLinkedList *deleteNode = pnode;
    *value = deleteNode->data;
    pnode->prior->next = pnode->next;
    pnode->next->prior = pnode->prior;
    
    free(deleteNode);
    
    return true;
}

bool deleteDoubleListWithItem(DoubleLinkedList *list, int item, int *position) {
    
    if (list == NULL || list->next == NULL) {
        return false;
    }

    DoubleLinkedList *pnode = list->next;
    
    int i = 0;
    while (pnode != NULL) {
        
        if (pnode->data != item) {
            i++;
            pnode = pnode->next;

        } else {
            
            break;
        }
    }
    
    if (pnode != list) {

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
    DoubleLinkedList *pnode = list->next;
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

DoubleLinkedList *findDoubleListNodeWithItem(DoubleLinkedList *list, int item) {
    
    if (list == NULL) {
        return false;
    }
    
    DoubleLinkedList *pnode = list->next;
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
        printf("%4d", pnode->data);
        pnode = pnode->next;
    }
    
    printf("\n");
}

