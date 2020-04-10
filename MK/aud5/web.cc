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

	bool daliSeIsti(WebPage wp) {
		return strcmp(this->url,wp.url) == 0;
	}

	void print () {
		cout<<url<<"->"<<content<<endl;
	}
};

class WebServer {
private:
	char name [40];
	WebPage * webPages;
	int size; //strlen(webPages)

	void copy (const WebServer & ws) {
		strcpy(this->name, ws.name);
		this->size = ws.size;
		webPages = new WebPage [this->size];
		for (int i=0;i<this->size;i++)
			webPages[i] = ws.webPages[i];
	}

public:
	WebServer (char * name = "FINKI") {
		strcpy(this->name, name);
		webPages = new WebPage [0];
		size = 0;
	}

	WebServer (const WebServer & ws) {
		copy(ws);
	}

	WebServer &operator = (const WebServer & ws) {
		if (this!=&ws) {
			delete [] webPages;
			copy(ws);
		}
		return *this;
	}

	~WebServer () {
		delete [] webPages;
	}

	bool contains (WebPage wp) {
		for (int i=0;i<size;i++) 
			if (webPages[i].daliSeIsti(wp))
				return true;
		return false;
	}

	void dodadiWebPage (WebPage wp) {
		if (contains(wp)==true) 
			return ;

		WebPage * tmp = new WebPage[size+1];
		for (int i=0;i<size;i++)
			tmp[i] = webPages[i];
		tmp[size++]=wp;		
		delete [] webPages;
		webPages = tmp;
		//++size;
	}

	void izbrisiWebPage (WebPage wp) {
		if (contains(wp)==true) {
			WebPage * tmp = new WebPage[size-1];
			int j=0; //moment pozicija vo nizata tmp
			for (int i=0;i<size;i++) {
				if (webPages[i].daliSeIsti(wp)==false)
					tmp[j++]=webPages[i];
			}
			delete [] webPages;
			webPages = tmp;
			--size;
		}
	}

	void listPages () {
		for (int i=0;i<size;i++)
			webPages[i].print();
	}
};

int main () {

	WebPage wp1 ("http://www.google.com", "The search engine");
	WebPage wp2 ("http://www.finki.ukim.mk", "FINKI");
	WebPage wp3 ("http://www.time.mk", "Site vesti");


	WebServer ws(" Server ");
	ws.dodadiWebPage(wp1) ;
	ws.dodadiWebPage(wp2);
	ws.dodadiWebPage(wp3) ;

	ws.listPages ();
	cout << "\nAfter delete: \n";
	ws.izbrisiWebPage(wp3);
	ws.listPages ();

}