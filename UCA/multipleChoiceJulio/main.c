#include <stdio.h>
#include <stdlib.h>
/*
int fa(int a[]){
    return fb(a)+1;
}
int fb(int b[]){
    int i=0;
    for(i=0; b[i]!=0;i++){
        return b[i]+1;
    }
}

int main()
{
    int a[]={5,7,3,4,0};
    printf("\n%d%d", fa(a),fb(a));
    return 0;
}

int f(int a, int b){
    if((a&&b) || !b==!((a||b)&&b)) return 1; //1. , 2. 1,3. 1
    return 0;
}
int main()
{
    printf("\n%d%d%d", f(1,0),f(0,1),f(1,1));
    return 0;
}
int main()
{
    char x, y;
    x=getche();
    //y=getche();
    if(x!='s' || yx!='n') printf("\nError");
    else printf("\nCorrecto");
    return 0;
}

int main()
{   double a =9/2*6+9%2;
    printf("\n%lf", a);
    return 0;
}*/
int main()
{   int i,j,ctr=0;
    int myArray[7]={0};
    for(i=1; i<=3; i++){
        for(j=1; j<=2; j++){
            if(i%j){
                myArray[j*i]=ctr;
            }ctr++;
        }
    }
    for(i=1; i<=7; i++) printf("%d[%d] - ",myArray[i],i);
    return 0;
}
