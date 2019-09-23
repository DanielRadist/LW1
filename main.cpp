/* @autor Rakhmanin Danila aka Radist AltSTU PI-82
 *
 * Разработать тип данных и набор процедур для работы с ним
 * (использовать ООП, использовать Git)
 *
 * 18. Класс координаты точки на карте состоит из трех вещественных полей (градусы, минуты и секунды).
 * Реализовать метод округления до градусов и вычисления координат точки, находящейся на середине отрезка,
 * соединяющего две другие точки (метод называется add).
 */


#include <iostream>

using namespace std;

class coordinates
{
private:
	float degrees, minutes, seconds;
public:
	//Процедура инициализации
	int Init()
	{
		cout << "Init data." << endl;
		degrees = minutes = seconds = 0;
		return 0;
	}
	//Процедура вывода на экран
	int Display()
	{
		cout << "degrees = " << degrees;
		cout << " minutes = " << minutes;
		cout << " seconds = " << seconds << endl;
		return 0;
	}
	//Процедура ввода с клавиатуры
	int Read()
	{
		cout << "Write degrees: ";
		cin >> degrees;

		cout << "Write minutes: ";
		cin >> minutes;

		cout << "Write seconds: ";
		cin >> seconds;
		return 0;
	}
	//Средняя точка м/д двух точек
	int Add(coordinates &kek, coordinates &lol)
	{
		degrees = (kek.degrees + lol.degrees) / 2;
		minutes = (kek.minutes + lol.minutes) / 2;
		seconds = (kek.seconds + lol.seconds) / 2;
		return 0;
	}
	//округление до градусов
	int Round()
	{
		if(seconds >= 30)
			minutes += 1;
		if(minutes >= 30)
			degrees += 1;

		seconds = minutes = 0;
		return 0;
	}
};

int main()
{
	coordinates one, two, three;
	one.Init();
	cout << "Write two:" << endl;
	two.Read();

	cout << "One: ";
	one.Display();
	cout << "Two: ";
	two.Display();

	three.Add(one, two);
	cout << "Three: ";
	three.Display();

	three.Round();
	cout << "Round Three: ";
	three.Display();

	return 0;
}
