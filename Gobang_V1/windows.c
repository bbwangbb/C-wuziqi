#include "windows.h"

/* ���ÿ���̨���� */
void SetTitle(char * title)
{
    SetConsoleTitle(title);
}


/* 0-��ɫ, 1-��ɫ,   2-��ɫ,      3-ǳ��ɫ,     4-��ɫ,   5-��ɫ,   6-��ɫ,   7-��ɫ,
 * 8-��ɫ, 9-����ɫ, 10-����ɫ,   11-��ǳ��ɫ   12-����ɫ 13-����ɫ 14-����ɫ 15-����ɫ
 */
/* ����������ɫ */
void SetColor(int ForeColor, int BackGroundColor)
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);                    //��ȡ��ǰ���ھ��
    SetConsoleTextAttribute(handle, ForeColor + BackGroundColor * 0x10);//������ɫ
}

/* �������ֹ�� */
void SetPosition(int x, int y)
{
    COORD cursorPosition;   //��������
    HANDLE handle;          //��ǰ���ھ��
    handle = GetStdHandle(STD_OUTPUT_HANDLE);
    cursorPosition.X = x;   //����x��y����
    cursorPosition.Y = y;
    SetConsoleCursorPosition(handle, cursorPosition);
}

/* ���ĳ������ */
void Clear(int x,int y,int rowCount)
{
    int i,j;
    for(i = 0;i < rowCount;i++)
    {
        SetPosition(x,y + i);
        for(j = 0;j < 16;j++)
        {
            printf(" ");
        }
    }
}

