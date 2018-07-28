#include <stdio.h>

#include "newSnake.c"

int main() {
	int finished = 0;				/*控制游戏是否结束*/
	int key;						/*接收按键*/
	int count = 0;					/*控制时延*/
	int initialSpeed = 4000;		/*初始速度*/
	int foodCount = FOOD_COUNT;		/*初始的食物数量*/
	int i;

	SNAKE snakeOne = {
		0, 
		5, 
		1,
		MAX_SANKE_LEN, 
		3, 
		{{32, 12}}
	};
	SNAKE snakeTwo = {
		0, 
		5, 
		1,
		MAX_SANKE_LEN, 
		2, 
		{{32, 12}}
	};
	FOOD_POINT *foodPoint;

	clrscr();								/*清屏*/

	drowGameBorder();						/*画游戏边框*/
	dataDisplay(initialSpeed, foodCount, snakeOne, snakeTwo);	/*显示右边的数据*/
	for(i = 0; i < 1625; i++) {
		barrierArray[i] = 0;
	}
	storageBarrier(snakeOne, snakeTwo);		/*把边界，障碍物，蛇身，食物的二维坐标转换为数组的一维下标存起来，分别为1， 2， 3， 4*/
	makeFood(snakeOne, snakeTwo, foodCount, foodPoint);
	
	while(!finished) {
		/*控制按键相关操作*/
		if(bioskey(1)) {
			key = bioskey(0);
			changeKey(key, &finished, &snakeOne, &snakeTwo, &initialSpeed);		
		}

		/*控制蛇的移动相关操作*/
		if(count > initialSpeed) {
			count = 0;
			moveSnake(&snakeOne);
			moveSnake(&snakeTwo);
			checkBarrier(&snakeOne, &snakeTwo, &finished, &foodCount, foodPoint);
			storageBarrier(snakeOne, snakeTwo);
			dataDisplay(initialSpeed, foodCount, snakeOne, snakeTwo);
			if(foodCount <= 0) {
				foodCount = FOOD_COUNT;
				makeFood(snakeOne, snakeTwo, foodCount, foodPoint);
			}
		}
		count++;
	}

	gotoxy(30, 12);
    printf("Game Over!");
    gotoxy(22, 13);
    printf("Press any key to exit...");
    bioskey(0);

	return 0;
}