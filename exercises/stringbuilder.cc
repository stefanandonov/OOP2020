#include <iostream>
using namespace std;

class IndexOutOfBounds {

};

class String {
private:
	char * chars;
	int length;

	void copy (const String & string) {
		this->length = string.length;
		chars = new char [this.length];
		strcpy(this->chars, string.chars);
	}
public:
	String (char * chars = "") {
		length = strlen(chars);
		this->chars = new char [length+1];
		strcpy(this->chars, chars);
	}

	String (const String &s) {
		copy(s);
	}

	~String () {
		delete [] chars;
	}

	String &operator = (const String &s) {
		if (this!=&s) {
			delete [] chars;
			copy (s);
		}
		return *this;
	}

	char & operator [](int i) {
		if (i<0 || i>=length)
			throw IndexOutOfBounds();
		return chars[i];
	}

	int getLength() {
		return length;
	}

	char * getChars () {
		return chars;
	}


};

class StringBuilder {
	char * chars;
	int length;
	int capacity;

	void copy (const StringBuilder & sb)  {
		this->capacity = sb.capacity;
		this->length = sb.length;
		chars = new char [this->length];
		strcpy(chars, sb.chars);
	}

public:
	StringBuilder(int capacity) {
		this->capacity = capacity; 
		length = 0;
		chars = new char[0];
	}

	StringBuilder (const StringBuilder &sb) {
		copy(sb);
	}

	StringBuilder &operator = (const StringBuilder &sb) {
		if (this!=sb) {
			delete [] chars;
			copy (sb);
		}
		return *this;
	}

	StringBuilder &operator += (String & string) {
		if ((this->length + string.getLength()) > capacity) {
			capacity*=2;
			if ((this->length + string.getLength()) > capacity) {
				capacity = this->length + string.getLength();
			}
		}
		char * temp = new  char [this->length + string.getLength() + 1];
		strcpy(temp, chars);

		for (int i = length; i < this->length + string.length();i++)
			temp [i] = string[i-length];

		this -> length += string.getLength;
		delete [] chars;

		chars = temp;
	}

	friend ostream &operator << (ostream &out, const StringBuilder &sb) {
		return out<<"Capacity: "<<sb.capacity<<endl<<"Size: "<<sb.length<<endl<<"Contents: "<<sb.char<<endl;
	}


};

int main() {
    int n;
    cin >> n;
    StringBuilder sb(n);
    cin >> n;
    for(int i = 0; i < n; ++i) {
    	char input[100];
        cin >> input;
        String s(input);
        int x;
        cin >> x;
        
        try {
        	cout << "s[" << x << "] = " << s[x] << endl;
    	}	
    	catch (IndexOutOfBounds e) {
    		cout << "Index '"<<x<<"' is out of bounds"<<endl;
    	}
        
        
        sb += s;
    }
    cout << sb;
    return 0;
}