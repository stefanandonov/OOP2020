#include<stdio.h>
#include<string.h>
#include<ctype.h>

typedef struct President
{
	char name [50];
	char party [50];
} President;

typedef struct city 
{
	char cityName [50];
	int population;
} city;

typedef struct country
{
	char name [50];
	int population;
	city capital;
	President president;
} country;

int compare (country c1, country c2) {
	if (c1.capital.population == c2.capital.population)
		return 0;
	else if (c1.capital.population > c2.capital.population)
		return 1;
	else
		return -1;
}

void findPresident (country * countries, int n) {
	country max = countries[0];

	int i;
	for (i=1;i<n;i++) {
		if (compare(countries[i], max)==1) {
			max = countries[i];
		}
	}

	printf("%s\n", max.president.name);
}

int main () {
	int i,n;
	country countries [50];
	scanf("%d", &n);

	for (i=0;i<n;i++) {
		scanf("%s %d %s %d %s %s", 
			countries[i].name,
			&countries[i].population,
			countries[i].capital.cityName,
			&countries[i].capital.population,
			countries[i].president.name,
			countries[i].president.party);
	}

	findPresident(countries, n);



}