/*
 * class masterData: member functions
 */
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

#include "masterData.hh"


void masterData::addRec(record var){
    rec.push_back(var);
}


void masterData::findnDispRec(string emp_id) {
    for (int i = 0; i < rec.size(); i++){
        if (rec[i].getId() == emp_id){
            cout << "DFGDGFGFG" << endl;
            rec[i].display();
        }
    }
}

// display all Employee info on Screen in a fancy format
void masterData::printAllRecs(){
    for (int j = 0; j < rec.size(); j++){
        rec[j].display();
    }
}

// display all Employee info on Screen in CSV format
void masterData::printAllRecsCSV() {
    for(int j = 0; j < rec.size(); j++){
        cout << rec[j].getName() << ", " << rec[j].getId() << ", " << rec[j].getAddress() << ", " << rec[j].getTitle();
        cout << ", " << rec[j].getSalary() << endl;
    }
}

// save all the employee information to user given file
void masterData::saveAllRecsCSVFile(string fileName) {
    ofstream newFile;
    newFile.open(fileName);
    if (!newFile.is_open()){
        cerr << "Error" << endl;
        return;
    }
    
    for(int j = 0; j < rec.size(); j++){
        newFile << rec[j].getName() << ", " << rec[j].getId() << ", " << rec[j].getAddress() << ", " << rec[j].getTitle();
        newFile << ", " << rec[j].getSalary() << endl;
    }
    
}

// read Master.csv file and populate info to this class
void masterData::readMasterFile(string fileName) {
    
    string line;
    int temp;
    int start = 0;
    ifstream myfile;
    myfile.open(fileName);
    
    if (!myfile.is_open()){
        cerr << "Error, cannot open specified text file." << endl;
        return;
        
    } else {
        
        while (true){
            getline(myfile, line);
            
            if (myfile.eof()){
                break;
            }
            addRec(parseLine(line));
        }
        //printAllRecs();
        cout << "Read Masterfile : " << fileName << endl;
        
    }
};

// parse a line of CSV input
record masterData::parseLine(string line) {
    
    vector <string> newStr;
    record tempInfo;
    int found;
    int start = 0;
    string newWord;
    int count = 0;
    
    
    found = line.find(',');
    while (found != string::npos){
        count++;
        newWord = line.substr(start, found-start);
        start = found+1;
        
        newStr.push_back(newWord);
        found = line.find(',', found+1);
        
        
    }
    
    newWord = line.substr(start, line.size() - start);
    newStr.push_back(newWord);
    start = 0;
    found = 1;
    
    //create a class with the values from the csv line
    tempInfo.setName(newStr[0]);
    tempInfo.setId(newStr[1]);
    tempInfo.setAddress(newStr[2]);
    tempInfo.setTitle(newStr[3]);
    tempInfo.setSalary(newStr[4]);
    
    return tempInfo;
}
