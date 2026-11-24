#include <iostream>
using namespace std;
int main(){
    // Part A - Address and Value
    cout<<"********************************************\n";
    cout<<"\tMEMORY ADDRESS EXPLORER\n";
    cout<<"********************************************\n\n";
    int age=10;
    float marks=89.6;
    char grade='A';
    cout<<"\n------------ Variable Information ------------\n\n";
    cout<<"Integer Value : "<<age<<endl;
    cout<<"Memory Address : "<<&age<<endl<<endl;
    cout<<"----------------------------------------------\n\n";
    cout<<"Character Value : "<<grade<<endl;
    cout<<"Memory Address : "<<&grade<<endl<<endl;
    cout<<"----------------------------------------------\n\n";
    cout<<"Floating Value : "<<marks<<endl;
    cout<<"Memory Address : "<<&marks<<endl<<endl;
    cout<<"----------------------------------------------\n\n";
    
    // Part B - Indirect Referencing
    cout<<"Indirect Referencing\n\n";
    int *ptr = &age;
    cout<<"Stored Value : "<<*ptr<<endl;
    *ptr = 20;
    cout<<"Modified Value : "<<age<<endl;
    
    // Part C - Sequential Data Collection
    cout<<"\n----------------------------------------------\n\n";
    cout<<"Sequential Data Collection\n\n";
    int arr[5]={1,2,3,4,5}, i;
    cout<<"1. Printing By Array Indexing : ";
    for(i=0; i<5; i++){
        cout<<arr[i]<<" ";
    }
    
    cout<<"\n2. Printing By Address : ";
    int *arr_ptr;
    arr_ptr = arr;
    for(i=0; i<5; i++){
        cout<<*(arr_ptr+i)<<" ";
    }
    cout<<"\n\n----------------------------------------------\n\n";
    cout<<"Observation\n";
    cout<<"Both approaches access the same memory locations.\n\n";
    cout<<"----------------------------------------------\n\n";
}