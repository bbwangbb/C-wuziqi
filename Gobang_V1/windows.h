#ifndef WINDOWS_H_INCLUDED
#define WINDOWS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

/* ���ÿ���̨���� */
void SetTitle(char * title);
/* 0-��ɫ, 1-��ɫ,   2-��ɫ,      3-ǳ��ɫ,     4-��ɫ,   5-��ɫ,   6-��ɫ,   7-��ɫ,
 * 8-��ɫ, 9-����ɫ, 10-����ɫ,   11-��ǳ��ɫ   12-����ɫ 13-����ɫ 14-����ɫ 15-����ɫ
 */

/* ����������ɫ */
void SetColor(int ForeColor, int BackGroundColor);

/* �������ֹ�� */
void SetPosition(int x, int y);

/* ���ĳ������ */
void Clear(int x,int y,int rowCount);
#endif // WINDOWS_H_INCLUDED
