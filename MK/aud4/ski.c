#include<stdio.h>
#include<string.h>

typedef struct SkiLift {
	char ime [15];
	int maxKapacitet;
	int voFunkcija; //vo C++ tuka treba da bide bool 
} SkiLift;

typedef struct SkiCentar
{
	char ime [20];
	char drzava [20];
	SkiLift skiLiftovi [20];
	int n;
	
} SkiCentar;

int kapacitetNaSkiCentar (SkiCentar skiCentar) {
	int i;
	int kapacitet = 0;
	for (i=0;i<n;i++) {
		if (skiCentar[i].voFunkcija) {
			kapacitet+=skiCentar[i].maxKapacitet;
		}
	}

	return kapacitet;
}

int compare (SkiCentar lev, SkiCentar desen) { 
	if (kapacitetNaSkiCentar(lev)==kapacitetNaSkiCentar(desen))
		return 0;
	else if (kapacitetNaSkiCentar(lev) > kapacitetNaSkiCentar(desen))
		return 1;
	else return -1;
}

void najgolemKapacitet(SkiCentar *sc, int n) {
	SkiCentar max = sc [0];
	int i;
	for (i=1;i<n;i++) {
		if (compare(sc[i], max)==1) {
			max = sc[i];
		}
	}

	printf("%s\n%s\n%d\n", max.ime, max.drzava, kapacitetNaSkiCentar(max));

}

int main()
{
	scanf("%d", &n);
	for (i = 0; i < n; i++){
		//vnesi ime
		//vnesi drzava
		//vnesi broj na liftovi
        
		
        //za sekoj ski lift vnesi:
			//vnesi ime
            //vnesi maksimalen broj korisnici
            //vnesi dali e pusten vo funkcija
	}
	
    //povik na funkcijata najgolemKapacitet
	
	return 0;
}