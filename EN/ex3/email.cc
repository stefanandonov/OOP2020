#include<iostream>
#include<cstring>

using namespace std;

class Email {
private:
	char sender [100];
	char receiver [100];
	char subject [50];
	char body [1000];
public:
	//default and constructor with arugments
	Email (char * _sender ="", char * _receiver = "", char * _subject = "", char * _body = "") {
		strcpy(sender, _sender);
		strcpy(receiver, _receiver);
		strcpy(subject, _subject);
		strcpy(body,_body);
	}

	void print () {
		cout<<"FROM: "<<sender<<endl;
		cout<<"TO: "<<receiver<<endl;
		cout<<"----------------------------"<<endl;
		cout<<"Subject: "<<subject<<endl;
		cout<<"----------------------------"<<endl;
		cout<<"Body: "<<endl<<body<<endl;
	}
};

bool isValid (char * email) {
	int positionOfAt = -1;
	for (int i=0;i<strlen(email);i++)
		if (email[i]=='@') {
			positionOfAt = i;			
		}

	if (positionOfAt == -1) {
		return false;
	} else {
		for (int i = positionOfAt; i<strlen(email);i++) {
			if (email[i] == '.')
				return true;
		}
		return false;
	}

}

int main () {
	char sender [100];
	char receiver [100];
	char subject [50];
	char body [1000];

	cin>>sender>>receiver>>subject>>body;

	if (isValid(sender) && isValid(receiver)) {
		Email email (sender, receiver, subject, body);
		email.print();
	}else {
		cout<<"One of the emails is not valid";
	}

}