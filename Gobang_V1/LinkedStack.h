#ifndef LINKEDSTACK_H_INCLUDED
#define LINKEDSTACK_H_INCLUDED
#include "data.h"

//链表结点
typedef struct{
    struct LSNode * next;           //指针域
    chess ch;                       //数据域
}LSNode;

//单链表结构
typedef struct{
    LSNode * top;                //栈顶
    int length;
}LS;

//初始化
void InitLS(LS * ls);

//压栈
void PushLS(LS * ls,chess ch);

//弹栈
chess PopLS(LS * ls);

//清空栈
void ClearLS(LS * ls);

//销毁栈
void DesLS(LS * ls);


#endif // LINKEDSTACK_H_INCLUDED
