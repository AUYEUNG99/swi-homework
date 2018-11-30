/*	输出字符矩阵
	WHILE not 游戏结束 DO
		ch＝等待输入
		CASE ch DO
		‘A’:左前进一步，break 
		‘D’:右前进一步，break    
		‘W’:上前进一步，break    
		‘S’:下前进一步，break    
		END CASE
		输出字符矩阵
	END WHILE
	输出 Game Over!!! */
	
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SNAKE_MAX_LENGTH 20
#define SNAKE_HEAD 'H'
#define SNAKE_BODY 'X'
#define BLANK_CELL ' '
#define SNAKE_FOOD '$'
#define WALL_CELL '*'

int snakeX[SNAKE_MAX_LENGTH] = {1,2,3,4,5};//蛇的初始坐标 
int snakeY[SNAKE_MAX_LENGTH] = {1,1,1,1,1};//蛇的初始坐标 
int snakeLength = 5;//蛇的初始长度
int snakeLive = 1;//蛇的生命

char map[12][12] = {
	"**********",
	"*XXXXH   *",
	"*        *",
	"*        *",
	"*        *",
	"*        *",
	"*        *",
	"*        *",
	"*        *",
	"**********"
};
void gameover() {
        if (map[snakeX[snakeLength - 1]][snakeY[snakeLength - 1]] == WALL_CELL || map[snakeX[snakeLength - 1]][snakeY[snakeLength - 1]] == SNAKE_BODY)
		 {
            printf("Game Over!\n");
            snakeLive--;
        }
    }

void drawMap(char map[][12]) {
	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 10; ++j) {
			printf("%c",map[i][j]);
		}
		printf("\n");
	}
}
int main() {
	drawMap(map);
	while(snakeLive) { 
		char ch = getchar();
		if (ch == '\n')
			continue;
		system("cls");
		map[snakeY[0]][snakeX[0]] = BLANK_CELL;//把蛇尾变为空格
        for (int i = 0; i < snakeLength - 1; i++)//蛇身往前移动
        {
            snakeX[i] = snakeX[i + 1];
            snakeY[i] = snakeY[i + 1];
            map[snakeY[i]][snakeX[i]] = SNAKE_BODY;
        }
		switch (ch) {
			case 'w':
            case 'W':snakeY[snakeLength - 1]--;
			break;//蛇头向上转
            case 'a':
            case 'A':snakeX[snakeLength - 1]--;
			break;//蛇头向左转
            case 's':
            case 'S':snakeY[snakeLength - 1]++;
			break;//蛇头向下转
            case 'd':
            case 'D':snakeX[snakeLength - 1]++;
			break;//蛇头向右转
			default:
			break;		
		}
		gameover();
		map[snakeY[snakeLength - 1]][snakeX[snakeLength - 1]] = SNAKE_HEAD;
		drawMap(map); 
	}
}



