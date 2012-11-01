/* snake.c */
/* author:master@aozima.cn */
/* update:Mar 5 2009 10:01 */

#include "snake.h"

snake_struct snake;

void snake_init(void) /* �߳�ʼ�� */
{
    unsigned char i;
    snake.flag = 0x00;

    snake.x[0] = 5;//(snake_romm_size_widht / 2); /* �趨��һ�ζ��ӳ��ֵ�λ�� */
    snake.y[0] = 5;//(snake_room_size_hight / 2); /* Ĭ��Ϊ������             */

    snake.length_now = snake_length_init;     /* ��ʼ����ǰ�߳�           */

    for(i=1;i<snake_length_init+1;i++){snake.y[i] = snake_length_init-i;}
    for(i=snake_room_size_hight;i>snake_length_init;i--){snake.y[i+1] = snake_room_size_hight;}

    for(i=0;i<snake_length_init;i++){snake.x[i+1] = 0;}
    for(;i<snake_room_size_widht;i++){snake.x[i+1] = snake_room_size_widht;}

    snake.addx = 0;
    snake.addy = 0;
}

void snake_run_step(void) /* ������һ�� */
{
    unsigned char i;

    if((snake.addx ==0) & (snake.addy == 0) ){return;}

    /* �ж��Ƿ�Զ��� */
    if( (snake.x[0] == snake.x[1] + snake.addx) && (snake.y[0] == snake.y[1] + snake.addy) )
    {
        snake.length_now++;                                          /* �߳�+1             */
        if(snake.length_now == snake_length_max)                     /* �ж��Ƿ�ͨ��       */
        {
            snake.flag |= (1<<7);                                    /* ����ͨ�ر���       */
            snake.addx = 0;snake.addy = 0;                           /* ���ͨ�ؾ�ֹͣ���� */
        }
        else
        {
            snake.x[0] = snake.x[snake.length_now - 1];
            snake.y[0] = snake.y[snake.length_now - 1];
        }
    }
    for(i=snake.length_now;i>1;i--)
    {
        snake.x[i] = snake.x[i-1];
        snake.y[i] = snake.y[i-1];
    }
    snake.x[1] = snake.x[2] + snake.addx;
    snake.y[1] = snake.y[2] + snake.addy;


    /* �ж�ײǽ */
    if( (snake.x[1] > (snake_room_size_widht - 1)) || (snake.y[1] > (snake_room_size_hight - 1)) )
    {
        snake.addx = 0;snake.addy = 0;
        snake.flag |= (1<<0);
    }

    /* �ж��Ƿ�ײ�Լ� */
    for(i=2;i<snake.length_now;i++)
    {
        if( (snake.x[1] == snake.x[i]) && (snake.y[1] == snake.y[i]) )
        {
            snake.addx = 0;snake.addy = 0;
            snake.flag |= (1<<1);
        }
    }
}

void snake_key(unsigned char key)
{
    if(snake.flag){return;}

    switch(key)
    {
        case 1 : if( (snake.y[1] + 1) != snake.y[2] ){ snake.addx = 0;snake.addy =  1;}break; /* up    */
        case 2 : if( (snake.y[1] - 1) != snake.y[2] ){ snake.addx = 0;snake.addy = -1;}break; /* down  */
        case 3 : if( (snake.x[1] - 1) != snake.x[2] ){ snake.addy = 0;snake.addx = -1;}break; /* left  */
        case 4 : if( (snake.x[1] + 1) != snake.x[2] ){ snake.addy = 0;snake.addx =  1;}break; /* right */
        default:break;
    }
}
/* end file */
