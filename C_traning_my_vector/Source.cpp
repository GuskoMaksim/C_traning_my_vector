#include <iostream>
#include <Windows.h>
#include "My_cont_vector.h"

using namespace std;


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	My_cont_vector<int> f(5);
	for (int i = 0; i < f.getSize(); i++)
	{
		try
		{
			cout << f[i] << endl;
		}
		catch (const std::exception& e)
		{
			cout << e.what() << endl;
		}
	}
	cout << endl;
	f.clear();
	f.puch_back(5);
	f.puch_back(3);
	f.puch_back(12);
	f.puch_back(212);
	for (int i = 0; i < f.getSize() + 1; i++)
	{
		try
		{
			cout << f[i] << endl;
		}
		catch (const std::exception& e)
		{
			cout << e.what() << endl;
		}
	}
	cout << endl;
	My_cont_vector<double> s(5);
	s.clear();
	s.puch_back(3.4);
	s.puch_back(9.1);
	s.puch_back(12.2);
	s.puch_back(4.3);
	for (int i = 0; i < s.getSize() + 1; i++)
	{
		try
		{
			cout << s[i] << endl;
		}
		catch (const std::exception& e)
		{
			cout << e.what() << endl;
		}
	}
}