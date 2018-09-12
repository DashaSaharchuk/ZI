#include <time.h>
#include<stdlib.h>
#include<iostream>
#include<math.h>
#include"krip.h"


using namespace std;


int main()
{
	long long int a, b;
	arrNOD c;
	cin >> a >> b;
	c = NOD(a, b);
	cout << c.a1 << " " << c.a2 << " " << c.a3 << endl; 
	system("pause");    
	return 0;
}
