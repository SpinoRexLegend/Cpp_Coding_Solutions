#include <iostream>
using namespace std;

class Shape
{
    public:
        virtual float area() = 0;
        virtual float perimeter() = 0;
};
class Circle: public Shape
{
    private:
        float radius;
        float pi;
    public:
        Circle(float radius)
        {
            this-> radius = radius;
            pi = 3.14159;
        }
        float area(){ return(pi*radius*radius); }
        float perimeter(){ return(2*pi*radius); }
};
class Rectangle: public Shape
{
    private:
        float breadth;
        int length;
    public:
        Rectangle(float length, float breadth)
        {
            this-> length = length;
            this-> breadth = breadth;
        }
        float area(){ return(length * breadth); }
        float perimeter(){ return(2*(length + breadth)); }
};

int main()
{
    Shape *p = new Circle(5.0);
    cout<<p->area()<<endl;
    cout<<p->perimeter()<<endl;
    p = new Rectangle(5, 10);
    cout<<p->area()<<endl;
    cout<<p->perimeter()<<endl;
    return 0;
}
