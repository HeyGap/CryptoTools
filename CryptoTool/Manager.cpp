#include"Manager.h"

void manager()
{
    int A;
    cout<<"***************************************************\n"
        <<"*\t\t\t\t\t\t  *\n"
        <<"*\tWelcome to use Gap's CryptoTools Box~\t  *\n"
        <<"*\t\t\t\t\t\t  *\n"
        <<"***************************************************\n";
    system("pause");
    system("cls");
    //选择加解密或编解码
    while(1)
    {
        cout<<"Plz pick your tools:\n"
            <<"0···Exit\n"
            <<"1···Encode/Decode\n"
            <<"2···Encrypt/Decrypt\n";
        cin>>A;cin.get();
        system("cls");
        switch(A)
        {
            case 0:while(1){Exit();}
            case 1:
            {
                //选择编解码具体方式
                CodeManager();
                break;
            }
            case 2:
            {
                //选择加解密具体方式
                CryptoManager();
                break;
            }
            default:break;
        }
    }
}

void Exit()
{
    int A;
    cout<<"Do you really want to exit?\n"
        <<"1··· Yes\n"
        <<"2··· No\n";
    cin>>A;cin.get();
    switch(A)
    {
        case 1:
        {
            system("pause");
            exit(0);
        }
        case 2:
        {
            system("cls");
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

