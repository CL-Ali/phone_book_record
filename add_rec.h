#include<iostream>
#include<string.h>
#include<string>
#include<fstream>
using namespace std;
bool Check_name(string firstname , string lastname){
    bool alreadytaken=false;
ifstream ifs("Phone_Record.txt");
string tfirstname ; string tlastname;
char tgender;string taddress;string tcontact;string temail;
if (!ifs.is_open())
{
    cout<<"file is not open "<<endl;
}
        ifs>>tfirstname;
        ifs>>tlastname;
        ifs>>tgender;
        ifs>>taddress;
        ifs>>tcontact;
        ifs>>temail;
    while (!ifs.eof())
    {
        if (firstname== tfirstname && lastname == tlastname)
        {
            alreadytaken = true;
            cout<<"\n\n\t Invalid :(\t This phone number is already taken :)"<<endl;
        }
        ifs>>tfirstname;
        ifs>>tlastname;
        ifs>>tgender;
        ifs>>taddress;
        ifs>>tcontact;
        ifs>>temail;
        
    }
    return alreadytaken;
}
void Add_rec_file(string firstname,string lastname,char gender,string address,string contact,string email){
   ofstream ofs("Phone_Record.txt",ios::app) ;
   ofs<<firstname<<endl;
   ofs<<lastname<<endl;
   ofs<<gender<<endl;
   ofs<<address<<endl;
   ofs<<contact<<endl;
   ofs<<email<<endl;
    cout <<"\n\n\t\t\t.... Information Record Successful ...";
}
   static char Contact_no[15], First_Name[20], Last_Name[20], Email[30],  Gender;
    static string Address;
void Add_rec(){
    cout << "\n\n\t\t\t!!!!!!!!!!!!!! Add Phone Record !!!!!!!!!!!!!\n";
    int valid = 0;
A:
    cout << "\n\t\t\tFirst Name: ";
    cin >> First_Name;
    First_Name[0] = toupper(First_Name[0]);
    if (strlen(First_Name) > 20 || strlen(First_Name) < 2)
    {
        cout << "\n\n\t Invalid :( \t The max range for first name is 20 and min range is 2 :)\n\n";
        goto A;
    }
    else
    {
        for (int b = 0; b < strlen(First_Name); b++)
        {
            if (isalpha(First_Name[b]))
            {
                valid = 1;
            }
            else
            {
                valid = 0;
                break;
            }
        }
        if (!valid)
        {
            cout << "\n\n\t\t First name contain Invalid character :(  Enter again :)\n\n";
            goto A;
        }
    }

B:
    cout << "\n\t\t\tLast Name: ";
    cin >> Last_Name;
    Last_Name[0] = toupper(Last_Name[0]);
    if (strlen(Last_Name) > 20 || strlen(Last_Name) < 2)
    {
        cout << "\n\n\t Invalid :( \t The max range for last name is 20 and min range is 2 :)\n";
        goto B;
    }
    else
    {
        for (int b = 0; b < strlen(Last_Name); b++)
        {
            if (isalpha(Last_Name[b]))
            {
                valid = 1;
            }
            else
            {
                valid = 0;
                break;
            }
        }
        if (!valid)
        {
            cout << "\n\n\t\t Last name contain Invalid character :(  Enter again :)\n";
            goto B;
        }
    }

    if(Check_name(First_Name,Last_Name)==true){
        goto A;
    }
    do
    {
        cout << "\n\t\t\tGender[F/M]: ";
        cin >> Gender;
         if(islower(Gender))
        {
            Gender= toupper(Gender);
        }
        if ((toupper(Gender) == 'M' || toupper(Gender) == 'F')){
            valid = 1;
        }
        else
        {
            valid = 0;
        }
        if (!valid)
        {
            cout << "\n\n\t\t Gender contain Invalid character :(  Enter either F or M :)\n";
        }
    } while (!valid);
    do
    {
    C:
        cout << "\n\t\t\tAddress: ";
        cin >> Address;
        Address[0] = toupper(Address[0]);
        if ((int)Address.length() > 50 || (int)Address.length() < 4)
        {
            cout << "\n\n\t Invalid :( \t The max range for address is 20 and min range is 4 :)\n";
            goto C;
        }

    } while (!valid);

    do
    {
    D:
        cout << "\n\t\t\tContact no: ";
        cin >> Contact_no;
        if (strlen(Contact_no) < 10)
        {
            cout << "\n\n\t Sorry :( Invalid. Contact no. must contain 10 numbers. Enter again :)\n";
            goto D;
        }
        else
        {
            for (int b = 0; b < strlen(Contact_no); b++)
            {
                if (isdigit(Contact_no[b]) || Contact_no[0] == '+')
                {
                    valid = 1;
                }
                else
                {
                    valid = 0;
                    break;
                }
            }
            if (!valid)
            {
                cout<<"\n\t\t Contact no. contain Invalid character :(  Enter again :)\n";
                goto D;
            }
        }
    } while (!valid);

    do
    {
    E:
        cout << "\n\t\t\tEmail: ";
        cin >> Email;
        if (strlen(Email) > 30 || strlen(Email) < 8)
        {
            cout << "\n\n\t Invalid :( \t The max range for email is 30 and min range is 8 :)\n";
            goto E;
        }
        else
        {

            bool atrate, dot;
            for (int i = 0;
                 i < strlen(Email); i++)

            {
                if (Email[i] == '@')
                {
                    atrate = true;
                }
                else if (
                    Email[i] == '.')
                {
                    dot = true;
                }
            }
            if (atrate != true || dot != true)
            {
                valid = 0;
                if (!valid)
                {
                    cout << "\n \t\t Sorry  :( \t Please enter valid email :) \n"
                         << endl;
                    atrate = false;
                    dot = false;
                    goto E;
                }
            }
            else
            {
                valid = 1;
            }
        }
    } while (
        !valid);
        }
void Add_Phone_rec(){
    Add_rec();
        Add_rec_file(First_Name,Last_Name,Gender,Address,Contact_no,Email);

}
