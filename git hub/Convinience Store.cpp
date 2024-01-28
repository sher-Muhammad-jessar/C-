#include<iostream>
#include<fstream>
#include<string>

using namespace std;

class shopping{
	private:
		int productcode;
		float discount;
		string name;
		float price;
		
	public:
		void menu();
		void administrator();
		void customer();
		void add();
		void edit();
		void Remove();
		void exit();
		void list();
		void receipt();
		
};

void shopping :: menu()
{
   // m:
	int choice;
	string loginid;
	string password;
	cout<<"\n\n\n\n\n";
	cout<<"\t\t\t\t\t\t\t****************************************************\n";
	cout<<"\t\t\t\t\t\t\t                                                 \n";
	cout<<"\t\t\t\t\t\t\t            7-ELEVEN convinience store \n\n";
	cout<<"\t\t\t\t\t\t\t                    Main Menu\n";	
	cout<<"\t\t\t\t\t\t\t                                                 \n";
	cout<<"\t\t\t\t\t\t\t****************************************************\n";
	cout<<"\n\n\n";
	cout<<"\t\t\t\t\t\t\t         ***********************************\n";
	cout<<"\t\t\t\t\t\t\t         *            1.Administrator      *\n ";
	cout<<"\t\t\t\t\t\t\t         *            2.Customer           *\n";
	cout<<"\t\t\t\t\t\t\t         *            3.Exit               *\n";
	cout<<"\t\t\t\t\t\t\t         ************************************\n";
	cout<<"\n";
	cout<<"\t\t\t\t\t\t\t         Please Select an option\n";cin>>choice;
	system("cls");
	switch(choice)
	{
		case 1:
		{
				
			cout<<"\n\n\n\t\t\t\t\t\tplease Enter login details\n\n";
			cout<<"\t\t\t\t\t\tEnter login ID : ";
			cin>>loginid;
			cout<<"\t\t\t\t\t\tEnter Password : ";
			cin>>password;
			
			if(loginid=="7E101" && password=="1234"){
	    	system("cls");
			administrator();
			}
		break;
	    }
		case 2:
		{
			customer();
			
		break;
		}
	/*	case 3:
		{	
			exit();
	    }
	  
	  */  default:
	    	cout<<"\t\t\t\t\t\t\tSelect from given options !";
		
	}
//goto m;		
}
void shopping :: administrator()
{
//	m:
	int choice;
	cout<<"\t\t\t\t\t\t\t                    Administrator Menu \n\n\n";
	cout<<"\t\t\t\t\t\t\t            |       1. Add Product         |\n";
	cout<<"\t\t\t\t\t\t\t            |       2. Modify Product      |\n";
	cout<<"\t\t\t\t\t\t\t            |       3. Delete Product      |\n";
    cout<<"\t\t\t\t\t\t\t            |       4. Back to Main Menu   |\n";
    
    cout<<"\n\n\n\n\t\t\t\t\tEnter option :  ";cin>>choice;
    
    system("cls");
    switch(choice)
    {
    	case 1:
    		add();
        break;
        
        case 2:
        	edit();
        break;
        
        case 3:
        	Remove();
        break;
		case 4:
			menu();
		break;
		default:
		cout<<"Invalid input !";	
	}
	
//	goto m;
}

void shopping :: customer()
	{
	//m:	
	int choice;
	cout<<"\t\t\t\t\t\t\t                   WELCOME TO 7-Eleven \n\n\n";
	cout<<"\t\t\t\t\t\t\t              |       1. Buy Product    |\n";
	cout<<"\t\t\t\t\t\t\t              |       2. Go Back        |\n";
	cout<<"\n\n";
	cout<<"Enter your choice";cin>>choice;
	system("cls");
	
	switch(choice)
	{
		case 1:
			receipt();
			break;
		case 2:
			menu();
			break;
		default:
		cout<<"Invalid input !";	
	}
    //goto m;
	}
	
	void shopping :: add()
	{
	char choi;
		do{
		
	    m:	
		fstream data;
		float pc;
		int c;
		float d;

		string n;
		float p;
		int token=0;
		
		
		cout<<"\n\n\t\t\t\t\t\t\t\tAdd new Product\n\n\n\n\n";
		cout<<"\n\t\tEnter Name of Product : ";cin>>name;
		cout<<"\n\t\tEnter Product Code : ";cin>>productcode;
		cout<<"\n\t\tEnter Price of Product : ";cin>>price;
		cout<<"\n\t\tEnter Discount on Product : ";cin>>discount;
		
		data.open("productData.txt",ios::in);             // for reading
		
		if(!data)
		{
			data.open("productData.txt",ios::app | ios::out);
			data<<" "<<productcode<<" "<<name<<" "<<price<<" "<<discount<<endl;
			data.close();
		}
		else
		{
			data>>pc>>n>>p>>d;
			
			while(!data.eof()){
				if(pc ==productcode){
					token++;
				}
				data>>c>>n>>p>>d;
			}
			
			data.close();
		}

       if(token==1){
       	goto m;
	   }
	   else{
	     	data.open("productData.txt",ios::app | ios::out);            //out for writing
			data<<" "<<productcode<<" "<<name<<" "<<price<<" "<<discount<<endl;
			data.close();
	   }

        cout<<"\t\t\t\t\tRecord succesfully inserted !";
       
     cout<<"\n\n\t\t\t\t\t\tDo you want to add another product ? (y/n) ";cin>>choi;
    }
    while(choi=='y');
  
	}
	
	void shopping :: edit()
	{
		char choice;
		do{
		
		fstream data,data1;
		float pc;
		int c;
		float d;
		string n;
		float p;
		int token=0;
		int pkey;
		
		cout<<"\n\t\t\t\t Modify the record : ";
		cout<<"\n\t\t\t\t Product Code : ";cin>>pkey;
		
		data.open("productData1.txt",ios::in);
		
		if(!data){
			cout<<"\n\t\t\t\tfile doesnt exist";
		}
		else
		{
		
		data1.open("productData1.txt",ios::app | ios::out);
		data>>productcode>>name>>price>>discount;
	}
		
		while(!data.eof())
		{
		
		if(pkey == productcode)
			{
				cout<<"\n\t\t Enter new code for product: "; cin>>pc;
				cout<<"\n\t\t Name : "; cin>>n;
				cout<<"\n\t\t Price : "; cin>>p;
				cout<<"\n\t\t Discount : ";cin>>d;
				data1<<" "<<pc<<" "<<n<<" "<<p<<" "<<d<<" "<<endl;
				cout<<"\n\t\t\t\t RECORD edited ! !";
				token++;
			}
		else
		{
			data1<<" "<<productcode<<" "<<name<<" "<<price<<" "<<discount<<endl;
			}	
		data>>productcode>>name>>price>>discount;
	}
	
	data.close();
	data1.close();

	remove("productData.txt");
	rename("productData1.txt","dataProduct.txt");
	
	if(token==0){
		cout<<"\n\t\tRecord not found !";
	}
cout<<"do you want to change another record ? ";cin>>choice;
}
while(choice=='y');
}

void shopping ::Remove()
{
	fstream data,data1;
	int pkey;
	int token=0;
	
	cout<<"\n\t\t\t\t Delete Product";	
	cout<<"\n\n\n\t\t\t\t Enter product code: "; cin>>pkey;
	data.open("productData.txt",ios::in);
	if(!data){
	cout<<"\n\t\t\tFile does not Exist ";	
}
else{
	data1.open("productData.txt",ios::app |ios::out);
    data>>productcode>>name>>price>>discount;
    
    while(!data.eof())
    {
    	if(productcode==pkey){
    		cout<<"\n\t\tProduct deleted succesfully !";
			token++ ;
			}
		else{
			data1<<" "<<productcode<<" "<<name<<" "<<price<<" "<<discount<<endl;
			}	
		data>>productcode>>name>>price>>discount;	
	}
	data.close();
	data1.close();

	remove("productData.txt");
	rename("productData1.txt","dataProduct.txt");
	
	if(token==0){
		cout<<"\n\t\t Record not found !";
	}
}
}

void shopping :: list()
{
	fstream data;
	data.open("productData.txt",ios::in);
	cout<<"\n\n\n____________________________________________________________________________\n";
	cout<<"Pno.\t\tName\t\tPrice\t\tDiscount\n";
	cout<<"___________________________________________________________________________\n";
	data>>productcode>>name>>price>>discount;

    while(!data.eof())
    {
    	cout<<productcode<<"\t\t"<<name<<"\t\t"<<price<<"\t\t"<<discount<<"\n";
    	data>>productcode>>name>>price>>discount;
	}
    data.close();
}

void shopping :: receipt()
{
	fstream data;
	int arrcode[100];
	int arrayquantity[100];
	int c=0;
	float amount;
	float dis=0;
	float total=0;
	char choice;
	

	
	data.open("productData.txt",ios::in);
	if(!data)
	{
		cout<<"\n\nEmpty data !";
	}
    else{
    	data.close();
    	list();
    	cout<<"\n\n\n";
		cout<<"\t\t\t\t__________________________\n";
    	cout<<"\t\t\t\t          Place order      \n";
    	cout<<"\t\t\t\t__________________________\n\n";
    	do
    	{
		
    	cout<<"Enter product code : ";cin>>arrcode[c];
    	cout<<"Enter product Quantity : ";cin>>arrayquantity[c];
    	for(int i=0;i<c;i++){
    		if(arrcode[c] ==arrcode[i])
    		{
    			cout<<"product code repeated. please try again !";
    	//		goto m;
			}
	
		}
    		c++;
    		cout<<"\n\ndo you want to buy another product (y/n) ?";
    		cin>>choice;
	}
	while(choice=='y');
	system("cls");
	cout<<"\n\n\\n\n\n";
	cout<<"\t\t\t\t\t\t________________________________________\n";
	cout<<"\t\t\t\t\t\t                RECEIPT                      \n";
	cout<<"\t\t\t\t\t\t_________________________________________\n\n\n";
	
	cout<<"\nProduct Code\t\tProduct Name\t\tQuantity\t\tPrice\t\t\tDiscount\t\t\t Total";
	
	for(int i=0;i<c;i++){
		data.open("productData.txt",ios::in);
        data>>productcode>>name>>price>>discount;
		
		while(!data.eof())
		{
			if(productcode==arrcode[i]){
				amount=price*arrayquantity[i];	
				discount=amount-(amount*discount/100);
				total+=discount;
				cout<<"\n"<<productcode<<"\t\t\t"<<name<<"\t\t"<<arrayquantity[i]<<"\t\t"<<price<<"\t"<<amount<<"\t\t"<<discount;
		}
	data>>productcode>>name>>price>>discount;
}

}
data.close();
}
cout<<"\n\n\t\t\t_________________________________________________\n\n";
cout<<"\n\t\t\t Total amount : "<<total;

}

int main(){
	
	shopping s;
	s.menu();
}
