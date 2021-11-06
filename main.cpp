#include <iostream>
using namespace std;

#define _WIN32_WINNT 0x0500

#include <windows.h>

char squer[9];

void Squer(int i=0,char p='O'){
	if(i==0)
	{
		for(int i=1;i<=9;i++)
		{
			squer[i]='0'+i;
		}
	}
	else if(squer[i]=='0'+i)
	{
		squer[i]=p;
	}
	else
	{
		cout<<"Try another nember :";
		cin>>i;
		squer[i]=p;
	}

}

void play()
{
cout<<endl<<" 		 "<<squer[1]<<" | "<<squer[2]<<" | "<<squer[3]<<" ";
cout<<endl<<"		---|---|---";
cout<<endl<<" 		 "<<squer[4]<<" | "<<squer[5]<<" | "<<squer[6]<<" ";
cout<<endl<<"		---|---|---";
cout<<endl<<" 		 "<<squer[7]<<" | "<<squer[8]<<" | "<<squer[9]<<" ";

}

bool chfiniched()
{
	/************
		123
		456
		789
		
		147
		258
		369
		
		159
		357
	************/
	int	x=1;
	int	y=2;
	int	z=3;
	
	for(int i=0;i<8;i++)
	{
	if(i==0)
	{
		x=1;
		y=2;
		z=3;
	}
	else if(i==1)
	{
		x=4;
		y=5;
		z=6;
	}
		else if(i==2)
	{
		x=7;
		y=8;
		z=9;
	}
		else if(i==3)
	{
		x=1;
		y=4;
		z=7;
	}
		else if(i==4)
	{
		x=2;
		y=5;
		z=8;
	}
		else if(i==5)
	{
		x=3;
		y=6;
		z=9;
	}
		else if(i==6)
	{
		x=1;
		y=5;
		z=9;
	}
		else if(i==7)
	{
		x=3;
		y=5;
		z=7;
	}
		if(squer[x]=='O' && squer[y]=='O'  && squer[z]=='O')
			{
				return true;
			}
		else if(squer[x]=='X' && squer[y]=='X' && squer[z]=='X')
			{
				return true;
			}
	}
int b=0;
	for(int i=1;i<=9;i++)
	{
		
		if(squer[i]!='0'+i)
		{
			b++;
		}
		if(b==9)
		{
			return true;
		}
	}
	
	return false;
}

void stm()
{
	system("Color 3B");
	
  HWND console = GetConsoleWindow();
  RECT r;
  GetWindowRect(console, &r); 
  MoveWindow(console, r.left, r.top, 360, 210, TRUE);
}
int main()
{
	
	stm();
	
	int i;
	char p='O';
	
	int nbp=0;
	
	Squer();
	cout<<endl<<"************* Start plying *************"<<endl;
	play();	
	
	while(chfiniched()==false)
	{
		
			
			cout<<endl<<endl<<"Play :";
			cin>>i;
			if(nbp%2==0)
			{
				p='O';
			}
			else
			{
				p='X';
			}
			Squer(i,p);
			system ("CLS");
			cout<<endl<<"************* Start plying *************"<<endl;
			play();	
			
			nbp++;
		
	}

	  cout<<endl<<endl<<"************** Game Over **************"<<endl;
	
}

/**************************

	1 | 2 | 3
	--|---|--
	4 | 5 | 6
	--|---|--
	7 | 8 | 9

**************************/
