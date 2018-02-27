/*
 * class menu: member functions
 */
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

#include "menu.hh"

void menu::displayMenu(){
    int inVal = 0;
    while (true){
    cout << "-------------- MENU --------------" << endl;
    cout << "1 : Initialize From File" << endl;
    cout << "2 : Display All Records" << endl;
    cout << "3 : Add New Employee" << endl;
    cout << "4 : Search" << endl;
    cout << "5 : Quit" << endl;
    cout << "----------------------------" << endl;
    cout << "Please select which option ... ";
    cin >> inVal;
        cout << endl;
    
        if (inVal > 5 || inVal < 1) {
            cerr << "Error, invalid option..." << endl;
            continue;
        }
        switch (inVal) {
            case 1 :
                option1();
                break;
            case 2 :
                option2();
                break;
            case 3 :
                option3();
                break;
            case 4 :
                option4();
                break;
            case 5 :
                option5();
                break;
                
        }
        
        
    }
}

void menu::option1(){
    string temp;
    
    cout << "Enter the name of the file" << endl;
    cin >> temp;
    
    ifstream inFile;
    //check if file exists
    
    empDB.readMasterFile(temp);
}

void menu::option2(){
    empDB.printAllRecs();
}

void menu::option3(){
    string newEmp;
    record newRec;
    cout << "Please enter the employee's name..." << endl;
    getline(cin, newEmp);
    newRec.setName(newEmp);
    
    cout << "Please enter the employee's ID..." << endl;
    getline(cin, newEmp);
    newRec.setId(newEmp);
    
    cout << "Please enter the employee's address..." << endl;
    getline(cin, newEmp);
    newRec.setAddress(newEmp);
    
    cout << "Please enter the employee's title..." << endl;
    getline(cin, newEmp);
    newRec.setTitle(newEmp);
    
    cout << "Please enter the employee's salary..." << endl;
    getline(cin, newEmp);
    newRec.setSalary(newEmp);
    
    empDB.addRec(newRec);
}

void menu::option4(){
    string tempStr;

    cout << "Enter the ID of the employee you want to search ... " << endl;
    cin >> tempStr;
    empDB.findnDispRec(tempStr);
}

void menu::option5(){
    string tempQuit;

    cout << "Do you want to save all changes before quitting? (yes or no)" << endl;
    cin >> tempQuit;
    if (tempQuit == "yes"){
        string tempFile;
        cout << "Enter the name of the file" << endl;
        cin >> tempFile;
        empDB.saveAllRecsCSVFile(tempFile);
    } else {
        exit(0);
    }
}
