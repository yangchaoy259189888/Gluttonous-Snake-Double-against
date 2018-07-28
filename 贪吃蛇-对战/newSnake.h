#ifndef _NEW_SNAKE_H_
#define _NEW_SNAKE_H_

#define MAX_SANKE_LEN				100
#define FOOD_COUNT					7

#define MIN_SPEED					6000
#define MAX_SPEED					1000

#define ESC 						0x11b
#define SNAKE_ONE_PgUp				0x4900
#define SNAKE_ONE_PgDn				0x5100
#define SNAKE_TWO_PgUp				0x1372
#define SNAKE_TWO_PgDn				0x2166

#define KEY_SNAKE_ONE_UP			0x4800
#define KEY_SNAKE_ONE_DOWN			0x5000
#define KEY_SNAKE_ONE_LEFT			0x4b00
#define KEY_SNAKE_ONE_RIGHT			0x4d00

#define KEY_SNAKE_TWO_UP			0x1177
#define KEY_SNAKE_TWO_DOWN			0x1f73
#define KEY_SNAKE_TWO_LEFT			0x1e61
#define KEY_SNAKE_TWO_RIGHT			0x2064

typedef struct DELTA_MOVE {
	int deltaCol;
	int deltaRow;
} DELTA_MOVE;

typedef struct SNAKE_BODY {
	int bodyCol;
	int bodyRow;
} SNAKE_BODY;

typedef struct SNAKE {
	int head;
	int len;
	int curLen;
	int maxLen;
	int direct;
	SNAKE_BODY snakeBody[MAX_SANKE_LEN];
} SNAKE;

typedef struct FOOD_POINT {
	int foodCol;
	int foodRow;
} FOOD_POINT;

void moveSnake(SNAKE *snake);
void changeSnakeHeadPoint(SNAKE_BODY *newSnakeHeadPoint, SNAKE_BODY oldSnakeHeadPoint, SNAKE snake);
void changeKey(int key, int *finished, SNAKE *snakeOne, SNAKE *snakeTwo, int *initialSpeed);
void changeSpeed(int key, int *initialSpeed);
void makeFood(SNAKE snakeOne, SNAKE snakeTwo, int foodCount, FOOD_POINT *foodPoint);
void swap(short *a, short *b);
void drowGameBorder();
void dataDisplay(int initialSpeed, int foodCount, SNAKE snakeOne, SNAKE snakeTwo);
void storageBarrier(SNAKE snakeOne, SNAKE snakeTwo);
void checkBarrier(SNAKE *snakeOne, SNAKE *snakeTwo, int *finished, int *foodCount, FOOD_POINT *foodPoint);

#endif