#include<iostream>
#include<string>
using namespace std;

enum Color
{
	console_gray = 0x88,		//0x88-шестнадцатеричный код цвета
	console_green=0xAA,
	console_blue=0x99,
	console_red = 0xCC,
	console_white = 0xFF
};
//enum - перечисление. Перечисление - это набор именнованных констант типа int

class Shape	//класс Фигура
{
protected:
	Color color;
public:
	Shape(Color color) :color(color)
	{
		cout << "ShConstructor:\t" << this << endl;
	}
	virtual ~Shape()
	{
		cout << "ShDestructor:\t" << this << endl;
	}
	virtual double get_area()const = 0;
	virtual double get_perimeter()const = 0;
	virtual void draw()const = 0;
};

class Square :public Shape
{
	double side;
public:
	double get_side()const 
	{
		return side;
	}
	void set_side(double side)
	{
		if (side <= 0)side = 1;
		this->side = side;
	}
	Square(double side, Color color) :Shape(color)
	{
		set_side(side);
	}
	~Square()
	{

	}
	double get_area()const
	{
		return side * side;
	}
	double get_perimeter()const
	{
		return side * 4;
	}
	
	void draw()const
	{
		system((std::string("color") + std::to_string(this->color)).c_str()); 
		for (int i = 0; i < side; i++)
		{
			for (int j = 0; j < side; j++)
			{
				cout << "* ";
			}
			cout << endl;
		}
	}
};

class Triangle : public Shape
{
	double sideС;
	double height;
public:
	double get_side()const
	{
		return sideС;
	}
	double get_height()const
	{
		return height;
	}
	void set_side(double sideС)
	{
		if (sideС <= 0)sideС = 1;
		this->sideС;
	}
	void set_height(double height)
	{
		if (height <= 0)height = 1;
		this->height = height;
	}
	Triangle(double sideС, double height, Color color) :Shape(color)
	{
		set_side(sideС);
		set_height(height);
		cout << "TConstructor:\t" << this << endl;
	}
	~Triangle()
	{

	}
	double get_area()const
	{
		return (sideС * height)* 0.5;
	}
	double get_perimeter()const
	{
		return sideС * 3;
	}
	void draw()const
	{
		for (int i = 0; i < sideС; i++)
		{
			for (int j = i; j < sideС; j++)
			{
				cout << " ";
			}
			for (int j = 0; j <= i; j++)
			{
				cout << "* ";
			}
		}cout << endl;
	}
};

class Circle :public Shape
{
	double radius;
	double pi;
public:
	double get_radius()const
	{
		return radius;
	}
	double get_pi()
	{
		return pi;
	}
	void set_radius(double radius)
	{
		if (radius <= 0)radius = 1;
		this->radius = radius;
	}
	void set_pi(double pi)
	{
		this->pi = pi;
	}
	Circle(double radius, double pi, Color color) : Shape(color)
	{
		set_radius(radius);
		set_pi(pi);
		cout << "CConstructor:\t" << this << endl;
	}
	~Circle()
	{

	}
	double get_area()const
	{
		return pi * (radius * radius);
	}
	double get_perimeter()const
	{
		return 2 * pi * radius;
	}
	void draw()const
	{
		//???//
	}
};

class Rectangle :public Shape
{
	double sideA;
	double sideB;
public:
	double get_side()const
	{
		return Rectangle::sideA;
		return Rectangle::sideB;
	}
	void set_side(double sideA, double sideB)
	{
		if (sideA, sideB <= 0)sideA, sideB = 1;
		this->sideA = sideA;
		this->sideB = sideB;
	}
	Rectangle(double sideA, double sideB, Color color) :Shape(color)
	{
		set_side(sideA, sideB);
	}
	~Rectangle()
	{

	}
	double get_area()const
	{
		return sideA * sideB;
	}
	double get_perimeter()const
	{
		return (sideA + sideB) * 2;
	}
	void draw()const
	{
		for (int i = 0; i < sideA; i++)
		{
			for (int j = 0; j < sideB; j++)
			{
				cout << "* ";
			}
			cout << endl;
		}
	}
};

void main()
{
	setlocale(LC_ALL, "ru");
	Square square(5, Color::console_red);
	cout << "Площадь квадрата: " << square.get_area() << endl;
	cout << "Периметр квадрата: " << square.get_perimeter() << endl;
	square.draw();

	Triangle triangle(2, 5, Color::console_red);
	cout << "Площадь треугольника: " << triangle.get_area() << endl;
	cout << "Периметр треугольника: " << triangle.get_perimeter() << endl;
	triangle.draw();

	Rectangle rectangle(4, 2, Color::console_red);
	cout << "Площадь прямоугольника: " << rectangle.get_area() << endl;
	cout << "Периметр прямоугольника: " << rectangle.get_perimeter() << endl;
	rectangle.draw();

	Circle circle(6, 3.14, Color::console_blue);
	cout << "Площадь круга: " << circle.get_area() << endl;
	cout << "Периметр круга: " << circle.get_perimeter() << endl;
	circle.draw();
} 