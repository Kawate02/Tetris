#pragma once

class Position
{
public:
	Position() : _x(0), _y(0) {};
	Position(int __x, int __y) : _x(__x), _y(__y) {};
	void Set( int x, int y ) 
	{
		_x = x;
		_y = y;
	}
	int x() 
	{
		return _x;
	};
	int y() 
	{
		return _y;
	};
private:
	int _x;
	int _y;
};