#include <stdio.h>

int main(void){
    int n,m;
    scanf("%d %d",&n,&m);

    int a[n];
    for(int i=0;i<n;i++) scanf("%d",&a[i]);

    int an[n];
    for(int i=0;i<n-1;i++) an[i] = a[i];

    int count=0;
    for(int i=0;i<n;i++){
        for(int j=1;j<m;j++){
            int s=0;
            for(int k=0;k<n;k++){
                if(an[k] == j) break;
                s++;
            }
            if(s!=n) goto show;
        }
 
        count++;
        for(int ii=0;ii<n-count;ii++) an[ii] = a[ii];
    }

    show:
        printf("%d",count);

    return 0;
}
