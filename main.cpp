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
protected:
	float degrees, minutes, seconds;
protected:
	static float infelicity;		//погрешность
public:

	//инициализация
	Coordinates(float degress, float minutes, float seconds)
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

	//Инициализация
	void init(float degrees, float minutes, float seconds)
	{
		this->degrees = degrees;
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
	void add(Coordinates &kek, Coordinates &lol)
	{
		this->degrees = (kek.degrees + lol.degrees) / 2;
		this->minutes = (kek.minutes + lol.minutes) / 2;
		this->seconds = (kek.seconds + lol.seconds) / 2;
	}



	//виртуальная фнкция округление до градусов
	virtual void round()
	{
		if(seconds >= 30)
			minutes += 1;
		if(minutes >= 30)
			degrees += 1;

		seconds = minutes = 0;
	}

	friend void round(Coordinates &value);
};

/*
void round(Coordinates &value)		//lw8 дружественная функция
{
	if(value.seconds >= 30)
		value.minutes += 1;
	if(value.minutes >= 30)
		value.degrees += 1;

	value.seconds = value.minutes = 0;
}*/

float Coordinates::infelicity;

/*
 * lw12
 * В 18.
 * п. 1 В производный класс добавлено целое (или булевское) поле, равное 1 (северной широты) или -1 (южной долготы).
 * п. 3 При округлении до градусов (целое число) учитывается расположении точки на полушариях.
 * п.6 При присваивании объекту производного класса объекта базового класса дополнительному полю присваивается -1 , если градусов меньше 10 и 1, в противном случае.
 */

class CoordinatesNSEW : protected Coordinates
{
private:
	int NSEW;
public:

	CoordinatesNSEW(int NSEW, float degrees, float minutes, float seconds) : Coordinates(degrees, minutes, seconds)
	{
		init(NSEW, degrees, minutes, seconds);
	}

	void init(int NSEW, float degrees, float minutes, float seconds)
	{
		Coordinates::init(degrees, minutes, seconds);

		setNSEW(NSEW);
	}

	void display()
	{
		Coordinates::display();
		cout << "NSEW = " << NSEW << endl;
	}

	int getNSEW()
	{
		return NSEW;
	}
	void setNSEW(int value)
	{
		if(value == 1 || value == -1)
			NSEW = value;
	}

	void round() override
	{
		if(seconds >= 30)
			minutes += 1;
		if(minutes >= 30)
			degrees += 1;

		seconds = minutes = 0;

		if(NSEW == -1)
			degrees *= -1;
	}

	void editorLW14()
	{
		degrees -= int(degrees/5);
		minutes -= int(minutes/5);
		seconds -= int(seconds/5);
		round();
	}

	CoordinatesNSEW operator=(Coordinates val)
	{
		this->degrees = val.getDegrees();
		this->minutes = val.getMinutes();
		this->seconds = val.getSeconds();
		this->infelicity = val.getInfelicity();
		if(val.getDegrees() < 10)
			this->NSEW = -1;
		else
			this->NSEW = 1;
		return *this;
	}
};

int main()
{
	//lw10
	Coordinates::setInfelicity(1.5);
	cout << "Infelicity: " << Coordinates::getInfelicity() << endl;

	CoordinatesNSEW a(1, 16, 8, 9);
	a.display();

	//Coordinates *one = new Coordinates(20, 15, 45);
	//a = *one;

	a.editorLW14();

	a.display();

	/*

	Coordinates *two = new Coordinates(30, 45, 10);
	Coordinates *three = new Coordinates();


	//cout << "Write two:" << endl;
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
	delete three;*/

	return 0;
}
