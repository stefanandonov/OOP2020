# Doctor and patient first partial exam tast

Impement a structure `Patient` in the programming language `C` that will contain information about:

- first and last name of the patient (char array of max 100 chars)
- does the patient have insurance (1=yes, 0=no)
- number of visits to the doctor during the last month (integer)

Then create a structure `Doctor`  that will contain info about:

- name of the doctor (char array of max 100 chars)
- number of patients (integer)
- List of patients (array of max 100 elements of the structure `Patient`)
- price of one visit of the doctor (double)

Create a method `most_successful_doctor (Doctor * doctors, int n)` that has two arguments, an array of doctors (elements of the structure Doctor) and an integer that represents the number of doctors in the array. The function should print the doctor who earned most money from visits of not insured patients. If two or more doctors have the same amount of earned money then the doctor that has most visits from the patients in the last month.

Complete the main function for scanning the info for the doctors and the patients.

## Test cases:

1. Input:
2
Д-р.Јованка_Јовановска
3
300.00
Јованова_Ивана 1 2
Боцевска_Ивана 0 3
Илиевска_Ангела 1 0
Д-р.Трајче_Трајчев
2
650.00
Крстевски_Филип 1 0
Цветановски_Иван 1 10

Output:
Д-р.Јованка_Јовановска 900.00 5

2. Input:
2
Д-р.Јованка_Јовановска
3
300.00
Јованова_Ивана 1 2
Боцевска_Ивана 0 3
Илиевска_Ангела 1 0
Д-р.Трајче_Трајчев
3
300.00
Крстевски_Филип 1 0
Цветановски_Иван 1 10
Ивановска_Цветанка 0 3

Output:
Д-р.Трајче_Трајчев 900.00 13

3. Input:
3
Д-р.Јованка_Јовановска
3
300.00
Јованова_Ивана 1 2
Боцевска_Ивана 0 3
Илиевска_Ангела 1 0
Д-р.Петко_Петковски
1
50.00
Ивановска_Цветанка 0 18
Д-р.Трајче_Трајчев
3
300.00
Крстевски_Филип 1 0
Цветановски_Иван 1 10
Ивановска_Цветанка 0 3

Output:
Д-р.Петко_Петковски 900.00 18