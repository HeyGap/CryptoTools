#include"ManagerCode.h"
#include"base.h"

void CodeManager()
{
    int A;
    cout<<"Plz pick yoru Encode/Decode Tools:\n"
        <<"0···exit\n"
        <<"1···Base64\n"
        <<"2···\n";
    cin>>A;cin.get();
    system("cls");
    switch(A)
    {
        case 0:break;
        case 1:
        {
            base64manager();
            break;
        }
        default:
        {
            cout<<"Invalid Input!Plz try again...\n";
            system("pause");
            system("cls");
            break;
        }
    }
}