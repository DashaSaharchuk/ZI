#include<stdlib.h>
#include<iostream>
#include<math.h>
#include <time.h>


using namespace std;

long long int BVSM(long long int x, long long int  a, long long int  b)//x - число, a - степень, b - модуль
{
	long long int res = 1;
    while (a != 0) 
    {
    	if (a & 1 == 1)
    		res = (res * x) % b;
   		x = (x * x) % b;    
   	    a = a >> 1;   
    }
    return res;
}

struct arrNOD //струдктура для НОДа
{
    long long int a1, a2, a3;
};
 
// Возвращает набор из трёх чисел - {НОД(a,b), x, y}
// Требуется a,b > 0  и a >= b

arrNOD NOD(long long int a, long long  int b)
{
    arrNOD U = {a, 1, 0}, V = {b, 0, 1};
    while (V.a1 != 0)
    {
        long long int q = U.a1 / V.a1;
        arrNOD T = {U.a1 % V.a1, U.a2 - q * V.a2, U.a3 - q * V.a3};
        U = V;
        V = T;
    }
    return U;
}

bool isPrime(int p) //проверка на примитивное число
{
   if (p <= 1) return false;
   long long int b = (long long int)pow(p, 0.5); 
   for (long long int i = 2; i <= b; ++i)
   {
      if ((p % i) == 0) return false;        
   }     
   return true;  
}

long long int Prime(long long int range) //рандомное примитивное число, range - сокращение полей рандома 
{
	long long int x;
	srand(time(NULL));
	do
	{
    	x = rand() % range;
    } while(isPrime(x) == false);
    return x;
}

long long int KeyDH(long long int q)
{
	long long int range = 10000;
	long long int p, g, Xa, Xb, Ya, Yb, Zab, Zba; 
	p = 2*q + 1;
	for (g = 2; g < p - 1; g++) //находим g 
		if (BVSM(g, q, p) != 1) break;
	
	Xa = Prime(range);//секретные ключи
	Xb = Prime(range);
	
	Ya = BVSM(g, Xa, p);//открытые ключи
	Yb = BVSM(g, Xb, p);	
	
	Zab = BVSM(Yb, Xa, p);
	Zba = BVSM(Ya, Xb, p);
	
	if (Zab == Zba) return Zab;
	else return 0;
}

