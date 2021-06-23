#include "windows.h"

/* 设置控制台标题 */
void SetTitle(char * title)
{
    SetConsoleTitle(title);
}


/* 0-黑色, 1-蓝色,   2-绿色,      3-浅绿色,     4-红色,   5-紫色,   6-黄色,   7-白色,
 * 8-灰色, 9-淡蓝色, 10-淡绿色,   11-淡浅绿色   12-淡红色 13-淡紫色 14-淡黄色 15-亮白色
 */
/* 设置文字颜色 */
void SetColor(int ForeColor, int BackGroundColor)
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);                    //获取当前窗口句柄
    SetConsoleTextAttribute(handle, ForeColor + BackGroundColor * 0x10);//设置颜色
}

/* 设置文字光标 */
void SetPosition(int x, int y)
{
    COORD cursorPosition;   //光标的坐标
    HANDLE handle;          //当前窗口句柄
    handle = GetStdHandle(STD_OUTPUT_HANDLE);
    cursorPosition.X = x;   //设置x、y坐标
    cursorPosition.Y = y;
    SetConsoleCursorPosition(handle, cursorPosition);
}

/* 清空某块区域 */
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

