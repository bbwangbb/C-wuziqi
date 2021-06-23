#include "chess.h"

int X = 0,Y = 0;
//初始化棋盘
void InitChessBoard(chess ch[][15]){
    int i,j;
    for(i = 0;i < 15;i++){
        for(j = 0;j < 15;j++){
            ch[i][j].x = j;
            ch[i][j].y = i;
            strcpy(ch[i][j].color,"十");     //循环设置棋盘位置为十
        }
    }
}

//显示棋盘
void ShowChessBoard(chess ch[][15]){
    Clear(0,0,16);          //每次打印前清空控制台
    SetPosition(0,0);       //设置光标位置
    int i,j;
    for(i = 0;i < 15;i++){
        for(j = 0;j < 15;j++){
            if(i == Y && j == X){
                SetColor(2,4);//如果当前位置在此处，就变色
            }
            printf("%s",ch[i][j].color);
            SetColor(7,0);
        }
        printf("\n");
    }
    printf("1.悔棋\n2.退出游戏");
}

//判断输赢
int LoseWin(chess c,chess ch[][15]){
    //下完一个子，就从这个子开始向他的8个方向遍历
    int count = 0;
    int i,j;
    //横向
    for(i = c.x - 1;i >= 0;i--){
        if(strcmp(c.color,ch[c.y][i].color) == 0 && strcmp(c.color,"十") != 0)
            count++;
        else
            break;
    }
    for(i = c.x + 1;i < 15;i++){
        if(strcmp(c.color,ch[c.y][i].color) == 0 && strcmp(c.color,"十") != 0)
            count++;
        else
            break;
    }
    if(count >= 4)
        return 1;
    //纵向
    count = 0;
    for(j = c.y + 1;j < 15;j++){
        if(strcmp(c.color,ch[j][c.x].color) == 0 && strcmp(c.color,"十") != 0)
            count++;
        else
            break;
    }
    for(j = c.y - 1;j >= 0;j--){
        if(strcmp(c.color,ch[j][c.x].color) == 0 && strcmp(c.color,"十") != 0)
            count++;
        else
            break;
    }
    if(count >= 4)
        return 1;
    //右斜方向
    count = 0;
    for(i = c.x - 1,j = c.y - 1;j >= 0 && i >= 0;i--,j--){
        if(strcmp(c.color,ch[j][i].color) == 0 && strcmp(c.color,"十") != 0)
            count++;
        else
            break;
    }
    for(i = c.x + 1,j = c.y + 1;j < 15 && i < 15;i++,j++){
        if(strcmp(c.color,ch[j][i].color) == 0 && strcmp(c.color,"十") != 0)
            count++;
        else
            break;
    }
    if(count >= 4)
        return 1;
    //左斜
    count = 0;
    for(i = c.x - 1,j = c.y + 1;j < 15 && i >= 0;i--,j++){
        if(strcmp(c.color,ch[j][i].color) == 0 && strcmp(c.color,"十") != 0)
            count++;
        else
            break;
    }
    for(i = c.x + 1,j = c.y - 1;j >= 0 && i < 15;i++,j--){
        if(strcmp(c.color,ch[j][i].color) == 0 && strcmp(c.color,"十") != 0)
            count++;
        else
            break;
    }
    //printf("%d\t%d\n",c.x,c.y);
    if(count >= 4)
        return 1;
    return 0;
}

//主界面
void ShowMenu(){
    chess ch[15][15];       //棋盘数组
    SetColor(7,0);
    LS ls;                  //备好链表
    InitLS(&ls);
    chess temp;             //用来存储弹栈数据
    InitChessBoard(ch);
    ShowChessBoard(ch);
    int count = 0;          //设置一个变量用来记录下子的颜色
    char key;
    while(1){
        key = getch();
        //默认黑子先走
        if(key == ' '){         //空格是下棋
            PushLS(&ls,ch[Y][X]);//下一步就记录一步
            //如果这个位置已经有棋子了 - 就不发生变化
            if(strcmp(ch[Y][X].color,"○") == 0 || strcmp(ch[Y][X].color,"●") == 0)
                continue;
            if(count % 2 == 0)  //用一个计数器来记录下子是什么颜色的
                strcpy(ch[Y][X].color,"○");//偶数为黑子
            else
                strcpy(ch[Y][X].color,"●");//奇数为白子
            count++;
        }else if(key == '1' || key == '2'){//1、悔棋   2、退出游戏
            switch(key){
            case '1':               //悔棋
                temp = PopLS(&ls);  //悔棋就把上一步给弄出来，把这个位置再设置成"十"
                strcpy(ch[temp.y][temp.x].color,"十");
                if(count == 0)      //同时计数器也要改变
                    count = 0;
                else
                    count--;
                break;
            case '2':
                exit(0);            //退出游戏 - 相当于System.exit(0);
                break;
            }
        }else if(key == 75){    //左
            X--;
        }
        else if(key == 72){     //上
            Y--;
        }
        else if(key == 77){     //右
            X++;
        }
        else if(key == 80){     //下
            Y++;
        }
        if(X > 14) X = 0;
        if(X < 0) X = 14;
        if(Y < 0) Y = 14;
        if(Y > 14) Y = 0;
        ShowChessBoard(ch);     //每次下完棋再显示一次棋盘，就给人感觉就下子了- -
        if(LoseWin(ch[Y][X],ch) == 1){//就是上面的遍历
            printf("\nGame Over!\n");
            if(strcmp(ch[Y][X].color,"●") == 0)//当前子是什么颜色 - 就谁win
                printf("白方胜！\n");
            else
                printf("黑方胜！\n");
            //询问是否继续
            printf("是否重来（y/n）:");       //是否重来
            char c = getch();
            fflush(stdin);                    //清空缓冲区
            if(c == 'y'){                     //重来也是一样
                Clear(0,0,20);                //清空
                InitChessBoard(ch);           //初始化
                ShowChessBoard(ch);           //显示棋盘
                count = 0;
            }else
                break;
        }
    }
}




















