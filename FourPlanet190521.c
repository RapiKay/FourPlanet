//오락실을 들어가거나 오락실에서 게임을 할때 (입장료/게임비용)을 냄(태욱이 아이디어) 

#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <conio.h>
#include <math.h>

#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80
#define ESC 27
#define ENTER 13
#define size 15

#define CRT_SECURE_NO_WARNINGS
#define MAP_ADJ_X 10
#define MAP_ADJ_Y 5
#define MAIN_X 11


unsigned int choice, i, j, value,  bet, money = 100;
char yesno;
typedef enum { NOCURSOR, SOLIDCURSOR, NORMALCURSOR } CURSOR_TYPE;
int plate[size+1][size+1]={0}; //흑은 1 백은 2 없으면 0 


//유틸 함수  
void save_money(){
	FILE *file = fopen("money.dat","wt");
		if(file==0){
			gotoxy(0,0); 
        	printf("FILE ERROR: SYSTEM CANNOT WRITE BEST SCORE ON \"MONEY.TXT\"");
		}
		else{
			fprintf(file,"%d", money);
        	fclose(file);
		}
} 

void remove_scrollbar(){
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO info;
    GetConsoleScreenBufferInfo(handle, &info);
    COORD new_size =
    {
        info.srWindow.Right - info.srWindow.Left + 1,
        info.srWindow.Bottom - info.srWindow.Top + 1
    };
    SetConsoleScreenBufferSize(handle, new_size);
}

void setcolor(int Tcolor, int Bcolor){
	HANDLE hc = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hc, (Bcolor<<4)|Tcolor);
}

void gotoxy(int x,int y) { //모니터상의 x,y 좌표로 이동시키는 함수 
    COORD pos={x,y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}

void setcursortype(CURSOR_TYPE c){ //커서 표시를 바꿔주는 함수  
     CONSOLE_CURSOR_INFO CurInfo;
 
     switch (c) {
     case NOCURSOR:
          CurInfo.dwSize=1;
          CurInfo.bVisible=FALSE;
          break;
     case SOLIDCURSOR:
          CurInfo.dwSize=100;
          CurInfo.bVisible=TRUE;
          break;
     case NORMALCURSOR:
          CurInfo.dwSize=20;
          CurInfo.bVisible=TRUE;
          break;
     }
     SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&CurInfo);
}

void intswap(int *x, int *y){
	int tmp;
	tmp=*x;
	*x=*y;
	*y=tmp;
}

void print_current_money(){
		printf("\t\t\t\t\t┌──────────────────────────────┐ \n");
		printf("\t\t\t\t\t│    현재 남은 돈 : %10d$│ \n", money);
		printf("\t\t\t\t\t└──────────────────────────────┘ \n");
	
}
void save_money(); 
//숫자 

prt1(){
	
	printf("                           ■■■■■■                                                 \n");
	printf("                         ■■■■■■■                                                 \n");
	printf("                       ■■■■■■■■                                                 \n");
	printf("                     ■■■■■■■■■                                                 \n");
	printf("                               ■■■■                                                 \n");
	printf("                               ■■■■                                                 \n");
	printf("                               ■■■■                                                 \n");
	printf("                               ■■■■                                                 \n");
	printf("                               ■■■■                                                 \n");
	printf("                               ■■■■                                                 \n");
	printf("                               ■■■■                                                 \n");
	printf("                               ■■■■                                                 \n");
	printf("                               ■■■■                                                 \n");
	printf("                               ■■■■                                                 \n");
	printf("                               ■■■■                                                 \n");
	printf("                               ■■■■                                                 \n");
	printf("                               ■■■■                                                 \n");
	printf("                               ■■■■                                                 \n");
	printf("                               ■■■■                                                 \n");
	printf("                               ■■■■                                                 \n");
	printf("                               ■■■■                                                 \n");
	printf("               ■■■■■■■■■■■■■■■■■■■■                                 \n");
	printf("               ■■■■■■■■■■■■■■■■■■■■                                 \n");
	printf("               ■■■■■■■■■■■■■■■■■■■■                                 \n");
	printf("               ■■■■■■■■■■■■■■■■■■■■                                 \n");
	setcolor(7,0);

}
prt2(){
	printf("               ■■■■■■■■■■■■■■■■■■■■                                 \n");
	printf("               ■■■■■■■■■■■■■■■■■■■■                                 \n");
	printf("               ■■■■■■■■■■■■■■■■■■■■                                 \n");
	printf("               ■■■■■■■■■■■■■■■■■■■■                                 \n");
	printf("                                               ■■■■                                 \n");
	printf("                                               ■■■■                                 \n");
	printf("                                               ■■■■                                 \n");
	printf("                                               ■■■■                                 \n");
	printf("                                               ■■■■                                 \n");
	printf("                                               ■■■■                                 \n");
	printf("               ■■■■■■■■■■■■■■■■■■■■                                 \n");
	printf("               ■■■■■■■■■■■■■■■■■■■■                                 \n");
	printf("               ■■■■■■■■■■■■■■■■■■■■                                 \n");
	printf("               ■■■■■■■■■■■■■■■■■■■■                                 \n");
	printf("               ■■■■                                                                 \n");
	printf("               ■■■■                                                                 \n");
	printf("               ■■■■                                                                 \n");
	printf("               ■■■■                                                                 \n");
	printf("               ■■■■                                                                 \n");
	printf("               ■■■■                                                                 \n");
	printf("               ■■■■                                                                 \n");
	printf("               ■■■■■■■■■■■■■■■■■■■■                                 \n");
	printf("               ■■■■■■■■■■■■■■■■■■■■                                 \n");
	printf("               ■■■■■■■■■■■■■■■■■■■■                                 \n");
	printf("               ■■■■■■■■■■■■■■■■■■■■                                 \n");

	
}
prt3(){
	printf("               ■■■■■■■■■■■■■■■■■■■■                                 \n");
	printf("               ■■■■■■■■■■■■■■■■■■■■                                 \n");
	printf("               ■■■■■■■■■■■■■■■■■■■■                                 \n");
	printf("               ■■■■■■■■■■■■■■■■■■■■                                 \n");
	printf("                                               ■■■■                                 \n");
	printf("                                               ■■■■                                 \n");
	printf("                                               ■■■■                                 \n");
	printf("                                               ■■■■                                 \n");
	printf("                                               ■■■■                                 \n");
	printf("                                               ■■■■                                 \n");
	printf("               ■■■■■■■■■■■■■■■■■■■■                                 \n");
	printf("               ■■■■■■■■■■■■■■■■■■■■                                 \n");
	printf("               ■■■■■■■■■■■■■■■■■■■■                                 \n");
	printf("               ■■■■■■■■■■■■■■■■■■■■                                 \n");
	printf("                                               ■■■■                                 \n");
	printf("                                               ■■■■                                 \n");
	printf("                                               ■■■■                                 \n");
	printf("                                               ■■■■                                 \n");
	printf("                                               ■■■■                                 \n");
	printf("                                               ■■■■                                 \n");
	printf("                                               ■■■■                                 \n");
	printf("               ■■■■■■■■■■■■■■■■■■■■                                 \n");
	printf("               ■■■■■■■■■■■■■■■■■■■■                                 \n");
	printf("               ■■■■■■■■■■■■■■■■■■■■                                 \n");
	printf("               ■■■■■■■■■■■■■■■■■■■■                                 \n");

	
}
prt4(){
	printf("               ■■■■                        ■■■■                                 \n");
	printf("               ■■■■                        ■■■■                                 \n");
	printf("               ■■■■                        ■■■■                                 \n");
	printf("               ■■■■                        ■■■■                                 \n");
	printf("               ■■■■                        ■■■■                                 \n");
	printf("               ■■■■                        ■■■■                                 \n");
	printf("               ■■■■                        ■■■■                                 \n");
	printf("               ■■■■                        ■■■■                                 \n");
	printf("               ■■■■                        ■■■■                                 \n");
	printf("               ■■■■                        ■■■■                                 \n");
	printf("               ■■■■■■■■■■■■■■■■■■■■                                 \n");
	printf("               ■■■■■■■■■■■■■■■■■■■■                                 \n");
	printf("               ■■■■■■■■■■■■■■■■■■■■                                 \n");
	printf("               ■■■■■■■■■■■■■■■■■■■■                                 \n");
	printf("                                               ■■■■                                 \n");
	printf("                                               ■■■■                                 \n");
	printf("                                               ■■■■                                 \n");
	printf("                                               ■■■■                                 \n");
	printf("                                               ■■■■                                 \n");
	printf("                                               ■■■■                                 \n");
	printf("                                               ■■■■                                 \n");
	printf("                                               ■■■■                                 \n");
	printf("                                               ■■■■                                 \n");
	printf("                                               ■■■■                                 \n");
	printf("                                               ■■■■                                 \n");
	
}
prt5(){

	printf("               ■■■■■■■■■■■■■■■■■■■■                                 \n");
	printf("               ■■■■■■■■■■■■■■■■■■■■                                 \n");
	printf("               ■■■■■■■■■■■■■■■■■■■■                                 \n");
	printf("               ■■■■■■■■■■■■■■■■■■■■                                 \n");
	printf("               ■■■■                                                                 \n");
	printf("               ■■■■                                                                 \n");
	printf("               ■■■■                                                                 \n");
	printf("               ■■■■                                                                 \n");
	printf("               ■■■■                                                                 \n");
	printf("               ■■■■                                                                 \n");
	printf("               ■■■■■■■■■■■■■■■■■■■■                                 \n");
	printf("               ■■■■■■■■■■■■■■■■■■■■                                 \n");
	printf("               ■■■■■■■■■■■■■■■■■■■■                                 \n");
	printf("               ■■■■■■■■■■■■■■■■■■■■                                 \n");
	printf("                                               ■■■■                                 \n");
	printf("                                               ■■■■                                 \n");
	printf("                                               ■■■■                                 \n");
	printf("                                               ■■■■                                 \n");
	printf("                                               ■■■■                                 \n");
	printf("                                               ■■■■                                 \n");
	printf("               ■■■■■■■■■■■■■■■■■■■■                                 \n");
	printf("               ■■■■■■■■■■■■■■■■■■■■                                 \n");
	printf("               ■■■■■■■■■■■■■■■■■■■■                                 \n");
	printf("               ■■■■■■■■■■■■■■■■■■■■                                 \n");

	
}

//여기까지 유틸함수 
//여기서부터 오목 

void print_title(){
	printf("         Thanks for playing / Bug Report&Suggestion to ajy720@gmail.com     \n");
	printf("        ⓒ 2018. An Hyeon Seok - student of Suwon Information High School   \n");
	printf("   ===========================================================================\n");
}

int check(int col){
	int i, j, k, flag=0, wincol;
	if(col==1) wincol=2;
	if(col==-1) wincol=-2;
	for(i=0;i<size;i++){ for(j=0;j<size;j++){ if(plate[i][j]==col){				
				for(k=1;k<5;k++){
					if(plate[i+k][j]==col) flag+=1;
					else break;
				} if(flag==4){
						for(k=0;k<5;k++) plate[i-k][j]=wincol;	
						return col;
					}flag = 0;
				
				for(k=1;k<5;k++){
					if(plate[i+k][j+k]==col) flag+=1;
					else break;
				} if(flag==4){
						for(k=0;k<5;k++) plate[i-k][j-k]=wincol;	
						return col;
					}flag = 0;
				
				for(k=1;k<5;k++){
					if(plate[i][j+k]==col) flag+=1;
					else break;
				} if(flag==4){
						for(k=0;k<5;k++) plate[i][j-k]=wincol;	
						return col;
					}flag = 0;
					
				for(k=1;k<5;k++){
					if(plate[i+k][j-k]==col) flag+=1;
					else break;	
				} if(flag==4){
						for(k=0;k<5;k++) plate[i-k][j+k]=wincol;	
						return col;
					}flag = 0;
					
	}	}   }
	return 0;
} 

void draw_plate(int play){
	int i, j;
	
	system("cls");
	print_title();
	if(play == 1) printf("\t\t\t   =====승자 예측 게임=====\n\n");
	else printf("\t\t\t      =====2인용 오목======\n\n");
	printf("    "); 
	for(i=0;i<size;i++) printf(" %2d  ", i); printf("\n   "); 
	
	//맨 윗줄 출력 
	
	for(i=0;i<size;i++){
		printf("\n%2d  ", i); 
		setcolor(0, 6); 
		printf("─┼──");
		for(j=1;j<size-1;j++){
			printf("──┼──");
		}printf("──┼──"); setcolor(7, 0); printf("\n    "); 
	
		if(i==size-1) break;
		
		setcolor(0, 6);
		printf(" │  ");
		for(j=1;j<size;j++) printf("  │  ");
		setcolor(7, 0); 
	}
	
	for(i=0;i<size;i++){
		for(j=0;j<size;j++){
			gotoxy(5+5*i, 7+2*j);
			if(plate[i][j]==1){
				setcolor(0, 6);
				printf("●");
				setcolor(7, 0);
			}
			
			if(plate[i][j]==-1){
				setcolor(15, 6);
				printf("●");
				setcolor(7, 0);
			}
			
			if(plate[i][j]==2){
				setcolor(0, 4);
				printf("⊙");
				setcolor(7, 0);
			}
			
			if(plate[i][j]==-2){
				setcolor(15, 4);
				printf("⊙");
				setcolor(7, 0);
			}
		}
	}
	
	gotoxy(1, 38);
}

OMOK(){		
	int i=0, j=0;
	
	int x, y;
	int turn = -1;
	int c=0;
	int play;
	int winner=0; 
	char dir;
	Restart:
	system("cls");
	for(i=0;i<size+1;i++) for(j=0;j<size+1;j++) plate[i][j]=0;	
		
	srand(time(NULL));
	print_title();
	printf("플레이 방식을 선택하세요.\n");
	printf("\n※승자 예측은 돈이 필요합니다※\n\n");
	printf("1. 승자 예측 \n2. 2인용 오목\n3. 게임 종료\n\n");
	
	while(1){
		printf("선택 => ");
		play = getche()-'0';
		if(play==1||play==2) break;
		else if(play==3){
			system("cls");
			printf("게임을 종료합니다.");
			return 0;
		}
		printf("\n정확한 값을 입력하세요.\n\n");
	} 
	
	if(play==1){
		system("cls");
		print_title();
		
		printf("\t\t\t┌──────────────────────────────┐\n");
		printf("\t\t\t│    현재 남은 돈 : %10d$│\n", money);
		printf("\t\t\t└──────────────────────────────┘\n");
		while( 1 ){
			printf("\n\t\t얼마를 거시겠습니까?  : ");
			scanf("%d", &bet);
			
			if( bet > money&& money>=0) printf("\t\t돈이 없습니다.\n\n");
			else if( bet < 0 ) printf("\t\t잘못된 값을 입력하셨습니다.\n\n");
			else break;
		}
		
		money-=bet;
		
		printf("\t\t승자를 선택하십시오.\n\t\t1. 흑돌  2. 백돌\n");
		while(1){
			printf("\t\t선택 => ");
			winner = getch()-'0';
			if(winner==1||winner==2) break;
			printf("\n\t\t정확한 값을 입력하세요.\n\n");
		} 
	}
	draw_plate(play); 
	
	do{
		turn*=-1;
		if(turn>0) printf("흑");
		else printf("백");
		printf("의 차례입니다.\n");
		if(play == 2){
			x=5+5*7; y=7+2*7;
			gotoxy(x,y);
		}
		while(1){
			if(play == 1){
				x=rand()%15; y=rand()%15;
				printf(" %d %d\n", x, y);
				if(getch() == ESC){
					printf(" 정말 게임을 다시 시작하시겠습니까? (Y/N)");
					while(1){
						yesno = getch();
						if(yesno=='y'||yesno=='Y') goto Restart;
						else if(yesno=='n'||yesno=='N') break;
					}
				}
			}
			else if(play == 2){
				while(1){
					dir = getch();
					switch(dir){
						case  LEFT: if(x>5)              x-=5; break;
						case RIGHT: if(x<(5+5*(size-1))) x+=5; break;
						case    UP: if(y>7)              y-=2; break;
						case  DOWN: if(y<(7+2*(size-1))) y+=2; break;
						case   ESC:	gotoxy(1, 38);
									printf("정말 게임을 다시 시작하시겠습니까? (Y/N)");
									while(1){
										yesno = getch();
										if(yesno=='y'||yesno=='Y') goto Restart;
										else if(yesno=='n'||yesno=='N'){
											gotoxy(1, 38);
											if(turn>0) printf("흑");
											else printf("백");
											printf("의 차례입니다.                                   \n");
											break;
										}
									}
				
					}
					gotoxy(x,y);
					if(dir == ENTER|| dir == ' '){
						x=(x-5)/5; y=(y-7)/2;
						break;
					}
				}
				
			gotoxy(1, 38);
			}
			
			if(plate[x][y]!=0&&play==2){ printf(" 이미 차지된 자리입니다.\n\n"); x=x*5+5; y=y*2+7; gotoxy(x,y);}
			if(plate[x][y]!=0&&play==1)  printf(" 이미 차지된 자리입니다.\n\n");
			else{
				if(turn>0) plate[x][y]=1;
				else plate[x][y]=-1;
				draw_plate(play);
			
				break; 
			}
		}
		
		if(c++<8) continue;
		
		int res = 0;
		res = check(turn); 
		if(res==0) continue;
		draw_plate(play);
		if(res==1) printf("흑돌이 승리했습니다.\n\n");
		else if(res==-1) printf("백돌이 승리했습니다.\n\n");
		
		if(winner==1&&res==1||winner==2&&res==-1){
			printf(" 축하합니다. 승자를 맞추셨습니다. \n\n");
			money=+bet*2; 
		}
		else printf(" 유감입니다. \n\n");
		printf(" 다시 시작하시겠습니까? (Y/N)");
		while(1){
			yesno = getch();
			if(yesno=='y'||yesno=='Y') goto Restart;
			else if(yesno=='n'||yesno=='N'){
				printf("\n 메인 메뉴로 돌아갑니다. \n");
				getch();
				return ;
			}
		}
	
	}while(1);
}

//여기까지 오목

void Gamemenu_PLAYGROUND(){
	static int gm1;
	system("cls");
	print_current_money();
	printf("\t\t\t\t\t     ┌───── 게임 메뉴─────┐ \n"); 
	printf("\t\t\t\t\t     │ 1. 오목(2인용)     │ \n");
	printf("\t\t\t\t\t     │ 2. 2048            │ \n");
	printf("\t\t\t\t\t     │ 3. 돌아가기        │ \n"); 
	printf("\t\t\t\t\t     └────────────────────┘ \n");
	printf("\t\t\t\t\t   어떤 놀이를 하시겠습니까? : "); 
	scanf("%d",&gm1);
	switch(gm1){
		case 1: OMOK();	break;
		case 2: break;
		case 3: break;
		default: break;
	}
}
//오락실 화면

void HORSE(){
	back1:
	system("cls");
	int HORNO;
	print_current_money();
	
	re2:
	printf("\t\t\t\t       (말의 마릿수 : 2~9, 메인메뉴 : ESC)");
		while(1){
			printf("\n\t\t\t\t      선택하십시오 : ");
			scanf("%d", &choice);
			if(choice>=1||choice<=9) break;
			else{
				printf("\n\t\t\t\t      잘못된 값을 입력하셨습니다.\n\n");
			}
		}
	HORNO = choice;
	
	int mov[9], pos[9]={0}, rp, n, rank[9];
	
	for(i=0;i<HORNO;i++){
		rank[i]=i+1;
	}
	
	re:
	printf("\t\t\t\t      말을 선택하십시오.(1~%d) => ", HORNO);
	scanf("%d", &choice);
	if(choice>HORNO||choice<1){
		printf("\t\t\t\t      정확한 값을 입력하십시오.\n\n");
		goto re;
	}
	
	while( 1 ){
		printf("\t\t\t\t      얼마를 거시겠습니까?  : ");
		scanf("%d", &bet);
		
		if( bet > money&& money>=0) printf("\t\t\t\t      돈이 없습니다.\n\n");
		else if( bet < 0 ) printf("\t\t\t\t      잘못된 값을 입력하셨습니다.\n\n");
		else break;
	}

	money-=bet;
	
	
	printf("\t\t\t\t      게임 속도를 선택하세요. (매우느림(1)~매우빠름(10)) : ");
	int gamespeed;
	scanf("%d", &gamespeed); 
	
	gamespeed = 700 - gamespeed * 50;
	
	system("cls");
		
		printf("                                           ===경마 게임===\n");
		printf("[Choice : %d]\n", choice);
		
		printf("===================================================================================================|\n");
		for(i=0;i<HORNO;i++) printf("\n===================================================================================================|\n");
	
	while(1){
		for(i=0;i<HORNO;i++) if(pos[i]>=100) goto exit; 
		srand(time(NULL));
		Sleep(gamespeed);
		
		for(rp=0;rp<HORNO;rp++){
			mov[rp]=rand()%5+1;
			gotoxy(pos[rp], 3+rp*2);
			for(i=0;i<mov[rp];i++){
				putchar(' '); //putchar(' ');
			} 
			setcolor(rp+1,0); 
			switch(rp+1){
				case 1: printf("①"); break;
				case 2: printf("②"); break;
				case 3: printf("③"); break;
				case 4: printf("④"); break;
				case 5: printf("⑤"); break;
				case 6: printf("⑥"); break;
				case 7: printf("⑦"); break;
				case 8: printf("⑧"); break;
				case 9: printf("⑨"); break;
			} 
			setcolor(7,0);
			pos[rp]+=mov[rp];
		}
	}
	exit: 
	
	for(i=0;i<HORNO-1;i++){
		for(j=i;j<HORNO;j++){
			if(pos[i]<pos[j]){
				intswap(&pos[i],&pos[j]);
				intswap(&rank[i],&rank[j]);
			}
		}
	}
	
	printf("\n\n\n\t\t\t\t\t┌────── 결과──────┐ \n"); 
	for(i=0;i<HORNO;i++){
		printf("\t\t\t\t\t│─────────────────│ \n"); 
		printf("\t\t\t\t\t│ %d등 : %d번 경주마│ \n", i+1, rank[i]);
		 
	}
	printf("\t\t\t\t\t│─────────────────│ \n"); 
	printf("\t\t\t\t\t└─────────────────┘ \n"); 
	
	if(rank[0]==choice){
		printf("이겼습니다!!!\n");
		printf("돈을 따셨습니다!!!\n");
		printf("배당은 %d배입니다.\n",HORNO);
		putchar('\a');
		money+=bet*HORNO;
		save_money();
	}
	else{
		printf("졌습니다...\n");
		printf("돈을 잃었습니다...\n");
		save_money(); 
	}
	
	if(money<=0){
		printf("돈을 전부 잃었습니다.\n");
		save_money();
		return ;
	}
		
	printf("다시 하시겠습니까? (Y/N) : ");
	
	while(1){
		yesno = getch();
		if(yesno=='Y'||yesno=='y'){
			putchar('Y');
			system("cls");
			save_money();
			setcolor(13,0);
			for(i=5;i>=1;i--){
				putchar('\a');
				switch(i){
					case 5: prt5(); break;
					case 4: prt4(); break;
					case 3: prt3(); break;
					case 2: prt2(); break;
					case 1: prt1(); break;
				}
			Sleep(1000);		
			system("cls");
			putchar('\b');
			}
			goto back1;
		} 
		else if(yesno=='N'||yesno=='n'){
			putchar('N');
			printf("\n\nWay Back Home - Shown\n");
			printf("이 노래 좋아요.\n");
			system("pause"); 
			system("cls");
			save_money();
			return ;
		}
		else{
			putchar('\b');
			putchar(' ');
		}
	}
	system("pause");
		
}

void ODDEVEN(){
	system("cls");
	value = 1 + rand() % 2;
	print_current_money();
	
	printf("\t\t\t\t   (홀수 : 1, 짝수 : 2, 메뉴로 돌아가기 : ESC)\n"); 
	while(1){
		printf("\t\t\t\t\t선택하십시오 : ");
		choice = getche();
		if(choice==ESC){printf("EESC\n\t\t\t\t\t메인메뉴로 돌아갑니다."); Sleep(1000); return;}
		if(choice=='1'||choice=='2'){choice-='0'; putchar('\n'); break;}
		else{
			printf("\n\t\t\t\t\t잘못된 값을 입력하셨습니다.\n\n");
		}
	}
	while(1){
		printf("\t\t\t\t\t얼마를 거시겠습니까?  : ");
		scanf("%d", &bet);
		if( bet > money ) {
			printf("\n\t\t\t\t\t돈이 없습니다!!!\n\n");
		}
		else if( bet <= 0 ) {
			printf("\n\t\t\t\t\t정확한 값을 입력하세요.\n\n");
		}
		else{
			money-=bet;
			break;
		}	
	}
	
	
	if((choice==1&&value==1)||(choice==2&&value==2)){	
		printf("\t\t\t\t\t정답은...\n\t\t\t\t\t");
		for(i=0;i<10;i++){
			printf("홀");	Sleep(50); 	putchar('\b');putchar('\b');
			printf("짝"); 	Sleep(50);	putchar('\b');putchar('\b');
		}putchar(' ');putchar(' ');
		
		if(value==1) printf("\b\b홀수였습니다!\n");
		else printf("\b\b짝수였습니다!\n");
	
		printf("\n\t\t\t\t\t돈을 따셨습니다!!!\n\a");
		money+=bet*2;
		save_money();
	}
					
	if((choice==1&&value==2)||(choice==2&&value==1)){
		printf("\t\t\t\t\t정답은...\n\t\t\t\t\t");
		for(i=0;i<10;i++){
			printf("홀");	Sleep(50); 	putchar('\b');putchar('\b');
			printf("짝"); 	Sleep(50);	putchar('\b');putchar('\b');
		}putchar(' ');putchar(' ');
			
		if(value==1) printf("\b\b홀수였습니다!\n");
		else printf("\b\b짝수였습니다!\n");
			
		printf("\n\t\t\t\t\t돈을 잃었습니다...\n");
		save_money();
	}
						
	if( money <= 0 ) {
		save_money();
		printf("돈을 전부 잃었습니다.\n");
		Sleep(1000);
		return;
	}
	
	else{	
		printf("\t\t\t\t\t다시 하시겠습니까? (Y/N) : ");			
		while(1){
			yesno = getch();
			if(yesno == 'y'||yesno == 'Y'){	putchar(yesno); save_money(); ODDEVEN();	}
			else if(yesno == 'n'||yesno == 'N'){ putchar(yesno); save_money(); return; }
		}
	}
}

void DICE(){
	system("cls");
	value = 1 + rand() % 6;
	printf("※게임설명※\n");
	printf("원하는 숫자와 랜덤으로 나오는\n숫자가 같으면 3배,내가고른 숫자와±1차이가나면 2배를받습니다.\n");
	printf("게임을 시작하려면 아무키나 누르십시오...\n"); 
	getch();
	system("cls");
	st:
	system("cls");
	print_current_money();
	printf("\t\t\t\t\t (주사위 : 1~6,  메인메뉴 : ESC)\n");
		
	while( 1 ){
		
		while(1){
			printf("\t\t\t\t\t선택하십시오 : ");
			choice = getche();
			if(choice==ESC){printf("EESC\n\t\t\t\t\t메인메뉴로 돌아갑니다."); Sleep(1000); return;}
			if(choice>='1'&&choice<='6'){choice-='0'; putchar('\n'); break;}
			else{
				printf("\n\t\t\t\t\t잘못된 값을 입력하셨습니다.\n\n");
			}
		}
		
		printf("\t\t\t\t\t얼마를 거시겠습니까?  : ");
		scanf("%d", &bet);
		if( bet > money ) printf("\n\t\t\t\t\t돈이 부족합니다.\n\n");
		else if( bet <= 0 ) printf("\n\t\t\t\t\t정확한 값을 입력하세요.\n\n");
		else break;
	}
	
	money-=bet;
	save_money();
	printf("\t\t\t\t\t%d", rand()%6+1);
	for(i=1;i<20;i++){
		printf("\b%d", rand()%6+1);
		Sleep(50);
	}putchar('\n');
	printf("\t\t\t\t\t랜덤 숫자 : %d\n", value);
	printf("\t\t\t\t\t선택한 숫자 : %d\n", choice);
	if(value==choice){
		putchar('\a');
		printf("\t\t\t\t\t숫자가 같습니다. 돈을 따셨습니다!!!\n");
		money += bet * 3;
		save_money();
	}	
	else if(value==choice+1||value==choice-1){
		printf("\t\t\t\t\t차이가 1 입니다. 돈을 따셨습니다!!!\n");
		money += bet * 2;
		save_money();
	}
	else {
		save_money();
		printf("\t\t\t\t\t돈을 잃었습니다...\n");
	} 		
				
	if( money<=0 ) {
		save_money();
		return ;
	}
	printf("\t\t\t\t\t다시 하시겠습니까? (Y/N) : ");
	while(1){
		yesno = getch();
		if(yesno == 'y'||yesno == 'Y'){	putchar(yesno); goto st;}
		else if(yesno == 'n'||yesno == 'N'){ putchar(yesno); return; }
	}
}

int main(){

	int choice, value;
	int gm;
	FILE *file = fopen("money.dat", "rt");
	if(file==0){ money = 100; }
	else {
		fscanf(file,"%d", &money);
		fclose(file);
	}
	
	while(1)
	{
		system("cls");
		srand(time(NULL));
		print_current_money();

		printf("\t\t\t\t\t     ┌───── 게임 메뉴─────┐ \n");
		printf("\t\t\t\t\t     │ 1. 홀짝        (x2)│ \n");
		printf("\t\t\t\t\t     │ 2. 주사위   (x2~x3)│ \n");
		printf("\t\t\t\t\t     │ 3. 경마     (x2~x9)│ \n");
		printf("\t\t\t\t\t     │ 4. 오락실          │ \n");
		printf("\t\t\t\t\t     │ 5. 끝내기          │ \n");
		printf("\t\t\t\t\t     └────────────────────┘ \n");
		printf("\t\t\t\t\t  어떤게임을 하시겠습니까? : "); 

		scanf("%d", &gm);
		fflush(stdin);
		putchar('\a');
		if(money<=0 && (gm>=1 && gm<=3)){
			printf("  돈이 부족합니다.\n  "); system("pause");  
		}
		else{
			switch( gm )
			{
				case 1: ODDEVEN(); break;
				
				case 2: DICE(); break;
				
				case 3: HORSE(); break;
					
				case 4: Gamemenu_PLAYGROUND(); break;
				
				case 5: system("cls");
						FILE *file = fopen("money.dat","wt");
						if(file==0){
							gotoxy(0,0); 
	                    	printf("FILE ERROR: SYSTEM CANNOT WRITE BEST SCORE ON \"MONEY.TXT\"");
						}
						else{
							fprintf(file,"%d", money);
	           	  			fclose(file);
						}
						printf("돈을 저장하고 프로그램을 종료합니다."); 
						return 0;
				
				case 7: scanf("%d", &money); break;
				
				case 9: money=2147483647; break;
				
				case 10: money = 1; break;
				default: getchar(); break;
			}
		}
		
}
	exit: return 0;
}

