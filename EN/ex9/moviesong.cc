#include<iostream>
#include<string.h>
using namespace std;

class Person {
private:
    char name[20];
    int year;
public:
    Person (char *name, int year) {
        strcpy(this->name, name);
        this->year = year;
    }
    Person () {
        strcpy(this->name, "");
    }
    bool operator==(char *name) {
        return strcmp(this->name, name) == 0;
    }
    char const * getName() {
        return name;
    }
    void print() {cout << name << " (" << year << ")";}
};

class Song {
  

protected:
    char title[30];
    Person performers[10];
    int numberPerformers;
    int *ratings;
    int numberRatings;

public:
    Song(char *title, Person *performers, int numberPerformers, int *ratings, int numberRatings) {
        strcpy(this->title, title);
        this->numberPerformers = numberPerformers;
        for (int i = 0; i < numberPerformers; i++) this->performers[i] = performers[i];
        this->numberRatings = numberRatings;
        this->ratings = new int[numberRatings];
        for (int i = 0; i < numberRatings; i++) this->ratings[i] = ratings[i];

    }
    Song(const Song &k) {
        strcpy(this->title, k.title);
        this->numberPerformers = k.numberPerformers;
        for (int i = 0; i < k.numberPerformers; i++) this->performers[i] = k.performers[i];
        this->numberRatings = k.numberRatings;
        this->ratings = new int[k.numberRatings];
        for (int i = 0; i < k.numberRatings; i++) this->ratings[i] = k.ratings[i];

    }
    Song operator=(const Song &k) {
        if (&k == this) return *this;
        strcpy(this->title, k.title);
        this->numberPerformers = k.numberPerformers;
        for (int i = 0; i < k.numberPerformers; i++) this->performers[i] = k.performers[i];
        this->numberRatings = k.numberRatings;
        delete [] ratings;
        this->ratings = new int[k.numberRatings];
        for (int i = 0; i < k.numberRatings; i++) this->ratings[i] = k.ratings[i];
        return *this;
    }

    int getnumberPerformers() {return numberPerformers;}
    Person operator[](int i) {if (i < numberPerformers && i >= 0) return performers[i]; else return Person();}

    virtual float getTotalRating() {
        int min = ratings[0];
        int max = ratings[0];

        for (int i=1;i<numberRatings;i++) {
            if (ratings[i]>max) {
                max = ratings[i];
            }
            if (ratings[i]<min) {
                min = ratings[i];
            }
        }

        return (max+min)/2.0;

    }

    virtual void print() {
        /*[Performer 1] ([Year1]), [Performer2] ([Year2]) …  : [Name]

        Movie: [Name of the movie]
        */

        for (int i=0;i<numberPerformers;i++) {
            performers[i].print();
            if (i!=(numberPerformers-1)) {
                cout<<", ";
            }
            else {
                cout<<": ";
            }
        }

        cout<<title<<endl;
    }

};

class Movie {
    
protected:
    char *title;
    int popularity;
public:
    Movie(char *title, int popularity) {
        this->popularity = popularity;
        this->title = new char[strlen(title) + 1];
        strcpy(this->title, title);
    }
    Movie(const Movie &v) {
        this->popularity = v.popularity;
        this->title = new char[strlen(v.title) + 1];
        strcpy(this->title, v.title);
    }
    Movie operator=(const Movie &v) {
        if (this == &v) return *this;
        this->popularity = v.popularity;
        delete [] title;
        this->title = new char[strlen(v.title) + 1];
        strcpy(this->title, v.title);
        return *this;
    }
    void print()  {cout << "Movie:" << title << endl;}
    virtual ~Movie() {delete [] title;}

};

class MovieSong : public Song, public Movie {
private:
    int songPopularity;

public:
    MovieSong (char * songTitle, Person * performers, int numberOfPerformers,
     int * ratings, int numberOfRatings, char * movieTitle,
     int popularity, int songPopularity) : 
     Song (songTitle, performers, numberOfPerformers, ratings, numberOfRatings), 
     Movie (movieTitle, popularity) {
        this->songPopularity = songPopularity;
    }

    MovieSong (const MovieSong & ms) : Song(ms), Movie(ms) {
        this->songPopularity = ms.songPopularity;
    }

    // char * getMovieTitle() const {
    //     return Movie::title;
    // }

    // char * getSongTitle() const {
    //     return Song::title;
    // }

    MovieSong & operator = (const MovieSong & ms) {
        if (this==&ms)
            return *this;
        strcpy(Song::title, ms.Song::title);
        this->numberPerformers = ms.numberPerformers;
        for (int i = 0; i < ms.numberPerformers; i++) this->performers[i] = ms.performers[i];
        this->numberRatings = ms.numberRatings;
        delete [] ratings;
        this->ratings = new int[ms.numberRatings];
        for (int i = 0; i < ms.numberRatings; i++) this->ratings[i] = ms.ratings[i];
            this->popularity = ms.popularity;
        delete [] Movie::title;
        Movie::title = new char[strlen(ms.Movie::title) + 1];
        strcpy(Movie::title, ms.Movie::title);
    }

    float getTotalRating() {
        /*
        The rating of a movie song is computed as a product 
        of the average of minimum and maximum rating given 
        from people and a coefficient of popularity 
        (computed by dividing the popularity of the song 
        with the popularity of the movie).*/
        float peopleRatings = Song::getTotalRating();

        float coef = songPopularity / (Movie::popularity*1.0);
        
        return peopleRatings * coef;
    }

    virtual void print() {
        /*[Performer 1] ([Year1]), [Performer2] ([Year2]) …  : [Name]

        Movie: [Name of the movie]
        */  

        Song::print();
        cout<<endl;
        Movie::print();
    }

};


int main() {

    Person performers[10];
    int year, numberOfPerformers, ratings[20], rating, numberOfRatings, type, popularity, songPopularity;
    char name[40], title[30], perfomer[30];

    cin >> type;

    if (type == 1) //test class MovieSong
    {
        cout << "-----TEST MovieSong-----" << endl;
        cin >> title >> numberOfPerformers;
        for (int i = 0; i < numberOfPerformers; i++) {
            cin >> name >> year;
            performers[i] = Person(name, year);
        }
        cin >> numberOfRatings;
        for (int i = 0; i < numberOfRatings; i++) {
            cin >> rating;
            ratings[i] = rating;
        }
        cin >> title >> popularity >> songPopularity;


        MovieSong ok(title, performers, numberOfPerformers, ratings, numberOfRatings, title, popularity, songPopularity);
        cout << "Object of class MovieSong is created";

    } else if (type == 2) // function print in song
    {
        cout << "-----TEST print-----" << endl;
        cin >> title >> numberOfPerformers;
        for (int i = 0; i < numberOfPerformers; i++)
        {
            cin >> name >> year;
            performers[i] = Person(name, year);
        }
        cin >> numberOfRatings;
        for (int i = 0; i < numberOfRatings; i++)
        {
            cin >> rating;
            ratings[i] = rating;
        }

        Song k(title, performers, numberOfPerformers, ratings, numberOfRatings);
        k.print();

    } else if (type == 3) // function getTotalRating
    {
        cout << "-----TEST getTotalRating-----" << endl;
        cin >> title >> numberOfPerformers;
        for (int i = 0; i < numberOfPerformers; i++)
        {
            cin >> name >> year;
            performers[i] = Person(name, year);
        }
        cin >> numberOfRatings;
        for (int i = 0; i < numberOfRatings; i++)
        {
            cin >> rating;
            ratings[i] = rating;
        }

        Song k(title, performers, numberOfPerformers, ratings, numberOfRatings);
        cout << "Total rating: " << k.getTotalRating() << endl;

    } else if (type == 4) //funkcija getTotalRating vo MovieSong
    {
        cout << "-----TEST getTotalRating-----" << endl;
        cin >> title >> numberOfPerformers;
        for (int i = 0; i < numberOfPerformers; i++)
        {
            cin >> name >> year;
            performers[i] = Person(name, year);
        }
        cin >> numberOfRatings;
        for (int i = 0; i < numberOfRatings; i++)
        {
            cin >> rating;
            ratings[i] = rating;
        }
        cin >> title >> popularity >> songPopularity;

        MovieSong fp(title, performers, numberOfPerformers, ratings, numberOfRatings, title, popularity, songPopularity);
        cout << "Total rating: " << fp.getTotalRating() << endl;

    } else if (type == 5) //funkcija print vo MovieSong
    {
        cout << "-----TEST print -----" << endl;
        cin >> title >> numberOfPerformers;
        for (int i = 0; i < numberOfPerformers; i++)
        {
            cin >> name >> year;
            performers[i] = Person(name, year);
        }
        cin >> numberOfRatings;
        for (int i = 0; i < numberOfRatings; i++)
        {
            cin >> rating;
            ratings[i] = rating;
        }
        cin >> title >> popularity >> songPopularity;

        MovieSong fp(title, performers, numberOfPerformers, ratings, numberOfRatings, title, popularity, songPopularity);
        fp.MovieSong::print();

    } else if (type == 6) //all classes
    {
        cout << "-----TEST Song and MovieSong-----" << endl;
        cin >> title >> numberOfPerformers;
        for (int i = 0; i < numberOfPerformers; i++)
        {
            cin >> name >> year;
            performers[i] = Person(name, year);
        }
        cin >> numberOfRatings;
        for (int i = 0; i < numberOfRatings; i++)
        {
            cin >> rating;
            ratings[i] = rating;
        }
        cin >> title >> popularity >> songPopularity;

        Song *p = new MovieSong(title, performers, numberOfPerformers, ratings, numberOfRatings, title, popularity, songPopularity);
        p->print();
        cout << "Total rating: " << p->getTotalRating() << endl;
        delete p;


    } else if (type == 7) // function average rating
    {
        cout << "-----TEST average rating-----" << endl;
        int k, opt;
        cin >> k;
        Song **pesni = new Song*[k];
        for (int j = 0; j < k; j++) {
            cin >> opt; //1 Song 2 MovieSong
            cin >> title >> numberOfPerformers;
            for (int i = 0; i < numberOfPerformers; i++)
            {
                cin >> name >> year;
                performers[i] = Person(name, year);
            }
            cin >> numberOfRatings;
            for (int i = 0; i < numberOfRatings; i++)
            {
                cin >> rating;
                ratings[i] = rating;
            }
            if (opt == 1) {
                pesni[j] = new Song(title, performers, numberOfPerformers, ratings, numberOfRatings);
            } else {
                cin >> title >> popularity >> songPopularity;
                pesni[j] = new MovieSong(title, performers, numberOfPerformers, ratings, numberOfRatings, title, popularity, songPopularity);
            }
        }

        cout << "Average rating of the songs is " << averageRating(pesni, k);
        for (int j = 0; j < k; j++) delete pesni[j];
        delete [] pesni;

    } else if (type == 8) // function print songs
    {
        cout << "-----TEST print songs-----" << endl;
        int k, opt;
        cin >> k;
        Song **pesni = new Song*[k];
        for (int j = 0; j < k; j++) {
            cin >> opt; //1 Song 2 MovieSong
            cin >> title >> numberOfPerformers;
            for (int i = 0; i < numberOfPerformers; i++)
            {
                cin >> name >> year;
                performers[i] = Person(name, year);
            }
            cin >> numberOfRatings;
            for (int i = 0; i < numberOfRatings; i++)
            {
                cin >> rating;
                ratings[i] = rating;
            }
            if (opt == 1) {
                pesni[j] = new Song(title, performers, numberOfPerformers, ratings, numberOfRatings);
            } else {
                cin >> title >> popularity >> songPopularity;
                pesni[j] = new MovieSong(title, performers, numberOfPerformers, ratings, numberOfRatings, title, popularity, songPopularity);
            }
        }
        cin >> perfomer;
        cout << "Songs of " << perfomer << " are:" << endl;
        printSongs(perfomer, pesni, k);
        for (int j = 0; j < k; j++) delete pesni[j];
        delete [] pesni;

    }


    return 0;
}

