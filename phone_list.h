#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;
void Phone_list()
{
    string firstname, lastname, gender, address, contact, email;
    ifstream ifs("Phone_Record.txt");
    if (!ifs.is_open())
    {
        cout << "file is not open " << endl;
    }
    else
    {

        cout << "\n\t\t\t!!!!!!!!!!!!!! List Phone Record !!!!!!!!!!!!!\n";
        cout << "\n\tFull Name \t\t";
        cout << "Gender \t\t";
        cout << "Address\t\t";
        cout << "Contact No\t\t";
        cout << "Email\t\t" << endl;
        cout << "=================================================================================================================";

        ifs >> firstname;
        ifs >> lastname;
        ifs >> gender;
        ifs >> address;
        ifs >> contact;
        ifs >> email;
        while (!ifs.eof())
        {
            if ( address.length() < 10 && (firstname.length() > 5 && lastname.length() > 5))
            {
                cout << "\n\t" << firstname << " " << lastname << "\t";
                cout << gender << "\t\t";
                cout << address << "\t\t";
                cout << contact << "\t\t";
                cout << email << "\t\t" << endl;
            }
            else if( address.length() < 10 && (firstname.length() < 6 && lastname.length() < 6)){

                cout << "\n\t" << firstname << " " << lastname << "\t\t";
                cout << gender << "\t\t";
                if (firstname.length()<5&&lastname.length()<5)
                {
                cout << address << "\t\t";
                }
                else{
                cout << address << "\t";
                }
                cout << contact << "\t\t";
                cout << email << "\t\t" << endl;
            }
            else if( address.length() > 9 && (firstname.length() < 6 && lastname.length() < 6)){


                cout << "\n\t" << firstname << " " << lastname << "\t\t";
                cout << gender << "\t\t";
                cout << address << "\t";
                cout << contact << "\t\t";
                cout << email << "\t\t" << endl;
            }
            else
            {
                cout << "\n\t" << firstname << " " << lastname << "\t\t";
                cout << gender << "\t\t";
                cout << address << "\t\t";
                cout << contact << "\t\t";
                cout << email << "\t\t" << endl;
            }
            ifs >> firstname;
            ifs >> lastname;
            ifs >> gender;
            ifs >> address;
            ifs >> contact;
            ifs >> email;
        }
    }
    cout << "\n\n\n\n\n";
}


