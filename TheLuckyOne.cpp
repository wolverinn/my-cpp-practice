#include <iostream>
#include <fstream>
#include <ctime>
#include <iomanip>
#include <windows.h>
#include <conio.h>
using namespace std;

#define EXIT_CODE	0x1b
#define SETCOLOR(color)	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),color)
#define MAX_N	100
#define MAX_L	20

char list[MAX_N][MAX_L];
bool selected[MAX_N];

int main()
{
	ifstream file("list.txt");
	
	if( file.is_open() )
	{
		int i = 0;
		while( !file.eof() )
		{
			file.getline(list[i++],MAX_L);
			if( i >= MAX_N )
				break;
		}
		file.close();
		char ch = 0;
		int num = i;
		if( num == 0 )
		{
			cout << "No data!" << endl;
			return 0;
		}
		srand(time(0));
		SETCOLOR(0xc);
		cout << "\n\tChoose The Lucky One!\n";
		SETCOLOR(0xb);
		cout << "\tPress ESC to EXIT!\n"
			 << "\tPress other key to STOP or CONTINUE\n" << endl;
		SETCOLOR(0xa);
		do
		{
			do{ 
				i = rand() % num;
			}while( selected[i] );
			cout << '\t' << setw(16) << left << list[i] << '\r';
			if( _kbhit() )
			{
				cout << endl;
				selected[i] = true;
				ch = _getch();
			}
			Sleep(50);
		}while( ch != EXIT_CODE );
	}
	else
		cout << "Can not open file!" << endl;

	return 0;
}