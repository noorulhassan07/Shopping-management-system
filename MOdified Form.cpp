#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class InvalidArg :public exception //Exceptional Handling
{
public:
    const char* what()const throw()
    {
        return ("Invalid Argument");
    }
};

// classes with their attributes and methods
class Shop {
public:
    void shop() 
    {
        cout << "\t\t\tA & N Shop" << endl << endl;
        cout << "\t\t\tContact US: (042)-111-123-123" << endl << endl;

        fstream Shop("Shop.txt", ios::app);
        Shop << "\t\t\t\t\t\t\t\t\tA & N SHOP" << endl << endl;
        Shop << "\t\t\t\t\t\t\t CONTACT US: (042)-111-123-123" << endl << endl;
    }
    void Conatct()
    {
        cout << "\t\t\tContact US: (042)-111-123-123" << endl << endl;
    }
};

class Customer : public Shop //customer class dereived from shop class 
{
private:
    string name, number, address, password, CNIC;
    char choice;

public:
    Customer() {}

    Customer(string name, string number, string password, string address, string CNIC) {
        this->name = name;
        this->number = number;
        this->password = password;
        this->address = address;
        this->CNIC = CNIC;

        // File Handling for Customer

        fstream Customer("Customer.txt", ios::app);
        Customer << "NAME\t\t\tADDRESS\t\t\tNUMBER\t\t\tCNIC" << endl;

        Customer <<this->name << "\t\t\t" << this->address << "\t\t\t" <<this->number << "\t\t\t" << this->CNIC << endl;
    }
    // getter and setter 
    void setName(string name) {
        this->name = name;
    }

    string getName() {
        return name;
    }

    void setNumber(string number) {
        this->number = number;
    }

    string getNumber() {
        return number;
    }

    void setAddress(string address) {
        this->address = address;
    }

    string getAddress() {
        return address;
    }

    void setCNIC(string CNIC) {
        this->CNIC = CNIC;
    }

    string getCNIC() {
        return CNIC;
    }

    void setPassword(string password) {
        this->password = password;
    }

    string getPassword() {
        return password;
    }

    // Condition to check whether customer is old or new
    void cus() 
    {
        cout << endl << endl << endl;
        cout << "   If you are an old customer, press O or o" << endl;
        cout << "   If you are a new customer, press N or n" << endl;
        cout << "   Enter e to Exit from this segment" << endl;
        cout << "   Enter your choice: ";
        cin >> choice;

        while (choice != 'e') 
        {
            if (choice == 'O' || choice == 'o') {
                cout << "   Enter Your name: ";
                cin >> name;
                cout << "   Enter your verified Number: ";
                cin >> number;
                break;
            }
            else if (choice == 'N' || choice == 'n') {
                cout << "   Enter your Name: ";
                cin >> name;
                cout << "   Enter your Password: ";
                cin >> password;
                cout << "   Enter your CNIC without dashes: ";
                cin >> CNIC;
                cout << "   Enter your Address: ";
                cin.ignore();
                getline(cin, address);
                break;
              
            }
            else 
            {
                cout << "   Invalid choice! Please try again." << endl;
                cout << "   Enter your choice: ";
                cin >> choice;
            }
            
        }
    }
};

class Products : public Shop
{
protected:
    double total_price;
    char choice;

public:
    virtual void shoppingProducts() = 0;
};
//************************************  MAKE UP   ******************************************
class MakeUp : public Products
{
public:
    void shoppingProducts() override
    {
        do {
int item, quantity;
            total_price = 0.0; // Declare total_price here
            cout << "   Here are makeup details " << endl << endl;
            cout << "   (1) Foundation     : price => 2000.00" << endl;
            cout << "   (2) Lipstick       : price => 1500.00" << endl;
            cout << "   (3) Eyeshadow      : price => 1800.00" << endl;
            cout << "   (4) Mascara        : price => 1200.00" << endl;
            cout << "   Press 0 to exit" << endl;

            cout << "   Select an item to purchase: ";
            cin >> item;

            if (item == 0) {
                break;
            }

            cout << "   Enter quantity: ";
            cin >> quantity;

            switch (item) {
            case 1:
                total_price += quantity * 2000.0;
                break;
            case 2:
                total_price += quantity * 1500.0;
                break;
            case 3:
                total_price += quantity * 1800.0;
                break;
            case 4:
                total_price += quantity * 1200.0;
                break;
            default:
                cout << "   Invalid item selection!" << endl;
                break;
            }

            cout << "   Total Price: " << total_price << endl;

            cout << "   Do you want to purchase more? (Y/N): ";
            cin >> choice;
        } while (choice == 'Y' || choice == 'y');
    }
};
//************************************      PERFUME     *************************************
class Perfume : public Products {
public:
   void shoppingProducts() override 
   {
        do {
            int item, quantity;
            total_price = 0.0; // Declare total_price here
            cout << "   Here are perfume details " << endl;
            cout << "   (1) Chanel No. 5   : price => 3000.00" << endl;
            cout << "   (2) Dior Sauvage   : price => 2500.00" << endl;
            cout << "   (3) Gucci Bloom    : price => 2800.00" << endl;
            cout << "   (4) Versace Eros   : price => 2200.00" << endl;
            cout << "   Press 0 to exit" << endl;

            cout << "   Select an item to purchase: ";
            cin >> item;

            if (item == 0) 
            {
                break;
            }
            cout << "   Enter quantity: ";
            cin >> quantity;

            switch (item) {
            case 1:
                total_price += quantity * 3000.0;
                break;
            case 2:
                total_price += quantity * 2500.0;
                break;
            case 3:
                total_price += quantity * 2800.0;
                break;
            case 4:
                total_price += quantity * 2200.0;
                break;
            default:
                cout << "   Invalid item selection!" << endl;
                break;
            }

            cout << "   Total Price: " << total_price << endl;

            cout << "   Do you want to purchase more? (Y/N): ";
            cin >> choice;
        } while (choice == 'Y' || choice == 'y');
    }
};
//**************************************        TOYS        *******************************************
class Toys : public Products
{
public:
   void shoppingProducts() override
   {
        do {
            int item, quantity;
            total_price = 0.0; // Declare total_price here
            cout << "   Here are toy details " << endl;
            cout << "   (1) Barbie Doll    : price => 500.00" << endl;
            cout << "   (2) Hot Wheels     : price => 300.00" << endl;
            cout << "   (3) LEGO Set       : price => 800.00" << endl;
            cout << "   (4) Teddy Bear     : price => 200.00" << endl;
            cout << "   Press 0 to exit" << endl;

            cout << "   Select an item to purchase: ";
           cin >> item;

            if (item == 0)
            {
             break;
            }

            cout << "   Enter quantity: ";
            cin >> quantity;

            switch (item)
            {
            case 1:
                total_price += quantity * 500.0;
                break;
            case 2:
                total_price += quantity * 300.0;
                break;
            case 3:
                total_price += quantity * 800.0;
                break;
            case 4:
                total_price += quantity * 200.0;
                break;
            default:
                cout << "   Invalid item selection!" << endl;
                break;
            }

            cout << "   Total Price: " << total_price << endl;

            cout << "   Do you want to purchase more? (Y/N): ";
            cin >> choice;
        } while (choice == 'Y' || choice == 'y');
    }
};
class CustomerHelp : public Shop
{
public:

    void getHelp()
    {
        cout << "   Welcome to Customer Help!" << endl<<endl;
        cout << "   How can we assist you today?" << endl;
        cout << "   (1) Product Inquiry" << endl;
        cout << "   (2) Order Status" << endl;
        cout << "   (3) Return or Exchange" << endl;
        cout << "   (4) Payment Issues" << endl;
        cout << "   (5) Other Queries" << endl;

        int choice;
        cout << endl;
        cout << "   Enter your choice: ";
        cin >> choice;

        try {
            switch (choice) 
            {
            case 1:
                cout << "   Please provide the details of the product you are inquiring about." << endl;
                // Perform product inquiry logic here
                break;
            case 2:
                cout << "   Your Order is Confirm and On the Way " << endl;
                // Perform order status inquiry logic here
                break;
            case 3:
                cout << "   Return the Package from the mentioned Address on the Parcel or contact us on the Number" << endl;
                // Perform return or exchange logic here
                break;
            case 4:
                cout << "   Cash on delivery, We dont accept Online Payment" << endl;
                // Perform payment issue logic here
                break;
            case 5:
                cout << "   Customer Assistance is on the Way" << endl;
                // Perform other query logic here
                break;
            default:
                throw InvalidArg();  // Throw an exception for invalid choice
            }
        }
        catch (const exception& e) 
        {
            cout <<  e.what() << endl;
        }
    }
};

int main()
{
    Customer cus("", "", "", "", "");
    cus.cus();
    int cho;
    MakeUp m;
    Perfume p;
    Toys t;
    CustomerHelp ch;

    do
    {
        cout << "   Enter 1 for Makeup Section" << endl << endl;
        cout << "   Enter 2 for Perfume Section" << endl << endl;
        cout << "   Enter 3 for Toys Section" << endl << endl;
        cout << "   Enter 4 for Help Center" << endl << endl;
        cout << "   Enter 5 for Exit from the Program" << endl;
        cout << endl;
        cout << "   Enter your Choice : ";
        cin >> cho;
        switch (cho)
        {
        case 1:
            
            cout << endl << endl;
            cout << "     Here are the Products for Make Up " << endl << endl;
            m.shoppingProducts();
            break;
            cout << endl << endl;
        case 2:
            
            cout << endl << endl;
            cout << "     Here are the Products for Perfume " << endl << endl;
            p.shoppingProducts();
            break;
            cout << endl << endl;
        case 3:
           
            cout << endl << endl;
            cout << "      Here are the Products for Toys " << endl << endl;
            t.shoppingProducts();
            break;
            cout << endl << endl;
        case 4:

            cout << endl << endl;
            ch.getHelp();
            break;
            cout << endl << endl;
        default:
            cout << endl << endl;
            cout << "\t\t\t\t\tTHANKYOU FOR CHOOSING A & N SHOP" << endl;
            ch.Contact();
        }


    } while (cho != 5);
    return 0;
}