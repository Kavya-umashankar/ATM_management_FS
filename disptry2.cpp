#include<iostream>
#include<fstream>
#include<conio.h>
#include<stdio.h>
#include<iomanip>
#include<stdlib.h>
#include<string.h>
#define max 10
#define datafile "custmain.txt"
#define indexfile "c1index.txt"
using namespace std;
fstream stdfile, indfile;
int i,indsize;
char buffer[80];
class index
{
public:
char iusn[15],addr[5];
void initial();
void write();
}in,id[max];
void index::initial()
{
indfile.open(indexfile,ios::in);
if(!indfile)
{
indsize=0;
return;
}
for(indsize=0;;indsize++)
{
indfile.getline(id[indsize].iusn,15,'|');
indfile.getline(id[indsize].addr,5,'\n');
if(indfile.eof())
break;
}
indfile.close();
}
// function to open file

// function to write



void opener(fstream &sfile,char * fn,std::_Ios_Openmode mode)
{
sfile.open(fn,mode);
if(!sfile)
{
cout<<"Unable to open the file\n";
exit(1);
}
}
void dataDisp()
{
int count;

cout<<setiosflags(ios::left);
//cout<<"|"<<setw(15)<<"Transaction id     "<<"|"<<setw(10)<<"acc no"<<"|"<<setw(10)<<"Name"<<"|"<<setw(10)<<"entry time"<<"|"<<setw(10)<<"exit time"<<"|"<<setw(10)<<"withdraw"<<"|"<<setw(10)<<"deposit"<<"|"<<setw(10)<<"account type"<<"|"<<"Balance|";
while(1)
{
	// unpack();
	stdfile.getline(buffer,100,'\n');
	count=0;
	i=0;
	if(buffer[i]!='$')
	{
		
		cout<<"\n";
		cout<<"|";
		
		while(buffer[i]!='\0')
		{
			if(buffer[i]=='|')
			{
				cout<<"|";
			}
			else
			{
				cout<<buffer[i];
			}
			
			
			i++;
		}
	}
	if(stdfile.eof())
	break;
}
}
// function to unpack
void unpack()
{
stdfile.getline(buffer,100,'\n');
i=0;
if(buffer[i]!='$')
{
cout<<"\n";
while(buffer[i]!='\0')
{
if(buffer[i]=='|')
cout<<"\t\t\t";
else
cout<<buffer[i];
 i++;
}
}
}




int main()
{
int ch,pos,flag;
char susn[15];
in.initial();
opener(stdfile,datafile,ios::in);
cout<<endl<<"\n";
dataDisp();
cout<<"|---| Index File: |";
cout<<endl<<"| Index file details are:| \n";
cout<<setw(10)<<"| T_ID |"<<setw(10)<<"Address|";
for(i=0;i<indsize;i++)
{
cout<<endl<<"|"<<setw(10)<<id[i].iusn<<"|"<<setw(10)<<id[i].addr<<endl;
}

}
