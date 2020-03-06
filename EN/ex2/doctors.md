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