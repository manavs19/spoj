#include <iostream>
#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <sstream>

using namespace std;

class BigInt
{
	public:
		string number;

		BigInt(){number = "";}
		BigInt(string s){number = s;}
		BigInt(int n)
		{
			stringstream ss;
			ss << n;
			number = ss.str();
		}

		BigInt operator+(BigInt);
		BigInt operator*(BigInt);

		friend ostream & operator<<(ostream &, const BigInt &);
};

BigInt BigInt::operator+(BigInt other)
{
	string a = this->number, b = other.number;

	int len1 = a.length();
	int len2 = b.length();

	if(len1==0)return other;
	if(len2==0)return *this;

	int i = len1-1, j = len2-1;
	string sum = "";
	int carry = 0;
	while(i>=0 && j>=0)
	{
		int d1 = a[i]-48;
		int d2 = b[j]-48;

		int temp = d1+d2+carry;
		int currSum = temp%10;
		carry = temp/10;

		char ch = currSum + 48;
		sum = ch+sum;

		i--;
		j--;
	}

	while(i>=0)
	{
		int d1 = a[i]-48;
		int temp = d1+carry;
		int currSum = temp%10;
		carry = temp/10;

		char ch = currSum + 48;
		sum = ch+sum;

		i--;
	}

	while(j>=0)
	{
		int d2 = b[j]-48;
		int temp = d2+carry;
		int currSum = temp%10;
		carry = temp/10;

		char ch = currSum + 48;
		sum = ch+sum;

		j--;
	}

	if(carry != 0)
	{
		char ch = carry + 48;
		sum = ch + sum;
	}

	BigInt ans(sum);
	return ans;
}

BigInt BigInt::operator*(BigInt other)
{
	int times = atoi(other.number.c_str());
	BigInt product("0");
	for (int i = 0; i < times; ++i)
	{
		product = product+*this;
	}

	return product;
}

ostream & operator<<(ostream & os, const BigInt & x)
{
	os<<x.number<<endl;
	return os;
}

int main()
{
	BigInt arr[101];
	arr[0] = BigInt("1");
	for (int i = 1; i <= 100; ++i)
	{
		arr[i] = arr[i-1] * BigInt(i);
	}
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);	
		cout<<arr[n];
	}

	return 0;
}