#include<iostream>
#include<fstream>
using std::cout;
using std::cin;
using std::endl;
//#define WRITE_TO_FILE
#define READ_FROM_FILE
void main()
{
	setlocale(LC_ALL, "");
#ifdef WRITE_TO_FILE
	//1.создаем поток:
	std::ofstream fout;
	//2.открываем поток:
	fout.open("File.txt", std::fstream::app);
	//3.пишем в поток:
	fout << "Hello Files ";
	//4.Если поток был открыт его нужно закрыть:
	fout.close();

	//открываем файл с командной строки
	system("notepad File.txt");
#endif // WRITE_TO_FILE

//1.Создаем и открываем поток:
	std::fstream fin("File.txt");
//2.Проверяем открылся ли поток:
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
		fin.close();//потоок есть смысл закрывать только если он был открыт
	}
	else
	{
		std::cerr << "Error: file not found" << endl;
	}

}