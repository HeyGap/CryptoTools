#include"ManagerCrypto.h"

void CryptoManager()
{
    int A;
    cout<<"Plz pick yoru Encrypt/Decrypt Tools:\n"
        <<"0···exit\n"
        <<"1···Stream\n"
        <<"2···\n";
    cin>>A;
    switch(A)
    {
        case 0:break;
        default:
        {
            cout<<"Invalid Input!Plz try again...\n";
            system("pause");
            system("cls");
            break;
        }
    }
}