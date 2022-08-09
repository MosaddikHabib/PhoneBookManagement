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
        f3.close();
    }

    void deleteFromFile()
    {
         long long phone;
         int flag = 0;
         ofstream f4;
         ifstream f5;

         f5.open("CMS.dat", ios::binary);
         f4.open("temp.dat", ios::binary);

         cout<<"Enter phone number to delete: ";
         cin>>phone;

         while(!f5.eof()){
            if(f5.read(reinterpret_cast<char*>(this), sizeof(*this))){
                if(phNo != phone){
                    f4.write(reinterpret_cast<char*>(this), sizeof(*this));
                }
                else flag =1;
            }
         }
         f5.close();
         f4.close();
         remove("CMS.dat");
         rename("temp.dat", "CMS.dat");

         flag==1 ? cout<<"\t contact deleted..." : cout<< "\t contact Not found...";

    }

    void editContact()
    {
        long long phone;
        fstream f6;

        cout<< "Edit contact :";
        cout<<endl<< "=================================";
        cout<<endl<<"Enter the phone number to be edit: ";
        cin>>phone;

        f6.open("CMS.dat", ios::binary | ios::out | ios::in);

        while(!f6.eof()){
            if(f6.read(reinterpret_cast<char*>(this), sizeof(*this))){
                if(phone == phNo)
                {
                    cout<<"Enter new record"<<endl;
                    createContact();

                    int pos = -1*sizeof(*this);
                    f6.seekp(pos, ios::cur);
                    f6.write(reinterpret_cast<char*>(this), sizeof(*this));
                    cout<<endl<<endl<<"\tContact successfully updated...";

                    return;
                }
            }
        }
        cout<<endl<<endl<<"No record found.";
    }


};

int main ()
{
    system("cls");
    system("color 3F"); //here color XY means , X=bg color and Y = text color

    cout<<endl<<endl<<endl<<endl<<endl<<endl<<"\t\t\t\t\t Welcome to my Handmade phone-book management system"<<endl<<endl<<endl<<endl<<endl<<endl;
    getch();

    while(1){
        contact c1;
        int choice;

        system("cls");
        system("color 4F");

        cout<<endl<<"phone-book management system";
        cout<<endl<<endl<<"Main Menu";
        cout<<endl<<"================================";
        cout<<endl<<"[1] Add a new phone number";
        cout<<endl<<"[2] List all contacts";
        cout<<endl<<"[3] Search for contact";
        cout<<endl<<"[4] Delete a contact";
        cout<<endl<<"[5] Edit a contact";
        cout<<endl<<"[0] Exit";
        cout<<endl<<"================================";

        cout<<endl<<"Enter your choice: ";
        cin>>choice;

        switch(choice){
        case 1:
            system("cls");
            c1.createContact();
            break;

        case 2:
            system("cls");
            c1.readFromFile();
            break;

        case 3:
            system("cls");
            c1.searchOnFile();
            break;

        case 4:
            system("cls");
            c1.deleteFromFile();
            break;

        case 5:
            system("cls");
            c1.editContact();
            break;

        case 0:
            system("cls");
            cout<<endl<<endl<<endl<<"Thank You user"<<endl<<endl<<endl;
            exit(0);
            break;

        default:
            continue;

        }

        int opt;
        cout<<endl<<endl<<"::Enter the choice"<<endl;
        cout<<"[1] Main menu";
        cout<<"[0] Exit";
        cin>>opt;

        switch(opt)
        {
            case 0:
            system("cls");
            cout<<endl<<endl<<endl<<"Thank You user"<<endl<<endl<<endl;
            exit(0);
            break;

        default:
            continue;
        }
    }

    return 0;
}
