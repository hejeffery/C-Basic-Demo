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

LinkedList *createLinkedList() {
    
    LinkedList *phead = (LinkedList *)malloc(sizeof(LinkedList));
    
    if (phead == NULL) {
        return NULL;
    }
    
    phead->next = NULL;
    return phead;
}

bool appendList(LinkedList *list, int value) {
    
    // 尾插法
    if (list == NULL) {
        return false;
    }
    
    // 遍历寻找尾结点
    LinkedList *ptail = list;
    while (ptail->next != NULL) {
        ptail = ptail->next;
    }
    
    // 分配一个新的结点并赋值
    LinkedList *pnew = (LinkedList *)malloc(sizeof(LinkedList));
    if (pnew == NULL) {
        return false;
    }
    pnew->data = value;
    pnew->next = NULL;

    // 尾节点的next指向新结点
    ptail->next = pnew;
    
    return true;
}

bool insertList(LinkedList *list, int position, int value) {
    
    if (list == NULL) {
        return false;
    }
    
    // 取出position位置的前一个结点
    int i = 0;
    LinkedList *pnode = list->next;
    // position - 1 说明是position的前一个位置
    while (pnode != NULL && i < (position - 1)) {
        pnode = pnode->next;
        i++;
    }
    
    // pnode == NULL处理了超过链表为空链表的情况或者可能大于链表长度的情况
    // i > position处理了position可能为负的情况或者
    if (pnode == NULL || i > (position - 1)) {
        // 插入的位置有问题
        return false;
    }
    
    LinkedList *pnew = (LinkedList *)malloc(sizeof(LinkedList));
    if (pnew == NULL) {
        return false;
    }

    pnew->data = value;
    pnew->next = pnode->next;
    pnode->next = pnew;

    return true;
}

bool isEmptyLinkedList(LinkedList *list) {
    
    return list->next == NULL ? true : false;
}

int length(LinkedList *list) {
    
    int length = 0;
    
    LinkedList *pnode = list->next;
    while (pnode != NULL) {
        length++;
        pnode = pnode->next;
    }
    
    return length;
}

void showLinkedList(LinkedList *list) {
    
    LinkedList *pnode = list->next;
    while (pnode != NULL) {
        printf("%4d", pnode->data);
        pnode = pnode->next;
    }
    printf("\n");
}


