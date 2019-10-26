#include "Slime.h"
#include <cmath>

#include <iostream>

using namespace SlimeGame;
using namespace std;

Slime::Slime(Species species, Purity purity, Age age, Size size, Ranking ranking) :
	_species(species), _purity(purity), _age(age), _size(size), _ranking(ranking)
{

}

Slime::~Slime()
{

}

std::string Slime::product()
{
	switch (_species)
	{
	case Fire:
		return "fire";
	case Water:
		return "water";
	case Earth:
		return "earth";
	case Air:
		return "air";
	};
	return "null";
}

std::string Slime::enhancedProduct()
{
	return "";
}

int Slime::ageUpThreshold()
{
	if (_age == Infant && _purity == Zero && _ranking == Normal)
	{
		return 30;
	}
	if (_age == Adolescent && _purity == Zero && _ranking == Normal)
	{
		return 50;
	}
	if (_age == Adult && _purity == Zero && _ranking == Normal)
	{
		return 120;
	}
	return -1;
}

int Slime::enhancedProduceThreshold()
{
	return -1;
}

int Slime::produceThreshold()
{
	int threshold = -1;

	if (_age == Adult && _purity == Zero && _ranking == Normal)
	{
		// Most basic threshold, 10x10
		threshold = 100;
	}

	if (_age == Adult && _purity == Ten && _ranking == Divine)
	{

	}

	if (threshold == -1) 
	{
		return -1;
	}

	float multiplier = pow(9.0, static_cast<int>(_size));
	return threshold * multiplier;
}

void Slime::feed(int nutrition)
{
	_nutrition += nutrition;

	int aut = ageUpThreshold();

	if (aut > 0 && _nutrition >= aut) 
	{
		ageUp();
		_nutrition -= aut;
		return;
	}

	int ept = enhancedProduceThreshold();

	if (ept > 0 && _nutrition >= ept) 
	{
		produce(true);
		_nutrition -= ept;
		return;
	}

	int pt = produceThreshold();

	if (pt > 0 && _nutrition >= pt) 
	{
		produce(false);
		_nutrition -= pt;
		return;
	}
}

void Slime::ageUp()
{
	switch (_age)
	{
	case Infant:
		cout << "Aged up to adolescent" << endl;
		_age = Adolescent;
		break;
	case Adolescent:
		cout << "Aged up to adult" << endl;
		_age = Adult;
		break;
	case Adult:
		cout << "Aged up to elder" << endl;
		_age = Elder;
		break;
	case Elder:
		cout << "Aged up to ancient" << endl;
		_age = Ancient;
		break;
	case Ancient:
		cout << "What do we do when we age up an ancient slime?" << endl;
		break;
	}
}

void Slime::produce(bool enhanced = false)
{
	int q = produceQuantity(enhanced);
	string p = enhanced ? enhancedProduct() : product();
	cout << "Produced " << q << " of " << p << endl;
}

int Slime::produceQuantity(bool enhanced = false)
{
	return pow(10, static_cast<int>(_size));
}