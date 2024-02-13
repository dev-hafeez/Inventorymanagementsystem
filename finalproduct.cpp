#include<iostream>
#include<string>
#include<fstream>
using namespace std;
int i;
struct productinformation{
	char productname[30];
	int  productid;
	int  productquantity;
	int  productprice;
}product[20];
void Buyproduct();
void Customer();
void Administration();
void Addproduct();
void Showproduct();
void showproduct();
void Showproductlist();
void ShowproductList();
void Delete();
int main(){
	int option;
	cout<<"\n\n\t\t\t\t\t\t***MAIN MENU***"<<endl<<endl;
	cout<<"Select any option from the following : "<<endl<<endl;
	cout<<"1. ADMINSTRATION "<<endl;
	cout<<"2. CUSTOMER"<<endl;
	cout<<"3. Exit\n"<<endl; 
	cout<<"Option : ";
	cin>>option;
	if(option==1){
	int incorrectattempts=0;
	while (incorrectattempts<3){
	string entry;
	string password= "Admin123";
	cout << "Enter Password: ";
	cin >> entry; 
	if (entry == password){
		cout<<"Access Granted"<<endl<<endl<<endl;
		Administration();
		}
	else {
		cout << "Incorrect Password..."<<endl;
	}
		incorrectattempts++;
		if (incorrectattempts==3){
			cout << "\nExiting Program...";
		}
		
	}
	}
	else if (option==2){
		Customer();
	}
	else if(option== 3){
		cout << "Exiting Program...Thank You...";
		
	}
	else{
		cout<<"\t\t\t\t\t\t-Invalid Entry- ";
		main();
	}
	return 0;
}
void Administration(){
	int option;
	cout<<"\t\t\t\t\t\t-ADMINISTRATION- "<<endl<<endl<<endl;
	cout<<"Select any option from the following : "<<endl<<endl;
	cout<<"1. ADD PRODUCT        ."<<endl;
	cout<<"2. SHOW PRODUCT LIST  ."<<endl;
	cout<<"3. SEARCH PRODUCTS    ."<<endl;
	cout<<"4. CLEAR PRODUCT LIST ."<<endl;
	cout<<"5. MAIN MENU          ."<<endl<<endl;
	cout<<"Option : ";
	cin>>option;
	if(option==1){
		Addproduct();
	}
	else if(option==2){
		Showproductlist();
	}
	else if(option==3){
		Showproduct();
	}
	else if (option==4){
		Delete();
	}
	else if (option==5){
		main();
	}
	else{
		cout<<"INVALID ENTRY";
		Administration();
	}
}
void Addproduct() {
    ofstream output;
    output.open("Data.txt", ios::app);
    cout << "\n\t\t\t\t\t\t-ADD PRODUCT- " << endl << endl;
    cout<<"PRODUCT NAME     : ";
    cin>>product[i].productname;
    output<<product[i].productname << "  ";

    cout<<"PRODUCT ID       : ";
    cin>>product[i].productid;
    output<<product[i].productid << "  ";

    cout<< "PRODUCT QUANTITY : ";
    cin>> product[i].productquantity;
    output << product[i].productquantity << "  ";

    cout<< "PRODUCT PRICE (1): ";
    cin>> product[i].productprice;
    output<< product[i].productprice << endl;

    cout<< "\t\t\t\t\t---PRODUCT ADDED SUCCESSFULLY---" << endl;
    output.close();
    i++;
    cout << i;
    Administration();
}
void Showproduct() {
    cout << "\n\t\t\t\t\t\t-SEARCH PRODUCTS- " << endl << endl;
    ifstream input("Data.txt", ios::in);
    cout << "Enter the name of product: ";
    string name;
    cin >> name;
    while (input >> product[i].productname >> product[i].productid >> product[i].productquantity >> product[i].productprice) {
    int j;
    for (j = 0; name[j] != '\0' && product[i].productname[j] != '\0'; j++) {
    if (name[j] != product[i].productname[j]) {
    break;
    }
    }
    if (name[j] == '\0' && product[i].productname[j] == '\0') {
	cout<<"==================================="<<endl;
    cout << "PRODUCT NAME     : " << product[i].productname << endl;
    cout << "PRODUCT ID       : " << product[i].productid << endl;
    cout << "PRODUCT QUANTITY : " << product[i].productquantity << endl;
    cout << "PRODUCT PRICE (1): " << product[i].productprice << endl;
	cout<<"==================================="<<endl;
	break;
    }
        i++;
    }
    input.close();
    Administration();
}
void showproduct() {
    cout << "\n\t\t\t\t\t\t-SEARCH PRODUCTS- " << endl << endl;
    ifstream input("Data.txt", ios::in);
    cout << "Enter the name of product: ";
    string name;
    cin >> name;
    while (input >> product[i].productname >> product[i].productid >> product[i].productquantity >> product[i].productprice) {
    int j;
    for (j = 0; name[j] != '\0' && product[i].productname[j] != '\0'; j++) {
    if (name[j] != product[i].productname[j]) {
    break;
    }
    }
    if (name[j] == '\0' && product[i].productname[j] == '\0') {
	cout<<"==================================="<<endl;
    cout << "PRODUCT NAME     : " << product[i].productname << endl;
    cout << "PRODUCT ID       : " << product[i].productid << endl;
    cout << "PRODUCT QUANTITY : " << product[i].productquantity << endl;
    cout << "PRODUCT PRICE (1): " << product[i].productprice << endl;
    cout<<"==================================="<<endl;
	break;
    }
        i++;
    }
    input.close();
    Customer();
}
void Customer(){
	int option;
	cout<<"\t\t\t\t\t\t-CUSTOMER- "<<endl<<endl;
	cout<<"Select any option from the following : "<<endl<<endl;
	cout<<"1. SEARCH PRODUCTS   ."<<endl;
	cout<<"2. SHOW PRODUCT LIST ."<<endl;
	cout<<"3. BUY PRODUCT       ."<<endl;
	cout<<"4. MAIN MENU         ."<<endl<<endl;
	cout<<"Option : ";
	cin>>option;
	if(option==1){
		showproduct();
	}
	else if(option==2){
		ShowproductList();
	}
	else if(option==3){
		Buyproduct();
	}
	else if (option==4){
		main();
	}
	else{
		cout<<"\t\t\t\t\t\tINVALID ENTRY ";
		Customer();
	}
}
void Buyproduct() {
    cout << "\n\t\t\t\t\t\t-BUY PRODUCT- " << endl << endl;
    ifstream input("Data.txt", ios::in);
    ofstream tempFile("temp.txt", ios::out);
    cout << "Enter the name of product: ";
    string name;
    cin >> name;
    productinformation product;
    bool productFound = false;
    while (input >> product.productname >> product.productid >> product.productquantity >> product.productprice) {
        if (product.productname == name) {
            productFound = true;
            product.productquantity -= 1;
            cout<<"==========================="<<endl;
            cout<<"PRODUCT NAME  : "<<product.productname<<endl;
            cout<<"PRODUCT ID    : "<<product.productid<<endl;
            cout<<"PRODUCT PRICE : "<<product.productprice<<" $ "<<endl;
            cout<<"==========================="<<endl;
        }
        tempFile << product.productname << " " << product.productid << " " << product.productquantity << " " << product.productprice << endl;
    }
    input.close();
    tempFile.close();
    if (productFound) {
        remove("Data.txt");
        rename("temp.txt", "Data.txt");
        cout << "Product bought successfully." << endl;
    } else {
        cout << "Product not found." << endl;
    }
    Customer();
}
void Delete(){
	ofstream output;
	output.open("Data.txt");
	output.close();
	cout<<"Product List is cleared Successfully "<<endl;
	Administration();
}
void Showproductlist(){
	ifstream input;
	input.open("Data.txt",std::ios::app);
	cout<<"\n\t\t\t\t\t\t---SHOW PRODUCT LIST--- "<<endl<<endl;
	for(int i=0;i<20;i++){
	if(input.eof()){
		cout<<"End of list "<<endl;
		cout<<"==================================="<<endl;		
		break;
	}
	else{
		cout<<"==================================="<<endl;		
		cout<<"PRODUCT NAME       : ";
		input>>product[i].productname;
		cout<<product[i].productname<<endl;
		cout<<"PRODUCT ID         : ";
		input>>product[i].productid;
		cout<<product[i].productid<<endl;
		cout<<"PRODUCT QUANTITY   : ";
		input>>product[i].productquantity;
		cout<<product[i].productquantity<<endl;
		cout<<"PRODUCT PRICE (1)  : ";
		input>>product[i].productprice;
		cout<<product[i].productprice<<endl;
		cout<<"==================================="<<endl;		
	}
	}
	input.close();
	Administration();
};
void ShowproductList(){
	ifstream input;
	input.open("Data.txt",std::ios::app);
	cout<<"\n\t\t\t\t\t\t---SHOW PRODUCT LIST--- "<<endl<<endl;
	for(int i=0;i<20;i++){
	if(input.eof()){
		cout<<"End of list "<<endl;
		cout<<"==================================="<<endl;
		break;
	}
	else{
		cout<<"==================================="<<endl;
		cout<<"PRODUCT NAME       : ";
		input>>product[i].productname;
		cout<<product[i].productname<<endl;
		cout<<"PRODUCT ID         : ";
		input>>product[i].productid;
		cout<<product[i].productid<<endl;
		cout<<"PRODUCT QUANTITY   : ";
		input>>product[i].productquantity;
		cout<<product[i].productquantity<<endl;
		cout<<"PRODUCT PRICE (1)  : ";
		input>>product[i].productprice;
		cout<<product[i].productprice<<endl;
		cout<<"==================================="<<endl;		
	}
	}
	input.close();
	Customer();
};
