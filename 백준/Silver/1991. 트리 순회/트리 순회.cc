#include <iostream>
#include <algorithm>

int arr[50][2];

using namespace std;

int n;

void preorder(int n)
{
	if (n == -1) return;
	cout << (char)(n + 'A');
	preorder(arr[n][0]);
	preorder(arr[n][1]);
}

void inorder(int n)
{
	if (n == -1) return;
	inorder(arr[n][0]);
	cout << (char)(n + 'A');
	inorder(arr[n][1]);
}

void postorder(int n)
{
	if (n == -1) return;
	postorder(arr[n][0]);
	postorder(arr[n][1]);
	cout << (char)(n + 'A');
}

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		char root, left, right;
		cin >> root >> left >> right;
		root = root - 'A';
		
		if (left == '.')
			arr[root][0] = -1;
		else
			arr[root][0] = left - 'A';
		if (right == '.')
			arr[root][1] = -1;
		else
			arr[root][1] = right - 'A';
	}
	preorder(0);
	cout << "\n";
	inorder(0);
	cout << "\n";
	postorder(0);
}