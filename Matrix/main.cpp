#include<iostream>
#include<fstream>
#include"Matrix.h"
using namespace std;
//void display(Matrix& a)
//{
//	//cout << a.getColum();
//	for (int i = 0; i < a.getRows(); i++)
//	{
//		for (int j = 0; j < a.getColum(); j++)
//		{
//			cout << a.at(i+1, j+1) << '\t';
//		}
//		cout << '\n';
//	}
//}
int main()
{
	Matrix m{ 2,2 };
	m(1, 1) = 1;
	m(1, 2) = 2;
	m(2, 1) = 2;
	m(2, 2) = 3;
	//m.display();
	fstream ofs;
	ofs.open("cheema.txt", ios::out | ios::binary);
	if (!ofs)
	{
		cout << "File can`t be opened";
	}
	else
	{
		int row = m.getRows();
		int col = m.getColum();
		ofs.write((char*)&row, sizeof(int));
		ofs.write((char*)&col, sizeof(int));
		for (int i = 1; i <= row; i++)
		{
			ofs.write((char*)&m(i, 1),4 * col);
		}
		ofs.close();
	}
	ofs.open("cheema.txt", ios::in | ios::binary);
	if (!ofs)
	{
		cout << "File can`t be opened";
	}
	else
	{
		Matrix n;
		int row;
		int col;
		ofs.read((char*)&row, sizeof(int));
		ofs.read((char*)&col, sizeof(int));
		n.reSize(row, col);
		for (int i = 1; i <= row; i++)
		{
			ofs.read((char*)&n(i, 1), 4 * col);
		}
		ofs.close();
		n.display();
	}

	return 0;
}