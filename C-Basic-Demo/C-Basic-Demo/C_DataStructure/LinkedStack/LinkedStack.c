//
//  LinkedStack.c
//  C-Basic-Demo
//
//  Created by HeJeffery on 2017/2/15.
//  Copyright © 2017年 HeJeffery. All rights reserved.
//

#include "LinkedStack.h"

#include <stdlib.h>
#include <memory.h>

////////////////////////////////////////////////////////////////////////////////////
//                                                                                //
//                使用的是尾插法，对于栈来说，效率不高，效率最高的是头插法                   //
//                                                                                //
////////////////////////////////////////////////////////////////////////////////////

LinkedStack *createLinkedStack() {
    
    LinkedStack *stack = (LinkedStack *)malloc(sizeof(LinkedStack));
    if (stack == NULL) {
        return NULL;
    }
    
    stack->next = NULL;
    return stack;
}

bool pushLinkedStack(LinkedStack *stack, int value) {
    
    if (stack == NULL) {
        return false;
    }
    
    LinkedStack *pnode = stack;
    while (pnode->next != NULL) {
        pnode = pnode->next;
    }
    
    LinkedStack *pnew = (LinkedStack *)malloc(sizeof(LinkedStack));
    if (pnew == NULL) {
        return false;
    }
    
    pnew->data = value;
    pnew->next = NULL;
    
    pnode->next = pnew;
    
    return true;
}

bool popLinkedStack(LinkedStack *stack, int *value, int *index) {
    
    if (stack == NULL) {
        return false;
    }
    
    // 空栈直接返回false
    if (isEmptyLinkedStack(stack)) {
        return false;
    }
    
    // 双指针
    int i = 0;
    LinkedStack *pnode1 = stack->next;
    LinkedStack *pnode2 = stack;
    while (pnode1->next != NULL) {
        i++;
        pnode2 = pnode1;
        pnode1 = pnode1->next;
    }
    
    *value = pnode1->data;
    *index = i;

    pnode2->next = NULL;
    free(pnode1);
    
    return true;
}

int lengthLinkedStack(LinkedStack *stack) {
    
    if (isEmptyLinkedStack(stack)) {
        return 0;
    }
    
    int length = 0;
    LinkedStack *pnode = stack;
    while (pnode->next != NULL) {
        pnode = pnode->next;
        length++;
    }
    
    return length;
}

bool isEmptyLinkedStack(LinkedStack *stack) {
    
    return stack->next == NULL ? true : false;
}

int topLinkedStackIndex(LinkedStack *stack) {
    
    if (isEmptyLinkedStack(stack)) {
        return -1;
    }
    
    int topIndex = 0;
    LinkedStack *pnode = stack;
    while (pnode->next != NULL) {
        pnode = pnode->next;
        topIndex++;
    }
    
    return topIndex;
}

int topLinkedStackValue(LinkedStack *stack) {
    
    if (isEmptyLinkedStack(stack)) {
        return -1;
    }
    
    LinkedStack *pnode = stack;
    while (pnode->next != NULL) {
        pnode = pnode->next;
    }
    
    return pnode->data;
}

void showLinkedStack(LinkedStack *stack) {
    
    if (isEmptyLinkedStack(stack)) {
        return;
    }
    
    printf("=================栈数据遍历开始==================\n");
    LinkedStack *pnode = stack->next;
    while (pnode != NULL) {
        printf("%4d", pnode->data);
        pnode = pnode->next;
    }
    printf("\n=================栈数据遍历结束==================\n");
}


////////////////////////////////////////////////////////////////////////////////////
//                                                                                //
//                                   头插法效率比较高                                //
//                                                                                //
////////////////////////////////////////////////////////////////////////////////////

LinkedStack *createLinkedStackHead() {
    
    LinkedStack *stack = (LinkedStack *)malloc(sizeof(LinkedStack));
    if (stack == NULL) {
        return NULL;
    }
    
    stack->next = NULL;
    
    return stack;
}

bool pushLinkedStackHead(LinkedStack **stack, int value) {
    
    if (*stack == NULL) {
        return false;
    }
    
    LinkedStack *pnew = (LinkedStack *)malloc(sizeof(LinkedStack));
    if (pnew == NULL) {
        return false;
    }

    pnew->data = value;
    pnew->next = *stack;
    
    *stack = pnew;

    return true;
}

bool popLinkedStackHead(LinkedStack **stack, int *value, int *index) {
    
    if (*stack == NULL) {
        return false;
    }
    
    if ((*stack)->next != NULL) {
        LinkedStack *pnode = (*stack);
        *value = pnode->data;
        *index = lengthLinkedStackHead(*stack);
        *stack = (*stack)->next;
        free(pnode);
    }

    return true;
}

int lengthLinkedStackHead(LinkedStack *stack) {
    
    if (stack == NULL) {
        return 0;
    }
    
    int length = 0;
    LinkedStack *pnode = stack;
    while (pnode->next != NULL) {
        length++;
        pnode = pnode->next;
    }
    
    return length;
}

bool isEmptyLinkedStackHead(LinkedStack *stack) {
    
    return stack->next == NULL ? true : false;
}

int topLinkedStackIndexHead(LinkedStack *stack) {

    return lengthLinkedStackHead(stack);
}

int topLinkedStackValueHead(LinkedStack *stack) {
    
    return stack->data;
}

void showLinkedStackHead(LinkedStack *stack) {
    
    if (stack == NULL || stack->next == NULL) {
        return;
    }
    
    printf("=================栈数据遍历开始==================\n");
    LinkedStack *pnode = stack;
    while (pnode->next != NULL) {
        printf("%4d", pnode->data);
        pnode = pnode->next;
    }
    printf("\n=================栈数据遍历结束==================\n");
}

