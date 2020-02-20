#include<iostream>
using namespace std;
#include<fstream>
bool kt_snt(int n)
{
	if (n < 2)
	{
		return false;
	}
	else if (n == 2)
	{
		return true;
	}
	else if (n > 2)
	{
		for (int i = 2; i < n; i++)
		{
			if (n % i == 0)
			{
				return false;
			}
		}
	}
	return true;

}
void doc_file(int a[], int& n, ifstream& filein)
{
	while (filein.eof() == false)
	{
		
		filein >> a[n];
		char x;
		filein >> x;
		n++;
	}
}
void ghi_file(int a[], int n, ofstream& fileout)
{
	for (int i = 0; i < n; i++)
	{
		if (kt_snt(a[i]) == true)
		{
			fileout << a[i]<<" ";
		}
	}
}
int main()
{
	ifstream filein;
	filein.open("input.txt", ios_base::in);
	int a[100];
	int n=0;
	doc_file(a, n, filein);
	filein.close();
	ofstream fileout;
	fileout.open("output.txt", ios_base::out);
	ghi_file(a, n, fileout);
	fileout.close();
	return 0;
}