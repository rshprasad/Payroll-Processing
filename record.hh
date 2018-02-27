#ifndef __RECORD_HH__
/*
 *  Class record - employee master information
 */




class record {
    string empId;
    string name;
    string address;
    string title;
    string baseSalary;
    string phoneNum;
    
public:
    void setId(string emp_id);
    
    string getId();
    
    void setName(string emp_name);
    
    string getName();
    
    void setAddress(string emp_address);
    
    string getAddress();
    
    void setTitle(string emp_title);
    
    string getTitle();
    
    void setSalary(string emp_salary);
    
    string getSalary();
    
    void display();
};

#endif
