#include<stdio.h>
#include<string.h>
#include<ctype.h>

typedef struct student
{
	char firstName [50];
	char lastName [50];
	int id;
	int totalPoints;	
} student;

int compare (student s1, student s2) {
	if (s1.totalPoints==s2.totalPoints)
		return 0;
	else if (s1.totalPoints > s2.totalPoints)
		return 1;
	else
		return -1;
}

void bubbleSort(student * students, int n)  
{  
    int i, j;  
    for (i = 0; i < n-1; i++)      
	    for (j = 0; j < n-i-1; j++)  
	        if (compare(students[j], students[j+1])==-1) {
	        	student temp = students[j];
	        	students[j] = students[j+1];
	        	students[j+1] = temp;
	        }
	            
} 

void sortAndPrint (student * students, int n) {
	bubbleSort(students, n);
	int i;
	for (i=0;i<n;i++) {
		printf("%s %s %d %d\n",
			students[i].lastName,
			students[i].firstName,
			students[i].id,
			students[i].totalPoints);
	}
} 

void normalize (char * name) {
	name[0] = toupper(name[0]);
	int i;
	for (i=1;i<strlen(name);i++)
		name[i] = tolower(name[i]);
}

int main () {
	student students [100];
	int n;
	scanf("%d", &n);

	int i,j, point;
	for (i=0;i<n;i++) {
		scanf("%s", students[i].firstName);
		scanf("%s", students[i].lastName);
		scanf("%d", &students[i].id);
		students[i].totalPoints = 0;
		for (j=0;j<4;j++){
			scanf("%d", &point);
			students[i].totalPoints+=point;
		}
		normalize(students[i].firstName);
		normalize(students[i].lastName);
	}

	sortAndPrint(students, n);
}