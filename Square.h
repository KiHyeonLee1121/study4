#ifndef SQUARE_H
#define SQUARE_H

#include <string>
#include "Point.h"

using namespace std;

class Square : public Point {
public:
    Square(const string, int, int, unsigned int = 0);
    unsigned int getSide() const;
    unsigned int getArea() const;
    string getName() const;
    void setSide(unsigned int);
    void setArea(unsigned int);
    void setName(string);

private:
    unsigned int side;
    unsigned int area{ 0 };
    string name;
};

#endif

//point에서 멤버함수 및 멤버변수를 상속받기 때문에
//이름,길이,넓이 변수 추가 및 멤버함수 추가

