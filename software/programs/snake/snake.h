/* snake.h */
/* author:master@aozima.cn */
/* update:Mar 5 2009 10:01 */

#ifndef SNAKE_H_INCLUDED
#define SNAKE_H_INCLUDED

#define snake_length_max                  20  //����߳�
#define snake_length_init                 3   //��ʼ���߳�
#define snake_room_size_hight             8   //���Ӹ� 0-255 ����>8
#define snake_room_size_widht             8   //���ӿ� 0-255 ����>8

typedef struct
{
    unsigned char x[snake_length_max+1];       //����X����ֵ �±�Ϊ����ÿһ�ڵ�����
    unsigned char y[snake_length_max+1];       //ͬ��,�±�0Ϊ���ӵ�ֵ
    unsigned char length_now;                  /* ��ǰ�߳� */
    signed   char addx;
    signed   char addy;
    unsigned char flag;                        //�ߵ�ǰ����
}snake_struct;

extern snake_struct snake;

void snake_init(void);                          /* init snake */
void snake_run_step(void);                      /* run a step */
void snake_key(unsigned char key);              /*            */

#endif // SNAKE_H_INCLUDED
