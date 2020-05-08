#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

//Fixed mistakes:
// - the model of the most expensive camera should be printed (it's a mistake in the text of the task)
// - the other mistakes were in the test cases (they are fixed now)


class Camera {
protected:
	char manufacturer [21];
	char model[21] ;
	int year;
	float resolution;

public: 
	Camera (char * manufacturer = "", char * model = "", int year = 2000, float resolution = 5.0) {
		strcpy(this->manufacturer, manufacturer);
		strcpy(this->model, model);
		this->year = year;
		this->resolution = resolution;
	}

	Camera (const Camera & c) {
		strcpy(this->manufacturer, c.manufacturer);
		strcpy(this->model, c.model);
		this->year = c.year;
		this->resolution = c.resolution;
	}

	char * getManufacturer() {
		return manufacturer;
	}

	virtual double price () = 0;
	virtual double rentalPrice (int days) = 0;
};

bool operator > (Camera & left, Camera & right) {
	return left.price() > right.price();
} 

class PhotoCamera : public Camera {
private:
	bool raw;
public:
	PhotoCamera (char * manufacturer = "", char * model = "", 
		int year = 2000, float resolution = 5.0, bool raw = true) : 
	Camera(manufacturer, model, year, resolution) {
		this->raw = raw;
	}

	PhotoCamera (const PhotoCamera & c) : Camera (c){
		this->raw = c.raw;
	}

	double price () {
		//The price of PhotoCamera is calculated as: 100 + resolution*20 (+ 50 if RAW is supported)
		double result = 100 + resolution*20;
		if (raw)
			result+=50;
		return result;
	}

	double rentalPrice (int days) {
		//For the PhotoCamera and the VideoCamera it is calculated in the same way as: 1/100 of the selling price of the camera per day. If the camera is rented for more than 7 days, a discount of 20% is calculated.
		double byDay = price()/100;
		double result = days * byDay;

		if (days>7) {
			result*=0.8;
		}

		return result;
	}
};

class VideoCamera : public Camera {
private:
	int maxLength; //in seconds

public:
	VideoCamera (char * manufacturer = "", char * model = "", 
		int year = 2000, float resolution = 5.0, int maxLength = 100) : 
	Camera(manufacturer, model, year, resolution) {
		this->maxLength = maxLength;
	}

	VideoCamera (const VideoCamera & vc) : Camera (vc) {
		this->maxLength = vc.maxLength;
	}

	double price() {
		double result = resolution * 80;
		if (maxLength > 3600) { //60 min = 3600 sec
			result*=1.4;
		}
		return result;
	}

	double rentalPrice (int days) {
		double byDay = price()/100;
		double result = days * byDay;
		if (days>7) {
			result*=0.8;
		}
		return result;
	}
};

class FilmCamera : public Camera {
private:
	int fps;

public:
	FilmCamera (char * manufacturer = "", char * model = "", 
		int year = 2000, float resolution = 5.0, int fps = 100) : 
	Camera(manufacturer, model, year, resolution) {
		this->fps = fps;
	}

	FilmCamera (const FilmCamera & fc) : Camera(fc) {
		this->fps = fc.fps;
	}

	double price () {
		double result = 50000.0;

		if (fps>30) {
			int diff = fps-30;
			result+=(diff*5000.0);
		}

		return result;
	}

	double rentalPrice (int days) {
		double result = days*500;

		if (fps > 60) {
			result*=2.0;
		}

		return result;
	}
};

/*
Define a global function production(…) that will take an array 
of Camera pointers, a number of cameras in the array and number
 of days filming will last as arguments, and will return the total 
 price for renting all the cameras in the array for the given number
  of days.
*/

double production (Camera ** cameras, int n, int days) {
	double sum = 0.0;

	for (int i=0;i<n;i++) {
		sum+=cameras[i]->rentalPrice(days);
	}

	return sum;
}

/*mostExpensiveCamera(…) that will take an array of Camera pointers,
 a number of cameras in the array as arguments, and will return the 
 manufacturer of the camera with the highest selling price.
*/

char * mostExpensiveCamera(Camera ** cameras, int n) {

	Camera * max = cameras[0];

	for (int i=1;i<n;i++) {
		if (*cameras[i] > *max) { 
			max = cameras[i];
		}
	}

	return max->getManufacturer();
}





int main(int argc, char *argv[])
{
  // Variables for reading input
  char model[20], producer[20];
  int year, length, fps, n;
  float resolution;
  bool raw;

  int t;

  // Array of cameras
  Camera *c [10];

  // Read number of cameras
  cin>>n;

  for(int i = 0; i < n; ++i){

    // Camera type: 1 - Photo, 2 - Video, 3 - Film
    cin>>t;

    if (t==1){
      cin >> producer >> model >> year >> resolution;
      cin >> raw;
      c[i] = new PhotoCamera(producer, model, year, resolution, raw);
    }
    else if (t==2){
      cin >> producer >> model >> year >> resolution;
      cin >> length;
      c[i] = new VideoCamera(producer, model, year, resolution, length);
    }
    else if (t==3){
      cin >> producer >> model >> year >> resolution;
      cin >> fps;
      c[i] = new FilmCamera(producer, model, year, resolution, fps);
    }
  }


  // Production days
  int days;
  cin >> days;
  
  
  cout<<"\n" << "Price of production is: " << production(c, n, days);
  cout<<"\n" << "Most expensive camera used in production is: " << mostExpensiveCamera(c, n);


  return 0;
}
