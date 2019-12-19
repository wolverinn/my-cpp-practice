#include <iostream>
#include <fstream>
#include <iomanip>
#include <ctime>
#include <windows.h>
#include <conio.h>
#include "common.h"
using namespace std;

#define	GAME_TIME	60	// seconds

enum CHOICE
{
	EXIT_GAME = 0,
	NEW_GAME,
	SAVE_GAME,
	LOAD_GAME,
	GAME_TOP,
	GAME_HELP
};

static CHOICE ShowMenu();
static void NewGame();
static void SaveGame();
static void LoadGame();
static void GameTop();
static void GameHelp();

void GameGather()
{
	srand(time(0));
	CHOICE c;
	do
	{
		c = ShowMenu();
		switch( c )
		{
			case EXIT_GAME: break;
			case NEW_GAME: NewGame(); break;
			case SAVE_GAME: SaveGame(); break;
			case LOAD_GAME: LoadGame();	break;
			case GAME_TOP: GameTop(); break;
			case GAME_HELP: GameHelp(); break;
		}
	}while( c != EXIT_GAME );
}

CHOICE ShowMenu()
{
	CHOICE c;
	system("cls");
	cout << "Welcome to Gather!" << endl;
	cout << "0) Exit Game" << endl;
	cout << "1) New Game" << endl;
	cout << "2) Load Game" << endl;
	cout << "3) Save Game" << endl;
	cout << "4) Game Top" << endl;
	cout << "5) Game Help" << endl;
	cout << "Input your choice(0~5):";
	bool input_ok = false; 
	while( !input_ok )
	{
		int num;
		cin >> num;
		if( cin.good() )
		{
			if( num >=0 && num <= 5 )
			{
				CHOICE list[] = { EXIT_GAME, NEW_GAME, LOAD_GAME, SAVE_GAME, GAME_TOP, GAME_HELP };
				c = list[num];
				input_ok = true;
			}
			else
				cout << "Out of range(0~5)! Please input again:";
		}
		else
		{
			cin.clear();
			cin.sync();
			cout << "Wrong input! Please input again:";
		}
	}
	return c;
}

static int player_x, player_y, gem_x, gem_y, gem_num, pass_time;
const int width = 25, height = 12;

static void GeneratePosition( int &x, int &y, int ex_x = -1, int ex_y = -1 )
{
	do
	{
		x = rand() % (width-2)+1;
		y = rand() % (height-2)+1;
	}while( x == ex_x && y ==  ex_y );
	return;
}

static void ShowMap()
{
	int i, j;
	system("cls");
	for( i=0; i<height; i++ )
	{
		cout << '#';
		for( j=1; j<width-1; j++ )
		{
			if( i==0 || i==height-1 )
				cout << '#';
			else
			{
				if( j == player_x && i == player_y )
					cout << 'O';
				else if( j == gem_x && i == gem_y )
					cout << '*';
				else
					cout << ' ';
			}
		}
		cout << '#' << endl;
	}
	return;
}

static void BeginGame()
{
	bool quit = false, update = true;
	int total_time = GAME_TIME*100, start_tm = clock()- pass_time*10;
	while(!quit)
	{
		if( update ) ShowMap();
		pass_time = (clock() - start_tm)/10;
		if( pass_time < total_time )
			cout << "Left Time:" << setw(5) << total_time - pass_time <<" Gathered GEMS:" << gem_num << '\r';
		else
		{
			cout << "Left Time:" << setw(5) << 0 <<" Gathered GEMS:" << gem_num << endl;
			cout << "Game is over!" << endl;
			quit = true;
			break;
		}
		update = false;
		Sleep(10);
		if( kbhit() )
		{
			int op = getch();
			switch( op )
			{
				case 0xe0:
					op = getch();
					switch( op )
					{
						case KEY_UP: player_y--; break;
						case KEY_DOWN: player_y++; break;
						case KEY_LEFT: player_x--; break;
						case KEY_RIGHT: player_x++; break;
						default: break;
					}
					
					if( player_x <= 0 ) 
						player_x = 1;
					else if( player_x >= width-1 ) 
						player_x = width - 2;
					else 
						update = true;

					if( player_y <= 0 ) 
						player_y = 1;
					else if( player_y >= height-1 ) 
						player_y = height - 2;
					else 
						update = true;
					
					if( player_x == gem_x && player_y == gem_y )
					{
						GeneratePosition( gem_x, gem_y, player_x, player_y );
						gem_num++;
					}
					break;
				case 0x1b: return;
				default: break;
			}
		}
	}
	WaitExit();
	return;
}

void NewGame()
{
	GeneratePosition( player_x, player_y );
	GeneratePosition( gem_x, gem_y );
	gem_num = 0;
	pass_time = 0;
	BeginGame();
}

void SaveGame()
{
	ofstream f("saved_game.txt");
	if( f.is_open())
	{
		f << player_x << '\t' << player_y << '\t'
		  << gem_x << '\t'<< gem_y << '\t' << gem_num << '\t'
		  << pass_time << endl;
		f.close();
		cout << "Saved OK!" << endl;
	}
	else
		cout << "Can not open file!" << endl;
	WaitExit();
	return;
}

void LoadGame()
{
	ifstream f("saved_game.txt");
	if( f.is_open())
	{
		f >> player_x;
		if( f.fail() || player_x <= 0 || player_x >= width-1 )
		{ cout << "Wrong player_x!" << endl; goto Exit; }
		f >> player_y;
		if( f.fail() || player_y <= 0 || player_y >= height-1 ) 
		{ cout << "Wrong player_y!" << endl; goto Exit; }
		f >> gem_x;
		if( f.fail() || gem_x <= 0 || gem_x >= width-1 ) 
		{ cout << "Wrong gem_x!" << endl; goto Exit; }
		f >> gem_y;
		if( f.fail() || gem_y <= 0 || player_y >= height-1 ) 
		{ cout << "Wrong gem_y!" << endl; goto Exit; }
		f >> gem_num;
		if( f.fail() || gem_num < 0 ) 
		{ cout << "Wrong gem_num!" << endl; goto Exit; }
		f >> pass_time;
		if( f.fail() || pass_time < 0 || pass_time > GAME_TIME*100 ) 
		{ cout << "Wrong pass_time!" << endl; goto Exit; }
		f.close();
		BeginGame();
		return;
	}
	else
		cout << "Can not open file!" << endl;
Exit:
	f.close();
	WaitExit();
	return;
}

void GameTop()
{
	cout << "Game Top is in design" << endl;
	system("pause");
	return;
}

void GameHelp()
{
	cout << "Game Help is in design" << endl;
	system("pause");
	return;
}
