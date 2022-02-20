#pragma once
class Point
{
public:
	Point(void);
	Point(int , int );
	~Point();

	void Set_X(int xx) { x = xx; }
	void Set_Y(int yy) { y = yy; }
	int Get_X(void) { return x; }
	int Get_Y(void) { return y; }
private:
	int x;
	int y;
};

