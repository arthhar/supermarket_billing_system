#include<iostream>
#include<fstream>

using namespace std;

class shopping{
    private:
        int pcode;
        float price;
        float dis;
        string pname;

        public:
            void menu();
            void administrator();
            void buyer();
            void add();
            void edit();
            void rem();
            void list();
            void receipt();
};

void shopping :: menu(){
    m:
    int choice;
    string email;
    string password;

    cout<<"\t\t\t\t___________________________________"<<endl;
    cout<<"\t\t\t\t                                   "<<endl;
    cout<<"\t\t\t\t       SuperMarket Main Menu       "<<endl;
    cout<<"\t\t\t\t                                   "<<endl;
    cout<<"\t\t\t\t___________________________________"<<endl;
    cout<<"\t\t\t\t                                   "<<endl;
    cout<<"\t\t\t\t|  1) Administrator   |"<<endl;
    cout<<endl;
    cout<<"\t\t\t\t|  2) Buyer           |"<<endl;
    cout<<endl;
    cout<<"\t\t\t\t|  3) Exit            |"<<endl;
    cout<<endl;
    cout<<"\t\t\t\t|  Please Select      |"<<endl;
    cin>>choice;

    switch(choice){
        case 1:
            cout<<"\t\t\t Please Login"<<endl;
            cout<<"\t\t\t Enter Email"<<endl;
            cin>>email;
            cout<<"\t\t\t Password"<<endl;
            cin>>password;

            if(email=="robby@email.com" && password=="robby@123"){
                administrator();
            }else{
                cout<<"Invalid email/password"<<endl;
            }
            break;
    
        case 2:
            buyer();
        
        case 3:
            exit(0);

            default:
                cout<<"Please select from given options"<<endl;
    }

    goto m;
}

void shopping :: administrator(){
    m:
    int choice;
    cout<<"\n\n\n\t\t\t Administrator menu ";
    cout<<"\n\t\t\t|   1) Add the product      |"<<endl;;
    cout<<"\n\t\t\t|   2) Modify the product   |"<<endl;
    cout<<"\n\t\t\t|   3) Delete the product   |"<<endl;
    cout<<"\n\t\t\t|   4) Back to main menu    |"<<endl;
    cout<<"\n\t\t\t Please Enter your choice "<<endl;
    cin>>choice;

    switch(choice){
        case 1:
            add();
            break;

        case 2:
            edit();
            break;
        
        case 3:
            rem();
            break;
        
        case 4:
            menu();
            break;

        default:
            cout<<"Invalid choice"<<endl;
    } 

    goto m;
}

void shopping :: buyer(){
    m:
    int choice;
    cout<<"\t\t\t   Buyer   "<<endl;
    cout<<"\t\t\t __________"<<endl;
    cout<<endl;
    cout<<"\t\t\t 1) Buy Product"<<endl;
    cout<<endl;
    cout<<"\t\t\t 2) Go Back"<<endl;
    cout<<endl;
    cout<<"Enter your choice : ";
    cin>>choice; 

    switch(choice){
        case 1:
            receipt();
            break;

        case 2:
            menu();

        default:
            cout<<"Invalid choice"<<endl;    
    }
    goto m;
}

void shopping :: add(){
    m:
    fstream data;
    int c;
    int token=0;
    float p;
    float d;
    string n;

    cout<<"\n\t\t\t Add new product    "<<endl;
    cout<<"\n\t\t\t Product code       "<<endl;
    cin>>pcode;
    cout<<"\n\t\t\t Name of product    "<<endl;
    cin>>pname;
    cout<<"\n\t\t\t Price of product   "<<endl;
    cin>>price;
    cout<<"\n\t\t\t Discount on product"<<endl;
    cin>>dis;

    data.open("database.txt", ios::in);

    if(!data){
        data.open("database.txt", ios::app|ios::out);
        data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<endl;
        data.close();
    }else{
        data>>c>>n>>p>>d;

        while(data.eof()){
            if(c==pcode){
                token++;
            }
            data>>c>>n>>p>>d;
        }
        data.close();
        if(token==1){
            goto m;
        }else{
            data.open("databse.txt", ios::app|ios::out);
            data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<endl;
            data.close();
        }
    }
    cout<<"\n\n\t\t Record inserted!";
}

void shopping :: edit(){
    fstream data, data1;
    int pkey;
    int token=0;
    int c;
    float p;
    float d;
    string n;

    cout<<"\n\t\t\t Modify the record";
    cout<<"\n\t\t\t Product code : ";
    cin>>pkey;

    data.open("database.txt",ios::in);
    if(!data){
        cout<<"\n\nFile does'nt exist";
    }else{
        data1.open("database1.txt", ios::app|ios::out);
        data>>pcode>>pname>>price>>dis;
        while(!data.eof()){
            if(pkey==pcode){
                cout<<"\n\t\t Product of new code:";
                cin>>c;
                cout<<"\n\t\t Name of product:";
                cin>>n;
                cout<<"\n\t\t Price: ";
                cin>>p;
                cout<<"\n\t\t Discount: ";
                cin>>d;
                data1<<" "<<" "<<n<<" "<<p<<" "<<d<<"\n";
                cout<<"\n\n\t\t Record edited";
                token++;
            }
            else{
                data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
            }
            data>>pcode>>pname>>price>>dis;
        }
        data.close();
        data1.close();

        remove("database.txt");
        rename("database1.txt", "database.txt");

        if(token==0){
            cout<<"\n\n Record not found";
        }
    }
}

void shopping::rem(){
    fstream data,data1;
    int pkey;
    int token=0;
    cout<<"\n\n\t Delete Product";
    cout<<"\n\n\t Enter the product code:";
    cin>>pkey;
    data.open("database.txt",ios::in);
    if(!data){
        cout<<"File does'nt exist";
    }
    else{
        data1.open("database1.txt",ios::app|ios::out);
        data>>pcode>>pname>>price>>dis;
        while(!data.eof()){
            if(pcode==pkey){
                cout<<"\n\n\t Product deleted sucessfully";
                token++;
            }else{
                data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
            }
            data>>pcode>>pname>>price>>dis;
        }
        data.close();
        data1.close();
        remove("database.txt");
        rename("database1.txt", "database.txt");

        if(token==0){
            cout<<"\n\n Record not found";
        }
    }
}

void shopping::list(){
    fstream data;
    data.open("database.txt", ios::in);
    cout<<"\n\n_________________________________________\n";
    cout<<"ProNo\t\tname\t\tPrice\n";
    cout<<"\n\n_________________________________________\n";
    data>>pcode>>pname>>price>>dis;
    while(!data.eof()){
        cout<<pcode<<"\t\t"<<pname<<"\t\t"<<price<<"\n";
        data>>pcode>>pname>>price>>dis;
    }
    data.close();
}

void shopping::receipt(){
    m:
    fstream data;
    int arrc[100];
    int arrq[100];
    char choice;
    int c=0;
    float amount=0;
    float dis=0;
    float total=0;
    cout<<"\n\n\n\n\n RECEIPT ";
    data.open("database.txt",ios::in);
    if(!data){
        cout<<"\n\n Empty database";
    }else{
        data.close();
        list();
        cout<<"\n__________________________________________\n";
        cout<<"\n|                                         \n";
        cout<<"\n            Please place the order        \n";
        cout<<"\n|                                         \n";
        cout<<"\n__________________________________________\n";
        do{
            cout<<"\n\nEnter Product Code ";
            cin>>arrc[c];
            cout<<"\n\nEnter the quantity ";
            cin>>arrq[c];
            for(int i=0; i<c; i++){
                if(arrc[c]==arrc[i]){
                    cout<<"\n\n Duplicate product code. Please try again";
                    goto m;
                }
            }
            c++;
            cout<<"\n\n Do you want another product ? if yes then press y else no";
            cin>>choice;
        }
        while(choice=='y');
        cout<<"\n\n\t\t\t____________________________RECEIPT__________________\n";
        cout<<"\nProduct No\t Product Name\t Product Quantity\t Price\t Amount\t Amont with Discount \n";
        for(int i=0; i<c; i++){
            data.open("database.txt", ios::in);
            data>>pcode>>pname>>price>>dis;
            while(!data.eof()){
                if(pcode==arrc[i]){
                    amount=price*arrq[i];
                    dis=amount-(amount*dis/100);
                    total=total+dis;
                    cout<<"\n"<<pcode<<"\t\t"<<pname<<"\t\t"<<arrq[i]<<"\t\t"<<price<<"\t\t"<<amount<<"\t\t"<<dis;
                }
                data>>pcode>>pname>>price>>dis;
            }
        }
        data.close();
    }
    cout<<"\n\n_________________________________________";
    cout<<"\nTotal Amount : "<<total;
}

int main(){
    shopping s;
    s.menu();
}
