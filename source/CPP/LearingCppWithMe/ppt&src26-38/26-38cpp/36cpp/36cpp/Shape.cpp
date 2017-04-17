#include "Shape.h"
#include "DynBase.h"
#include <iostream>
using namespace std;


void Circle::Draw()
{
	cout<<"Circle::Draw() ..."<<endl;
}
Circle::~Circle()
{
	cout<<"~Circle ..."<<endl;
}

void Square::Draw()
{
	cout<<"Square::Draw() ..."<<endl;
}
Square::~Square()
{
	cout<<"~Square ..."<<endl;
}



void Rectangle::Draw()
{
	cout<<"Rectangle::Draw() ..."<<endl;
}

Rectangle::~Rectangle()
{
	cout<<"~Rectangle ..."<<endl;
}

REGISTER_CLASS(Circle);
REGISTER_CLASS(Square);
REGISTER_CLASS(Rectangle);
