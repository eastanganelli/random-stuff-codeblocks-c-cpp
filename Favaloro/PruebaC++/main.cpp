#include <iostream>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

class Rectangle {
    int Height, Width;
    public:
        void set_value(int, int);
        int area() { return Height*Width; }
} Rect;

void Rectangle::set_value(int x, int y){
    Width = y;
    Height = x;
}

int main(){
    Rect.set_value(3,4);
    cout << Rect.area() << "\n";
    return 0;
}
