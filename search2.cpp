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
void opener(fstream &sfile,char * fn,std::_Ios_Openmode mode)
{
sfile.open(fn,mode);
if(!sfile)
{
cout<<"Unable to open the file\n";
exit(1);
}
}
void unpack()
{
stdfile.getline(buffer,100,'\n');
i=0;
if(buffer[i]!='$')
{
cout<<"\n";
cout<<"|";
while(buffer[i]!='\0')
{
if(buffer[i]=='|')
cout<<"|";
else
cout<<buffer[i];
 i++;
}
}
}


void recDisp(int pos)
{
opener(stdfile,datafile,ios::in);
stdfile.seekg(atoi(id[pos].addr),ios::beg);
cout<<"||\n\n";
 cout<<"|"<<setw(10)<<"acc no"<<"|"<<setw(10)<<"Name"<<"|"<<setw(10)<<"account type"<<"|"<<"balance";
 unpack();
}

int  search(char *fusn)
{
int low=0,high=indsize-1;
int mid;
while(low<=high)
{
mid=(low+high)/2;
if(strcmp(fusn,id[mid].iusn)==0)
return mid;
else if(strcmp(fusn,id[mid].iusn)>0)
low=mid+1;
else
high=mid-1;
}
return -1;
}

int main(int argc,char *argv[])
{
int ch,pos,flag;
char susn[15];
in.initial();
char * tid=argv[1];
strcpy(susn,tid);

flag=search(susn);
if(flag==-1)
cout<<"Record Not found\n";
else
recDisp(flag);


}