#include <stdio.h>
#include <math.h>
int main(){
    int n,i,index,o,sum,diff,mul;
    long long int power;
    scanf("%d",&n);
    int num[n];
    for(i=0;i<n;i++){
        scanf("%d",&num[i]);
    }
    scanf("%d",&index);
    int idx[index];
    for(i=0;i<index;i++){
        scanf("%d",&idx[i]);
    }
    scanf("%d",&o);
    switch (o)
    {
    case 1:
        sum=0;
        for(i=0;i<index;i++){
            sum+=num[idx[i]];
        }
        printf("%d",sum);
        break;
    case 2:
        diff=0;
        diff+=num[idx[0]];
        for(i=1;i<index;i++){
            diff-=num[idx[i]];
        }
        printf("%d",diff);
        break;
    case 3:
        mul=1;
        for(i=0;i<index;i++){
            mul*=num[idx[i]];
        }
        printf("%d",mul);
        break;
    case 4:
        power=0;
        for(i=0;i<index;i++){
            power+=num[idx[i]];
        }
        power=(pow(power,power));
        printf("%lld",power);
        break;
    default:
        break;
    }
    return 0;
}