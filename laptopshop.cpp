#include<stdio.h>  //arjinder.20858@lpu.co.in
#include<conio.h>
#include<iostream>
#include<cstring>
#include<fstream>
#include<windows.h>
#include<dos.h>
#define ENTER 13
#define BKSP 8
#define TAB 9
#define SP 32
using namespace std;


class laptop
{  long int lapid;
    char lapname[20],prob[100];
    int model_no;
    long int cont;
    public:
    	laptop()
    	{lapid=0,strcpy(lapname,"no-name");
    	 model_no=0; cont=00; 
		}
		void getlaptopdata()
		      { cout<<"enter lapid ,lapname,model_no and contact number";
		        cin>>lapid;
		        cin.ignore();
		        cin.getline(lapname,19);
		        cin>>model_no;
		        cin>>cont;
		        cout<<"enter problems using commas";
		        cin.ignore();
		        cin.getline(prob,50);
		    
			  }
       
	    void showlaptopdata()
               {  cout<<" "<<lapid<<ends<<lapname<<ends<<model_no<<ends<<cont<<ends<<prob; 
               cout<<endl;
			   }
		int storelaptop();
	void viewalllaptop();
	void searchlaptop(char*);
	void deletelaptop(char*);
	void updatelaptop(char*);			   
};
void laptop::viewalllaptop()
{     ifstream fin;
   fin.open("file3.txt",ios::in|ios::binary);
   if(!fin)
	     {  cout<<"file not found";
		 }
   else
       {   
       fin.read((char*)this,sizeof(*this));
       while(!fin.eof()){
       showlaptopdata();
        fin.read((char*)this,sizeof(*this));}
	   fin.close();
 }
}
int laptop::storelaptop()
{   if(lapid==0 &&model_no==0) 
{   cout<<"laptop data not entered";
return 0;
}
else{
   ofstream fout;
    fout.open("file3.txt",ios::app|ios::binary);
    fout.write((char*)this,sizeof(*this));
    fout.close();
    return 1;
}}
void laptop::searchlaptop(char*t)
{    

  ifstream fin;
fin.open("file3.txt",ios::in|ios::binary);

if(!fin)
{ cout<<"file not found";
}
else{
  fin.read((char*)this,sizeof(*this));
while(!fin.eof()){ 
		  if(strcmp(t,lapname)==0)
                  {  showlaptopdata();
                      
                     fin.read((char*)this,sizeof(*this)); 
					               
				   	}  fin.read((char*)this,sizeof(*this)); 
					    }
fin.close();
}
}
void laptop::deletelaptop(char *t)
{    ifstream fin;
ofstream fout;
fin.open("file3.txt",ios::in|ios::binary);
if(!fin)
{   cout<<"file does not found";

  }
  else{   
   fout.open("temp.txt",ios::out|ios::binary);
   fin.read((char*)this,sizeof(*this));
   while(!fin.eof()){
   
            if(strcmp(lapname,t))
			         {
						   fout.write((char*)this,sizeof(*this));
                          fin.read((char*)this,sizeof(*this));
                          cout<<"\ndone";
                          
                 }
                 fin.read((char*)this,sizeof(*this));
                  
                    
					  
				}
					  fin.close();
					  fout.close();
					  
					  remove("file3.txt");
					  
					  rename("temp.txt","file3.txt");
					  cout<<"done";
			  }
}

void laptop::updatelaptop( char *t)
{    fstream file;
file.open("file3.txt",ios::in|ios::out|ios::ate|ios::binary);
file.seekg(0);
file.read((char*)this,sizeof(*this));
  while(!file.eof()){  
                    if(!strcmp(t,lapname)){ getlaptopdata();
                      file.seekp(file.tellp()-sizeof(*this));
                      file.write((char*)this,sizeof(*this));  
					  }  
					  file.read((char*)this,sizeof(*this));    }
}
gotoxy(int x,int y)
{
  COORD coord;
coord.X=x;
coord.Y=y;
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
int menu()
{   
int choice;
gotoxy(39,5);
cout<<" Laptop Repair Shop\n";
gotoxy(20,10);
cout<<" 1 enter laptop data\n";
gotoxy(20,15);
cout<<" 2 view all laptop record\n";
gotoxy(60,10);
cout<<" 3 search laptop record\n";
gotoxy(60,15);
cout<<" 4 delete laptop record\n";
gotoxy(60,20);
cout<<" 5 update laptop record\n";
cin>>choice;
/*
Beep(349,500);
Beep(523.25,500);
Beep(587.33,500);
Beep(659.25,500);
Beep(783.99,500);
Beep(698.46,500);
Beep(880.00,500);
Beep(987.77,500);
Beep(1000,500);
Beep(400,500);
*/
return choice;
}
int passcode()
{ char password[30],ch,eh,password1[30]="arjinder";
 int i=0,j;
 gotoxy(40,15);
 cout<<"Enter Password";
 while(1)
 {  ch=getch();
    if(ch==ENTER)
         {  password[i]='\0'; 
		 break;
		 }
		 else if(ch==BKSP)
		    {  if(i>0)
		        { i--;
		           cout<<"\b \b";
				}
			}
			else if(ch==SP || ch==TAB)
			 {  continue;
			 }
			 else
			 { password[i]=ch;
			 i++;
			 cout<<"*";}
 }
 if(strcmp(password,password1)==0)
 {  system("cls");
 return 1;
 }
 else {
 	system("color 4");
 	Beep(1000,500); Beep(1000,500);
 cout<<"wrong password";
  return 0;
 }
}
int main()
  {	char laptopname[19];
  int j;
  	laptop b1;
  system("color 02");	
int c=passcode();
if(c==0)
{Beep(523,500);
}
else {
label:
	system("cls");
Beep(587,500);
int c=menu();

   if(c==1)
         {   Beep(659,500); 
		 b1.getlaptopdata();  
		  b1.storelaptop();
		 }
		 else if(c==2)
		  { Beep(698,500);
		   b1.viewalllaptop();
		  }
		  else if(c==3)
		  {Beep(784,500);  
		   gets(laptopname);
		   Beep(329,500);
		     b1.searchlaptop(laptopname);
		     
		  }
		  else if(c==4)
		  {  Beep(493,500); 
		  cin.ignore();    
		    cin>>laptopname;
		    Beep(783,500);
		    b1.deletelaptop(laptopname);
		  }
		  else if(c==5)
		    {  
Beep(392,500);
			cin>>laptopname;
			Beep(440,500);
		    b1.updatelaptop(laptopname);
			}
			 cout<<"two continue press 1";
			 cin>>j;
			 if(j==1)
			 {  goto label;
			 }
}}	  
