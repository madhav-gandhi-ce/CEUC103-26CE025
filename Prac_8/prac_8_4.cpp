#include <iostream>
using namespace std;
int i=0, sum_digit=0;
void till_n(int n){
    if (n==0){
        return ;
    }
    till_n(n-1);
    cout<<n<<" ";
}
void from_n(int n){
    if (n==0){
        return ;
    }
    cout<<n<<" ";
    from_n(n-1);
}

void rev_num(int n_1){
    if (n_1==0){
        return;
    }
    cout<<n_1%10;
    sum_digit += n_1%10;
    rev_num(n_1/10);
}
void binary(int n_2){
    if (n_2==0){
        return;
    }
    binary(n_2/2);
    cout<<n_2%2;
}
int main(){
    // Part A - Recursive Transversal
    cout<<"\n----------Part A - Recursive Transversal----------\n\n";
    int n;
    cout<<"Enter a number : ";
    cin>>n;
    cout<<"1 to "<<n<<" are : ";
    till_n(n);
    cout<<endl;
    cout<<n<<" to 1 are : ";
    from_n(n);
    
    // Part B - Recursive Number Processing
    cout<<"\n\n----------Part B - Recursive Number Processing----------\n\n";
    int n_1;
    cout<<"Enter a number : ";
    cin>>n_1;
    cout<<"The reverse of "<<n_1<<" is : ";
    rev_num(n_1);
    cout<<"\nThe sum of digits of "<<n_1<<" is : "<<sum_digit;
    
    // Part C - Recursive Number Conversion
    cout<<"\n\n----------Part C - Recursive Number Conversion----------\n\n";
    int n_2;
    cout<<"Enter a number : ";
    cin>>n_2;
    binary(n_2); 
}