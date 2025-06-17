#include<iostream>
using namespace std;

class SmartSecurity
{
	public:
		bool doorSecurity, windowSecurity;
		SmartSecurity()
		{
			doorSecurity = false;
			windowSecurity = false;
		}
		void lockAll()
		{
			doorSecurity = false;
			windowSecurity = false;
		}
		void unlockAll()
		{
			doorSecurity = true;
			windowSecurity = true;
		}
		void displayStatus()
		{
			cout<<"Is the door unlocked? "<<doorSecurity<<endl;
			cout<<"Is the window unlocked? "<<windowSecurity<<endl;
		}
};

int main()
{
	SmartSecurity ss;
	int ch = 1;
	cout<<"1 for locking\n2 for unlocking\n3for displying status \n";
	while(ch!= 0)
	{
		cin>>ch;
		if(ch == 1)
			ss.lockAll();
		else if(ch == 2)
			ss.unlockAll();
		else if(ch == 3)
			ss.displayStatus();
		else
			cout<<"Invalid input";
	}
}
