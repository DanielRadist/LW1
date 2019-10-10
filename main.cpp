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

	~coordinates()
	{

	}

	//Процедура инициализации
	void init(int degress, int minutes, int seconds)
	{
		this->degrees = degress;
		this->minutes = minutes;
		this->seconds = seconds;
	}
	//Процедура вывода на экран
	void display()
	{
		cout << "degrees = " << degrees;
		cout << " minutes = " << minutes;
		cout << " seconds = " << seconds << endl;
	}
	//Процедура ввода с клавиатуры
	void read()
	{
		cout << "Write degrees: ";
		cin >> degrees;

		cout << "Write minutes: ";
		cin >> minutes;

		cout << "Write seconds: ";
		cin >> seconds;
	}
	//Средняя точка м/д двух точек
	void add(coordinates &kek, coordinates &lol)
	{
		degrees = (kek.degrees + lol.degrees) / 2;
		minutes = (kek.minutes + lol.minutes) / 2;
		seconds = (kek.seconds + lol.seconds) / 2;
	}
	//округление до градусов
	void round()
	{
		if(seconds >= 30)
			minutes += 1;
		if(minutes >= 30)
			degrees += 1;

		seconds = minutes = 0;
	}
};

int main()
{
	coordinates *oneAndTwo = new coordinates[2];
	coordinates *three = new coordinates;


	oneAndTwo[0].init(20, 15, 45);

	cout << "Write two:" << endl;
	oneAndTwo[1].read();

	cout << "One: ";
	oneAndTwo[0].display();
	cout << "Two: ";
	oneAndTwo[1].display();


	three->add(oneAndTwo[0], oneAndTwo[1]);
	cout << "Three: ";
	three->display();

	three->round();
	cout << "Round Three: ";
	three->display();

	delete [] oneAndTwo;
	delete three;

	return 0;
}
