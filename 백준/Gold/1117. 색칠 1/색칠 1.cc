#include <iostream>

using namespace std;

int main()
{
	long long W, H, f, c, x1, y1, x2, y2;
	cin >> W >> H >> f >> c >> x1 >> y1 >> x2 >> y2;
	long long fold;

	long long d = W * H;

	if (f > W / 2)
		fold = W - f;
	else
		fold = f;

	if (fold <= x1)
		d -= (c + 1) * (y2 - y1) * (x2 - x1);
	else if (fold < x2)
	{
		d -= 2 * (c + 1) * (y2 - y1) * (fold - x1);
		d -= (c + 1) * (y2 - y1) * (x2 - fold);
	}
	else
		d -= 2 * (c + 1) * (y2 - y1) * (x2 - x1);
	cout << d;
}