#ifndef WEATHER_H
#define WEATHER_H

#include <string>

using namespace std;

struct GPS {
	double latitude;
	double longitude;
	GPS(double la, double lo) : latitude(la),
		longitude(lo) {}
};

ostream& operator<<(ostream& os, const GPS& gps);

const int UNRATED = -1;
const int BAD = 0;
const int OK = 1;
const int GOOD = 2;

class Weather {
	friend ostream& operator<<(ostream& os, const Weather& w);
public:
	Weather(string nm, GPS loc);
	string get_name() const;
	int get_rating() const;
	void set_rating(int new_rating);

private:
	string station_nm;
	GPS my_loc;
	int rating = UNRATED;
};
#endif