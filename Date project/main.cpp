#include"String.h"
#include"Date.h"
int main()
{
	String a = { "hello" };
	String c = "Usman" + a;
	cout << c;
	Date d;
	String s = (String)d;
	cout << s;
	return 0;
}