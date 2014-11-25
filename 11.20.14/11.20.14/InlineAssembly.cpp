#include <iostream>
using namespace std;

struct point
{
	int x;
	int y;
};

int main()
{
	point p, q, v;
	cout << "Enter x and y for point p:" << endl;
	cin >> p.x >> p.y;
	cout << "Enter x and y for point q:" << endl;
	cin >> q.x >> q.y;

	__asm {
			mov eax, q.x   // v.x = q.x - p.x
			sub eax, p.x
			mov v.x, eax

			mov eax, q.y   // v.y = q.y - p.y
			sub eax, p.y
			mov v.y, eax

			//mov ebp, eax <- Don't do this
	}

	cout << "The vector from p to q is : <";
	cout << v.x << "," << v.y << ">" << endl;

	return 0;
}
