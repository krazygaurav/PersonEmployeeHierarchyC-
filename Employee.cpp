#include <iostream>
#include <string.h>
#include <stdlib.h>
#include "Employee.h"

using namespace std;

Employee:: ~Employee(){
    delete sal_change_rates;
}
Employee:: Employee(){
    salary = 0.0;
    cnt_sal_changes = 10;
    work_email = "work@";
    sal_change_rates = new double[10];
    for(int i=0;i<10;i++){
        sal_change_rates[i]= 0.0;
    }
}
Employee:: Employee( const Employee& clone){
    salary = clone.salary;
    sal_change_rates = clone.sal_change_rates;
    cnt_sal_changes = clone.cnt_sal_changes;
    work_email = clone.work_email;
}
Employee Employee::operator=(const Employee& rhs ){
    Employee emp;
    emp.salary = rhs.salary;
    emp.sal_change_rates = rhs.sal_change_rates;
    emp.cnt_sal_changes = rhs.cnt_sal_changes;
    emp.work_email = rhs.work_email;
    return emp;
    //return *this;
}
double Employee::getChangeRate( int i) const{
    return sal_change_rates[i];
}
string Employee::getEmail() const{
    return work_email;
}
void Employee::setEmail(string new_email){
    work_email = new_email;
}
string Employee::getTypeOfObj() const{
    return "Employee";
}

/*
The first parameter of this function is an array of Person pointers (i.e., Person *).

This function is going to first allocate an array of (numPersons + numEmployees ) Person pointers.
Next, for each of the first numPersons pointers on this array, say arrayPersonEmp[ i ], this function will create a Person object
using the new operator and make it the pointee of arrayPersonEmp[ i ]. Furthermore, it will call Person's setEmail() member function
 to set each newly created Person object's personalEmail to personal@gmail.com.
Finally, for each of the next numEmployees pointers on this array, say arrayPersonEmp[ j ], this function will create an Employee
object using the new operator and make it the pointee of arrayPersonEmp[ j ]. Similarly, it will call Employee's setEmail() member
 function to set each newly created Employee object's work_email to work@gmail.com.
*/
void mixedArray( Person** &arrayPersonEmp, int numPersons, int numEmployees){
    arrayPersonEmp = new Person*[numPersons + numEmployees];
    for(int i=0;i<numPersons;i++){
        arrayPersonEmp[i] = new Person();
        arrayPersonEmp[i]->setEmail("personal@gmail.com");
    }
    for(int i=0;i<numEmployees;i++){
        arrayPersonEmp[i+numPersons] = new Employee();
        arrayPersonEmp[i+numPersons]->setEmail("work@gmail.com");
    }
}

void deleteMixedArray(Person** &arrayPersonEmp, int size ){
    for(int i=0;i<size;i++){
        delete []arrayPersonEmp[i];
    }
    delete arrayPersonEmp;
}
