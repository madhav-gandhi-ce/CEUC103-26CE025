// Practical 11.3
// File Handling
// Last Updated On 26th November, 2026 At 22:14

#include <iostream>
#include <fstream>
using namespace std;

int main(){
    char enrollment[20],name[50],branch[20],grade[5];
    char line[200];
    int n,i,semester;
    float percentage;

    cout<<"********************************************"<<endl;
    cout<<"STUDENT RECORD MANAGEMENT SYSTEM"<<endl;
    cout<<"********************************************"<<endl;

    // Part A - Create and Write Student Records
    ofstream fout("StudentRecords.txt");
    if(!fout){
        cout<<"Error: Unable to create StudentRecords.txt";
        return 0;
    }

    cout<<"StudentRecords.txt Created Successfully"<<endl;
    cout<<"--------------------------------------------"<<endl;

    cout<<"Enter Number of Students : ";
    cin>>n;
    cin.ignore();

    for(i=0;i<n;i++){
        cout<<"Student "<<i+1<<endl;

        cout<<"Enrollment Number : ";
        cin.getline(enrollment,20);

        cout<<"Student Name : ";
        cin.getline(name,50);

        cout<<"Branch : ";
        cin.getline(branch,20);

        cout<<"Semester : ";
        cin>>semester;

        cout<<"Percentage : ";
        cin>>percentage;
        cin.ignore();

        cout<<"Grade : ";
        cin.getline(grade,5);

        fout<<enrollment<<endl;
        fout<<name<<endl;
        fout<<branch<<endl;
        fout<<semester<<endl;
        fout<<percentage<<endl;
        fout<<grade<<endl;

        cout<<"--------------------------------------------"<<endl;
    }
    fout.close();

    cout<<"Student Records Stored Successfully"<<endl;
    cout<<"--------------------------------------------"<<endl;

    // Part B - Read and Display Student Records
    ifstream fin("StudentRecords.txt");

    if(!fin){
        cout<<"Error: Unable to open StudentRecords.txt for reading.";
        return 0;
    }
    cout<<"Reading StudentRecords.txt"<<endl;

    cout.setf(ios::fixed);
    cout.precision(2);

    while(!fin.eof()){
        fin.getline(enrollment,20);
        if(fin){
            fin.getline(name,50);
            fin.getline(branch,20);
            fin>>semester;
            fin>>percentage;
            fin.ignore();
            fin.getline(grade,5);

            if(fin){
                cout<<"Enrollment : "<<enrollment<<endl;
                cout<<"Name : "<<name<<endl;
                cout<<"Branch : "<<branch<<endl;
                cout<<"Semester : "<<semester<<endl;
                cout<<"Percentage : "<<percentage<<endl;
                cout<<"Grade : "<<grade<<endl;
                cout<<"--------------------------------------------"<<endl;
            }
        }
    }
    fin.close();

    cout<<"End of File Reached Successfully"<<endl;
    cout<<"--------------------------------------------"<<endl;

    // Part C - Backup Student Records
    cout<<"Creating BackupStudentRecords.txt"<<endl;

    ifstream source("StudentRecords.txt");
    if(!source){
        cout<<"Error: Unable to open StudentRecords.txt for backup.";
        return 0;
    }
    ofstream destination("BackupStudentRecords.txt");

    if(!destination){
        cout<<"Error: Unable to create BackupStudentRecords.txt.";
        return 0;
    }
    while(source.getline(line,200)){
        destination<<line<<endl;
    }
    if(!destination){
        cout<<"Error: Unable to write backup file.";
        return 0;
    }
    source.close();
    destination.close();

    cout<<"Backup Completed Successfully"<<endl;
    cout<<"--------------------------------------------"<<endl;

    cout<<"Program Executed Successfully"<<endl;
    cout<<"--------------------------------------------"<<endl;
}
