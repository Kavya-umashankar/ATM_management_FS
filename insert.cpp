#include<iostream>
#include<fstream>
#include<conio.h>
#include<stdio.h>
#include<iomanip>
#include<stdlib.h>
#include<string.h>
#include<cstdlib>
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
char iid[15],addr[5];
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
indfile.getline(id[indsize].iid,15,'|');
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
indfile<<id[i].iid<<"|"<<id[i].addr<<"\n";
indfile.close();
}

int  search(char *fusn)
{
int low=0,high=indsize-1;
int mid;
while(low<=high)
{
mid=(low+high)/2;
if(strcmp(fusn,id[mid].iid)==0)
return mid;
else if(strcmp(fusn,id[mid].iid)>0)
low=mid+1;
else
high=mid-1;
}
return -1;
}

int main(int argc,char * argv[])
{
    //cout<<"hello";
    char tid[15],accno[15],name[20],acctype[30],balance[10];

int ch,pos,flag;
char susn[15];
//Student S;
in.initial();

//char * tid1=argv[1];
char * accno1=argv[1];
char * name1=argv[2];
char * acctype1=argv[3];
char * balance1= argv[4];


//strcpy(tid,tid1);
strcpy(accno,accno1);
strcpy(name,name1);
strcpy(acctype,acctype1);
strcpy(balance,balance1);


//int k;

for(i=indsize;i>0;i--)
{
if(strcmp(tid,id[i-1].iid)<0)
id[i]=id[i-1];
else
break;
}
opener(stdfile,datafile,ios::app);

//strcpy(buffer,tid);
//strcat(buffer,"|");
strcat(buffer,accno);
strcat(buffer,"|");
strcat(buffer,name);
strcat(buffer,"|");
strcat(buffer,acctype);
strcat(buffer,"|");
strcat(buffer,balance);
strcat(buffer,"|");


//S.pack();
stdfile.seekg(0,ios::end);
int k;
k=stdfile.tellg();
stdfile<<buffer<<endl;
strcpy(id[i].iid,accno);
sprintf(id[i].addr,"%d",k);
indsize++;in.write();

stdfile.close();

}
