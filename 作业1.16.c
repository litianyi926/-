#include <stdio.h>
int main()
{
    int X,Y,Z,t;
    scanf("%d",&X);
    scanf("%d",&Y);
    scanf("%d",&Z);
    if(X<Y)
    {
        t = X;
        X = Y;
        Y = t;
    }
    if(X<Z)
    {
        t = X;
        X = Z;
        Z = t;
    }
    if(Y<Z)
    {
        t = Y;
        Y = Z;
        Z = t;
    }
    printf("%d %d %d\n",X,Y,Z);
    return 0;
}
