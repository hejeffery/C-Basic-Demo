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

bool insertCircleList(CircleLinkedList *list, int position, int value) {
    
    if (list == NULL) {
        return false;
    }
    
//    // 第一种方法
//    int length = circleListLength(list);
//    
//    if (position < 0 || position > length) {
//        return false;
//    }
//
//    CircleLinkedList *pnode = list;
//    int i = 0;
//    while (i < position) {
//        i++;
//        pnode = pnode->next;
//    }
//    
//    CircleLinkedList *pnew = (CircleLinkedList *)malloc(sizeof(CircleLinkedList));
//    if (pnew == NULL) {
//        return false;
//    }
//
//    pnew->data = value;
//    pnew->next = pnode->next;
//    pnode->next = pnew;
    
    // 第二种方法：双指针
    int length = circleListLength(list);

    if (position < 0 || position > length) {
        return false;
    }

    CircleLinkedList *pnode1 = list->next;
    CircleLinkedList *pnode2 = list;
    int i = 0;
    while (pnode1 != list && i < position) {

        pnode2 = pnode1;
        pnode1 = pnode1->next;
        i++;
    }
    
    CircleLinkedList *pnew = (CircleLinkedList *)malloc(sizeof(CircleLinkedList));
    if (pnew == NULL) {
        return false;
    }
    
    pnew->data = value;
    pnew->next = pnode1;
    pnode2->next = pnew;
    
    return true;
}

bool deleteCircleListWithPosition(CircleLinkedList *list, int position, int *value) {
    
    if (list == NULL) {
        return false;
    }
    
    int length = circleListLength(list);
    
    if (position < 0 || position > length) {
        return false;
    }
    
    // 双指针
    int i = 0;
    CircleLinkedList *pnode1 = list->next;
    CircleLinkedList *pnode2 = list;
    while (pnode1 != list && i < position) {
        i++;
        pnode2 = pnode1;
        pnode1 = pnode1->next;
    }
    
    // 保存需要删除的结点
    CircleLinkedList *deletedNode = pnode1;
    *value = deletedNode->data;
    
    // 需要删除结点的前驱结点指向需要删除结点的后继结点
    pnode2->next = pnode1->next;
    
    // 释放被删除的结点
    free(deletedNode);
    
    return true;
}

bool deleteCircleListWithItem(CircleLinkedList *list, int item, int *position) {
    
    if (list == NULL || list->next == NULL) {
        return false;
    }
    
//    // 第一种方法
//    // 先查找item是否存在
//    bool isFindItem = findCircleListItem(list, item, position);
//    
//    // 不存在，直接返回false
//    if (!isFindItem) {
//        return false;
//    }
//    
//    // 存在就调用deleteList
//    return deleteCircleListWithPosition(list, *position, &item);
    
    // 第二种方法：双指针
    CircleLinkedList *pnode1 = list->next;
    CircleLinkedList *pnode2 = list;
    
    int i = 0;
    while (pnode1 != list) {
        
        if (pnode1->data != item) {
            pnode2 = pnode1;
            pnode1 = pnode1->next;
            i++;

        } else {
            break;
        }
    }
    
    if (pnode1 != list) {// 在链表中找到了item
        pnode2->next = pnode1->next;
        free(pnode1);
        *position = i;
        return true;

    } else {// 在链表中没有找到item
        *position = -1;
        return false;
    }
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

bool findCircleListItem(CircleLinkedList *list, int item, int *position) {
    
    if (list == NULL) {
        return false;
    }
    
    CircleLinkedList *pnode = list->next;
    int i = 0;
    while (pnode != list) {
        
        if (pnode->data == item) {
            *position = i;
            return true;
        }

        pnode = pnode->next;
        i++;
    }
    
    return false;
}

CircleLinkedList *findCircleNodeWithItem(CircleLinkedList *list, int item) {
    
    if (list == NULL) {
        return NULL;
    }
    
    CircleLinkedList *pnode = list->next;
    while (pnode != list) {
        
        if (pnode->data == item) {
            return pnode;
        }
        
        pnode = pnode->next;
    }
    
    return NULL;
}

bool isEmptyCircleLinkedList(CircleLinkedList *list) {
    
    return list == list->next ? true : false;
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
