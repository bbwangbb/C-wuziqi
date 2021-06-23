#ifndef CHESS_H_INCLUDED
#define CHESS_H_INCLUDED
#include "data.h"
#include "LinkedStack.h"
#define CHESSBOARD_X 20
#define CHESSBOARD_Y 20


//初始化棋盘
void InitChessBoard(chess ch[][15]);

//显示棋盘
void ShowChessBoard(chess ch[][15]);

//判断输赢
int LoseWin(chess c,chess ch[][15]);

//主界面
void ShowMenu();
#endif // CHESS_H_INCLUDED
