//
//  SequenceArrayList.h
//  C-Basic-Demo
//
//  Created by HeJeffery on 2017/1/19.
//  Copyright © 2017年 HeJeffery. All rights reserved.
//

#ifndef SequenceArrayList_h
#define SequenceArrayList_h

#include <stdio.h>
#include <stdbool.h>

typedef struct SequenceArrayList ArrayList;

////////////////////////////////////////////////////////////////////////////////////
//                                                                                //
//                                    数组的顺序存储                                 //
//                                                                                //
////////////////////////////////////////////////////////////////////////////////////
struct SequenceArrayList {
    int *list;
    int length;
    int currentIndex;
};

bool createArrayList(ArrayList *arrayList, int length);

bool isFullArrayList(ArrayList *arrayList);

bool isEmptyArrayList(ArrayList *arrayList);

bool append(ArrayList *arrayList, int value);

bool insert(ArrayList *arrayList, int index, int value);

bool deleteValue(ArrayList *arrayList, int index, int *value);

bool indexOfItem(ArrayList *arrayList, int index, int *item);

void clearAll(ArrayList *arrayList);

void showArrayList(ArrayList *arrayList);

#endif /* SequenceArrayList_h */
