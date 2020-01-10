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

class Coordinates
{
private:
	float degrees, minutes, seconds;
private:
	static float infelicity;		//погрешность
public:

	//инициализация
	Coordinates(int degress, int minutes, int seconds)
	{
		this->degrees = degress;
		this->minutes = minutes;
		this->seconds = seconds;
	}
	Coordinates()
	{
	}

	//lw10 статический метод
	static void setInfelicity(float value)
	{
		infelicity = value;
	}
	static float getInfelicity()
	{
		return infelicity;
	}

	//Методы по получению значений
	float getDegrees()
	{
		return degrees;
	}
	float getMinutes()
	{
		return minutes;
	}
	float getSeconds()
	{
		return seconds;
	}
	//lw8 Методы по получению значений по адресу и ссылке
	void getMinutes(float *value)
	{
		*value = minutes;
	}
	void getSeconds(float &value)
	{
		value = seconds;
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
	void add(Coordinates &kek, Coordinates &lol)
	{
		this->degrees = (kek.degrees + lol.degrees) / 2;
		this->minutes = (kek.minutes + lol.minutes) / 2;
		this->seconds = (kek.seconds + lol.seconds) / 2;
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

	friend void round(Coordinates &value);
};

void round(Coordinates &value)		//lw8 дружественная функция
{
	if(value.seconds >= 30)
		value.minutes += 1;
	if(value.minutes >= 30)
		value.degrees += 1;

	value.seconds = value.minutes = 0;
}

float Coordinates::infelicity;

int main()
{
	//lw10
	Coordinates::setInfelicity(1.5);
	cout << "Infelicity: " << Coordinates::getInfelicity() << endl;


	Coordinates *one = new Coordinates(20, 15, 45);
	Coordinates *two = new Coordinates(30, 45, 10);
	Coordinates *three = new Coordinates();


	cout << "Write two:" << endl;
	//oneAndTwo[1].read();

	cout << "One: ";
	one->display();
	cout << "Two: ";
	two->display();

	three->add(*one, *two);
	cout << "Three: ";
	three->display();

	three->round();
	cout << "Round Three: ";
	three->display();

	delete one;
	delete two;
	delete three;

	return 0;
}
