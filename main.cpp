/* @autor Rakhmanin Danila aka Radist AltSTU PI-82
 *
 * ����������� ��� ������ � ����� �������� ��� ������ � ���
 * (�� ������������ ����������� ���, ���������� ������������ ���� �, ������������ Git)
 *
 * 18. ����� ���������� ����� �� ����� ������� �� ���� ������������ ����� (�������, ������ � �������).
 * ����������� ����� ���������� �� �������� � ���������� ��������� �����, ����������� �� �������� �������,
 * ������������ ��� ������ ����� (����� ���������� add).
 */


#include <iostream>

using namespace std;

struct coordinates
{
	float degrees;
	float minutes;
	float seconds;
};

//��������� �������������
int Init(coordinates &kek)
{
	cout << "Init data." << endl;
	kek.degrees = kek.minutes = kek.seconds = 0;
	return 0;
}

//��������� ������ �� �����
int Display(coordinates &kek)
{
	cout << "degrees = " << kek.degrees;
	cout << " minutes = " << kek.minutes;
	cout << " seconds = " << kek.seconds << endl;
}

//��������� ����� � ����������
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
