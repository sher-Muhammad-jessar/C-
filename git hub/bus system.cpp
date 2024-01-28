#include<iostream>
#include<unistd.h>
using namespace std;
class bus{
	char arrive[10],depart[10],from2[10],to2[10],from[10],to[10],name[99];
	int busn,number,fair,password,id,seat;
    int availtick;
    int pass;
    int id1;
    int age;
    int bnum2;
  public:
  	void ticketlist();
  	void businfo();
  	void printtick();
  	void setpass();
  	bus(int initialtick):availtick(initialtick){}
  	void book(int numtick){
  		cout<<"enter your name"<<endl;
  		cin>>name;
  		cout<<"bus number"<<endl;
  		cin>>busn;
		if(busn>11 && busn<=16){
			cout<<"ok"<<endl;
		}
		else{
			cout<<"no such bus is available"<<endl;
			cout<<"try again"<<endl;
			cin>>busn;
		}
		
		cout<<"which seat number you want:"<<endl;
		cin>>seat;
		cout<<"from:"<<endl;
		cin>>from;
		cout<<"to:"<<endl;
		cin>>to;
  		if(numtick>0 && numtick<=availtick){
  			availtick-=numtick;
  			cout<<numtick<<" tickets booked succesfully"<<endl;
		    }
		    
		    else{
		    	cout<<"tickets not available"<<endl;
			}
			cout<<"\n"<<"remaining tickets"<<availtick;
	    } 
	   
};
void bus::ticketlist(){
	 cout<<"busno:11"<<"  "<<"Hyderabad"     <<"   "">>>""   "<<"karachi"<<"<-->"<<"price is=PKR800"<<endl;
     cout<<"arrival at 7:00"<<"  "<<"depart at 7:30"<<endl; 
	 cout<<"busno:12"<<"  "<<"Karachi"       <<"   "">>>""   "<<"sukkhur"<<"<-->"<<"price is=PKR2500"<<endl;
     cout<<"arrival at 8:00"<<"  "<<"depart at 8:30"<<endl;
	 cout<<"busno:13"<<"  "<<"karachi"       <<"   "">>>""   "<<"lahore"<<"<-->"<<"price is=PKR6740"<<endl;
     cout<<"arrival at 9:00"<<"  "<<"depart at 9:30"<<endl;
	 cout<<"busno:14"<<"  "<<"hyderabad"     <<"   "">>>""   "<<"mianwali"<<"<-->"<<"price is=PKR4379"<<endl;
     cout<<"arrival at 7:00"<<"  "<<"depart at 7:30"<<endl;
	 cout<<"busno:15"<<"  "<<"hub choki"     <<"   "">>>""   "<<"Quetta"<<"<-->"<<"price is=PKR5000"<<endl;
     cout<<"arrival at 7:00"<<"  "<<"depart at 7:30"<<endl;
	 cout<<"busno:16"<<"  "<<"nausheroferoz" <<"   "">>>""   "<<"karachi"<<"<-->"<<"price is=PKR2000"<<endl;
     cout<<"arrival at 7:00"<<"  "<<"depart at 7:30"<<endl;
}
void bus::businfo(){
		cout<<"enter bus number"<<endl;
		cin>>bnum2;
		cout<<"from:"<<" ";
		cin>>from2;
		cout<<"destination:"<<"  ";
		cin>>to2;
		cout<<"total seats are 50"<<"  ";
		cout<<"sucessfully entered"<<endl;
		sleep(2);
}
void bus::printtick(){
	cout<<"ticket information"<<endl;
	cout<<"Name:"<<name<<endl;
	cout<<" seat number you want:"<<seat<<endl;
    cout<<"bus number:"<<busn<<endl;
    cout<<"from:"<<"  "<<from<<endl;
    cout<<"destination:"<<"  "<<to<<endl; 
    
}
void bus::setpass(){
	
	cout<<"enter password"<<endl;
	cin>>pass;
	cout<<"enter id"<<endl;
	cin>>id;
	if(pass==12345 && id==7877){
	cout<<"you are recongnised"<<endl;	
	}
	else{
		cout<<"**input valid password and ID that was assigned to you**"<<endl;
	    cout<<"enter the password again"<<endl;
	    cin>>pass;
	    cout<<"enter the id again"<<endl;
	    cin>>id;
	}
	
}
int main(){
	cout<<"*****BUS TICKET RESERVATION SYSTEM*****"<<endl;
	cout<<"Prepeared By:--> ABDUL AZIZ"<<endl;
	cout<<"Roll number:-->23sw061"<<endl;
	cout<<"Submited to:--> Sir sajjad"<<endl;
	bus b(50);
	b.setpass();
	sleep(2);
	while(true){
	cout<<"\t\t**** BUS TICKET RESERVATION SYSTEM****\t"<<endl;
    cout<<"\t\t 1. BUS ROUTE,TIME,AND PRICE LIST\t"<<endl;
    cout<<"\t\t 2. GET BUS INFO \t"<<endl;
    cout<<"\t\t 3. BOOK SEATS\t"<<endl;
	cout<<"\t\t 4. MY TICKET \t"<<endl;
    cout<<"\t\t 5. EXIT\t "<<endl;
    cout<<"enter your choice"<<endl;
    int in;
    int numtick;
	cin>>in;
  if(in==1){
  	b.ticketlist();
  }
  else if(in==2){
  	b.businfo();
	}
  	
  else if(in==3){
  	cout<<"how many seats you want"<<endl;
  	cin>>numtick;
	  b.book(numtick);
	  cout<<"\n****you can get your ticket by choosing 4th option****"<<endl;
  }
  else if(in==4){
  	cout<<"***YOUR TICKET***"<<endl;
  	b.printtick();
  	cout<<"**** HAVE A SAFE JOURNEY ****"<<endl;
  }
  else if(in==5){
  	cout<<"***HAVE A NICE DAY***"<<endl;
	  break;
  }
  cout<<"\n you want to continue YES/NO"<<endl;
  char input;
  cin>>input;
  if(input=='n'){
  	break;
  }
  else{
  	continue;
  }
}
cout<<"****THANKS FOR VISITING AND BOOKING TICKET****"<<endl;
return 0;
}
