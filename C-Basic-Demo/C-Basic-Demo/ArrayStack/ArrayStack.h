//
//  ArrayStack.h
//  C-Basic-Demo
//
//  Created by HeJeffery on 2017/1/11.
//  Copyright © 2017年 HeJeffery. All rights reserved.
//

#ifndef ArrayStack_h
#define ArrayStack_h

#include <stdio.h>
#include <stdbool.h>

#define StackLength 100

typedef struct ArrayStack Stack;

// 栈，数组形式
struct ArrayStack {
    int data[StackLength];
    int topIndex;
};

// 创建Stack
void createStack(Stack *stack);

// 是否是空栈
bool isEmptyStack(Stack *stack);

// 是否是满栈
bool isFullStack(Stack *stack);

// 获取栈顶的Index
int topIndex(Stack *stack);

// 获取栈顶的值
int topValue(Stack *stack);

// 压栈
bool push(Stack *stack, int value);

// 出栈
bool pop(Stack *stack, int *value, int *index);

// 显示栈的数据
void showStackData(Stack *stack);

#endif /* ArrayStack_h */
