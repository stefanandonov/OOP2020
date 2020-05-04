#include<iostream>
#include<cmath>

using namespace std;

class RoundPeg {
protected:
	double radius;

public:
	RoundPeg (double radius = 1.0) {
		this->radius = radius;
	}

	RoundPeg (const RoundPeg & rp) {
		this->radius = rp.radius;
	}

	virtual double getRadius() {
		return radius;
	}

};

class SqaurePeg{
protected:
	double side;

public:
	SqaurePeg (double side = 1.0) {
		this->side = side;
	}

	SqaurePeg (const SqaurePeg & rp) {
		this->side = rp.side;
	}

	double getSide() {
		return side;
	}
};

class RoundHole {
private:
	double radius;

public:
	RoundHole (double radius = 1.0) {
		this->radius = radius;
	}

	RoundHole (const RoundHole & rh) {
		this->radius = rh.radius;
	}

	bool fits (RoundPeg * rp) {
		return rp->getRadius() <= radius;
	}
};

class SquarePegAdapter : public SqaurePeg, public RoundPeg {
public:
	SquarePegAdapter(double side) : SqaurePeg(side) {}

	SquarePegAdapter(const SqaurePeg & sp) : SqaurePeg(sp) {}

	double getRadius() {
		return side * sqrt(2) / 2;
	}
};

int main () {

	RoundHole rh (5.0);

	RoundPeg ** array = new RoundPeg * [8];

	array[0] = new RoundPeg (4.0); 
	array[1] = new RoundPeg (6.0);
	array[2] = new RoundPeg (5.0);

	SqaurePeg sp1 (4); // 4*1.41/2 fituva
	SqaurePeg sp2 (5); // 5*1.41/2 fituva
	SqaurePeg sp3 (10); // 10*1.41/2 = 5*1.41 > 5 //nema da fituva
	SqaurePeg sp4 (11); 

	array[3] = new SquarePegAdapter(sp1); 
	array[4] = new SquarePegAdapter(sp2);
	array[5] = new SquarePegAdapter(sp3);
	array[6] = new SquarePegAdapter(sp4);

	for (int i=0;i<7;i++)
		cout<<rh.fits(array[i])<<endl;



	//rh.fits(sp1);  nema da raboti

	return 0;
}