//IMPLEMENTING LINEAR SEARCH
#include <iostream>
using namespace std;
int main()
{
	int n, nf;
	cout << "Enter the number of elements to be input : ";
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	cout << "Enter the index of the element u wanna find : ";
	cin >> nf;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] == nf)
		{
			cout << "The expected and first index of the character is " << i;
			break;
		}
	}
}
