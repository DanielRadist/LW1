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

int main()
{
	coordinates one;
	Init(one);

	cout << "One: ";
	Display(one);

	return 0;
}
