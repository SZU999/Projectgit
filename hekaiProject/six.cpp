#include<iostream>
using namespace std;

class Phone{
private:
	int id;
	char type;
	int state;
	string name;
public:
	Phone();  //��ΪҪ�����ʾ��Ϣ����Ҫ�ж������飬�������������� 
	~Phone();
	int check(int pid);
	void show();
};

Phone::Phone()
{
	cin>>id>>type>>state>>name;
	cout<<id<<" constructed."<<endl;
}

Phone::~Phone()
{
	cout<<id<<" destructed."<<endl;
}

void Phone::show()
{
	cout<<"Phone="<<id<<"-Type="<<type<<"-State=";
	if(!state) cout<<"unuse";
	else cout<<"use";
	cout<<"-Owner="<<name<<endl;
}

int Phone::check(int pid)   //��ѯ�Ƿ���ڸú��� 
{
	if(id==pid) return 1;
	else return 0;
}


int main()
{
	Phone *p=new Phone[3];
	
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int pid;
		cin>>pid;
		bool flag=0;
		for(int j=0;j<3;j++)
		{
			if(p[j].check(pid))
			{
				flag=1;
				p[j].show();
				break;
			}
		}
		
		if(!flag) cout<<"wrong number."<<endl;
	} 
	
	delete [] p;
	return 0;
}

/*
80000001 A 1 tom
80000002 B 0 ken
80000003 C 1 mary
3
50000002
80000003
80000002
*/

//output
/*
80000001 constructed.
80000002 constructed.
80000003 constructed.
wrong number.
Phone=80000003�CType=C�CState=use�COwner=mary
Phone=80000002�CType=B�CState=unuse�COwner=ken
80000003 destructed.
80000002 destructed.
80000001 destructed.
*/
