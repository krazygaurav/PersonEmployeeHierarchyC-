#include<iostream>
#include "Person.h"
#include "Employee.h"

using namespace std;
int main(){
    Person person;
    person.setEmail("singhal.gaurav93@gmail.com");
    cout<<person.getTypeOfObj()<<endl;
    cout<<person.getEmail()<<endl;
    cout<<person.getPlace(2)<<endl;

    Employee employee;
    employee.setEmail("singhal.gaurav93@gmail.com");
    cout<<employee.getTypeOfObj()<<endl;
    cout<<employee.getEmail()<<endl;
    cout<<employee.getChangeRate(3)<<endl;
    return 0;
}
