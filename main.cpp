#include <iostream>
#include <vector>
#include <string>
#include "Point.h"
#include "Square.h"

using namespace std;

// Point class function definitions
Point::Point(int px, int py) {
    x = px;
    y = py;
}

int Point::getX() const {
    return x;
}

int Point::getY() const {
    return y;
}

void Point::setX(int px) {
    x = px;
}

void Point::setY(int py) {
    y = py;
}

// Square class function definitions
Square::Square(const string n, int px, int py, unsigned int s) : Point(px, py) {
    name = n;
    side = s;
    area = side * side;
}

//Square 생성자에 좌표는 Point(px, py) 얘가 해주니까 
//Square 생성자에서는 name,side,area만 뜸

unsigned int Square::getSide() const {
    return side;
}

unsigned int Square::getArea() const {
    return area;
}

string Square::getName() const {
    return name;
}

void Square::setSide(unsigned int s) {
    side = s;
    area = side * side;
}

void Square::setArea(unsigned int a) {
    area = a;
}

void Square::setName(string n) {
    name = n;
}

int main() {
    int n;
    cin >> n;

    // vector크기 입력받기
    vector<Square> squares;

    for (int i = 0; i < n; i++) {
        string name;
        int x, y;
        unsigned int side;

        cin >> name >> x >> y >> side;
        squares.push_back(Square(name, x, y, side));
    }

    // 반복문 내에서 임시객체를 만들어서 매 반복마다 입력받고
	// squares 벡터에 push_back으로 객체 인스턴스화

    // 1) 넓이기준 정렬 - 아예 벡터를 하나 더 만들어서 정렬하여 저장
    vector<Square> areaOrder = squares;
    int size1 = (int)areaOrder.size();

    for (int i = 0; i < size1 - 1; i++) {
        for (int j = i + 1; j < size1; j++) {
            if (areaOrder[i].getArea() > areaOrder[j].getArea()) {
                Square temp = areaOrder[i];
                areaOrder[i] = areaOrder[j];
                areaOrder[j] = temp;
            }
        }
    }

    // 여기 중첩 for는 배열의 모든 원소에 대해 중첩없이 쌍을  만드는 '조합'
    // A B C D E 라고 칠 때
	// AB AC AD AE BC BD BE CD CE DE <- 이런식으로 모든 조합이 만들어짐
    // 바깥반복 한번에 대해서 안쪽 반복이 끝나면,
    // 바깥반복의 i번쨰 원소는 i부터 끝까지 중(남아있는 배열)에서 가장 작은 값이 됨.
    // 즉, 바깥반복은 인덱스 하나를 고정하고, 안쪽반복이 그 고정된 인덱스를 
    // 남아있는 값 중 가장 작은 값으로 최적화 하는 것

    cout << endl;
    cout << "Squares in increasing order of area" << endl;
    for (int i = 0; i < size1; i++) {
        cout << areaOrder[i].getName()
            << "(" << areaOrder[i].getX() << ", " << areaOrder[i].getY() << ") "
            << "side=" << areaOrder[i].getSide()
            << ", area=" << areaOrder[i].getArea() << endl;
    }

    // 2) sort by max x-coordinate
    vector<Square> maxXOrder = squares;
    int size2 = (int)maxXOrder.size();

    for (int i = 0; i < size2 - 1; i++) {
        for (int j = i + 1; j < size2; j++) {
            int maxXi = maxXOrder[i].getX() + (int)maxXOrder[i].getSide();
            int maxXj = maxXOrder[j].getX() + (int)maxXOrder[j].getSide();

            if (maxXi > maxXj) {
                Square temp = maxXOrder[i];
                maxXOrder[i] = maxXOrder[j];
                maxXOrder[j] = temp;
            }
        }
    }

    cout << endl;
    cout << "Squares in increasing order of max x-coordinate" << endl;
    for (int i = 0; i < size2; i++) {
        int maxX = maxXOrder[i].getX() + (int)maxXOrder[i].getSide();

        cout << maxXOrder[i].getName()
            << "(" << maxX << ", " << maxXOrder[i].getY() << ") "
            << "side=" << maxXOrder[i].getSide()
            << ", area=" << maxXOrder[i].getArea() << endl;
    }

    // 3) sort by max y-coordinate
    vector<Square> maxYOrder = squares;
    int size3 = (int)maxYOrder.size();

    for (int i = 0; i < size3 - 1; i++) {
        for (int j = i + 1; j < size3; j++) {
            int maxYi = maxYOrder[i].getY() + (int)maxYOrder[i].getSide();
            int maxYj = maxYOrder[j].getY() + (int)maxYOrder[j].getSide();

            if (maxYi > maxYj) {
                Square temp = maxYOrder[i];
                maxYOrder[i] = maxYOrder[j];
                maxYOrder[j] = temp;
            }
        }
    }

    cout << endl;
    cout << "Squares in increasing order of max y-coordinate" << endl;
    for (int i = 0; i < size3; i++) {
        int maxY = maxYOrder[i].getY() + (int)maxYOrder[i].getSide();

        cout << maxYOrder[i].getName()
            << "(" << maxYOrder[i].getX() << ", " << maxY << ") "
            << "side=" << maxYOrder[i].getSide()
            << ", area=" << maxYOrder[i].getArea() << endl;
    }

    return 0;
}