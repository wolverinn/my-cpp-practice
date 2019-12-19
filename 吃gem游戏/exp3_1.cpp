#include <iostream>
#include <iomanip>
#include <time.h>
#include <windows.h>
#include <conio.h>
using namespace std;

extern void GameInput();
extern void GameGather();

int main()
{
	GameInput();
	GameGather();
	return 0;
}

void WaitExit()
{
	cout << "Press ESC to return!" << endl;
	int key;
	do
	{
		key = getch();
	}while( key != 0x1b ); // 以Esc作为退出键
}