#include<iostream>
#include<cstring>

using namespace std;

class TennisPlayer {
protected:
	char firstName [50]; //yes
	char lastName [50];//yes
	bool playsInLeague;//yes

public:
	TennisPlayer (char * firstName = "", char * lastName = "", bool playsInLeague = true) {
		//cout<<"TennisPlayer constructor called"<<endl;
		strcpy(this->firstName, firstName);
		strcpy(this->lastName, lastName);
		this->playsInLeague = playsInLeague;
	}

	TennisPlayer (const TennisPlayer & tp) {
		strcpy(this->firstName,tp.firstName);
		strcpy(this->lastName, tp.lastName);
		this->playsInLeague = tp.playsInLeague;
	}

	friend ostream & operator << (ostream & out, const TennisPlayer & tp) {
		out<< "Tennis player: "<<tp.firstName<<" "<<tp.lastName<<" ";
		out<<(tp.playsInLeague ? "plays" : "doesn't play"); //rank is: 3
		return out;
	}

	~TennisPlayer() {
		//cout<<"TennisPlayer deconstructor called"<<endl;
	}
};

class RankedTennisPlayer : public TennisPlayer {
private:
	int rank;
public:
	RankedTennisPlayer(char * firstName = "", char * lastName = "",
	 bool playsInLeague = true, int rank = 0) : 
	TennisPlayer(firstName, lastName, playsInLeague) {
		//cout<<"RankedTennisPlayer constructor called"<<endl;
		this->rank = rank;
	}

	RankedTennisPlayer (const TennisPlayer & tp, int rank = 0) : TennisPlayer(tp) {
		this->rank = rank;
	}

	RankedTennisPlayer (const RankedTennisPlayer & rtp) : TennisPlayer(rtp) {
		this->rank = rtp.rank;
	}

	~RankedTennisPlayer() {
		//cout<<"RankedTennisPlayer deconstructor called"<<endl;
	}

	friend ostream & operator << (ostream & out, const RankedTennisPlayer & rtp) {
		TennisPlayer tp (rtp); //copy contstructor for the TennisPlayer;
		out<<"Ranked "<<tp<<" rank: "<<rtp.rank;
		return out;
	}
};

int main () {

	TennisPlayer rf("Roger", "Federer");
	TennisPlayer ng("Novak", "Djokovikj");
	 cout << rf << endl;
	 cout << ng << endl;
	TennisPlayer t;
	RankedTennisPlayer rn("Rafael", "Nadal", true, 2750);
	cout << rn << endl;
	TennisPlayer tp = rn;
	cout << tp << endl;
	//RankedTennisPlayer copy(tp);
	RankedTennisPlayer copy(ng, 3320);
	cout << copy << endl;

	//no rank will be printed
	// TennisPlayer * tpPtr;
	// tpPtr = &copy;
	// cout<<(*tpPtr);

	RankedTennisPlayer * rtp;
	rtp = &rf;
	cout<<(*rtp)<<endl;


	return 0;
}