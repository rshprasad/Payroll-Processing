/*
 * class record: member functions
 */
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

#include "record.hh"


void record::setId(string emp_id) {
    empId = emp_id;
}

string record::getId() {
    return empId;
}

void record::setName(string emp_name){
    name = emp_name;
}

string record::getName(){
    return name;
}

void record::setAddress(string emp_address){
    address = emp_address;
}

string record::getAddress(){
    return address;
}

void record::setTitle(string emp_title){
    title = emp_title;
}

string record::getTitle(){
    return title;
}

void record::setSalary(string emp_salary){
    baseSalary = emp_salary;
}

string record::getSalary(){
    return baseSalary;
}

void record::display() {
    cout << "Employee ID : " << empId << endl;
    cout << "Employee Name : " << name << endl;
    cout << "Employee Address : " << address << endl;
    cout << "Employee title : " << title << endl;
    cout << "Employee Salary : " << baseSalary << endl;
    cout << endl;
}
