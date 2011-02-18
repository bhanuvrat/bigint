#include <iostream>
#include <stdlib.h>
#include <string.h>

#define size 32765

using namespace std;

class Bigint
{
	private:
		char num[size];
		void reverse();
	public:
		Bigint();
		Bigint(char*);
		friend istream& operator>> (istream &, Bigint &);
		friend ostream& operator<< (ostream&, Bigint &);
		friend Bigint toBigint(int);
		Bigint operator+ (const Bigint&);
		Bigint operator= (const Bigint&);
		Bigint operator- (const Bigint&);
		Bigint operator* (const Bigint&);
		   int operator==(const Bigint&);
};
Bigint toBigint(int);
