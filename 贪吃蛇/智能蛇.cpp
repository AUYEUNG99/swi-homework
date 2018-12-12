#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include<math.h>
#include<Windows.h>
#define SNAKE_MAX_LENGTH 50
#define SNAKE_HEAD 'H'
#define SNAKE_BODY 'X'
#define BLANK_CELL ' '
#define SNAKE_FOOD '$'
#define WALL_CELL '*'

// 在全局变量中用数组movable[4]={“a”,”d”,”w”,”s”} 记录可走的方向，用数组distance[4]={0,0,0,0} 记录离食物的距离

char map[12][13] = {
    "************",
    "*XXXXH     *",
    "*          *",
    "*          *",
    "*          *",
    "*          *",
    "*          *",
    "*          *",
    "*          *",
    "*          *",
    "*          *",
    "************" };
//全局变量：初始状态表
char movable[4] = { 'a', 'd', 'w', 's' };
int distance[4] = { 0 };
int food = 0;//定义开始时食物数量为0
int x = 0, y = 0;//定义食物的坐标（x，y）
int snakex[SNAKE_MAX_LENGTH] = { 5, 4, 3, 2, 1 };//蛇身的横坐标
int snakey[SNAKE_MAX_LENGTH] = { 1, 1, 1, 1, 1 };//蛇身的纵坐标
int lastX = 1, lastY = 1;//表示蛇尾部的坐标
int length = 5;//定义初始长度，在该变量完成蛇长的变化
char wheregonext(int x, int y, int z, int m);
void move(int x, int y);//蛇移动函数
void output(void);//蛇移动效果打印函数
void clear(void);//蛇移动前的蛇图像清空
void printmap(void);//打印
int gameover(void);//判定游戏结束（碰到身子或边界）
void snakefood(void);//用来生成食物
void eatfood(void);//蛇吃食物后身体增长
int main() {
    int i;
    snakefood();
    printmap();
    //打印初始状态图
    char c;
    int a = 0, b = 0;
    while (1)
    {
        snakefood();
        c = wheregonext(snakex[0], snakey[0], x, y);
        Sleep(1000);
        switch (c){//进行移动
        case 'a'://左移时
            a = 1;
            b = 0;
            snakefood();
            move(a, b);
            if (gameover())//判定游戏是否结束
            {
                printf("\nGAME OVER!!!\n");
                Sleep(100);
                return 0;
            }
            else
            {
                system("cls");
                printmap();
            }
            break;
        case 'd'://右移
            b = 1;
            a = 0;
            snakefood();
            move(a, b);
            if (gameover())//判定游戏是否结束
            {
                printf("\nGAME OVER!!!\n");
                Sleep(100);
                return 0;
            }
            else
            {
                system("cls");
                printmap();
            }
            break;
        case 's'://上移
            a = -1;
            b = 0;
            snakefood();
            move(a, b);

            if (gameover())//判定游戏是否结束
            {
                printf("\nGAME OVER!!!\n");
                Sleep(1000);
                return 0;
            }
            else
            {
                system("cls");
                printmap();
            }
            break;
        case 'w'://下移
            b = -1;
            a = 0;
            snakefood();
            move(a, b);
            if (gameover())//判定游戏是否结束
            {
                printf("\nGAME OVER!!!\n");
                Sleep(1000);
                return 0;
            }
            else
            {
                system("cls");
                printmap();
            }

            break;
        }

    }//判定贪吃蛇的移动（通过move函数实现）并通过output函数实现map上的变化


}
// 在全局变量中用数组movable[4]={“a”,”d”,”w”,”s”} 记录可走的方向，用数组distance[4]={0,0,0,0} 记录离食物的距离
char wheregonext(int hx, int hy, int fx, int fy) {// Hx,Hy: 头的位置
    // Fx,Fy：食物的位置
    int p = 0, min = 9999;
    distance[0] = abs(fx - (hx - 1)) + abs(fy - hy);
    distance[1] = abs(fx - (hx + 1)) + abs(fy - hy);
    distance[2] = abs(fx - hx) + abs(fy - (hy - 1));
    distance[3] = abs(fx - hx) + abs(fy - (hy + 1));
    // 分别计算蛇头周边四个位置到食物的距离。H头的位置，F食物位置
    if (distance[0] <= min && (map[hy][hx - 1] == ' ' || map[hy][hx - 1] == '$')) {
            min = distance[0];
            p = 0;
        }
    if (distance[1] <= min && (map[hy][hx + 1] == ' ' || map[hy][hx + 1] == '$')) {
            min = distance[1];
            p = 1;
        }
    if (distance[2] <= min && (map[hy - 1][hx] == ' ' || map[hy - 1][hx] == '$')) {
            min = distance[2];
            p = 2;
        }
    if (distance[3] <= min && (map[hy + 1][hx] == ' ' || map[hy + 1][hx] == '$')) {
            min = distance[3];
            p = 3;
        }
    // 选择distance中存最小距离的下标p，最小距离不能是9999
    min = 9999;
    return movable[p];  // 返回 movable[p]
}

void move(int a, int b){
    int i;
    if (a == 1 && b == 0)
    {
        clear();//清空map
        lastX = snakex[length - 1];
        lastY = snakey[length - 1];//记录当前蛇尾坐标
        for (i = length - 1; i >= 1; i--)
        {
            snakex[i] = snakex[i - 1];
            snakey[i] = snakey[i - 1];//移动
        }
        snakex[0]--;//蛇头移动
        eatfood();//判断是否吃了食物
        output();//移动完成
    }
    if (a == 0 && b == 1)
    {
        clear();
        lastX = snakex[length - 1];
        lastY = snakey[length - 1];
        for (i = length - 1; i >= 1; i--)
        {
            snakex[i] = snakex[i - 1];
            snakey[i] = snakey[i - 1];
        }
        snakex[0]++;
        eatfood();
        output();
    }
    if (a == -1 && b == 0)
    {
        clear();
        lastX = snakex[length - 1];
        lastY = snakey[length - 1];
        for (i = length - 1; i >= 1; i--)
        {
            snakex[i] = snakex[i - 1];
            snakey[i] = snakey[i - 1];
        }
        snakey[0]++;
        eatfood();
        output();
    }
    if (a == 0 && b == -1)
    {
        clear();
        lastX = snakex[length - 1];
        lastY = snakey[length - 1];
        for (i = length - 1; i >= 1; i--)
        {
            snakex[i] = snakex[i - 1];
            snakey[i] = snakey[i - 1];
        }
        snakey[0]--;
        eatfood();
        output();
    }

}

void clear(void){
    int i;
    for (i = 0; i < length; i++)
        map[snakey[i]][snakex[i]] = BLANK_CELL;//将蛇原来位置清空
}
void output(void){
    int i;
    map[snakey[0]][snakex[0]] = SNAKE_HEAD;
    for (i = 1; i < length; i++)
        map[snakey[i]][snakex[i]] = SNAKE_BODY;//蛇移动后的位置

}
void printmap(void){
    printf("\n\n\n\n\n\n\n\n\n\n\n\n");
    int i;
    for (i = 0; i < 12; i++)
    {
        printf("%s\n", map[i]);
    }
    //蛇可以完成移动，并打印
}
int gameover(void){
    int i;
    int fail = 0;
    for (i = 1; i<length; i++)//用来判断是否头碰身子
    {
        if (snakex[0] == snakex[i] && snakey[0] == snakey[i])
            fail = 1;
    }
    if (snakex[0]>10 || snakey[0] > 10 || snakex[0] < 1 || snakey[0] < 1 || fail == 1)//前四个条件为是否触碰边界，后一个条件判断是否头碰身子
        return 1;
    else
        return 0;
}
void snakefood(void){
    srand(time(NULL));

    if (food == 0)
    {
        x = rand() % 10 + 1;
        y = rand() % 10 + 1;
        if (map[y][x] == ' ')//确保在空白位置出现食物
        {
            map[y][x] = SNAKE_FOOD;//在地图可到达位置上随机生成食物
            food++;//确保每次只出现一个食物
        }

    }
}
void eatfood(void){
    if (snakey[0] == y&&snakex[0] == x)//判断蛇是否吃到食物
    {
        length++;//蛇长增加一个
        food = 0;
        snakex[length - 1] = lastX;
        snakey[length - 1] = lastY;
    }
}

