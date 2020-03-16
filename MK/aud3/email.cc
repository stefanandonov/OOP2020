#include<iostream>
#include<cstring>

using namespace std;

class Email {
private:
	char from [100];
	char to [100];
	char subject [40];
	char body [500];

public:
	//2 vo 1 (default i so argumenti)
	Email (char * ffrom = "", char * tto = "", char * ssubject = "", char * bbody = "") {
		strcpy(from ,ffrom);
		strcpy(to, tto);
		strcpy(subject, ssubject);
		strcpy(body, bbody);
	}

	void print () {
		cout<<"TO: "<<to<<endl;
		cout<<"FROM "<<from<<endl;
		cout<<"SUBJECT: \n"<<subject<<endl;
		cout<<body<<endl;
	}
};

bool valid (char * email) {
	int count = 0;
	int monkeyPosition = 0;
	for (int i=0;i<strlen(email);i++)
		if (email[i]=='@') {
			++count;
			monkeyPosition = i;
		}

	int countDots = 0;

	for (int i=monkeyPosition; i<strlen(email);i++) {
		if (email[i]=='.') 
			++countDots;
	}

	return ((count==1) && (countDots>=1));
}

int main () {
	char from [100], to [100], subject [40], body[500];

	cin>>from>>to>>subject>>body;

	if (valid(from) && valid(to)) {
		Email email (from, to, subject, body);
		email.print();
	}
	else {
		cout<<"Mejlot ne ti e okej decko. "<<endl;
	}
	

	return 0;
}