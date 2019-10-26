#include "Slime.h"

using namespace SlimeGame;

#include <iostream>
using namespace std;

void main()
{
	Slime *slime = new Slime(Fire, Zero, Infant, Medium, Normal);
	for (int a = 0; a < 20; a++)
	{
		int nutrition = 10;
		slime->feed(nutrition);
	}
}