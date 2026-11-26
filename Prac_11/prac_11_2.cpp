#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    char line[200];
    int i;
    // Part A - Create and Write File
    ofstream fout("Document.txt");
    if(!fout){
        cout<<"Error in creating file.";
        return 0;
    }

    cout<<"Enter 3 lines:"<<endl;
    for(i=0;i<3;i++){
        cin.getline(line,200);
        fout<<line<<endl;
    }

    fout.close();

    cout<<"File created and data written successfully."<<endl;

    // Part B - Read File and Detect EOF
    ifstream fin("Document.txt");

    if(!fin){
        cout<<"Error in opening file.";
        return 0;
    }

    cout<<"\nContents of Document.txt:"<<endl;
    while(!fin.eof()){
        fin.getline(line,200);
        if(fin){
            cout<<line<<endl;
        }
    }
    if(fin.eof()){
        cout<<"End of file reached."<<endl;
    }
    fin.close();

    // Part C - Create Backup File
    ifstream source("Document.txt");
    ofstream destination("BackupDocument.txt");

    if(!source||!destination){
        cout<<"Error in opening files.";
        return 0;
    }

    while(!source.eof()){
        source.getline(line,200);
        if(source){
            destination<<line<<endl;
        }
    }
    source.close();
    destination.close();

    ifstream check("BackupDocument.txt");

    if(check){
        cout<<"\nBackup file created successfully."<<endl;
    }
    else{
        cout<<"Error in creating backup file.";
    }
    check.close();

    // Part D - File Pointer Operations
    ifstream file("Document.txt");
    if(!file){
        cout<<"Error in opening file.";
        return 0;
    }
    cout<<"\nCurrent File Position:"<<file.tellg()<<endl;

    file.seekg(0,ios::beg);

    file.getline(line,200);
    file.getline(line,200);

    cout<<"Data after repositioning:"<<endl;
    cout<<line<<endl;

    file.clear();
    file.seekg(0,ios::beg);

    cout<<"\nComplete Contents of File:"<<endl;

    while(!file.eof()){
        file.getline(line,200);
        if(file){
            cout<<line<<endl;
        }
    }
    file.close();
}