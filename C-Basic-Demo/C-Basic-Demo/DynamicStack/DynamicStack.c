//
//  DynamicStack.c
//  C-Basic-Demo
//
//  Created by HeJeffery on 2017/1/19.
//  Copyright © 2017年 HeJeffery. All rights reserved.
//

#include "DynamicStack.h"
#include <stdlib.h>
#include <memory.h>

bool createDynamicStack(DynamicStack *stack, int length) {
    stack->data = (int *)calloc(length, sizeof(int));
    if (stack->data == NULL) {
        return false;
    }
    
    stack->topIndex = -1;
    stack->baseLength = length;
    stack->currentSize = length;
    return true;
}

bool isEmptyDynamicStack(DynamicStack *stack) {
    return stack->topIndex == -1 ? true : false;
}

int currentStackSize(DynamicStack *stack) {
    return stack->currentSize;
}

bool pushDynamicStack(DynamicStack **stack, int value) {
    // 已经满了，再分配空间
    if ((*stack)->topIndex == (*stack)->currentSize) {
        (*stack)->data = (int *)realloc((*stack)->data, sizeof(int) * (*stack)->baseLength);
        if ((*stack)->data == NULL) {
            printf("压栈失败，分配空间失败\n");
            return false;

        } else {
            (*stack)->currentSize += (*stack)->baseLength;
        }
    }
    
    (*stack)->topIndex++;
    (*stack)->data[(*stack)->topIndex] = value;
    return true;
}

bool popDynamicStack(DynamicStack *stack, int *value, int *index) {
    // 空栈，就直接返回
    if (isEmptyDynamicStack(stack)) {
        return false;
    }
    
    *value = stack->data[stack->topIndex];
    *index = stack->topIndex;
    stack->topIndex--;
    return true;
}

void showDynamicStackData(DynamicStack *stack) {
    if (isEmptyDynamicStack(stack)) {
        return;
    }
    
    printf("=================栈数据遍历开始==================\n");
    for (int i = 0; i <= stack->topIndex; i++) {
        printf("%d  \n", stack->data[i]);
    }
    printf("栈当前的size = %d\n", currentStackSize(stack));
    printf("=================栈数据遍历结束==================\n\n");
}
