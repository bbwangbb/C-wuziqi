#ifndef WINDOWS_H_INCLUDED
#define WINDOWS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

/* 设置控制台标题 */
void SetTitle(char * title);
/* 0-黑色, 1-蓝色,   2-绿色,      3-浅绿色,     4-红色,   5-紫色,   6-黄色,   7-白色,
 * 8-灰色, 9-淡蓝色, 10-淡绿色,   11-淡浅绿色   12-淡红色 13-淡紫色 14-淡黄色 15-亮白色
 */

/* 设置文字颜色 */
void SetColor(int ForeColor, int BackGroundColor);

/* 设置文字光标 */
void SetPosition(int x, int y);

/* 清空某块区域 */
void Clear(int x,int y,int rowCount);
#endif // WINDOWS_H_INCLUDED
