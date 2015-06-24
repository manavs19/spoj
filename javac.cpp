#include <stdio.h>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

int max(int a, int b)
{
	return a>b?a:b;
}

int main()
{
	char s[104];
	while(scanf("%s",s)>0)
	{
		char t[300];int j=0;
		
		int error=0;
		if(isupper(s[0]) || s[0]=='_')error=1;

		int lang=0;//1 is c++, 2 is java
		int i;
		int wordFlag=0;
		for(i=0;i<strlen(s);++i)
		{
			char ch = s[i];
			if(ch=='_')//C++
			{
				if(wordFlag || lang==2){error=1;break;}
				lang=1;
				wordFlag=1;
			}
			else if(isupper(ch))//Java
			{
				if(lang==1){error=1;break;}
				lang=2;
				t[j++]='_';
				t[j++]=(ch+32);
			}
			else if(islower(ch))
			{
				if(wordFlag)
				{
					t[j++] = (ch-32);
					wordFlag=0;
				}
				else
					t[j++] = ch;
			}
			else
			{
				error=1;
				break;
			}
		}
		t[j] = 0;
		if(error || wordFlag)printf("Error!\n");
		else printf("%s\n", t);
	}

	return 0;
}