#include<iostream>
#include<conio.h>
#include<cstdlib>
#include<iomanip>
#include<unistd.h>
#include<windows.h>
#include<fstream>
#include<limits>
//#include<ofstream>
//#include<ifstream>
using namespace std;

class Register{
 	private:
 		string username;
 		string password;
 	public:
 		void setusername(string u){username=u;}
 	     void setpassword(string p){password=p;}
 	    bool userExists(const string& user, const string& pass)
		 {
		 	ifstream file("user_accounts.txt");
		 	string storedUsername, storedPassword;
	        while(file >> storedUsername >> storedPassword)
			{
		        if(storedUsername == user && storedPassword == pass)
				{
			       file.close();
			       return true;
		        }
	        }
	        file.close();
			return false;
        }
        void addUser(const string& user, const string & pass)
        {
        	cout << "Adding user to file - Username: " << user << ", Password: " << pass << endl;

        	ofstream file("user_accounts.txt", ios::app);
        	file<<user<<" "<<pass<<endl;
        	file.close();
        	cout<<"Registering! Please wait";
        	for(int j=1; j<3; j++)
        	{
        		cout<<".";
        		sleep(1);
			}
        	cout<<"User registered successfully!";
        	sleep(2);
		}
	};
class carrental{
	int a;
	string name;
	public:
		carrental()
		{
			
		   cout<<"Please give us the chance to be you permanent host :)\n";
		   dash:
			cout<<" 1.Create an account.\n 2.Sign in\n  ";
				cout<<"select the option:";
				cin>>a;
			if (a==1){
					create();
					goto dash;
				}
			else if (a==2){
					signin();
				}
				else {cout<<"You clicked wrong option.\nplease select any two of them";
				goto dash;
				}
	}
		 void create(){
		 		system("CLS");
		 	cout<<"\t\t*********************___________________________*******************************\n";
	   cout<<"\t\t\t\t    Welcome to Ali vehicle rental house \n";
	   cout<<"\t\t*********************___________________________*******************************\n\n";
			string fname;
			Register r;
			
				string lname;
			string pass,pass1;
			double contact;
			string email;
			 string uname;
		           cout<<"Enter the first name :"; cin>>fname;
		             cout<<"Enter the last name :"; cin>>lname;
		               cout<<"Make a user name please:"; cin>>uname;
		               cout<<"Enter your contact number:"; cin>>contact;
		                  cout<<"Enter your email:"; cin>>email;
		       cout<<"Enter password :"; cin>>pass;
		       dars:
		       cout<<"Confirm you password:"; cin>>pass1;
		       if (pass!=pass1){
		       	cout<<"You re-entered wrong password .\n";
			   }
		       else { 
			   sleep(5);
			   cout<<" Great ! Your account has been registered successfully !!!!\n\n";
			   system("CLS");
			   	cout<<"\t\t*********************___________________________*******************************\n";
	   cout<<"\t\t\t\t    Welcome to Ali vehicle rental house \n";
	   cout<<"\t\t*********************___________________________*******************************\n\n";
	   
			   cout<<"Enter any character to get list of vehicles we have : ";
			   getch();
			   }
		      }
		      void 	signin(){
		      		system("CLS");
		      	cout<<"\t\t*********************___________________________*******************************\n";
	   cout<<"\t\t\t\t    Welcome to Ali vehicle rental house \n";
	   cout<<"\t\t*********************___________________________*******************************\n\n";
		      	string uname;
		      	string pass;
		      	cout<<"Enter the username:"; 
				  cin>>uname;
		      	cout<<"Enter the password:"; 
				  cin>>pass;
				   system("CLS");
			   	cout<<"\t\t*********************___________________________*******************************\n";
	   cout<<"\t\t\t\t    Welcome to Ali vehicle rental house \n";
	   cout<<"\t\t*********************___________________________*******************************\n\n";
		      	cout<<"Enter any character to get list of vehicle we have : ";
		      	getch();
			  }
			 
    char choose(){
    	system("CLS");
    	 cout<<"\t\t*********************___________________________*******************************\n";
	   cout<<"\t\t\t    Welcome to Ali vehicle rental house \n";
	   cout<<"\t\t*********************___________________________*******************************\n\n";
    	char vehicle;
    	cout<<"A.Bike B.Car c.Truck ";
    	cout<<"\nEnter your choice: "; cin>>vehicle;
    	return vehicle;
	}
	int  bikelist(){
		system("CLS");
    	 cout<<"\t\t*********************___________________________*******************************\n";
	   cout<<"\t\t\t\t    Welcome to Ali vehicle rental house \n";
	   cout<<"\t\t*********************___________________________*******************************\n\n";
		         cout<<"Here you get the list of bikes , we have:\n"; 
		         cout<<"Loading";
		  for(int i=1;i<=4;i++)
		  {
		  	cout<<".";
		  	sleep(1);
		  }
		  int i;
		  string yesno;
		  	  cout<<endl;
		  	  list:
		cout<<"1.Honda CB Hornet 160R\n__Engine Capacity:162.7 CC\n__Mileage:0 - 62 KM/L\n__Fuel Tank Capacity:12.0 L";
		cout<<"\nPrice.per.Hour:150 PKR "<<endl<<endl;
		
              cout<<"2.HondaCD 110 Dream\n__Engine Capacity:109.5 CC\n__Mileage:74 KM/L\n__Fuel Tank Capacity:8.0 L";
		cout<<"\nPrice.per.Hour:130 PKR "<<endl<<endl;
		
		cout<<"3.Honda Activa 6G\n__Engine Capacity:109.5 CC\n__Mileage:45 KM/L\n__Fuel Tank Capacity:5.3 L";
		cout<<"\nPrice.per.Hour:110 PKR "<<endl<<endl;
		
			cout<<"4.Honda CD 70\n__Engine Capacity:70.00 CC\n__Mileage: 50-65 km/l\n__Fuel Tank Capacity:8.5 L";
		cout<<"\nPrice.per.Hour:100 PKR "<<endl<<endl;
		
		cout<<"\n\n please choose the bike you want to get on rent:"; 
		cin>>i;
			switch(i){
			case 1:
				sleep(2);
				cout<<"You chose : Honda CB Hornet 160R \n Do you want proceed or leave you choice(yes or no): ";
				      cin>>yesno; 
			if(yesno=="yes"){
				cout<<"Proceed for payment :";
			}
			else if (yesno=="no"){
				cout<<" Cancel the vehicle ";
			}
			{ break;
			}
			case 2:
				sleep(2);
				cout<<"You chose :HondaCD 110 Dream \n Do you want proceed or leave you choice(yes or no): ";
				      cin>>yesno; 
			if(yesno=="yes"){
				cout<<"Proceed for payment :";
			}
			else if (yesno=="no"){
				cout<<"Canceled v";
			}
			{ break;
			}
				case 3:
				sleep(2);
				cout<<"You chose :Honda Activa 6G\n Do you want proceed or leave you choice(yes or no): ";
				      cin>>yesno; 
			if(yesno=="yes"){
				cout<<"Proceed for payment :";
			}
			else if (yesno=="no"){
				cout<<"Canceled the vehicle\n";
			}
			{ break;
			}
			case 4:
				sleep(2);
				cout<<"You chose :Honda CD 70\n Do you want proceed or leave you choice(yes or no): ";
				      cin>>yesno; 
			if(yesno=="yes"){
				cout<<"Proceed for payment:";
				payment();
			}
			else if (yesno=="no"){
				cout<<"Canceled the vehicle\n";
			}
			{ break;
			}
			default : cout<<"You chose option which is not present\n ";
			cout<<"going to list again";
			for(int i=1;i<=4;i++)
		  {
		  	cout<<".";
		  	sleep(1);
		  }
		  system("CLS");
			 goto list;
			 break;			
		}
	}
       int  carlist(){
       		system("CLS");
    	 cout<<"\t\t*********************___________________________*******************************\n";
	   cout<<"\t\t\t\t    Welcome to Ali vehicle rental house \n";
	   cout<<"\t\t*********************___________________________*******************************\n\n";
		         cout<<"Here you get the list of bikes , we have:\n"; 
		         cout<<"Loading";
		  for(int i=1;i<=4;i++)
		  {
		  	cout<<".";
		  	sleep(1);
		  }
		 
  int i;
  string yesno;
		  	  cout<<endl;
		  	  list:
		cout<<"1.Maruti Suzuki Alto 800\n__Fuel Type:Petrol/ Petrol+CNGCC\n__Transmission:Manual\n__Mileage-iconMileage:24.7 - 31.4 KM/L";
		cout<<"\n__Tank Capacity:35.0/60.0 L\n__Seating:4/5\n__SeaterAirbags:Yes";
		cout<<"\nPrice.per.Hour:1000 PKR "<<endl<<endl;
		
		cout<<"2.ToyotaYaris800\n__Fuel Type:Petrol\n__Transmission:Manual/ Automati\n__Mileage:17.1 - 17.8 KM/L";
		cout<<"\n__Tank Capacity:42.0 L\n__Seating:5\n__SeaterAirbags:Yes";
		cout<<"\nPrice.per.Hour:1500 PKR "<<endl<<endl;
		
	cout<<"3.Toyota Corolla Altis\n__Fuel Type:Petrol/Diesel\n__Transmission:Manual/ Automatic\n__Mileage:16.7 - 21.3 KM/L";
		cout<<"\n__Tank Capacity:43.0/55.0 L\n__Seating:5";
		cout<<"\nPrice.per.Hour:1000 PKR "<<endl<<endl;
		
				cout<<"4.Honda City\n__Fuel Type:Petrol, Hybrid\n__Transmission:Automatic\n__Mileage:17.80 KM/";
		cout<<"\n__Tank Capacity:40.0 L\n__Seating:5";
		cout<<"\nPrice.per.Hour:1200 PKR "<<endl<<endl;
		
		cout<<"\n\n please choose the car you want to get on rent:"; 
		cin>>i;
		switch(i){
			case 1:
				sleep(2);
				cout<<"You chose : Maruti Suzuki Alto 800 \n Do you want proceed or leave you choice(yes or no): ";
				      cin>>yesno; 
			if(yesno=="yes"){
				cout<<"Proceed for payment or want to see other vehicles:";
			}
			else if (yesno=="no"){
				cout<<"Want to see other vehicles or Cancel";
			}
			{ break;
			}
			case 2:
				sleep(2);
				cout<<"You chose :ToyotaYaris800 \n Do you want proceed or leave you choice(yes or no): ";
				      cin>>yesno; 
			if(yesno=="yes"){
				cout<<"Proceed for payment or want to see other vehicles:";
			}
			else if (yesno=="no"){
				cout<<"Want to see other vehicles or Cancel";
			}
			{ break;
			}
				case 3:
				sleep(2);
				cout<<"You chose :Toyota Corolla Altis\n Do you want proceed or leave you choice(yes or no): ";
				      cin>>yesno; 
			if(yesno=="yes"){
				cout<<"Proceed for payment or want to see other vehicles:";
			}
			else if (yesno=="no"){
				cout<<"Want to see other vehicles or Cancel";
			}
			{ break;
			}
			case 4:
				sleep(2);
				cout<<"You chose :Honda City \n Do you want proceed or leave you choice(yes or no): ";
				      cin>>yesno; 
			if(yesno=="yes"){
				cout<<"Proceed for payment or want to see other vehicles:";
			}
			else if (yesno=="no"){
				cout<<"Want to see other vehicles or Cancel";
			}
			{ break;
			}
			default : cout<<"You chose option which is not present\n ";
			cout<<"going to list again";
			for(int i=1;i<=4;i++)
		  {
		  	cout<<".";
		  	sleep(1);
		  }
		  system("CLS");
			 goto list;
			 break;			
		}
			  
	   }
	    int jeeplist(){
       		system("CLS");
    	 cout<<"\t\t*********************___________________________*******************************\n";
	   cout<<"\t\t\t\t    Welcome to Ali vehicle rental house \n";
	   cout<<"\t\t*********************___________________________*******************************\n\n";
		         cout<<"Here you get the list of Jeeps, we have:\n"; 
		         cout<<"Loading";
		  for(int i=1;i<=4;i++)
		  {
		  	cout<<".";
		  	sleep(1);
		  }
		 
  int i;
  string yesno;
		  	  cout<<endl;
		  	  list:
		cout<<"1.Jeep Wrangler Sport S\n__Fuel_type:  Regular unleaded\n__Transmission:  Manual\n__Mileage-iconMileage:12.1KM/L";
		cout<<"\n__Tank Capacity:35.0/60.0 L\n__Seating:4";
		cout<<"\nPrice.per.Hour:  2200 PKR "<<endl<<endl;
		
		cout<<"2.jeep wrangler sahara\n__Fuel Type:  Petrol/Diesel\n__Transmission:  Manual/ Automatic\n__Mileage:15 KM/L";
		cout<<"\n__Tank Capacity:  42.0 L\n__Seating:5";
		cout<<"\nPrice.per.Hour:  2300 PKR "<<endl<<endl;
            
	cout<<"3.Jeep Commander Specs\n__Fuel Type:  Petrol\n__Transmission:  Automatic\n__Mileage:  16.7 - 16.11 KM/L";
		cout<<"\n__Tank Capacity:  43.0/55.0 L\n__Seating:5\n__SeaterAirbags:Yes";
		cout<<"\nPrice.per.Hour:  1900 PKR "<<endl<<endl;
		
				cout<<"4.jeep grand cherokee\n__Fuel Type: Diesel,Hybrid\n__Transmission:  Automatic\n__Mileage: 23.11 KM/";
		cout<<"\n__Tank Capacity:  41.0 L\n__Seating:5\n__SeaterAirbags:Yes";
		cout<<"\nPrice.per.Hour:  2200 PKR "<<endl<<endl;
		
		cout<<"\n\n please choose the Jeep you want to get on rent:"; 
		cin>>i;
		switch(i){
			case 1:
				sleep(2);
				cout<<"You chose : Jeep Wrangler Sport \n Do you want proceed or leave you choice(yes or no): ";
				      cin>>yesno; 
			if(yesno=="yes"){
				cout<<"Proceed for payment or want to see other vehicles:";
			}
			else if (yesno=="no"){
				cout<<"Want to see other vehicles or Cancel";
			}
			{ break;
			}
			case 2:
				sleep(2);
				cout<<"You chose :jeep wrangler sahara \n Do you want proceed or leave you choice(yes or no): ";
				      cin>>yesno; 
			if(yesno=="yes"){
				cout<<"Proceed for payment or want to see other vehicles:";
			}
			else if (yesno=="no"){
				cout<<"Want to see other vehicles or Cancel";
			}
			{ break;
			}
				case 3:
				sleep(2);
				cout<<"You chose :Jeep Commander Specs\n Do you want proceed or leave you choice(yes or no): ";
				      cin>>yesno; 
			if(yesno=="yes"){
				cout<<"Proceed for payment or want to see other vehicles:";
			}
			else if (yesno=="no"){
				cout<<"Want to see other vehicles or Cancel";
			}
			{ break;
			}
			case 4:
				sleep(2);
				cout<<"You chose :jeep grand cherokee \n Do you want proceed or leave you choice(yes or no): ";
				      cin>>yesno; 
			if(yesno=="yes"){
				cout<<"Proceed for payment or want to see other vehicles:";
			}
			else if (yesno=="no"){
				cout<<"Want to see other vehicles or Cancel";
			}
			{ break;
			}
			default : cout<<"You chose option which is not present\n ";
			cout<<"going to list again";
			for(int i=1;i<=4;i++)
		  {
		  	cout<<".";
		  	sleep(1);
		  }
		  system("CLS");
			 goto list;
			 break;			
		}

		  	  
	   }
	   void payment(){
	   	
	   }

};

int main(){
	   cout<<"\t\t*********************___________________________*******************************\n\n\n\n\n\n\n";
	   cout<<"\t\t\t\t    WELCOME TO ALI VEHICLE RENTAL HOUSE \n\n\n\n\n";
	   cout<<"\t\t*********************___________________________*******************************\n\n\n\t\t\t\t\t\t";
	   cout<<"Wait a little please";
	   	  for(int i=1;i<=4;i++)
		  {
		  	cout<<".";
		  	sleep(3);
		  }
         system("CLS");
           cout<<"\t\t*********************___________________________*******************************\n";
	   cout<<"\t\t\t\t\t    Welcome to Ali vehicle rental house \n";
	   cout<<"\t\t*********************___________________________*******************************\n";
       carrental veh1;
       cout<<"\nWait please";
         for(int i=1;i<=4;i++)
		  {
		  	cout<<".";
		  	sleep(1);
		  }
       switch(veh1.choose())
	   {
       	case 'a': 
		     cout<<"You chose Bikes..............\n";
		     cout<<"Here you get the lsit of Bikes, we have:\n";
		          cout<<"Loading";
		           for(int i=1;i<=4;i++)
		  {
		  	cout<<".";
		  	sleep(1);
		  }
		  	  cout<<endl;
		  veh1.bikelist(); 
		  break;
		 case 'b': 
		 system("CLS");
		 	 cout<<"\t\t*********************___________________________*******************************\n";
	   cout<<"\t\t\t\t    Welcome to Ali vehicle rental house \n";
	   cout<<"\t\t*********************___________________________*******************************\n\n";
		   cout<<"You chose cars..............\n";
		       cout<<"Here you get the list of cars,we have:\n"; 
		          cout<<"Loading";
		  for(int i=1;i<=4;i++)
		  {
		  	cout<<".";
		  	sleep(1);
		  }
		  	  cout<<endl;
		  veh1.carlist(); 
		  break;
		  	 case 'c': 
			   system("CLS");
			   	 cout<<"\t\t*********************___________________________*******************************\n";
	   cout<<"\t\t\t\t    Welcome to Ali vehicle rental house \n";
	   cout<<"\t\t*********************___________________________*******************************\n\n";
		   cout<<"You chose jeeps..............\n";
		   cout<<"Here you get the list of jeeps,we have:\n"; 
		  cout<<"Loading";
		  for(int i=1;i<=4;i++)
		  {
		  	cout<<".";
		  	sleep(1);
		  }
		  cout<<endl;
		veh1.jeeplist(); 
	
		  break;	 
       	}  
      
	return 0;
}
	
