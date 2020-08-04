#include<iostream.h>
#include<fstream.h>
#include<stdio.h>
#include<iomanip.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<dir.h>
#include<dos.h>
#include<bios.h>
#include<graphics.h>

void screen();
void drawdoublelinebox(int,int,int,int);
void drawsinglelinebox(int,int,int,int);
void normal();


#define datafile "hash.txt"
#define recsize 78
#define max 59
#define m 177
#define bucketsize 3
int hash(char a[]);
fstream file;
char buffer[100];

class atm
{
public:
  char dv_no[12],v_desc[10],name[12],entry_time[7],exit_time[7],type[10];
public:
	void initial();
	void read();
	void pack();
	void unpack();
	int  retrieve(int addr,char k[],int i);
	void datadisp();
	int  remove(int addr,char k[]);
	void modify(int addr ,char k[]);
};

int myatoi(char *k)
{
   int res=0;
   for(int i=0;k[i]!='\0';++i)
   {
      if(k[i]==58)
	 continue;
      res=res*10+k[i]-48;
   }
   //cout<<res;
   return res;
}

void opener(fstream &file,char *fn,int mode)
{
	file.open(fn,mode);
	if(!file)
	{
		cout<<"UNABLE TO OPEN THE FILE\n"<<fn;
		getch();
		exit(1);
	}
}

void atm::initial()
{
	int i,j;
	file.open(datafile,ios::in);
	if(!file)
	{
		file.open(datafile,ios::out);
		if(!file)
		{
			cout<<"UNABLE TO OPEN THE FILE\n";
			getch();
			exit(1);
		}
		for(i=0;i<max;i++)
		{
			file.seekp(i*recsize*3,ios::beg);
			for(j=0;j<(recsize*3)-2;j++)
			   file<<"#";
			file<<endl;
		}
		cout<<"EMPTY FILE CREATED\n";
	}
	file.close();
	return;
}
void atm::read()
{
	int addr,len,len1,len2,len3,len4,len5;

	char v_no[12],dv_desc[10],dslot[8];


	 LABEL:
		cout<<"\n\t\t\tENTER THE ACCOUNT NUMBER: ";
		gets(v_no);
		len=strlen(v_no);
		addr=hash(v_no);
		if(len!=6||v_no[0]<63||v_no[1]<63||v_no[2]>63||v_no[3]>63 ||v_no[4]>63 ||v_no[5]>63)
		{
			cout<<"\n\t  ENTER VALID ACCOUNT NUMBER: ";
			goto LABEL;
		}

		if(retrieve(addr,v_no,0)>0)
		{
			cout<<"!!*** ACCOUNT IS ALREADY PRESENT, WE CANNOT ADD IT TO THE HASH FILE ***!!\n";
			goto LABEL;
		}
		file.close();
		strcpy(dv_no,v_no);

	NAME:
		cout<<"\n\t\tENTER THE NAME OF THE CUSTOMER: ";
		gets(name);
		int i=0;
		while(name[i]!='\0')
		{
			 if(name[i]<63||i>9)
			{
				  cout<<"\n\t  ENTER THE VALID CUSTOMER NAME(LESS THAN 10 CHARACTERS): ";
				 goto NAME;
			}
			i++;
		}


       ENT:
		cout<<"\n\t\tENTER THE  TIME OF ENTRY IN 24 HRS FORMAT: ";
		gets(entry_time);
		len4=strlen(entry_time);
		 i=0;
	while(entry_time[i]!='\0')
	{
	    if(entry_time[i]>63||i>4||entry_time[2]!=58 ||len4!=5)
	    {
	      cout<<"\n\t  ENTER THE VALID TIME OF ENTRY IN 24 HRS FORMAT: ";
	      goto ENT;
	    }
	      i++;
	}


     EXT:
	cout<<"\n\t\tENTER THE TIME OF EXIT IN 24 HRS FORMAT: ";
	gets(exit_time);
	len5=strlen(exit_time);
	   i=0;
	while(exit_time[i]!='\0')
	{
	    if(exit_time[i]>63||i>4||exit_time[2]!=58 ||len5!=5)
	    {
	      cout<<"\n\t  ENTER THE VALID  TIME OF EXIT IN 24 HRS FORMAT: ";
	      goto EXT;
	    }
	      i++;
	}



   TYPE:
		cout<<"\n\t\tENTER THE TYPE OF ACCOUNT: ";
		gets(type);
		 i=0;
		while(name[i]!='\0')
		{
			 if(name[i]<63||i>9)
			{
				  cout<<"\n\t  ENTER THE VALID ACCOUNT TYPE: ";
				 goto TYPE;
			}
			i++;
		}




	pack();

	return;


}
void atm::pack()
{
	strcpy(buffer,dv_no);		strcat(buffer,"|");
	strcat(buffer,name);		strcat(buffer,"|");
	strcat(buffer,entry_time);	strcat(buffer,"|");
	strcat(buffer,exit_time);	strcat(buffer,"|");
	strcat(buffer,type);        	strcat(buffer,"|");
}

int hash(char dv_no[])
{
int i=0,sum=0,c,len;
len=strlen(dv_no);
if(len%2==1)
    len++;
for(i=0;i<len;i+=2)
    sum=(sum+((dv_no[i]+dv_no[i+1])-96));
c=sum%59;
//cout<<"\n\t\t    HASH KEY GENERATED IS: "<<c<<endl;
return c;
}

void store(int addr)
{
char dummy[10];
int flag=0,i;
file.open(datafile,ios::in|ios::out);
file.seekg(addr*recsize*bucketsize,ios::beg);
file.getline(dummy,5,'\n');
if(strcmp(dummy,"####")==0 ||strcmp(dummy,"$$$$")==0)
{
	file.seekp(addr*recsize*bucketsize,ios::beg);
	file<<buffer;
	clrscr();
	textcolor(RED);
	textbackground(BLACK);
	cout<<"\n\n\n\n";
	for(int q=0;q<80;q++) cout<<'~';
	for(int w=0;w<80;w++) cout<<'*';
	cout<<"\n\n\t\t   CUSTOMER RECORD IS INSERTED SUCCESSFULLY.......PRESS ANY KEY TO CONTINUE\n\n";
	for(int e=0;e<80;e++) cout<<'*';
	cout<<"\n";
	for(int r=0;r<80;r++) cout<<'~';
	getch();
	flag=1;
}
file.seekg(addr*recsize*bucketsize+recsize,ios::beg);
file.getline(dummy,5,'\n');
if((strcmp(dummy,"####")==0||strcmp(dummy,"$$$$")==0) && flag!=1)
{
	file.seekp(addr*recsize*bucketsize+recsize,ios::beg);
	file<<buffer;clrscr();
	textcolor(GREEN);
	textbackground(BLACK);
	cout<<"\n\n\n\n";
	for(int q=0;q<80;q++) cout<<'~';
	for(int w=0;w<80;w++) cout<<'*';
	cout<<"\n\n\t\t   CUSTOMER RECORD IS INSERTED SUCCESSFULLY....!!\n\n";
	for(int e=0;e<80;e++) cout<<'*';
	cout<<"\n";
	for(int r=0;r<80;r++) cout<<'~';
	getch();
	flag=1;
}
file.seekg(addr*recsize*bucketsize+(2*recsize),ios::beg);
file.getline(dummy,5,'\n');
if((strcmp(dummy,"####")==0||strcmp(dummy,"$$$$")==0)&&flag!=1)
{
	file.seekp(addr*recsize*bucketsize+(2*recsize),ios::beg);
	file<<buffer;
	clrscr();
	textcolor(YELLOW);
	textbackground(BLACK);
	cout<<"\n\n\n\n";
	for(int q=0;q<80;q++) cout<<'~';
	for(int w=0;w<80;w++) cout<<'*';
	cout<<"\n\n\t\t   CUSTOMER RECORD IS INSERTED SUCCESSFULLY....!!\n\n";
	for(int e=0;e<80;e++) cout<<'*';
	cout<<"\n";
	for(int r=0;r<80;r++) cout<<'~';
	getch();
	flag=1;
}
if(flag!=1)
{
for(i=addr+1;i!=addr;i++)
{
	if(i%max==0)
		i=0;
	file.seekg(i*recsize*bucketsize,ios::beg);
	file.getline(dummy,5,'\n');
	if(strcmp(dummy,"####")==0||strcmp(dummy,"$$$$")==0)
	{
		clrscr();
		textcolor(GREEN);
		textbackground(BLACK);
		cout<<"\n\n\n\n";
		for(int t=0;t<80;t++) cout<<'~';
		for(int y=0;y<80;y++) cout<<'*';
		cout<<"\n\n\t\t\tCOLLISION HAS OCCURED....!!\n\n";
		cout<<"\t      HOME ADDRESS IS: "<<addr<<" & ACTUAL ADDRESS IS: "<<i<<"\n";
		file.seekp(i*recsize*bucketsize,ios::beg);
		file<<buffer;
		textcolor(YELLOW);
		textbackground(BLACK);
		cout<<"\n\n\t\t   CUSTOMER RECORD IS INSERTED SUCCESSFULLY....!!\n\n";
		for(int u=0;u<80;u++) cout<<'*';
		cout<<"\n";
		for(int f=0;f<80;f++) cout<<'~';
		getch();
		flag=1;
		break;
	}
	file.seekg(i*recsize*bucketsize+recsize,ios::beg);
	file.getline(dummy,5,'\n');
	if(strcmp(dummy,"####")==0||strcmp(dummy,"$$$$")==0)
	{
		clrscr();
		textcolor(GREEN);
		textbackground(BLACK);
		cout<<"\n\n\n\n";
		for(int t=0;t<80;t++) cout<<'~';
		for(int y=0;y<80;y++) cout<<'*';
		cout<<"\n\n\t\t\tCOLLISION HAS OCCURED....!!\n\n";
		cout<<"\t      HOME ADDRESS IS: "<<addr<<" & ACTUAL ADDRESS IS: "<<i<<"\n";
		file.seekp(i*recsize*bucketsize+recsize,ios::beg);
		file<<buffer;
		textcolor(YELLOW);
		textbackground(BLACK);
		cout<<"\n\n\t\t   CUSTOMER RECORD IS INSERTED SUCCESSFULLY....!!\n\n";
		for(int u=0;u<80;u++) cout<<'*';
		cout<<"\n";
		for(int f=0;f<80;f++) cout<<'~';
		getch();
		flag=1;
		break;
	}
	file.seekg(i*recsize*bucketsize+(2*recsize),ios::beg);
	file.getline(dummy,5,'\n');
       if(strcmp(dummy,"####")==0||strcmp(dummy,"$$$$")==0)
	{
		clrscr();
		textcolor(GREEN);
		textbackground(BLACK);
		cout<<"\n\n\n\n";
		for(int t=0;t<80;t++) cout<<'~';
		for(int y=0;y<80;y++) cout<<'*';
		cout<<"\n\n\t\t\tCOLLISION HAS OCCURED....!!\n\n";
		cout<<"\t      HOME ADDRESS IS: "<<addr<<" & ACTUAL ADDRESS IS: "<<i<<"\n";
		file.seekp(i*recsize*bucketsize+(2*recsize),ios::beg);
		file<<buffer;
		textcolor(GREEN);
		textbackground(BLACK);
		cout<<"\n\n\t\t   CUSTOMER RECORD IS INSERTED SUCCESSFULLY....!!\n\n";
		for(int u=0;u<80;u++) cout<<'*';
		cout<<"\n";
		for(int f=0;f<80;f++) cout<<'~';
		getch();
		flag=1;
		break;
	}
}
}
if(i==addr && (flag!=1))
{
	clrscr();
	textcolor(YELLOW);
	textbackground(BLACK);
	cout<<"\n\n\n\n";
	for(int o=0;o<80;o++) cout<<'~';
	for(int a=0;a<80;a++) cout<<'*';
	cout<<setw(23)<<" "<<"\n\n\t*** HASH FILE IS FULL, CUSTOMER RECORD CAN'T BE INSERTED!! ***\n\n";
	for(int s=0;s<80;s++) cout<<'*';
	for(int d=0;d<80;d++) cout<<'~';
	getch();
}
getch();
file.close();
return;
}

void atm::unpack()
{
	char dummy[100];
	file.getline(name,12,'|');
	file.getline(entry_time,7,'|');
	file.getline(exit_time,7,'|');
	file.getline(type,5,'|');
	file.getline(dummy,100,'#');
}

int atm::retrieve(int addr,char k[],int l)  //search
{
int found=0,i;
char dummy[10];
i=addr;
file.open(datafile,ios::in);
cout<<setiosflags(ios::left);
//if(l==1)
do
{
	file.seekg(i*recsize*bucketsize,ios::beg);
	file.getline(dummy,5,'\n');
	if(strcmp(dummy,"####")==0)
		break;
	file.seekg(i*recsize*bucketsize,ios::beg);
	file.getline(dv_no,10,'|');
	if(strcmp(dv_no,k)==0)
	{
		found=1;
		if(l==1)
		{
		unpack();
		clrscr();
		textcolor(15);
	      textbackground(WHITE);
	   cout<<endl;
	   cout<<setw(18)<<" "<<"THE SEARCHED  RECORD IS DISPLAYED"<<endl<<endl;
	   for(int f=0;f<80;f++)   cout<<'*';   cout<<endl;
	   cout<<setw(20)<<" "<<"	ACCOUNT NUMBER		:  "<<setw(10)<<dv_no<<endl<<endl;
	   cout<<setw(20)<<" "<<"	NAME			:  "<<setw(10)<<name<<endl<<endl;
	   cout<<setw(20)<<" "<<" 	TIME OF ENTRY		:  "<<setw(5)<<entry_time<<endl<<endl;
	   cout<<setw(20)<<" "<<"	TIME OF EXIT		:  "<<setw(5)<<exit_time<<endl<<endl;
	   cout<<setw(20)<<" "<<"	ACCOUNT TYPE		:  "<<setw(5)<<type<<endl<<endl;
	   for(int g=0;g<80;g++) cout<<'*';
	   cout<<endl<<setw(25)<<" ";

	   cout<<" RECORD FOUND...!!"<<endl;
		}
		break;
	}
	file.seekg(i*recsize*bucketsize+recsize,ios::beg);
	file.getline(dv_no,10,'|');
	if(strcmp(dv_no,"#########")==0)
	      break;
	if(strcmp(dv_no,k)==0)
	{
		found=1;
		if(l==1)
		{
		unpack();
		clrscr();
		textcolor(15);
	      textbackground(BLUE);
	   cout<<endl;
	   cout<<setw(18)<<" "<<"THE SEARCHED  RECORD IS DISPLAYED"<<endl<<endl;
	   for(int f=0;f<80;f++)   cout<<'*';   cout<<endl;
	   cout<<setw(20)<<" "<<"	ACCOUNT NUMBER		:  "<<setw(10)<<dv_no<<endl<<endl;
	   cout<<setw(20)<<" "<<"	NAME			:  "<<setw(10)<<name<<endl<<endl;
	   cout<<setw(20)<<" "<<" 	TIME OF ENTRY		:  "<<setw(5)<<entry_time<<endl<<endl;
	   cout<<setw(20)<<" "<<"	TIME OF EXIT		:  "<<setw(5)<<exit_time<<endl<<endl;
	   cout<<setw(20)<<" "<<"	ACCOUNT TYPE		:  "<<setw(5)<<type<<endl<<endl;
	   for(int g=0;g<80;g++) cout<<'*';
	   cout<<endl<<setw(25)<<" ";

	cout<<" RECORD FOUND...!!"<<endl;
		}
		break;
	}

	file.seekg(i*recsize*bucketsize+(2*recsize),ios::beg);
	file.getline(dv_no,10,'|');
	if(strcmp(dv_no,"#########")==0)
	      break;
	if(strcmp(dv_no,k)==0)
	{
		found=1;
		if(l==1)
		{
		unpack();
		clrscr();
		textcolor(15);
	      textbackground(BLUE);
	   cout<<endl;
	   cout<<setw(18)<<" "<<"THE SEARCHED  RECORD IS DISPLAYED"<<endl<<endl;
	   for(int f=0;f<80;f++)   cout<<'*';   cout<<endl;
	   cout<<setw(20)<<" "<<"	ACCOUNT NUMBER		:  "<<setw(10)<<dv_no<<endl<<endl;
	   cout<<setw(20)<<" "<<"	NAME			:  "<<setw(10)<<name<<endl<<endl;
	   cout<<setw(20)<<" "<<" 	TIME OF ENTRY		:  "<<setw(5)<<entry_time<<endl<<endl;
	   cout<<setw(20)<<" "<<"	TIME OF EXIT		:  "<<setw(5)<<exit_time<<endl<<endl;
	   cout<<setw(20)<<" "<<"	ACCOUNT TYPE		:  "<<setw(5)<<type<<endl<<endl;
	   for(int g=0;g<80;g++) cout<<'*';
	   cout<<endl<<setw(25)<<" ";

	cout<<" RECORD FOUND...!!"<<endl;
		}
		break;
	}
	else
	{
		i++;
		if(i%max==0)
			i=0;
	}
}while(i!=addr);
if(found==0 && l==1)
{
		textcolor(15);
	      textbackground(RED);
	cout<<setw(23)<<" "<<"\n\n\t!!*** ENTERED CUSTOMER RECORD DOES NOT EXISTS IN HASH FILE ***!!\n\n";
	for(int h=0;h<80;h++) cout<<'~';
	for(int j=0;j<80;j++) cout<<'~';
	getch();
}
	/*if(l==0)
	    cout<<found<<endl;*/

return found ;
}

void atm::datadisp()
{
	file.open(datafile,ios::in);
	int i=0;
	char dummy[10];
	cout<<setiosflags(ios::left);
	while(i<max)
	{
	 if(file.eof())
		break;
	file.seekg(i*recsize*bucketsize,ios::beg);
	file.getline(dummy,5,'\n');
	if(strcmp(dummy,"####")!=0 && strcmp(dummy,"$$$$")!=0)
	{
		file.seekg(i*recsize*bucketsize,ios::beg);
		file.getline(dv_no,10,'|');
		unpack();
		clrscr();
	      //drawdoublelinebox(17,7,60,30);
	      textcolor(15);
	      textbackground(RED);
	   cout<<endl<<endl<<endl;
	   cout<<setw(25)<<" "<<"DISPLAYING CUSTOMER RECORDS"<<endl<<endl;
	   for(int i=0;i<80;i++)   cout<<'*';   cout<<endl;
	  cout<<setw(20)<<" "<<"	ACCOUNT NUMBER		:  "<<setw(10)<<dv_no<<endl<<endl;
	   cout<<setw(20)<<" "<<"	NAME			:  "<<setw(10)<<name<<endl<<endl;
	   cout<<setw(20)<<" "<<" 	TIME OF ENTRY		:  "<<setw(5)<<entry_time<<endl<<endl;
	   cout<<setw(20)<<" "<<"	TIME OF EXIT		:  "<<setw(5)<<exit_time<<endl<<endl;
	   cout<<setw(20)<<" "<<"	ACCOUNT TYPE		:  "<<setw(5)<<type<<endl<<endl;
	   for(int k=0;k<80;k++) cout<<'*';
	   cout<<endl<<endl<<setw(20)<<" ";
	   getch();

	}
	file.seekg(i*recsize*bucketsize+recsize,ios::beg);
	file.getline(dummy,5,'\n');
	if(strcmp(dummy,"####")!=0 && strcmp(dummy,"$$$$")!=0)
	{
		 file.seekg(i*recsize*bucketsize+recsize,ios::beg);
		file.getline(dv_no,10,'|');
		unpack();
	     clrscr();
		textcolor(15);
	      textbackground(RED);
	   cout<<endl<<endl<<endl;
	   cout<<setw(25)<<" "<<"DISPLAYING CUSTOMER RECORDS"<<endl<<endl;
	   for(int i=0;i<80;i++)   cout<<'*';   cout<<endl;
	 cout<<setw(20)<<" "<<"	ACCOUNT NUMBER		:  "<<setw(10)<<dv_no<<endl<<endl;
	   cout<<setw(20)<<" "<<"	NAME			:  "<<setw(10)<<name<<endl<<endl;
	   cout<<setw(20)<<" "<<" 	TIME OF ENTRY		:  "<<setw(5)<<entry_time<<endl<<endl;
	   cout<<setw(20)<<" "<<"	TIME OF EXIT		:  "<<setw(5)<<exit_time<<endl<<endl;
	   cout<<setw(20)<<" "<<"	ACCOUNT TYPE		:  "<<setw(5)<<type<<endl<<endl;
	   for(int k=0;k<80;k++) cout<<'*';
	   cout<<endl<<endl<<setw(20)<<" ";
	   getch();


	}
	file.seekg(i*recsize*bucketsize+(2*recsize),ios::beg);
	file.getline(dummy,5,'\n');
	if(strcmp(dummy,"####")!=0 && strcmp(dummy,"$$$$")!=0)
	{
		file.seekg(i*recsize*bucketsize+(2*recsize),ios::beg);
		file.getline(dv_no,10,'|');
		unpack();
		clrscr();
		textcolor(15);
	      textbackground(RED);
	   cout<<endl<<endl<<endl;
	   cout<<setw(25)<<" "<<"DISPLAYING CUSTOMER RECORDS"<<endl<<endl;
	   for(int i=0;i<80;i++)   cout<<'*';   cout<<endl;
	  cout<<setw(20)<<" "<<"	ACCOUNT NUMBER		:  "<<setw(10)<<dv_no<<endl<<endl;
	   cout<<setw(20)<<" "<<"	NAME			:  "<<setw(10)<<name<<endl<<endl;
	   cout<<setw(20)<<" "<<" 	TIME OF ENTRY		:  "<<setw(5)<<entry_time<<endl<<endl;
	   cout<<setw(20)<<" "<<"	TIME OF EXIT		:  "<<setw(5)<<exit_time<<endl<<endl;
	   cout<<setw(20)<<" "<<"	ACCOUNT TYPE		:  "<<setw(5)<<type<<endl<<endl;
	   for(int k=0;k<80;k++) cout<<'*';
	   cout<<endl<<setw(20)<<" ";
	   getch();
	}
	i++;
	}
	clrscr();
	textcolor(15);
	      textbackground(YELLOW);
	cout<<"\n\n\n\n\n\n\n\n\n\t\t=============================================\n"<<endl;
	cout<<"\t\t     !!*** NO RECORDS TO DISPLAY ***!!"<<endl;
	cout<<"\n\t\t=============================================\n"<<endl;
	getch();
	file.close();
}



int atm::remove(int addr,char k[])
{
int found=0,i;
char dummy[10];
i=addr;
int s;

file.open(datafile,ios::in|ios::out);
cout<<setiosflags(ios::left);
do
{
	file.seekg(i*recsize*bucketsize,ios::beg);
	file.getline(dummy,5,'\n');
	if(strcmp(dummy,"####")==0)
		break;
	file.seekg(i*recsize*bucketsize,ios::beg);
	file.getline(dv_no,10,'|');
	if(strcmp(dv_no,"#########")==0)
	      break;
	if(strcmp(dv_no,k)==0)
	{
		found=1;
		unpack();
		clrscr();
		textcolor(15);
	      textbackground(1);
	   cout<<endl<<endl;
	   cout<<setw(26)<<" "<<"CUSTOMER RECORD DISPLAYED"<<endl;
	   for(int l=0;l<80;l++)   cout<<'*';   cout<<endl;
	 cout<<setw(20)<<" "<<"	ACCOUNT NUMBER		:  "<<setw(10)<<dv_no<<endl<<endl;
	   cout<<setw(20)<<" "<<"	NAME			:  "<<setw(10)<<name<<endl<<endl;
	   cout<<setw(20)<<" "<<" 	TIME OF ENTRY		:  "<<setw(5)<<entry_time<<endl<<endl;
	   cout<<setw(20)<<" "<<"	TIME OF EXIT		:  "<<setw(5)<<exit_time<<endl<<endl;
	   cout<<setw(20)<<" "<<"	ACCOUNT TYPE		:  "<<setw(5)<<type<<endl<<endl;
	   for(int z=0;z<80;z++) cout<<'*';
	   cout<<endl<<setw(20)<<" ";

		textcolor(15);
	      textbackground(1);
		cout<<" RECORD TO BE DELETED IS FOUND"<<endl;
		file.seekp(i*recsize*bucketsize,ios::beg);
	      for(s=0;s<recsize;s++)
		   file.put('$');
		cout<<setw(25)<<" "<<"  RECORD IS DELETED... !!"<<endl;
		getch();
		file.close();
		break;
	}
	file.seekg(i*recsize*bucketsize+recsize,ios::beg);
	file.getline(dv_no,10,'|');
		if(strcmp(dv_no,"#########")==0)
		 break;
	if(strcmp(dv_no,k)==0)
	{
		found=1;
		unpack();
		clrscr();
		textcolor(15);
	      textbackground(1);
	   cout<<endl<<endl;
	   cout<<setw(26)<<" "<<"CUSTOMER RECORD DISPLAYED"<<endl;
	   for(int l=0;l<80;l++)   cout<<'*';   cout<<endl;
	   cout<<setw(20)<<" "<<"	ACCOUNT NUMBER		:  "<<setw(10)<<dv_no<<endl<<endl;
	   cout<<setw(20)<<" "<<"	NAME			:  "<<setw(10)<<name<<endl<<endl;
	   cout<<setw(20)<<" "<<" 	TIME OF ENTRY		:  "<<setw(5)<<entry_time<<endl<<endl;
	   cout<<setw(20)<<" "<<"	TIME OF EXIT		:  "<<setw(5)<<exit_time<<endl<<endl;
	   cout<<setw(20)<<" "<<"	ACCOUNT TYPE		:  "<<setw(5)<<type<<endl<<endl;
	   for(int z=0;z<80;z++) cout<<'*';
	   cout<<endl<<setw(20)<<" ";

		textcolor(15);
	      textbackground(1);
	cout<<" RECORD TO BE DELETED IS FOUND"<<endl;
		file.seekp(i*recsize*bucketsize+recsize,ios::beg);
	      for(s=0;s<recsize;s++)
		   file.put('$');
		cout<<setw(25)<<" "<<"  RECORD IS DELETED... !!"<<endl;
		getch();
		break;
	}

	file.seekg(i*recsize*bucketsize+(2*recsize),ios::beg);
	file.getline(dv_no,10,'|');
	if(strcmp(dv_no,k)==0)
	{
		found=1;
		unpack();
		clrscr();
		textcolor(15);
	      textbackground(1);
	   cout<<endl<<endl;
	   cout<<setw(26)<<" "<<"CUSTOMER RECORD IS DISPLAYED"<<endl;
	   for(int l=0;l<80;l++)   cout<<'*';   cout<<endl;
	   cout<<setw(20)<<" "<<"	ACCOUNT NUMBER		:  "<<setw(10)<<dv_no<<endl<<endl;
	   cout<<setw(20)<<" "<<"	NAME			:  "<<setw(10)<<name<<endl<<endl;
	   cout<<setw(20)<<" "<<" 	TIME OF ENTRY		:  "<<setw(5)<<entry_time<<endl<<endl;
	   cout<<setw(20)<<" "<<"	TIME OF EXIT		:  "<<setw(5)<<exit_time<<endl<<endl;
	   cout<<setw(20)<<" "<<"	ACCOUNT TYPE		:  "<<setw(5)<<type<<endl<<endl;
	   for(int z=0;z<80;z++) cout<<'*';
	   cout<<endl<<setw(20)<<" ";

		textcolor(15);
	      textbackground(1);
		cout<<" RECORD TO BE DELETED IS FOUND"<<endl;
		file.seekp(i*recsize*bucketsize+(2*recsize),ios::beg);
	       for(s=0;s<recsize-2;s++)
		   file.put('$');
		   file.put('\n');
		cout<<setw(25)<<" "<<"  RECORD IS DELETED... !!"<<endl;
		getch();
		break;
	}
	else
	{
		i++;
		if(i%max==0)
			i=0;
	}
}while(i!=addr);
if(found==0)
{
	textcolor(15);
	      textbackground(1);
	cout<<setw(23)<<" "<<"\n\n\t!!*** ENTERED  RECORD DOES NOT EXISTS IN HASH FILE ***!!\n\n";
	for(int k=0;k<80;k++) cout<<'^';
	for(int j=0;j<80;j++) cout<<'^';
	getch();
}
return found;
}

void atm::modify(int addr, char k[])
{
int found=0,i;
char dummy[10];
i=addr;
int s;
int x;

file.open(datafile,ios::in|ios::out);
cout<<setiosflags(ios::left);
do
{
	file.seekg(i*recsize*bucketsize,ios::beg);
	file.getline(dummy,5,'\n');
	if(strcmp(dummy,"####")==0)
		break;
       file.seekg(i*recsize*bucketsize,ios::beg);
	file.getline(dv_no,10,'|');
	if(strcmp(dv_no,k)==0)
	{
		found=1;
		unpack();
		clrscr();
		textcolor(YELLOW);
	      textbackground(0);
	   cout<<endl;
	   cout<<setw(18)<<" "<<" RECORD TO BE MODIFIED IS DISPLAYED"<<endl<<endl;
	   for(int c=0;c<80;c++)   cout<<'*';   cout<<endl;
	  cout<<setw(20)<<" "<<"	ACCOUNT NUMBER		:  "<<setw(10)<<dv_no<<endl<<endl;
	   cout<<setw(20)<<" "<<"	NAME			:  "<<setw(10)<<name<<endl<<endl;
	   cout<<setw(20)<<" "<<" 	TIME OF ENTRY		:  "<<setw(5)<<entry_time<<endl<<endl;
	   cout<<setw(20)<<" "<<"	TIME OF EXIT		:  "<<setw(5)<<exit_time<<endl<<endl;
	   cout<<setw(20)<<" "<<"	ACCOUNT TYPE		:  "<<setw(5)<<type<<endl<<endl;
	   for(int v=0;v<80;v++) cout<<'*';
	   cout<<endl<<setw(20)<<" ";

		textcolor(YELLOW);
	      textbackground(0);
		cout<<" RECORD TO BE MODIFIED IS FOUND"<<endl;
		getch();
		file.seekp(i*recsize*bucketsize,ios::beg);
	      for(s=0;s<recsize;s++)
		   file.put('$');
		  cout<<"\t\t\tRECORD DELETED...!!"<<endl;
		  getch();
		   file.close();
		clrscr();
		textcolor(15);
	      textbackground(1);
		cout<<"\n";
		for(int b=0;b<80;b++) cout<<'~';
		for(int n=0;n<80;n++) cout<<'*';
		  cout<<"\t\t\tENTER THE NEW CUSTOMER RECORD: \n";
		  getch();
		read();
		x=hash(dv_no);
		store(x);

		cout<<"\t\t    RECORD IS MODIFIED SUCCESSFULLY...!!\n";
		getch();
		break;
	}
	file.seekg(i*recsize*bucketsize+recsize,ios::beg);
	file.getline(dv_no,10,'|');
	if(strcmp(dv_no,"#########")==0)
	      break;

	if(strcmp(dv_no,k)==0)
	{
		found=1;
		unpack();
		clrscr();
		textcolor(YELLOW);
	      textbackground(0);
	   cout<<endl;
	   cout<<setw(18)<<" "<<" RECORD TO BE MODIFIED IS DISPLAYED"<<endl<<endl;
	   for(int c=0;c<80;c++)   cout<<'*';   cout<<endl;
	  cout<<setw(20)<<" "<<"	ACCOUNT NUMBER		:  "<<setw(10)<<dv_no<<endl<<endl;
	   cout<<setw(20)<<" "<<"	NAME			:  "<<setw(10)<<name<<endl<<endl;
	   cout<<setw(20)<<" "<<" 	TIME OF ENTRY		:  "<<setw(5)<<entry_time<<endl<<endl;
	   cout<<setw(20)<<" "<<"	TIME OF EXIT		:  "<<setw(5)<<exit_time<<endl<<endl;
	   cout<<setw(20)<<" "<<"	ACCOUNT TYPE		:  "<<setw(5)<<type<<endl<<endl;
	   for(int v=0;v<80;v++) cout<<'*';
	   cout<<endl<<setw(20)<<" ";

		 textcolor(YELLOW);
	      textbackground(0);
		cout<<" RECORD TO BE MODIFIED IS FOUND"<<endl;
		getch();
		file.seekp(i*recsize*bucketsize+recsize,ios::beg);
	      for(s=0;s<recsize;s++)
		   file.put('$');
		cout<<"\t\t\tRECORD DELETED...!!"<<endl;
		  getch();
		   file.close();
		clrscr();
		textcolor(15);
	      textbackground(1);
		cout<<"\n";
		for(int b=0;b<80;b++) cout<<'~';
		for(int n=0;n<80;n++) cout<<'*';
		  cout<<"\t\t\tENTER THE NEW CUSTOEMR RECORD: \n";
		  getch();
		read();
		x=hash(dv_no);
		store(x);

		cout<<"\t\t    RECORD IS MODIFIED SUCCESSFULLY...!!\n";
		getch();
		break;
	}

	file.seekg(i*recsize*bucketsize+(2*recsize),ios::beg);
	file.getline(dv_no,10,'|');
	if(strcmp(dv_no,"#########")==0)
	      break;

	if(strcmp(dv_no,k)==0)
	{
		found=1;
		unpack();
		clrscr();
		textcolor(YELLOW);
	      textbackground(0);
	   cout<<endl;
	   cout<<setw(18)<<" "<<" RECORD TO BE MODIFIED IS DISPLAYED"<<endl<<endl;
	   for(int c=0;c<80;c++)   cout<<'*';   cout<<endl;
	   cout<<setw(20)<<" "<<"	ACCOUNT NUMBER		:  "<<setw(10)<<dv_no<<endl<<endl;
	   cout<<setw(20)<<" "<<"	NAME			:  "<<setw(10)<<name<<endl<<endl;
	   cout<<setw(20)<<" "<<" 	TIME OF ENTRY		:  "<<setw(5)<<entry_time<<endl<<endl;
	   cout<<setw(20)<<" "<<"	TIME OF EXIT		:  "<<setw(5)<<exit_time<<endl<<endl;
	   cout<<setw(20)<<" "<<"	ACCOUNT TYPE		:  "<<setw(5)<<type<<endl<<endl;
	   for(int v=0;v<80;v++) cout<<'*';
	   cout<<endl<<setw(20)<<" ";

		textcolor(YELLOW);
	      textbackground(0);
		cout<<"RECORD TO BE MODIFIED IS FOUND"<<endl;
		getch();
		file.seekp(i*recsize*bucketsize+(2*recsize),ios::beg);
	       for(s=0;s<recsize-2;s++)
		   file.put('$');
		   file.put('\n');
		  cout<<"\t\t\tRECORD DELETED...!!"<<endl;
		  getch();
		   file.close();
		clrscr();
		textcolor(15);
	      textbackground(1);
		cout<<"\n";
		for(int b=0;b<80;b++) cout<<'~';
		for(int n=0;n<80;n++) cout<<'*';
		  cout<<"\t\t\tENTER THE NEW  RECORD: \n";
		  getch();
		read();
		x=hash(dv_no);
		store(x);

		cout<<"\t\t    RECORD IS MODIFIED SUCCESSFULLY...!!\n";
		getch();
		break;
	}
	else
	{
		i++;
		if(i%max==0)
			i=0;
	}
}while(i!=addr);
if(found==0)
{
	textcolor(15);
	      textbackground(1);
	cout<<setw(23)<<" "<<"\n\n\t!!*** ENTERED CUSTOMER RECORD DOES NOT EXISTS IN HASH FILE ***!!\n\n";
	for(int k=0;k<80;k++) cout<<'=';
	for(int j=0;j<80;j++) cout<<'^';
	getch();
}
}



/*Douoblebox design*/

void drawdoublelinebox(int x,int y,int len,int bdt)
{
	gotoxy(x,y);
	cprintf("ษ");
		gotoxy(x,y+bdt);
	cprintf("ศ");
	gotoxy(x+len,y);
	cprintf("ป");
	gotoxy(x+len,y+bdt);
	cprintf("ผ");
	for(int i=x+1;i<x+len;i++)
	{
		gotoxy(i,y);
		cprintf("อ");
		gotoxy(i,y+bdt);
		cprintf("อ");
	}
	for(int j=y+1;j<y+bdt;j++)
	{
		gotoxy(x,j);
		cprintf("บ");
		gotoxy(x+len,j);
		cprintf("บ");
			}
}

/*Double box design*/

void drawsinglelinebox(int x,int y,int len,int bdt)
{                                            // (x,y) : co.ord. of 1st tip
	gotoxy(x,y);                         // len : length of box
	cprintf("ฺ");                        // bdt : breadth of box
	gotoxy(x,y+bdt);
	cprintf("ภ");
	gotoxy(x+len,y);
	cprintf("ฟ");
	gotoxy(x+len,y+bdt);
	cprintf("ู");

	for(int i=x+1;i<x+len;i++)
	{
		gotoxy(i,y);
		cprintf("ฤ");
		gotoxy(i,y+bdt);
		cprintf("ฤ");
	}
	for(int j=y+1;j<y+bdt;j++)
	{
		gotoxy(x,j);
		cprintf("ณ");
		gotoxy(x+len,j);
		cprintf("ณ");
	}
}
void normal()  // to obtain normal background
{
      //	textattr(WHITE); // textattr sets text attributes for text-window functions
       //	textcolor(WHITE);// textcolor selects a new character color in text mode
	textbackground(GREEN);//textbackground selects a new text background color
      //	_setcursortype(_NORMALCURSOR); /* sets cursor type to normal underscore type cursor  */
	//return;
}

void screen()
{
 int g=19,h=10;

    textbackground(BLUE);
     gotoxy(24,3);
     textcolor(BLACK);
     cprintf("     ATM MANAGEMENT SYSTEM      ");
     gotoxy(24,4);
     textcolor(15);
     cprintf(" อออออออออออออออออออออออออออออ ");
     drawdoublelinebox(17,7,44,14);
     gotoxy(28,7);
     textbackground(YELLOW);
	 textcolor(WHITE);
	 cprintf("  MAIN    MENU " );
     normal();
     textcolor(15);
     gotoxy(g,h++);
     cout<<"	     1. CUSTOMER PORTAL";
     gotoxy(g,h++);
     cout<<"	     2. MANAGER PORTAL";
     gotoxy(g,h++);
     cout<<"	     3. EXIT";
     gotoxy(g,h++);
     gotoxy(g,h++);
     gotoxy(g,h++);
     normal();
}


void main()
{
int ch,addr,l,choice;
char sv_no[10];
atm f;
f.initial();
clrscr();
do
{
	screen();
	cout<<"     ENTER YOUR CHOICE  :  ";
	cin>>ch;
	switch(ch)
	{
	case 1:clrscr();
		cout<<"\n";
		for(int b=0;b<80;b++) cout<<'~';
		cout<<setw(24)<<" "<<"ENTER THE CUSTOMER  DETAILS \n";
		for(int h=0;h<80;h++) cout<<'~';
		cout<<"\n";
		getch();
	 LABEL: f.read();
		addr=hash(f.dv_no);
		store(addr);
		getch();
		file.close();
		clrscr();
		break;
	case 2:do
	      {
	      clrscr();
	      drawdoublelinebox(17,7,44,14);
	     textcolor(0);
	      textbackground(15);
		  clrscr();
	       //	  textbackground(BLACK);
	      gotoxy(25,3);
	      //textcolor(YELLOW);
	      cprintf("        CUSTOMER RECORDS       ");
	      gotoxy(25,4);
	      cprintf(" ออออออออออออออออออออออออออออ ");
	      int z=19,q=10;
	      textcolor(YELLOW);
	      drawdoublelinebox(17,7,44,14);
	      gotoxy(28,7);
	     textbackground(RED);
	      textcolor(WHITE);
	      cprintf("  MAIN    MENU " );
	      normal();
	     textcolor(YELLOW);
	      gotoxy(z,q++);
	      cout<<"     1.  SEARCH CUSTOMER RECORD";
		  gotoxy(z,q++);
	      cout<<"     2.  DISPLAY CUSTOMER DETAILS";
	      gotoxy(z,q++);
	      cout<<"     3.  DELETE CUSTOMER RECORD";
	      gotoxy(z,q++);
		  cout<<"     4.  MODIFY CUSTOMER DETAILS";
	      gotoxy(z,q++);
	      cout<<"     5.  QUIT";
	      gotoxy(z,q++);
	      gotoxy(z,q++);
	      gotoxy(z,q++);
	      cout<<"     ENTER YOUR CHOICE [1-5]  : ";
	      cin>>choice;
	 switch(choice)
	 {

	 case 1:clrscr();
		textcolor(15);
		textbackground(YELLOW);
		cout<<"\n\n\n\n";
		cout<<"\t\t\t  SEARCHING  RECORD\n\n";
		for(int e=0;e<80;e++) cout<<'~';
		//cout<<"\n";
		for(int w=0;w<80;w++) cout<<'~';
		cout<<"\n";
		cout<<setw(20)<<" "<<"ENTER THE ACCOUNT NUMBER TO BE SEARCHED: "<<endl;
		cout<<setw(36)<<" ";
		cin>>sv_no;
		cout<<"\n";
		addr=hash(sv_no);
		f.retrieve(addr,sv_no,1);
		getch();
		file.close();
		break;
	case 2://cout<<"vehicle details:"<<endl;
		textcolor(15);
	      textbackground(RED);
	       f.datadisp();
	       file.close();
		break;
       case 3://p.del();
		clrscr();
		textcolor(15);
	      textbackground(1);
		cout<<"\n\n\n\n";
		cout<<"\t\t\t  DELETING CUSTOMER RECORD\n\n";
		for(int x=0;x<80;x++) cout<<'^';
		//cout<<"\n";
		for(int y=0;y<80;y++) cout<<'^';
		cout<<"\n";
		cout<<setw(20)<<" "<<"ENTER THE ACCOUNT NUMBER TO BE DELETED: "<<endl;
		cout<<setw(36)<<" ";
		cin>>sv_no;
		cout<<"\n";
		addr=hash(sv_no);
		f.remove(addr,sv_no);
		getch();
		file.close();
		break;
       case 4:clrscr();
		textcolor(15);
	      textbackground(1);
		cout<<"\n\n\n\n";
		cout<<"\t\t\t  MODIFYING CUSTOMER RECORD\n\n";
		for(int u=0;u<80;u++) cout<<'=';
		//cout<<"\n";
		for(int r=0;r<80;r++) cout<<'^';
		cout<<"\n";
		cout<<setw(20)<<" "<<"ENTER THE CUSTOMER RECORD TO BE MODIFIED: \n";
		cout<<setw(36)<<" ";
		cin>>sv_no;
	      addr=hash(sv_no);
		cout<<"\n";
	      f.modify(addr,sv_no);
		getch();
	     file.close();
	      break;
	case 5:clrscr();
		screen();
			 break;
	default:sound(600);delay(500);nosound();
		break;
	}
	}while(choice!=5);   break;

case 3:exit(0);

default: sound(100);delay(500);nosound(); break;
}
}while(ch!=3);

       file.close();
}



