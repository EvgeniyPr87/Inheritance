#include<iostream>
#include<fstream>
using std::cout;
using std::cin;
using std::endl;
//#define WRITE_TO_FILE
//#define READ_FROM_FILE
void main()
{
	setlocale(LC_ALL, "");
#ifdef WRITE_TO_FILE
	//1.������� �����:
	std::ofstream fout;
	//2.��������� �����:
	fout.open("File.txt", std::fstream::app);
	//3.����� � �����:
	fout << "Hello Files ";
	//4.���� ����� ��� ������ ��� ����� �������:
	fout.close();

	//��������� ���� � ��������� ������
	system("notepad File.txt");
#endif // WRITE_TO_FILE

#ifdef READ_FROM_FILE
	//1.������� � ��������� �����:
	std::fstream fin("File.txt");
	//2.��������� �������� �� �����:
	if (fin.is_open())
	{
		while (!fin.eof())
		{
			const int SIZE = 256;
			char sz_buffer[SIZE] = {};
			//fin >> sz_buffer;
			fin.getline(sz_buffer, SIZE);
			cout << sz_buffer << endl;
		}
		fin.close();//����� ���� ����� ��������� ������ ���� �� ��� ������
	}
	else
	{
		std::cerr << "Error: file not found" << endl;
	}
#endif // READ_FROM_FILE


}