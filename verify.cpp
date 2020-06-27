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
// class Student
// {
// char dusn[15],name[20],age[5],branch[5],sem[5];
// public:
// void read();
// void pack();
// int search(char*);
// void recDisp(int);
// void remove(int);
// void dataDisp();
// void unpack();
// };
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
void opener(fstream &sfile,char * fn,std::_Ios_Openmode mode)
{
sfile.open(fn,mode);
if(!sfile)
{
cout<<"Unable to open the file\n";
exit(1);
}
}
// function to write
void index::write()
{
opener(indfile,indexfile,ios::out);
for(i=0;i<indsize;i++)
indfile<<id[i].iusn<<"|"<<id[i].addr<<"\n";
indfile.close();
}
// function to read

// function to pack
// void Student::pack()
// {
// strcpy(buffer,dusn);
// strcat(buffer,"|");
// strcat(buffer,name);
// strcat(buffer,"|");
// strcat(buffer,age);
// strcat(buffer,"|");
// strcat(buffer,branch);
// strcat(buffer,"|");
// strcat(buffer,sem);
// strcat(buffer,"|");
// }
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

int main( int argc,char *argv[])
{
    char id[15];

int ch,pos,flag;
char susn[15];
//Student S;
in.initial();
char *tid=argv[1];
int k;
strcpy(id,tid);
if(search(id)>=0)
{
cout<<"1";
}
// for(i=indsize;i>0;i--)
// {
// if(strcmp(dusn,id[i-1].iusn)<0)
// id[i]=id[i-1];
// else
// break;
// }
// opener(stdfile,datafile,ios::app);
// cout<<"Enter the Name\n";
// cin>>name;
// cout<<"Enter the age\n";
// cin>>age;
// cout<<"Enter the branch\n";
// cin>>branch;
// cout<<"Enter the semester\n";
// cin>>sem;
// pack();
// stdfile.seekg(0,ios::end);
// k=stdfile.tellg();
// stdfile<<buffer<<endl;
// strcpy(id[i].iusn,dusn);
// sprintf(id[i].addr,"%d",k);
// indsize++;
// //read();
// in.write();

stdfile.close();

}