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

class food
{
private:
	int taste, satiety, view, salt;
public:
	//Процедура инициализации
	int Init()
	{
		cout << "Init food" << endl;
		view = taste = satiety = salt = 0;
		return 0;
	}
	//Процедура вывода на экран
	int Display()
	{
		cout << "taste:" << taste;
		cout << " satiety:" << satiety;
		cout << " view:" << view;
		cout << " salt:" << salt << endl;
		return 0;
	}
	//Процедура ввода с клавиатуры
	int Read()
	{
		cout << "taste: ";
		cin >> taste;

		cout << "satiety: ";
		cin >> satiety;

		cout << "view: ";
		cin >> view;
		return 0;
	}
	//объединить еду в блюдо
	int Add(food &food1, food &food2)
	{
		//food1 + food2 = food3
		taste = (food1.taste + food2.taste) / 2;
		satiety = food1.satiety + food2.satiety;
		view = (food1.view + food2.view) / 2;
		salt = (food1.salt + food2.salt) / 2;
		return 0;
	}
	//посолить еду
	int toSalt()
	{
		salt += 1;

		taste = taste / salt;
	}
};

int main()
{
	food cutlet, potatoes, cutletAndPotatoes;
	cutlet.Init();
	potatoes.Init();
	cutletAndPotatoes.Init();

	cout << "Cutlet: ";
	cutlet.Display();

	cout << "Read cutlet: ";
	cutlet.Read();
	cout << "Cutlet: ";
	cutlet.Display();

	cout << "Read potatoes: ";
	potatoes.Read();

	cout << "cutletAndPotatoes: ";
	cutletAndPotatoes.Add(cutlet, potatoes);
	cutletAndPotatoes.toSalt();
	cutletAndPotatoes.Display();

	cout << "cutletAndPotatoes to salt: ";
	cutletAndPotatoes.toSalt();
	cutletAndPotatoes.Display();

	return 0;
}
