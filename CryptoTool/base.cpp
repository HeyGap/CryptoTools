#include"base.h"

void base64manager()
{
    cout<<"Plz pick your mode:\n"
        <<"0···exit\n"
        <<"1···encode\n"
        <<"2···decode\n";
    int A;
    cin>>A;cin.get();
    system("cls");
    switch(A)
    {
        case 0:break;
        case 1:
        {
            char M[Size];
            cout<<"Plz pick your mode:\n"
                <<"1···Default\n"
                <<"2···DIY\n";
            cin>>A;cin.get();
            system("cls");
            if(A==1)
            {
                char base64_table[65]="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

                cout<<"Plz input your plaintext...(no more than "<<Size-1<<" bits)\n";
                cin.getline(M,Size);
                cout<<"Your plaintext is "<<M<<endl;
                
                base64encode(M,base64_table);
                system("pause");
                system("cls");
            }
            else if(A==2)
            {
                char base64_table[65];

                cout<<"Plz input your base64_table\n";
                cin.getline(base64_table,65);
                cout<<"Plz input your plaintext...(no more than "<<Size-1<<" bits)\n";
                cin.getline(M,Size);
                cout<<"Your plaintext is "<<M<<endl;

                base64encode(M,base64_table);
                system("pause");
                system("cls");
            }
            break;
        }
        case 2:
        {
            cout<<"Plz pick your mode:\n"
                <<"1···Default\n"
                <<"2···DIY\n";
            cin>>A;cin.get();
            system("cls");
            char C[Size];
            if(A==1)
            {
                char base64_table[65]="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

                cout<<"Plz input your ciphertext...(no more than "<<Size-1<<" bits)\n";
                cin.getline(C,Size);
                cout<<"Your ciphertext is "<<C<<endl;

                base64decode(C,base64_table);
                system("pause");
                system("cls");
            }
            else if(A==2)
            {
                char base64_table[65];

                cout<<"Plz input your base64_table\n";
                cin.getline(base64_table,65);
                cout<<"Plz input your ciphertext...(no more than "<<Size-1<<" bits)\n";
                cin.getline(C,Size);
                cout<<"Your ciphertext is "<<C<<endl;

                base64decode(C,base64_table);
                system("pause");
                system("cls");
            }
            else
            {
                cout<<"Invalid Input!Plz try again...\n";
                system("pause");
                system("cls");
            }
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

void base64encode(char* M,const char* base64_table)
{
    int len,NoB,rmd;
    int countc=0;
    int countm=0;
    len=strlen(M);//length of M
    NoB=len/3;//number of block(sizeof(char)*3=3bytes=3*8bits=24bits)
    rmd=len%3;//reminder of M
    char* C=new char[len*8/6+4];

    if(rmd==0)
    {
        for(int i=0;i<NoB;i++)
        {
            C[countc]=base64_table[M[countm]>>2];//要前n位，就是右移len-n位
            C[countc+1]=base64_table[((M[countm] & 3)<<4) | (M[countm+1]>>4)];//要后n位，就是“与'2^n-1'按位和” ; 按位合并两个二进制数是“与”操作
            C[countc+2]=base64_table[((M[countm+1] & 15)<<2) | (M[countm+2>>6])];
            C[countc+3]=base64_table[M[countm+2] & 63];
            countc+=4;
            countm+=3;
        }
    }
    else if(rmd==1)
    {
        for(int i=0;i<NoB-1;i++)
        {
            C[countc]=base64_table[M[countm]>>2];
            C[countc+1]=base64_table[((M[countm] & 3)<<4) | (M[countm+1]>>4)];
            C[countc+2]=base64_table[((M[countm+1] & 15)<<2) | (M[countm+2>>6])];
            C[countc+3]=base64_table[M[countm+2] & 63];
            countc+=4;
            countm+=3;
        }
        C[countc]=base64_table[M[countm]>>2];
        C[countc+1]=base64_table[((M[countm] & 3)<<4)];
        C[countc+2]='=';
        C[countc+3]='=';
    }
    else
    {
        for(int i=0;i<NoB-1;i++)
        {
            C[countc]=base64_table[M[countm]>>2];
            C[countc+1]=base64_table[((M[countm] & 3)<<4) | (M[countm+1]>>4)];
            C[countc+2]=base64_table[((M[countm+1] & 15)<<2) | (M[countm+2>>6])];
            C[countc+3]=base64_table[M[countm+2] & 63];
            countc+=4;
            countm+=3;
        }
        C[countc]=base64_table[M[countm]>>2];
        C[countc+1]=base64_table[((M[countm] & 3)<<4) | (M[countm+1]>>4)];
        C[countc+2]=base64_table[((M[countm+1] & 15)<<2)];
        C[countc+3]='=';
    }
    cout<<"Your ciphertext is "<<C<<endl;
}

void base64decode(char* C,const char* base64_table)
{
    int len,NoB;
    int countc=0;
    int countm=0;
    char* M=new char[Size];
    len=strlen(C);
    NoB=len/4;
    if(C[len-2]=='=')
    {
        C[len-2]=0;
        C[len-1]=0;
    }
    else
    {
        if(C[len-1]=='=')
        {
            C[len-1]=0;
        }
    }
    for(int i=0;i<NoB;i++)
    {
        int tmp[4];
        for(int i=0;i<64;i++)
        { 
            if(C[countc]==base64_table[i])
            {
                tmp[0]=i;
                break;
            }
        }
        for(int i=0;i<64;i++)
        {
            if(C[countc+1]==base64_table[i])
            {
                tmp[1]=i;
                break;
            }
        }
        for(int i=0;i<64;i++)
        {
            if(C[countc+2]==base64_table[i])
            {
                tmp[2]=i;
                break;
            }
        }
        for(int i=0;i<64;i++)
        {
            if(C[countc+3]==base64_table[i])
            {
                tmp[3]=i;
                break;
            }
        }
        M[countm]=(tmp[0]<<2)|(tmp[1]>>4);
        M[countm+1]=((tmp[1]&15)<<4)|(tmp[2]>>2);
        M[countm+2]=((tmp[2]&3)<<6)|tmp[3];
        countc+=4;
        countm+=3;
    }
    M[countm]=0;
    cout<<"Your plaintext is "<<M<<endl;
}

