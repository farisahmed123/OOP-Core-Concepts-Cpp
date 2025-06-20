#include<iostream>
using namespace std;
class Bike_price                             // 1st class
{
	private : 
	int price;
	public:
		Bike_pirce()
		{
		price = 0;	
		}
	void setBikePrice(int x)
	{
		price = x;
	}
	int getBikePrice()
	{
		return price;
	}
};
class Bike_Specifiaction                            // 2nd class
{
	string Bike_torque;                      // private member of class
	int Bike_speed;                       // private member of class
	int Bike_tyres;                       // private member of class
	public:
		Bike_Specifiaction()
		{
		Bike_torque = "N/A";
		Bike_speed = 0;
		Bike_tyres = 0; 
		} 
		
		void setBikeTorqe(string x)
		{
			Bike_torque = x;
		}
		string getBikeTorqe()
		{
			return Bike_torque;
		}
		void setBikeSpeed(int y)
		{
			Bike_speed = y;
		}
		int getBikeSpeed()
		{
			return Bike_speed;
		}
		void setBikeTryes(int z)
		{
			Bike_tyres = z;
		}
		int getBikeTyres()
		{
			return Bike_tyres;
		}
};
class Bike_Detail                                   // 3rd class
{
	private : 
	int Brake;                           // private member class
	int fuel_tank;                    // private member class
	public:
		Bike_Detail()
		{
			Brake = 0;
		}
		Bike_Specifiaction a;                  // OBJ of 2nd Class in 3rd class
		void setBrake(int x)
		{
			Brake = x;
		}
		int getBrake()
		{
			return Brake;
		}
		void setFueltank(int x)
		{
			fuel_tank = x;
		}
		int getFueltank()
		{
			return fuel_tank;
		}
		
};
class Bike_Engine                         // 4th class
{
	int engine;                          // private member class
	public : 
	Bike_engine()
	{
		engine = 0;
	}
	void setEngine(int z)
	{
		engine  = z;
	}
	int getEngine()
	{
		return engine;
	}
};
class Bike_Model                       // 5th class
{
	int model;                     // private member class
	public : 
	Bike_Model()
	{
		model = 0;
	}
	void setBikeModel(int y)
	{
		model = y;
	}
	int getBikeModel()
	{
		return model;
	}
};
class Bike                          // Main Class
{
	private : 
	string Bike_Name;                // private member of Main Class
	public : 
	Bike()
	{
		Bike_Name = "N/A";
	}
	void setBikeName(string x)
	{
		Bike_Name = x;
	}
	string getBikeName()
	{
		return Bike_Name;
	}
	Bike_Model  a;                   // 1st class OBJ
	Bike_Engine b;                   // 2nd class OBJ
	Bike_price  c;                   // 3rd class OBJ
	Bike_Detail d;                   // 4th class OBJ
	Bike_Specifiaction e;            // 5th class OBJ
};
int main()       // Main Body
{
	cout<<"\t\t-------------------- WELCOME TO BIKE COMPANY ----------------------\n\n";
	Bike a;                // Main Class OBJ
	string x;
	cout<<"Set Name of Bike : ";
	cin>>x;
	a.setBikeName(x);
	cout<<endl;
	
	int y;
	cout<<"Model Must Be Grater then 1990 and less then 2024"<<endl<<endl;
	do{
	cout<<"Set Model of Bike : ";
	cin>>y;
	if(y < 1990 || y > 2023)
	{
		cout<<"\t\t\t\tPlease re-enter Model"<<endl;
	}
	a.a.setBikeModel(y);
}while(y < 1990 || y > 2023);

	cout<<endl;
	
	int z;                                            // Bike Engine-Number
	cout<<"Set Engine number of Bike : ";
	cin>>z;
	a.b.setEngine(z);
	
	cout<<endl;
	
	int w;                                                                                     // Bike Price
	cout<<"Bike Price Must be Grater Then 10000 bohtt mehngaii hey bhaii "<<endl<<endl;
	do
	{
	cout<<"Set Price of Bike : ";
	cin>>w;
	if(w < 10000)
	{
		cout<<"\t\t\t\tre-enter Price"<<endl;
	}
	a.c.setBikePrice(w);
}while(w < 10000);

	cout<<endl;
	
	int brake;                                                        // Bike Brake
	   cout<<"Maximum Brake You Can Set is 4 "<<endl<<endl;
   do{
	cout<<"Set Brake of Bike : ";
	cin>>brake;
		if(brake > 4)
   	{
   		cout<<"\t\t\t\tbreak Must be Less Than 5  "<<endl;
	}
	a.d.setBrake(brake);
}
while(brake > 4);

cout<<endl;

	int Fueltank;                                                            // Bike Fuel-Tank
	   cout<<"Maximum Fuel Tank Capacity You Can Set is 30L "<<endl<<endl;
	do{
	cout<<"Set Capacity of Fuel Tank of Bike : ";
	cin>>Fueltank;
	if(Fueltank > 30)
	{
		cout<<"\t\t\t\tFuel Tank Must be less than 31L  "<<endl;
	}
	a.d.setFueltank(Fueltank);
}while(Fueltank > 30);

cout<<endl;

	string torque;                                                            // Bike Torque
	cout<<"Set Torqeu Of Bike : ";
	cin>>torque;
	a.d.a.setBikeTorqe(torque);
	
	cout<<endl;
	
	int tyres;                                                          // Bike Tyres
	   cout<<"Maximum Tyres You Can Set is 2 "<<endl<<endl;
	do
	{
	cout<<"Set Bike Tyres : ";
	cin>>tyres;
	if(tyres > 2)
		{
			cout<<"\t\t\t\tMaximum Tyres you can is atmost 2  "<<endl;
		}
	a.d.a.setBikeTryes(tyres);
}while(tyres > 2);

cout<<endl;

	int speed;                                                                 // Bike Speed
	   cout<<"Maximum Speed You Can Set is 300 "<<endl<<endl;
	do{
	cout<<"Set Maximum Speed of Bike : ";
	cin>>speed;
	if(speed > 300)
	{
		cout<<"\t\t\t\tMaximum Speed Of Bike In not more than 300  "<<endl;
	}
	a.d.a.setBikeSpeed(speed);
}while(speed > 300);

cout<<endl;
cout<<endl;

	int input;
	do{
	cout<<"1. For See Bike full Data : \n\n";
	cout<<"2. For Update Bike Price : \n\n";
	cout<<"3. For Update Bike Model : \n\n";
	cout<<"4. For Update Bike Name : \n\n";
	cout<<"5. For Updated Bike Speed : \n\n";
	cout<<"0. For Logout : \n\n";
	cout<<"Enter Your Option : ";
	cin>>input;
	cout<<endl;
	if(input == 1)                         // Full Data 
	{
		cout<<"----------------------------BIKE DETAIL-------------------------------"<<endl<<endl;
		cout<<"NAME : "<<a.getBikeName()<<endl;
		cout<<"ENGI : "<<a.b.getEngine()<<endl;
		cout<<"MODEL : "<<a.a.getBikeModel()<<endl;
		cout<<"PRICE : "<<a.c.getBikePrice()<<endl;
		cout<<"BRAKE : "<<a.d.getBrake()<<endl;
		cout<<"FUEL  : "<<a.d.getFueltank()<<endl;
		cout<<"SPEED : "<<a.d.a.getBikeSpeed()<<endl;
		cout<<"TYRES : "<<a.d.a.getBikeTyres()<<endl;
		cout<<"TORQU : "<<a.d.a.getBikeTorqe()<<endl<<endl;
	}
	if(input == 2)                         // Update Price
	{
		int x;
		cout<<"Enter Your Updated Bike Price : ";
		cin>>x;
		a.c.setBikePrice(x);
		cout<<"Price Updated "<<endl<<endl;
	}
	if(input == 3)                      // Update Model
	{
		int y;
		cout<<"Enter Your Updated Bike Model : ";
		cin>>y;
		a.a.setBikeModel(y); 
		cout<<"Model Updated"<<endl<<endl;
	}
	if(input == 4)                       // Update Name
	{
		string y;
		cout<<"Enter Your Updated Bike Name : ";
		cin>>y;
		a.setBikeName(y);
		cout<<"Name Updated"<<endl<<endl;
	}
	if(input == 5)                      // Update Speed
	{
		int speed;
		cout<<"Enter Your Updated Bike Speed : ";
		cin>>speed;
		a.d.a.setBikeSpeed(speed);
		cout<<"Speed Updated"<<endl<<endl;
	}

}
while(input != 0);
}

