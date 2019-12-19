#include<iostream>
#include<string>
using namespace std;
extern int opt,sum;
extern char input01,input02,command;
extern string map[5][4];
extern string mapx[5][4];
int GY(int a,int b){
	if(map[a][b]=="¹Ø"&&map[a][b+1]=="Óð"&&command=='g'&&input01=='y') return 1;
	else return 0;
}
int HZ(int a,int b){
	if(map[a][b]=="»Æ"&&map[a+1][b]=="ÖÒ"&&command=='h') return 1;
	else return 0;
}
int MC(int a,int b){
	if(map[a][b]=="Âí"&&map[a+1][b]=="³¬"&&command=='m') return 1;
	else return 0;
}
int ZF(int a,int b){
	if(map[a][b]=="ÕÅ"&&map[a+1][b]=="·É"&&command=='z'&&input01=='f') return 1;
	else return 0;
}
int ZY(int a,int b){
	if(map[a][b]=="ÕÔ"&&map[a+1][b]=="ÔÆ"&&command=='z'&&input01=='y') return 1;
	else return 0;
}
char *zn(){
	switch(input01){
	case '1':return "z1";
	case '2':return "z2";
	case '3':return "z3";
	case '4':return "z4";
	default:return "a";
	}
}
int move_1(){
	opt=1;
	for(int a=0;a<5;a++){
			for(int j=0;j<4;j++){
				if(j<3&&map[a][j]==" "&&map[a][j+1]==" "&&GY(a+1,j)){
					map[a][j]="¹Ø";
					map[a][j+1]="Óð";
					map[a+1][j]=" ";
					map[a+1][j+1]=" ";
					opt=0;
					return 0;
				}
				if(a<3&&j<3&&map[a][j]==" "&&map[a][j+1]==" "&&map[a+1][j]=="²Ü"&&map[a+1][j+1]=="²Ù"&&command=='c'){
					map[a][j]="²Ü";
					map[a][j+1]="²Ù";
					map[a+1][j]="²Ü";
					map[a+1][j+1]="²Ù";
					map[a+2][j]=" ";
					map[a+2][j+1]=" ";
					opt=0;
					return 0;
				}
				if(a<3&&map[a][j]==" "&&(ZY(a+1,j)||HZ(a+1,j)||MC(a+1,j)||ZF(a+1,j))){
					map[a][j]=map[a+1][j];
					map[a+1][j]=map[a+2][j];
					map[a+2][j]=" ";
					opt=0;
					return 0;
				}
				if(map[a][j]==" "&&map[a+1][j]==zn()&&command=='z'){
					map[a][j]=map[a+1][j];
					map[a+1][j]=" ";
				    opt=0;
					return 0;
					}
				continue;
			}
	}
	return 0;
}
int move_2(){
	opt=1;
	for(int a=0;a<5;a++){
			for(int j=3;j>=0;j--){
				if(a>0&&map[a][j]==" "&&command=='z'&&map[a-1][j]==zn()){
					map[a][j]=map[a-1][j];
					map[a-1][j]=" ";
				    opt=0;
					return 0;
					}
				if(a>0&&j<3&&map[a][j]==" "&&map[a][j+1]==" "&&GY(a-1,j)){
					map[a][j]="¹Ø";
					map[a][j+1]="Óð";
					map[a-1][j]=" ";
					map[a-1][j+1]=" ";
					opt=0;
					return 0;
				}
				if(a>=2&&j<3&&map[a][j]==" "&&map[a][j+1]==" "&&map[a-1][j]=="²Ü"&&map[a-1][j+1]=="²Ù"&&command=='c'){
					map[a][j]="²Ü";
					map[a][j+1]="²Ù";
					map[a-1][j]="²Ü";
					map[a-1][j+1]="²Ù";
					map[a-2][j]=" ";
					map[a-2][j+1]=" ";
					opt=0;
					return 0;
				}
				if(map[a][j]==" "&&a>=2&&(ZY(a-2,j)||HZ(a-2,j)||MC(a-2,j)||ZF(a-2,j))){
					map[a][j]=map[a-1][j];
					map[a-1][j]=map[a-2][j];
					map[a-2][j]=" ";
					opt=0;
					return 0;
				}
				continue;
			}
	}
	return 0;
}
int move_3(){
	opt=1;
	for(int a=0;a<5;a++){
			for(int j=0;j<3;j++){
				if(map[a][j]==" "&&map[a][j+1]==zn()&&command=='z'){
					map[a][j]=map[a][j+1];
					map[a][j+1]=" ";
				    opt=0;
					return 0;
					}
				if(j<2&&map[a][j]==" "&&GY(a,j+1)){
                    map[a][j]=map[a][j+1];
					map[a][j+1]=map[a][j+2];
					map[a][j+2]=" ";
					opt=0;
					return 0;
				}
				if(a<4&&map[a][j]==" "&&map[a+1][j]==" "&&(HZ(a,j+1)||MC(a,j+1)||ZF(a,j+1)||ZY(a,j+1))){
					map[a][j]=map[a][j+1];
					map[a+1][j]=map[a+1][j+1];
					map[a][j+1]=" ";
					map[a+1][j+1]=" ";
					opt=0;
					return 0;
				}
				if(a<4&&j<2&&map[a][j]==" "&&map[a+1][j]==" "&&map[a][j+1]=="²Ü"&&map[a+1][j+1]=="²Ü"&&command=='c'){
					map[a][j]="²Ü";
					map[a+1][j]="²Ü";
					map[a][j+1]="²Ù";
					map[a+1][j+1]="²Ù";
					map[a][j+2]=" ";
					map[a+1][j+2]=" ";
					opt=0;
					return 0;
				}
				continue;
			}
	}
	return 0;
}
int move_4(){
	opt=1;
	for(int a=0;a<5;a++){
			for(int j=0;j<4;j++){
				if(j>0&&map[a][j]==" "&&map[a][j-1]==zn()&&command=='z'){
					map[a][j]=map[a][j-1];
					map[a][j-1]=" ";
				    opt=0;
					return 0;
					}
				if(j>1&&map[a][j]==" "&&GY(a,j-2)){
                    map[a][j]=map[a][j-1];
					map[a][j-1]=map[a][j-2];
					map[a][j-2]=" ";
					opt=0;
					return 0;
				}
				if(a<4&&j>0&&map[a][j]==" "&&map[a+1][j]==" "&&(HZ(a,j-1)||MC(a,j-1)||ZF(a,j-1)||ZY(a,j-1))){
					map[a][j]=map[a][j-1];
					map[a+1][j]=map[a+1][j-1];
					map[a][j-1]=" ";
					map[a+1][j-1]=" ";
					opt=0;
					return 0;
				} 
				if(a<4&&j>1&&map[a][j]==" "&&j>=2&&map[a+1][j]==" "&&map[a][j-1]=="²Ù"&&map[a+1][j-1]=="²Ù"&&command=='c'){
					map[a][j]="²Ù";
					map[a+1][j]="²Ù";
					map[a][j-1]="²Ü";
					map[a+1][j-1]="²Ü";
					map[a][j-2]=" ";
					map[a+1][j-2]=" ";
					opt=0;
					return 0;
				}
				continue;
			}
	}
	return 0;
}
int option(){
	switch(input02){
	case'w':{move_1();break;}
	case's':{move_2();break;}
	case'a':{move_3();break;}
	case'd':{move_4();break;}
	default:{cout<<"input again"<<endl;system("pause");break;}
	}
	if(opt){ cout<<"unable to move"<<endl;sum--;system("pause");}
	return 0;
}