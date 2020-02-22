# include <iostream>
# include <fstream>
# include <iomanip>
# include <string>
using namespace std;

class master {
	public:
double custnum;
char name[100];
double balance;
};

class transactions {
	public:
char transtype;
int custnum;
int transnum;
char item[100];
int quantity;
double price;
double amountpaid;
};

int main ()
{
ifstream masterfile ("master.txt");
ifstream transfile ("trans.txt");
int prevbalance[100];
master main [100];

for (int i=0; !masterfile.eof(); i++) {
masterfile>>main[i].custnum>>main[i].name>>main[i].balance;
}

for (int i=0;!masterfile.eof();i++) {
cout << main[i].custnum<<" ";
cout << main[i].name<<" ";
cout << main[i].balance<<" "<<
endl<<endl;
prevbalance[i] = main[i].balance;
}

double companybalance = 0;
double orderamt=0;

transactions tran[35];
for (int i=0; !transfile.eof(); i++) {
transfile>> tran[i].transtype;
cout<<tran[i].transtype<<" ";

if (tran[i].transtype == 'O') {
transfile>>tran[i].custnum;
cout<<tran[i].custnum<<" ";

transfile>> tran[i].transnum;
cout<<tran[i].transnum<<" ";

transfile>>tran[i].item;
cout<<tran[i].item<<" ";

transfile>>tran[i].quantity;
cout<<tran[i].quantity<<" ";

transfile>>tran[i].price;
cout<<tran[i].price<<" "<<endl<<endl;

orderamt= tran[i].price*tran[i].quantity;
main[i].balance+= orderamt;

companybalance += main[i].balance;

}
else if (tran[i].transtype == 'P'){
transfile>>tran[i].custnum;
cout<<tran[i].custnum<<" ";

transfile>> tran[i].transnum;
cout<<tran[i].transnum<<" ";

transfile>>tran[i].amountpaid;
cout<<tran[i].amountpaid<<endl<<endl<<endl;

main[i].balance-tran[i].amountpaid;

companybalance += main[i].balance;

}}

for(int i=0; i<50; i++) {
cout<<"Name: "<< main[i].name <<" Customer #: "<< main[i].custnum<<endl<<endl;
cout<<"Previous Balance "<<prevbalance[i]<<endl;
for(int j=0; j<7; j++){
cout<<"Transaction #: "<<tran[j].transnum<<" "<<tran[j].item<<" $"<<orderamt<<endl; }
cout<<"Balance Due: "<<main[i].balance<<endl;
}
}
