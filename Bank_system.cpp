#include <iostream>
using namespace std;
struct cust
{
	string name;
	int nath_id;
	double balance;
	double credit[1000];
	double depit[1000];
	cust* next;
	cust* prev;
};
class bank
{
private:
	double balance;
	int length;
	int length_credit;
	int length_depit;
	cust* first;
	cust* last;
public:
	bank()
	{
		balance = 0.0;
		length = 0;
		length_credit = 0;
		length_depit = 0;
		first = last = NULL;
	}
	void insert(string name, int id, double balance)
	{
		cust* newcust = new cust;
		newcust->name = name;
		newcust->nath_id = id;
		newcust->balance = balance;
		newcust->credit[length_credit] = 0.0;
		newcust->depit[length_depit] = 0.0;
		if (length == 0)
		{
			first = last = newcust;
			newcust->next = newcust->prev = NULL;
			length++;
		}
		else if (length == 1)
		{
			newcust->prev = first;
			first->next = newcust;
			last = newcust;
			newcust->next = NULL;
			length++;
		}
		else
		{
			newcust->prev = last;
			last->next = newcust;
			last = newcust;
			newcust->next = NULL;
			length++;
		}
	}
	void credit(int pos, double credit)
	{
		cust* newcust = first;
		if (length == 0)
		{
			cout << "ERROR !" << endl;
		}
		else
		{
			while (newcust->nath_id != pos)
			{
				newcust = newcust->next;
			}
			newcust->credit[length_credit] = credit;
			newcust->balance += newcust->credit[length_credit];
			cout << "[ Excellent process credit is success ] " << endl;
			length_credit++;
		}
	}
	void depit(int pos, double depit)
	{
		cust* newcust = first;
		if (length == 0)
		{
			cout << "ERROR !" << endl;
		}
		else
		{
			while (newcust->nath_id != pos)
			{
				newcust = newcust->next;
			}
			newcust->depit[length_depit] = depit;
			newcust->balance -= newcust->depit[length_depit];
			cout << "[ Excellent process depit is success ] " << endl;
			length_depit++;
		}
	}
	//DELETE:
	void delcust(int pos)
	{
		cust* newcust = first;
		if (length == 0)
		{
			cout << "ERROR !" << endl;
		}
		else if (length == 1)
		{
			delete first;
			first = last = NULL;
			length--;
			cout << "Delete client of nathional_id= (" << pos << ") is success"
				<< endl;
			cout << "#EMPTY !" << endl;
		}
		else
		{
			while (newcust->nath_id != pos)
			{
				newcust = newcust->next;
			}
			if (first == newcust)
			{
				first = newcust->next;
				newcust->next->prev = NULL;
				delete newcust;
				length--;
				cout << "Delete client of nathional_id= (" << pos << ") is successf" << endl;
			}
			//------------------//
			else if (last == newcust)
			{
				last = newcust->prev;
				newcust->prev->next = NULL;
				delete newcust;
				length--;
				cout << "Delete client of nathional_id= (" << pos << ") is successL" << endl;
			}
			else
			{
				newcust->prev->next = newcust->next;
				newcust->next->prev = newcust->prev;
				delete newcust;
				length--;
				cout << "Delete client of nathional_id= (" << pos << ") is successN"
					<< endl;
			}
		}
	}
	//UPDATE
	void update(int pos, string name, int id, double balance)
	{
		cust* newclient = new cust;
		newclient->name = name;
		newclient->nath_id = id;
		newclient->balance = balance;
		newclient->credit[0] = 0.0;
		newclient->depit[0] = 0.0;
		cust* newcust = first;
		if (length == 0)
		{
			cout << "ERROR !!" << endl;
		}
		else if (length == 1)
		{
			first = last = newclient;
			newclient->prev = newclient->next = NULL;
			delete newcust;
			cout << "The update of client of nathional_id=L (" << newclient->nath_id << ") is success"
				<< endl; cout << "#Done !" << endl;
		}
		else
		{
			while (newcust->nath_id != pos)
			{
				newcust = newcust->next;
			}
			if (first == newcust)
			{
				newcust->next->prev = newclient;
				newclient->next = newcust->next;
				newclient->prev = NULL;
				first = newclient;
				delete newcust;
				cout << "The update of client of nathional_id=F (" << newclient->nath_id << ") is success"
					<< endl;
				cout << "#Done !" << endl;
			}
			//------------------//
			else if (last == newcust)
			{
				newcust->prev->next = newclient;
				newclient->prev = newcust->prev;
				newclient->next = NULL;
				last = newclient;
				delete newcust;
				cout << "The update of client of nathional_id=S (" << newclient->nath_id << ")is success"
					<< endl;
				cout << "#Done !" << endl;
			}
			else
			{
				newcust->prev->next = newclient;
				newclient->prev = newcust->prev;
				newcust->next->prev = newclient;
				newclient->next = newcust->next;
				delete newcust;
				cout << "The update of client of nathional_id=N (" << newclient->nath_id << ") is success"
					<< endl;
				cout << "#Done !" << endl;
			}
		}
	}
	void display(int pos)
	{
		cust* newcust = first;
		if (length == 0)
		{
			cout << "ERROR !" << endl;
		}
		else
		{
			while (newcust->nath_id != pos)
			{
				newcust = newcust->next;
				if (newcust == NULL)
				{
					cout << "ERROR!-NOT FOUND THE CLIENT OF : (" << pos << ")" << endl;
				}
			}
			//=====//
			cout << "the name is : " << newcust->name << endl;
			cout << "the nath_id is : " << newcust->nath_id << endl;
			cout << "the balance is : " << newcust->balance << endl;
			cout << "Number of credit is : " << length_credit << endl;
			cout << "Number of depit is : " << length_depit << endl;
			cout << "<======================>" << endl;
			//=====//
		}
	}
};
int main()
{	
	cout << "{...Welcome to bank system...} !!" << endl;
	cout << endl;
	bank b;
	int ch;
	string name;
	int nath_id;
	int newnath_id;
	double balance = 0.0;
	double credit = 0.0;
	double depit = 0.0;
	cout << "1) Create account for new client " << endl;
	cout << "2) Credit for the account" << endl;
	cout << "3) Depit for the account" << endl;
	cout << "4) Print all information for client" << endl;
	cout << "5) Update the date for client " << endl;
	cout << "6) Delete the data of client" << endl;
	cout << "7) Exit" << endl;
	do {
		cout << "Enter choice: " << endl;
		cin >> ch;
		switch (ch) {
		case 1: {
			cout << "Please enter the name of new client :" << endl;
			cin >> name;
			cout << "Please enter the nathional_id of new client :" << endl;
			cin >> nath_id;
			cout << "Please enter the number of money of new client :" << endl;
			cin >> balance;
			b.insert(name, nath_id, balance);
			break; 
		}
		case 2: {
			cout << "please enter the nathional_id :" << endl;
			cin >> nath_id;
			cout << "Please enter the number of money of credit :" << endl;
			cin >> credit;
			b.credit(nath_id, credit);
			break;
		}
		case 3: {
			cout << "please enter the nathional_id :" << endl;
			cin >> nath_id;
			cout << "Please enter the number of money of depit :" << endl;
			cin >> depit;
			b.depit(nath_id, depit);
			break;
		}
		case 4: {
			cout << "please enter the nathional_id :" << endl;
			cin >> nath_id;
			cout << "All information for client is :" << endl;
			b.display(nath_id);
			break;
		}
		case 5: {
			cout << "please enter the nathional_id that you will update :" << endl;
			cin >> nath_id;
			cout << "please enter the name of new client :" << endl;
			cin >> name;
			cout << "Please enter the new nathional_id of new client :" << endl;
			cin >> newnath_id;
			cout << "Please enter the number of money of new client :" << endl;
			cin >> balance;
			b.update(nath_id, name, newnath_id, balance);
			break;
		}
		case 6: {
			cout << "please enter the nathional_id that you will Delete :" << endl;
			cin >> nath_id;
			b.delcust(nath_id); 
			break;
		}
		case 7: {
			cout << "Exit" << endl;
			break;
		}
		default: {
			cout << "Invalid Choice" << endl;
		}
		}
	} while (ch != 7);
	return 0;
}
