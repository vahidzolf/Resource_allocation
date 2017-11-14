#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iterator>


using namespace std;

void selectSort(vector<int> &arr,vector<int> &ind)
{

	int pos_min,temp;
	int n = arr.size();
	for (int i=0; i < n; i++)
	{
		ind[i]=i;
	}
	for (int i=0; i < n-1; i++)
	{
	    pos_min = i;//set pos_min to the current index of array
		for (int j=i+1; j < n; j++)
		{
			if (arr[j] < arr[pos_min])
                   pos_min=j;
	//pos_min will keep track of the index that min is in, this is needed when a swap happens
		}
		
	//if pos_min no longer equals i than a smaller value must have been found, so a swap must occur
            if (pos_min != i)
            {		
                temp = arr[i];
                arr[i] = arr[pos_min];
                arr[pos_min] = temp;
                
                temp = ind[i];
                ind[i] = ind[pos_min];
                ind[pos_min] = temp;
            }
	}
}

bool wayToSort(int i, int j) { return i > j; }

int check_group(int indexelem)
{
		return indexelem % 2 ;
}

void analyze_vector(vector<int> current_row,int& g1_counter,int& freed_num)
{
	g1_counter=0;
	freed_num=0;
	for(int i=0;i<current_row.size();++i)
	{
		if(current_row[i]==-1)
			freed_num++;
		else 
			if(check_group(current_row[i]))
				g1_counter++;
	}
	
}

bool put(vector<vector<int> > &Alloc,int id,int& num)
{
	bool flag=false,fflag=false;
	int counter=0,freed,g1_counter;

	for(int row=0;row<10;++row)
	{
		analyze_vector(Alloc[row],g1_counter,freed);
		if (freed == 0)
			continue;
		if (check_group(id)==1)
			if (g1_counter == 15)
				continue;
		for(int column=0;column<24;++column)
		{				
			if(Alloc[row][column]==-1 && counter < num )
			{
				flag = true;
				Alloc[row][column]=id;
				if (check_group(id)==1)
					g1_counter++;
					if ( g1_counter==15)
					{
						fflag=true;
						break;
					}
				counter++;
			}
			else if (counter == num)
			{
				fflag=true;
				break;
			}
		}
		if (fflag)
			break;
	}
	num=num-counter;
	return flag;
}

bool check_end(vector<int> &Demand)
{
	for(vector<int>::iterator it = Demand.begin(); it != Demand.end(); ++it) 
	{
		if(*it != 0)
		{
			return false;
		}
	}
	return true;	
}

bool Allocate(int my_round,vector<int> &Demand,vector<vector<int> >& Alloc)
{
	int count =10,need,v,element,id,max_users=5,users_count=0;
	bool flag;
	vector<int> sorted(10);
	vector<int> users;
	vector<int> index(10);
	vector<int> currrent_g1_slots(10);
	sorted = Demand;

	selectSort(sorted,index);
	
	while(sorted.size() != 0)
	{
		if(users_count >= max_users)
		{
			break;
		}
		users.push_back(id);
		element = sorted.back();
		sorted.pop_back();
		
		id = index.back();
		index.pop_back();
		
		need = ceil(element/10);
		users_count++;
		do 
		{
			flag = put(Alloc,id,need);
			if (!flag)
			{
				cout << "LOOP Detected"<<endl;
				break;
			}
		}while(need != 0);
		Demand[id]=0;
	} 
	cout << "Alloc["<<my_round<<"] : " <<endl ;
	for (int i=0;i<=9;++i)
	{

		for(int j=0;j<=24;++j)
		{
			if (j==0)
				cout << "[ "; 
			
			if (j==24)
			{
				cout << Alloc[i][j] << "] "<< endl;
			}
			else
				cout << Alloc[i][j] << " , " ;
		}
	}
	return check_end(Demand);
}


int main()
{
	vector<int> Demand(10);
	vector<vector <int> > Alloc(10);
	for(int i=0;i<10;++i)
		Alloc[i].resize(24);


	srand (time(NULL));
	cout << "Demand is : [";
	for (int i=0;i<=9;++i)
	{
		Demand[i] = rand() % 250 + 1 ;
		
		if (i==9)
			cout << Demand[i] << " ]"<<endl;
		else
			cout << Demand[i] << " , ";
	}
	cout << "Index is : [";
	for (int i=0;i<=9;++i)
	{
		if (i==9)
			cout << i << " ]"<<endl;
		else
			cout << i << " , ";
	}
	
	int my_round=0;
	do{
		for (int i=0;i<=9;++i)
			for (int j=0;j<=24;++j)
				Alloc[i][j]=-1;
		
		Allocate(my_round,Demand,Alloc);
		my_round++;
	}while(!check_end(Demand));

	
	return 0;
}
