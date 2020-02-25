#include<stdio.h>

typedef struct Pacient
{
	char name [100];
	int insurance;
	int visits;

} Pacient;

typedef struct MaticenDoktor
{
	char name [100];
	int count;
	Pacient pacients [100];
	double price;
} MaticenDoktor;

double profit (MaticenDoktor d1) {
	int i;
	double suma = 0;
	for (i=0;i<d1.count;i++) {
		if (d1.pacients[i].insurance==0)
			suma += (d1.pacients[i].visits * d1.price);
	}
	return suma;
}

int pregledi (MaticenDoktor d1) {
	int i;
	double suma = 0;

	for (i=0;i<d1.count;i++) {
		suma += d1.pacients[i].visits;
	}
	return suma;
}
int compare (MaticenDoktor d1, MaticenDoktor d2) {
	if (profit(d1)==profit(d2)) {
		if (pregledi(d1) == pregledi(d2))
			return 0;
		else if (pregledi(d1) > pregledi(d2))
			return 1;
		else
			return -1;
	}
	else if (profit(d1) > profit(d2))
		return 1;
	else
		return 0;
}

void najuspeshen_doktor (MaticenDoktor * doktori, int n) {
	MaticenDoktor max = doktori[0];

	int i;
	for (i=1;i<n;i++) {
		if (compare(doktori[i], max)==1) {
			max = doktori[i];
		}
	}

	printf("%s %.2f %d", max.name, profit(max), pregledi(max));
}

int main () {
	int j,i,n;
	MaticenDoktor maticni [100];

	scanf("%d", &n);
	for (i=0;i<n;i++) {
		scanf("%s", maticni[i].name);
		scanf("%d", &maticni[i].count);
		scanf("%lf", &maticni[i].price);
		for (j=0;j<maticni[i].count;j++) {
			Pacient p;
			scanf("%s %d %d", 
				p.name,
				&p.insurance,
				&p.visits);
			maticni[i].pacients[j]=p;
		}

	}

	najuspeshen_doktor(maticni, n);
	
	return 0;
}