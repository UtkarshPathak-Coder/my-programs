#include<stdio.h>
int gcd(int,int);
int main()
{
    int n1,n2;
    printf("Enter the two numbers : ");
    scanf("%d%d",&n1,&n2);
    int gcdd=gcd(n1,n2);
    printf("%d",gcdd);
}
int gcd(int n1,int n2)
{
    if(n1%n2==0)
        return n2;
    return gcd(n2,n1%n2);
}
