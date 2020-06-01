#include <iostream>
using namespace std;
class student
{
protected:
    int rno;
    int m1 ;
    int m2 ;

public:
    student (int rno = 15, int m1 = 10, int m2 = 10) {
        this->rno = rno;
        this->m1 = m1;
        this->m2 = m2;
    }
};
class sports
{
protected:
    int sm;
public:
    sports (int sm = 10) {
        this->sm = sm;
    }
    
};
class statement:public student,public sports
{
private:
    int tot,avg;
public:
    statement (int rno = 15, int m1 = 10, int m2 = 10, int sm = 10) :
    student(rno,m1,m2), sports(sm) {}
    void display()
    {
        tot = (m1 + m2 + sm);
        avg = tot / 3;
        cout << tot << " " << avg;
        
    }
};
int main()
{
    statement obj;
    obj.display();
}

TA::TA(int ) called
Faculty::Faculty(int ) called
Student::Student(int ) called
Person::Person(int ) called




