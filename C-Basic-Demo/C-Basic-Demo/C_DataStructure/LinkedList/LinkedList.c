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

    // 尾结点的next指向新结点
    ptail->next = pnew;
    
    return true;
}

bool insertList(LinkedList *list, int position, int value) {// 也可以用双指针来实现
    
    if (list == NULL) {
        return false;
    }
    
//    // 第一种方式
//    // 取出position位置的前一个结点
//    int i = 0;
//    LinkedList *pnode = list;
//    while (pnode != NULL && i < position) {
//        pnode = pnode->next;
//        i++;
//    }
//    
//    // pnode == NULL处理了超过链表为空链表的情况或者可能大于链表长度的情况
//    // i > position处理了position可能为负的情况或者
//    if (pnode == NULL || i > position) {
//        // 插入的位置有问题
//        return false;
//    }
    
    // 第二种方式
    int count = length(list);
    
    if (position < 0 || position > count) {
        // 插入的位置有问题
        return false;
    }

    int i = 0;
    LinkedList *pnode = list;
    while (pnode != NULL && i < position) {
        pnode = pnode->next;
        i++;
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


bool deleteListWithPosition(LinkedList *list, int position, int *value) {
    
    if (list == NULL) {
        return false;
    }
    
    int count = length(list);
    
    if (position < 0 || position > count) {
        // 删除的位置有问题
        return false;
    }
    
    // 取出position位置的前一个结点
    int i = -1;
    LinkedList *pnode = list;
    while (pnode != NULL && i < (position - 1)) {
        i++;
        pnode = pnode->next;
    }
    
    // 保存需要删除的结点
    LinkedList *deletedNode = pnode->next;
    
    if (deletedNode != NULL) {// 不为空说明结点有效
        *value = deletedNode->data;
        
        // 需要删除结点的前驱结点指向需要删除结点的后继结点
        pnode->next = pnode->next->next;
        
        // 释放被删除的结点
        free(deletedNode);
        
        return true;

    } else {
        return false;
    }
    
}

bool deleteListWithItem(LinkedList *list, int item, int *position) {// 双指针实现
    
    if (list == NULL) {
        return false;
    }
    
    // 双指针处理
    LinkedList *pnode1 = list;
    LinkedList *pnode2 = list;
    
    int i = -1;
    while (pnode1 != NULL) {
        
        // 不相等，pnode2保存pnode1的值，pnode1前进1
        if (pnode1->data != item) {
            i++;
            pnode2 = pnode1;
            pnode1 = pnode1->next;
            
        } else {
            break;
        }
    }
    
    if (pnode1 != NULL) {// 没有执行到最后的结点，找到了需要删除的item
        // 被删除的item的上一个结点指向item的下一个结点
        pnode2->next = pnode1->next;
        free(pnode1);
        *position = i;
        return true;
        
    } else {// 没有找到需要删除的item
        *position = -1;
        return false;
    }
}

bool findListItem(LinkedList *list, int item, int *position) {
    
    if (list == NULL) {
        return false;
    }
    
    int i = 0;
    LinkedList *pnode = list->next;
    while (pnode != NULL) {
        if (pnode->data == item) {
            *position = i;
            return true;
        }
        pnode = pnode->next;
        i++;
    }
    
    return false;
}

LinkedList *findNodeWithItem(LinkedList *list, int item) {
    
    if (list == NULL) {
        return false;
    }
    
    LinkedList *pnode = list->next;
    while (pnode != NULL) {
        
        if (pnode->data == item) {
            return pnode;
        }

        pnode = pnode->next;
    }
    
    return NULL;
}

LinkedList *findCenterNode(LinkedList *list) {
    
    if (list == NULL) {
        return NULL;
    }
    
    // 前进一个
    LinkedList *pnode = list->next;
    // 前进两个
    LinkedList *pnode2 = list->next;
    
    while (pnode2->next != NULL) {
        pnode = pnode->next;
        
        pnode2 = pnode2->next;
        if (pnode2->next != NULL) {
            pnode2 = pnode2->next;
        }
        
    }
    return pnode;
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

void reverseList(LinkedList *list) {
    
    if (list == NULL || list->next == NULL) {
        return;
    }

    LinkedList *preNode = list;
    LinkedList *currentNode = preNode->next;
    LinkedList *nextNode = NULL;

    preNode = NULL;

    while (currentNode) {
        nextNode = currentNode->next;

        currentNode->next = preNode;
        preNode = currentNode;
        currentNode = nextNode;
    }

    list->next = preNode;
}

LinkedList *mergeList(LinkedList *list1, LinkedList *list2) {
    
    if (list1 == NULL || list1->next == NULL || list2 == NULL || list2->next == NULL) {
        return NULL;
    }
    
    LinkedList *mergeList = createLinkedList();
    
    LinkedList *pnode1 = list1->next;
    LinkedList *pnode2 = list2->next;
    
    while (pnode1 != NULL || pnode2 != NULL) {
        
        if (pnode1 != NULL && pnode2 != NULL) {
            if (pnode1->data <= pnode2->data) {

                appendList(mergeList, pnode1->data);
                pnode1 = pnode1->next;
                
            } else {
                appendList(mergeList, pnode2->data);
                pnode2 = pnode2->next;
            }

        } else {
            
            while (pnode1 != NULL) {
                appendList(mergeList, pnode1->data);
                pnode1 = pnode1->next;
            }
            
            while (pnode2 != NULL) {
                appendList(mergeList, pnode2->data);
                pnode2 = pnode2->next;
            }
        }
    }

    return mergeList;
}

bool hasCircleList(LinkedList *list) {
    
    if (list == NULL) {
        return false;
    }
    
    // 前进一个
    LinkedList *pnode1 = list->next;
    // 前进两个
    LinkedList *pnode2 = list->next;
    
    while (pnode1 != NULL && pnode2 != NULL) {
        
        pnode1 = pnode1->next;
        pnode2 = pnode2->next;
        if (pnode2 != NULL) {
            pnode2 = pnode2->next;
        }
        
        // 如果相等，就说明有环
        if (pnode1 == pnode2) {
            return true;
        }
    }

    return false;
}

bool clearList(LinkedList *list) {
    
    if (list == NULL) {
        return false;
    }
    
//    // 第一种方法：逐个删除，需要改变头结点
//    LinkedList *node = NULL;
//    while (list != NULL) {
//        node = list->next;
//        free(list);
//        list = node;
//    }
    
    // 第二种方式：双指针
    LinkedList *pnode1 = list;
    LinkedList *pnode2 = list;
    while (pnode1 != NULL) {
        pnode2 = pnode1;
        pnode1 = pnode1->next;
        free(pnode2);
    }
    
    return true;
}

void showLinkedList(LinkedList *list) {
    
    LinkedList *pnode = list->next;
    while (pnode != NULL) {
        printf("%4d", pnode->data);
        pnode = pnode->next;
    }
    printf("\n");
}

void reversePrintList(LinkedList *list) {
    
    if (list == NULL) {
        return;

    } else {
        
        reversePrintList(list->next);
        printf("%4d", list->data);
    }
}


