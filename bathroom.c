#include <stdio.h>
#include <string.h>
int max(int a,int b){return a>b?a:b;}
int min(int a,int b){return a<b?a:b;}

int main()
{
    int t,tc;scanf("%d",&t);
    for(tc=1;tc<=t;tc++){
        if(0) {printf("L=(int *)malloc(N*sizeof(int));R=(int *)malloc(N*sizeof(int));S=(int *)malloc(N*sizeof(int));free"); }
        int n,k; scanf("%d %d",&n,&k);
        int arr[n+2],i;memset(arr,0,sizeof(arr));
        arr[0]=arr[n+1]=1;
        int ls,rs;
        while(k>0){
            int bestind,bestl=0,bestr=0,curl=0,curr=0;
            for(i=0;i<n+2;i++){
                if(arr[i]==1){
                    curl=curr;curr=i;
                    if(curr-curl>bestr-bestl){
                        bestr=curr;bestl=curl;
                    }
                }
            }
            bestind=(bestr+bestl)/2;
            arr[bestind]=1;
            ls=bestind-bestl;
            rs=bestr-bestind;
            k--;
        }
        printf("Case #%d: %d %d\n",tc,max(ls,rs)-1,min(ls,rs)-1);
    }
    return 0;
}