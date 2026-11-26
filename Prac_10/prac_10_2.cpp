// Practical 10.2
// Memory Allocation Of Structure and Union
// Last Updated On 26th November, 2026 At 19:01

#include <iostream>
#include <iomanip>
using namespace std;
struct Product{
    int id;
    char name[20];
    float price;
};
struct Data_A{
    char code;
    double price;
    int quantiy;
    char category;
};
struct Data_B{
    double price;
    int quantiy;
    char code;
    char category;
};
union Shared{
    int num;
    float decimal;
    char ch;
};
int main(){
    Product p;
    cout<<"\n********************************************\n";
    cout<<"COMPOSITE DATA REPRESENTATION ANALYZER\n";
    cout<<"********************************************\n\n";

    cout<<"Composite Data Type - Product\n\n";
    cout<<"Size of Product ID : "<<sizeof(p.id)<<" Bytes\n";
    cout<<"Size of Product Name : "<<sizeof(p.name)<<" Bytes\n";
    cout<<"Size of Product Price : "<<sizeof(p.price)<<" Bytes\n";

    cout<<"Total Size of Structure : "<<sizeof(Product)<<" Bytes\n";

    cout<<"\n--------------------------------------------\n\n";
    
    // Part B
    cout<<"Composite Data Type A\n";
    cout<<"Size : "<<sizeof(Data_A)<<" Bytes\n";
    cout<<"\n--------------------------------------------\n\n";

    cout<<"Composite Data Type B\n";
    cout<<"Size : "<<sizeof(Data_B)<<" Bytes\n";
    cout<<"\n--------------------------------------------\n\n";
    
    cout<<"Padding and Alignment Observed\n";
    cout<<"Different member arrangements affect memory size\n";
    cout<<"\n--------------------------------------------\n\n";
    
    // Part C
    Shared data;
    cout<<"Shared Memory Representation\n\n";
    data.num=120;
    cout<<"Integer Value : "<<data.num<<endl;
    data.decimal=12.0;
    cout<<"Floating Value : "<<fixed<<setprecision(2)<<data.decimal<<endl;
    data.ch = 'x';
    cout<<"Character Value : "<<data.ch<<endl;
    
    cout<<"\nAfter Updating Floating Value\n";
    cout<<"Integer Value Changed"<<endl;
    cout<<"Character Value Changed"<<endl;
    
    cout<<"\nAfter updating union members\n";
    cout<<"Previous member data gets overwritten.\n";
    cout<<"\n--------------------------------------------\n\n";
    
    // Part D
    cout<<"Trade-off Analysis\n\n";
    
    cout<<"Structure\n";
    cout<<"Separate Memory for Every Member\n";
    cout<<"Suitable for Storing Complete Records\n";
    cout<<"\n--------------------------------------------\n\n";
    cout<<"Union\n";
    cout<<"Shared Memory for All Members\n";
    cout<<"Suitable for Memory-efficient Applications\n";
    cout<<"\n--------------------------------------------\n\n";
    cout<<"Program Executed Successfully\n";
    cout<<"\n--------------------------------------------\n\n";
}