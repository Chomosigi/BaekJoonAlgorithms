#include <iostream>

using namespace std;

void showClass(string s)
{
	if (s == "Algorithm")
		cout << "204" << "\n";
	else if(s == "DataAnalysis")
		cout << "207" << "\n";
	else if (s == "ArtificialIntelligence")
		cout << "302" << "\n";
	else if (s == "CyberSecurity")
		cout << "B101" << "\n";
	else if (s == "Network")
		cout << "303" << "\n";
	else if (s == "Startup")
		cout << "501" << "\n";
	else if (s == "TestStrategy")
		cout << "105" << "\n";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		showClass(s);
	}
}