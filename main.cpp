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
	return 0;
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
	return 0;
}

//Средняя точка м/д двух точек
int Add(coordinates &kek, coordinates &lol, coordinates &chebyrek)
{
	chebyrek.degrees = (kek.degrees + lol.degrees) / 2;
	chebyrek.minutes = (kek.minutes + lol.minutes) / 2;
	chebyrek.seconds = (kek.seconds + lol.seconds) / 2;
	return 0;
}

//округление до градусов
int Round(coordinates &kek)
{
	if(kek.seconds >= 30)
		kek.minutes += 1;
	if(kek.minutes >= 30)
		kek.degrees += 1;

	kek.seconds = kek.minutes = 0;
	return 0;
}

int main()
{
	coordinates one, two, three;
	Init(one);
	cout << "Write two:" << endl;
	Read(two);

	cout << "One: ";
	Display(one);
	cout << "Two: ";
	Display(two);

	Add(one, two, three);
	cout << "Three: ";
	Display(three);

	Round(three);
	cout << "Round Three: ";
	Display(three);

	return 0;
}
