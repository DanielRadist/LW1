/* @autor Rakhmanin Danila aka Radist AltSTU PI-82
 *
 * Придумать свой вариант задания и реализовать его (Аналогично заданию 2)
 *
 * Еда. 3 поля:
 * - вкус 0 ...
 * - сытность 0 ...
 * - вид 0 ...
 * - солёность 0 ...
 *
 */


#include <iostream>

using namespace std;

struct food
{
	int taste;
	int satiety;
	int view;
	int salt;
};

//Процедура инициализации
int Init(food &food1)
{
	cout << "Init food" << endl;
	food1.view = food1.taste = food1.satiety = food1.salt = 0;
	return 0;
}


//Процедура вывода на экран
int Display(food &food1)
{
	cout << "taste:" << food1.taste;
	cout << " satiety:" << food1.satiety;
	cout << " view:" << food1.view;
	cout << " salt:" << food1.salt << endl;
	return 0;
}

//Процедура ввода с клавиатуры
int Read(food &food1)
{
	cout << "taste: ";
	cin >> food1.taste;

	cout << "satiety: ";
	cin >> food1.satiety;

	cout << "view: ";
	cin >> food1.view;
	return 0;
}

//объединить еду в блюдо
int Add(food &food1, food &food2, food &food3)
{
	//food1 + food2 = food3
	food3.taste = (food1.taste + food2.taste) / 2;
	food3.satiety = food1.satiety + food2.satiety;
	food3.view = (food1.view + food2.view) / 2;
	food3.salt = (food1.salt + food2.salt) / 2;
	return 0;
}

//посолить еду
int toSalt(food &food1)
{
	food1.salt += 1;

	food1.taste = food1.taste / food1.salt;
}


int main()
{
	food cutlet, potatoes, cutletAndPotatoes;
	Init(cutlet);
	Init(potatoes);
	Init(cutletAndPotatoes);

	cout << "Cutlet: ";
	Display(cutlet);

	cout << "Read cutlet: ";
	Read(cutlet);
	cout << "Cutlet: ";
	Display(cutlet);

	cout << "Read potatoes: ";
	Read(potatoes);

	cout << "cutletAndPotatoes: ";
	Add(cutlet, potatoes, cutletAndPotatoes);
	toSalt(cutletAndPotatoes);
	Display(cutletAndPotatoes);

	cout << "cutletAndPotatoes to salt: ";
	toSalt(cutletAndPotatoes);
	Display(cutletAndPotatoes);


	return 0;
}
