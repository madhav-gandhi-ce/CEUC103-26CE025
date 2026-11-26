#include <iostream>
using namespace std;
void stack_heap(){
    // Part A - Stack And Heap Memory
    int local_1=10;
    cout<<"----------Stack Memory----------\n\n";
    cout<<"Local Variable Value : "<<local_1<<endl;
    cout<<"Memory Address : "<<&local_1<<endl;
    int *heap = new int(20);
    cout<<"\n---------Dynamically Allocated Memory---------\n\n";
    cout<<"Allocated Value : "<<heap<<endl;
    cout<<"Memory Address : "<<&heap<<endl;
    delete heap;
}
void multi_ref(){
    // Part B - Multi-level Referencing
    int num=50;
    int *ptr_1 = &num;
    int **ptr_2 = &ptr_1;
    int ***ptr_3 = &ptr_2;
    cout<<"\n---------------------------------------------\n\n";
    cout<<"---------Multi-level Referencing---------\n\n";
    cout<<"Orginial Value : "<<num<<endl;
    cout<<"Single-level Address : "<<ptr_1<<endl;
    cout<<"Double-level Value : "<<ptr_2<<endl;
    cout<<"Triple-level Value : "<<ptr_3<<endl;
    cout<<"Value Accessed through Three Levels : "<<***ptr_3<<endl;
}
void memory_safety(){
    // Part C - Memory Safety
    cout<<"\n---------------------------------------------\n\n";
    cout<<"---------Memory Safety---------\n\n";
    int *ptr_1 = NULL;
    cout<<"Null Reference\n";
    if (ptr_1 == NULL){
        cout<<"Safe (Reference is NULL)\n";
    }
    // cout<<*ptr_1; --> We cannot derefernce it...if executed than causes undefined behaviour
    cout<<"\n---------------------------------------------\n\n";
    int *ptr_2 = new int;
    *ptr_2 = 100;
    delete ptr_2;
    // So now *ptr_2 is dangling pointer
    // So we cant execute cout<<*ptr_2 --> It may vause undefined behaviour...it is unsafe
    // Solution : after delete ptr_2...write ptr_2 = NULL --> so now the pointer no longer holds the address
    cout<<"Invalid Reference\n";
    cout<<"Memory Released Successfully\n";
    cout<<"Reference Invalid\n";
    cout<<"\n---------------------------------------------\n\n";
    int *ptr_3;
    // ptr_3 is uninitialized so we must never dereference it
    // So we cant execute cout<<*ptr_3 --> Unsafe
    cout<<"Uninitialized Address Variable\n";
    cout<<"Unsafe to Access\n";
    cout<<"\n---------------------------------------------\n\n";

}
int main(){
    cout<<"********************************************\n";
    cout<<"\tMEMORY ORGANIZATION ANALYZER\n";
    cout<<"********************************************\n\n";
    stack_heap();
    multi_ref();
    memory_safety();
}