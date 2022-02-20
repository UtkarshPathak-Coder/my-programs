#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct triangle
{
	int a;
	int b;
	int c;
};

typedef struct triangle triangle;
void sort_by_area(triangle* tr, int n) {
    int i,j;
    float p,s[100],temp2;
    triangle temp;
    for(i=0;i<n;i++)
    {
        p=(tr[i].a+tr[i].b+tr[i].c)/2;
        s[i]=sqrt((p*(p-tr[i].a)*(p-tr[i].b)*(p-tr[i].c)));
    }
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
           if(s[j+1]<s[j])
           {temp=tr[j+1];
            temp2=s[j+1];
            tr[j+1]=tr[j];
            s[j+1]=s[j];
            tr[j]=temp;
            s[j]=temp2;
        }}
    }
  
}

int main()
{
	int n;
	scanf("%d", &n);
	triangle *tr = malloc(n * sizeof(triangle));
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &tr[i].a, &tr[i].b, &tr[i].c);
	}
	sort_by_area(tr, n);
    printf("ppp");
	for (int i = 0; i < n; i++) {
		printf("%d %d %d\n", tr[i].a, tr[i].b, tr[i].c);
	}
	return 0;
}