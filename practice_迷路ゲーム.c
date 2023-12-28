#include <stdio.h>
// インテンドブロックがちゃんとしてなかったからバグっていた
int main(void){
    int meiro[5] ={1,2,3,1,1};
    int i =0;
    int kaito=0;

    while(i<5)
        {
        printf("右なら1,前なら2,左なら3と入力してください¥n");
        scanf("%d",&kaito);
        }
        if(meiro[i]==kaito)
        {
            printf("道がありました、先に進みましょう");
            i=i+1;
        }
        else
            {printf("残念でした、別の道を行きましょう");}
    if(i==5){
        printf("ゴールおめでとう¥n");
    }
    return 0;
}