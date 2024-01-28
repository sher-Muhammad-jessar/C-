/*
           ********LIBRARY MANAGEMENT SYSTEM*****************
           *********23SW046 MUHAMMAD IQBAL LAKHO*************
*/
//HEADER FILES
#include<iostream>
#include<iomanip>
#include<fstream>
#include<string>
#include<conio.h>
using namespace std;
int ts=0,tb=0;
//CLASS STUDENT
class Student{
	private:
		string name;
		int id;
		string department;
		string book;
	public:
		void setname(string str){
			name=str;
		}
		void setid(int n){
			id=n;
		}
		void setdepartment(string str){
			department=str;
		}
		void rebook(string str){
			book=str;
		}
		void setbook(string str){
			book+=str;
			book+=",";
		}
	    string getname(){
	    	return name;
		}
		string getdepartment(){
	    	return department;
		}
		string getbook(){
	    	return book;
		}
		int getid(){
	    	return id;
		}
		void getdata(){
			cout<<"\nStudent id :";cin>>id;
			cin.ignore();
			cout<<"\nStudent name :";getline(cin,name);
		     cout<<"\nStudent department :";getline(cin,department);
			
		}
		void display(){
		    cout<<"\n\n\t\t\tStudent information";
			cout<<"\n\nStudent name "<<name;
			cout<<"\nStudent id "<<id;
			cout<<"\nStudent department "<<department; 
		}
}; 
//CLASS BOOK
class Book{
	private:
		string name;
		string author;
	    int edition;
	public:
		void setname(string str){
			name=str;
		}
		void setedition(int n){
			edition=n;
		}
		void setauthor(string str){
			author=str;
		}
		
	    string getname(){
	    	return name;
		}
		string getauthor(){
	    	return author;
		}
		int getedition(){
	    	return edition;
		}
		void getdata(){
			cin.ignore();
			cout<<"\nBook name :";getline(cin,name);
			cout<<"\nAuthorname :";getline(cin,author);
			cout<<"\nBook edition :";cin>>edition;
			
		}
		void display(){
			cout<<"\n\n\t\t\tBook information";
			cout<<"\n\nBook name "<<name;
			cout<<"\nBook author "<<author;
			cout<<"\nBook edition "<<edition;
		}
};
//MENU FUNCTION WHICH ALLOWS TO CHOOSE OPTION
void menu(Student s[100],Book b[100]){
		int ch;
		system("color 3f");
		cout<<"\n\n\t\t\t\t*-----------------------------------*\n";
    	cout<<"\n\t\t\t\t*\tLIBRARY MANAGEMENT SYSTEM   *\n";
		cout<<"\n\t\t\t\t*\t\t23SW046             *\n";
	   	cout<<"\n\t\t\t\t*-----------------------------------*\n\n\n";
		cout<<"1.Add Student\n2.Add book\n3.See all books\n4.See all students\n5.Issue book\n6.Remove student\n7.Remove Book\n8.See book issued for one student\n9.Return book\n";
		cin>>ch;
	
		system("cls");
    	char in='y';
while(in=='y'){
        system("color F3");
	    if(ch==1){
			s[ts].getdata();
			++ts;
			cout<<"\nDo you want to add another press y : ";cin>>in;
		}
	else if(ch==2){
			b[tb].getdata();
			++tb;
			cout<<"\nDo you want to add another press y : ";cin>>in;
		}
	else if(ch==3){
			for(int i=0;i<tb;i++)
				b[i].display();
			cout<<"\n\nPress 0 to go to main menu : ";cin>>in;
		}
	else if(ch==4){
		for(int i=0;i<ts;i++)
			s[i].display();
		cout<<"\n\nPress 0 to go to main menu : ";cin>>in;
	}
	else if(ch==5){
		int n;
		string st;
		cout<<"\nEnter id of student whom you want to issue a book : ";cin>>n;
		bool found=false;
		for(int i=0;i<ts;i++){
			if(n==s[i].getid()){
				cin.ignore();
                cout<<"\nEnter book name : ";getline(cin,st);
					for(int j=0;j<tb;j++){
				    	if(st==b[j].getname()){
				    	found=true;
				    	s[i].setbook(b[j].getname());
						break;
						}
							else found=false;	 
					}
				break;
			}
			
		}
		if(found)cout<<"\nBook issued";
		else cout<<"\nData not found ";
		cout<<"\n\nDo you want to issue anothor book press y : ";cin>>in;
	}
	else if(ch==6){
		int n;
		cout<<"\nEnter student id : ";cin>>n;
		bool found=false;
		for(int i=0;i<ts;i++){
			if(n==s[i].getid()){
				for(int j=0;j<ts-i;j++)
				{
				s[i+j]=s[i+(j+1)];
				}
				--ts;
				
				found=true;
				break;
		}
		else found=false;
		}
        if(found)cout<<"\nStudent information deleted";
            else cout<<"\nStudent data not found";
		cout<<"\n\nDo you want to delete another press y : ";cin>>in;
	}
	else if(ch==7){
		string n;
		bool found=false;
		cin.ignore();
		cout<<"\nEnter Book name : ";getline(cin,n);
		for(int i=0;i<tb;i++){
			if(n==b[i].getname()){
				for(int j=0;j<tb-i;j++)
				{
				s[i+j]=s[i+(j+1)];
				}
			--tb;
			found=true;
			break;
		}
		else found=false;
		}
		if(found)cout<<"\nBook Removed successfully ";
		else cout<<"\nBook not found ";
		cout<<"\n\nDo you want to delete another press y : ";cin>>in;
	}
	else if(ch==8){
		int n;
		cout<<"\nEnter id of student : ";cin>>n;
		bool found=false;
		for(int i=0;i<ts;i++){
			if(n==s[i].getid()){
			cout<<"\nBooks issued : "<<s[i].getbook();
			found=true;
			}
		}
		if(found==false)cout<<"\nStudent data not found ";
		cout<<"\n\nSee other student issued books press y : ";cin>>in;
	}
	else if(ch==9){
		int n;
		string str;
		cout<<"\nEnter id of student : ";cin>>n;
		bool found=false;
		for(int i=0;i<ts;i++){
			if(n==s[i].getid()){
				cin.ignore();
				cout<<"\nEnter book name : ";getline(cin,str);
				bool present=s[i].getbook().find(str)!=string::npos;
				if(present==true){
					string sr=s[i].getbook().replace(s[i].getbook().find(str),str.length()+1," ");
					s[i].rebook(sr);
					cout<<"\nBook returned";
					}
				else cout<<"\nBook is not issued to student";
				found=true;
				break;
			}else found=false;
		}
		if(found==false)cout<<"\nStudent data not found";
		cout<<"\n\nDo you want to return other book ";cin>>in;
	}
 	else {cout<<"\ninvlaid input";break;}
	}
	system("cls");
	menu(s,b);
}
//MAIN
int main(){
	Student s[100];
	Book b[100];
	menu(s,b);
}

