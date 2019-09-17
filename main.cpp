/* @autor Rakhmanin Danila aka Radist AltSTU PI-82
 *
 * Разработать тип данных и набор процедур для работы с ним
 * (не использовать конструкции ООП, желательно использовать язык С, использовать Git)
 *
 * 18. Класс координаты точки на карте состоит из трех вещественных полей (градусы, минуты и секунды).
 * Реализовать метод округления до градусов и вычисления координат точки, находящейся на середине отрезка,
 * соединяющего две другие точки (метод называется add).
 */


#include <iostream>

using namespace std;

struct coordinates
{
	float degrees;
	float minutes;
	float seconds;
};

//Процедура инициализации
int Init(coordinates &kek)
{
	cout << "Init data." << endl;
	kek.degrees = kek.minutes = kek.seconds = 0;
	return 0;
}

//Процедура вывода на экран
int Display(coordinates &kek)
{
	cout << "degrees = " << kek.degrees;
	cout << " minutes = " << kek.minutes;
	cout << " seconds = " << kek.seconds << endl;
}

//Процедура ввода с клавиатуры
int Read(coordinates &kek)
{
	cout << "Write degrees: ";
	cin >> kek.degrees;

	cout << "Write minutes: ";
	cin >> kek.minutes;

	cout << "Write seconds: ";
	cin >> kek.seconds;
}

int main()
{
	coordinates one, two;
	Init(one);
	cout << "Write two:" << endl;
	Read(two);

	cout << "One: ";
	Display(one);
	cout << "Two: ";
	Display(two);

	return 0;
}
