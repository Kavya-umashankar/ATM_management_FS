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
void remove(int pos)
{
opener(stdfile,datafile,ios::in|ios::out);
stdfile.seekg(atoi(id[pos].addr),ios::beg);
stdfile.put('$');
for(i=pos;i<indsize;i++)
id[i]=id[i+1];
indsize--;
}

int main(int argc,char *argv[])
{
int ch,pos,flag;
char susn[15];
in.initial();
char *tid=argv[1];
strcpy(susn,tid);
pos=search(susn);
if(pos==-1)
cout<<"1";
else
{
remove(pos);
in.write();
}


}