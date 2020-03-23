#include <iostream>
#include <cstring>
using namespace std;



// your code here

class Character {
private:
    char character;

    void copy (const Character & c) {
        this->character = c.character;
    }

public:
    Character (char c = '') {
        this->character = c;
    }

    Character (const Character & c) {
        copy(c);
    }

    Character & operator = (const Character & c)  {
        if (this!=&c) {
            copy(c);
        }

        return *this;
    }

    bool operator==(const Character &c) {
        return this->character == c.character;
    }

    friend ostream & operator << (ostream &out, const Character & c) {
        return out<<c;
    }
};

class CharSequence {
    Character * chars;
    int size;

    void copy (const CharSequence & cs) {
        this->size = cs.size;
        //delete [] chars;
        chars = new Character[cs.size];
        for (int i=0;i<this->size;i++) {
            chars[i] = cs.chars[i];
        }
    }
public:
    CharSequence (char * input) {
        size = strlen(input);
        chars = new Character [size];
        for (int i=0;i<size;i++) {
            chars[i] = Character(input[i]);
        }
    }

    CharSequence (const CharSequence &cs){
        copy (cs);
    }

    CharSequence & operator = (const CharSequence & cs) {
        if (this!=&cs){
            delete [] chars;
            copy(cs);
        }
        return *this;
    }

    Character& operator[](int i) {
        return chars[i];
    }

    CharSequence& operator +=(const Character &c) {
        Character * temp = new Character [this->size + 1];
        for (int i=0;i<this->size;i++) {
            temp[i] = chars[i];
        }
        temp[this->size++] = c;
        delete [] chars;
        chars = temp;
        return *this;
    }

    bool operator==(const CharSequence &cs) {
        if (this->size != cs.size)
            return false;

        for (int i=0;i<this->size;i++) {
            if (chars[i]!=cs.chars[i])
                return false;
        }
        return true;
    }

    int operator[](char c) {
        int count = 0;
        Character cc (c);
        for (int i=0;i<size;i++)
            if (chars[i]==cc)
                ++count;

        return count;
    }

    friend ostream & operator << (ostream &out, const CharSequence & c) {
        for (int i=0;i<size;i++)
            out<<chars[i];
        return out<<endl;
    }

    CharSequence toUpperCase() {

    }
};



int main() {
    int n;
    cin >> n;

    if(n == 1) {
        cout << "Testing Character class" << endl;
        cout << "Character constructor" << endl;
        char c;
        cin >> c;
        Character cc(c);
        cout << "OK" << endl;
        cout << "Character operator <<" << endl;
        cout << cc << endl;
    } else if(n == 2) {
        cout << "Testing CharSequence constructors" << endl;
        char word[100];
        cin >> word;
        CharSequence cs1(word);
        cout << cs1 << endl;
    } else if(n == 3) {
        cout << "Testing CharSequence copy constructor and operator[int]" << endl;
        CharSequence cs("Some sequence");
        CharSequence copy(cs);
        cs[0] = 'X';
        cout << "Original: " << cs << endl;
        cout << "Copy: " << copy << endl;
    } else if(n == 4) {
        cout << "Testing CharSequence =operator and operator[int]" << endl;
        CharSequence cs("Some sequence");
        CharSequence copy;
        copy = cs;
        cs[0] = 'X';
        cout << "Original: " << cs << endl;
        cout << "Copy: " << copy << endl;
    } else if(n == 5) {
        cout << "Testing CharSequence operator+=" << endl;
        CharSequence cs;
        char word[100];
        cin >> word;
        int len = strlen(word);
        for(int i = 0; i < len; ++i) {
            cs += Character(word[i]);
        }
        cout << cs << endl;
    } else if(n == 6) {
        cout << "Testing CharSequence operator[char]" << endl;
        CharSequence cs("If you don't read the newspaper, you're uninformed. If you read the newspaper, you're mis-informed.");
        cout << cs['e'] << endl;
    } else if(n == 7) {
        cout << "Testing CharSequence toUpperCase" << endl;
        CharSequence cs("If you tell the truth, you don't have to remember anything");
        cout << cs.toUpperCase() << endl;
    } else if(n == 8) {
        cout << "Testing CharSequence operator ==" << endl;
        CharSequence cs1("abc");
        CharSequence cs2("abc");
        CharSequence cs3("abcd");
        CharSequence cs4("xyz");
        cout << (cs1 == cs2) << endl;
        cout << (cs1 == cs3) << endl;
        cout << (cs2 == cs4) << endl;
    }
    
    return 0;
}

