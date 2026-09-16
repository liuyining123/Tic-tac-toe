#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<math.h>
int board[4][4]; //棋盘

bool check(int i, int j){
    if(i<1 || i>3 || j<1 || j>3){
        return false;
    }
    if(board[i][j] == 1 || board[i][j] == 2){
        return false;
    }
    return true;
}
bool checkWin(int player){
    int i,j;
    //检查行
    for(i=1;i<=3;i++){
        if(board[i][1] == player && board[i][2] == player && board[i][3] == player){
            return true;
        }
    }
    //检查列
    for(j=1;j<=3;j++){
        if(board[1][j] == player && board[2][j] == player && board[3][j] == player){
            return true;
        }
    }
    //检查对角线
    if(board[1][1] == player && board[2][2] == player && board[3][3] == player){
        return true;
    }
    if(board[1][3] == player && board[2][2] == player && board[3][1] == player){
        return true;
    }
    return false;
}
void printBoard(){
    int i,j;
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            if(board[i+1][j+1]==1){
                printf(" X ");
            }else if(board[i+1][j+1]==2){
                printf(" O ");
            }else{
                printf("   ");
            }
            if(j<2){
                printf("|");
            }
        }
        printf("\n");
        if(i<2){
            printf("---|---|---\n");
        }
    }
}
int main(){
    /*实现一个井字棋小游戏*/
    int i,j;
    printf("欢迎来到井字棋小游戏！\n");
    //游戏循环
    while(1){
        //初始化棋盘
        int player = 1; //玩家1先手
        int moves = 0; //记录步数
        for(int i=1;i<=3;i++){
            for(int j=1;j<=3;j++){
                board[i][j] = 0;
            }
        }//清空棋盘
        while(1){
            printBoard();
            printf("玩家%d，请输入你的落子位置（行 列）：",player);
            scanf("%d %d",&i,&j);
            if(!check(i,j)){
                printf("落子位置不合法，请重新输入！\n");
                continue;
            }
            board[i][j] = player;
            moves++;
            if(checkWin(player)){
                printBoard();
                printf("玩家%d获胜！\n",player);
                break;
            }
            if(moves == 9){
                printBoard();
                printf("平局！\n");
                break;
            }
            player = 3 - player; //切换玩家
        }
        printf("是否继续游戏？（y/n）：");
        char c;
        scanf(" %c",&c);
        if(c != 'y' && c != 'Y'){
            break;
        }
    }
    return 0;
}