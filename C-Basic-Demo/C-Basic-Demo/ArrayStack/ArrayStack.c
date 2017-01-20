//
//  ArrayStack.c
//  C-Basic-Demo
//
//  Created by HeJeffery on 2017/1/11.
//  Copyright © 2017年 HeJeffery. All rights reserved.
//

#include "ArrayStack.h"
#include <memory.h>

void createStack(Stack *stack) {
    stack->topIndex = -1;
    memset(stack->data, 0, sizeof(int) * StackLength);
}

bool isEmptyStack(Stack *stack) {
    return stack->topIndex == -1 ? true : false;
}

bool isFullStack(Stack *stack) {
    return stack->topIndex == (StackLength - 1) ? true : false;
}

int topIndex(Stack *stack) {
    return stack->topIndex;
}

int topValue(Stack *stack) {
    return stack->data[stack->topIndex];
}

bool push(Stack *stack, int value) {
    // 不是满栈，就push
    if (!isFullStack(stack)) {
        stack->topIndex++;
        stack->data[stack->topIndex] = value;
        return true;
    }

    return false;
}

bool pop(Stack *stack, int *value, int *index) {
    // 不是空栈就pop
    if (!isEmptyStack(stack)) {
        *value = stack->data[stack->topIndex];
        *index = stack->topIndex;
        stack->topIndex--;
        return true;
    }
    return false;
}

void showStackData(Stack *stack) {
    
    // 空栈就不做处理
    if (isEmptyStack(stack)) {
        return;
    }

    printf("=================栈数据遍历开始==================\n");
    for (int i = 0; i <= stack->topIndex; i++) {
        printf("%d  \n", stack->data[i]);
    }
    printf("=================栈数据遍历结束==================\n");
}
