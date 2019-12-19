#include <iostream>
#include <iomanip>
#include <ctime>
#include <windows.h>
#include <conio.h>
#include "common.h"
using namespace std;

#define	GAME_TIME	5	// seconds

static void CountDown( int seconds )
{
	for( int i = seconds; i >= 1; i-- )
	{
		cout << i << "!            \r";
		Sleep(1000); // 等待1秒
	}
	return;
}
void GameInput()
{
	cout << "You have only "<< GAME_TIME << " seconds to input!" << endl;
	cout << "Are you ready? ";
	system("pause"); // 暂停
	system("cls"); // 清屏
	system("color 0c"); // 红色前景色
	CountDown(3); // 倒计时3秒
	// 开始游戏
	cout << "Go!" << endl;
	system("color 0a"); // 绿色前景色

	int start_tm = clock(), pass_tm = 0, n = 0;
	while( pass_tm < GAME_TIME*100 )
	{
		cout << setw(5) << GAME_TIME*100 - pass_tm << ' '; // 显示剩余时间
		if( kbhit()) // 判断是否有按键按下
		{
			int key = getch(); // 获取按键键值不回显
			if( key > 0x80 ) // 控制按键
			{
				int key2 = getch(); // 获取控制按键的第二键值
				switch( key2 )
				{
					case KEY_UP:	cout << "↑" << ' '; break;
					case KEY_DOWN:	cout << "↓" << ' '; break;
					case KEY_LEFT:	cout << "←" << ' '; break;
					case KEY_RIGHT:	cout << "→" << ' '; break;
					default:		cout << (char)key2 << ' ';
				}
				cout << setw(3) << key << ' ' << key2;
			}
			else
				cout << (char)key << ' ' << setw(3) << key << "    ";
			n++;
		}
		cout << '\r';
		Sleep(10);
		pass_tm = (clock() - start_tm)/10; // 计算已经过的时间
	}
	// 游戏结束
	system("color 0f"); // 恢复前景色
	cout << setw(5) << 0 << ' ' << endl;
	cout << "You hit " << n << " keys!" << endl;
	WaitExit();
	return;
}