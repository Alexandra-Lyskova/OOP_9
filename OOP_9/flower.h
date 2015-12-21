#pragma once
class Flower
{
	char* name;
	int size;
public:
	Flower(char *name, int size);
	char* getName();
	int getSize();
	void setSize(int size);
	~Flower();
};
