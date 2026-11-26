// Practical 10.1
// Use of Structure
// Last Updated On 26th November, 2026 At 16:47
#include <iostream>
#include <iomanip>
using namespace std;

struct Academic {
    short int sem;
    float per;
    char grade[3];
};
struct Contact {
    long long mobile;
    char email[40];
};
struct Student {
    char id[10];
    char name[20];
    char branch[20];
    Academic ac;
    Contact con;
};
void display_stu(Student *ptr){
    cout<<left<<setw(20)<<"Enrollment Number"<<" : "<<ptr->id<<endl;
    cout<<left<<setw(20)<<"Student Name"<<" : "<<ptr->name<<endl;
    cout<<left<<setw(20)<<"Branch"<<" : "<<ptr->branch<<endl;
    cout<<left<<setw(20)<<"Semester"<<" : "<<ptr->ac.sem<<endl;
    cout<<left<<setw(20)<<"Percentage"<<" : "<<ptr->ac.per<<endl;
    cout<<left<<setw(20)<<"Grade"<<" : "<<ptr->ac.grade<<endl;
    cout<<left<<setw(20)<<"Mobile Number"<<" : "<<ptr->con.mobile<<endl;
    cout<<left<<setw(20)<<"Email ID"<<" : "<<ptr->con.email<<endl;
    cout<<"\n\n--------------------------------------------\n\n";
}
void update_con(Student *ptr){
    cout<<"Enter New Mobile Number : ";
    cin>>ptr->con.mobile;
    cout<<"Enter New Email ID : ";
    cin.ignore();
    cin.getline(ptr->con.email, 40);
    cout<<"\n\nUpdated Successfully!\n\n";
}
void stu_academic(Student *ptr){
    cout<<"Semester : "<<ptr->ac.sem<<endl;
    cout<<"Percentage : "<<ptr->ac.per<<endl;
    cout<<"Grade: "<<ptr->ac.grade<<endl;
}
int main(){
    int n, i, choice, stu_num, index;
    cout<<"********************************************\n";
    cout<<"STUDENT RECORD MANAGEMENT SYSTEM\n";
    cout<<"********************************************\n\n";
    cout<<"Enter Number of Students : ";
    cin>>n;
    cout<<"--------------------------------------------\n\n";
    Student stu[n];
    for (i=0; i<n; i++){
        cout<<"Student "<<i+1<<endl<<endl;
        cout<<left<<setw(20)<<"Enrollment Number"<<" : ";
        cin.ignore();
        cin.getline(stu[i].id, 10);
        cout<<left<<setw(20)<<"Student Name"<<" : ";
        cin.getline(stu[i].name, 20);
        cout<<left<<setw(20)<<"Branch"<<" : ";
        cin.getline(stu[i].branch, 20);
        cout<<left<<setw(20)<<"Semester"<<" : ";
        cin>>stu[i].ac.sem;
        cout<<left<<setw(20)<<"Percentage"<<" : ";
        cin>>stu[i].ac.per;
        if (stu[i].ac.per >= 90) {
            stu[i].ac.grade[0] = 'O';
            stu[i].ac.grade[1] = '\0';
        }
        else if (stu[i].ac.per >= 80) {
            stu[i].ac.grade[0] = 'A';
            stu[i].ac.grade[1] = '+';
            stu[i].ac.grade[2] = '\0';
        }
        else if (stu[i].ac.per >= 70) {
            stu[i].ac.grade[0] = 'A';
            stu[i].ac.grade[1] = '\0';
        }
        else if (stu[i].ac.per >= 60) {
            stu[i].ac.grade[0] = 'B';
            stu[i].ac.grade[1] = '+';
            stu[i].ac.grade[2] = '\0';
        }
        else if (stu[i].ac.per >= 50) {
            stu[i].ac.grade[0] = 'B';
            stu[i].ac.grade[1] = '\0';
        }
        else if (stu[i].ac.per >= 40) {
            stu[i].ac.grade[0] = 'C';
            stu[i].ac.grade[1] = '\0';
        }
        else {
            stu[i].ac.grade[0] = 'F';
            stu[i].ac.grade[1] = '\0';
        }
        cout<<left<<setw(20)<<"Grade"<<" : "<<stu[i].ac.grade<<endl;
        cout<<left<<setw(20)<<"Mobile Number"<<" : ";
        cin>>stu[i].con.mobile;
        cout<<left<<setw(20)<<"Email ID"<<" : ";
        cin.ignore();
        cin.getline(stu[i].con.email, 40);
        cout<<"\n\n--------------------------------------------\n\n";
    }
    
    cout<<"--------------------------------------------\n\n";
    for (i=0; i<n; i++){
        cout<<"Student "<<i+1<<endl;
        display_stu(&stu[i]);
    }

    cout<<"Do you want to update contact information ?\n";
    cout<<"1. Yes\n";
    cout<<"2. No\n";
    m : cout<<"Enter your choice (1 or 2) : ";
    cin>>choice;
    if (choice == 1){
        cout<<"Enter the student number to update : ";
        cin>>stu_num;
        if (stu_num>=1 && stu_num<=n){
            update_con(&stu[stu_num-1]);
        }
        else {
        cout<<"\nInvalid Choice\n\n";
        goto m;
        }
    }
    
    n : cout<<"Enter Student Number to display academic information : ";
    cin>>index;
    if (index>=1 && index<=n){
        stu_academic(&stu[index-1]);
    }
    else if (index!=0){
        cout<<"Invalid Number!\n";
        goto n;
    }

    cout<<"\n\n--------------------------------------------\n\n";
    cout<<"\tPROGRAM EXECUTED SUCCESSFULLY";
    cout<<"\n\n--------------------------------------------\n\n";
}