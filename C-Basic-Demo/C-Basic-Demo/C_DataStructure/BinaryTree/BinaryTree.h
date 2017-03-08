//
//  BinaryTree.h
//  C-Basic-Demo
//
//  Created by HeJeffery on 2017/3/8.
//  Copyright © 2017年 HeJeffery. All rights reserved.
//

#ifndef BinaryTree_h
#define BinaryTree_h

#include <stdio.h>
#include <stdbool.h>

////////////////////////////////////////////////////////////////////////////////////
//                                                                                //
//                                      二叉树                                     //
//                                                                                //
////////////////////////////////////////////////////////////////////////////////////

typedef struct BTNode BinaryTree;

typedef struct BTNode BTNode;

struct BTNode {
    int data;
    BTNode *leftChild;
    BTNode *rightChild;
};

/**
 *  插入元素到二叉树
 *
 *  @param binaryTree BinaryTree地址的地址
 *  @param value 添加的元素
 */
void insertBinaryTree(BinaryTree **binaryTree, int value);

/**
 *  判断是不是空二叉树
 *
 *  @param binaryTree BinaryTree的地址
 *  @return 空二叉树返回true，反之返回false
 */
bool isEmptyBinaryTree(BinaryTree *binaryTree);

/**
 *  计算二叉树的深度
 *
 *  @param binaryTree BinaryTree的地址
 *  @return 返回二叉树的深度
 */
int deepBinaryTree(BinaryTree *binaryTree);

/**
 *  计算二叉树叶结点的个数(没有子结点的结点叫叶结点)
 *
 *  @param binaryTree BinaryTree的地址
 *  @return 返回二叉树叶结点的个数
 */
int leafNodeCount(BinaryTree *binaryTree);

/**
 *  先序遍历
 *
 */
void preorderBinaryTree(BinaryTree *binaryTree);

/**
 *  中序遍历
 *
 */
void inorderBinaryTree(BinaryTree *binaryTree);

/**
 *  后序遍历
 *
 */
void postorderBinaryTree(BinaryTree *binaryTree);

#endif /* BinaryTree_h */
