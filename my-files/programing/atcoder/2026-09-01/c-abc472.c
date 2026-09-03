#include <stdio.h>

/*
<方針>
    m日間の合計<=kならばYesを表示する

    1. m日前のデータをtotalから削除
    2. total+a[i]<=kならi日目のデータを入れる Yesを表示する
    3. そうでないならa[i]を0にして足さない

    体感B,C問題あたりからint型でオーバフローする可能性がある
    オーバフローしそうならlong longを積極的に使う
*/

int main(){
    int n,m;
    long long k;
    scanf("%d %d %d",&n,&m,&k);

    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }

    long long total=0;
    for(int i=0;i<n;i++){
        if(i>=m)total -= a[i-m];
        if(total+a[i]<=k){
            total += a[i];
            puts("Yes");
        }else{
            puts("No");
            a[i]=0;
        }

        //if(i>=m)total -= a[i-m]; ここでtotalから除算する処理を実行してもいい
        //printf("%d ",total);
    }

    return 0;
}
