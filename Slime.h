#pragma once

#include <string>
using namespace std;

namespace SlimeGame {
    enum Age {
        Infant,
        Adolescent,
        Adult,
        Elder,
        Ancient
    };

    enum Species {
        Fire,
        Water,
        Earth,
        Air
    };

    enum Purity {
		Zero,
        One,
        Two,
        Three,
        Four,
        Five,
        Six,
        Seven,
        Eight,
        Nine,
        Ten
    };

	enum Size {
		Medium,
		Large,
		Huge,
		Gargantuan,
		Colossal
	};

    enum Ranking {
        Normal,
        Noble,
        Royal,
        Imperial,
        Legendary,
        Mythical,
        Divine
    };

    class Slime
    {
    public:
        Slime(Species, Purity, Age, Size, Ranking);
        virtual ~Slime();

		virtual string product();
		virtual string enhancedProduct();
		virtual int produceThreshold();
		virtual int enhancedProduceThreshold();
		virtual int ageUpThreshold();

		virtual int produceQuantity(bool);
		virtual int produceEnhancedQuantity()
		{
			return produceQuantity(true);
		}

		virtual void feed(int);

		virtual void ageUp();
		virtual void produce(bool);
		virtual void produceEnhanced() {
			produce(true);
		}
	private:
        Age _age;
        Species _species;
		Purity _purity;
        Size _size;
        Ranking _ranking;
		float _nutrition = 0.0;
    };

	class Pen {

	};

	class BreedingPen {

	};
}