#include<iostream>
#include<string>
#include<cstring>
#include<fstream>
#include<conio.h>
#include<cstdlib>
using namespace std;
string tasks[100];
int total=0,ch;
char yes;


void display()
    {   
        cout<<"Your todo List :-"<<endl;
        for(int i = 0;i<total;i++)
            {
                cout<<i+1<<". "<<tasks[i]<<endl;
            } 
        cout<<endl; 
    };
void input()
    {
        do
        {
        cout<<"Enter Task "<<total+1<<" - ";
        getline(cin,tasks[total]);
        total++;
        cout<<"Would you like to Add more (Y/N) ";
        cin>>yes;
        cin.ignore();
        } while(yes=='y' || yes=='Y');
        system("pause");
        system("cls");
    };
void del()
    {
        int remove,swap;
        display();
        cout<<"Enter the task number you want to delete - ";
        cin>>remove;
        swap =total-remove;   
        for(int z=0;z<swap;z++)
        {
            tasks[remove-1]=tasks[remove];
            remove=remove+1;
        };
        tasks[total].erase();
        total=total-1;
        system("pause");
        system("cls");
    }; 

void mscreen()
{
    cout<<endl<<"1. Add New Task"<<endl;
    cout<<"2. Delete The Completed Tasks"<<endl;
    cout<<"3. Exit"<<endl<<"Enter Your Choice :- ";
    cin>>ch;
    cin.ignore();
    system("cls");
};   
int storetasks() 
{   
    ofstream fout;
    fout.open("list.dat",ios::out|ios::binary);
    for(int y=0;y<total;y++)
    fout.write((char*)&tasks[y],sizeof(tasks[y]));
    fout.close();
    return 0;
};
void viewtasks()
{   
    int x=0,cr;
    ifstream fin;
    fin.open("list.dat",ios::in|ios::binary);
    if(!fin)
    {
        cout<<"Your todo List :-"<<endl<<"No Todo List Found"<<endl;
        cout<<"Press 1 to create New Todo list :- ";
        cin>>cr;
        cin.ignore();
        system("cls");
        if(cr==1)
        {
            input();
            storetasks();
        }
        else
        {
            exit(1);
        }
        
    }
    else
    {
        fin.read((char*)&tasks[x],sizeof(tasks[x]));
        while(!fin.eof())
        {
            total=total+1;
            x=x+1;
            fin.read((char*)&tasks[x],sizeof(tasks[x]));
        }
    }
};


int main()
{   

    viewtasks();
    abcdef:
    display();
    mscreen();

    switch (ch)
    {
    case 1:
        input();
        storetasks();
        goto abcdef;
        
    
    case 2:
        del();
        storetasks();
        goto abcdef;
    
    case 3:
        exit(2);
    default:
        cout<<"Invalid Response"<<endl;
        system("pause");
        system("cls");
        goto abcdef;
    }
    
    return 0;
}