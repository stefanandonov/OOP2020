#include<stdio.h>

typedef struct date {
	int den;
	int mesec;
	int godina;
} date;

int compare (date d1, date d2) {
	if (d1.godina==d2.godina) {
		if (d1.mesec == d2.mesec) {
			if (d1.den == d2.den)
				return 0;
			//return d1.den > d2.den ? 1 : -1;
			else if (d1.den > d2.den)
				return 1;
			else
				return -1;
		}
		else if (d1.mesec > d2.mesec)
			return 1;
		else
			return -1;
	}
	else if (d1.godina > d2.godina)
		return 1;
	else 
		return -1;
}

int razlika (date d1, date d2) {
	date pogolem, pomal;
	if (compare(d1,d2)==0)
		return 0;
	else if (compare(d1,d2)==1) {
		pogolem = d1;
		pomal = d2;
	}
	else {
		pogolem = d2;
		pomal = d1;
	}

	int denovi = 0;
	denovi += (pogolem.godina - pomal.godina)*365;
	denovi += (pogolem.mesec - pomal.mesec)*30;
	denovi += (pogolem.den - pomal.den);
	return denovi; 
}

int main () {
	date d1;
	date d2;
	date * ptrDate = &d2;

	scanf("%d %d %d", &d1.den, &d1.mesec, &d1.godina);
	scanf("%d %d %d", &ptrDate->den, &ptrDate->mesec, &ptrDate->godina);
	//printf("%d %d %d", d1.den, d1.mesec, d1.godina);
	//printf("%d %d %d", ptrDate->den, ptrDate->mesec, ptrDate->godina);
	
	printf("%d", razlika(d1,d2));
	
}
