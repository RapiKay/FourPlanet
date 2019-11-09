//�������� ���ų� �����ǿ��� ������ �Ҷ� (�����/���Ӻ��)�� ��(�¿��� ���̵��) 

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
int plate[size+1][size+1]={0}; //���� 1 ���� 2 ������ 0 


//��ƿ �Լ�  
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

void gotoxy(int x,int y) { //����ͻ��� x,y ��ǥ�� �̵���Ű�� �Լ� 
    COORD pos={x,y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}

void setcursortype(CURSOR_TYPE c){ //Ŀ�� ǥ�ø� �ٲ��ִ� �Լ�  
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
		printf("\t\t\t\t\t���������������������������������������������������������������� \n");
		printf("\t\t\t\t\t��    ���� ���� �� : %10d$�� \n", money);
		printf("\t\t\t\t\t���������������������������������������������������������������� \n");
	
}
void save_money(); 
//���� 

prt1(){
	
	printf("                           �������                                                 \n");
	printf("                         ��������                                                 \n");
	printf("                       ���������                                                 \n");
	printf("                     ����������                                                 \n");
	printf("                               �����                                                 \n");
	printf("                               �����                                                 \n");
	printf("                               �����                                                 \n");
	printf("                               �����                                                 \n");
	printf("                               �����                                                 \n");
	printf("                               �����                                                 \n");
	printf("                               �����                                                 \n");
	printf("                               �����                                                 \n");
	printf("                               �����                                                 \n");
	printf("                               �����                                                 \n");
	printf("                               �����                                                 \n");
	printf("                               �����                                                 \n");
	printf("                               �����                                                 \n");
	printf("                               �����                                                 \n");
	printf("                               �����                                                 \n");
	printf("                               �����                                                 \n");
	printf("                               �����                                                 \n");
	printf("               ���������������������                                 \n");
	printf("               ���������������������                                 \n");
	printf("               ���������������������                                 \n");
	printf("               ���������������������                                 \n");
	setcolor(7,0);

}
prt2(){
	printf("               ���������������������                                 \n");
	printf("               ���������������������                                 \n");
	printf("               ���������������������                                 \n");
	printf("               ���������������������                                 \n");
	printf("                                               �����                                 \n");
	printf("                                               �����                                 \n");
	printf("                                               �����                                 \n");
	printf("                                               �����                                 \n");
	printf("                                               �����                                 \n");
	printf("                                               �����                                 \n");
	printf("               ���������������������                                 \n");
	printf("               ���������������������                                 \n");
	printf("               ���������������������                                 \n");
	printf("               ���������������������                                 \n");
	printf("               �����                                                                 \n");
	printf("               �����                                                                 \n");
	printf("               �����                                                                 \n");
	printf("               �����                                                                 \n");
	printf("               �����                                                                 \n");
	printf("               �����                                                                 \n");
	printf("               �����                                                                 \n");
	printf("               ���������������������                                 \n");
	printf("               ���������������������                                 \n");
	printf("               ���������������������                                 \n");
	printf("               ���������������������                                 \n");

	
}
prt3(){
	printf("               ���������������������                                 \n");
	printf("               ���������������������                                 \n");
	printf("               ���������������������                                 \n");
	printf("               ���������������������                                 \n");
	printf("                                               �����                                 \n");
	printf("                                               �����                                 \n");
	printf("                                               �����                                 \n");
	printf("                                               �����                                 \n");
	printf("                                               �����                                 \n");
	printf("                                               �����                                 \n");
	printf("               ���������������������                                 \n");
	printf("               ���������������������                                 \n");
	printf("               ���������������������                                 \n");
	printf("               ���������������������                                 \n");
	printf("                                               �����                                 \n");
	printf("                                               �����                                 \n");
	printf("                                               �����                                 \n");
	printf("                                               �����                                 \n");
	printf("                                               �����                                 \n");
	printf("                                               �����                                 \n");
	printf("                                               �����                                 \n");
	printf("               ���������������������                                 \n");
	printf("               ���������������������                                 \n");
	printf("               ���������������������                                 \n");
	printf("               ���������������������                                 \n");

	
}
prt4(){
	printf("               �����                        �����                                 \n");
	printf("               �����                        �����                                 \n");
	printf("               �����                        �����                                 \n");
	printf("               �����                        �����                                 \n");
	printf("               �����                        �����                                 \n");
	printf("               �����                        �����                                 \n");
	printf("               �����                        �����                                 \n");
	printf("               �����                        �����                                 \n");
	printf("               �����                        �����                                 \n");
	printf("               �����                        �����                                 \n");
	printf("               ���������������������                                 \n");
	printf("               ���������������������                                 \n");
	printf("               ���������������������                                 \n");
	printf("               ���������������������                                 \n");
	printf("                                               �����                                 \n");
	printf("                                               �����                                 \n");
	printf("                                               �����                                 \n");
	printf("                                               �����                                 \n");
	printf("                                               �����                                 \n");
	printf("                                               �����                                 \n");
	printf("                                               �����                                 \n");
	printf("                                               �����                                 \n");
	printf("                                               �����                                 \n");
	printf("                                               �����                                 \n");
	printf("                                               �����                                 \n");
	
}
prt5(){

	printf("               ���������������������                                 \n");
	printf("               ���������������������                                 \n");
	printf("               ���������������������                                 \n");
	printf("               ���������������������                                 \n");
	printf("               �����                                                                 \n");
	printf("               �����                                                                 \n");
	printf("               �����                                                                 \n");
	printf("               �����                                                                 \n");
	printf("               �����                                                                 \n");
	printf("               �����                                                                 \n");
	printf("               ���������������������                                 \n");
	printf("               ���������������������                                 \n");
	printf("               ���������������������                                 \n");
	printf("               ���������������������                                 \n");
	printf("                                               �����                                 \n");
	printf("                                               �����                                 \n");
	printf("                                               �����                                 \n");
	printf("                                               �����                                 \n");
	printf("                                               �����                                 \n");
	printf("                                               �����                                 \n");
	printf("               ���������������������                                 \n");
	printf("               ���������������������                                 \n");
	printf("               ���������������������                                 \n");
	printf("               ���������������������                                 \n");

	
}

//������� ��ƿ�Լ� 
//���⼭���� ���� 

void print_title(){
	printf("         Thanks for playing / Bug Report&Suggestion to ajy720@gmail.com     \n");
	printf("        �� 2018. An Hyeon Seok - student of Suwon Information High School   \n");
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
	if(play == 1) printf("\t\t\t   =====���� ���� ����=====\n\n");
	else printf("\t\t\t      =====2�ο� ����======\n\n");
	printf("    "); 
	for(i=0;i<size;i++) printf(" %2d  ", i); printf("\n   "); 
	
	//�� ���� ��� 
	
	for(i=0;i<size;i++){
		printf("\n%2d  ", i); 
		setcolor(0, 6); 
		printf("��������");
		for(j=1;j<size-1;j++){
			printf("����������");
		}printf("����������"); setcolor(7, 0); printf("\n    "); 
	
		if(i==size-1) break;
		
		setcolor(0, 6);
		printf(" ��  ");
		for(j=1;j<size;j++) printf("  ��  ");
		setcolor(7, 0); 
	}
	
	for(i=0;i<size;i++){
		for(j=0;j<size;j++){
			gotoxy(5+5*i, 7+2*j);
			if(plate[i][j]==1){
				setcolor(0, 6);
				printf("��");
				setcolor(7, 0);
			}
			
			if(plate[i][j]==-1){
				setcolor(15, 6);
				printf("��");
				setcolor(7, 0);
			}
			
			if(plate[i][j]==2){
				setcolor(0, 4);
				printf("��");
				setcolor(7, 0);
			}
			
			if(plate[i][j]==-2){
				setcolor(15, 4);
				printf("��");
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
	printf("�÷��� ����� �����ϼ���.\n");
	printf("\n�ؽ��� ������ ���� �ʿ��մϴ١�\n\n");
	printf("1. ���� ���� \n2. 2�ο� ����\n3. ���� ����\n\n");
	
	while(1){
		printf("���� => ");
		play = getche()-'0';
		if(play==1||play==2) break;
		else if(play==3){
			system("cls");
			printf("������ �����մϴ�.");
			return 0;
		}
		printf("\n��Ȯ�� ���� �Է��ϼ���.\n\n");
	} 
	
	if(play==1){
		system("cls");
		print_title();
		
		printf("\t\t\t����������������������������������������������������������������\n");
		printf("\t\t\t��    ���� ���� �� : %10d$��\n", money);
		printf("\t\t\t����������������������������������������������������������������\n");
		while( 1 ){
			printf("\n\t\t�󸶸� �Žðڽ��ϱ�?  : ");
			scanf("%d", &bet);
			
			if( bet > money&& money>=0) printf("\t\t���� �����ϴ�.\n\n");
			else if( bet < 0 ) printf("\t\t�߸��� ���� �Է��ϼ̽��ϴ�.\n\n");
			else break;
		}
		
		money-=bet;
		
		printf("\t\t���ڸ� �����Ͻʽÿ�.\n\t\t1. �浹  2. �鵹\n");
		while(1){
			printf("\t\t���� => ");
			winner = getch()-'0';
			if(winner==1||winner==2) break;
			printf("\n\t\t��Ȯ�� ���� �Է��ϼ���.\n\n");
		} 
	}
	draw_plate(play); 
	
	do{
		turn*=-1;
		if(turn>0) printf("��");
		else printf("��");
		printf("�� �����Դϴ�.\n");
		if(play == 2){
			x=5+5*7; y=7+2*7;
			gotoxy(x,y);
		}
		while(1){
			if(play == 1){
				x=rand()%15; y=rand()%15;
				printf(" %d %d\n", x, y);
				if(getch() == ESC){
					printf(" ���� ������ �ٽ� �����Ͻðڽ��ϱ�? (Y/N)");
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
									printf("���� ������ �ٽ� �����Ͻðڽ��ϱ�? (Y/N)");
									while(1){
										yesno = getch();
										if(yesno=='y'||yesno=='Y') goto Restart;
										else if(yesno=='n'||yesno=='N'){
											gotoxy(1, 38);
											if(turn>0) printf("��");
											else printf("��");
											printf("�� �����Դϴ�.                                   \n");
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
			
			if(plate[x][y]!=0&&play==2){ printf(" �̹� ������ �ڸ��Դϴ�.\n\n"); x=x*5+5; y=y*2+7; gotoxy(x,y);}
			if(plate[x][y]!=0&&play==1)  printf(" �̹� ������ �ڸ��Դϴ�.\n\n");
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
		if(res==1) printf("�浹�� �¸��߽��ϴ�.\n\n");
		else if(res==-1) printf("�鵹�� �¸��߽��ϴ�.\n\n");
		
		if(winner==1&&res==1||winner==2&&res==-1){
			printf(" �����մϴ�. ���ڸ� ���߼̽��ϴ�. \n\n");
			money=+bet*2; 
		}
		else printf(" �����Դϴ�. \n\n");
		printf(" �ٽ� �����Ͻðڽ��ϱ�? (Y/N)");
		while(1){
			yesno = getch();
			if(yesno=='y'||yesno=='Y') goto Restart;
			else if(yesno=='n'||yesno=='N'){
				printf("\n ���� �޴��� ���ư��ϴ�. \n");
				getch();
				return ;
			}
		}
	
	}while(1);
}

//������� ����

void Gamemenu_PLAYGROUND(){
	static int gm1;
	system("cls");
	print_current_money();
	printf("\t\t\t\t\t     ������������ ���� �޴������������� \n"); 
	printf("\t\t\t\t\t     �� 1. ����(2�ο�)     �� \n");
	printf("\t\t\t\t\t     �� 2. 2048            �� \n");
	printf("\t\t\t\t\t     �� 3. ���ư���        �� \n"); 
	printf("\t\t\t\t\t     �������������������������������������������� \n");
	printf("\t\t\t\t\t   � ���̸� �Ͻðڽ��ϱ�? : "); 
	scanf("%d",&gm1);
	switch(gm1){
		case 1: OMOK();	break;
		case 2: break;
		case 3: break;
		default: break;
	}
}
//������ ȭ��

void HORSE(){
	back1:
	system("cls");
	int HORNO;
	print_current_money();
	
	re2:
	printf("\t\t\t\t       (���� ������ : 2~9, ���θ޴� : ESC)");
		while(1){
			printf("\n\t\t\t\t      �����Ͻʽÿ� : ");
			scanf("%d", &choice);
			if(choice>=1||choice<=9) break;
			else{
				printf("\n\t\t\t\t      �߸��� ���� �Է��ϼ̽��ϴ�.\n\n");
			}
		}
	HORNO = choice;
	
	int mov[9], pos[9]={0}, rp, n, rank[9];
	
	for(i=0;i<HORNO;i++){
		rank[i]=i+1;
	}
	
	re:
	printf("\t\t\t\t      ���� �����Ͻʽÿ�.(1~%d) => ", HORNO);
	scanf("%d", &choice);
	if(choice>HORNO||choice<1){
		printf("\t\t\t\t      ��Ȯ�� ���� �Է��Ͻʽÿ�.\n\n");
		goto re;
	}
	
	while( 1 ){
		printf("\t\t\t\t      �󸶸� �Žðڽ��ϱ�?  : ");
		scanf("%d", &bet);
		
		if( bet > money&& money>=0) printf("\t\t\t\t      ���� �����ϴ�.\n\n");
		else if( bet < 0 ) printf("\t\t\t\t      �߸��� ���� �Է��ϼ̽��ϴ�.\n\n");
		else break;
	}

	money-=bet;
	
	
	printf("\t\t\t\t      ���� �ӵ��� �����ϼ���. (�ſ����(1)~�ſ����(10)) : ");
	int gamespeed;
	scanf("%d", &gamespeed); 
	
	gamespeed = 700 - gamespeed * 50;
	
	system("cls");
		
		printf("                                           ===�渶 ����===\n");
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
				case 1: printf("��"); break;
				case 2: printf("��"); break;
				case 3: printf("��"); break;
				case 4: printf("��"); break;
				case 5: printf("��"); break;
				case 6: printf("��"); break;
				case 7: printf("��"); break;
				case 8: printf("��"); break;
				case 9: printf("��"); break;
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
	
	printf("\n\n\n\t\t\t\t\t�������������� ����������������� \n"); 
	for(i=0;i<HORNO;i++){
		printf("\t\t\t\t\t�������������������������������������� \n"); 
		printf("\t\t\t\t\t�� %d�� : %d�� ���ָ��� \n", i+1, rank[i]);
		 
	}
	printf("\t\t\t\t\t�������������������������������������� \n"); 
	printf("\t\t\t\t\t�������������������������������������� \n"); 
	
	if(rank[0]==choice){
		printf("�̰���ϴ�!!!\n");
		printf("���� ���̽��ϴ�!!!\n");
		printf("����� %d���Դϴ�.\n",HORNO);
		putchar('\a');
		money+=bet*HORNO;
		save_money();
	}
	else{
		printf("�����ϴ�...\n");
		printf("���� �Ҿ����ϴ�...\n");
		save_money(); 
	}
	
	if(money<=0){
		printf("���� ���� �Ҿ����ϴ�.\n");
		save_money();
		return ;
	}
		
	printf("�ٽ� �Ͻðڽ��ϱ�? (Y/N) : ");
	
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
			printf("�� �뷡 ���ƿ�.\n");
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
	
	printf("\t\t\t\t   (Ȧ�� : 1, ¦�� : 2, �޴��� ���ư��� : ESC)\n"); 
	while(1){
		printf("\t\t\t\t\t�����Ͻʽÿ� : ");
		choice = getche();
		if(choice==ESC){printf("EESC\n\t\t\t\t\t���θ޴��� ���ư��ϴ�."); Sleep(1000); return;}
		if(choice=='1'||choice=='2'){choice-='0'; putchar('\n'); break;}
		else{
			printf("\n\t\t\t\t\t�߸��� ���� �Է��ϼ̽��ϴ�.\n\n");
		}
	}
	while(1){
		printf("\t\t\t\t\t�󸶸� �Žðڽ��ϱ�?  : ");
		scanf("%d", &bet);
		if( bet > money ) {
			printf("\n\t\t\t\t\t���� �����ϴ�!!!\n\n");
		}
		else if( bet <= 0 ) {
			printf("\n\t\t\t\t\t��Ȯ�� ���� �Է��ϼ���.\n\n");
		}
		else{
			money-=bet;
			break;
		}	
	}
	
	
	if((choice==1&&value==1)||(choice==2&&value==2)){	
		printf("\t\t\t\t\t������...\n\t\t\t\t\t");
		for(i=0;i<10;i++){
			printf("Ȧ");	Sleep(50); 	putchar('\b');putchar('\b');
			printf("¦"); 	Sleep(50);	putchar('\b');putchar('\b');
		}putchar(' ');putchar(' ');
		
		if(value==1) printf("\b\bȦ�������ϴ�!\n");
		else printf("\b\b¦�������ϴ�!\n");
	
		printf("\n\t\t\t\t\t���� ���̽��ϴ�!!!\n\a");
		money+=bet*2;
		save_money();
	}
					
	if((choice==1&&value==2)||(choice==2&&value==1)){
		printf("\t\t\t\t\t������...\n\t\t\t\t\t");
		for(i=0;i<10;i++){
			printf("Ȧ");	Sleep(50); 	putchar('\b');putchar('\b');
			printf("¦"); 	Sleep(50);	putchar('\b');putchar('\b');
		}putchar(' ');putchar(' ');
			
		if(value==1) printf("\b\bȦ�������ϴ�!\n");
		else printf("\b\b¦�������ϴ�!\n");
			
		printf("\n\t\t\t\t\t���� �Ҿ����ϴ�...\n");
		save_money();
	}
						
	if( money <= 0 ) {
		save_money();
		printf("���� ���� �Ҿ����ϴ�.\n");
		Sleep(1000);
		return;
	}
	
	else{	
		printf("\t\t\t\t\t�ٽ� �Ͻðڽ��ϱ�? (Y/N) : ");			
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
	printf("�ذ��Ӽ����\n");
	printf("���ϴ� ���ڿ� �������� ������\n���ڰ� ������ 3��,������ ���ڿ͡�1���̰����� 2�踦�޽��ϴ�.\n");
	printf("������ �����Ϸ��� �ƹ�Ű�� �����ʽÿ�...\n"); 
	getch();
	system("cls");
	st:
	system("cls");
	print_current_money();
	printf("\t\t\t\t\t (�ֻ��� : 1~6,  ���θ޴� : ESC)\n");
		
	while( 1 ){
		
		while(1){
			printf("\t\t\t\t\t�����Ͻʽÿ� : ");
			choice = getche();
			if(choice==ESC){printf("EESC\n\t\t\t\t\t���θ޴��� ���ư��ϴ�."); Sleep(1000); return;}
			if(choice>='1'&&choice<='6'){choice-='0'; putchar('\n'); break;}
			else{
				printf("\n\t\t\t\t\t�߸��� ���� �Է��ϼ̽��ϴ�.\n\n");
			}
		}
		
		printf("\t\t\t\t\t�󸶸� �Žðڽ��ϱ�?  : ");
		scanf("%d", &bet);
		if( bet > money ) printf("\n\t\t\t\t\t���� �����մϴ�.\n\n");
		else if( bet <= 0 ) printf("\n\t\t\t\t\t��Ȯ�� ���� �Է��ϼ���.\n\n");
		else break;
	}
	
	money-=bet;
	save_money();
	printf("\t\t\t\t\t%d", rand()%6+1);
	for(i=1;i<20;i++){
		printf("\b%d", rand()%6+1);
		Sleep(50);
	}putchar('\n');
	printf("\t\t\t\t\t���� ���� : %d\n", value);
	printf("\t\t\t\t\t������ ���� : %d\n", choice);
	if(value==choice){
		putchar('\a');
		printf("\t\t\t\t\t���ڰ� �����ϴ�. ���� ���̽��ϴ�!!!\n");
		money += bet * 3;
		save_money();
	}	
	else if(value==choice+1||value==choice-1){
		printf("\t\t\t\t\t���̰� 1 �Դϴ�. ���� ���̽��ϴ�!!!\n");
		money += bet * 2;
		save_money();
	}
	else {
		save_money();
		printf("\t\t\t\t\t���� �Ҿ����ϴ�...\n");
	} 		
				
	if( money<=0 ) {
		save_money();
		return ;
	}
	printf("\t\t\t\t\t�ٽ� �Ͻðڽ��ϱ�? (Y/N) : ");
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

		printf("\t\t\t\t\t     ������������ ���� �޴������������� \n");
		printf("\t\t\t\t\t     �� 1. Ȧ¦        (x2)�� \n");
		printf("\t\t\t\t\t     �� 2. �ֻ���   (x2~x3)�� \n");
		printf("\t\t\t\t\t     �� 3. �渶     (x2~x9)�� \n");
		printf("\t\t\t\t\t     �� 4. ������          �� \n");
		printf("\t\t\t\t\t     �� 5. ������          �� \n");
		printf("\t\t\t\t\t     �������������������������������������������� \n");
		printf("\t\t\t\t\t  ������� �Ͻðڽ��ϱ�? : "); 

		scanf("%d", &gm);
		fflush(stdin);
		putchar('\a');
		if(money<=0 && (gm>=1 && gm<=3)){
			printf("  ���� �����մϴ�.\n  "); system("pause");  
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
						printf("���� �����ϰ� ���α׷��� �����մϴ�."); 
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

