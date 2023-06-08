#include <iostream>
#include <string.h>
using namespace std;
class table
{
	typedef struct hash
	{
		long key;
		char name[10];
	} hash;

public:
	int t;
	hash hashtable[10];
	string arr2[10];
	char na[10], ntemp[10];
	long k;
	int n, hashvalue, temp;
	void getdata();
	void getdata1();
	int hashfunction(int);
	void search();
	void display();
	int find(long);
	void Delete();
};

int table::find(long k)
{
	int i;
	for (i = 0; i < 10; i++)
	{
		if (hashtable[i].key == k)
		{
			cout << "\n\t****" << hashtable[i].key << " is Found at " << i << " Location With Name " << hashtable[i].name << "****";
			return i;
		}
	}
	if (i == 10)
		return -1;
}

void table ::getdata()
{
	cout << "\n\nEnter number of elements : ";
	cin >> n;
	for (int i = 0; i < 10; i++)
	{
		hashtable[i].key = 0;
		strcpy(hashtable[i].name, "NULL");
	}

	for (int i = 0; i < n; i++)
	{
		cout << "\n";
		cout << "Enter an element : ";
		cin >> k;
		cout << "Enter name : ";
		cin >> na;
		hashvalue = hashfunction(k);
		int j = 0;
		while (hashvalue != j)
		{
			j++;
		}
		if (hashtable[j].key == 0)
		{
			hashtable[j].key = k;
			strcpy(hashtable[j].name, na);
		}
		else
		{
			temp = hashtable[j].key;
			strcpy(ntemp, hashtable[j].name);
			hashtable[j].key = k;
			strcpy(hashtable[j].name, na);

			for (int t = j + 1; t <= 10; t++)
			{
				if (hashtable[t].key == 0)
				{
					hashtable[t].key = temp;
					strcpy(hashtable[t].name, ntemp);
					break;
				}
				if (t >= 9)
				{
					for (int q = 0; q <= t; q++)
					{
						if (hashtable[q].key == 0)
						{
							hashtable[q].key = temp;
							strcpy(hashtable[q].name, ntemp);
							break;
						}
					}
				}
			}
		}
	}
}

int table ::hashfunction(int key)
{
	return key % 10;
}

void table::display()
{
	int i;
	cout << "\n\t\tKey\t\tName";
	for (i = 0; i < 10; i++)
	{
		cout << "\n\th[" << i << "]\t" << hashtable[i].key << "\t\t" << hashtable[i].name;
	}
}

void table ::getdata1()
{
	cout << "\n\nEnter number of elements : ";
	cin >> n;
	for (int i = 0; i < 10; i++)
	{
		hashtable[i].key = 0;
		strcpy(hashtable[i].name, "NULL");
	}
	for (int i = 0; i < n; i++)
	{
		cout << "\n";
		cout << "Enter an element : ";
		cin >> k;
		cout << "Enter name : ";
		cin >> na;
		hashvalue = hashfunction(k);
		int j = 0;
		while (hashvalue != j)
		{
			j++;
		}
		if (hashtable[j].key == 0)
		{
			hashtable[j].key = k;
			strcpy(hashtable[j].name, na);
		}
		else
		{
			for (int t = j + 1; t <= 10; t++)
			{
				if (hashtable[t].key == 0)
				{
					hashtable[t].key = k;
					strcpy(hashtable[t].name, na);
					break;
				}
				if (t >= 9)
				{
					for (int q = 0; q <= t; q++)
					{
						if (hashtable[q].key == 0)
						{
							hashtable[q].key = k;
							strcpy(hashtable[q].name, na);
							break;
						}
					}
				}
			}
		}
	}
}

int main()

{
	int ch;
	long k;
	table obj;

	do
	{
		cout << "\n\n\n*******Enter the choice********";
		cout << "\n\tPress 1 FOR WITH REPLACEMENT\n\tPress 2 for without replacement \n\tPress 5 for Exit";
		cout << "\nEnter choice :-";
		cin >> ch;
		if (ch == 1)
		{
			obj.getdata();
			cout << "Your hash table is : \n\n";
			cout << "Index"
				 << "\t"
				 << "Data"
				 << "\t"
				 << "Name" << endl;
			cout << "=====================";
			obj.display();

			cout << "\n\nIf you want to search any key press 3 else press 6:-";
			cin >> ch;
			if (ch == 3)
			{
				cout << "\n\tEnter a Key Which You Want to Search: ";
				cin >> k;
				obj.find(k);
			}
		}

		if (ch == 2)
		{
			obj.getdata1();
			cout << "Your hash table is : \n\n";
			cout << "Index"
				 << "\t"
				 << "Data"
				 << "\t"
				 << "Name" << endl;
			cout << "=====================";
			obj.display();

			cout << "\n\nIf you want to search any key press 4 else press 6";
			cin >> ch;
			if (ch == 4)
			{
				cout << "\n\tEnter a Key Which You Want to Search: ";
				cin >> k;
				obj.find(k);
			}
		}
	} while (ch != 5);
	return 0;
}