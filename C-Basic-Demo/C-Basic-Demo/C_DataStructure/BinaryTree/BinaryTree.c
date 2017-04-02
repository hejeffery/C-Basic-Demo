//
//  BinaryTree.c
//  C-Basic-Demo
//
//  Created by HeJeffery on 2017/3/8.
//  Copyright © 2017年 HeJeffery. All rights reserved.
//

#include "BinaryTree.h"

#include <stdlib.h>
#include <memory.h>

void insertBinaryTree(BinaryTree **binaryTree, int value) {
    
    if (*binaryTree == NULL) {

        BTNode *pnew = (BTNode *)malloc(sizeof(BTNode));
        if (pnew == NULL) {
            return;
        }

        pnew->data = value;
        pnew->leftChild = NULL;
        pnew->rightChild = NULL;
        
        *binaryTree = pnew;

        return;

    } else {
        // 左子树
        if (value < (*binaryTree)->data) {
            insertBinaryTree(&((*binaryTree)->leftChild), value);

        } else {// 右子树
            insertBinaryTree(&((*binaryTree)->rightChild), value);
        }
    }
}

bool isEmptyBinaryTree(BinaryTree *binaryTree) {
    
    return binaryTree == NULL ? true : false;
}

int deepBinaryTree(BinaryTree *binaryTree) {
    
    if (binaryTree == NULL) {
        return 0;
    }
    
    int leftDeep = deepBinaryTree(binaryTree->leftChild);
    int rightDeep = deepBinaryTree(binaryTree->rightChild);
    
    return leftDeep > rightDeep ? leftDeep + 1: rightDeep + 1;
}

int leafNodeCount(BinaryTree *binaryTree) {
    
    if (isEmptyBinaryTree(binaryTree)) {
        return 0;
    }
    
    static int count = 0;
    
    if (binaryTree != NULL) {
        if (binaryTree->leftChild == NULL && binaryTree->leftChild == NULL) {
            count++;
        }
        
        leafNodeCount(binaryTree->leftChild);
        leafNodeCount(binaryTree->rightChild);
    }
    return count;
}

void preorderBinaryTree(BinaryTree *binaryTree) {
    
    if (isEmptyBinaryTree(binaryTree)) {
        return;
    }
    
    printf("%4d", binaryTree->data);
    preorderBinaryTree(binaryTree->leftChild);
    preorderBinaryTree(binaryTree->rightChild);
    
}

void inorderBinaryTree(BinaryTree *binaryTree) {
    
    if (isEmptyBinaryTree(binaryTree)) {
        return;
    }
    
    inorderBinaryTree(binaryTree->leftChild);
    printf("%4d", binaryTree->data);
    inorderBinaryTree(binaryTree->rightChild);
}

void postorderBinaryTree(BinaryTree *binaryTree) {
    
    if (isEmptyBinaryTree(binaryTree)) {
        return;
    }
    
    postorderBinaryTree(binaryTree->leftChild);
    postorderBinaryTree(binaryTree->rightChild);
    printf("%4d", binaryTree->data);
}
