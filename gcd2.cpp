#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;

int gcd(int a, int b)
{
	return b==0?a:gcd(b,a%b);
}

int main() {	
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int a;char b[255];
		cin>>a>>b;
		if(a==0)
		{
			printf("%s\n", b);
			continue;
		}
		int d = 0;
        for (int i = 0; i<strlen(b); ++i)
            d = (d*10 + b[i] - '0') % a;
        printf("%d\n", gcd(a,d));	
	}    
    return 0;
}