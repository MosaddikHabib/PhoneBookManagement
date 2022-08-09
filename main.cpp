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
};

int main ()
{
    cout<<"Hello world";
}
