#include<stdio.h>

typedef struct date
{
	int day;
	int month;
	int year;
} date;

int compare (date d1, date d2) {
	if (d1.year == d2.year) {
		if (d1.month == d2.month) {
			if (d1.day == d2.day) 
				return 0;
			else if (d1.day > d2.day)
				return 1;
			else return -1;
		}
		else if (d1.month > d2.month)
			return 1;
		else
			return -1;
	}
	//return d1.year > d2.year ? 1 : -1;
	else if (d1.year > d2.year)
		return 1;
	else
		return -1;
}

int findGreaterAndSmaller (date d1, date d2, date * greater, date * smaller) {

	if (compare(d1,d2)==0)
		return 0;
	else if (compare(d1,d2)==1) {
		*greater = d1;
		*smaller = d2;
		return 1;
	}
	else {
		*greater = d2;
		*smaller = d1;
		return -1;
	}
}

int diff (date d1, date d2) {

	date greater, smaller;
	if (findGreaterAndSmaller(d1,d2, &greater, &smaller)==0)
		return 0;

	int totalDays = 0;
	totalDays += ((greater.year - smaller.year)*365);
	totalDays += ((greater.month - smaller.month)*30);
	totalDays += (greater.day - smaller.day);

	return totalDays;
}

int main () {
	date d1,d2;
	date * dPtr = &d2;

	scanf("%d %d %d", &d1.day, &d1.month, &d1.year);
	scanf("%d %d %d", &dPtr->day, &dPtr->month, &dPtr->year);

	printf("Compare result between them: %d\n", compare(d1,d2));
	printf("The difference between them is : %d", diff(d1,d2));

}