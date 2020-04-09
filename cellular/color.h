#ifndef COLOR_H
#define COLOR_H

class color {
	typedef unsigned char byte;
private:
	byte _red;
	byte _green;
	byte _blue;
public:

	color() {
		_red = 0;
		_green = 0;
		_blue = 0;
	}
	
	color(byte red, byte green, byte blue) {
		_red = red;
		_green = green;
		_blue = blue;
	}
	
	byte get_red() const 
	{
		return _red;
	}
	byte get_green() const 
	{ 
		return _green;
	}
	byte get_blue() const 
	{ 
		return _blue;
	}
};

bool operator == (const color& c1, const color& c2) 
{
	return c1.get_red() == c2.get_red() && c1.get_green() == c2.get_green() && c1.get_blue() == c2.get_blue();
}

bool operator != (const color& c1, const color& c2)
{
	return !(c1 == c2);
}


#endif // COLOR_H
