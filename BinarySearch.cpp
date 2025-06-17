//Binary search
#include<iostream>
using namespace std;

int main()
{
	bool check = true;
	int len;
	cout << "please enter the number of elements u want in the sorted list" << " : ";
	cin >> len;
	int bs[len];
	for (int i = 0; i < len; i++)
	{
		cout << "Please enter element " << i+1 << " : ";
		cin >> bs[i];
		cout << "\n";
	}
	int es;
	cout << "please enter the number to be searched" << " : ";
	cin >> es;
	int ll = 0;
	int ul = len - 1;
	int mv;
	while (ll < len && ul > 0)
	{
		mv = (ul - ll)/2;
		if (es > bs[mv])
		{
			ll = mv;
			check = false;
		}
		else if (es < bs[mv])
		{
			ul = mv;
			check = false;
		}
		else
		{
			cout << "Element is present at index " << mv;
			check = true;
			break;
		}
	}
	if (check == false)
		cout << "Element is absent in the enteresd list of arrary ";
	return 0;
}

