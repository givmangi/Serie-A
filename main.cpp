#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#define DIM 5
using namespace std;

struct squadra{
    string nome;
    int punti;
    string capocannoniere_nome;
    int capocannoniere_gol;
}squadre[DIM],app;

void input()
{
    ofstream file("serie_a.dat",ios::out|ios::binary);
    if(!file)
        cout<<"ERRORE NELL'APERTURA DEL FILE";
    else
    {
        string temp;
        for(int i=0;i<DIM;i++)
        {
            cout<<endl<<"\tInserimento "<<(i+1)<<" squadra:"<<endl;
            cout<<endl<<"Nome squadra:";
            fflush(stdin);
            getline(cin,temp);
            squadre[i].nome=temp;
            cout<<"Punti squadra:";
            cin>>squadre[i].punti;
            cout<<"Capocannoniere squadra:";
            fflush(stdin);
            getline(cin,temp);
            squadre[i].capocannoniere_nome=temp;
            cout<<"Gol capocannoniere:";
            cin>>squadre[i].capocannoniere_gol;
            file.write((char *)&squadre[i],sizeof(squadre[i]));
        }
    }
}

void classifica()
{
    ifstream file("serie_a.dat",ios::in|ios::binary);
    if(!file)
        cout<<"ERRORE NELL'APERTURA DEL FILE";
    else
    {
        for(int i=0;i<DIM;i++)
            file.read((char *)&squadre[i],sizeof(squadre[i]));
        for(int i=0;i<DIM;i++)
        {
            for(int j=i+1;j<DIM;j++)
                if(squadre[i].punti<squadre[j].punti)
                {
                    app=squadre[i];
                    squadre[i]=squadre[j];
                    squadre[j]=app;
                }
        }
        cout<<endl<<endl<<"\tCLASSIFICA SERIE A"<<endl;
        for(int i=0;i<DIM;i++)
            cout<<endl<<(i+1)<<"\t"<<squadre[i].nome<<"\t\t"<<squadre[i].punti;
    }
}

void marcatori()
{
    ifstream file("serie_a.dat",ios::in|ios::binary);
    if(!file)
        cout<<"ERRORE NELL'APERTURA DEL FILE";
    else
    {
        for(int i=0;i<DIM;i++)
            file.read((char *)&squadre[i],sizeof(squadre[i]));
        for(int i=0;i<DIM;i++)
        {
            for(int j=i+1;j<DIM;j++)
                if(squadre[i].capocannoniere_gol<squadre[j].capocannoniere_gol)
                {
                    app=squadre[i];
                    squadre[i]=squadre[j];
                    squadre[j]=app;
                }
        }
        cout<<endl<<endl<<"\tCLASSIFICA MARCATORI"<<endl;
        for(int i=0;i<DIM;i++)
            cout<<endl<<(i+1)<<"\t"<<squadre[i].capocannoniere_nome<<"\t"<<squadre[i].capocannoniere_gol<<"\t\t"<<squadre[i].nome;
    }
}

int main()
{
    int op;
    do
    {
        do
        {
            cout<<endl<<"\tINSERIRE OPERAZIONE DA ESEGUIRE:"<<endl;
            cout<<"1)Inserimento dati"<<endl;
            cout<<"2)Stampa classifica"<<endl;
            cout<<"3)Stampa classifica marcatori"<<endl;
            cout<<"4)Uscita"<<endl;
            cin>>op;
            system("cls");
        }
        while(op<1||op>4);
        switch(op)
        {
            case 1:input();
                   break;
            case 2:classifica();
                   break;
            case 3:marcatori();
                   break;
        }
    }
    while(op!=4);
    return 0;
}
