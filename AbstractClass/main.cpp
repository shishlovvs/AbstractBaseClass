#include<iostream>
using namespace std;

class Vehichle
{
	int speed;
public:
	virtual void move() = 0;	//������ ����������� ����� (pure virtual functions);
	//������ ���� ����� � ������ ����� �����������
	//virtual type name(parametres) = 0;

};

class GroundVehichle: public Vehichle
{
public:

};

class WaterVehichle : public Vehichle
{
	;
};

class AirVehichle : public Vehichle
{
	int height;	//����������� �����
};

class Bike :public GroundVehichle
{
public:
	//���������� �����, ��������� �� ���������� ����� ����������� ����� move()
	void move()
	{
		cout << "�������� ����� �� ���� �������" << endl;
	}
};

class Car :public GroundVehichle 
{
public:
	void move()
	{
		cout << "������ ���� �� ������� �������" << endl;
	}
};

class Boat :public WaterVehichle
{
public:
	void move()
	{
		cout << "����� ������" << endl;
	}
};

void main()
{
	setlocale(LC_ALL, "ru");
	//Vehichle v;		//���������� ������� ��������� ������������ ������ 
	//GroundVehichle gv;	//���� ����� ����� �������� ����������� 
						//��� ��� �� ���������� ����� move
	Bike HD;
	HD.move();
	Car bmv;
	bmv.move();
	Boat boat;
	boat.move();
}