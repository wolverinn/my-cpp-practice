#include <iostream>
#include <fstream>
#include <iomanip>
#include <ctime>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include<string>
using namespace std;
string map[5][4]={{"»Æ","²Ü","²Ù","ÕÔ"},{"ÖÒ","²Ü","²Ù","ÔÆ"},{"Âí","¹Ø","Óğ","ÕÅ"},{"³¬","z1","z2","·É"},{"z3"," "," ","z4"}};
string mapx[5][4]={{"»Æ","²Ü","²Ù","ÕÔ"},{"ÖÒ","²Ü","²Ù","ÔÆ"},{"Âí","¹Ø","Óğ","ÕÅ"},{"³¬","z1","z2","·É"},{"z3"," "," ","z4"}};
void SaveGame();
void LoadGame();
int GameHelp();
int NewGame();
int opt=1,tx=0,sum=-1;
char input01,input02,command;
extern int option();

int reset(){
	for(int i=0;i<5;i++){
		for(int j=0;j<4;j++){
			map[i][j]=mapx[i][j];
		}
	}
	tx=clock()/1000;
    sum=-1;
	return 0;
}
int show_map(){
	for(int a=0;a<5;a++){
		for(int b=0;b<4;b++){
			if(b==3) cout<<setw(2)<<map[a][b]<<endl;
			else cout<<setw(2)<<map[a][b];
		}
	}
	return 0;
}
int check(){
	if(map[3][1]=="²Ü"&&map[3][2]=="²Ù"&&map[4][1]=="²Ü"&&map[4][2]=="²Ù")
		return 0;
	else return 1;
}
int ShowMenu(){
	system("cls");
	cout<<"0) Exit"<<endl;
	cout << "1) New Game" << endl;
	cout << "2) Load Game" << endl;
	cout << "3) Save Game" << endl;
	cout << "4) Game Help" << endl;
	char command;
	command=getch();
	switch(command){
	case '0':{return 0;}
    case '1':{NewGame();break;}
	case '2':{LoadGame();break;}
	case '3':{SaveGame();return ShowMenu();}
	case'4':{GameHelp();return ShowMenu();}
	default:{cout<<"input again"<<endl;system("pause");break;}
	}
	return 0;
}

int NewGame(){
	while(check()){
		system("cls");
		show_map();
		cout<<"total time:"<<clock()/1000-tx<<"s"<<endl;
		cout << "0) Exit Game" << endl;
		cout<<"1) Restart"<<endl;
		cin>>command;
		switch(command){
		case '0':{system("pause");sum--;return 0;}
		case '1':{reset();sum--;break;}
		default:{cin>>input01;cin>>input02;option();break;}
		}
		sum++;
	}
	cout<<"pass!"<<endl<<"total steps:"<<sum<<endl;
	system("pause");
	ShowMenu();
	return 0;
}
int main(){
	ShowMenu();
	return 0;
}


void SaveGame()
{
	ofstream f("saved_game.txt");
	if( f.is_open())
	{
		for(int i=0;i<5;i++){
			for(int j=0;j<4;j++){
		f << map[i][j] << '\0' << endl;
			}
		}
		f.close();
		cout << "Saved OK!" << endl;
	}
	else
		cout << "Can not open file!" << endl;
	system("pause");
	return;
}

void LoadGame()
{
	ifstream f("saved_game.txt");
	if( f.is_open())
	{
		for(int i=0;i<5;i++){
			for(int j=0;j<4;j++){
		       f >> map[i][j];
		if( f.fail() )
		{ cout<< "Wrong!" <<endl; goto Exit; }
		}
		}
		f.close();
		NewGame();
		return;
	}
	else
		cout << "Can not open file!" << endl;
Exit:
	f.close();
	system("pause");
	return;
}


int GameHelp()
{
	cout << "press w,s,a,d to move" << endl;
	system("pause");
	return 0;
}