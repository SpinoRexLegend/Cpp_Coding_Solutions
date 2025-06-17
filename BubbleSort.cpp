//Bubble sort
#include<iostream>
using namespace std;
int main()
{
	int n;
	int count = 1;
	cout << "Please enter the number of element/ length of the array : ";
	cin >> n;
	int num[n];
	for (int i = 0; i < n; i++)
	{
		cout << "Please enter element " << i+1 << " : " ;
		cin >> num[i];
	}
	for (int i = 0; i < n; i++)
	{
		while (count < n)
		{
			if(num[count] < num[count - 1])
			{
				num[count] = num[count] + num[count - 1];
				num[count - 1] = num[count] - num[count - 1];
				num[count] = num[count] - num[count - 1];
			}
			count++;
		}
		count = 1;
	}
	for (int i = 0; i < n; i++)
	{
		cout << num[i] << "	\n";
	}
	
	return 1;
}
