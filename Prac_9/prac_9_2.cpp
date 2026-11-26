#include <iostream>
#include <iomanip>
using namespace std;
void display(char (*id)[10], char (*name)[20], char (*branch)[20], int *sem, float *per, char (*grade)[3], int n){
    cout<<"\n\nStudent Records using Address-based Access\n";
    cout<<"--------------------------------------------\n";
    for (int i=0; i<n; i++){
        cout<<"Address : "<<(id+i)<<endl<<endl;
        cout<<left<<setw(10)<<*(id+i);
        cout<<left<<setw(10)<<*(name+i);
        cout<<left<<setw(10)<<*(branch+i);
        cout<<left<<setw(2)<<*(sem+i);
        cout<<left<<setw(6)<<*(per+i);
        cout<<left<<setw(4)<<*(grade+i);
        cout<<"\n\n--------------------------------------------\n\n";
    }
}
int main(){
    cout<<"********************************************\n";
    cout<<"\tSTUDENT RECORD MANAGEMENT SYSTEM\n";
    cout<<"********************************************\n\n";

    int n, i;
    float total=0, high, low;
    cout<<"Enter Number Of Students : ";
    cin>>n;
    char (*id)[10] = new char[n][10];
    char (*name)[20] = new char[n][20];
    char (*branch)[20] = new char[n][20];
    int *sem = new int[n];
    float *per = new float[n];
    char (*grade)[3] = new char[n][3];

    cout<<"\nDynamic Memory Allocated Successfully\n\n";
    cout<<"--------------------------------------------\n\n";
    cout<<"Enter Students Details : \n\n";
    for (i=0; i<n; i++){
        cout<<"Student "<<i+1<<endl<<endl;
        cout<<left<<setw(26)<<"Enter Enrollment Number"<<" : ";
        cin.ignore();
        cin.getline(id[i], 10);
        cout<<left<<setw(26)<<"Enter Student Name"<<" : ";
        cin.getline(name[i], 20);
        cout<<left<<setw(26)<<"Enter Branch"<<" : ";
        cin.getline(branch[i], 20);
        cout<<left<<setw(26)<<"Enter Semester"<<" : ";
        cin>>sem[i];
        cout<<left<<setw(26)<<"Enter Percentage"<<" : ";
        cin>>per[i];
        total += per[i];

        if (per[i] >= 90){
            grade[i][0] = 'O';
            grade[i][1] = '\0';
        }
        else if (per[i] >= 80){
            grade[i][0] = 'A';
            grade[i][1] = '+';
            grade[i][2] = '\0';
        }
        else if (per[i] >= 70){
            grade[i][0] = 'A';
            grade[i][1] = '\0';
        }
        else if (per[i] >= 60){
            grade[i][0] = 'B';
            grade[i][1] = '+';
            grade[i][2] = '\0';
        }
        else if (per[i] >= 50){
            grade[i][0] = 'B';
            grade[i][1] = '\0';
        }
        else if (per[i] >= 40){
            grade[i][0] = 'C';
            grade[i][1] = '\0';
        }
        else{
            grade[i][0] = 'F';
            grade[i][1] = '\0';
        }
        cout<<setw(26)<<"Grade"<<" : "<<grade[i]<<endl;
    }
    
    cout<<"\n--------------------------------------------\n";
    
    display(id, name, branch, sem, per, grade, n);
    cout<<"Academic Summary\n\n";
    cout<<"Class Average Percentage : "<<total/n;
    high = per[0];
    low = per[0];
    for (i=0; i<n; i++){
        if (high<per[i]){
            high = per[i];
        }
        if (low>per[i]){
            low = per[i];
        }
    }
    cout<<"\nHighest Percentage : "<<high<<" % \n";
    cout<<"Lowest Percentage : "<<low<<" % \n\n";
    cout<<"--------------------------------------------\n\n";
    delete[] id;
    delete[] name;
    delete[] branch;
    delete[] sem;
    delete[] per;
    delete[] grade;
    cout<<"Dynamic Memory Released Successfully\n";
    id = nullptr;
    name = nullptr;
    branch = nullptr;
    sem = nullptr;
    per = nullptr;
    grade = nullptr;
    cout<<"\nAddress Variable Reset Successfully\n";
    cout<<"\n--------------------------------------------\n";
    cout<<"Program Executed Successfully\n";
    cout<<"--------------------------------------------\n\n";
}