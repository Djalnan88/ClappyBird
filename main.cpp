#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <conio.h>
#define W 15
#define H 8
using namespace std;

int m[H][W+1] = {0, }, bx = 1, by = H/2, ud = 1;
// board, player x, player y, obstacle position
void Make() // make the obstacle
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

void Flow() // scroll the board
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
    int c = 100, s, score = 0, sid;
    // interval between obstacle, speed of the game, score, seed of rand;
    printf("PUT ANY NUMBER\n");
    scanf("%d", &sid);
    printf("PUT SPEED (1 == 1/1000sec)\n");
    scanf("%d", &s);
    srand(sid);
    system("color A"); // green
    while(m[by][bx] != 2) { // play the game
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
        printf("score : %d\n", score++);
        Sleep(s--); // make the game faster
        if(s <= 1) s++;
        if(by > H) break; // outside the board
    }
    system("color 4"); // red
    printf("GAME OVER");
    getch();
    return 0;
}
