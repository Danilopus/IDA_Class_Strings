#include <iostream>
#include <string>
#include <windows.h>
#include <time.h>
#include <algorithm>
//#include <array>

// Service functions prototypes ------------------------------------
int Get_Int_SA();				// String-analysis вариант фильтра INTEGER
int Get_Int_Positive();			// String-Analysis вариант проверки ввода INTEGER_POSITIVE		
int Get_Int_PG();				// peek&get вариант проверки ввода INTEGER	
double Get_Dbl_SA();		// String-analysis вариант фильтра DOUBLE.
double Get_Dbl_Positive();	// String-analysis вариант фильтра DOUBLE_POSITIVE
double Get_Dbl_PG();		// peek&get вариант проверки ввода DOUBLE	
int Get_Random(int Range_min, int Range_max);
double Get_Random(double Range_min, double Range_max);
template <typename ANY> void Fill_Array_with_Random(ANY arr[], int Size, ANY Range_min, ANY Range_max);
template <typename ANY> void Array_Console_Out(ANY arr[], int Size);

// Classwork 27.03.2023 ----------------------------------------------------	

//Task 1
void Task_1()
{
//Определение: Строка - упорядоченный набор символьных элементов, объедененных в массив, в конце которого располагается нуль-терминатор

//Definition: String - an ordered set of character elements combined into an array, at the end of which there is a null terminator

	//C-Style string. Variant 1
	char C_String[] = { 'H','e','l','l','o','\0' };
	int string_size = sizeof(C_String) / sizeof(C_String[0]);

	std::cout << "\n" << "Array_Console_Out(C_String, 5):";
	Array_Console_Out(C_String, 5);

	std::cout << "\n" << "for (int i = 0; i < string_size; i++):\n";
	for (int i = 0; i < string_size; i++)
		std::cout << C_String[i];
	std::cout << "\n";

	std::cout << "\n" << "std::cout << C_String :\n";
	std::cout << C_String << "\n\n";

	//C-Style string. Variant 2
	char C_String_2[] = { "Hello again!" };
	std::cout << "\n" << "char C_String_2[] = { \"Hello again!\" }";
	std::cout << "\n" << "std::cout << C_String_2:\n";
	std::cout << C_String_2 << "\n\n";

}
//Task 2
void Task_2()
{
	// C++ Style strings via <string>
	std::string CPP_String;
	std::cout << "\n" << "std::cout << CPP_String :\n";
	std::cout << CPP_String << "\n\n";

	CPP_String = { "Hello twice!" };
	std::cout << "\n" << "std::cout << CPP_String :\n";
	std::cout << CPP_String << "\n\n";

	CPP_String = { "Hello third!" };
	std::cout << "\n" << "std::cout << CPP_String :\n";
	std::cout << CPP_String << "\n\n";

	//Конкатенация - процесс слияния двух или более строк в одну новую

	//Concatenation - the process of merging two or more strings into one new one

	CPP_String = CPP_String + " (C) Studentio";
	CPP_String += "!!!" + 'j'; //???
	CPP_String += "!!!";
	CPP_String += '?';
	CPP_String += '?'+'?';
	CPP_String += '?' + '?' + '?';
	CPP_String += '???' + '??' + '?';
		
	std::cout << "\n" << "!!!+r" << "!!!" + 'r';

	std::cout << "\n" << "std::cout << CPP_String :\n";
	std::cout << CPP_String << "\n\n";
}
void Task_3()
{
	//String console in
	std::cout << "What is your name?\n -> ";
	std::string CPP_String_2;
	std::cin >> CPP_String_2;
	std::cout << "\nHello, " << CPP_String_2 << "! How is your day?\n";

	std::cout << "What is your job?\n -> ";
	std::string CPP_String_Job;
	//std::cin.clear();
	//std::cin.sync();
	std::cin.ignore();
	std::getline(std::cin, CPP_String_Job);
	std::cout << "\n" << CPP_String_Job << " is cool!\n\n";

	std::cout << "How old are you?\n -> ";
	std::string CPP_String_age;
	std::cin >> CPP_String_age;
	std::cout << "Once upon a time and I was " << CPP_String_age << " age old...\n";
}
void Task_4()
{
	// Метод (в ООП) - функция, применяемая к объектам какого-либо класса. Каждый класс обаладает своим набором методов

// A method (in OOP) -  is a function applied to objects of some class. Each class has its own set of methods.

	std::string CPP_String_test = "Hello, how are you?";

	// string.length(), string.size() - return size of a string
	std::cout << "\n" << "Size = " << CPP_String_test.size();
	std::cout << "\n" << "Length = " << CPP_String_test.length();


	// string.insert - make an insertion
	CPP_String_test.insert(3, "xxx");
	std::cout << "\n\n" << "Insert = " << CPP_String_test;

	std::cout << "\n" << "Insertx2 = " << CPP_String_test.insert(3, "*insertion*");

	//string.replace
	std::cout << "\n\n" << "Replace = " << CPP_String_test.replace(30, 5, "*replace*");

	//string.find
	std::cout << "\n\n" << "Find *replace* = " << CPP_String_test.find("*replace*");
	std::cout << "\n" << "Find *ins* = " << CPP_String_test.find("*ins*");
	std::cout << "\n" << "Find *ins = " << CPP_String_test.find("*ins");

	//string.rfind
	std::cout << "\n\n" << "Rfind xx = " << CPP_String_test.rfind("xx");
	std::cout << "\n" << "Rfind xx, 5 = " << CPP_String_test.rfind("xx", 5);

	//string.substr retutn sub string from original string
	std::cout << "\n\n" << "Substr 3 = " << CPP_String_test.substr(3);
	std::cout << "\n" << "Substr 3,11 = " << CPP_String_test.substr(3, 11);


}

// MAIN ------- MAIN ------- MAIN ------- MAIN ------- MAIN --------



int main()
{
	//Task_1();
	//Task_2();
	//Task_3();
	//Task_4();
	

	// to_string
	int Var = 12345;
	//std::string Str_from_Num = Var;
	std::string Str_from_Num = std::to_string(Var);
	Str_from_Num += '!';

	std::cout << "\n\n"<<"Str_from_Num: " << Str_from_Num;

	Var += char('!');
	Str_from_Num = std::to_string(Var);
	std::cout << "\n\n" << "Str_from_Num: " << Str_from_Num;

	//stoi stod
	std::cout << "\n\nEnter some number -> ";
	std::getline(std::cin, Str_from_Num);
	Var = std::stoi(Str_from_Num);
	Var++;	
	std::cout << "Var = " << Var;

	//Letter case
	std::string hello_str = "HeLLo";
	std::cout << "\n\n" << char(std::tolower(hello_str[0]));
	std::cout << "\n\n" << hello_str;

	std::tolower(hello_str[1]);

	for (int i=0; i< hello_str.length();i++)
		hello_str[i]= std::tolower(hello_str[i]);
	std::cout << "\n\n" << hello_str;

	for (int i = 0; i < hello_str.length(); i++)
		hello_str[i] = std::toupper(hello_str[i]);
	std::cout << "\n\n" << hello_str;

	
	std::cout << "\n\n";
	system("pause");
	return 0;
}

// Service functions -----------------------------------------
int Get_Int_SA() {
	std::string a;
	std::cin.sync(); 
	std::cin.clear(); 
	getline(std::cin, a);
	if (a != "")
	{

		if ((a.find_first_not_of("-0123456789") == -1))
		{
			for (int i = 1; i < a.size(); i++) // определяем есть ли минусы кроме первого символа
			{
				if (a[i] == '-') 
				{
					std::cout << "Input Error: Minus misstanding. [INTEGER] expected.\n";
					return Get_Int_SA();
				}
			}
			try
			{
				return stoi(a);
			}
			catch (std::out_of_range)
			{
				std::cout << "Input Error: Data type overflow. [INTEGER] expected.\n";
				return Get_Int_SA();
			}


		}
		else
		{
			std::cout << "Input Error: Incorrect symbol. [INTEGER] expected.\n";
			return Get_Int_SA();
		}
	}
	else
	{
		std::cout << "Input Error: NULL input. [INTEGER] expected.\n";
		return Get_Int_SA();
	}
}
int Get_Int_Positive()
{
	std::string a;
	std::cin.sync();
	std::cin.clear();
	getline(std::cin, a);
	if (a != "") 
	{

		if ((a.find_first_not_of("0123456789") == -1))
		{
			try{
				return stoi(a);
			}
			catch (std::out_of_range){
				std::cout << "Input Error: overflow. Positive [INTEGER] expected.\n";
			}
		}
		else
		{
			std::cout << "Input Error: Positive [INTEGER] expected.\n";
			return Get_Int_Positive();
		}		
	}
	else
		std::cout << "Input Error: NULL input. Positive [INTEGER] expected.\n";
	return Get_Int_Positive();
}
int Get_Int_PG()
{
	int a;
	while (!(std::cin >> a) || (std::cin.peek() != '\n'))
	{
		std::cin.clear();
		while (std::cin.get() != '\n');
		std::cout << "Input error! [INTEGER] expected. Repeat please...\n";
	}
	return a;
}
double Get_Dbl_SA(){
	std::string a;
	std::cin.sync();
	getline(std::cin, a);
	if (a == "") { std::cout << "\nInput Error : NULL input\n"; return Get_Dbl_SA(); }
	if ((a.find_first_not_of("-.0123456789") == -1))
	{
		for (int i = 1; i < a.size(); i++) // Проверяем отсутсвие лишних минусов
		{
			if (a[i] == '-')
			{
				std::cout << "\nInput Error: Minus misstanding. [DOUBLE] expected.\n";
				return Get_Dbl_SA();
			}

		}
		bool Dot_Flag = 0;
		for (int i = 0; i < a.size(); i++) // проверяем отсутсвие лишних точек
		{
			if (a[i] == '.')
			{
				if (Dot_Flag == 1)
				{
					std::cout << "\nInput Error: Dot misstandig. [DOUBLE] expected.\n";
					return Get_Dbl_SA();
				}
				Dot_Flag = 1;
			}

		}		 	
				try{
					return stod(a);
				}
				catch (std::out_of_range) {
					std::cout << "Input Error: overflow. [DOUBLE] expected.\n";
					return Get_Dbl_SA();					
				}						
	}
	else {		
		std::cout << "Incorrect symbols: [DOUBLE] expected.\nUse dot instead of coma. Example 50.64\n";
		return Get_Dbl_SA();
	}
}
double Get_Dbl_Positive(){
	std::string a, dot = ".";
	std::cin.sync();
	std::cin.clear();
	getline(std::cin, a);
	if (a != "")
	{
		if ((a.find_first_not_of(".0123456789") == -1))
		{
			bool One_Dot_already = false;
			for (int i = 0; i < a.size(); i++)
			{				
				if (a[i] == dot[0] && One_Dot_already == true) //проверяем количество разделителей
				{
					std::cout << "Input Error: Dot misstandig. Positive [DOUBLE] expected.\n";
					return Get_Dbl_Positive();
				}
				if (a[i] == dot[0])	One_Dot_already = true;
			}
			try
			{				
				return stod(a);
			}
			catch (std::out_of_range)
			{
				std::cout << "Input Error: Data type overflow. Positive [DOUBLE] expected.\n";
				return Get_Dbl_Positive();
			}
		}
		else
		{
			//std::cout << "Incorrect symbols: positive REAL expected.\nUse coma instead of dot. Example 50,64\n"; // да точно говорю вот даже сообщение такое было, а теперь наоборот wtf*2?!
			std::cout << "Incorrect symbols: Positive [DOUBLE] expected.\nUse dot instead of coma. Example 50.64\n";
			return Get_Dbl_Positive();
		}
	}
	else
	{
		std::cout << "Input Error: NULL input. Positive [DOUBLE] expected.\n";
		return Get_Dbl_Positive();
	}
	return Get_Dbl_Positive();
}
double Get_Dbl_PG()
{
	double a;
	while (!(std::cin >> a) || (std::cin.peek() != '\n'))
	{
		std::cin.clear();
		while (std::cin.get() != '\n');
		std::cout << "Input error! [DOUBLE] expected. Repeat please...\n";
	}
	return a;
}
int Get_Random(int Range_min=-999, int Range_max=999)
{
	if (Range_min > Range_max) 
	{ 
		std::cout << "\nError: Range_min > Range_max. New range: [Range_max..Range_min]\n";
		std::swap(Range_min, Range_max);
	}
	//return (Range_min + rand() % (Range_max - Range_min + 1));
	double K_random = double((rand() % RAND_MAX)) / RAND_MAX;
	int random = Range_min + ((Range_max - Range_min) * K_random);
	//return Range_min + (Range_max - Range_min) * (rand() % RAND_MAX) / RAND_MAX;
	return random;
}
double Get_Random(double Range_min=-9999.0, double Range_max=9999.0)
{
	if (Range_min > Range_max)
	{
		std::cout << "\nError: Range_min > Range_max. New range: [Range_max..Range_min]\n";
		std::swap(Range_min, Range_max);
	}
	return 	Range_min + (Range_max - Range_min) * double(rand() % RAND_MAX) / RAND_MAX;	
}
template <typename ANY> void Array_Console_Out(ANY arr[], int Size)
{
	std::cout << "\n[";
	for (int i = 0; i < Size; i++)
		std::cout << arr[i] << ", ";
	std::cout << "\b\b]\n";
}
template <typename ANY> void Fill_Array_with_Random(ANY arr[], int Size, ANY Range_min, ANY Range_max)
{
	for (int i = 0; i < Size; i++)
	{
		arr[i] = Get_Random(Range_min, Range_max);		
	}
}
