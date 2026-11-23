// Practical 8.3
// Using Recursions
// Last Updated on 23rd November, 2026 at 14:30


#include <iostream>
using namespace std;
int fact=1, i=0, n, n_1, sum;
int fact_iterative(int n_1){
    for (; n_1!=0; n_1--){
        fact = fact*n_1;
    }
    return fact;
}

int fact_recursion(int n_1){
    if (n_1==0 || n_1==1){
        return 1;
    }
    return n_1*fact_recursion(n_1-1);
}

int fibo_rec(int n){
    if(n<=1){
        return n;
    }
    else {
        return fibo_rec(n-1) + fibo_rec(n-2);
    }
}

int fibo_iter(int c){
    int next, a=0,b=1;
    for(i=0;i<c;i++)
    {
        cout<<a<<" ";
        next = a+b;
        a = b;
        b = next;
    }
}
int main(){
    // Part A
    cout<<"Part A - Factorial\n\n";
    cout<<"Enter a number : ";
    cin>>n_1;
    cout<<"Factorial of "<<n_1<<" through iterative approach is : "<<fact_iterative(n_1)<<endl;
    cout<<"Factorial of "<<n_1<<" through recursion approach is : "<<fact_recursion(n_1);

    // Part B
    cout<<"\n\nPart B - Fibonacci Series\n\n";
    cout<<"Enter a number : ";
    cin>>n;
    cout<<"Fibonacci series through recursions : ";
    for (i=0; i<n; i++){
        cout<<fibo_rec(i)<<" ";
    }
    cout<<endl;
    cout<<"Fibonacci series through iterations : ";
    fibo_iter(n);
}

