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

int main()
{
	coordinates one;
	Init(one);

	cout << "One: ";
	Display(one);

	return 0;
}
