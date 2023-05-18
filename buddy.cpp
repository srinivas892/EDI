#include<bits/stdc++.h>
using namespace std;

int size;

vector<pair<int, int>> free_list[100000];

map<int, int> mp;

void initialize(int sz)
{
	int n = ceil(log(sz) / log(2));
	size = n + 1;
	
	for(int i = 0; i <= n; i++)
		free_list[i].clear();

	free_list[n].push_back(make_pair(0, sz - 1));
}

void allocate(int sz)
{
	
	int n = ceil(log(sz) / log(2));

	if (free_list[n].size() > 0)
	{
		pair<int, int> temp = free_list[n][0];

		free_list[n].erase(free_list[n].begin());
		cout << "Memory from " << temp.first
			<< " to " << temp.second << " allocated"
			<< "\n";

		mp[temp.first] = temp.second -
						temp.first + 1;
	}
	else
	{
		int i;
		for(i = n + 1; i < size; i++)
		{

			if(free_list[i].size() != 0)
				break;
		}

		if (i == size)
		{
			cout << "Sorry, failed to allocate memory \n";
		}
		
		else
		{
			pair<int, int> temp;
			temp = free_list[i][0];

			free_list[i].erase(free_list[i].begin());
			i--;
			
			for(; i >= n; i--)
			{
				
				pair<int, int> pair1, pair2;
				pair1 = make_pair(temp.first,temp.first +(temp.second -temp.first) / 2);
				pair2 = make_pair(temp.first +(temp.second -temp.first + 1) / 2,temp.second);
								
				free_list[i].push_back(pair1);

				free_list[i].push_back(pair2);
				temp = free_list[i][0];

				free_list[i].erase(free_list[i].begin());
			}
			cout << "Memory from " << temp.first
				<< " to " << temp.second
				<< " allocated" << "\n";
				
			mp[temp.first] = temp.second -
							temp.first + 1;
		}
	}
}

int main()
{

	
	int total,c,req;
	cout<<"Enter the Memory Size in KB : ";
	cin>>total;
	initialize(total);
	while(true)
	{
	    cout<<"Enter the request size : ";
		cin>>req;
		if(req == 0)
			break;
		allocate(req);
		cout<<"Enter 0 for Exit"<<endl;
	}


	return 0;
}
