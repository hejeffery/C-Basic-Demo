//
//  CBasic.c
//  C-Basic-Demo
//
//  Created by HeJeffery on 2017/1/31.
//  Copyright © 2017年 HeJeffery. All rights reserved.
//

#include "CBasic.h"

#include <stdlib.h>

// 一些数组容易混淆的知识点
void someArrayConfusion() {
    printf("*********一维数组*********\n");
    // 一维数组
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    // a和&a的区别
    printf("a = %p, &a = %p\n", a, &a);
    // 1.a是数组的首地址，指向数组元素的第一个元素；
    // 2.&a是数组的地址，指向一个一维数组。此时可以把数组当成一个类型，改类型的大小是4(int是4个字节) * 10，所以&a + 1代表移动该数组类型的1个长度，在此也就是移动40字节
    // 它们的本质就是指针的类型不一样
    // 下面的+1就是加上一个类型的大小
    printf("a + 1 = %p, &a + 1 = %p\n", a + 1, &a + 1);
    printf("sizeof(a) = %lu, sizeof(*(&a)) = %lu, sizeof(&a) = %lu\n", sizeof(a), sizeof(*(&a)), sizeof(&a));
    
    printf("\n*********二维数组*********\n");
    // 二维数组
    int b[3][4] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    // b、&b，*b的区别
    printf("b = %p, &b = %p, *b = %p\n", b, &b, *b);
    // 1.b是二维数组的首行地址，相当于行指针
    // 2.&b是数组的地址，指向一个二维数组。此时可以把数组当成一个类型，改类型的大小是4(int是4个字节) * 3 * 4，所以&b + 1代表移动该数组类型的1个长度，在此也就是移动48字节
    // 3.*b是首行首列的地址，相当于列指针，*b + 1往后移动一个元素，就是首行第1列的地址
    printf("b + 1= %p, &b + 1 = %p, *b + 1 = %p\n", b + 1, &b + 1, *b + 1);
    printf("sizeof(b) = %lu, sizeof(*b) = %lu, sizeof(&b) = %lu\n", sizeof(b), sizeof(*b), sizeof(&b));
    
    // 数组指针
    printf("\n*********数组指针*********\n");
    int (*p)[10];
    // 可以判断这里的p的类型是数组
    printf("p = %p, p + 1 = %p", p, p + 1);
}

// 二维数组和指针的总结
void twoDimensionalArray() {
    int array[4][4] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%p, %2d, ", &array[i][j], array[i][j]);
        }
        printf("\n");
    }
    
    printf("\n");
    
    printf("\n*********打印行*********\n");
    for (int i = 0; i < 4; i++) {
        printf("%p, %2d\n", array + i, *array[i]);
    }
    
    printf("\n*********打印列*********\n");
    for (int i = 0; i < 4; i++) {
        printf("%p, %2d\n", *array + i, *(*array + i));
    }
    printf("\n");
    
    // 二维数组总结：类型的转换是关键
    // array是行指针，类型是int (*p)[4]；*(array + i) + j是列指针，类型是 int *p
    // array + i === &array[i]，表示第i行
    // *(array + i) === array[i] 表示第i行第0列的地址
    // *(array + i) + j === array[i] + j === &array[i][j] 表示第i行第j列的地址
    // *(*(array + i) + j) === *(array[i] + j) === array[i][j] 表示第i行第j列
}

// 用动态分配内存打印
// 1
// 1 2
// 1 2 3
// 1 2 3 4
// 1 2 3 4 5
void dynamicPrintArray() {
    int count = 5;
    int **array = (int **)malloc(sizeof(int *) * count);
    for (int i = 0; i < count; i++) {
        *(array + i) = malloc(sizeof(int) * (i + 1));
        for (int j = 0; j <= i; j++) {
            *(*(array + i) + j) = j + 1;
            printf("%4d", *(*(array + i) + j));
        }
        printf("\n");
    }
}
