#include <iostream>
#include <stack>
#include <algorithm>
#include <cmath>

#define INF 9999999

using namespace std;


int main() {
	bool ascending = true;
	bool descending = true;
	for (int i = 0; i < 8; i++)
	{
		int n;
		cin >> n;
		if (ascending == false || n != i + 1)
			ascending = false;
		if (descending == false || n != 8 - i)
			descending = false;
	}
	if (ascending == true)
		cout << "ascending";
	else if (descending == true)
		cout << "descending";
	else
		cout << "mixed";
}