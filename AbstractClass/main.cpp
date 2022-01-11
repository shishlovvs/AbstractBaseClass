#include<iostream>
using namespace std;

class Vehichle
{
	int speed;
public:
	virtual void move() = 0;	//Чистый виртуальный метод (pure virtual functions);
	//именно этот метод и делает класс абстрактным
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
	int height;	//асбтрактный класс
};

class Bike :public GroundVehichle
{
public:
	//конкретный класс, поскольку он ОПРЕДЕЛЯЕТ чисто виртуальный метод move()
	void move()
	{
		cout << "Мотоцикл ездит на двух колесах" << endl;
	}
};

class Car :public GroundVehichle 
{
public:
	void move()
	{
		cout << "Машина едет на четырех колесах" << endl;
	}
};

class Boat :public WaterVehichle
{
public:
	void move()
	{
		cout << "Лодка плывет" << endl;
	}
};

void main()
{
	setlocale(LC_ALL, "ru");
	//Vehichle v;		//Невозможно создать экземпляр абстрактного класса 
	//GroundVehichle gv;	//этот класс также является абстрактным 
						//так как не определяет метод move
	Bike HD;
	HD.move();
	Car bmv;
	bmv.move();
	Boat boat;
	boat.move();
}