#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>


void *threaddeal(void *arg){

    int i = *(int *)(arg);
    printf("这是第%d个线程\n",i);
}
int
main()
{
    pthread_t tid1;


    int j;

    int count = 20;
    for(j = 0;j< count;j++){

        int *p = &(j);
        int ret = pthread_create(&tid1,NULL,threaddeal,(void*)p);
        if(ret){
             printf("创建线程失败: %d  %s\n",ret,strerror(ret));
        }else{
           pthread_detach(tid1);// 分离线程，回收线程stack占用的内存
        }
    }


    while(1){
   
}
    return 0;
}
