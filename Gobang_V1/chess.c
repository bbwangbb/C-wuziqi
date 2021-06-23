#include "chess.h"

int X = 0,Y = 0;
//��ʼ������
void InitChessBoard(chess ch[][15]){
    int i,j;
    for(i = 0;i < 15;i++){
        for(j = 0;j < 15;j++){
            ch[i][j].x = j;
            ch[i][j].y = i;
            strcpy(ch[i][j].color,"ʮ");     //ѭ����������λ��Ϊʮ
        }
    }
}

//��ʾ����
void ShowChessBoard(chess ch[][15]){
    Clear(0,0,16);          //ÿ�δ�ӡǰ��տ���̨
    SetPosition(0,0);       //���ù��λ��
    int i,j;
    for(i = 0;i < 15;i++){
        for(j = 0;j < 15;j++){
            if(i == Y && j == X){
                SetColor(2,4);//�����ǰλ���ڴ˴����ͱ�ɫ
            }
            printf("%s",ch[i][j].color);
            SetColor(7,0);
        }
        printf("\n");
    }
    printf("1.����\n2.�˳���Ϸ");
}

//�ж���Ӯ
int LoseWin(chess c,chess ch[][15]){
    //����һ���ӣ��ʹ�����ӿ�ʼ������8���������
    int count = 0;
    int i,j;
    //����
    for(i = c.x - 1;i >= 0;i--){
        if(strcmp(c.color,ch[c.y][i].color) == 0 && strcmp(c.color,"ʮ") != 0)
            count++;
        else
            break;
    }
    for(i = c.x + 1;i < 15;i++){
        if(strcmp(c.color,ch[c.y][i].color) == 0 && strcmp(c.color,"ʮ") != 0)
            count++;
        else
            break;
    }
    if(count >= 4)
        return 1;
    //����
    count = 0;
    for(j = c.y + 1;j < 15;j++){
        if(strcmp(c.color,ch[j][c.x].color) == 0 && strcmp(c.color,"ʮ") != 0)
            count++;
        else
            break;
    }
    for(j = c.y - 1;j >= 0;j--){
        if(strcmp(c.color,ch[j][c.x].color) == 0 && strcmp(c.color,"ʮ") != 0)
            count++;
        else
            break;
    }
    if(count >= 4)
        return 1;
    //��б����
    count = 0;
    for(i = c.x - 1,j = c.y - 1;j >= 0 && i >= 0;i--,j--){
        if(strcmp(c.color,ch[j][i].color) == 0 && strcmp(c.color,"ʮ") != 0)
            count++;
        else
            break;
    }
    for(i = c.x + 1,j = c.y + 1;j < 15 && i < 15;i++,j++){
        if(strcmp(c.color,ch[j][i].color) == 0 && strcmp(c.color,"ʮ") != 0)
            count++;
        else
            break;
    }
    if(count >= 4)
        return 1;
    //��б
    count = 0;
    for(i = c.x - 1,j = c.y + 1;j < 15 && i >= 0;i--,j++){
        if(strcmp(c.color,ch[j][i].color) == 0 && strcmp(c.color,"ʮ") != 0)
            count++;
        else
            break;
    }
    for(i = c.x + 1,j = c.y - 1;j >= 0 && i < 15;i++,j--){
        if(strcmp(c.color,ch[j][i].color) == 0 && strcmp(c.color,"ʮ") != 0)
            count++;
        else
            break;
    }
    //printf("%d\t%d\n",c.x,c.y);
    if(count >= 4)
        return 1;
    return 0;
}

//������
void ShowMenu(){
    chess ch[15][15];       //��������
    SetColor(7,0);
    LS ls;                  //��������
    InitLS(&ls);
    chess temp;             //�����洢��ջ����
    InitChessBoard(ch);
    ShowChessBoard(ch);
    int count = 0;          //����һ������������¼���ӵ���ɫ
    char key;
    while(1){
        key = getch();
        //Ĭ�Ϻ�������
        if(key == ' '){         //�ո�������
            PushLS(&ls,ch[Y][X]);//��һ���ͼ�¼һ��
            //������λ���Ѿ��������� - �Ͳ������仯
            if(strcmp(ch[Y][X].color,"��") == 0 || strcmp(ch[Y][X].color,"��") == 0)
                continue;
            if(count % 2 == 0)  //��һ������������¼������ʲô��ɫ��
                strcpy(ch[Y][X].color,"��");//ż��Ϊ����
            else
                strcpy(ch[Y][X].color,"��");//����Ϊ����
            count++;
        }else if(key == '1' || key == '2'){//1������   2���˳���Ϸ
            switch(key){
            case '1':               //����
                temp = PopLS(&ls);  //����Ͱ���һ����Ū�����������λ�������ó�"ʮ"
                strcpy(ch[temp.y][temp.x].color,"ʮ");
                if(count == 0)      //ͬʱ������ҲҪ�ı�
                    count = 0;
                else
                    count--;
                break;
            case '2':
                exit(0);            //�˳���Ϸ - �൱��System.exit(0);
                break;
            }
        }else if(key == 75){    //��
            X--;
        }
        else if(key == 72){     //��
            Y--;
        }
        else if(key == 77){     //��
            X++;
        }
        else if(key == 80){     //��
            Y++;
        }
        if(X > 14) X = 0;
        if(X < 0) X = 14;
        if(Y < 0) Y = 14;
        if(Y > 14) Y = 0;
        ShowChessBoard(ch);     //ÿ������������ʾһ�����̣��͸��˸о���������- -
        if(LoseWin(ch[Y][X],ch) == 1){//��������ı���
            printf("\nGame Over!\n");
            if(strcmp(ch[Y][X].color,"��") == 0)//��ǰ����ʲô��ɫ - ��˭win
                printf("�׷�ʤ��\n");
            else
                printf("�ڷ�ʤ��\n");
            //ѯ���Ƿ����
            printf("�Ƿ�������y/n��:");       //�Ƿ�����
            char c = getch();
            fflush(stdin);                    //��ջ�����
            if(c == 'y'){                     //����Ҳ��һ��
                Clear(0,0,20);                //���
                InitChessBoard(ch);           //��ʼ��
                ShowChessBoard(ch);           //��ʾ����
                count = 0;
            }else
                break;
        }
    }
}




















