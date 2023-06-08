
#include <iostream>
#include <string.h>
#include <queue>
using namespace std;

class flight
{
public:
	int am[10][10];
	char city_index[10][10];
	flight();
	int create();
	void display(int city_count);
	void connect(int city_count);
};

flight::flight()
{
	int i, j;
	for (i = 0; i < 10; i++)
	{
		strcpy(city_index[i], "xx");
	}
	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 10; j++)
		{
			am[i][j] = 0;
		}
	}
}

int flight::create()
{
	int city_count = 0, j, si, di, wt;
	char s[10], d[10], c;
	do
	{
		cout << "\n\tEnter Source City      : ";
		cin >> s;
		cout << "\n\tEnter Destination City : ";
		cin >> d;
		for (j = 0; j < 10; j++)
		{
			if (strcmp(city_index[j], s) == 0)
				break;
		}
		if (j == 10)
		{
			strcpy(city_index[city_count], s);
			city_count++;
		}

		for (j = 0; j < 10; j++)
		{
			if (strcmp(city_index[j], d) == 0)
				break;
		}

		if (j == 10)
		{
			strcpy(city_index[city_count], d);
			city_count++;
		}

		cout << "\n\t Enter Distance From " << s << " And " << d << ": ";
		cin >> wt;

		for (j = 0; j < 10; j++)
		{
			if (strcmp(city_index[j], s) == 0)
				si = j;
			if (strcmp(city_index[j], d) == 0)
				di = j;
		}

		am[si][di] = wt;
		cout << "\n\t Do you want to add more cities.....(y/n) : ";
		cin >> c;
	} while (c == 'y' || c == 'Y');
	return (city_count);
}
void flight::display(int city_count)
{
	int i, j;
	cout << "\n\t Displaying Adjacency Matrix :\n\t";
	for (i = 0; i < city_count; i++)
		cout << "\t" << city_index[i];
	cout << "\n";

	for (i = 0; i < city_count; i++)
	{
		cout << "\t" << city_index[i];
		for (j = 0; j < city_count; j++)
		{
			cout << "\t" << am[i][j];
		}
		cout << "\n";
	}
}

void flight::connect(int city_count)
{
	int i, j, s;
	bool visited[10] = {false};
	queue<int> q;

	q.push(0);
	visited[0] = true;

	while (!q.empty())
	{
		s = q.front();
		q.pop();

		for (i = 0; i < city_count; i++)
		{
			if (am[s][i] && !visited[i])
			{
				visited[i] = true;
				q.push(i);
			}
		}
	}

	for (i = 0; i < city_count; i++)
	{
		if (!visited[i])
		{

			cout << "\n\tNode " << city_index[i] << " is not connected\n";
			cout << "\n\tThe graph is not connected.\n";
			return;
		}
	}

	cout << "\n\tThe graph is connected.\n";
}

int main()
{
	flight f;
	int n, city_count;
	char c;
	do
	{
		cout << "\n\t*** Flight Main Menu *****";
		cout << "\n\t1. Create \n\t2. Adjacency Matrix\n\t3. Graph is connected or not \n\t4. Exit";
		cout << "\n\t.....Enter your choice : ";
		cin >> n;
		switch (n)
		{
		case 1:
			city_count = f.create();
			break;
		case 2:
			f.display(city_count);
			break;

		case 3:
			f.connect(city_count);
			break;
		case 4:
			return 0;
		}

	} while (n != 4);
	return 0;
}
