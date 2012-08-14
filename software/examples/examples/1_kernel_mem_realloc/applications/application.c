#include <rtthread.h>

/* 线程TCB和栈*/
struct rt_thread thread1;
char thread1_stack[512];
/* 线程入口*/
void thread1_entry(void* parameter)
{
    int i,j = 1;
    char *ptr[10]; /* 用于放置10个分配内存块的指针*/
    /* 对指针清零*/
    for (i = 0; i <10; i ++) 
        ptr[i] = RT_NULL;
    while(j--)
    {
        for (i = 0; i <10; i++)
        {
        /* 每次分配(1 <<i)大小字节数的内存空间*/
            ptr[i] = rt_malloc(10);
            /* 如果分配成功*/
            if (ptr[i] != RT_NULL)
            {
                rt_kprintf("get memory: 0x%x\n", ptr[i]);
                 rt_realloc(ptr[i],16);
                /* 如果分配成功*/
                if (ptr[i] != RT_NULL)
                {
                    rt_kprintf("memory realloc success!\n");
                    /* 释放内存块*/
                    rt_free(ptr[i]);
                    rt_kprintf("memory free success!\n");
                    ptr[i] = RT_NULL;
                }
            }
        }
    }
}

int rt_application_init()
{
    /* 初始化线程对象*/
    rt_thread_init(&thread1,
    "thread1",
    thread1_entry, RT_NULL,
    &thread1_stack[0], sizeof(thread1_stack),
    10, 100);
    rt_thread_startup(&thread1);
    return 0;
}
