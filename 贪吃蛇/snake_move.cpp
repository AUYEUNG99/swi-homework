/*	����ַ�����
	WHILE not ��Ϸ���� DO
		ch���ȴ�����
		CASE ch DO
		��A��:��ǰ��һ����break 
		��D��:��ǰ��һ����break    
		��W��:��ǰ��һ����break    
		��S��:��ǰ��һ����break    
		END CASE
		����ַ�����
	END WHILE
	��� Game Over!!! */
	
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SNAKE_MAX_LENGTH 20
#define SNAKE_HEAD 'H'
#define SNAKE_BODY 'X'
#define BLANK_CELL ' '
#define SNAKE_FOOD '$'
#define WALL_CELL '*'

int snakeX[SNAKE_MAX_LENGTH] = {1,2,3,4,5};//�ߵĳ�ʼ���� 
int snakeY[SNAKE_MAX_LENGTH] = {1,1,1,1,1};//�ߵĳ�ʼ���� 
int snakeLength = 5;//�ߵĳ�ʼ����
int snakeLive = 1;//�ߵ�����

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
		map[snakeY[0]][snakeX[0]] = BLANK_CELL;//����β��Ϊ�ո�
        for (int i = 0; i < snakeLength - 1; i++)//������ǰ�ƶ�
        {
            snakeX[i] = snakeX[i + 1];
            snakeY[i] = snakeY[i + 1];
            map[snakeY[i]][snakeX[i]] = SNAKE_BODY;
        }
		switch (ch) {
			case 'w':
            case 'W':snakeY[snakeLength - 1]--;
			break;//��ͷ����ת
            case 'a':
            case 'A':snakeX[snakeLength - 1]--;
			break;//��ͷ����ת
            case 's':
            case 'S':snakeY[snakeLength - 1]++;
			break;//��ͷ����ת
            case 'd':
            case 'D':snakeX[snakeLength - 1]++;
			break;//��ͷ����ת
			default:
			break;		
		}
		gameover();
		map[snakeY[snakeLength - 1]][snakeX[snakeLength - 1]] = SNAKE_HEAD;
		drawMap(map); 
	}
}



