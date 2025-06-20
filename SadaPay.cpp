#include<iostream>
using namespace std;

class SadaPay{
	private:
	int balance;
	string Account_name;
	int Account_number;
	int phone_number;
	string Birth;
	string email;
	string address;
	public:
		SadaPay(int blnc, string acc_name, int acc_No , string add, string ema, int phn_no, string birth)
		{
			balance = blnc;
			Account_name = acc_name;
			Account_number = acc_No;
			phone_number = phn_no;
			Birth = birth;
			email = ema;
			address = add;
		}
		~SadaPay()
		{
			cout<<"Allah Hafiz\n";
		}
		void Withdraw();
		void Depostie_Money();
		void Display();
		void UpdateName();
		void UpdateAccountNmber();
		void UpdateBlnce();
		void Display_Balance();
		void Transfer();
		void More();
};

void SadaPay :: Depostie_Money()
{
	int Money_Deposite;
	cout<<"Enter Your Deposit Money here : ";
	cin>>Money_Deposite;
	balance = balance + Money_Deposite;
	cout<<endl;
	cout<<"Monye Deposited Succesfull"<<endl<<endl;
}

void SadaPay :: Withdraw()
{
	int withdraw;
	cout<<"Enter Your Withdraw Money here : ";
	cin>>withdraw;
	cout<<endl;
	if(withdraw > balance)
	{
		cout<<"Cannot Withdraw Money"<<endl<<endl;
	}
	else
	{
		balance = balance - withdraw;
		cout<<"Withdraw Succesfull"<<endl<<endl;
	}
}

void SadaPay :: Transfer()
{
	int number;
	cout<<"Enter Number To the Money trasferred : ";
	cin>>number;
	int trasnfer_money;
	cout<<"Enter Your Money to be Trasnfeered : ";
	cin>>trasnfer_money;
	cout<<endl;
	if(trasnfer_money > balance)
	{
		cout<<"Transferred Failed"<<endl<<endl;
	}
	else
	{
		balance = balance - trasnfer_money;
		cout<<"Money Trasfered to the number : "<<number<<endl<<endl;
	}
}

void SadaPay :: UpdateName()
{
	string Updated_Name;
	cout<<"Enter Your Updated Name here : ";
	cin>>Updated_Name;
	Account_name = Updated_Name;
	cout<<endl;
	cout<<"Name Updated "<<endl<<endl;;
}

void SadaPay :: UpdateBlnce()
{
	int new_balance;
	cout<<"Enter Updated Balance : ";
	cin>>new_balance;
	balance = new_balance;
	cout<<endl;
	cout<<"Balance Updated "<<endl<<endl;
}

void SadaPay :: UpdateAccountNmber()
{
	int new_acc_num;
	cout<<"Enter Your Updated Account Number : ";
	cin>>new_acc_num;
	Account_number = new_acc_num;
	cout<<endl;
	cout<<"Account Number Updated"<<endl;
}

void SadaPay :: Display_Balance()
{
	cout<<"Your Current Balance : "<<balance<<endl<<endl;
}

void SadaPay :: Display()
{
	cout<<"Account Holder Name : "<<Account_name<<endl<<endl;
	cout<<"Account Number : "<<Account_number<<endl<<endl;
	cout<<"Account Balance : "<<balance<<endl<<endl;
	cout<<"Phone Number : "<<phone_number<<endl<<endl;
	cout<<"Email : "<<email<<endl<<endl;
	cout<<"Address : "<<address<<endl<<endl;
	cout<<"Birth Date : "<<Birth<<endl<<endl;
}

void SadaPay :: More()
{
	cout<<"Account Holder Name : "<<Account_name<<endl<<endl;
	int inp;
do
{
	cout<<"1.  Rewards : \n\n";
	cout<<"2.  Info : \n\n";
	cout<<"0.  Exit : \n\n";
	cout<<"----------------------\n";
	cout<<"Enter Your Option : ";
	cin>>inp;
	cout<<"----------------------\n";
	
	cout<<endl;
if(inp == 1)
{
		int input;
do
{
		cout<<"1.  Golden Ticket : \n\n";
		cout<<"2.  Invite Freinds : \n\n";
		cout<<"0.  Exit : \n\n";
		cout<<"----------------------\n";
		cout<<"Enter Your Option : ";
		cin>>input;
		cout<<"----------------------\n";
		cout<<endl;
        if(input == 1)
		{
		int ticket;
		cout<<"Press 1 For Golden ticket : ";
		cin>>ticket;
		cout<<endl;
		string code;
		cout<<"Enter Code HCSNSND for confirm Golden Ticket : ";
		cin>>code;
		cout<<endl;
		if(code == "HCSNSND")	
		{
			cout<<"Golden Ticket Activated "<<endl;
		}
		else
		{
			cout<<"Golden Ticket Failed"<<endl;
		}
		}
	if(input == 2)
	{
		cout<<"Advantage of Invite Freinds\n\n";
		cout<<"1. Speed Up Your SadaPay Account\n";
		cout<<"2. Fast Transaction\n";
		cout<<"3. No Lag Issue\n\n";
		int inpt;
		cout<<"Press 1 for Invite Your Freinds : ";
		cin>>inpt;
		cout<<endl;
		if(inpt == 1)
		{
		string name;
		cout<<"Enter Name Of your Invited Freind : ";	
		cin>>name;
		cout<<endl;
		int phn_no;
		cout<<"Enter Phone Number Of your freind : ";
		cin>>phn_no;
		cout<<endl;
		cout<<"Invitation Done "<<endl<<endl;
		}	
	}	
}while(input != 0);

}
		
if(inp == 2)
{
			int inputt;
do
{
			    cout<<"1.  For Information : \n\n";
			    cout<<"2.  Terms And Condition : \n\n";
		    	cout<<"3.  Schedule Of Charges : \n\n";
	     		cout<<"0.  Exit : \n\n";
				cout<<"----------------------\n";
		        cout<<"Enter Your Option : ";
		        cin>>inputt;
		        cout<<"----------------------\n";
				if(inputt == 1)
				{
					cout<<endl;
					cout<<"->  Your Name , Your Phone number , email , address , date of Birth \n->  and other Informtaion provided when you create your Account"<<endl;
					cout<<"->  You Can Deposite Your Money , Withdraw Your Money , \n->  Get Debit Card , Easy Shopping , Easy Transaction throug SadaPay"<<endl;
					cout<<"->  Data processors to process your information on our behald\n";
					cout<<"->  Third / Party services whom you have asked us to integrate with, such as Social Network\n";
					cout<<"->  Head office of SadaPay  Ufone Tower 9th floor Blue area, Islamabad\n";
					cout<<"->  SadaPay Lahore Office   Naveena Tower 6th Floor 35C Gulberg\n\n";
				}
				
				if(inputt == 2)
				{
					cout<<endl;
					cout<<"MAKING PAYMENTS\n";
					cout<<"->  your instructions are unclear\n";
					cout<<"->  we suspect fraud or crminal activity on your account\n";
					cout<<"->  we`re not allowed to make the transfer bu law\n\n";
					cout<<"IF SOMETHING GOES WRONG\n";
					cout<<"->  it was taken after you froze your card\n";
					cout<<"->  any money you lost due to out mistakes will be returned\n";
					cout<<"->  we are availbae 24 hours for you\n\n";
				}
				
				if(inputt == 3)
				{
					cout<<endl;
					cout<<"\t\tcharges are not inclusive of tax(FED),\n\t\t\tunless otherwise stated\n\n";
					cout<<"GENERAL\n\n";
					cout<<"->  Account Opening Charges ------------------------------------ None\n";
					cout<<"->  Monthly Charges -------------------------------------------- None\n";
					cout<<"->  Anual Charges ---------------------------------------------- None\n";
					cout<<"->  Mobile Banking Fees ---------------------------------------- None\n";
					cout<<"->  SMS Fees --------------------------------------------------- None\n\n";
					cout<<"DEBIT CARD \n\n";
					cout<<"->  MasterCard Issuance ---------------------- Rs. 895(ont time)\n";
					cout<<"->  MasterCard Replacment cost ------------------------ Rs. 895\n";
					cout<<"->  PayPak fee ----------------------------------- Rs. 1200(annually)\n";
					cout<<"->  PayPak Replacement fee -------------------------------- Rs. 1200\n\n";
//					cout<<endl;
				}
}while(inputt != 0);
			
}	
}
while (inp != 0);
}

int main()
{
	cout<<"-----------------------------------------WELCOME TO SADAPAY ACCOUNT---------------------------------------------\n\n\n";
	cout<<"Create SadaPay Account\n\n";
	string Account_name;
	cout<<"Enter Your SadaPay Account Name : ";
	cin>>Account_name;
	cout<<endl;
	int number;
	cout<<"Enter Your Phone Number : ";
	cin>>number;
	cout<<endl;
	string adrres;
	cout<<"Enter Your Address : ";
	cin>>adrres;
	cout<<endl;
	string email;
	cout<<"Enter Your Email : ";
	cin>>email;
	cout<<endl;
	string birth;
	cout<<"Enter Your Date of Birth : ";
	cin>>birth;
	cout<<endl;
	int balance;
	cout<<"Enter Your Initial Money in SadaPay : ";
	cin>>balance;
	cout<<endl;
	int account_number;
	cout<<"Enter your account number : ";
	cin>>account_number;
	cout<<endl;
	string code;
	cout<<"Enter Your Code : ";
	cin>>code;
	cout<<endl;
	string confirm_code;
	
	do{
	cout<<"Re-enter Your Code for Confirmation : ";
	cin>>confirm_code;
	cout<<endl;
}
while(code != confirm_code);
	cout<<"-------------------------------------------------SadaPay Account Created-------------------------------------------------"<<endl<<endl;
	SadaPay OBJ(balance,Account_name,account_number,adrres,email,number,birth);
	int input;
	do
	{
		cout<<"1.  Depostie Money  \n\n";
		cout<<"2.  Withdraw Money  \n\n";
		cout<<"3.  Detail Account  \n\n";
		cout<<"4.  Update Account Name  \n\n";
		cout<<"5.  Update Account Balance  \n\n";
		cout<<"6.  Update Account Number  \n\n";
		cout<<"7.  Check Current Balance  \n\n";
		cout<<"8.  Money Transfer \n\n";
		cout<<"9.  More Option  \n\n";
		cout<<"0.  Logout This  \n\n";
		cout<<"----------------------\n";
		cout<<"Enter Your Option : ";
		cin>>input;
		cout<<"----------------------\n";
		cout<<endl;
		if(input == 1)
		{
//			cout<<"Welcome To Depostie System"<<endl<<endl/;
			OBJ.Depostie_Money();
		}
		
		if(input == 2)
		{
			OBJ.Withdraw();
		}
		
		if(input == 3)
		{
			OBJ.Display();
		}
		
		if(input == 4)
		{
			OBJ.UpdateName();
		}
		
		if(input == 5)
		{
			OBJ.UpdateBlnce();
		}
		
		if(input == 6)
		{
			OBJ.UpdateAccountNmber();
		}
		
		if(input == 7)
		{
			OBJ.Display_Balance();
		}
		
		if(input == 8)
		{
			OBJ.Transfer();
		}
		
		if(input == 9)
		{
			OBJ.More();
		}
		
	}
	
	while(input != 0);
}
