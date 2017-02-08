//
//  LinkedList.c
//  C-Basic-Demo
//
//  Created by HeJeffery on 2017/2/8.
//  Copyright © 2017年 HeJeffery. All rights reserved.
//

#include "LinkedList.h"

#include <stdlib.h>
#include <memory.h>

Node *createLinkedList() {
    
    Node *phead = (Node *)malloc(sizeof(Node));
    
    if (phead == NULL) {
        return NULL;
    }
    
    phead->next = NULL;
    return phead;
}

bool appendList(Node *node, int value) {
    
    if (node == NULL) {
        return false;
    }
    
    // 尾插法
    Node *ptail = node;
    while (ptail->next != NULL) {
        ptail = ptail->next;
    }
    
    Node *pnew = (Node *)malloc(sizeof(Node));
    if (pnew == NULL) {
        return false;
    }
    pnew->data = value;
    pnew->next = NULL;

    ptail->next = pnew;
    
    ptail = pnew;
    
    return true;
}

bool isEmptyLinkedList(Node *node) {
    
    return node->next == NULL ? true : false;
}

int length(Node *node) {
    
    int length = 0;
    
    Node *pnode = node->next;
    while (pnode != NULL) {
        length++;
        pnode = pnode->next;
    }
    
    return length;
}

void showLinkedList(Node *node) {
    
    Node *pnode = node->next;
    while (pnode != NULL) {
        printf("%4d", pnode->data);
        pnode = pnode->next;
    }
}


