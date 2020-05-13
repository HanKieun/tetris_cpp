#include "GameManager.h"

GameManager::GameManager()
{

}

GameManager::~GameManager()
{
}

void GameManager::spawnBlock()
{
	int tempBlock[4][4] = { 0, };

	blockManager.getBlcok(tempBlock);
	Point curPoint = boardManager.SetSpawn(tempBlock);

	blockManager.SetCurPoint(curPoint);

	/*for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++)
		{
			cout << tempBlock[i][j];
		}
		cout << endl;
	}*/
}

void GameManager::InputKey(char key)
{
	Point movePoint;

	switch (key)
	{
	case UP:
	case DOWN:
	case RIGHT:
	case LEFT:
		movePoint = controller.MoveBlockPoint(key);

		Point curPoint = blockManager.GetCurPoint();

		int block[4][4] = { 0, };
		blockManager.getBlcok(block);

		boardManager.DrawBlock(curPoint, movePoint, block);
		blockManager.MoveCurPoint(movePoint);

		break;
	}
}

void GameManager::Run()
{
	boardManager.SetFrame();

	boardManager.DrawBoard();

	spawnBlock();

	int key;
	while (1)
	{
		if (_kbhit())
		{
			key = _getch();
			if (key == 224)
			{
				key = _getch();
				InputKey(key);
			}
		}
	}

	
}