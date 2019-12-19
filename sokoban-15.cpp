#include<iostream>
#include<conio.h>
using namespace std;
char map[7][8];
int man_x=5,man_y=6,opt=1;
int check_map(){
	int s;
	for(int l=2;l<=7;l++)
		if(map[4][l]!='&') s=1;
	if(s==1) return 1;
	else return 0;
}
void show_map(){
	system("cls");
	for(int i=1;i<=7;i++){
		for(int j=1;j<=8;j++){
			if(j==8) cout<<map[i][j]<<endl;
			else cout<<map[i][j];
		}
	}
}
int behind(int t){
	switch(t){
	case 1:{if(map[man_y+1][man_x]=='%') map[man_y+1][man_x]='*';else map[man_y+1][man_x]=' ';break;}
	case 2:{if(map[man_y-1][man_x]=='%') map[man_y-1][man_x]='*';else map[man_y-1][man_x]=' ';break;}
	case 3:{if(map[man_y][man_x+1]=='%')map[man_y][man_x+1]='*';else map[man_y][man_x+1]=' ';break;}
	case 4:{if(map[man_y][man_x-1]=='%') map[man_y][man_x-1]='*';else map[man_y][man_x-1]=' ';break;}
	}
	return 0;
}
int push_check(int t){
	switch(t){
	case 1:{
		if(map[man_y-1][man_x]=='#'){ cout<<"reinput"<<endl;system("pause");return (0);}
		else if(map[man_y-1][man_x]=='@'&&(map[man_y-2][man_x]=='@'||map[man_y-2][man_x]=='#'||map[man_y-2][man_x]=='&')){cout<<"reinput"<<endl;system("pause");return 0;}
		else if(map[man_y-1][man_x]=='&'&&(map[man_y-2][man_x]=='@'||map[man_y-2][man_x]=='#'||map[man_y-2][man_x]=='&')){cout<<"reinput"<<endl;system("pause");return 0;}
		else return 1;
		break;
		   }
	case 2:{
		if(map[man_y+1][man_x]=='#'){ cout<<"reinput"<<endl;system("pause");return (0);}
		else if(map[man_y+1][man_x]=='@'&&(map[man_y+2][man_x]=='@'||map[man_y+2][man_x]=='#'||map[man_y+2][man_x]=='&')){cout<<"reinput"<<endl;system("pause");return 0;}
		else if(map[man_y+1][man_x]=='&'&&(map[man_y+2][man_x]=='@'||map[man_y+2][man_x]=='#'||map[man_y+2][man_x]=='&')){cout<<"reinput"<<endl;system("pause");return 0;}
		else return 1;
		break;
		   }
	case 3:{
		if(map[man_y][man_x-1]=='#'){ cout<<"reinput"<<endl;system("pause");return (0);}
		else if(map[man_y][man_x-1]=='@'&&(map[man_y][man_x-2]=='@'||map[man_y][man_x-2]=='#'||map[man_y][man_x-2]=='&')){cout<<"reinput"<<endl;system("pause");return 0;}
		else if(map[man_y][man_x-1]=='&'&&(map[man_y][man_x-2]=='@'||map[man_y][man_x-2]=='#'||map[man_y][man_x-2]=='&')){cout<<"reinput"<<endl;system("pause");return 0;}
		else return 1;
		break;
		   }
	case 4:{
		if(map[man_y][man_x+1]=='#'){ cout<<"reinput"<<endl;system("pause");return (0);}
		else if(map[man_y][man_x+1]=='@'&&(map[man_y][man_x+2]=='@'||map[man_y][man_x+2]=='#'||map[man_y][man_x+2]=='&')){cout<<"reinput"<<endl;system("pause");return 0;}
		else if(map[man_y][man_x+1]=='&'&&(map[man_y][man_x+2]=='@'||map[man_y][man_x+2]=='#'||map[man_y][man_x+2]=='&')){cout<<"reinput"<<endl;system("pause");return 0;}
		else return 1;
		break;
		   }
	}
}
int push_op(int t){
	switch(t){
	case 1:{
		man_y--;
		opt=1;
		if(map[man_y][man_x]=='@'&&map[man_y-1][man_x]=='*'){ map[man_y-1][man_x]='&';behind(1);}
		if(map[man_y][man_x]=='@'&&map[man_y-1][man_x]==' '){ map[man_y-1][man_x]='@';behind(1);}
		if(map[man_y][man_x]=='&'&&map[man_y-1][man_x]=='*'){ map[man_y-1][man_x]='&';behind(1);opt=0;}
		if(map[man_y][man_x]=='&'&&map[man_y-1][man_x]==' '){ map[man_y-1][man_x]='@';behind(1);opt=0;}
		if(map[man_y][man_x]=='*'){ opt=0;behind(1);}
		if(map[man_y][man_x]==' ') behind(1);
		break;
		   }
	case 2:{
		man_y++;
		opt=1;
		if(map[man_y][man_x]=='@'&&map[man_y+1][man_x]=='*'){ map[man_y+1][man_x]='&';behind(2);}
		if(map[man_y][man_x]=='@'&&map[man_y+1][man_x]==' '){ map[man_y+1][man_x]='@';behind(2);}
		if(map[man_y][man_x]=='&'&&map[man_y+1][man_x]=='*'){ map[man_y+1][man_x]='&';behind(2);opt=0;}
		if(map[man_y][man_x]=='&'&&map[man_y+1][man_x]==' '){ map[man_y+1][man_x]='@';behind(2);opt=0;}
		if(map[man_y][man_x]=='*'){ opt=0;behind(2);}
		if(map[man_y][man_x]==' ') behind(2);
		break;
		   }
	case 3:{
		man_x--;
		opt=1;
		if(map[man_y][man_x]=='@'&&map[man_y][man_x-1]=='*'){ map[man_y][man_x-1]='&';behind(3);}
		if(map[man_y][man_x]=='@'&&map[man_y][man_x-1]==' '){ map[man_y][man_x-1]='@';behind(3);}
		if(map[man_y][man_x]=='&'&&map[man_y][man_x-1]==' '){ map[man_y][man_x-1]='@';behind(3);opt=0;}
		if(map[man_y][man_x]=='&'&&map[man_y][man_x-1]=='*'){ map[man_y][man_x-1]='&';behind(3);opt=0;}
		if(map[man_y][man_x]=='*'){ opt=0;behind(3);}
		if(map[man_y][man_x]==' ') behind(3);
		break;
		   }
	case 4:{
		man_x++;
		opt=1;
		if(map[man_y][man_x]=='@'&&map[man_y][man_x+1]=='*'){ map[man_y][man_x+1]='&';behind(4);}
		if(map[man_y][man_x]=='@'&&map[man_y][man_x+1]==' '){ map[man_y][man_x+1]='@';behind(4);}
		if(map[man_y][man_x]=='&'&&map[man_y][man_x+1]==' '){ map[man_y][man_x+1]='@';behind(4);opt=0;}
		if(map[man_y][man_x]=='&'&&map[man_y][man_x+1]=='*'){ map[man_y][man_x+1]='&';behind(4);opt=0;}
		if(map[man_y][man_x]=='*'){ opt=0;behind(4);}
		if(map[man_y][man_x]==' ') behind(4);
		break;
		   }
	}
	return 0;
}
int reset(){
	man_x=5;man_y=6;opt=1;
	for(int a=1;a<=7;a++){
		for(int b=1;b<=8;b++){
			map[a][b]=' ';
		}
	}
	for(int l=2;l<=7;l++)
		map[4][l]='*';
	map[3][3]='@';map[3][5]='@';map[3][6]='@';
	map[5][3]='@';map[5][4]='@';map[5][6]='@';
	for(int i=1;i<=7;i++){
		for(int j=1;j<=8;j++){
			while(i==1){
				if(j!=1&&j!=8) map[i][j]='#';
				break;
			}
			while(i==2){
				if(j==1||j==2||j==7||j==8) map[i][j]='#';
				break;
			}
			while(i==6){
				if(j!=4&&j!=5) map[i][j]='#';
				break;
			}
			while(i==7){
				if(j!=1&&j!=2&&j!=7&&j!=8) map[i][j]='#';
				break;
			}
		}
	}
	map[3][1]='#';map[3][8]='#';map[4][1]='#';map[4][8]='#';map[5][1]='#';map[5][8]='#';
	return 0;
}
int main(){
	int sum=-1;
	reset();
	char input;
	do{
	switch(input){
	case '0':{reset();break;}
	case 'w':{if(push_check(1))
				 push_op(1);
		      break;
			 }
	case 's':{if(push_check(2))
				 push_op(2);
		      break;
			 }
	case 'a':{if(push_check(3))
				 push_op(3);
		      break;
			 }
	case 'd':{if(push_check(4))
				 push_op(4);
		      break;
			 }
	default:cout<<"reinput"<<endl;
	}
	if(opt==1) map[man_y][man_x]='0';
	else map[man_y][man_x]='%';
	show_map();
	cout<<"0) restart"<<endl;
	sum++;
	input=getch();
	}
	while(check_map());
	cout<<"total steps:"<<sum<<endl;
	return 0;
}
