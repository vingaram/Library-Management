#include<ctype.h>
#include<process.h>
#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<fstream.h>
struct date                             //structure for date
{
	int dd,mm,yy;                  //for date,month & year
};
class acquisition                      //class for acquisition register
{
	int acquisition_no,no_of_pages;
	char access_code[6],book_title[41],author1[21],author2[21];
	char publisher[31],status;//status:'a' for not issued,'i' for issued
	float price;
	date date_publish,date_purchase;
public:
	char retstatus()
	{
		return status;
	}
	void issued()
	{
		status='i';
	}
	void returned()
	{
		status='a';
	}
	char* retbt()
	{
		return(book_title);
	}
	char* retpub()
	{
		return(publisher);
	}
	int retprice()
	{
		return(price);
	}
	acquisition input_from_file();
	void output_to_file(acquisition);
	void delet();
	void disp();
	void modify();
	void modifys();
	char* retaccess()
	{
		return access_code;
	}
	void read();
}book;
class membership
{
	int membership_no;
	char member_name[26],member_address[41];
	date date_begin,date_end;
	float membership_fee,caution_amt,total_fine_amount;
public:
	void modifys();
	void fine(int);
	void renew();
	void out_to_file(membership);
	membership in_from_file();
	date ret_date_begin()
	{
		return(date_begin);
	}
	date ret_date_end()
	{
		return(date_end);
	}
	char* retname()
	{
		return(member_name);
	}
	char* retaddress()
	{
		return(member_address);
	}
	void delet();
	void disp();
	void modify();
	int retmem()
	{
		return membership_no;
	}
	void read()
	{
		clrscr();
		cout<<"----------------READER'S HUT----------------------\n";
		cout<<"\nEnter membership number:\n";
		cin>>membership_no;
		cout<<"Enter member name:\n";
		gets(member_name);
		cout<<"Enter member's address:\n";
		gets(member_address);
		cout<<"Enter the day of begin of membership:\n";
		cin>>date_begin.dd;
		cout<<"Enter the month of begin of membership:\n";
		cin>>date_begin.mm;
		cout<<"Enter the year of begin of membership:\n";
		cin>>date_begin.yy;
		date_end=date_begin;
		date_end.yy=date_begin.yy+1;
		cout<<"Enter membership fee:\n";
		cin>>membership_fee;
		cout<<"Enter caution deposit amount:\n";
		cin>>caution_amt;
		total_fine_amount=0.0;
	}
}members;
class books
{
	int member_no;
	char access_code[6],publisher[31],book_name[41];
	date issue_date,return_date;
	char member_name[26],member_address[41];
	float price;
public:
	void disp();
	void delet();
	void returned();
	int isleapyear();
	void issue();
	int no_of_days();
	void calc_ret_date();
	int ret_memno();
	int isoverdue(date);
	char* ret_access()
	{
	return(access_code);
	}
	date ret_date()
	{
		return(return_date);
	}
	date retdate()
	{
		return(issue_date);
	}
}issues;
//int fnoa,fnom,fnoi;
int int_validate(char[]);
int calc_fine(date,date);
void fmodifym(membership,membership);
void fmodifya(acquisition,acquisition);
void renewal();
void adda();
void modifyas();
void issuef();
int searchi(char[]);
int searchim(int);
int searcha(char[]);
int searchm(int);
void modifyms();
void modifya();
void deletea();
void addm();
void book_return();
void modifym();
void deletem();
void list_overdue_books();
void list_expiring_memberships();
void list_books();
void list_members();
void increment(date &);
/*void putit()
{
ofstream ofile("variables.txt");
ofile<<fnoa<<" "<<fnom<<" "<<fnoi;
ofile.close();
}
void getit()
{
ifstream ifile("variables.txt");
ifile>>fnoa>>fnom>>fnoi;
cout<<fnoa<<"  "<<fnom<<"  "<<fnoi;
getch();
ifile.close();
}*/
char* password()
{
	int tempo;
	char pass[100],temp;
	label1:
	clrscr();
	cout<<"----------------READER'S HUT----------------------\n";
	cout<<"\nEnter password:";
	for(int i=0;i<100;i++)
	{
	tempo=temp=getch();
	cout<<'*';
	if(tempo==13||tempo==27)
	break;
	pass[i]=temp;
	}
	pass[i]='\0';
	return(pass);
}
void main()
{
	clrscr();
	char ch1,ch2,ch3;
//	getit();
//	input();
	label1:
	if(strcmp(password(),"hut")==0)
		goto label2;
	labe:
	clrscr();
	cout<<"\n----------------READER'S HUT----------------------\n";
	cout<<"\nDo you want to try again(y/n):";
	cin>>ch1;
	if(ch1=='y'||ch1=='Y')
		goto label1;
	else if(ch1=='n'||ch1=='N')
		exit(0);
	else
		cout<<"\nWrong key.\n";
		getch();
		goto labe;
	label2:
	clrscr();
	cout<<"\n\n\n\t WELCOME TO READER'S HUT"<<'\n'<<'\n'<<'\t'<< " A library With A Difference, A Never Before Experience!"<<'\n'<<'\n'<<'\t'<<" A Place To Read, A Chance To Grow!"<<'\n'<<'\n'<<'\t'<<" Come And Explore!";
	getch();

	int choice,achoice,mchoice,qchoice;
	do
	{
		clrscr();
		cout<<"\n\n\t----------------READER'S HUT----------------------\n\n";
		cout<<"\n1.Acquisition\n2.Membership\n3.Book Issue\n4.Book Return\n"
		    <<"5.Membership Renewal\n6.Queries\n7.Exit\nEnter choice:";
		cin>>choice;
		switch(choice)
		{
		case 1:
			do
			 {
				clrscr();
				cout<<"\n----------------READER'S HUT----------------------\n";
				cout<<"\n1.Add book\n2.Modify book detail\n3.Modify book access code or aquisition_no\n4.Delete book\n5.Back";
				cout<<"\nEnter choice:";
				cin>>achoice;
				switch(achoice)
				{
				case 1:
					book.read();
					book.output_to_file(book);
					break;
				case 2:
					modifya();
					break;
				case 3:
					label3:
					if(strcmp(password(),"modify")==0)
						goto label4;
					clrscr();
					cout<<"\n----------------READER'S HUT----------------------\n";
					cout<<"\nDo you want to try again(y/n):";
					cin>>ch2;
					if((ch2=='y'||ch2=='Y')&&(ch2!='n'&&ch2!='N'))
						goto label3;
					else
						break;
					label4:
					clrscr();
					modifyas();
					break;
				case 4:
					deletea();
					break;
				}
			}while(achoice!=5);
			break;
		case 2:
			do
			{
				clrscr();
				cout<<"\n----------------READER'S HUT----------------------\n";
				cout<<"\n1.Add member\n2.Modify member detail\n3.Modify member no.:\n4.Delete member\n5.Back";
				cout<<"\nEnter choice";
				cin>>mchoice;
				switch(mchoice)
				{
				case 1:
					members.read();
					members.out_to_file(members);
					break;
				case 2:
					modifym();
					break;
				case 3:
					label5:
					if(strcmp(password(),"modify")==0)
						goto label6;
					clrscr();
					cout<<"\n----------------READER'S HUT----------------------\n";
					cout<<"\nDo you want to try again(y/n):";
					cin>>ch3;
					if((ch3=='y'||ch3=='Y')&&(ch3!='n'&&ch3!='N'))
						goto label5;
					else
						break;
					label6:
					clrscr();
					modifyms();
					break;
				case 4:
					deletem();
					break;
				}
			}while(mchoice!=5);
			break;
		case 3:
			issues.issue();
			break;
		case 4:
			book_return();
			break;
		case 5:
			renewal();
			break;
		case 6:
			do
			{
				clrscr();
				cout<<"\n----------------READER'S HUT----------------------\n";
				cout<<"\n1.List of overdue books\n2.List of expiring memberships\n"
				    <<"3.List of books in library\n4.List of members\n5.Back";
				cout<<"\nEnter choice:";
				cin>>qchoice;
				switch(qchoice)
				{
				case 1:
					list_overdue_books();
					break;
				case 2:
					list_expiring_memberships();
					break;
				case 3:
					list_books();
					break;
				case 4:
					list_members();
					break;
				}
			}while(qchoice!=5);
			break;
		}
	}while(choice!=7);
//putit();
}
void modifya()
{
	clrscr();
	int flag=0;
	acquisition temp_book;
	char temp[6],ch;
	clrscr();
	cout<<"\n----------------READER'S HUT----------------------\n";
	cout<<"\nEnter the access code of the book:\n";
	cin>>temp;
	clrscr();
	cout<<"\n----------------READER'S HUT----------------------\n";
//	for(int i=0;i<;i++)
	flag=searcha(temp);
	temp_book=book;
	if(flag&&book.retstatus()!='n')
	{
		book.disp();
		cout<<"\n\nDo you want to continue(y/n):";
		cin>>ch;
		if(ch=='y'||ch=='Y')
			{
			book.modify();
			fmodifya(temp_book,book);
			}
	}
}
void acquisition::modify()
{
	clrscr();
	cout<<"Enter book title:\n";
	gets(book_title);
	cout<<"Enter author's first name:\n";
	gets(author1);
	cout<<"Enter author's second name:\n";
	gets(author2);
	cout<<"Enter publisher's name:\n";
	gets(publisher);
	cout<<"Enter book price:\n";
	cin>>price;
	cout<<"Enter number of pages in the book:\n";
	cin>>no_of_pages;
	cout<<"Enter the day of publishing:\n";
	cin>>date_publish.dd;
	cout<<"Enter the month of publishing:\n";
	cin>>date_publish.mm;
	cout<<"Enter the year of publishing:\n";
	cin>>date_publish.yy;
	cout<<"Enter the day of purchase:\n";
	cin>>date_purchase.dd;
	cout<<"Enter the month of purchase:\n";
	cin>>date_purchase.mm;
	cout<<"Enter the year of publishing:\n";
	cin>>date_purchase.yy;
}
void deletea()
{
	int flag=0;
	char temp[6],ch;
	clrscr();
	cout<<"----------------READER'S HUT----------------------\n";
	cout<<"Enter the access code of the book:";
	cin>>temp;
	clrscr();
	cout<<"----------------READER'S HUT----------------------\n";
	flag=searcha(temp);
//	for(int i=0;i<fnoa;i++)
		if(flag&&book.retstatus()!='n')
		{
		book.disp();
		cout<<"Do you want to continue(y/n):";
		cin>>ch;
		if(ch=='y'||ch=='Y')
			book.delet();
	}
}
void modifym()
{
	membership temp_member;
	int flag=0,temp;
	char ch;
	clrscr();
	cout<<"----------------READER'S HUT----------------------\n";
	cout<<"Enter the membership no. of the member:";
	cin>>temp;
	clrscr();
	cout<<"----------------READER'S HUT----------------------\n";
//	for(int i=0;i<fnom;i++)
	flag=searchm(temp);
	temp_member=members;
	if(flag&&members.retmem())
	{
		members.disp();
		cout<<"Do you want to continue(y/n):";
		cin>>ch;
		if(ch=='y'||ch=='Y')
		{
			members.modify();
			fmodifym(temp_member,members);
		}
	}
}
void membership::modify()
{
	clrscr();
	cout<<"----------------READER'S HUT----------------------\n";
	cout<<"Enter member name:\n";
	gets(member_name);
	cout<<"Enter member's address:\n";
	gets(member_address);
	cout<<"Enter the day of begin of membership:\n";
	cin>>date_begin.dd;
	cout<<"Enter the month of begin of membership:\n";
	cin>>date_begin.mm;
	cout<<"Enter the year of begin of membership:\n";
	cin>>date_begin.yy;
	date_end=date_begin;
	date_end.yy=date_begin.yy+1;
	cout<<"Enter membership fee:\n";
	cin>>membership_fee;
	cout<<"Enter caution deposit amount:\n";
	cin>>caution_amt;
}
void deletem()
{
	int flag=0,temp;
	char ch;
	clrscr();
	cout<<"----------------READER'S HUT----------------------\n";
	cout<<"Enter the membership no. of the book:";
	cin>>temp;
	clrscr();
	cout<<"----------------READER'S HUT----------------------\n";
//	for(int i=0;i<fnom;i++)
	flag=searchm(temp);
	if(flag&&members.retmem())
	{
		members.disp();
		cout<<"Do you want to continue(y/n):";
		cin>>ch;
		if(ch=='y'||ch=='Y')
			members.delet();
	}
}
void list_overdue_books()
{
	books temp_issue1,temp_issue2;
	date temp;
	int flag1=0,flag2=0;
	char ch='y';
	clrscr();
	cout<<"----------------READER'S HUT----------------------\n";
	cout<<"Enter the day of interest:\n";
	cin>>temp.dd;
	cout<<"Enter the month of interest:\n";
	cin>>temp.mm;
	cout<<"Enter the year of interest:\n";
	cin>>temp.yy;
	ifstream ifile;
	ifile.open("Issues.txt",ios::binary);
	ifstream ifi;
	ifi.open("Retfiles.txt",ios::binary);
	while(ifile||ifi)
	{
	if(ch=='y'||ch=='Y')
	{
	if(ifile)
	flag1=1;
	if(ifi)
	flag2=1;
	if(flag1)
	ifile.read((char*)&temp_issue1,sizeof(temp_issue1));
	if(flag2)
	ifi.read((char*)&temp_issue2,sizeof(temp_issue2));
	if(!temp_issue1.isoverdue(temp))
	flag1=0;
	if(!temp_issue2.isoverdue(temp))
	flag2=0;
	if(flag1&&flag2)
	if(!strcmp(temp_issue1.ret_access(),temp_issue2.ret_access()))
	{
	temp_issue1.disp();
	cout<<"\nDo you want to continue(y/n):\n";
	cin>>ch;
	}
	else
	{
	temp_issue1.disp();
	cout<<"\nDo you want to continue(y/n):\n";
	cin>>ch;
	if(ch=='y'||ch=='Y')
	{
	temp_issue2.disp();
	cout<<"\nDo you want to continue(y/n):\n";
	cin>>ch;
	}
	}
	else if(flag1)
	{
	temp_issue1.disp();
	cout<<"\nDo you want to continue(y/n):\n";
	cin>>ch;
	}
	else
	{
	temp_issue1.disp();
	cout<<"\nDo you want to continue(y/n):\n";
	cin>>ch;
	}
	}
	}
	ifile.close();
	ifi.close();
}
void books::issue()
{
	clrscr();
	int flag1=0,flag2=0;
	cout<<"----------------READER'S HUT----------------------\n";
	cout<<"Enter access code of the book:";
	gets(access_code);
	cout<<"Enter member no. of the member:";
	cin>>member_no;
	cout<<"Enter the day of issue:";
	cin>>issue_date.dd;
	cout<<"Enter the month of issue:";
	cin>>issue_date.mm;
	cout<<"Enter the year of issue:\n";
	cin>>issue_date.yy;
//	for(int i=0;i<fnoi;i++)
	flag1=searcha(access_code);
	flag2=searchm(member_no);
//	flag3=searchi(access_code,member_no);
	char ch=book.retstatus();
	if(flag1&&flag2)
	if(ch=='a')
		{
			book.issued();
			strcpy(publisher,book.retpub());
			strcpy(book_name,book.retbt());
			price=book.retprice();
		}
	else if(ch=='i')
	{
		cout<<"The Book Is Issued.";
		getch();
	}
//	for(i=0;i<fnom;i++)
	if(ch=='a')
	{
		if(flag1&&flag2)
		{
			strcpy(member_address,members.retaddress());
			strcpy(member_name,members.retname());
		}
	calc_ret_date();
	issuef();
	}
}
int books::no_of_days()
{
	int no=31;
	int flag1,flag2;
	switch(issue_date.mm)
	{
	case 1:
		no=31;
		break;
	case 2:
		no=28+isleapyear();
		break;
	case 3:
		no=31;
		break;
	case 4:
		no=30;
		break;
	case 5:
		no=31;
		break;
	case 6:
		no=30;
		break;
	case 7:
		no=31;
		break;
	case 8:
		no=31;
		break;
	case 9:
		no=30;
		break;
	case 10:
		no=31;
		break;
	case 11:
		no=30;
		break;
	case 12:
		no=31;
		break;
	}

	return no;
}
int books::isleapyear()
{
	if(issue_date.yy%4==0)
		return 1;
	else
		return 0;
}
void books::calc_ret_date()
{
	date temp;
	temp=issue_date;
	int days=issue_date.dd;
	int left=no_of_days()-days;
	return_date=issue_date;
	switch(left)
	{
	case 0:
		temp.dd=7;
		temp.mm++;
		break;
	case 1:
		temp.dd=6;
		temp.mm++;
		break;
	case 2:
		temp.dd=5;
		temp.mm++;
		break;
	case 3:
		temp.dd=4;
		temp.mm++;
		break;
	case 4:
		temp.dd=3;
		temp.mm++;
		break;
	case 5:
		temp.dd=2;
		temp.mm++;
		break;
	case 6:
		temp.dd=1;
		temp.mm++;
		break;
	default:
		return_date.dd+=7;
	}
	if(left>=0&&left<=6)
	return_date=temp;
//	cout<<"\n"<<return_date.dd<<endl<<return_date.mm<<endl<<return_date.yy;
	getch();
}
void list_expiring_memberships()
{
	clrscr();
	cout<<"----------------READER'S HUT----------------------\n";
	int month;
	membership member;
	char ch='y';
//	date temp;
	cout<<"Enter the month:";
	cin>>month;
	clrscr();
	cout<<"----------------READER'S HUT----------------------\n";
//	for(int i=0;i<fnom&&(ch=='y'||ch=='Y');i++)
	ifstream ifile;
	ifile.open("Membership.txt",ios::binary);
	while(ifile)
	{
	ifile.read((char*)&member,sizeof(member));
	if((ch=='y'||ch=='Y')&&month==member.ret_date_end().mm)
	{
		clrscr();
		cout<<"----------------READER'S HUT----------------------\n";
		cout<<"\nThe membership no. is:\n"<<members.retmem();
		cout<<"\nThe member's name is:\n"<<members.retname();
		cout<<"\nThe member's address is:\n"<<members.retaddress();
		cout<<"\nThe membership commencement day is:\n"<<members.ret_date_begin().dd;
		cout<<"\nThe membership commencement month is:\n"<<members.ret_date_begin().mm;
		cout<<"\nThe membership commencement year is:\n"<<members.ret_date_begin().yy;
		cout<<"\nThe day of expiry is:\n"<<members.ret_date_end().dd;
		cout<<"\nThe month of expiry is:\n"<<members.ret_date_end().mm;
		cout<<"\nThe year of expiry is:\n"<<members.ret_date_end().yy;
		cout<<"\nDo you want to continue(y/n):\n";
		cin>>ch;
	}
	}
}
void acquisition::delet()
{
	clrscr();
	if(status!='i')
	{
		acquisition temp;
		ofstream ofile;
		ofile.open("Temp.txt",ios::out);
		ifstream ifile;
		ifile.open("Acquisition.txt",ios::binary);
		while(ifile)
		{
			ifile.read((char*)&temp,sizeof(temp));
			if(strcmp(temp.retaccess(),book.retaccess()))
				ofile.write((char*)&temp,sizeof(temp));
		}
		ifile.close();
		ofile.close();
		remove("Acquisition.txt");
		rename("Temp.txt","Acquisition.txt");
		}

	else
	{
		cout<<"The book is being issued.";
		getch();
	}
}
int books::ret_memno()
{
	return member_no;
}
void membership::delet()
{
	clrscr();
	if(membership_no)
	{
		membership temp;
		ofstream ofile;
		ofile.open("Temp.txt",ios::out);
		ifstream ifile;
		ifile.open("Membership.txt",ios::binary);
		while(ifile)
		{
			ifile.read((char*)&temp,sizeof(temp));
			if(temp.retmem()!=members.retmem())
				ofile.write((char*)&temp,sizeof(temp));
		}
		ifile.close();
		ofile.close();
		remove("Membership.txt");
		rename("Temp.txt","Membership.txt");
		cout<<"Deleted.";
		getch();
	}
	else
		cout<<"Can Not Be Deleted.";
		getch();
}
void books::returned()
{
	clrscr();
	cout<<"----------------READER'S HUT----------------------\n";
	int flag1=0,flag2=0,days,late=0;
	date retur_date;
	cout<<"Enter the day of return:\n";
	cin>>retur_date.dd;
	cout<<"Enter the month of return:\n";
	cin>>retur_date.mm;
	cout<<"Enter the year of return:\n";
	cin>>retur_date.yy;
	flag1=searchm(member_no);
	flag2=searcha(access_code);
	if(retur_date.yy>return_date.yy)
		late=1;
	else if(retur_date.yy==return_date.yy&&retur_date.mm>return_date.mm)
		late=1;
	else if(retur_date.yy==return_date.yy&&retur_date.mm==return_date.mm&&retur_date.dd>return_date.dd)
		late=1;
	if(late)
	{
		cout<<"Late";
		getch();
	//	for(int i=0;i<fnom;i++)
		if(flag1)
		{
		cout<<"fined";getch();
		members.fine(calc_fine(return_date,retur_date));}
		}
		if(flag2)
		{cout<<"returned";getch();
		book.returned();         }
	delet();
}
void increment(date &temp)
{
int no;
int leap=0;
if(temp.yy%4==0)
leap=1;
switch(temp.mm)
{
	case 1:
		no=31;
		break;
	case 2:
		no=28+leap;
		break;
	case 3:
		no=31;
		break;
	case 4:
		no=30;
		break;
	case 5:
		no=31;
		break;
	case 6:
		no=30;
		break;
	case 7:
		no=31;
		break;
	case 8:
		no=31;
		break;
	case 9:
		no=30;
		break;
	case 10:
		no=31;
		break;
	case 11:
		no=30;
		break;
	case 12:
		no=31;
		break;
}
if(temp.dd!=no)
temp.dd++;
else if(temp.mm!=12)
{
temp.dd=1;
temp.mm++;
}
else
{
temp.dd=temp.mm=1;
temp.yy++;
}
}
int calc_fine(date return_date1,date return_date2)
{
date temp1=return_date1,temp2=return_date2;
int days=0;
while(temp1.dd<temp2.dd||temp1.mm<temp2.mm||temp1.yy<temp2.yy)
{
increment(temp1);
days++;
}
return(days);
}
void membership::fine(int days)
{
clrscr();
cout<<"----------------READER'S HUT----------------------\n";
total_fine_amount+=days;
cout<<"The fine amt for late return is:\n";
cout<<days;
getch();
}
void membership::renew()
{
	int flag=1;
	clrscr();
	cout<<"----------------READER'S HUT----------------------\n";
//	for(int i=0;i<fnoi;i++)
	flag=searchim(membership_no);
		if(flag)
		{
			cout<<"A book is due.\n";
			getch();
		}
	else
	{
		total_fine_amount=0.0;
		date_begin.yy+=1;
		date_end=date_begin;
		date_end.yy=date_begin.yy+1;
	}
}
void acquisition::disp()
{

	clrscr();
	cout<<"----------------READER'S HUT----------------------\n";
	cout<<"\nThe acquisition number is:\n";
	cout<<acquisition_no;
	cout<<"\nThe access code is:\n";
	puts(access_code);
	cout<<"\nThe book title is:\n";
	puts(book_title);
	cout<<"\nThe author's first name is:\n";
	puts(author1);
	cout<<"\nThe author's second name is:\n";
	puts(author2);
	cout<<"\nThe publisher's name is:\n";
	puts(publisher);
	cout<<"\nThe book price is:\n";
	cout<<price;
	cout<<"\nThe number of pages in the book is:\n";
	cout<<no_of_pages;
	cout<<"\nPress a key to continue:";
	getch();
	clrscr();
	cout<<"\nThe day of publishing is:\n";
	cout<<date_publish.dd;
	cout<<"\nThe month of publishing is:\n";
	cout<<date_publish.mm;
	cout<<"\nThe year of publishing is:\n";
	cout<<date_publish.yy;
	cout<<"\nThe day of purchase is:\n";
	cout<<date_purchase.dd;
	cout<<"\nThe month of publishing is:\n";
	cout<<date_purchase.mm;
	cout<<"\nThe year of purhase is:\n";
	cout<<date_purchase.yy;
	cout<<"\nThe status of the book is:";
	cout<<status;
}
int books::isoverdue(date rdate)
{
	if(rdate.yy>return_date.yy)
		return(1);
	else if((rdate.mm>return_date.mm)&&(rdate.yy==return_date.yy))
		return(1);
	else if((rdate.dd>return_date.dd)&&(rdate.mm==return_date.mm)&&(rdate.yy==return_date.yy))
		return(1);
	else
		return(0);
}
void list_books()
{
	char ch='y';
	ifstream ifile;
	ifile.open("Acquisition.txt",ios::binary);
	while(ifile&&(ch=='Y'||ch=='y'))
	{
	ifile.read((char*)&book,sizeof(book));
	clrscr();
	cout<<"----------------READER'S HUT----------------------\n";
	book.disp();
	cout<<"\nDo you want to continue(y/n):\n";
	cin>>ch;
	}
	ifile.close();
}
void list_members()
{
	char ch='y';
//	for(int i=0;i<fnom&&(ch=='y'||ch=='Y');i++)
	ifstream ifile;
	ifile.open("Membership.txt",ios::binary);
	while(ifile&&(ch=='y'||ch=='Y'))
	{
	ifile.read((char*)&members,sizeof(members));
	clrscr();
	cout<<"----------------READER'S HUT----------------------\n";
	members.disp();
	cout<<"Do you want to continue(y/n):\n";
	cin>>ch;
	}
}
void membership::disp()
{
	if(membership_no)
	{
	clrscr();
	cout<<"----------------READER'S HUT----------------------\n";
	cout<<"\nThe membership number is:\n";
	cout<<membership_no;
	cout<<"\nThe member name is:\n";
	cout<<member_name;
	cout<<"\nThe member's address is:\n";
	cout<<member_address;
	cout<<"\nThe day of begin of membership is:\n";
	cout<<date_begin.dd;
	cout<<"\nThe month of begin of membership is:\n";
	cout<<date_begin.mm;
	cout<<"\nThe year of begin of membership is:\n";
	cout<<date_begin.yy;
	cout<<"\nThe day  of expiry of membership is:\n";
	cout<<date_end.dd;
	cout<<"\nThe month of expiry of membership is:\n";
	cout<<date_end.mm;
	cout<<"\nThe year of expiry of membership is:\n";
	cout<<date_end.yy;
	cout<<"\nThe membership fee is:\n";
	cout<<membership_fee;
	cout<<"\nThe caution deposit amount is:\n";
	cout<<caution_amt;
	cout<<"\nThe total fine amount is:\n";
	cout<<total_fine_amount;
	}
}
void books::disp()
{
	clrscr();
	cout<<"----------------READER'S HUT----------------------\n";
	cout<<"\nThe access code of the book is:\n";
	cout<<access_code;
	cout<<"\nThe member no. of the member is:\n";
	cout<<member_no;
	cout<<"\nThe day of issue is:\n";
	cout<<issue_date.dd;
	cout<<"\nThe month of issue is:";
	cout<<issue_date.mm;
	cout<<"\nThe year of issue is:\n";
	cout<<issue_date.yy;
	cout<<"\nThe publisher is:\n";
	cout<<publisher;
	cout<<"\nThe book name is:\n";
	cout<<book_name;
	cout<<"\nThe book price is:\n";
	cout<<price;
	cout<<"\nThe day of return is:\n";
	cout<<return_date.dd;
	cout<<"\nThe month of return is:\n";
	cout<<return_date.mm;
	cout<<"\nThe year of return is:\n";
	cout<<return_date.yy;
	cout<<"\nThe member's name is:\n";
	cout<<member_name;
	cout<<"\nThe member's address is:\n";
	cout<<member_address;
}
void books::delet()
{
	acquisition book1;
	membership member;
	ofstream ofile;
	ofile.open("Temp.txt",ios::out);
	ifstream ifile;
	ifile.open("Issues.txt",ios::binary);
	books temp1;
	while(ifile)
	{
ifile.read((char*)&temp1,sizeof(temp1));
if(strcmp(temp1.ret_access(),issues.ret_access()))
ofile.write((char*)&temp1,sizeof(temp1));
}
ofile.close();
ifile.close();
remove("Issues.txt");
rename("Temp.txt","Issues.txt");
ofstream ofi;
ofi.open("Temp.txt",ios::out);
ifstream ifi;
ifi.open("Membership.txt",ios::binary);
while(ifi)
{
ifi.read((char*)&member,sizeof(member));
if(member.retmem()!=members.retmem())
ofi.write((char*)&member,sizeof(member));
else
ofi.write((char*)&members,sizeof(members));
}
ifi.close();
ofi.close();
remove("Membership.txt");
rename("Temp.txt","Membership.txt");
ifstream input_file;
input_file.open("Acquisition.txt",ios::binary);
ofstream output_file;
output_file.open("Temp.txt",ios::out);
while(input_file)
{
input_file.read((char*)&book1,sizeof(book1));
if(strcmp(book1.retaccess(),book.retaccess()))
output_file.write((char*)&book1,sizeof(book1));
else
output_file.write((char*)&book,sizeof(book));
}
output_file.close();
input_file.close();
remove("Acquisition.txt");
rename("Temp.txt","Acquisition.txt");
ofstream out_file;
out_file.open("Retfiles.txt",ios::binary|ios::app|ios::ate);
out_file.write((char*)&issues,sizeof(issues));
out_file.close();
}
void book_return()
{
	clrscr();
	cout<<"----------------READER'S HUT----------------------\n";
	char access_code[6];
	cout<<"Enter the access code of the book";
	gets(access_code);
//	for(int i=0;i<fnoi;i++)
	int flag=searchi(access_code);
	if(flag)
	       {cout<<"a";getch();	issues.returned();}
}
void renewal()
{
	clrscr();
	membership temp;
	cout<<"----------------READER'S HUT----------------------\n";
	int flag=0,member_no;
	cout<<"Enter member no:\n";
	cin>>member_no;
	flag=searchm(member_no);
	//	for(int i=0;i<fnom;i++)
	if(flag)
	{
	temp=members;
	members.renew();
	fmodifym(temp,members);
	}
}
acquisition acquisition::input_from_file()
{
acquisition temp;
ifstream ifile;
ifile.open("Acquisition.txt",ios::binary);
ifile.read((char*)&temp,sizeof(temp));
ifile.close();
return(temp);
}
void acquisition::output_to_file(acquisition temp)
{
ofstream ofile;
ofile.open("Acquisition.txt",ios::app|ios::ate|ios::binary);
if(temp.retstatus()!='n')
ofile.write((char*)&temp,sizeof(temp));
ofile.close();
}
void fmodifya(acquisition book1,acquisition book2)
{
acquisition temp;
ofstream ofile;
ofile.open("Temp.txt",ios::out);
ifstream ifile;
ifile.open("Acquisition.txt",ios::binary);
while(ifile)
{
ifile.read((char*)&temp,sizeof(temp));
if(strcmp(temp.retaccess(),book1.retaccess()))
ofile.write((char*)&temp,sizeof(temp));
else
ofile.write((char*)&book2,sizeof(book2));
}
ifile.close();
ofile.close();
remove("Acquisition.txt");
rename("Temp.txt","Acquisition.txt");
}
membership membership::in_from_file()
{
membership temp;
ifstream ifile;
ifile.open("Membership.txt",ios::binary);
ifile.read((char*)&temp,sizeof(temp));
ifile.close();
return(temp);
}
void membership::out_to_file(membership temp)
{
ofstream ofile;
ofile.open("Membership.txt",ios::app|ios::ate|ios::binary);
if(temp.retmem())
ofile.write((char*)&temp,sizeof(temp));
ofile.close();
}
void fmodifym(membership member1,membership member2)
{
membership temp;
ofstream ofile;
ofile.open("Temp.txt",ios::out);
ifstream ifile;
ifile.open("Membership.txt",ios::binary);
while(ifile)
{
ifile.read((char*)&temp,sizeof(temp));
if(ifile)
if(temp.retmem()!=member1.retmem())
ofile.write((char*)&temp,sizeof(temp));
else
ofile.write((char*)&member2,sizeof(member2));
}
ifile.close();
ofile.close();
remove("Membership.txt");
rename("Temp.txt","Membership.txt");
}
void modifyas()
{
	clrscr();
	acquisition temp_book;
	int flag1=0,flag2=0;
	char temp[6],ch;
	clrscr();
	cout<<"\n----------------READER'S HUT----------------------\n";
	cout<<"\nEnter the present access code of the book:\n";
	cin>>temp;
	clrscr();
	cout<<"\n----------------READER'S HUT----------------------\n";
	flag2=searcha(temp);
//	for(int i=0;i<fnoa;i++)
		if(flag2&&book.retstatus()!='n')
		{
			temp_book=book;
			flag1=1;
		}
	if(flag1)
	{
		book.disp();
		cout<<"\n\nDo you want to continue(y/n):";
		cin>>ch;
		if(ch=='y'||ch=='Y')
			{
			book.modifys();
			fmodifya(temp_book,book);
			}
	}
}
void acquisition::modifys()
{
		clrscr();
		cout<<"\n----------------READER'S HUT----------------------\n";
		cout<<"\nEnter acquisition number:\n";
		cin>>acquisition_no;
		cout<<"Enter access code:\n";
		gets(access_code);
}
int searcha(char access[])
{
int flag=0;
ifstream ifile;
ifile.open("Acquisition.txt",ios::binary);
while(ifile)
{
ifile.read((char*)&book,sizeof(book));
if(!strcmp(book.retaccess(),access))
{
flag=1;
break;
}
}
ifile.close();
return flag;
}
void modifyms()
{
	clrscr();
	membership temp_member;
	int temp,flag1=0,flag2=0;
	char ch;
	clrscr();
	cout<<"\n----------------READER'S HUT----------------------\n";
	cout<<"\nEnter the present membership no. of the member:\n";
	cin>>temp;
	clrscr();
	cout<<"\n----------------READER'S HUT----------------------\n";
	flag2=searchm(temp);
//	for(int i=0;i<fnoa;i++)
		if(flag2&&members.retmem())
		{
			temp_member=members;
			flag1=1;
		}
	if(flag1)
	{
		members.disp();
		cout<<"\n\nDo you want to continue(y/n):";
		cin>>ch;
		if(ch=='y'||ch=='Y')
			{
			members.modifys();
			fmodifym(temp_member,members);
			}
	}
}
void membership::modifys()
{
		clrscr();
		cout<<"\n----------------READER'S HUT----------------------\n";
		cout<<"\nEnter membership number:\n";
		cin>>membership_no;
}
int searchm(int member_no)
{
int flag=0;
ifstream ifile;
ifile.open("Membership.txt",ios::binary);
while(ifile)
{
ifile.read((char*)&members,sizeof(members));
if(members.retmem()==member_no)
{
flag=1;
break;
}
}
ifile.close();
return flag;
}
void issuef()
{
acquisition temp1;
ifstream ifile;
ifile.open("Acquisition.txt",ios::binary);
ofstream ofile;
ofile.open("Temp.txt",ios::out);
while(ifile)
{
ifile.read((char*)&temp1,sizeof(temp1));
if(strcmp(temp1.retaccess(),book.retaccess()))
ofile.write((char*)&temp1,sizeof(temp1));
else
ofile.write((char*)&book,sizeof(book));
}
ofile.close();
ifile.close();
remove("Acquisition.txt");
rename("Temp.txt","Acquisition.txt");
membership temp2;
ifstream ifi;
ifi.open("Membership.txt",ios::binary);
ofstream ofi;
ofi.open("Temp.txt",ios::out);
while(ifi)
{
ifi.read((char*)&temp2,sizeof(temp2));
if(temp2.retmem()!=members.retmem())
ofi.write((char*)&temp2,sizeof(temp2));
else
ofi.write((char*)&members,sizeof(members));
}
ofi.close();
ifi.close();
remove("Membership.txt");
rename("Temp.txt","Membership.txt");
ofstream ofiles;
ofiles.open("Issues.txt",ios::app|ios::ate|ios::binary);
ofiles.write((char*)&issues,sizeof(issues));
ofiles.close();
}
int searchi(char access[])
{
int flag=0;
ifstream ifile;
ifile.open("Issues.txt",ios::binary);
while(ifile)
{
ifile.read((char*)&issues,sizeof(issues));
if(!strcmp(issues.ret_access(),access))
{
flag=1;
break;
}
}
ifile.close();
return flag;
}
int searchim(int member_no)
{
int flag=0;
ifstream ifile;
ifile.open("Issues.txt",ios::binary);
while(ifile)
{
if(!ifile.eof())
{
ifile.read((char*)&issues,sizeof(issues));
if(ifile)
if(issues.ret_memno()==member_no)
{
cout<<"aa";
cout<<issues.ret_access()<<endl
<<issues.ret_memno()<<endl
<<issues.ret_date().dd<<endl
<<issues.ret_date().mm<<endl
<<issues.ret_date().yy<<endl
<<issues.retdate().dd<<endl;
getch();
flag=1;
break;
}
}
}
ifile.close();
return flag;
}
int int_validate(char str[])
{
int flag=1;
for(int i=0;str[i]!='\0';i++)
if(!isdigit(str[i]))
flag=0;
return flag;
}
void acquisition::read()
	{
		int flag=0;
		char str[100];
		label1:
		clrscr();
		cout<<"\n----------------READER'S HUT----------------------\n";
		cout<<"\nEnter acquisition number:\n";
		gets(str);
	      //	cin>>acquisition_no;
		flag=int_validate(str);
		if(!flag)
		goto label1;
		cout<<"Enter access code:\n";
		gets(access_code);
		cout<<"Enter book title:\n";
		gets(book_title);
		cout<<"Enter author's first name:\n";
		gets(author1);
		cout<<"Enter author's second name:\n";
		gets(author2);
		cout<<"Enter publisher's name:\n";
		gets(publisher);
		cout<<"Enter book price:\n";
		cin>>price;
		cout<<"Enter number of pages in the book:\n";
		cin>>no_of_pages;
		cout<<"Enter the day of publishing:\n";
		cin>>date_publish.dd;
		cout<<"Enter the month of publishing:\n";
		cin>>date_publish.mm;
		cout<<"Enter the year of publishing:\n";
		cin>>date_publish.yy;
		cout<<"Enter the day of purchase:\n";
		cin>>date_purchase.dd;
		cout<<"Enter the month of purchase:\n";
		cin>>date_purchase.mm;
		cout<<"Enter the year of publishing:\n";
		cin>>date_purchase.yy;
		status='a';
	}
