#include<iostream>
#include<string>
#include<Windows.h>
using namespace std;

namespace Geometry
{
	enum Color
	{
		console_gray = 0x88,		//0x88-шестнадцатеричный код цвета
		console_green = 0xAA,
		console_blue = 0x99,
		console_red = 0xCC,
		console_white = 0xFF,
		console_default = 0x07,

		red		= 0x000000FF,
		green	= 0x0000FF00,
		blue	= 0x00FF0000
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
			/*std::string command = std::string("color ") + console_color[color];
			cout << command << endl;
			system(command.c_str()); */
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hConsole, color);
			//SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE|BACKGROUND_RED);
			for (int i = 0; i < side; i++)
			{
				for (int j = 0; j < side; j++)
				{
					cout << "* ";
				}
				cout << endl;
			}
			SetConsoleTextAttribute(hConsole, Color::console_default);
		}
	};

	class Triangle :public Shape
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
			this->sideС = sideС;
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
			return (sideС * height) * 0.5;
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
				}cout << endl;
			}
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

	class Rectangle :public Shape   //Прямоугольник
	{
		double left_side;           //Левая сторона
		double upper_side;          //Верхняя сторона
	public:
		double get_left_side()const
		{
			return left_side;
		}
		double get_upper_side()const
		{
			return upper_side;
		}
		void set_left_side(double left_side)
		{
			if (left_side <= 0)left_side = 1;
			this->left_side = left_side;
		}
		void set_upper_side(double upper_side)
		{
			if (upper_side <= 0)upper_side = 2;
			this->upper_side = upper_side;
		}
		Rectangle(double upper_side, double left_side, Color color) :Shape(color)
		{
			set_upper_side(upper_side);
			set_left_side(left_side);
			cout << "RecConstructor: " << this << endl;
		}
		~Rectangle()
		{
			cout << "RecDestructor: " << this << endl;
		}
		double get_area()const
		{
			return left_side * upper_side;
		}
		double get_perimeter()const
		{
			return (left_side + upper_side) * 2;
		}
		void draw()const
		{
			//1)Получаем окно консоли:
			HWND hwnd = GetConsoleWindow();
			//2)Создаем контекст устройства полученного окна, в котором будем рисовать
			HDC hdc = GetDC(hwnd);
			//3)Создаем карандаш
			HPEN hpen = CreatePen(PS_SOLID, 5, color); //PS_SOLID - сплошная линия, 5 - толщина 5px
			//4)Прежде чем рисовать карандашом, его нужно выбрать чем и на чем рисовать:
			SelectObject(hdc, hpen);
			//5)Чтобы фигура была закрашена, нужно применить кисть:
			HBRUSH hbrush = CreateSolidBrush(color);
			SelectObject(hdc, hbrush);
			::Rectangle(hdc, 100, 100, 200, 200);

			//?)Удаляем кисть:
			DeleteObject(hbrush);
			//?)Удаляем карандаш
			DeleteObject(hpen);
			//?)Все контексты устройства нужно удалять, чтобы освободить занимаемые ими ресурсы:
			ReleaseDC(hwnd, hdc);
			/*for (int i = 0; i < left_side; i++)
			{
				for (int j = 0; j < upper_side; j++)
				{
					cout << "* ";
				}
			}cout << endl;*/
		}
	};
}

	void main()
	{
		setlocale(LC_ALL, "ru");
		Geometry::Square square(5, Geometry::Color::console_red);
		cout << "Площадь квадрата: " << square.get_area() << endl;
		cout << "Периметр квадрата: " << square.get_perimeter() << endl;
		square.draw();

		Geometry::Triangle triangle(10, 15, Geometry::Color::console_red);
		cout << "Площадь треугольника: " << triangle.get_area() << endl;
		cout << "Периметр треугольника: " << triangle.get_perimeter() << endl;
		triangle.draw();

		Geometry::Circle circle(6, 3.14, Geometry::Color::console_blue);
		cout << "Площадь круга: " << circle.get_area() << endl;
		cout << "Периметр круга: " << circle.get_perimeter() << endl;
		circle.draw();

		/*Geometry::Rectangle rect(1000, 2000, Geometry::Color::green);
		cout << "Площадь прямоугольника: " << rect.get_area() << endl;
		cout << "Периметр прямоугольника: " << rect.get_perimeter() << endl;
		rect.draw();*/
	}