#ifndef LINKEDSTACK_H_INCLUDED
#define LINKEDSTACK_H_INCLUDED
#include "data.h"

//������
typedef struct{
    struct LSNode * next;           //ָ����
    chess ch;                       //������
}LSNode;

//������ṹ
typedef struct{
    LSNode * top;                //ջ��
    int length;
}LS;

//��ʼ��
void InitLS(LS * ls);

//ѹջ
void PushLS(LS * ls,chess ch);

//��ջ
chess PopLS(LS * ls);

//���ջ
void ClearLS(LS * ls);

//����ջ
void DesLS(LS * ls);


#endif // LINKEDSTACK_H_INCLUDED
