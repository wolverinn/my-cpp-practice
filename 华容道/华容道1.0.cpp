
#include<iostream>
#include<iomanip>
using namespace std;
void move(int a[5][4],char b,char c){
	int i,j;
	bool k;
	switch(b){
	case '1':
		switch(c){
		case 'x':
			k=false;
			for(i=0;i<5;i++){
				for(j=0;j<4;j++) {if(a[i][j]==7){
										k=true;
										if(a[i+1][j]==0){
										a[i+1][j]=7;
										a[i][j]=0;
										break;}
										else {cout<<"不可移动"<<endl;
											break;}
				}
				}if(k)break;
			}break;
		case 's':
			k=false;
			for(i=0;i<5;i++){
				for(j=0;j<4;j++) {if(a[i][j]==7){
										k=true;
										if(a[i-1][j]==0){
										a[i-1][j]=7;
										a[i][j]=0;
										break;}
										else {cout<<"不可移动"<<endl;
											break;}
				}
				}if(k)break;
			}break;
		case 'z':
			k=false;
			for(i=0;i<5;i++){
				for(j=0;j<4;j++) {if(a[i][j]==7){
										k=true;
										if(a[i][j-1]==0){
										a[i][j-1]=7;
										a[i][j]=0;
										break;}
										else {cout<<"不可移动"<<endl;
											break;}
				}
				}if(k)break;
			}break;
		case 'y':
			k=false;
			for(i=0;i<5;i++){
				for(j=0;j<4;j++) {if(a[i][j]==7){
										k=true;
										if(a[i][j+1]==0){
										a[i][j+1]=7;
										a[i][j]=0;
										break;}
										else {cout<<"不可移动"<<endl;
											break;}
				}
				}if(k)break;
			}
		}break;
		case '2':
		switch(c){
		case 'x':
			k=false;
			for(i=0;i<5;i++){
				for(j=0;j<4;j++) {if(a[i][j]==8){
										k=true;
										if(a[i+1][j]==0){
										a[i+1][j]=8;
										a[i][j]=0;
										break;}
										else {cout<<"不可移动"<<endl;
											break;}
				}
				}if(k)break;
			}break;
		case 's':
			k=false;
			for(i=0;i<5;i++){
				for(j=0;j<4;j++) {if(a[i][j]==8){
										k=true;
										if(a[i-1][j]==0){
										a[i-1][j]=8;
										a[i][j]=0;
										break;}
										else {cout<<"不可移动"<<endl;
											break;}
				}
				}if(k)break;
			}break;
		case 'z':
			k=false;
			for(i=0;i<5;i++){
				for(j=0;j<4;j++) {if(a[i][j]==8){
										k=true;
										if(a[i][j-1]==0){
										a[i][j-1]=8;
										a[i][j]=0;
										break;}
										else {cout<<"不可移动"<<endl;
											break;}
				}
				}if(k)break;
			}break;
		case 'y':
			k=false;
			for(i=0;i<5;i++){
				for(j=0;j<4;j++) {if(a[i][j]==8){
										k=true;
										if(a[i][j+1]==0){
										a[i][j+1]=8;
										a[i][j]=0;
										break;}
										else {cout<<"不可移动"<<endl;
											break;}
				}
				}if(k)break;
			}
		}break;
		case '3':
		switch(c){
		case 'x':
			k=false;
			for(i=0;i<5;i++){
				for(j=0;j<4;j++) {if(a[i][j]==9){
										k=true;
										if(a[i+1][j]==0){
										a[i+1][j]=9;
										a[i][j]=0;
										break;}
										else {cout<<"不可移动"<<endl;
											break;}
				}
				}if(k)break;
			}break;
		case 's':
			k=false;
			for(i=0;i<5;i++){
				for(j=0;j<4;j++) {if(a[i][j]==9){
										k=true;
										if(a[i-1][j]==0){
										a[i-1][j]=9;
										a[i][j]=0;
										break;}
										else {cout<<"不可移动"<<endl;
											break;}
				}
				}if(k)break;
			}break;
		case 'z':
			k=false;
			for(i=0;i<5;i++){
				for(j=0;j<4;j++) {if(a[i][j]==9){
										k=true;
										if(a[i][j-1]==0){
										a[i][j-1]=9;
										a[i][j]=0;
										break;}
										else {cout<<"不可移动"<<endl;
											break;}
				}
				}if(k)break;
			}break;
		case 'y':
			k=false;
			for(i=0;i<5;i++){
				for(j=0;j<4;j++) {if(a[i][j]==9){
										k=true;
										if(a[i][j+1]==0){
										a[i][j+1]=9;
										a[i][j]=0;
										break;}
										else {cout<<"不可移动"<<endl;
											break;}
				}
				}if(k)break;
			}
		}break;
		case '4':
		switch(c){
		case 'x':
			k=false;
			for(i=0;i<5;i++){
				for(j=0;j<4;j++) {if(a[i][j]==10){
										k=true;
										if(a[i+1][j]==0){
										a[i+1][j]=10;
										a[i][j]=0;
										break;}
										else {cout<<"不可移动"<<endl;
											break;}
				}
				}if(k)break;
			}break;
		case 's':
			k=false;
			for(i=0;i<5;i++){
				for(j=0;j<4;j++) {if(a[i][j]==10){
										k=true;
										if(a[i-1][j]==0){
										a[i-1][j]=10;
										a[i][j]=0;
										break;}
										else {cout<<"不可移动"<<endl;
											break;}
				}
				}if(k)break;
			}break;
		case 'z':
			k=false;
			for(i=0;i<5;i++){
				for(j=0;j<4;j++) {if(a[i][j]==10){
										k=true;
										if(a[i][j-1]==0){
										a[i][j-1]=10;
										a[i][j]=0;
										break;}
										else {cout<<"不可移动"<<endl;
											break;}
				}
				}if(k)break;
			}break;
		case 'y':
			k=false;
			for(i=0;i<5;i++){
				for(j=0;j<4;j++) {if(a[i][j]==10){
										k=true;
										if(a[i][j+1]==0){
										a[i][j+1]=10;
										a[i][j]=0;
										break;}
										else {cout<<"不可移动"<<endl;
											break;}
				}
				}if(k)break;
			}
		}break;
		case 'c':
		switch(c){
		case 'x':
			k=false;
			for(i=0;i<5;i++){
				for(j=0;j<4;j++) {if(a[i][j]==1){
										k=true;
										if(a[i+2][j]==0&&a[i+2][j+1]==0){
										a[i+2][j]=a[i+2][j+1]=1;
										a[i][j]=a[i][j+1]=0;
										break;}
										else {cout<<"不可移动"<<endl;
											break;}
				}
				}if(k)break;
			}break;
		case 's':
			k=false;
			for(i=0;i<5;i++){
				for(j=0;j<4;j++) {if(a[i][j]==1){
										k=true;
										if(a[i-1][j]==0&&a[i-1][j+1]==0){
										a[i-1][j]=a[i-1][j+1]=1;
										a[i+1][j]=a[i+1][j+1]=0;
										break;}
										else {cout<<"不可移动"<<endl;
											break;}
				}
				}if(k)break;
			}break;
		case 'z':
			k=false;
			for(i=0;i<5;i++){
				for(j=0;j<4;j++) {if(a[i][j]==1){
										k=true;
										if(a[i][j-1]==0&&a[i+1][j-1]==0){
										a[i][j-1]=a[i+1][j-1]=1;
										a[i][j+1]=a[i+1][j+1]=0;
										break;}
										else {cout<<"不可移动"<<endl;
											break;}
				}
				}if(k)break;
			}break;
		case 'y':
			k=false;
			for(i=0;i<5;i++){
				for(j=0;j<4;j++) {if(a[i][j]==1){
										k=true;
										if(a[i][j+2]==0&&a[i+1][j+2]==0){
										a[i][j+2]=a[i+1][j+2]=1;
										a[i][j]=a[i+1][j]=0;
										break;}
										else {cout<<"不可移动"<<endl;
											break;}
				}
				}if(k)break;
			}
		}break;
		case 'm':
		switch(c){
		case 'x':
			k=false;
			for(i=0;i<5;i++){
				for(j=0;j<4;j++) {if(a[i][j]==2){
										k=true;
										if(a[i+2][j]==0){
										a[i+2][j]=2;
										a[i][j]=0;
										break;}
										else {cout<<"不可移动"<<endl;
											break;}
				}
				}if(k)break;
			}break;
		case 's':
			k=false;
			for(i=0;i<5;i++){
				for(j=0;j<4;j++) {if(a[i][j]==2){
										k=true;
										if(a[i-1][j]==0){
										a[i-1][j]=2;
										a[i+1][j]=0;
										break;}
										else {cout<<"不可移动"<<endl;
											break;}
				}
				}if(k)break;
			}break;
		case 'z':
			k=false;
			for(i=0;i<5;i++){
				for(j=0;j<4;j++) {if(a[i][j]==2){
										k=true;
										if(a[i][j-1]==0&&a[i+1][j-1]==0){
										a[i][j-1]=a[i+1][j-1]=2;
										a[i][j]=a[i+1][j]=0;
										break;}
										else {cout<<"不可移动"<<endl;
											break;}
				}
				}if(k)break;
			}break;
		case 'y':
			k=false;
			for(i=0;i<5;i++){
				for(j=0;j<4;j++) {if(a[i][j]==2){
										k=true;
										if(a[i][j+1]==0&&a[i+1][j+1]==0){
										a[i][j+1]=a[i+1][j+1]=2;
										a[i][j]=a[i+1][j]=0;
										break;}
										else {cout<<"不可移动"<<endl;
											break;}
				}
				}if(k)break;
			}
		}break;
		case 'y':
		switch(c){
		case 'x':
			k=false;
			for(i=0;i<5;i++){
				for(j=0;j<4;j++) {if(a[i][j]==3){
										k=true;
										if(a[i+2][j]==0){
										a[i+2][j]=3;
										a[i][j]=0;
										break;}
										else {cout<<"不可移动"<<endl;
											break;}
				}
				}if(k)break;
			}break;
		case 's':
			k=false;
			for(i=0;i<5;i++){
				for(j=0;j<4;j++) {if(a[i][j]==3){
										k=true;
										if(a[i-1][j]==0){
										a[i-1][j]=3;
										a[i+1][j]=0;
										break;}
										else {cout<<"不可移动"<<endl;
											break;}
				}
				}if(k)break;
			}break;
		case 'z':
			k=false;
			for(i=0;i<5;i++){
				for(j=0;j<4;j++) {if(a[i][j]==3){
										k=true;
										if(a[i][j-1]==0&&a[i+1][j-1]==0){
										a[i][j-1]=a[i+1][j-1]=3;
										a[i][j]=a[i+1][j]=0;
										break;}
										else {cout<<"不可移动"<<endl;
											break;}
				}
				}if(k)break;
			}break;
		case 'y':
			k=false;
			for(i=0;i<5;i++){
				for(j=0;j<4;j++) {if(a[i][j]==3){
										k=true;
										if(a[i][j+1]==0&&a[i+1][j+1]==0){
										a[i][j+1]=a[i+1][j+1]=3;
										a[i][j]=a[i+1][j]=0;
										break;}
										else {cout<<"不可移动"<<endl;
											break;}
				}
				}if(k)break;
			}
		}break;
		case 'f':
		switch(c){
		case 'x':
			k=false;
			for(i=0;i<5;i++){
				for(j=0;j<4;j++) {if(a[i][j]==4){
										k=true;
										if(a[i+2][j]==0){
										a[i+2][j]=4;
										a[i][j]=0;
										break;}
										else {cout<<"不可移动"<<endl;
											break;}
				}
				}if(k)break;
			}break;
		case 's':
			k=false;
			for(i=0;i<5;i++){
				for(j=0;j<4;j++) {if(a[i][j]==4){
										k=true;
										if(a[i-1][j]==0){
										a[i-1][j]=4;
										a[i+1][j]=0;
										break;}
										else {cout<<"不可移动"<<endl;
											break;}
				}
				}if(k)break;
			}break;
		case 'z':
			k=false;
			for(i=0;i<5;i++){
				for(j=0;j<4;j++) {if(a[i][j]==4){
										k=true;
										if(a[i][j-1]==0&&a[i+1][j-1]==0){
										a[i][j-1]=a[i+1][j-1]=4;
										a[i][j]=a[i+1][j]=0;
										break;}
										else {cout<<"不可移动"<<endl;
											break;}
				}
				}if(k)break;
			}break;
		case 'y':
			k=false;
			for(i=0;i<5;i++){
				for(j=0;j<4;j++) {if(a[i][j]==4){
										k=true;
										if(a[i][j+1]==0&&a[i+1][j+1]==0){
										a[i][j+1]=a[i+1][j+1]=4;
										a[i][j]=a[i+1][j]=0;
										break;}
										else {cout<<"不可移动"<<endl;
											break;}
				}
				}if(k)break;
			}
		}break;
		case 'h':
		switch(c){
		case 'x':
			k=false;
			for(i=0;i<5;i++){
				for(j=0;j<4;j++) {if(a[i][j]==5){
										k=true;
										if(a[i+2][j]==0){
										a[i+2][j]=5;
										a[i][j]=0;
										break;}
										else {cout<<"不可移动"<<endl;
											break;}
				}
				}if(k)break;
			}break;
		case 's':
			k=false;
			for(i=0;i<5;i++){
				for(j=0;j<4;j++) {if(a[i][j]==5){
										k=true;
										if(a[i-1][j]==0){
										a[i-1][j]=5;
										a[i+1][j]=0;
										break;}
										else {cout<<"不可移动"<<endl;
											break;}
				}
				}if(k)break;
			}break;
		case 'z':
			k=false;
			for(i=0;i<5;i++){
				for(j=0;j<4;j++) {if(a[i][j]==5){
										k=true;
										if(a[i][j-1]==0&&a[i+1][j-1]==0){
										a[i][j-1]=a[i+1][j-1]=5;
										a[i][j]=a[i+1][j]=0;
										break;}
										else {cout<<"不可移动"<<endl;
											break;}
				}
				}if(k)break;
			}break;
		case 'y':
			k=false;
			for(i=0;i<5;i++){
				for(j=0;j<4;j++) {if(a[i][j]==5){
										k=true;
										if(a[i][j+1]==0&&a[i+1][j+1]==0){
										a[i][j+1]=a[i+1][j+1]=5;
										a[i][j]=a[i+1][j]=0;
										break;}
										else {cout<<"不可移动"<<endl;
											break;}
				}
				}if(k)break;
			}
		}break;
		case 'g':
		switch(c){
		case 'x':
			k=false;
			for(i=0;i<5;i++){
				for(j=0;j<4;j++) {if(a[i][j]==6){
										k=true;
										if(a[i+1][j]==0&&a[i+1][j+1]==0){
										a[i+1][j]=a[i+1][j+1]=6;
										a[i][j]=a[i][j+1]=0;
										break;}
										else {cout<<"不可移动"<<endl;
											break;}
				}
				}if(k)break;
			}break;
		case 's':
			k=false;
			for(i=0;i<5;i++){
				for(j=0;j<4;j++) {if(a[i][j]==6){
										k=true;
										if(a[i-1][j]==0&&a[i-1][j+1]==0){
										a[i-1][j]=a[i-1][j+1]=6;
										a[i][j]=a[i][j+1]=0;
										break;}
										else {cout<<"不可移动"<<endl;
											break;}
				}
				}if(k)break;
			}break;
		case 'z':
			k=false;
			for(i=0;i<5;i++){
				for(j=0;j<4;j++) {if(a[i][j]==6){
										k=true;
										if(a[i][j-1]==0){
										a[i][j-1]=6;
										a[i][j+1]=0;
										break;}
										else {cout<<"不可移动"<<endl;
											break;}
				}
				}if(k)break;
			}break;
		case 'y':
			k=false;
			for(i=0;i<5;i++){
				for(j=0;j<4;j++) {if(a[i][j]==6){
										k=true;
										if(a[i][j+2]==0){
										a[i][j+2]=6;
										a[i][j]=0;
										break;}
										else {cout<<"不可移动"<<endl;
											break;}
				}
				}if(k)break;
			}
		}break;
	}
}
void xianshi(int a[5][4]){
	int i,j,huanhang=0;
	for(i=0;i<5;i++){
		for(j=0;j<4;j++){
			switch(a[i][j]){
			case 1:cout<<"曹操  ";break;
			case 2:cout<<"马超  ";break;
			case 3:cout<<"赵云  ";break;
			case 4:cout<<"张飞  ";break;
			case 5:cout<<"黄忠  ";break;
			case 6:cout<<"关羽  ";break;
			case 7:cout<<"兵一  ";break;
			case 8:cout<<"兵二  ";break;
			case 9:cout<<"兵三  ";break;
			case 10:cout<<"兵四  ";break;
			default:cout<<"      ";}
			huanhang++;
			if (huanhang%4==0) cout<<endl;
		}
	}
}
int main(){
	int qipan[5][4]={2,1,1,3,2,1,1,3,4,6,6,5,4,7,8,5,9,0,0,10};
	char renwu,yidong;
	xianshi(qipan);
	do{
		cout<<"请输入人物及移动方向"<<endl;
		cin>>renwu>>yidong;
		move(qipan,renwu,yidong);
		xianshi(qipan);}
	while(qipan[4][1]!=1||qipan[4][2]!=1);
		cout<<"恭喜你成功了！"<<endl;
	return 0;
}
