#include<iostream>
using namespace std;

class CBook{
private:
	string id,name;
	int snum,remain;
public:
	CBook();
	void set(string id,string name,int snum,int remain);
	string borrow();
	void display(); 
	int getRemain();
	int getSnum();
	string getName();
	string getId();
};

CBook::CBook(){}
void CBook::set(string id,string name,int snum,int remain)
{
	this->id=id;this->name=name;
	this->snum=snum;this->remain=remain;
}

int CBook::getSnum(){return snum;}
int CBook::getRemain(){return remain;}
string CBook::getName(){return name;}
string CBook::getId(){return id;}

string CBook::borrow()
{
	if(remain>=1)
	{
		remain--;
		return id;
	}
	else return "";
}

void CBook::display()
{
	cout<<id<<" "<<name<<" "<<snum<<" "<<remain<<endl;
}


int main()
{
	int haveborrow=0;
	int nowremain=0;
	
	int n,m;
	cin>>n;
	
	CBook *p=new CBook[n]; 
	for(int i=0;i<n;i++)
	{
		string id,name;
		int snum,remain;
		cin>>id>>name>>snum>>remain;
		p[i].set(id,name,snum,remain);
	}
	
	cin>>m;
	while(m--)
	{
		string str;
		cin>>str;
		for(int i=0;i<n;i++)
		{
			if(str==p[i].getName())
			{
				if(p[i].borrow()=="")
				{
					cout<<str<<" "<<"������ȫ�����"<<endl;
				}
				else
				{
					cout<<str<<" "<<"��ȡ��: "<<p[i].getId()<<endl;
				}
				
				break;
			}
		}
		
	}
	
	cout<<endl;
	
	for(int i=0;i<n;i++)
	{
		haveborrow+=p[i].getSnum()-p[i].getRemain();
		nowremain+=p[i].getRemain();
		p[i].display();
	}
	cout<<"���ͼ��: "<<haveborrow<<"��  ʣ��ݲ�ͼ��: "<<nowremain<<"��"<<endl; 
	
	return 0;
}



/*
4
TP312JA-43/L99 Java���Գ�����ƽ̳� 3 0
TP312PH/Q68b PHP7�ں����� 3 2
TP311.561-43/L93 Python��ѧ�̳� 3 1
TP311.5-43/M18a1(2) ������̻��� 3 3
4
Java���Գ�����ƽ̳�
������̻���
Python��ѧ�̳�
Python��ѧ�̳�


*/

//output
/*
Java���Գ�����ƽ̳� ������ȫ�����\n
������̻��� ��ȡ��: TP311.5-43/M18a1(2)\n
Python��ѧ�̳� ��ȡ��: TP311.561-43/L93\n
Python��ѧ�̳� ������ȫ�����\n
\n
TP312JA-43/L99 Java���Գ�����ƽ̳� 3 0\n
TP312PH/Q68b PHP7�ں����� 3 2\n
TP311.561-43/L93 Python��ѧ�̳� 3 0\n
TP311.5-43/M18a1(2) ������̻��� 3 2\n
���ͼ��: 8��  ʣ��ݲ�ͼ��: 4��
*/ 
