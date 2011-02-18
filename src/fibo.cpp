#include <iostream>
#include "bigint.h"

using namespace std;

Bigint zero("0");
Bigint one("1");
Bigint two("2");

Bigint *series, value;

Bigint fibo (int n)
{
	Bigint a, b;
	if(!(series[n] == zero))
	{	
		a=fibo(n-1);
		b=fibo(n-2);
		series[n]=a+b;		
		cout<<n<<": "<<series[n]<<endl<<endl;

	}
	return series[n];
}
int main()
{
	int n;
	cout<<"Enter the number of terms required: ";	
	cin>>n;
	series = new Bigint[n+1];
	series[1]=one;
	series[2]=one;
	value=fibo(n);
	cout<<value<<endl;

	
}
