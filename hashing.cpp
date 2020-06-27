#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<fstream>
#include<iostream>
using namespace std;
class node
{
public:
char tid1[15],accno1[15],name1[20],entry1[20],exit1[20],with1[20],deposit1[10],acctype1[30];
node *link;
};
node *h[29]; //Array of record pointers
//equal to size of hash keys--29
class atm
{
public:
char tid[15],accno[15],name[20],entry[20],exitr[20],with[20],deposit[10],acctype[30];
char buffer[25];
int count ;

void insert();
void hash_insert();
void retrive(char * key);
};
void atm::insert()
{
fstream out;
out.open("hash.txt",ios::out|ios::app);


strcpy(buffer,tid);
strcat(buffer,"|");
strcat(buffer,accno);
strcat(buffer,"|");
strcat(buffer,name);
strcat(buffer,"|");
strcat(buffer,entry);
strcat(buffer,"|");
strcat(buffer,exitr);
strcat(buffer,"|");
strcat(buffer,with);
strcat(buffer,"|");
strcat(buffer,deposit);
strcat(buffer,"|");
strcat(buffer,acctype);
strcat(buffer,"|");
strcat(buffer,"\n");


out<<buffer;
out.close();
}
//Insert record into the hash table
void atm::hash_insert()
{
node *p,*prev,*curr;
p=new node;
strcpy(p->tid1,tid);
strcpy(p->accno1,accno);
strcpy(p->name1,name);
strcpy(p->entry1,entry);
strcpy(p->exit1,exitr);
strcpy(p->with1,with);
strcpy(p->deposit1,deposit);
strcpy(p->acctype1,acctype);
p->link=NULL;
prev=NULL;
curr=h[count]; //getting the hash pointer location
if(curr==NULL) // Case: No collision
{
h[count]=p;
return;
}
while(curr!=NULL) // Case : On collision -- Insert at rear end
{
prev=curr;
curr=curr->link;
}
prev->link=p;
}
void atm::retrive(char* key)
{
fstream in;
int j;
node *curr;
in.open("hash.txt",ios::in);
while(!in.eof())
{
in.getline(tid,15,'|');
in.getline(accno,15,'|');
in.getline(name,20,'|');
in.getline(entry,20,'|');
in.getline(exitr,20,'|');
in.getline(with,10,'|');
in.getline(deposit,10,'|');
in.getline(acctype,20,'|');

count=0;
for(j=0;j<strlen(tid);j++)
{
count=count+tid[j];
}
count=count%29; // Hash Key = ASCII count% 29
hash_insert();
}

//cout<<"\nEnter the usn = ";
cout<<"key"<<key;
count=0;
for(j=0;j<strlen(key);j++) // Calculating Hash Key
count=count+key[j];
count=count%29;
curr=h[count];
while(curr!=NULL && strcmp(curr->tid1,key)!=0)
{
 curr=curr->link;
}
if(strcmp(curr->tid1,key)==0)
{
cout<<"\n\nRecord found : "<<curr->tid1<<" "<<curr->accno1<<" "<<curr->name1<<" "<<curr->entry1<<" "<<curr->exit1<<" "<<curr->with1<<" "<<curr->deposit1<<" "<<curr->acctype1;
return;
}
if(curr==NULL) //End of list reached with no record found
{
cout<<"\nRecord not found";
return;
}
}
int main()
{
/*
char tid2[15],accno2[15],name2[20],entry2[20],exit2[20],with2[10],deposit2[10],acctype2[10];
cout<<"enter the transacction id (10 digit): "<<endl;
cin>>tid2;
cout<<"enter the account number (10 digit): "<<endl;
cin>>accno2;
cout<<"entry time= "<<endl;
cin>>entry2;
cout<<"exit time= "<<endl;
cin>>exit2;
cout<<"enter the amount withdrawn(if deposit thwn enter 0): "<<endl;
cin>>with2;
cout<<"enter thhe amount deposited : "<<endl;
cin>>deposit2;
cout<<"enter the type of account(saving/current) : "<<endl;
cin>>acctype2;
*/

char * tid2=_argv[1];
char * accno2=_argv[2];
char * name2=_argv[3];
char * entry2=_argv[4];
char * exit2=_argv[5];
char * with2=_argv[6];
char * deposit2=_argv[7];
char * acctype2=_argv[8];
atm s;
strcpy(s.tid,tid2);
strcpy(s.accno,accno2);
strcpy(s.name,name2);
strcpy(s.entry,entry2);
strcpy(s.exitr,exit2);
strcpy(s.with,with2);
strcpy(s.deposit,deposit2);
strcpy(s.acctype,acctype2);
s.insert();
s.retrive(tid2);
}