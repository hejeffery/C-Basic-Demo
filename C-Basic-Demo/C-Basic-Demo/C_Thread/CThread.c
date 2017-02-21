//
//  CThread.c
//  C-Basic-Demo
//
//  Created by HeJeffery on 2017/2/20.
//  Copyright © 2017年 HeJeffery. All rights reserved.
//

#include "CThread.h"

#include <pthread.h>
#include <unistd.h>

void threadMethod1(void *threadName) {
    
    for (int i = 0; i < 10; i++) {
        printf("%s ----> i = %d\n", (char *)threadName, i);
    }
}

void createThread1() {
    
    char *thread1 = "thread1";
    char *thread2 = "thread2";
    pthread_t pthread1, pthread2;
    pthread_create(&pthread1, NULL, (void *)threadMethod1, (void *)thread1);
    
//    pthread_join(pthread1, NULL);// 等待pthread1完成后，才执行pthread2
    
    pthread_create(&pthread2, NULL, (void *)threadMethod1, (void *)thread2);
    
//    pthread_join(pthread2, NULL);// 等待pthread2完成后，才执行下面的代码
    
    printf("\n主线程的打印\n");
    
    // 睡五秒，否则主线程结束了，子线程就看不到了
    sleep(5);
}

// 多线程访问同一个变量，如果不用线程同步技术，会导致访问的变量出错
int globleNum = 0;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void threadMethod2(void *threadName) {
    
    int temp = 0;
    for (int i = 0; i < 10000; i++) {
        
        // 加锁
        if (pthread_mutex_lock(&mutex) != 0) {
            printf("加锁失败\n");
        }
        
        temp = globleNum;
        temp = temp + 1;
        globleNum = temp;
        
        // 释放锁
        if (pthread_mutex_unlock(&mutex) != 0) {
            printf("释放锁失败\n");
        }
    }
}

void createThread2() {

    char *thread1 = "thread1";
    char *thread2 = "thread2";
    pthread_t pthread1, pthread2;
    pthread_create(&pthread1, NULL, (void *)threadMethod2, (void *)thread1);
    pthread_create(&pthread2, NULL, (void *)threadMethod2, (void *)thread2);
    
    // 睡五秒，否则主线程结束了，子线程就看不到了
    sleep(5);
    
    printf("globleNumber = %d\n", globleNum);
}


