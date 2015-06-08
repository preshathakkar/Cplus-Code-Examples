
#include <iostream> 					
#include <vector>

#define lli long long int
#define veci vector <int>
#define vecb vector <bool>

using namespace std;

int main()
{
	lli num, src, nxtNode;
	veci dist, visit;
	cout<<endl<<"Enter the number of nodes in the graph : "<<endl;
	cin>>num;
	vector <veci > disttable;
	disttable.clear();
	cout<<endl<<"Please Enter the node number from which you want to calculate the distance (Starting from 0) : "<<endl;
	cin>>src;
	lli min=999999999;
						
	dist.clear(); 
	visit.clear();
	for (int ind=0; ind<num; ind++)
	{
		dist.push_back(0);
		visit.push_back(false);
	}

	
	cout<<endl<<"Enter the distances in a table form : "<<endl;
	
	for(int ind=0; ind<num; ind++)
	{
	   cout<<"  "<<ind; 
	    
	}
	
	cout<<endl;
	
	for (int ind=0; ind<num; ind++)
	{
		veci row;
		row.clear();
		cout<<ind<<" ";
		for (int r=0; r<num; r++)
		{
			lli d;
			cin>>d;
			row.push_back(d);
			
		}
		disttable.push_back(row);
	}									// input loop		
	
	dist = disttable.at(src);
	
	dist.at(src)=0;
	visit.at(src)=true;
	
	for (int ind=0; ind<num; ind++)
	{
		min=999999999;
		
		for (int r=0; r<num; r++)
		{
			if (min>=dist.at(r) && !visit.at(r))
			{
				min = dist.at(r);
				nxtNode = r;
			}
			
			
		}
			visit.at(nxtNode)=true;
		
			for (int s=0; s<num; s++)
			{
				if (!visit.at(s))
				{
					if (min+disttable.at(nxtNode).at(s) < dist.at(s))   
					{
						dist.at(s)=min+disttable.at(nxtNode).at(s);
					}
				}
			}
	}
	
	
	cout<<endl<<"Shortest Computed Distances are as below :"<<endl;
	for (int ind=0; ind<num; ind++)
	{
		cout<<"Distance of node "<<ind<<" from "<<src<<" is "<<dist.at(ind)<<endl;
	}
	
	return 0;
}
