#include <iostream>
#include <stdlib.h>
#include <string.h>

#include "bigint.h"

using namespace std;

void Bigint::reverse()
{
	int i=0,len=strlen(num)-1;
	char ch;
	for(;i<=len/2;i++)
	{
		ch=num[i];
		num[i]=num[len-i];
		num[len-i]=ch;
	}
}
Bigint::Bigint()
{
	memset(num, 0, sizeof(num));
	num[0]='0';
}

Bigint::Bigint(char* tnum)
{
	strcpy(num,tnum);
	reverse();
}

Bigint Bigint::operator+ (const Bigint &operand)
{
	int i=0,carry=0,a,b;
	Bigint sum;
	
	for(i=0; i<size && (num[i] || operand.num[i] || carry);i++)
	{
		a=num[i];
		b=operand.num[i];
		
		if(a) a-=48;
		if(b) b-=48;
		
	
		sum.num[i]= a + b + carry;
		carry = sum.num[i] / 10;
		sum.num[i]%=10;
		
		sum.num[i]+=48;
	}
	return sum;
}

Bigint Bigint::operator= (const Bigint &operand)
{
	strcpy(num, operand.num);
	return operand;
}

istream& operator>>(istream & input, Bigint &operand)
{
	input>>operand.num;
	operand.reverse();
	return input;
}

ostream& operator<<(ostream & output, Bigint &operand)
{
	operand.reverse();
	output<<operand.num;
	operand.reverse();
	return output;
}
int Bigint::operator==(const Bigint& operand)
{
	return strcmp(num,operand.num);
}
Bigint Bigint::operator-(const Bigint& operand)
{
}
Bigint Bigint::operator*(const Bigint& operand)
{
	int i,j, dig1, dig2, carry,value;
	int len1 = strlen (num);
	int len2 = strlen (operand.num);
	const char* op1, *op2;
	Bigint buff, prod;


	if(len1>len2) 
	{
		op1=num;
		op2=operand.num;
	}
	else
	{
		op1=operand.num;
		op2=num;
	}
	for(i=0; i<len2; i++)
	{
		carry=0;
		dig2=op2[i];
		if(dig2) dig2-=48;
		memset(buff.num, 0, sizeof(buff.num));
	
		for(j=0; j < len1 || carry ; j++)
		{
			dig1 = op1[j];
			if(dig1) dig1 -= 48;
			value = dig1 * dig2 + carry;
			carry = value / 10;
			value%= 10;
			buff.num[j+i] = value+48;
		}
		prod=prod+buff;
	}
	return prod;
}

Bigint toBigint(int n)
{
	int i;
	Bigint temp;
	for(i=0; n%10 || n/10; i++,n/=10)
		temp.num[i]=(n%10) + 48;
	return temp;
}
