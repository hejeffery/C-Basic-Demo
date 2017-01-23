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

////////////////////////////////////////////////////////////////////////////////////
//                                                                                //
//                                 栈，静态数组形式                                  //
//                                                                                //
////////////////////////////////////////////////////////////////////////////////////

struct ArrayStack {
    int data[StackLength];// 数组的长度
    int topIndex;// 栈顶的index，初始值为-1
};

/**
 *  创建Stack
 *
 *  @param stack 需要被初始化的ArrayStack的地址
 */
void createStack(Stack *stack);

/**
 *  是否是空栈
 *
 *  @param stack ArrayStack的地址
 *  @return 空栈返回true，反之返回false
 */
bool isEmptyStack(Stack *stack);

/**
 *  是否是满栈
 *
 *  @param stack ArrayStack的地址
 *  @return 满栈返回true，反之返回false
 */
bool isFullStack(Stack *stack);

/**
 *  获取栈顶的Index
 *
 *  @param stack ArrayStack的地址
 *  @return 返回的栈顶index
 */
int topIndex(Stack *stack);

/**
 *  获取栈顶的值
 *
 *  @param stack ArrayStack的地址
 *  @return 返回的栈顶的值
 */
int topValue(Stack *stack);

/**
 *  压栈
 *
 *  @param stack ArrayStack的地址
 *  @param value 压栈的值
 *  @return 压栈成功返回true，反之返回false
 */
bool push(Stack *stack, int value);

/**
 *  出栈
 *
 *  @param stack ArrayStack的地址
 *  @param value 出栈的值
 *  @param index 出栈的index的值
 *  @return 出栈成功返回true，反之返回false
 */
bool pop(Stack *stack, int *value, int *index);

/**
 *  显示栈的数据
 *
 *  @param stack ArrayStack的地址
 */
void showStackData(Stack *stack);

#endif /* ArrayStack_h */
