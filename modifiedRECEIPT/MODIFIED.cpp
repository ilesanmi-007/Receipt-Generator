#include <iostream>
#include <iomanip>
using namespace std;

struct customer
{
	char name[30];
	char phoneNumber[15];
	char address[50];
};

struct product
{
	int quantity;
	char name[30];
	float price;
};

struct details
{
	product myproduct;
	customer mycustomer;
};

//functions prototype:
void introduction();
void customerDetails(details*);
void product_details(details [], int*);
void printreceipt(details [], details, int);


details info;
int main()
{

	cout<<"hello world"<<endl;
	details info;
	int numofproduct;
	details inform[20];
	introduction();
	system("cls");
	customerDetails(&info);
	//system("cls");
	product_details(inform, &numofproduct);
	//system("cls");

	printreceipt(inform , info, numofproduct);


	cout<<" #ilesanmi's_touch"<<endl;
	return 0;
}


void introduction()
{
	cout<<"**********welcome to ILESANMI ENTERPRISES*******"<<endl;
	cout<<"we deal with all kinds of products; tech, devices etc"<<endl;
}

void customerDetails(details* info)
{
	cout<<endl;
	cout<<"please fill in the following details: "<<endl<<endl;
	cout<<"enter your name: ";
	cin.getline(info->mycustomer.name,29);
	cout<<"enter your phone number: ";
	cin.getline(info->mycustomer.phoneNumber, 14);
	cout<<"enter your address: ";
	cin.getline(info->mycustomer.address, 49);
}

void product_details(details infor[20],  int *numofproduct)
{
	cout<<endl;
	cout<<"enter the number of goods you wanna buy: ";
	cin>>*numofproduct;	
	cout<<endl;
	char junk;
	for(int i = 0; i < *numofproduct; i++)
	{
		cout<<"enter name of product: ";
		cin>>junk;
		cin.ignore();
		cin.getline(infor[i].myproduct.name, 29);
		cin.ignore();

		cout<<"enter quantity of product: ";
		cin>>infor[i].myproduct.quantity;
		cin.ignore();

		cout<<"enter price of each: ";
		cin>>infor[i].myproduct.price;
		cin.ignore();
		cout<<endl;
		system("cls");
	}
}


void printreceipt(details Realdeal[20], details info, int numofproduct)
{
	cout<<"               ILESANMI ENTERPRISES"<<endl;
	cout<<"       34, berger street, okoafo, badagry, lagos."<<endl;
	cout<<"                                                             "<<endl;
	cout<<"                                                             "<<endl;
	cout<<"                                                             "<<endl;

	float partT = 0, total[30];

	cout<<"name: "<<info.mycustomer.name<<endl;
	cout<<endl;
	cout<<"address: "<<info.mycustomer.address<<endl;
	cout<<endl;
	cout<<"phone Number: "<<info.mycustomer.phoneNumber<<endl;
	cout<<endl;

	for (int i = 0; i< numofproduct;  i++)
	{
		total[i] = partT + (Realdeal[i].myproduct.price * Realdeal[i].myproduct.quantity);
	}

	cout<<"                 goods bought"<<"         "<<"QUANTITY BOUGHT"<<"       "<<"TOTAL PRICE PER PRODUCT"<<endl;


	for (int i = 0; i < 1; i++)
	{
		for (int j =0; j<numofproduct; j++)
		{
			cout<<Realdeal[j].myproduct.name<<setw(15)<<"|"<<setw(5)<<Realdeal[j].myproduct.quantity
				<<setw(15)<<"|"<<setw(5)<<Realdeal[j].myproduct.price<<setw(15)<<"|"<<setw(5)<<total[j]<<endl;
			cout<<"-------------------------------------------------------------------------------"<<endl;
		}

	
	}

	float finalTotal = 0;
	for (int i = 0; i<1; i++)
	{
		for (int j = 0; j<numofproduct; j++)
		{
			finalTotal = finalTotal + total[j];
		}
	}

	cout<<"                                                                "<<finalTotal<<endl;
}