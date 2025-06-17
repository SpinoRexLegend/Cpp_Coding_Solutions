#include<iostream>
using namespace std;
class Box
{
	public:
		int length, breadth, height;
		Box()
		{
			length = height = breadth = 0;
		}
		Box(int length, int breadth, int height)
		{
			this->length = length;
			
			this->breadth = breadth;
			this->height = height;
		}
		Box(int value)
		{
			length = value;
			breadth = value;
			height = value;
		}
		int volume()
		{
			return(length*breadth*height);
		}
};
int main()
{
	int ch;
	cout<<"1 for default costructor\n2 for 3 parameter constructor\n3 for 1 parameter constructor\n";
	cin>>ch;
	Box box;
	switch(ch)
	{
		case 1:
			cout<<box.volume();
			break;
		case 2:
			int len, bre, hei;
			cin>>len>>bre>>hei;
			box = Box(len, bre, hei);
			cout<<box.volume();
			break;
		case 3:
			int value;
			cin>>value;
			box = Box(value);
			cout<<box.volume();
			break;
		default:
			cout<<"Invalid input";
	}
}
