#include<iostream>
#include<cstring>

using namespace std;

class WebPage {
private:
	char url [100];
	char * content;

	void copy (const WebPage &wp) {
		strcpy(this->url, wp.url);
		this->content = new char [strlen(wp.content)+1];
		strcpy(this->content, wp.content);
	}

public:
	//defualt and const with arugmetn
	WebPage(char * url = "", char * content = "") {
		strcpy(this->url, url);
		this->content = new char [strlen(content)+1];
		strcpy(this->content, content);
	}

	WebPage (const WebPage & wp) {
		copy(wp);
	}

	WebPage & operator = (const WebPage & wp) {
		if (this!=&wp) {
			delete [] content;
			copy(wp);
		}
		return *this;
	}

	~WebPage() {
		delete [] content;
	}

	void print() {
		cout<<url<<" "<<content<<endl;
	}

	bool equal (WebPage wp) {
		return strcmp(this.url,wp.url) == 0;
	}
};

class WebServer {
private:
	char name [100];
	WebPage * webPages; //this is emptu
	int size; //this is zero
public:
	WebServer(char * name = "FINKI WS") {
		strcpy(this->name, name);
		webPages = new WebPage [0];
		size = 0;
	}

	void addPage (WebPage wp) {
		for (int i=0;i<size;i++) {
			if (webPages[i].equal(wp)) {
				return ;
			}
		}

		//1
		WebPage * tmp = new WebPage [size+1];
		//2 
		for (int i=0;i<size;i++) {
			tmp[i] = webPages[i];
		}
		//3
		tmp[size] = wp;
		//4
		++size;
		//5 
		delete [] webPages;
		//6
		webPages = tmp;
	}

	void deletePage (WebPage wp) {
		bool flag = false;
		for (int i=0;i<size;i++) {
			if (webPages[i].equal(wp)) {
				flag = true;
			}
		}

		if (flag) {
			//1
			WebPage * tmp = new WebPage[size-1];

			//2
			int j = 0;
			for (int i=0;i<size;i++) {
				if (!webPages[i].equal(wp)) {
					tmp[j] = webPages[i];
					++j;
				}
			}

			//3
			delete [] webPages;

			//4 
			webPages = tmp;

			//5
			--size;
		}
	}

	void print () {
		for (int i=0;i<size;i++)
			webPages[i].print();
	}

};

int main () {

	return 0;
}