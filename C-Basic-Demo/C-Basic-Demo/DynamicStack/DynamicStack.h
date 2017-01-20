//
//  DynamicStack.h
//  C-Basic-Demo
//
//  Created by HeJeffery on 2017/1/19.
//  Copyright © 2017年 HeJeffery. All rights reserved.
//

#ifndef DynamicStack_h
#define DynamicStack_h

#include <stdio.h>
#include <stdbool.h>

typedef struct DynamicStack DynamicStack;

////////////////////////////////////////////////////////////////////////////////////
//                                                                                //
//                                 栈，动态数组栈                                    //
//                                                                                //
////////////////////////////////////////////////////////////////////////////////////

struct DynamicStack {
    int *data;
    int topIndex;
    int currentSize;
    int baseLength;
};

/**
 *  创建栈
 *
 *  @param stack 需要被初始化的DynamicStack的地址
 *  @param length 长度
 *  @return 创建成功返回true，创建失败返回false
 */
bool createDynamicStack(DynamicStack *stack, int length);

/**
 *  判断栈是否为空
 *
 *  @param stack DynamicStack的地址
 *  @return 空栈返回true，反之返回false
 */
bool isEmptyDynamicStack(DynamicStack *stack);

/**
 *  获取当前栈的size
 *
 *  @param stack DynamicStack的地址
 *  @return 返回队列当前的size
 */
int currentStackSize(DynamicStack *stack);

/**
 *  压栈
 *
 *  @param stack DynamicStack的地址
 *  @param value DynamicStack的地址
 *  @return 压栈成功返回true，反之返回false
 */
bool pushDynamicStack(DynamicStack *stack, int value);

/**
 *  出栈
 *
 *  @param stack DynamicStack的地址
 *  @param value 出栈的值
 *  @param index 出栈值的索引
 *  @return 出栈成功返回true，反之返回false
 */
bool popDynamicStack(DynamicStack *stack, int *value, int *index);

/**
 *  显示栈的数据
 *
 *  @param stack DynamicStack的地址
 */
void showDynamicStackData(DynamicStack *stack);

#endif /* DynamicStack_h */
