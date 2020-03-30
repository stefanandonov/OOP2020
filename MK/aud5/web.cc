#include<iostream>
#include<cstring>

using namespace std;

class WebPage {
private:
	char url [100];
	char * content; // deklarirame dinamicki alocirana niza od znaci

	void copy (const WebPage & wp) {
		strcpy(this->url, wp.url);
		this->content = new char [strlen(wp.content)+1];
		strcpy(this->content, wp.content);
	}
public:
	WebPage (char * url = "", char * content = "") {
		strcpy(this->url, url);
		this->content = new char [strlen(content)+1];
		strcpy(this->content, content);
	}

	WebPage (const WebPage &wp) {
		copy(wp);
	}

	WebPage &operator = (const WebPage & wp) {
		if (this!=&wp) {
			delete [] content;
			copy(wp);
		}
		return *this;
	}

	~WebPage () {
		delete [] content;
	}
};

int main () {

}