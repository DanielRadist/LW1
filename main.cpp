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

int main()
{
	coordinates one, two;
	Init(one);

	return 0;
}
