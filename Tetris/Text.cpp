#include "Text.h"

Text::Text(const char* text, int x, int y, int size) : text(text), x(x), y(y), size(size)
{
}

const char* Text::Get(int* x, int* y, int* size)
{
	*x = this->x;
	*y = this->y;
	*size = this->size;
    
	return text;
}
