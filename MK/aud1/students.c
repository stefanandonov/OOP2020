#include<stdio.h>

typedef struct student {
	char ime [100];
	char prezime [100];
	int index;
	int totalPoints;
} student;

void sort (student * students, int n) {
	int i = 0, j = 0;
	student tmp;
    for (i = 0; i < n; i++) {   // loop n times - 1 per element
        for (j = 0; j < n - i - 1; j++) { // last i elements are sorted already
            if (students[j].totalPoints <= students[j+1].totalPoints) {  // swop if order is broken
                tmp = students[j];
                students[j] = students[j+1];
                students[j+1] = tmp;
            }
        }
    }
}

int main () {
	int n;
	int i,j;
	int points, p;
	student students [100];

	scanf("%d", &n);

	for(i=0;i<n;i++) {
		scanf("%s", &students[i].ime);
		scanf("%s", &students[i].prezime);
		scanf("%d", &students[i].index);
		points=0;
		for (j=0;j<4;j++) {
			scanf("%d", &p);
			points+=p;
		}
		students[i].totalPoints = points;
	}

	sort(students,n);

	for (i=0;i<n;i++) {
		printf("%s %s %d %d\n", students[i].prezime,
			students[i].ime,
			students[i].index,
			students[i].totalPoints);
	}

}