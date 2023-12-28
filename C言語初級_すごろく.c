#include <stdio.h>
#include <stdlib.h>

int kujibiki(int seed) {
    int ransuu = 0;
    srand(seed); 
    // ランドは1から１０を出力する、3で割ることで最大でも2の値が出るようにできる
    // 0,1,2,0,1,2,0,1,2,0,って感じで計算結果はなると思うんだけど、その場合1が出る確率が一番高くないですか？
    // でもシード値が設定される場合は、またそれに酔っても変化するからランダムになると言えるらしい
    ransuu = 1 + rand() % 3; 
    return ransuu;
}

int main() {
    int HeadCount = 0;
    int increment = 0;
    int progress = 0;
    int turn = 0;
    int seed = 0;
    int MaxTurn = 0;
    
    printf("ペットすごろくです\n");
    printf("何人で遊びますか？半角数字で入力してください\n");
    scanf("%d", &HeadCount);

    while (HeadCount < 1) {
        printf("入力し直してください\n");
        scanf("%d", &HeadCount);
    }

    int masu[HeadCount];
    for (increment = 0; increment < HeadCount; increment++)
        masu[increment] = 0;
        
    while (turn < MaxTurn) {
        // incrementで人を管理。increment+1=人の襦袢
        for (increment = 0; increment < HeadCount; increment++) {
            if (masu[increment] < 7) {
                printf("%d人目の番です\n", increment + 1);
                printf("今マスは%dのところにあります\n", masu[increment]);
                printf("1~100まで好きな数字を入力してください\n");
                scanf("%d", &seed);
                
                while (seed <= 0 || seed > 101) {
                    progress = kujibiki(seed);
                    printf("%d", progress);
                    masu[increment] = masu[increment] + progress;
                }

                if (masu[increment] > 7) {
                    printf("おめでとう,%dすすんであがりです\n", progress);
                } else {
                    printf("%d進んで%dにつきました\n", progress, masu[increment]);
                }

                if (masu[increment] == 1) {
                    printf("お気に入りのおやつは？\n");
                } else if (masu[increment] == 2) {
                    printf("飲み物は？\n");
                } else if (masu[increment] == 3) {
                    printf("名前の由来は？\n");
                } else if (masu[increment] == 4) {
                    printf("一番可愛い仕草は？\n");
                } else if (masu[increment] == 5) {
                    printf("いつからかってる？\n");
                } else if (masu[increment] == 6) {
                    printf("お気に入りのおやつは？\n");
                } else {
                    printf("最後に一言\n");
                }
            }
        }
        turn++;
    }
    return 0;
}
