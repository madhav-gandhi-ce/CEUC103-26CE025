// Practical 11.1
// Error Handling
// Last Updated On 26th November, 2026 At 21:24

#include <iostream>
#include <fstream>
using namespace std;
int global = 100;
int main(){
    int local = 200;
    cout<<"********************************************\n";
    cout<<"PROGRAM EXECUTION & ERROR HANDLING\n";
    cout<<"********************************************\n\n";

    cout<<"Compile-time and Run-time Memory\n";
    cout<<"Global Variable Value : "<<global<<endl;
    cout<<"Local Variable Value : "<<local<<endl;
    int *ptr = new int(300);
    cout<<"Dynamic Memory Value : "<<*ptr<<endl;
    delete ptr;
    ptr = nullptr;

    cout<<"\n--------------------------------------------\n";
    cout<<"Low-Level Error Demonstration\n";
    int num = 2147483647;
    num = num+1;
    cout<<"Arithmetic Overflow Observed\n";
    cout<<"--------------------------------------------\n\n";
    cout<<"Pointer Aliasing\n\n";
    int value = 50;
    int *ptr_1 = &value;
    int *ptr_2 = &value;
    cout<<"Original Value : "<<*ptr_1<<endl;
    *ptr_1 = 75;
    cout<<"Updated Value : "<<*ptr_2<<endl;
    cout<<"Both Address Variables Refer to the Same Memory Location\n"<<endl;
    cout<<"\n--------------------------------------------\n\n";
    
    // Memory Leak Demonstration
    cout<<"Memory Leak Demonstration\n";
    
    int *ptr_3 = new int(500);
    cout<<"Dynamic Memory Allocation\n";
    delete ptr_3;
    cout<<"Memory Released Successfully\n";
    cout<<"\n--------------------------------------------\n\n";

    // Part C
    int dividend, divisor;

    cout<<"Arithmetic Operation\n";
    cout<<"Enter Dividend : ";
    if (cin>>dividend){
        cout<<"Enter Divisor : ";

        if (cin>>divisor){
            if (divisor==0){
                cout<<"Error : Division by Zero is not Allowed." << endl;
            }
            else{
                cout<<"Result : "<<(float)dividend/divisor << endl;
            }
        }
        else{
            cout<<"Error : Invalid Numerical Input."<<endl;
        }
    }
    else{
        cout<<"Error : Invalid Numerical Input."<<endl;
    }

    cout<<"--------------------------------------------"<<endl;

    // File Operation
    cout<<"\nFile Operation"<<endl;

    ifstream file("missing_file.txt");

    if (!file){
        cout<<"Unable to Open File."<<endl;
    }
    else{
        cout<<"File Opened Successfully."<<endl;
        file.close();
    }
    cout<<"--------------------------------------------"<<endl;
    cout<<"\nPROGRAM EXECUTED SUCCESSFULLY"<<endl;
    cout<<"--------------------------------------------"<<endl;

}
