//
//  Algorithm.c
//  C-Basic-Demo
//
//  Created by HeJeffery on 2017/1/23.
//  Copyright © 2017年 HeJeffery. All rights reserved.
//

#include "Algorithm.h"

#include <stdlib.h>
#include <memory.h>
#include <string.h>
#include <time.h>

void selectionSort(int *array, int count) {
    // 选择排序法的思想：每一趟都是找出最值(和找出一个数组中的最值算法类似)，然后交换。
    // 也就是第一个数和后面的数逐个扫描，第二个数和后面的数逐个扫描....
    for (int i = 0; i < count; i++) {
        
        // 这里和找出一个数组中的最值算法一样
        for (int j = i + 1; j < count; j++) {
            if (array[i] < array[j]) {

                array[i] = array[i] ^ array[j];
                array[j] = array[i] ^ array[j];
                array[i] = array[i] ^ array[j];
            }
        }
    }
    
    for (int i = 0; i < count; i++) {
        printf("%d  \n", array[i]);
    }
}

void bubbleSort(int *array, int count) {
    // 冒泡排序的思想：数字上浮或者下沉
    // 比较的相邻的两个数
    int loopNumber = count - 1;
    for (int i = 0; i < loopNumber; i++) {// 每循环一次就有一个数上浮或者下沉
        for (int j = 0; j < loopNumber - i; j++) {
            if (array[j] > array[j + 1]) {

                array[j] = array[j] ^ array[j + 1];
                array[j + 1] = array[j] ^ array[j + 1];
                array[j] = array[j] ^ array[j + 1];
            }
        }
    }
    for (int i = 0; i < count; i++) {
        printf("%d  \n", array[i]);
    }
}

void insertSort(int *array, int count) {
    // 插入排序的思想：把数组分为n-1个数组序列。每次从数组的最后一个值往前插值
    // 从第二个元素开始
    for (int i = 1; i < count; i++) {
        // 用来记录数组序列的最后一个元素的位置
        int index = i;
        // 用来记录数组序列的最后一个元素
        int element = array[i];
        
        while (index > 0 && element < array[index - 1]) {
            array[index] = array[index - 1];// 往后移
            index--;
        }
        array[index] = element;
    }
    
    for (int i = 0; i < count; i++) {
        printf("%d  \n", array[i]);
    }
}

void quickSort(int *array, int beginIndex, int lastIndex) {
    
    // 双指针快速排序的思想：分治思想---使用递归处理
    // 选数组的第一个元素为参照，比该元素小的放在该元素的左边，比该元素小的放在该元素的右边
    if (beginIndex < lastIndex) {
        
        int i = beginIndex;
        for (int j = beginIndex + 1; j <= lastIndex; j++) {

            // array[beginIndex]此时就是一个参照
            if (array[j] < array[beginIndex]) {

                // i往前移动1
                i++;
                
                // 交换array[i]和array[j]的值
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }

        // 交换array[beginIndex]和array[i]的值
        int temp = array[i];
        array[i] = array[beginIndex];
        array[beginIndex] = temp;
        
        // 递归处理子数组
        quickSort(array, beginIndex, i - 1);
        quickSort(array, i + 1, lastIndex);
    }
}

int binarySearch(int *array, int count, int searchNumber) {
    int headIndex = 0;
    int tailIndex = count - 1;
    while (headIndex <= tailIndex) {
        int middleIndex = (headIndex + tailIndex) / 2;
        if (searchNumber < array[middleIndex]) {// 从上半部分查找
            tailIndex = middleIndex - 1;
            
        } else if (searchNumber > array[middleIndex]) {// 从下半部分查找
            headIndex = middleIndex + 1;
            
        } else if (searchNumber == array[middleIndex]) {// 找到了
            return middleIndex;
            
        }
    }
    return -1;// 没有找到返回-1
}

int lagrangeSearch(int *array, int count, int searchNumber) {
    int headIndex = 0;
    int tailIndex = count - 1;
    while (headIndex <= tailIndex) {
        // 比例
        float ratio = ((searchNumber - array[headIndex]) / (array[tailIndex] - array[headIndex])) * 1.0;
        int middleIndex = headIndex + (tailIndex - headIndex) * ratio;
        if (searchNumber < array[middleIndex]) {// 从上半部分查找
            tailIndex = middleIndex - 1;
            
        } else if (searchNumber > array[middleIndex]) {// 从下半部分查找
            headIndex = middleIndex + 1;
            
        } else if (searchNumber == array[middleIndex]) {// 找到了
            return middleIndex;
            
        }
    }
    return -1;// 没有找到返回-1
}

void outOfOrderArray(int *array, int count) {
    // 获取随机数种子
    // 思想：1.第1个元素和第1个元素后面的9个元素中的其中一个交换
    //      2.第2个元素和第2个元素后面的8个元素中的其中一个交换
    //      3.第3个元素和第3个元素后面的7个元素中的其中一个交换......
    time_t t;
    srand((unsigned int)time(&t));
    
    for (int i = 0; i < count - 1; i++) {
        int randomIndex = i + (rand() % (count - 1 - i));
        int temp = array[i];
        array[i] = array[randomIndex];
        array[randomIndex] = temp;
    }
    
    for (int i = 0; i < count; i++) {
        printf("%d  \n", array[i]);
    }
}

int fibonacciRecursion(int number) {
    if (number == 1 || number == 2) {
        return 1;
        
    } else {
        // 推理出递归的公式：f(n) = f(n - 1) + f(n - 2) (n >= 2)
        return fibonacciRecursion(number - 1) + fibonacciRecursion(number - 2);
    }
}

int fibonacciArrayFor(int number) {
    // 小于等于0就返回0
    if (number <= 0) {
        return 0;
    }
    
    int array[number];
    
    // for实现
    for (int i = 0; i < number; i++) {
        if (i == 0 || i == 1) {
            array[i] = 1;
            
        } else {
            array[i] = array[i - 1] + array[i - 2];
        }
    }
    return array[number - 1];
}

int fibonacciArrayWhile(int number) {
    // 小于等于0就返回0
    if (number <= 0) {
        return 0;
    }
    
    int array[number];
    
    // while实现
    int index = 0;
    while (index != number) {
        if (index == 0 || number == 1) {
            array[index] = 1;
            
        } else {
            array[index] = array[index - 1] + array[index - 2];
        }
        index++;
    }
    return array[index - 1];
}

int recursionPlus(int number) {
    if (number < 0) {
        return 0;
    }
    return recursionPlus(number - 1) + number;
}

void nineMultNine() {
    for (int i = 1; i < 10; i++) {
        for (int j = 1; j <= i; j++) {
            printf("%d*%d = %2d   ", i, j, i * j);
        }
        printf("\n");
    }
}

void decimalToBinary(int number) {
    if (number == 0) {
        return;
        
    } else {
        
        decimalToBinary(number / 2);
        printf("%d", number % 2);
    }
}

int reverseNumber(int number) {
    int result = 0;
    
    // while实现
    if (number != 0) {
        while (number) {
            int temp = number % 10;
            result = result * 10 + temp;
            number /= 10;
        }
    }
    
//    // for实现
//    if (number != 0) {
//        for (; number > 0; number /= 10) {
//            int temp = number % 10;
//            result = result * 10 + temp;
//        }
//    }
    return result;
}

int reverseNumberByRecursion(int number, int *result) {
    if (number == 0) {
        return 1;
        
    } else {
        *result = *result * 10 + number % 10;
        return reverseNumberByRecursion(number / 10, result);
    }
}

int numberToAddByRecursion(int number) {
    if (number == 0) {
        return 0;
        
    } else {
        return number % 10 + numberToAddByRecursion(number / 10);
    }
}

void yangHuisTriangle() {
    int array[10][10] = {0};
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            // 第一列或者i == j时，都为1
            if (i == j || j == 0) {
                array[i][j] = 1;
                
            } else {
                array[i][j] = array[i - 1][j - 1] + array[i - 1][j];
            }
        }
    }
    
    int blankNum = 20;
    for (int i = 0; i < 10; i++) {
        printf("%*d", blankNum - 2 * i, array[i][0]);
        for (int j = 1; j <= i; j++) {
            printf("%4d", array[i][j]);
        }
        printf("\n");
    }
}

bool isIncreasingArrayByRecursion(int *array, int count) {
    if (count == 1) {// 只有一个元素，递增
        return 1;
        
    } else if (count == 2) {
        // 只有两个元素，判断0和1
        return array[1] >= array[0];
        
    } else {
        return isIncreasingArrayByRecursion(array, count - 1) && array[count - 1] >= array[count - 2];
    }
}

#define NUM 7
void circleArray() {
    int array[NUM][NUM] = {0};
    int number = 1;
    for (int i = 0, j = 0, k = 0; k < ((NUM + 1)) / 2; k++, i = k, j = k) {
        
        while (i < NUM - j) {
            array[i][j] = number++;
            j++;
        }
        
        j--;
        i++;
        while (i < NUM - k) {
            array[i][j] = number++;
            i++;
        }
        
        i--;
        j--;
        while (j >= k) {
            array[i][j] = number++;
            j--;
        }
        
        j++;
        i--;
        while (i > k) {
            array[i][j] = number++;
            i--;
        }
    }
    
    for (int i = 0; i < NUM; i++) {
        for (int j = 0; j < NUM; j++) {
            printf("%4d", array[i][j]);
        }
        printf("\n");
    }
}

void reverseArray(int *array, int count) {
    int *head = array;
    int *tail = array + count - 1;
    while (head < tail) {
        *head = *head ^ *tail;
        *tail = *head ^ *tail;
        *head = *head ^ *tail;
        head++;
        tail--;
    }
}

int stepProblemByRecursion(int stepNumber) {
    if (stepNumber < 1) {
        return 0;
    }
    
    if (stepNumber == 1) {
        return 1;
        
    } else if (stepNumber == 2) {
        return 2;
        
    } else if (stepNumber == 3) {
        return 4;
        
    }else {
        return stepProblemByRecursion(stepNumber - 1) + stepProblemByRecursion(stepNumber - 2) + stepProblemByRecursion(stepNumber - 3);
    }
}

void arrayIntersection() {
    // 思想：取长度最小的作为外层循环，用外层循环的数逐个和内层循环的数对比，两个数相等就放入新的数组
    // 交集的数组的最大长度是两个相交数组长度的最小值
    int array1[10] = {5, 6, 2, 3, 7, 8, 1, 12, 34, 9};
    int array2[5] = {2, 3, 1, 4, 6};
    
    int intersectionArray[5] = {0};
    
    int index = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 10; j++) {
            if (array2[i] == array1[j]) {
                intersectionArray[index] = array2[i];
                index++;
                break;
            }
        }
    }
    
    for (int i = 0; i < 5; i++) {
        if (intersectionArray[i] != 0) {
            printf("%d  ", intersectionArray[i]);
        }
    }
    printf("\n");
}

void arrayUnion() {
    // 交集的数组的最大长度是两个相交数组长度的总和
    // 把最小数组长度的值赋值给并集的数组
    int array1[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int array2[5] = {5, 6, 8, 9 ,10};
    int unionArray[15] = {0};
    
    for (int i = 0; i < 5; i++) {
        unionArray[i] = array2[i];
    }
    
    int index = 5;
    for (int i = 0; i < 10; i++) {
        bool isEqual = false;
        for (int j = 0; j < 5; j++) {
            if (array1[i] == array2[j]) {
                isEqual = true;
                break;
                
            }
        }
        if (!isEqual) {
            unionArray[index++] = array1[i];
        }
    }
    
    for (int i = 0; i < 15; i++) {
        if (unionArray[i] != 0) {
            printf("%d  ", unionArray[i]);
        }
    }
}

void duplicateArray(int *array, int count) {
    int resultArray[15] = {0};
    int index = 0;
    // 用指针遍历
    for (int *p = array; p < array + count; p++) {
        if (*(p) != *(p + 1)) {
            resultArray[index] = *p;
            index++;
        }
    }
    
    for (int i = 0; i < count; i++) {
        if (resultArray[i] != 0) {
            printf("%d  ", resultArray[i]);
        }
    }
    
    printf("\n");
}

void repeatNumberCountInArray(int *array, int count) {
    
    struct Repeat {
        int number;
        int count;
    };
    
    struct Repeat repeats[15] = {0};
    
    int index = 0;
    for (int i = 0; i < count; i++) {
        repeats[index].number = array[i];
        int numberCount = 1;
        for (int j = i; j < count; j++) {
            if (array[j] == array[j + 1]) {// 相等
                numberCount++;
                
            } else {// 不相等
                i = j;
                break;
            }
        }
        
        repeats[index].count = numberCount;
        index++;
    }
    
    for (int i = 0; i < count; i++) {
        if (repeats[i].count) {
            printf("number = %d, count = %d\n", repeats[i].number, repeats[i].count);
        }
    }
}

void bitOperation() {
    // 100的二进制：0110 0100
    // 取出100的第k位
    // 思路：先右移k位，再按位与1。1和任何位相与，不变
    int a = 100;
    int aIndex = (a >> 6) & 1;
    printf("aIndex = %d\n", aIndex);
    
    // 100的二进制：0110 0100
    // 将第k位清零，类似“关灯”
    // 思路：1移动到第k位，取反，再和数相与。0和任何位相与，为0
    int b = 100;
    b = b & ~(1 << 2);
    printf("b的第2位清零后的值是: %d\n", b);
    
    // 100的二进制：0110 0100
    // 将第k位置1，类似“开灯”
    // 思路：1移动到第k位，数相或。1和任何位相或，为1
    int c = 100;
    c = c | (1 << 3);
    printf("b的第3位置为1后的值是: %d\n", c);
    
    // 100的二进制：0110 0100
    // 相反数
    // 思路：取反再加1
    int d = 100;
    printf("d的相反数是：%d\n", ~d + 1);
    
    // 100的二进制：0110 0100
    // 判断一个数是基数还是偶数
    // 思路：看第0位是1还是0，如果是1，是奇数；是0，就是偶数
    int e = 100;
    if ((e & 1) == 1) {
        printf("e = %d, 是基数\n", e);
    } else {
        printf("e = %d, 是偶数\n", e);
    }
}

char *simpleZipStringTime(char *src) {
    
    if (src == NULL) {
        return NULL;
    }

    unsigned long srcLength = strlen(src);
    char *presult = (char *)calloc(srcLength + 1, sizeof(char));
    
    if (presult == NULL) {
        return NULL;
    }
    
    char *pstr = presult;// 记录presult的首地址
    
    while (*src != '\0') {
        char *srctemp = src;
        
        // 先计算出字符出现的次数
        unsigned long count = 1;
        while (*srctemp == *(srctemp + 1)) {
            count++;
            srctemp++;
        }
        
        // 如果字符只出现过1次
        if (count == 1) {
            *pstr = *srctemp;// 处理字符位

            pstr++;// 往前移1位
            src++;

        } else {// 出现的次数超过1次
            *pstr = count + '0';// 处理数字位
            *(pstr + 1) = *src;// 处理字符位

            pstr += 2;// 往前移2位
            src += count;
        }
    }
    
    // 压缩内存
    srcLength = strlen(presult) + 1;
    presult = (char *)realloc(presult, sizeof(char) * srcLength);

    if (presult == NULL) {
        return NULL;
    }

    return presult;
}

char *simpleUnzipStringTime(char *src) {
    
    if (src == NULL) {
        return NULL;
    }
    
    char *presult = (char *)calloc(1024, sizeof(char));
    char *pstr = presult;// 记录presult的首地址
    
    while (*src != '\0') {
        
        char *ptemp = src;
        
        if (*ptemp >= '0' && *ptemp <= '9') {
            int length = *ptemp - '0';
            for (int i = 0; i < length; i++) {
                *pstr = *(ptemp + 1);
                pstr++;
            }
            src += 2;
            
        } else {
            *pstr = *ptemp;
            pstr++;
            src++;
        }
    }
    
    // 压缩内存
    unsigned long resultStrLength = strlen(presult) + 1;
    presult = (char *)realloc(presult, sizeof(char) * resultStrLength);
    if (presult == NULL) {
        return NULL;
    }
    return presult;
}

char *simpleZipStringSpace(char *src) {
    
    if (src == NULL) {
        return NULL;
    }
    
    // 使用双指针处理
    char *psrc1 = src;
    char *psrc2 = src;
    
    while ((*psrc1 = *psrc2) != '\0') {

        int length = 1;
        char *psrc3 = psrc2 + 1;// 往后移一位
        while (*psrc2 == *psrc3) {
            psrc3++;
            length++;
        }
        
        if (length == 1) {
            psrc1++;
            psrc2++;

        } else {
            *(psrc3 - 2) = length + '0';
            psrc2 += length - 2;
        }
    }
    
    return src;
}

char *simpleUnzipStringSpace(char *src) {
    
    if (src == NULL) {
        return NULL;
    }
    
    // 使用双指针处理
    char *psrc1 = src;
    char *psrc2 = src;
    
    while ((*psrc1 = *psrc2) != '\0') {
        
        int length = 0;
        if (*psrc2 >= '0' && *psrc2 <= '9') {
            length = *psrc2 - '0';
        }
        
        char chr = *(psrc2 + 1);
        
        if (length == 0) {
            psrc1++;
            psrc2++;

        } else {

            // 往后移动
            for (char *p = psrc2 + strlen(psrc2); p >= psrc2; p--) {
                *(p + length - 2) = *p;
            }
            
            // 插入
            for (int i = 0; i < length; i++) {
                *(psrc2 + i) = chr;
            }
        }
        
    }

    return src;
}

void structBit(int num) {
    
    // 思路：一个字节一个字节的对int进行处理，结果需要逆序输出，因为低字节在低位
    struct Byte {
        unsigned char bit1 : 1;
        unsigned char bit2 : 1;
        unsigned char bit3 : 1;
        unsigned char bit4 : 1;
        unsigned char bit5 : 1;
        unsigned char bit6 : 1;
        unsigned char bit7 : 1;
        unsigned char bit8 : 1;
    };
    
    unsigned long length = sizeof(num);
    struct Byte *byte = &num;
    while (length--) {
        printf("%d%d%d%d %d%d%d%d ", (byte + length)->bit8,
                                     (byte + length)->bit7,
                                     (byte + length)->bit6,
                                     (byte + length)->bit5,
                                     (byte + length)->bit4,
                                     (byte + length)->bit3,
                                     (byte + length)->bit2,
                                     (byte + length)->bit1);
    }
    printf("\n");
}


