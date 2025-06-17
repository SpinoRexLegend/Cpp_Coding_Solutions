//Making a bank management system
#include<iostream>
#include<vector>
using namespace std;

class BankAccount
{
    private:
        int bankId;
        string holderName;
        float money;
        float amount;
    public:
        BankAccount(int bankId, string holderName, float money = 1000.00)
        {
            this->bankId = bankId;
            this->holderName = holderName;
            this->money = money;
        }
        
        void displayAccDetails()
        {
            cout<<"Bank Account Id: "<<bankId<<endl;
            cout<<"Bank Account Holder name: "<<holderName<<endl;
            cout<<"Current possesion: $"<<money<<endl;
        }
        void credit(float amount);
        void debit(float amount);
        int getId();
        float getMoney();
};
void BankAccount::credit(float amount)
{
    money+=amount;
}
void BankAccount::debit(float amount)
{
    money-=amount;
}
int BankAccount::getId()
{
    return bankId;
}
float BankAccount::getMoney()
{
    return money;
}

class Bank
{
    private:
        vector<BankAccount*>accounts;
        BankAccount* findAccount(int id)
        {
            for(auto account: accounts)
            {
                if(account->getId() == id)
                    return account;
            }
            return nullptr;
        }
    public:
        void newAccount(BankAccount* account)
        {
            accounts.push_back(account);
        }
        void credit(int id, float amount)
        {
            BankAccount* account = findAccount(id);
            account->credit(amount);
        }
        void debit(int id, float amount)
        {
            BankAccount* account = findAccount(id);
            if(amount > account->getMoney())
            {
                cout<<"Insufficient funds"<<endl;
                return;
            }
            account->debit(amount);
        }
        void showDetails(int id)
        {
            BankAccount* account = findAccount(id);
            account->displayAccDetails();
        }
};

int main()
{
    Bank bank;
    bank.newAccount(new BankAccount(0, "Jonathan Crane"));
    bank.newAccount(new BankAccount(1, "Bruce Wayne", 50000));
    
    int choice, id;
    float amt;
    cout<<"Press 1 to create new Account\n"<<"Press 2 to credit amount\n"<<"Press 3 to debit amount\n"<<"Press 4 display bank details\n"<<"Press 0 to exit simulation\n"<<endl;
    do
    {
        cout<<"Enter thy choice: ";
        cin >> choice;
        
        switch(choice)
        {
            case 0:
                return 1;
            case 1:{
                int bankId;
                string name;
                float amt;
                cout<<"Please enter the Holder Name, Bank Id, Initial amount"<<endl;
                cin.ignore();
                getline(cin, name);
                cin>> bankId>> amt;
                bank.newAccount(new BankAccount(bankId, name, amt));
                break;
            }
            case 2:
                cout<<"Enter bank id: "<<endl;
                cin>>id;
                cout<<"Enter amount to be credited: ";
                cin>>amt;
                bank.credit(id, amt);
                break;
            case 3:
                cout<<"Enter bank id: "<<endl;
                cin>>id;
                cout<<"Enter amount to be debited: ";
                cin>>amt;
                bank.debit(id, amt);
                break;
            case 4:
                cout<<"Enter bank id: "<<endl;
                cin>>id;
                bank.showDetails(id);
                break;
        }
    }while(choice!=0);
    
    return 1;
}
