#include <iostream>
#include <Windows.h>
#include "My_cont_vector.h"

using namespace std;


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	My_cont_vector<int> f(5);
	f.clear();
	f.puch_back(5);
	f.puch_back(3);
	f.puch_back(12);
	f.puch_back(212);
	for (int i = 0; i < f.getSize(); i++)
	{
		cout << f[i] << endl;
	}
}