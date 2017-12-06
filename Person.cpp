
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include "Person.h"

using namespace std;


Person::~Person(){
    delete placesVisited;
}
Person::Person(){
    //0->SSN, "na"->name, "personal@"->personalEmail, 10->cntPlaces, allocate space to placesVisited and initializes each place to "unknown"
    SSN = 0;
    name = "na";
    personalEmail = "personal@";
    cntPlaces = 10;
    placesVisited = new string[10];
    for(int i=0;i<10;i++){
        placesVisited[i] = "unknown";
    }
}

Person::Person( const Person &clone ){
    SSN = clone.SSN;
    name = clone.name;
    personalEmail = clone.personalEmail;
    cntPlaces = clone.cntPlaces;
    placesVisited = clone.placesVisited;
}
Person& Person:: operator=(const Person& rhs ){
    Person person;
    person.SSN = rhs.SSN;
    person.name = rhs.name;
    person.personalEmail = rhs.personalEmail;
    person.cntPlaces = rhs.cntPlaces;
    person.placesVisited = rhs.placesVisited;
    return person;
}
string Person:: getPlace(int i) const{
    return placesVisited[i];
}

string Person::getEmail() const{
    return personalEmail;
}

void Person::setEmail(string new_email) {
    personalEmail = new_email;
}

string Person::getTypeOfObj() const{
    return "Person";
}
