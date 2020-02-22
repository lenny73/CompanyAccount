# include <iostream>
# include <fstream>
# include <string>
# include <iomanip>
using namespace std;

class Master {
	public:
		
		char name[100];
		double number;
		double currentBalance;
};

class Transaction {
	public:
		
		char items[100];
		char type;
		int number;
		int Tnumber;
		int quantity;
		double price;
		double paid;
};



int main (){
	
	ifstream master; 
	master.open("master.txt");
	ifstream trans;
	trans.open ("trans.txt");
	int prevbalance[100];
	Master m [100];
	double companyB = 0,orderAmount=0;
	Transaction t[35];
	int codelist[100];
	int n,tn,print,choice,code;

if ((!master) && (!trans)){
	cout << "File not found!" << endl << endl;
		system("pause");
	return 1;
	}

for (int i=0; !master.eof(); i++) {
	master>>m[i].number>>m[i].name>>m[i].currentBalance;
	}

for (int i=0;!master.eof();i++) {
	cout << m[i].number<<"\n ";
	cout << m[i].name<<"\n ";
	cout << m[i].currentBalance<<"\n ";
	prevbalance[i] = m[i].currentBalance;
	}

for (int i=0; !trans.eof(); i++) {
	trans>> t[i].type;

if (t[i].type == 'O') {
	trans>>t[i].number;
	trans>> t[i].Tnumber;
	trans>>t[i].items;
	trans>>t[i].quantity;
	trans>>t[i].price;

	orderAmount= t[i].price*t[i].quantity;

	m[i].currentBalance+= orderAmount;

	companyB += m[i].currentBalance;

	}
if (t[i].type == 'P'){
	trans>>t[i].number;
	trans>> t[i].Tnumber;
	trans>>t[i].paid;

	m[i].currentBalance-t[i].paid;

	companyB += m[i].currentBalance;

	}}
do{
	
	ifstream inFile;
	inFile.open("code.txt");
	for (int i =0; i<=3; i++)
	{inFile>>codelist[i];}
	cout<<"\nEnter Admin Code";
	cin>>code;
	for(int i=0;i<=3;i++){
	if(code==codelist[i]){
		cout<<"\nAdmin menu:\n1.Show resultT\n2.Print list\n3.view transaction list" ;
		cin>>choice;
		
		if(choice==1){
		cout<<"\nEnter number of customers do you want to see?";
		cin>>n;
		cout<<"\nEnter how many transactions do you want to see";
		cin>>tn;
		for(int i=0; i<n; i++) {
		cout<<"\n\nName: "<< m[i].name <<"\nCustomer #: "<< m[i].number;
		cout<<"\nPrevious Balance "<<prevbalance[i];

		for(int j=0; j<tn; j++){
		cout<<"\nTransaction #: "<<t[j].Tnumber<<" "<<t[j].items<<" $"<<orderAmount; 
		cout<<"\nBalance Due: "<<m[i].currentBalance;}}

		}
		if(choice==2){
		ofstream file;  
		file.open("totalresult.txt",  ios::out | ios::app);
		cout<<"\n Would you like to print?"<<"\ny or n";
		cin>>print;
			if(print==1){
			cout<<"\nEnter number of customers do you want to see?";
			cin>>n;
			cout<<"\n How many transaction?";
			cin>>tn;
				for(int i=0; i<n; i++) {
				file<<"\n\nName: "<< m[i].name <<" Customer #: "<< m[i].number;
				file<<"\nPrevious Balance "<<prevbalance[i];}
			
   				for(int i = 1; i <= tn; i++){
  
				file<<"\n\nTransaction #:"<<t[i].Tnumber
				<<"  "<<t[i].items
	            <<" $"<<orderAmount
				<<"\nBalance Due: "<<m[i].currentBalance;
				}
				file.close();}
			if(print!=1) {
			cout<<"\n without print";
			}
		}
		if(choice==3){
			if (t[i].type == 'O') {
			cout<<t[i].type<<" ";
			cout<<t[i].number<<" ";
			cout<<t[i].Tnumber<<" ";
			cout<<t[i].items<<" ";
			cout<<t[i].quantity<<" ";
			cout<<t[i].price<<"\n\n ";
			cout<<companyB;}
			
			if (t[i].type == 'P') {
			cout<<t[i].number<<" ";
			cout<<t[i].Tnumber<<" ";
			cout<<t[i].paid<<"\n\n ";
			}
		}
	}
		if(n!=codelist[i]){"Enter correct code";}
	
}}while(true);

return 0;

}
