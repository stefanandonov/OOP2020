#include<iostream>
#include<cstring>

using namespace std;

class TennisPlayer {
private:
	char firstName [50];
	char lastName [50];
	bool playsInLeague;

public:
	TennisPlayer (char * firstName = "", char * lastName = "", bool playsInLeague = true) {
		//cout<<"Tennis player constructor called"<<endl;
		strcpy(this->firstName, firstName);
		strcpy(this->lastName, lastName);
		this->playsInLeague = playsInLeague;
	}

	//tp = tp1;
	TennisPlayer (const TennisPlayer & tp) {
		strcpy(this->firstName, tp.firstName);
		strcpy(this->lastName, tp.lastName);
		this->playsInLeague = tp.playsInLeague;
	}

	void setPlaysInLeague (bool playsInLeague) {
		this->playsInLeague = playsInLeague;
	}

	bool getPlaysInLeague() {
		return this->playsInLeague;
	}

	friend ostream & operator << (ostream & out, const TennisPlayer & tp) {
		return out<<tp.firstName<<" "<<tp.lastName<<" "<<(tp.playsInLeague ? "YES" : "NO")<<" ";
	}
};

class RankedTennisPlayer : public TennisPlayer {
private:
	int rank;
	

public:
	RankedTennisPlayer (char * firstName = "", char * lastName = "", bool playsInLeague = false, int rank = 0) :
	TennisPlayer(firstName, lastName, playsInLeague) {
		//cout<<"Ranked tennis player constructor called"<<endl;
		this->rank = rank;
	}

	RankedTennisPlayer (const TennisPlayer & tp, int rank) : TennisPlayer (tp){
		this->rank = rank;
	}

	RankedTennisPlayer (const RankedTennisPlayer & rtp) 
	: TennisPlayer(rtp) {
		this->rank = rtp.rank;
	}

	friend ostream & operator << (ostream & out, const RankedTennisPlayer & rtp) {
		TennisPlayer tp (rtp);
		return out<<tp<<" "<<rtp.rank<<endl;
	}
};

int main () {
	TennisPlayer rf("Roger", "Federer");
	TennisPlayer ng("Novak", "Djokovikj");
	cout << rf;
	cout << ng;
	//TennisPlayer t;
	RankedTennisPlayer rn("Rafael", "Nadal", true, 2750);
	cout << rn;
	TennisPlayer tp = rn;
	cout << tp;
	//RankedTennisPlayer copy(tp);
	RankedTennisPlayer copy(ng, 3320);
	cout << copy;
	return 0;
}