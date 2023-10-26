#include<iostream>
using namespace std;


class Robot{
private:
	string name;
	int xl,sh,fy,rank;
	char type;
	static int cnt;    //�����ܹ�������� 
public:
	Robot(string name,char type,int rank);
	friend bool trans(Robot *r,char newtype);
	void show();
	static int getCnt();
	static void addCnt(){cnt++;}
};

Robot::Robot(string name,char type,int rank):name(name),type(type),rank(rank)
{
	if(type=='N')
	{
		xl=5*rank;sh=5*rank;fy=5*rank;
	}
	else if(type=='A')
	{
		xl=5*rank;sh=10*rank;fy=5*rank;
	}
	else if(type=='D')
	{
		xl=5*rank;sh=5*rank;fy=10*rank;
	}
	else
	{
		xl=50*rank;sh=5*rank;fy=5*rank;
	}
}
int Robot::getCnt(){return cnt;}
void Robot::show()
{
	cout<<name<<"-"<<type<<"-"<<rank<<"-"<<xl<<"-"<<sh<<"-"<<fy<<endl;
}

bool trans(Robot *r,char newtype)
{
	if(newtype==r->type) return false;
	else
	{
		r->type=newtype;
		if(newtype=='N')
		{
			r->xl=5*r->rank;r->sh=5*r->rank;r->fy=5*r->rank;
		}
		else if(newtype=='A')
		{
			r->xl=5*r->rank;r->sh=10*r->rank;r->fy=5*r->rank;
		}
		else if(newtype=='D')
		{
			r->xl=5*r->rank;r->sh=5*r->rank;r->fy=10*r->rank;
		}
		else
		{
			r->xl=50*r->rank;r->sh=5*r->rank;r->fy=5*r->rank;
		}
	}
}


int Robot::cnt=0; 

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string name;
		char type;
		int rank;
		cin>>name>>type>>rank;
		Robot r(name,type,rank);
		char newtype;
		cin>>newtype;
		if(trans(&r,newtype)) Robot::addCnt(); 
		
		r.show();
	}
	
	cout<<"The number of robot transform is "<<Robot::getCnt()<<endl;
	return 0;
}

/*
3
X001 N 5
H
X002 A 5
D
X003 D 5
D
*/

//output
/*
X001�CH�C5�C250�C25�C25
X002�CD�C5�C25�C25�C50
X003�CD�C5�C25�C25�C50
The number of robot transform is 2
*/
