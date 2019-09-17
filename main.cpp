/* @autor Rakhmanin Danila aka Radist AltSTU PI-82
 *
 * Придумать свой вариант задания и реализовать его (Аналогично заданию 2)
 *
 * Еда. 3 поля:
 * - вкус 0 ... 10
 * - сытность 0 ... 10
 * - вид 0 ... 10
 *
 */


#include <iostream>

using namespace std;

struct food
{
	int taste;
	int satiety;
	int view;
};

//Процедура инициализации
int Init(food &food1)
{
	cout << "Init food" << endl;
	food1.view = food1.taste = food1.satiety = 0;
	return 0;
}

/*
//Процедура вывода на экран
int Display()
{

}

//Процедура ввода с клавиатуры
int Read()
{

}

//
int Add()
{

}

//*/


int main()
{
	food cutlet;
	Init(cutlet);

	return 0;
}
