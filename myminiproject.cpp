#include <bits/stdc++.h>
using namespace std;
class bank
{
    char name[20];
    float balance;
public:
    int id;
    int getid();
    void create();
    void display();
    void deposit();
    void withdraw();
};


int bank::getid()
{
    return id;
}

void bank::create()
{
    cout << "Enter Name\t";
    cin >> name;
    cout << "Enter Id\t";
    cin >> id;
    cout << "Account created successfully\n";
    balance = 0;
}

void bank::deposit()
{
    cout << "Enter Amount\t";
    float amt;
    cin >>amt;
    balance = balance + amt;
    cout << "Updated balance  = "<< balance << endl; 
}

void bank::withdraw()
{
    cout << "Enter Amount\t";
    float amt;
    cin >> amt;
    if(amt > balance)
    {
        cout << "\nInsufficient Balance\n";
    }
    else
    {
        balance = balance - amt;
        cout << "Updated balance  = "<< balance << endl; 
    }
}

void bank::display()
{
    cout << "\nAccount Number\t" << id;
    cout << "\nName : \t" << name;
    cout << "\nBalance : " << balance;
}

int main()
{
    fstream f;
    bank obj;
    char choice = 'd';
     cout << "\n\n*******************\n";
    cout << "*            WELCOME TO MY BANK                   *\n";
    cout << "*****************\n";
    while (choice != 'x')
    {
       
        cout << "\n\na) Create Account\n";
        cout << "b) Get Account Details\n";
        cout << "c) Deposit Money\n";
        cout << "d) Withdraw Money\n";
        cout << "x) Exit App\n";
        cout << "\n\nEnter your choice\t";
        cin >> choice;
        int z = 0;
        int x = 0;
        switch (choice)
        {
        case 'a':
            obj.create();
            f.open("bankdata.dat", ios::app);
            f.write((char *)&obj, sizeof(obj));
            f.close();
            break;
        case 'b':
            cout << "Enter your Id\t";
            cin >> x;
            f.open("bankdata.dat", ios::in);
            while (!f.eof())
            {
                f.read((char *)&obj, sizeof(obj));
                if (obj.id == x)
                {
                    obj.display();
                    z = 1;
                    break;
                }
            }
            if (z == 0)
                cout << "Sorry! Data not found\n";
            f.close();
            break;
        case 'c':
            cout << "Enter your Id\t";   
            cin >> x;
            f.open("bankdata.dat", ios::in|ios::out);
            while (!f.eof())
            {
                int pos = f.tellg();
                f.read((char *)&obj, sizeof(obj)); 
                if (obj.id == x)
                {
                    obj.deposit();
                    z = 1;
                    f.seekp(pos);
                    f.write((char *) &obj, sizeof(obj));
                    break;
                }
            }
            if (z == 0)
                cout << "Sorry! Data not found\n";
                f.close();
            break;
        case 'd':
            cout << "Enter your Id\t";   
            cin >> x;
            f.open("bankdata.dat", ios::in|ios::out);
            while (!f.eof())
            {
                int pos = f.tellg();
                f.read((char *)&obj, sizeof(obj)); 
                if (obj.id == x)
                {
                    obj.withdraw();
                    z = 1;
                    f.seekp(pos);
                    f.write((char *) &obj, sizeof(obj));
                    break;
                }
            }
            if (z == 0)
                cout << "Sorry! Data not found\n";
                f.close();
            break;
        }
    }
}