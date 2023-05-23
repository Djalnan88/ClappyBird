#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#define W 15
#define H 8
using namespace std;

int m[H][W+1] = {0, }, bx = 1, by = H/2;
int ud = 1;

void Make()
{
    if(ud == 1) {
        for(int i = H; i >= H-rand()%3-2; i--){
            m[i][W] = 2; m[i][W-1] = 2;
        }
        ud = 0;
    }
    else {
        for(int i = 0; i <= rand()%3+2; i++){
            m[i][W] = 2; m[i][W-1] = 2;
        }
        ud = 1;
    }
    return;
}

void Flow()
{
    for(int i = 0; i <= H; i++) {
        if(m[i][0] == 2) m[i][0] = 0;
        for(int j = 1; j <= W; j++) {
            if(m[i][j] != 1) m[i][j-1] = m[i][j];
        }
        m[i][W] = 0;
    }
    return;
}

int main()
{
    int c = 100, s = 300, sid;
    printf("PUT ANY NUMBER : ");
    scanf("%d", &sid);
    srand(sid);
    system("color A");
    while(m[by][bx] != 2) {
        system("cls");
        printf("PRESS A TO JUMP\n");
        m[by][bx] = 1;
        if(kbhit()){
            int ch = getch();
            if(ch == 'a' || ch == 'A') by -= 2;
        }
        if(by++ < 0) by = 0;
        for(int i = 0; i <= H; i++) {
            for(int j = 0; j <= W; j++) {
                printf("%d", m[i][j]);
            }
            printf("\n");
        }
        if(c++ > rand()%4+3){
            Make();
            c = 0;
        }
        Flow();
        printf("score : %d\n", 300-s);
        Sleep(s--);
        if(s == 100) s++;
        if(by > H) break;
    }
    system("color 4");
    printf("GAME OVER");
    getch();
    return 0;
}
