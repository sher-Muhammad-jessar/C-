#include<iostream>
#include<conio.h>
#include<iomanip>
#include<fstream>
#include<string>
#include<unistd.h>
#include<windows.h>
#include<mmsystem.h>
using namespace std;
void header(){
	cout<<"========================================================================================================================"<<endl;
 	cout<<"\n*\t\t\t\t\t\tWELCOME TO HOTEL BLUE\t\t\t\t\t               *"<<endl;
 	cout<<"\n========================================================================================================================\n";
}

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
 class Reservation{
 	private:
 		string type;
 		int number;
 		string floor;
 		string date;
 	public:
 		void settype(string t){type=t;}
 		void setnumber(int n){number=n;}
		void setfloor(string f){floor=f;}
		void setdate(string d){date=d;}
		void receipt(string d, string f, string t, int n)
		{
			header();
			cout<<"\n\n\t\t\t\t\t\t\tYOUR RECEIPT :-";
			cout<<"\n\n\nDATE = "<<d<<"\nFLOOR = "<<f<<"\nROOM NUMBER = "<<n<<"\nROOM TYPE = "<<t<<"\n\n\nOur team will be waiting to warmly welcome you and we wish your stay with us remains memorable! Enjoy your stay!";
		}
		void addBooking(const string& date, const string& floor, const string& type, const int& room)
		{
			ofstream file("user_bookings.txt", ios::app);
			file<<date<<" "<<floor<<" "<<type<<" "<<room<<endl;
			file.close();
		}
		
 };
 int main()
 {
 	PlaySound(TEXT("weed.wav"),NULL , SND_FILENAME | SND_ASYNC | SND_LOOP);

 	system("color 9f");

 	Register r;
 	Reservation R;

 	int choice;
 	int ck=1899,ch=2099,cb=649,cn=849,bill=0;
 	int p=1899,s=599,l=599,t=849,sh=1299,cho=899,sd=120,cof=249,tea=99,al=8500;


	string user,pass,inputuser,inputpass,complaint;
	main:
		system("CLS");
	header();
	cout<<"\n1. Register\n2. Sign In\n3. Exit\nMake your choice : ";
 	cin>>choice;
 	switch(choice)
 	{
 	case 1:
 	{ 
 	system("CLS");
 	header();
 	cout<<"\n\n\t\t\t\t\t\t    SIGNING UP\n\n";
 	cout<<"\nCreate Username : ";
 	cin.ignore();
 	getline(cin,user);
 	cout<<"\nCreate Password : ";
 	cin>>pass;
 	r.setusername(user);
 	r.setpassword(pass);
 	r.addUser(user,pass);
 	choice=0;
 	break;}
 	case 2:{
 		goto login;
		break;
	 }
 	case 3:
 	return 0;
 	default:
 		{
 			cout<<"Invalid choice";
 			cout<<"\n Press any key to try again!";
 			getch();
 			goto main;
		 }
	}
 	login:
 	system("CLS");
 	header();
	cout<<"\n\t\t\t\t\t********LOGIN PAGE********";
 	cout<<"\nEnter Username : ";
 	cin.ignore();
 	getline(cin,user);
 	cout<<"\nEnter Password : ";  
 	cin>>pass;
 	if(r.userExists(user, pass))
 	{
 	cout<<"\nLOGIN SUCCESSFUL!";
 	cout<<"\nPress any key to proceed to Dashboard";
 	getch();
 	/*if(inputuser==user && inputpass==pass)
 	{
 	cout<<"\nLOGIN SUCCESSFUL!";*/
 	 	dashboard:
 	system("CLS");
 	header();
	cout<<"\n\t\t\t\t\t      ********DASHBOARD********\n";
 	cout<<"\n1. Reservation";
 	cout<<"\n2. Contact Numbers";
 	cout<<"\n3. File a complaint";
 	cout<<"\n4. Request a service";
 	cout<<"\n5. Check your bill and check out";
 	cout<<"\n6. Log out";
 	cout<<"\nMake your choice : ";

 	cin>>choice;
 	switch(choice)
 	{
 	case 1:
 		{
 			choice=0;
 			system("CLS");
 			string floor,date,type;
 			int roomnumber;
 			header();
 			cout<<"\t\t\t\t\t\t************RESERVATION**********\nNOTE:ALL THE ROOMS HAVE SAME COST i.e., PKR 12599\n";
 			cout<<"\nWrite date(dd/mm/yyyy) for reservation : ";
 			cin>>date;
 			cout<<"\nFollowing floors are available : \nMezannine \n1st \n2nd \nSelect floor you want room on : ";
 			cin.ignore();
 			cin>>floor;
 			cout<<"\nFollowing types are available : \n Single Occupancy\n Double Occupancy\n Business Suite\n Honeymoon Suite\nEnter the type that you want : ";
			cin.ignore();
			getline(cin,type);
 			cout<<"\nFollowing rooms are vacant : \n1\t2\t3\t4\t5\t6\t7\t8\t9\t10\t11\t12\nEnter the room number which you want : ";
 			cin>>roomnumber;
 			bill+=12599;
 			cout<<"\nRoom reserved successfully at standard rate of Rs.12599!\nPress any key to proceed to receipt. ";
 			getch();
 			system("CLS");
 			R.setdate(date);
 			R.setfloor(floor);
 			R.settype(type);
 			R.setnumber(roomnumber);
 			R.receipt(date,floor,type,roomnumber);
 			R.addBooking(date,floor,type,roomnumber);
 			cout<<"\nPress any key to proceed to Dashboard";
 			getch();
 			goto dashboard;	
 			break;
		 }
		 case 2:
		 	{
		 		system("CLS");
		 		header();
		 		cout<<"\nYou can contact our team on the following contact numbers:\n+51423451\n+51472893\n+51423129\nPress any key to proceed to dashboard";
		 		getch();
		 		goto dashboard;
		 		break;
			 }
			 case 3:
			 	{
			 		system("CLS");
			 		header();
			 		cout<<"\t\t\t\t\t\tCOMPLAINTS CENTER\n\n\n";
			 		cout<<"File your complaints here\n\n\n";
			 		cout<<"Write your all concerns and press enter to submit : ";
			 		cin.ignore();
			 		getline(cin,complaint);
			 		system("CLS");
			 		header();
			 		cout<<"\n\n\nYour complaint was filed successfully. We apologise for any inconvinience and further assure you that you won't face similiar situation again. Our team may contact you via email. Kindly respond to it accordingly.";
			 		cout<<"\nPress any key to proceed back to Dashboard";
			 		getch();
			 		goto dashboard;
			 		break;
				 }
				 case 4:
				 	{
				 		service:
				 		choice=0;
				 		system("CLS");
				 		header();
 			            cout<<"\t\t\t\t\t\t**************SERVICES***********";
 			            cout<<"\n1. Internet Connectivity";
 			            cout<<"\n2. Room Service";
 			            cout<<"\n3. Food & Drinks";
 			            cout<<"\n4. Request Bedding Items";
 			            cout<<"\n5. Go back to Dashboard";
 			            cout<<"\nMake your choice : ";
 			            cin>>choice;
 			            switch(choice)
 			            {
 			            	case 1:
 			            		{
 			            			system("CLS");
 			            			header();
 			            			cout<<"\t\t\t\t\t\t**************INTERNET***********";
 			            			cout<<"\n Username: "<<user<<"27@hotelblue.com";
 			            			cout<<"\n Password: FADAAbF2";
 			            			cout<<"\n\nPress any key to proceed back to Services Menu";
 			            			getch();
 			            			goto service;
								 }
							case 2:
								{
									system("CLS");
 			            			header();
 			            			int r;
 			            			cout<<"\t\t\t\t\t\t************ROOM SERVICE*********";
 			            			cout<<"\nEnter your room number : ";
 			            			cin>>r;
 			            			cout<<"\nOur Staff will reach you in a while. We appreciate your patience";
 			            			cout<<"\nPress any key to proceed back to services ";
 			            			getch();
 			            			goto service;
 			            		    break;
								}
								
							case 3:
								{
									food:
									system("CLS");
									header();
									choice=0;
									cout<<"\t\t\t\t\t\t************FOOD AND DRINKS********";
                                    cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tCustomer Name: "<<user<<endl;
                                    cout<<"Right Now, We have following varieties available in the menu";
                                    cout<<"\n1. Asian Cuisines";
                                    cout<<"\n2. Italian Cuisines";
                                    
                                    cout<<"\n3. Chinese Cuisines";
                                    
                                    cout<<"\n4. Tea, Snacks & Beverages";
                                    cout<<"\n5. Back"; 
									cout<<"\nMake your choice : ";                                   
									cin>>choice;
                                    switch(choice)
                                    {
                                    	case 1:
                                    		{
                                    			asian:
                                    			system("CLS");
                                    			header();
                                    			choice=0;
                                    			cout<<"************ASIAN CUISINES********";
                                    			cout<<"\n\n1. Chicken Karahi\t\t\t"<<ck;
                                    			cout<<"\n2. Chicken Haandi\t\t\t"<<ch;
                                    			cout<<"\n3. Chicken Biryani\t\t\t"<<cb;
                                    			cout<<"\n4. Chicken Nihari\t\t\t"<<cn;
                                    			cout<<"\n5. Go back to Dashboard";
                                    			cout<<"\nMake your choice : ";
                                    			cin>>choice;
                                    			switch(choice)
                                    			{
                                    				case 1:
                                    					{
                                    						system("CLS");
                                    						header();
                                    						cout<<"\n\n\nYou've ordered 1 kg Chicken karahi. An amount of "<<ck<<" has been added to your bill.";
                                    						bill+=ck;
                                    						getch();
															goto food;
                                    						break;
														}
													case 2:
														{
															system("CLS");
															header();
															cout<<"\n\n\nYou've ordered 1 kg Chicken Handi. An amount of "<<ch<<" has been added to your bill.";
															bill+=ch;
															getch();
															goto food;
															break;
														}
													case 3:
														{
															system("CLS");
															header();
															cout<<"\n\n\nYou've ordered 1 kg Chicken Biryani. An amount of "<<ch<<" has been added to your bill.";
															bill+=cb;
															getch();
															goto food;
															break;
														}
													case 4:
														{
															system("CLS");
															header();
															cout<<"\n\n\nYou've ordered 1 kg Chicken Nihari. An amount of "<<cn<<" has been added to your bill.";
															bill+=ch;
															getch();
															goto food;
															break;
														}
													case 5:
														{
															goto food;
															break;
														}
												}
											}
												case 2:
													{
													system("CLS");
                                    			    header();
                                    			    choice=0;
                                    			    cout<<"***********ITALIAN CUISINES*******";
                                    			    cout<<"\n\n1. Pizza\t\t\t"<<p;
                                    			    cout<<"\n2. Spaghetti\t\t\t"<<s;
                                    			    cout<<"\n3. Lasagna\t\t\t"<<l;
                                    			    cout<<"\n4. Tiramisu(X12)\t\t\t"<<t;
                                    			    cout<<"\n5. Back";
                                    			    cout<<"\nMake your choice : ";
                                    			    cin>>choice;
                                    			    switch(choice)
                                    			    {
                                    			    	case 1:
                                    					{
                                    						system("CLS");
                                    						header();
                                    						cout<<"\n\n\nYou've ordered 1 Large Pizza. An amount of "<<p<<" has been added to your bill.";
                                    						bill+=p;
                                    						getch();
															goto food;
                                    						break;
														}
													case 2:
														{
															system("CLS");
															header();
															cout<<"\n\n\nYou've ordered 1 Spaghetti (Serving 2 persons). An amount of "<<s<<" has been added to your bill.";
															bill+=s;
															getch();
															goto food;
															break;
														}
													case 3:
														{
															system("CLS");
															header();
															cout<<"\n\n\nYou've ordered 1 Large Lasgna. An amount of "<<l<<" has been added to your bill.";
															bill+=l;
															getch();
															goto food;
															break;
														}
													case 4:
														{
															system("CLS");
															header();
															cout<<"\n\n\nYou've ordered 12 pieces Tiramisu. An amount of "<<t<<" has been added to your bill.";
															bill+=t;
															getch();
															goto food;
															break;
														}
													case 5:
														{
															goto food;
															break;
														}	
													}
												}
													case 3:
													{
													system("CLS");
                                    			    header();
                                    			    choice=0;
                                    			    cout<<"***********CHINESE CUISINES*******";
                                    			    cout<<"\n\n1. Fried Rice+Shashlik\t\t\t"<<sh;
                                    			    cout<<"\n2. Chicken Chowmein\t\t\t"<<cho;
                                    			
                                    			    cout<<"\n3. Back";
                                    			    cout<<"\nMake your choice : ";
                                    			    cin>>choice;
                                    			    switch(choice)
													{
                                    			    	case 1:
                                    					{
                                    						system("CLS");
                                    						header();
                                    						cout<<"\n\n\nYou've ordered Fried Rice with Chicken Shashlik. An amount of "<<sh<<" has been added to your bill.";
                                    						bill+=sh;
                                    						getch();
															goto food;
                                    						break;
														}
													case 2:
														{
															system("CLS");
															header();
															cout<<"\n\n\nYou've ordered Chicken Chowmein(Serving 2 persons). An amount of "<<cho<<" has been added to your bill.";
															bill+=cho;
															getch();
															goto food;
															break;
														}
													
													case 3:
														{
															goto food;
															break;
														}	
													}
												}
													case 4:
													{
													system("CLS");
                                    			    header();
                                    			    choice=0;
                                    			    cout<<"\t\t\t\t\t          *****TEA, BEVERAGES & DRINKS*****";
                                    			    cout<<"\n\n1. Tea\t\t\t"<<tea;
                                    			    cout<<"\n2. Coffee\t\t"<<cof;
                                    			    cout<<"\n3. Soft Drinks\t\t"<<sd;
                                    			    cout<<"\n4. Champaigne(Only for non muslims community)\t"<<al;
                                    			    cout<<"\n5. Back";
                                    			    cout<<"\nMake your choice : ";
                                    			    cin>>choice;
                                    			    switch(choice)
													{
                                    			    	case 1:
                                    					{
                                    						system("CLS");
                                    						header();
                                    						cout<<"\n\n\nYou've ordered a cup of tea. An amount of "<<tea<<" has been added to your bill.";
                                    						bill+=tea;
                                    						getch();
															goto food;
                                    						break;
														}
														case 2:
                                    					{
                                    						system("CLS");
                                    						header();
                                    						cout<<"\n\n\nYou've ordered a cup of coffee. An amount of "<<cof<<" has been added to your bill.";
                                    						bill+=cof;
                                    						getch();
															goto food;
                                    						break;
														}
														case 3:
                                    					{
                                    						system("CLS");
                                    						header();
                                    						cout<<"\n\n\nYou've ordered a can of soft drink. An amount of "<<sd<<" has been added to your bill.";
                                    						bill+=sd;
                                    						getch();
															goto food;
                                    						break;
														}
														case 4:
                                    					{
                                    						system("CLS");
                                    						header();
                                    						cout<<"\n\n\nYou've ordered a can of champaigne. An amount of "<<al<<" has been added to your bill.";
                                    						bill+=al;
                                    						getch();
															goto food;
                                    						break;
														}
														case 5:
															goto food;
													
											}
									}
									case 5:
										{
										
										goto service;
									    break;
									}
							}
							case 4:
								{
									choice=0;
									system("CLS");
 			            			header();
 			            			cout<<"\n\t\t\t\t\t\t************BEDDING ITEMS********";
 			            			cout<<"\n\n1. Request change of bedsheet and pillow covers";
 			            			cout<<"\n2. Request extra bedding items";
 			            			cout<<"\n3. Back";
 			            			cout<<"\nNote: Change of bedding items is complimentary whereas extra bedding items will be inclusive with the bill";
 			            			cout<<"\n\nMake your choice: ";
 			            			cin>>choice;
 			            			switch(choice)
 			            			{
 			            				case 1:
 			            					{
 			            						system("CLS");
 			            						choice=0;
 			            						header();
 			            						cout<<"\nOur staff will entertain your request in a while. We appreciate your patience! Enjoy your stay!";
 			            						cout<<"\nPress any key to proceed back to services menu";
 			            						getch();
 			            						goto service;
 			            						break;
											 }
										case 2:
											{
												system("CLS");
												header();
												choice=0;
												cout<<"\n\nOur bedding items are provided in kits. Each kit contains the following accessories :\nA. 1 Bedsheet\nB. 2 Pillow Covers\nC. 1 Towel\nD. 1 Blanket";
												cout<<"\n\nHow many extra bedding kits do you want? : ";
												cin>>choice;
												int beddingkit=choice*5200;
												bill+=beddingkit;
												system("CLS");
												header();
												cout<<"\nYour order was recorded successfully. An amount of PKR "<<beddingkit<<" was added to your bill";
											    cout<<"\nYou will get the kit within 10 minutes. Press any key to proceed back to services menu.";
											    getch();
											    goto service;
											    break;
											}
											case 3:
												goto service;
									 }
 			            			cout<<"\n\nPress any key to proceed back to Services Menu";
 			            			getch();
 			            			goto service;
								}
							case 5:
								{
									system("CLS");
									header();
									char ch;
									cout<<"ARE YOU SURE YOU WANT TO GO BACK TO DASHBOARD(Y/N)";
									ch=getch();
									if(ch=='y' || ch=='Y')goto dashboard;
									else goto service;
									
								}
						 }
 			            
				 		break;
					 }
					 case 5:
		              {
			             system("CLS");
			             header();
			             choice=0;
			             cout<<"\n\t\t\t\t\t\t****************BILLS************";
			             cout<<"\nIt was truly an honor to have had you with us here at The Hotel Blue. We wholeheartedly thank you for choosing us for your stay!\n ";
			             cout<<"\nYour total costs of stay added up to a total of PKR "<<bill<<".";
			             cout<<"\nYou can proceed to the reception to check out and get the detailed receipt of your costs. Thanks";
			             cout<<"\nDo you want to go back to dashboard(Y/N)?";
			             choice=getch();
			             if(choice=='y' || choice=='Y')
			             goto dashboard;
			             else
			             return 0;

		}
						 
							 case 6:
							 	{
							 		char a;
							 		cout<<"ARE YOU SURE YOU WANT TO LOG OUT (Y/N)?";
							 		cin>>a;
							 		if(a=='y'||a=='Y')
							 		goto login;
							 		else goto dashboard;
							 		break;
								 }
	}
	
    }
    }else{
 	     cout<<"\nINCORRECT CREDENTIALS ! Try Again ";
 	     getch();
 	     goto login;
 	 }
 	 return 0;
 	}
 	

