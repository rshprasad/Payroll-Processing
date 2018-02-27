#ifndef __MASTERDATA_HH__

#include "record.hh"

class masterData{
    vector<record> rec;
    
public:
    void addRec(record var);
    
    void findnDispRec(string emp_id);
    
    // display all Employee info on Screen in a fancy format
    void printAllRecs();
    
    // display all Employee info on Screen in CSV format
    void printAllRecsCSV();
    
    // save all the employee information to user given file
    void saveAllRecsCSVFile(string fileName);
    
    // read Master.csv file and populate info to this class
    void readMasterFile(string fileName);
    
    // parse a line of CSV input
    record parseLine(string line);

};

#endif
