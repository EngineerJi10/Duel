#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
using namespace std;
const int width=100,delay=130;

int main(){
    int pos1=1,pos2=width-1,attack1=0,attack2=0,life1=100,life2=100,cnt1=0,cnt2=0;
    char fly1=0,fly2=0;
    while(life1>0 && life2>0){
        char key=0;
        if(_kbhit()) key=_getch();
        if(key=='a' && 0<=pos1-1) pos1--;
        else if(key=='d' && pos1+1<pos2) pos1++;
        else if(key=='s') fly1=1;
        if(key=='4' && pos1<pos2-1) pos2--;
        else if(key=='6' && pos2+1<=width) pos2++;
        else if(key=='5') fly2=1;
        if(fly1 && cnt1==0) attack1++;
        if(fly2 && cnt2==0) attack2++;
        if(pos2-pos1+1<=attack1+attack2){
            if(attack1>attack2) cnt1=delay;
            else cnt2=delay;
            fly1=fly2=attack1=attack2=0;
        }
        if(pos1+attack1==pos2) life2-=(width-pos2+pos1),attack1=0,fly1=fly2=0;
        else if(pos2-attack2==pos1) life1-=(width-pos2+pos1),attack2=0,fly1=fly2=0;
        for(int i=0; i<pos1; i++) printf(" ");
        printf("!");
        for(int i=0; i<attack1; i++) printf("+");
        int t=pos2-pos1-attack1-attack2-1;
        for(int i=0; i<t; i++) printf(" ");
        for(int i=0; i<attack2; i++) printf("+");
        printf("!");
        for(int i=0; i<width-pos2; i++) printf(" ");
        printf("%d %d\n",life1,life2);
        if(cnt1>0) cnt1--;
        else if(cnt2>0) cnt2--;
    }
    if(life1>0) printf("Player 1 won");
    else printf("Player 2 won");
    _sleep(1000);
    return 0;
}
