#include<iostream>
#include<cstring>

using namespace std;

class Team {
private:
	char name [100];
	char stadium [100];
	char city [100];

	void copy (const Team & t) {
		strcpy(this->name, t.name);
		strcpy(this->stadium, t.stadium);
		strcpy(this->city, t.city);
	}

public:
	//default constrc, const wit argument
	Team (char * name = "", char * stadium = "", char * city = "") {
		strcpy(this->name, name);
		strcpy(this->stadium, stadium);
		strcpy(this->city, city);
	}

	Team (const Team & t) {
		copy(t);
	}

	Team & operator = (const Team & t) {
		if (this!=&t) {
			copy(t);
		}
		return *this;
	}

	~Team() {
		//do nothing
	}

	void printInfo () {
		cout<<name<<" "<<city<<" "<<stadium<<endl;
	}

	friend class Game;
};

class Game {
private:
	Team * home;
	Team * away;
	int homeGoals, awayGoals;

public:
	Game (Team * home, Team * away, int homeGoals, int awayGoals) {
		this->home = home;
		this->away = away;
		this->homeGoals = homeGoals;
		this->awayGoals = awayGoals;
	}

	Game (const Game & g) {
		this->home = g.home;
		this->away = g.away;
		this->homeGoals = g.homeGoals;
		this->awayGoals = g.awayGoals;
	}

	~Game () {
		delete home;
		delete away;
	}

	void printInfo() {
		//Barcelona:Real Madrid 2:1
		cout<<home->name<<":"<<away->name<<" "<<homeGoals<<":"<<awayGoals<<endl;
	}

	friend bool isPick (Game game, char type);
};

bool isPick (Game game, char type) {
	//type == 1,2,X

	if (type=='1')
		return game.homeGoals > game.awayGoals;
	else if (type=='X')
		return game.homeGoals == game.awayGoals;
	else 
		return game.homeGoals < game.awayGoals;
}

int main () {

	Team * t1 = new Team("Barcelona", "Barcelona", "Camp noe");
	Team * t2 = new Team("Real Madrid", "Madrid", "Santiago Barnabeo");

	Game game (t1,t2,2,1);
	game.printInfo();
	

	cout<<isPick(game,'1')<<endl;
	cout<<isPick(game,'X')<<endl;
	cout<<isPick(game,'2')<<endl;

	return 0;
}