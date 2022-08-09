#include<iostream>
#include <conio.h>
#include <fstream>

using namespace std;

class contact {
     char fName[50], lName[50], address[100],email[50];
     long long phNo;

     //public function to take input form user end
 public:
    void createContact()
    {
        cout<<"First Name: ";
        cin>>fName;

        cout<<"Last Name: ";
        cin>>lName;

        cout<<"Phone Number: ";
        cin>>phNo;

        cout<<"Address: ";
        cin>>address;

        cout<<"E-Mail address: ";
        cin>>email;
    }

    void showContact()
    {
        cout<<"Name : "<<fName<<" "<<lName<<endl;
        cout<<"Phone : "<<phNo<<endl;
        cout<<"Living Address : "<<address<<endl;
        cout<<"E-Mail : "<<email<<endl;
    }

    void writeOnFile()
    {
        char ch;
        ofstream f1;
        f1.open("CMS.dat", ios::binary | ios::app);

        do{
            createContact();
            f1.write(reinterpret_cast<char*>(this), sizeof(*this));
            cout<<"Do you have next data ? (y/n)";
            cin>>ch;
        }while(ch=='y');

        cout<<"Contact has been successfully Created...";
        f1.close();
    }

    void readFromFile()
    {
        ifstream f2;
        f2.open("CMS.dat", ios::binary);

        cout<<"\n========================================";
        cout<< "List of Contact";
        cout<<"\n========================================";

        while(!f2.eof()){
            if(f2.read(reinterpret_cast<char*>(this), sizeof(*this))){
                showContact();
                cout<<"\n========================================";
            }
        }
        f2.close();
    }

    void searchOnFile(){
        ifstream f3;
        long long phone;
        cout<< "Enter phone number : ";
        cin>>phone;
        f3.open("CMS.dat", ios::binary);

        while(!f3.eof()){
            if(f3.read(reinterpret_cast<char*>(this), sizeof(*this))){
                if(phone==phNo){
                    showContact();
                    return;
                }
            }
        }
        cout<<"\n\n No record Found....";
        f3.close;
    }
};

int main ()
{
    cout<<"Hello world";
}
