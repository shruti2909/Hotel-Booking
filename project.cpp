#include<iostream.h>
#include<conio.h>
#include<fstream.h>
#include<stdio.h>
class hotel
{
    int room_no;
    char name[30];
    char address[50];
    char phone[10];

    public:
    void main_menu();
    void add();
    void display();
    void rooms();
   }cus;

void hotel::main_menu()
{
    int choice;

    while(choice!=5)
    {
	clrscr();
	cout<<"\n\t\t\t\t///// MAIN MENU /////";
	cout<<"\n\n\t1.Book A Room";
	cout<<"\n\t2.Customer Record";
	cout<<"\n\t3.Rooms Allotted";
	cout<<"\n\t4.Exit";
	cout<<"\n\tEnter Your Choice: ";
	cin>>choice;
	switch(choice)
	{
	    case 1: add();
		    break;
	    case 2: display();
		    break;
	    case 3: rooms();
		    break;
	    case 4: break;
	    default:
		    {
		      cout<<"\n\n\t\tWrong choice!!!";
		      getch();
		    }
	}
    }
}
void hotel::add()
{
    clrscr();
    int r,flag;
    ofstream fout("Record.txt",ios::app);
    cout<<"\n Enter Customer Detalis";
    cout<<"\n\n Room no: ";
    cin>>r;
   if(flag)
	cout<<"\n Sorry,The Room is booked";
    else
    {
	room_no=r;
	cout<<" Name: ";
	gets(name);
	cout<<" Address: ";
	gets(address);
	cout<<" Phone No: ";
	gets(phone);
	fout.write((char*)&cus,sizeof(cus));
	cout<<"\n Room is booked!!!";
    }
    getch();
    fout.close();
}
void hotel::display()
{
    clrscr();
    ifstream fin("Record.txt",ios::in);
    int r,flag;
    cout<<"\n Enter room no: ";
    cin>>r;
    while(!fin.eof())
    {
	fin.read((char*)&cus,sizeof(cus));
	if(room_no==r)
	{
	    clrscr();
	    cout<<"\n Cusromer Details";
	    cout<<"\n\n Room no: "<<room_no;
	    cout<<"\n Name: "<<name;
	    cout<<"\n Address: "<<address;
	    cout<<"\n Phone no: "<<phone;
	    flag=1;
	    break;
	}
    }

    if(flag==0)
	cout<<"\n Sorry Room no is vacant!!";
    getch();
    fin.close();
}
void hotel::rooms()
{
    clrscr();
    ifstream fin("Record.txt",ios::in);
    cout<<"\n\t\t\tList Of Rooms Allotted";
    cout<<"\n\n Room No.\t Name\t\t Address\t\t Phone No.\n";
    while(!fin.eof())
    {
	fin.read((char*)&cus,sizeof(cus));
	cout<<"\n "<<room_no<<"\t"<<name;
	cout<<"\t"<<address<<"\t"<<phone;
    }
    getch();
    fin.close();
}
void main()
{
    hotel h;
    clrscr();
    cout<<"\n\t\t\t HOTEL MANAGEMENT PROJECT ";
    h.main_menu();
    getch();
}
