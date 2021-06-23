#include "LinkedStack.h"

//初始化
void InitLS(LS * ls){
    ls->length = 0;     //将栈长度设为0
    ls->top = NULL;     //栈顶指针设为空
}

//压栈
void PushLS(LS * ls,chess ch){
    //给指针赋空间 - 相当于Java的new感觉
    LSNode * node = (LSNode*)malloc(sizeof(LSNode));
    //将数据传进去
    node->ch = ch;
    node->next = ls->top;
    ls->top = node;     //改变栈顶指针指向
    ls->length++;       //栈长++
}

//弹栈
chess PopLS(LS * ls){
    if(ls->length == 0) return;     //栈长为0就不弹出
    LSNode * node = ls->top;        //因为指针不用需要释放空间 - 用于释放空间
    chess ch = node->ch;
    ls->top = node->next;
    free(node);                     //释放空间
    ls->length--;
    return ch;                      //返回棋子
}

//清空栈
void ClearLS(LS * ls){
    LSNode * node = ls->top;
    LSNode * next;
    while(node){                    //释放栈里的每个指针
        next = node;
        free(node);
        node = next->next;
    }
    ls->length = 0;
    ls->top = NULL;
}

//销毁栈 - 先清空栈再释放头结点
void DesLS(LS * ls){
    ClearLS(ls);
    free(ls);
}






