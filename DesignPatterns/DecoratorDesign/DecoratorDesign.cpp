#include <bits/stdc++.h>
using namespace std;

class Shape
{
public:
	virtual void draw() {};
	virtual int calculateCost() {};
};

class Rectangle : public Shape
{
private:
	int cost = 10;
public:
	void draw()
	{
		cout << "Rectangle is drawn\n";
	}
	int calculateCost()
	{
		return cost;
	}
};

class Circle : public Shape
{
private:
	int cost = 20;
public:
	void draw()
	{
		cout << "Cirle is drawn\n";
	}
	int calculateCost()
	{
		return cost;
	}
};

class ShapeDecorator : public Shape
{
};

class RedColorDecorator : public ShapeDecorator
{
private:
	int cost = 5;
	Shape *shapeObj;
public:
	RedColorDecorator(Shape *shapeObj)
	{
		this->shapeObj = shapeObj;
	}
	void draw()
	{
		this->shapeObj->draw();
		cout << "Red color is decorated for the shape\n";
	}
	int calculateCost()
	{
		return this->shapeObj->calculateCost() + cost;
	}
};

int main()
{
	Shape *redColorCirle = new RedColorDecorator(new Circle());
	redColorCirle->draw();
	cout << "Cost to draw specified shape : " << redColorCirle->calculateCost() << "\n";

	Shape *redColorRectangle = new RedColorDecorator(new Rectangle());
	redColorRectangle->draw();
	cout << "Cost to draw specified shape : " << redColorRectangle->calculateCost() << "\n";
	return 0;
}

