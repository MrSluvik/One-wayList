//Реалізуйте клас Однонаправлений список з методами: List(void);      ~List(void);      void pushBack(T data); //додає елемент підряд
//void popFront();//Видаляє перший елемент в списку;       void clear(); //Вадаляє всі елементи в списку
//int getSize(); void pushFront(T data); //в початок списку додає елемент;  void removeAt(int index);//видаляє елемент по вказаному індексу
//void popBack();     // видаляє з кінця спику елемент;      void insert(T data, int index); //вставка в заданий індекс
//list_count(x)//Повертає кількість елементів зі значенням x;   T& operator[](const int index);
#include <iostream>
#include "List.h"
using namespace std;
int main()
{
	List<int>A;
	A.pushBack(6);
	A.pushBack(13);
	A.pushBack(6);
	A.pushBack(87);

	A.pushFront(6);

	A.removeAt(2);
	A.popBack();
	A.insert(6, 2);
	
	cout << A.list_count(6)<<endl ;

	for (int i = 0; i < A.getSize(); i++)
	{
		cout << A[i] << "\t";

	}

}


