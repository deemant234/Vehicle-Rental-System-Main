#include<iostream>
#include<cstdio>
#include<string>
#include<ios> 
#include<limits>
#include<algorithm>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<fstream>
#include<iomanip>
#include<conio.h>
using namespace std;
template <typename T> bool check(T d1, T d2,T m1,T m2,T y1,T y2)
{
	 if(d1>d2&&m1>m2)
    {
    	if(y1>y2||y1==y2)
        return true;
        else
        return false;
    }
    else
    if(d1>=d2&&m1==m2)
    {
	if(y1==y2||y1>y2)
    return true;
    else
    if(y1<y2)
    return false;
	}
	else
    if(d1<d2&&m1>m2)
    {
    	if(y1>y2||y1==y2)
    return true;
    else
    if(y1<y2)
    return false;
	}
	else
    if(d1<d2&&m1==m2)
    {
    	if(y1>y2)
    	return true;
    	else
    	if(y1==y2||y1<y2)
    	return false;
	}
	else
	if(d1>d2&&m1<m2)
	{
		if(y1>y2)
    return true;
    else
    if(y1==y2||y1<y2)
    return false;
	}
	else
	if(d1<d2&&m1<m2)
	{
		if(y1>y2)
		return true;
		else
		return false;
	}
}
int ctr1=0,ctr2=0,ctr3=0,ctr4=0,ctr5=0,ctr6=0,ctr7=0,ch,ch1,ch2=0,ch3,i,days,commission;//global variables
struct Common_User
{
    char name[30];
    char mob_no[11];
}CU[5];
struct Using_Vehicle_List
{
    char name[30];
    char mob_no[11];
}UV[5];
struct Renting_Vehicle_List
{
    char name[30];
    char mob_no[11];
}RV[5];
struct User_for_Using_Vehicle_Max_Days
{
    char nameU[30],nameO[30],mob_noU[11],mob_noO[11],veh_no[20];
    int d,m,y,type_of_veh,max_days;
}listUVMD[5];
struct User_for_Using_Vehicle_NO_Max_Days
{
    char nameU[30],nameO[30],mob_noU[11],mob_noO[11],veh_no[20];
    int d,m,y,type_of_veh;
}listUVD[5];
struct User_for_Using_Vehicle
{
    char name[30],mob_no[11],veh_no[20];
    int no_of_days,type_of_veh,d1,d2,m1,m2,y1,y2;
}listUV[5];
struct User_for_Using_Vehicle_Tmp
{
    char name[30],mob_no[11],veh_no[20];
    int type_of_veh;
}listUVT[5];
struct User_for_Renting_Vehicle
{
    char name[30],mob_no[11],veh_no[20];
    int type_of_veh;//no of days to be checked,commision to be added
}listRV[5];
class User
{
    char name[30],veh_no[20];
    int check_del,ty_veh,d1,d2,m1,m2,y1,y2;
    float fare;
    char mob_no[11];
    fstream fofUVM,fofUVNM,fofV,fofCU,fofRV,fofUV,foutR,ftmp1,ftmp2,fofR,fofU,fofRV1,fofUV1,foftmp,fofCU1;
    public:
    User()
    {
    	foftmp.open("tmp_file.txt",ios::app|ios::binary|ios::out|ios::in);
        fofUVM.open("user_using_vehicle_max_days.txt",ios::binary|ios::app|ios::out|ios::in);
        fofUVNM.open("user_using_vehicle_no_max_days.txt",ios::binary|ios::app|ios::out|ios::in);
        ftmp2.open("tmp2.txt",ios::binary|ios::app|ios::out|ios::in);
        ftmp1.open("tmp1.txt",ios::binary|ios::app|ios::out|ios::in);
		fofCU.open("common_user.txt",ios::binary|ios::app|ios::in|ios::out);
        fofCU1.open("common_user.txt",ios::binary|ios::app|ios::out|ios::in);
		fofV.open("vehicle_list.txt",ios::app|ios::binary|ios::out|ios::in);
        fofRV1.open("User_for_Renting_Record.txt",ios::app|ios::binary|ios::out|ios::in);
		fofRV.open("User_for_Renting_Record.txt",ios::app|ios::binary|ios::out|ios::in);
        fofUV.open("User_for_Using_Record.txt",ios::app|ios::binary|ios::in|ios::out);
        fofUV1.open("User_for_Using_Record.txt",ios::app|ios::binary|ios::in|ios::out);
		fofR.open("Renting_User.txt",ios::app|ios::binary|ios::out|ios::in);
        fofU.open("Using_User.txt",ios::app|ios::binary|ios::out|ios::in);
        cout.width(500);
        cout<<"Welcome to vehicle rental system ,press any key to continue\n\n";
        ch=getch();
    }
    void users();
    void remove_veh();
    void Using_for_fixed_days(int,int,int);
    int offsetDays(int ,int ,int );
    bool isLeap(int);
    bool newUser();
    bool registeredUser();
    void userServices();
    void portal();
    void UserPortal();
    friend void checkPortal();
    void newUserPortal();
    void newUserPortalFail();
    void registeredUserPortal();
    void RegisteredUserPortalFail();
    void fareC();
    void Using_for_fixed_days();
    void addDays(int,int,int,int);
    void revoffsetDays(int,int,int*,int*);
    int maxDays(int,int,int,int,int,int);
    void display();
    ~User()
    {
    	foftmp.close();
        fofR.close();
        fofRV.close();
        fofU.close();
        fofRV1.close();
        fofCU1.close();
        fofUV.close();
        fofUV1.close();
        fofV.close();
        fofUVM.close();
        fofUVNM.close();
        fofCU.close();
    }
};
void User::display()
{
    i=0;
    fofRV.clear();
    fofRV.seekg(0,ios::beg);
    fofRV.read((char*)&listRV[0],sizeof(listRV[0]));
    while (fofRV.eof()==0)
    {
        cout<<setw(10)<<i;
        cout<<setw(11)<<"name:\t"<<setw(10)<<listRV[0].name<<endl;
        cout<<setw(11)<<"mobile number: \t"<<listRV[0].mob_no<<endl;
        cout<<setw(11)<<"vehicle number:\t"<<listRV[0].veh_no<<endl;
        cout<<setw(11)<<"vehicle type:\t"<<setw(3)<<listRV[0].type_of_veh<<endl<<setfill('*')<<"\n";
        i++;
        fofRV.read((char*)&listRV[0],sizeof(listRV[0]));
    }
}
void User::users()
{
    i=0;
    fofU.read((char*)&UV[0],sizeof(UV[0]));
    while (fofU.eof()==0)
    {
        cout<<setw(10)<<i;
        cout<<setw(11)<<"name:\t"<<setw(10)<<UV[0].name<<endl;
        cout<<setw(11)<<"mobile number: \t"<<UV[0].mob_no<<endl;
        i++;
        fofU.read((char*)&UV[0],sizeof(UV[0]));
    }
}
void User::remove_veh()
{
    cout<<"Enter name of owner\n";
    cin.getline(name,30,'\n');
    i=strlen(name);
	for(ctr2=0;ctr2<i;ctr2++)
    {
        name[ctr2]=toupper(name[ctr2]);
    }
    cout<<"Enter vehicle number\n";
    cin.getline(veh_no,20,'\n');
    i=strlen(veh_no);
	for(ctr2=0;ctr2<i;ctr2++)
    {
        veh_no[ctr2]=toupper(veh_no[ctr2]);
    }
    fofRV.clear();
    fofRV.seekg(0,ios::beg);
    fofRV.read((char*)&listRV[0],sizeof(listRV[0]));
    while (fofRV.eof()==0)
    {
        if(strcmp(listRV[0].name,name)==0&&strcmp(listRV[0].veh_no,veh_no)!=0)
        {
            ftmp1.write((char*)&listRV[0],sizeof(listRV[0]));
        }
        else
        {
            cout<<"starting date of rental\n";
            cin>>d1;
            cout<<"starting month of rental\n";
            cin>>m1;
            cout<<"starting year of rental\n";
            cin>>y1;
            cout<<"please enter today's date\n";
            cin>>d2;
            cout<<"month\n";
            cin>>m2;
            cout<<"year\n";
            cin>>d2;
            days=maxDays(d1,m1,y1,d2,m2,y2);
            if(listRV[0].type_of_veh==2)
            {
                commission=days*800;
                cout<<"profit gained is:\t"<<commission<<endl;
            }
            else
            if(listRV[0].type_of_veh==4)
            {
                commission=days*1500;
                cout<<"profit gained is:\t"<<commission<<endl;
            }
            else
            if (listRV[0].type_of_veh==3)
            {
                commission=days*1000;
                cout<<"profit gained is:\t"<<commission<<endl;
            }
            else
            {
                commission=days*2000;
                cout<<"profit gained is:\t"<<commission<<endl;    
            }
        }
        fofRV.read((char*)&listRV[0],sizeof(listRV[0]));
    }
    fofRV.close();
    ftmp1.close();
    remove("User_for_Renting_Record.txt");
    rename("tmp1.txt","User_for_Renting_Record.txt");
    cout<<"vehicle removed successfully\n";
}
void User::registeredUserPortal()
{
    if(registeredUser()==true)
        {
            while(1)
            {
            cout<<"you are a  registered user , press 1 to continue , press 2 to go back\n";
            cin>>ch2;
            if(ch2==1)
            {
                userServices();
                break;
            }
            else
            if(ch2==2)
            {
                UserPortal();
                break;
            }
            else
            {
                cout<<"please enter a valid choice\n";
            }
            }
        }
        else
        {
            RegisteredUserPortalFail();
            exit(1);
        }
}
void User::RegisteredUserPortalFail()
{
    cout<<"We could not find your account , please enter 1 to try again , 2 to go back\n";
    cin>>ch1;
    if(ch1==1)
    {
        registeredUserPortal();
        exit(1);
    }
    else
    if(ch1==2)
    {
        UserPortal();
        exit(1);
    }
    else
    {
        cout<<"please enter a valid choice\n";
        RegisteredUserPortalFail();
        exit(1);
    }
}
void User::newUserPortal()
{   
    while(true)
    {    
        if(newUser()==true)
        {
            cout<<"you have been successfully registered , press 1 to continue , press 2 to go back\n";
            cin>>ch2;
            if(ch2==1)
            {
                userServices();
                break;
            }
            else
            if(ch2==2)
            {
                UserPortal();
                break;
            }
            else
            {
                cout<<"please enter a valid choice\n";
            }
        }
        else
        {
        newUserPortalFail();
        break;
        }
    }
}
void User::newUserPortalFail()
{
    cout<<"Your account could not be created , sorry for the inconveniance,press 1 to try again,2 to go back\n";
    cin>>ch2;
    if(ch2==1)
    {
        newUserPortal();
    }
    else
    if(ch2==2)
    {
        UserPortal();
    }
    else
    {
        cout<<"please enter a valid choice\n";
        newUserPortalFail();
    }
}
void User::UserPortal()
{
    cout<<"please enter 1 if you are a new user, 2 if you are a registered user, 3 to exit\n";
    cin>>ch1;
            if(ch1==1)
            {
                newUserPortal();
            }
            else
            if(ch1==2)
            {
               registeredUserPortal();
            }
            else
            if(ch1==3)
            {
                exit(1);
            }
            else
            {
                cout<<"please enter a valid choice\n";
                UserPortal();
            }    
}
bool User::newUser()
{
    cout<<"PLEASE ENTER YOUR NAME\n";
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    cin.getline(CU[0].name,30,'\n');
    i=strlen(CU[0].name);
    for(ctr2=0;ctr2<i;ctr2++)
    {
        CU[0].name[ctr2]=toupper(CU[0].name[ctr2]);
    }
    cout<<"PLEASE ENTER YOUR MOBILE NUMBER\n";
    cin>>CU[0].mob_no;
    if(fofCU1.good()==true)
    {
        fofCU.write((char*)&CU[0],sizeof(CU[0]));
        return true;
    }
    else
    return false;
}
bool User::registeredUser()
{
    cout<<"please enter your name\n";
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    cin.getline(name,30,'\n');
    i=strlen(name);
    for(ctr2=0;ctr2<i;ctr2++)
    {
        name[ctr2]=toupper(name[ctr2]);
    }
    cout<<"please enter your mobile number\n";
    cin>>mob_no;
    fofCU.seekg(0,ios::beg);
    fofCU.read((char*)&CU[1],sizeof(CU[1]));
    do
    {
        if(strcmp(CU[1].name,name)==0&&(strcmp(CU[1].mob_no,mob_no)==0))
        {
        ctr1++;
        break;	
    	}
    	fofCU.read((char*)&CU[1],sizeof(CU[1]));
    }while(fofCU.eof()==0);
    fofCU.clear();
    if(ctr1!=0)
    return true;
    else
    return false;
}
bool User::isLeap(int y)
{
	if (y%100 != 0 && y%4 == 0 || y %400 == 0)
		return true;
	return false;
}
int User::offsetDays(int d, int m, int y)
{
	int offset = d;
	switch (m - 1)
	{
	case 11:
		offset += 30;
	case 10:
		offset += 31;
	case 9:
		offset += 30;
	case 8:
		offset += 31;
	case 7:
		offset += 31;
	case 6:
		offset += 30;
	case 5:
		offset += 31;
	case 4:
		offset += 30;
	case 3:
		offset += 31;
	case 2:
		offset += 28;
	case 1:
		offset += 31;
	}
	if (isLeap(y)==true&& m > 2)
	offset += 1;
	return offset;
}
void User::revoffsetDays(int offset, int y, int *d, int *m)
{
	int month[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (isLeap(y))
		month[2] = 29;
	int i;
	for (i = 1; i <= 12; i++)
	{
		if (offset <= month[i])
			break;
		offset = offset - month[i];
	}
	*d = offset;
	*m = i;
}


void User::addDays(int d1,int m1,int y1,int x)
{
	int offset1 = offsetDays(d1, m1, y1);
	int remDays = isLeap(y1)?(366-offset1):(365-offset1);
	// y2 is going to store result year and
	// offset2 is going to store offset days
	// in result year.
	int offset2;
	if (x <= remDays)
	{
		y2 = y1;
		offset2 = offset1 + x;
	}
	else
	{
		// x may store thousands of days.
		// We find correct year and offset
		// in the year.
		x -= remDays;
		y2 = y1 + 1;
		int y2days = isLeap(y2)?366:365;
		while (x >= y2days)
		{
			x -= y2days;
			y2++;
			y2days = isLeap(y2)?366:365;
		}
		offset2 = x;
	}
	// Find values of day and month from
	// offset of result year.
	revoffsetDays(offset2, y2, &d2, &m2);
	listUV[0].d2=d2;
    listUV[0].m2=m2;
    listUV[0].y2=y2;
}
void User::fareC()
{
	switch (ty_veh)
                {
                case 1:
                fare=days*500;
                break;
                case 2:
                fare=days*1000;
                break;
                case 3:
                fare=days*1500;
                break;
                case 4:
                fare=days*2000;
                break;
                default:
                fare=days*3000;
                break;
                }
}
void User::Using_for_fixed_days()
{
                cout<<"Enter number of days till which vehicle is required\n";
                cin>>listUV[0].no_of_days;
                cout<<"Enter starting date\n";
                cin>>d1;
                cout<<"Enter starting month\n";
                cin>>m1;
                cout<<"Enter starting year\n";
                cin>>y1;
                listUV[0].d1=d1;
                listUV[0].m1=m1;
                listUV[0].y1=y1;
                addDays(d1, m1, y1, listUV[0].no_of_days);
                switch (ty_veh)
                {
                case 1:
                fare=listUV[0].no_of_days*500;
                break;
                case 2:
                fare=listUV[0].no_of_days*1000;
                break;
                case 3:
                fare=listUV[0].no_of_days*1500;
                break;
                case 4:
                fare=listUV[0].no_of_days*2000;
                break;
                default:
                fare=listUV[0].no_of_days*3000;
                break;
                }
}
void User::Using_for_fixed_days(int d1,int m1,int y1)
{
                addDays(d1, m1, y1,days);
                switch (ty_veh)
                {
                case 1:
                fare=listUV[0].no_of_days*500;
                break;
                case 2:
                fare=listUV[0].no_of_days*1000;
                break;
                case 3:
                fare=listUV[0].no_of_days*1500;
                break;
                case 4:
                fare=listUV[0].no_of_days*2000;
                break;
                default:
                fare=listUV[0].no_of_days*3000;
                break;
                }
}
int User::maxDays(int d1,int m1,int y1,int d2,int m2,int y2)
{
    int tmpm,tmpd,tmpy;
	int arr1[]={31,28,31,30,31,30,31,31,30,31,30,31};
	int arr2[]={31,29,31,30,31,30,31,31,30,31,30,31};
	int no,tmp1=0,tmp2=0,tmp3=0,tmp4=0,i,tmp,ctr=0;
	if(y2<y1)
	{
		tmpd=d2;
		tmpm=m2;
		tmpy=y2;
		d2=d1;
		m2=m1;
		y2=y1;
		d1=tmpd;
		m1=tmpm;
		y1=tmpy;
	}
	else
	if((y2==y1&&m2<m1)||(y2==y1&&m2==m1&&d2<d1))
	{
		tmpd=d2;
		tmpm=m2;
		tmpy=y2;
		d2=d1;
		m2=m1;
		y2=y1;
		d1=tmpd;
		m1=tmpm;
		y1=tmpy;
	}
	if(y1==y2&&m1==m2)
	{
		no=d2-d1;
	}
	else
	if(y1==y2&&m1!=m2)
	{
		if(y1%400==0)
		{
			tmp1=arr2[m1-1]-d1;
			tmp2=d2;
			for(i=m1;i<m2-1;i++)
			{
				tmp3=tmp3+arr2[i];
			}
			no=tmp1+tmp2+tmp3;
		}
		else
		{
			tmp1=arr1[m1-1]-d1;
			tmp2=d2;
			for(i=m1;i<m2-1;i++)
			{
				tmp3=tmp3+arr1[i];
			}
			no=tmp1+tmp2+tmp3;
		}
	}
	else
	if(y2>y1)
	{
		tmp=y1;
		if(tmp%400==0)
		{
			for(ctr=m1;ctr<12;ctr++)
			{
				tmp1=tmp1+arr2[ctr];
			}
			tmp2=arr2[m1-1]-d1;
		}
		else
		if(tmp%4==0&&tmp%100!=0)
		{
			for(ctr=m1;ctr<12;ctr++)
			{
				tmp1=tmp1+arr2[ctr];
			}
			tmp2=arr2[m1-1]-d1;
		}
		else
		{
			for(ctr=m1;ctr<12;ctr++)
			{
				tmp1=tmp1+arr1[ctr];
			}
			tmp2=arr1[m1-1]-d1;
		}
		for(i=tmp+1;i<y2;i++)
		{
			if(i%400==0)
			tmp3=tmp3+366;
			else
			if(i%4==0&&i%100!=0)
			tmp3=tmp3+366;
			else
			tmp3=tmp3+365;	
		}
		if(y2%400==0)
		{
			for(i=0;i<m2-1;i++)
			tmp4=tmp4+arr2[i];
			no=tmp1+tmp2+tmp3+tmp4+d2+5;
		}
		else
		if(y2%4==0&&y2%100!=0)
		{
			for(i=0;i<m2-1;i++)
			tmp4=tmp4+arr2[i];
			no=tmp1+tmp2+tmp3+tmp4+d2;
		}
		else
		{
			for(i=0;i<m2-1;i++)
			tmp4=tmp4+arr1[i];
			no=tmp1+tmp2+tmp3+tmp4+d2;
		}
	}
	return no;
}
void User::userServices()
{
    cout<<"Please enter 1 if you want to take a vehicle on rent , please enter 2 if you want to give your vehicle on rent, please enter 3 if you want to return the vehicle taken on rent\n";
    cin>>ch1;
    switch (ch1)
    {
        case 1:
        cout<<"Please enter your name\n";
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cin.getline(name,30,'\n');
        i=strlen(name);
        for(ctr2=0;ctr2<i;ctr2++)
        {
            name[ctr2]=toupper(name[ctr2]);
        }
        cout<<"please enter your mobile number\n";
        cin>>mob_no;
        fofCU.clear();
        fofCU.seekg(0,ios::beg);
        while (fofCU.eof()==0)
        {
            fofCU.read((char*)&CU[0],sizeof(CU[0]));
            if(strcmp(CU[0].name,name)==0&&strcmp(CU[0].mob_no,mob_no)==0)
            {
                ctr3++;
                break;
            }
        }
        fofCU.clear();
        if(ctr3!=0)
        {
            strcpy(listUV[0].name,name);
            strcpy(listUV[0].mob_no,mob_no);
        }
        else
        {
            while (1)
            {
            cout<<"Could not find name registered in our database ,please enter 1 to try again , 2 to go back\n";
            cin>>ch2;
            if (ch2==1)
            {
                userServices();
                exit(1);
            }
            else
            if(ch2==2)
            {
                UserPortal();
                exit(1);
            }
            else
            {
                cout<<"Enter a valid choice please\n";
            }
            }
        }
        cout<<"please enter type of vehicle required\n";
		cin>>ty_veh;
        listUV[0].type_of_veh=ty_veh;
        	fofRV.clear();
            fofRV.seekg(0,ios::beg);
            fofRV.read((char*)&listUVT[0],sizeof(listUVT[0]));
			do
			{
                if (listUVT[0].type_of_veh==ty_veh)
                {
                    ctr4++;
                    cout<<"vehicle owner name :\t"<<listUVT[0].name<<endl;
                    cout<<"vehicle number :\t"<<listUVT[0].veh_no<<endl;
                    cout<<"vehicle type :\t"<<listUVT[0].type_of_veh<<endl;
                }
            fofRV.read((char*)&listUVT[0],sizeof(listUVT[0]));
            }while(fofRV.eof()==0);
            fofRV.clear();
            fofRV.seekg(0,ios::beg);
            if(ctr4!=0)//to be closed and else vehicle not found to be added
            {
            cout<<"Please enter the vehicle number you would like to take on rent\n";
            cin>>veh_no;
            i=strlen(veh_no);
            for(ctr2=0;ctr2<i;ctr2++)
            {
            veh_no[ctr2]=toupper(veh_no[ctr2]);
            }
            strcpy(listUV[0].veh_no,veh_no);
            cout<<"entered veh no is "<<veh_no<<endl;
            fofRV.seekg(0,ios::beg);
            system("CLS");
            fofRV1.clear();
			fofRV1.seekg(0,ios::beg);
            while(!fofRV1.eof())
            {
            	fofRV1.read((char*)&listUVT[1],sizeof(listUVT[1]));
            	if(strcmp(listUVT[1].veh_no,veh_no)==0)
            	{
            		break;
				}
			}
			fofRV1.clear();
			fofRV1.seekg(0,ios::beg);
            cout<<"You have selected vehicle number :\t"<<listUVT[1].veh_no<<endl;
            cout<<"press 1 to confirm , 2 to cancel\n";//while loop can be used
            cin>>ch1;
            if(ch1==1)
            {
                cout<<"Press 1 if you want to rent a vehicle for fixed number of days, press 2 if you want to rent a vehicle for undefined time\n";
                cin>>ch2;
                if(ch2==1)
                {
                Using_for_fixed_days();
                fofUV.clear();
                fofUV.seekg(0,ios::beg);
                fofUV.read((char*)&listUV[2],sizeof(listUV[2]));
                while(fofUV.eof()==0)
                {
					if(strcmp(veh_no,listUV[2].veh_no)==0)
					{
						if(check(d1,listUV[2].d1,m1,listUV[2].m1,y1,listUV[2].y1))
						{
							if(check(listUV[2].d2,d1,listUV[2].m2,m1,listUV[2].y2,y1))
							{
								ctr5++;
							}
						}
						if(!check(listUV[2].d1,d2,listUV[2].m1,m2,listUV[2].y1,y2))
						{
							if(!check(d2,listUV[2].d2,m2,listUV[2].m2,y2,listUV[2].y2))
							{
								ctr5++;
							}
						}
					}
                	fofUV.read((char*)&listUV[2],sizeof(listUV[2]));
				}
				if(ctr5!=0)
				{
					cout<<"vehicle not available at the moment , please try again later\n";
					userServices();
					exit(1);
				}
				else
				{
					cout<<"vehicle available for booking\n\n";
				
                fofUV.clear();
                cout.fill('*');
                cout.width(500);
                cout<<"Name of person :\t"<<name<<endl;
                cout.fill('*');
                cout.width(500);
                cout<<"Mobile Number of person:\t"<<mob_no<<endl;
                cout.fill('*');
                cout.width(500);
                cout<<"Vehicle type is:\t"<<veh_no<<" wheeler"<<endl;
                cout.fill('*');
                cout.width(500);
                cout<<"Vehicle is taken on rent for :\t"<<listUV[0].no_of_days<<" days\n\n"<<endl;
                cout.width(500);
                cout.fill('*');
                cout<<"TOTAL FARE IS :\t"<<fare<<endl;
                while (true)
                {
                cout<<"press 1 to confirm your ride , 2 to cancel it\n";
                cin>>ch;
                if(ch==1)
                {
                    cout.widen(5);
                    cout.width(250);
                    strcpy(listUV[0].name,name);
                    strcpy(listUV[0].veh_no,veh_no);
                    strcpy(listUV[0].mob_no,mob_no);
                    strcpy(UV[0].name,name);
                    strcpy(UV[0].mob_no,mob_no);
					cout<<" Congratulations for your ride ,enjoy it \n\n";
                    fofUV.write((char*)&listUV[0],sizeof(listUV[0]));
                    fofU.write((char*)&UV[0],sizeof(UV[0]));
                    break;
                }
                else
                if(ch==2)
                {
                userServices();
                break;
                }
                else
                {
                    cout<<"please  enter a valid choice\n";
                }
                } 
        	}
        }
            else
            if(ch2==2)
            {
                cout<<"Enter starting date\n";
                cin>>d1;
                cout<<"Enter starting month\n";
                cin>>m1;
                cout<<"Enter starting year\n";
                cin>>y1;
                listUV[0].d1=d1;
                listUV[0].m1=m1;    
                listUV[0].y1=y1;
                fofUV.clear();
                fofUV.seekg(0,ios::beg);
                fofUV.read((char*)&listUV[2],sizeof(listUV[2]));
                while(fofUV.eof()==0)
                {
                if(strcmp(listUV[2].veh_no,veh_no)==0)
				{
				if(check(listUV[2].d1,d1,listUV[2].m1,m1,listUV[2].y1,y1))
				{
				listUV[3].d1=listUV[2].d1;
                listUV[3].d2=listUV[2].d2;
                listUV[3].m1=listUV[2].m1;
                listUV[3].m2=listUV[2].m2;
                listUV[3].y1=listUV[2].y1;
                listUV[3].y2=listUV[2].y2;
                listUV[3].no_of_days=listUV[2].no_of_days;
                listUV[3].type_of_veh=listUV[2].type_of_veh;
				strcpy(listUV[3].mob_no,listUV[2].mob_no);
                strcpy(listUV[3].name,listUV[2].name);
                strcpy(listUV[3].veh_no,listUV[2].veh_no);
            	}
            	}
            	fofUV.read((char*)&listUV[2],sizeof(listUV[2]));
            	}
            	fofUV.clear();
            	fofUV.seekg(0,ios::beg);
                while(fofUV.eof()==0)
                {
                	fofUV.read((char*)&listUV[2],sizeof(listUV[2]));
                    if(strcmp(listUV[2].veh_no,veh_no)==0)
                    {
						if(check(listUV[2].d1,d1,listUV[2].m1,m1,listUV[2].y1,y1))
                    	{
                    		if(check(listUV[3].d1,listUV[2].d1,listUV[3].m1,listUV[2].m1,listUV[3].y1,listUV[2].y1))
							{
								if(check(listUV[2].d1,d1,listUV[2].m1,m1,listUV[2].y1,y1))
							{								
								listUV[3].d1=listUV[2].d1;
                				listUV[3].d2=listUV[2].d2;
                				listUV[3].m1=listUV[2].m1;
                				listUV[3].m2=listUV[2].m2;
                				listUV[3].y1=listUV[2].y1;
                				listUV[3].y2=listUV[2].y2;
                				listUV[3].no_of_days=listUV[2].no_of_days;
                				listUV[3].type_of_veh=listUV[2].type_of_veh;
								strcpy(listUV[3].mob_no,listUV[2].mob_no);
                				strcpy(listUV[3].name,listUV[2].name);
                				strcpy(listUV[3].veh_no,listUV[2].veh_no);
							}
							}
							ctr6++;	
						}
						else
						if(check(d1,listUV[2].d1,m1,listUV[2].m1,y1,listUV[2].y1))
						{
							if(check(listUV[2].d2,d2,listUV[2].m2,m2,listUV[2].y2,y2))
							ctr7++;
						}
					}					
				}
				fofUV.clear();
				fofUV.seekg(0,ios::beg);
				cout<<ctr6<<endl<<ctr7<<endl;
				if(ctr7!=0)
				{
					cout<<"case `1\n";//testing 2
					cout<<"vehicle not available at the moment,please try again later\n";
					userServices();//testing 11 else use exit(1)			
					exit(1);	
				}
				else
				if(ctr7==0&&ctr6!=0)
				{
						cout<<"case 2\n";//testing 1
						days=maxDays(d1,m1,y1,listUV[3].d1,listUV[3].m1,listUV[3].y1);
						cout.width(200);
                        cout.fill('!');
                        cout<<"\n\n";
                        cout<<"You can take the vehicle for maximum of "<<days<<" number of days,else you will be fined \n";
                        while(true)
                        {
                        	cout<<"press 1 to confirm , 2 to cancel\n";
                        	cin>>ch3;
						if(ch3==1)
                        {
                            strcpy(listUVMD[0].nameU,name);
                            strcpy(listUVMD[0].nameO,listUVT[1].name);
                            strcpy(listUVMD[0].mob_noU,mob_no);
                            strcpy(listUVMD[0].mob_noO,listUVT[0].mob_no);
                            listUVMD[0].d=d1;
                            listUVMD[0].m=m1;
                            listUVMD[0].y=y1;
                            listUVMD[0].max_days=days;
                            listUVMD[0].type_of_veh=ty_veh;
                            strcpy(listUVMD[0].veh_no,veh_no);
                            fofUVM.clear();
                            fofUVM.seekg(0,ios::beg);
                            fofUVM.write((char*)&listUVMD[0],sizeof(listUVMD[0]));
                            fofRV.clear();
                            fofRV.seekg(0,ios::beg);
                            fofRV.read((char*)&listUVT[0],sizeof(listUVT[0]));
                            while(fofRV.eof()==0)
                            {
                                if(strcmp(listUVT[0].veh_no,listUVMD[0].veh_no)!=0)
                                {
                                	foftmp.write((char*)&listUVT[0],sizeof(listUVT[0]));
								}
								if(fofRV.eof()!=0)
								break;
								fofRV.read((char*)&listUVT[0],sizeof(listUVT[0]));	   
							}
                            fofRV.close();
							foftmp.close();
							fofRV1.close();
							remove("User_for_Renting_Record.txt");
							rename("tmp_file.txt","User_for_Renting_Record.txt");
							cout.width(200);
                            cout.fill('!');
                            cout<<"\n\n";
                            Using_for_fixed_days(d1,m1,y1);
                            cout<<"Enjoy your ride and please return the vehicle by "<<d2<<":"<<m2<<":"<<y2<<endl;
                            break;
                        }
                        else
                        if(ch3==2)
                        {
                        	cout<<"you have chose to exit the window\n";
                        	exit(1);
						}
                    }
                }
                    else
                    {
                        while (true)
                        {
                        cout<<"case 3\n";//testing 3
                        cout<<"press 1 to confirm , 2 to cancel\n";
                        cin>>ch3;
                        if(ch3==1)
                        {
                            strcpy(listUVD[0].nameU,name);
                            strcpy(listUVD[0].nameO,listUVT[1].name);                            
                            strcpy(listUVD[0].mob_noU,mob_no);
                            strcpy(listUVMD[0].mob_noO,listUVT[0].mob_no);
                            listUVD[0].d=d1;
                            listUVD[0].m=m1;
                            listUVD[0].y=y1;
                            listUVD[0].type_of_veh=ty_veh;
                            strcpy(listUVD[0].veh_no,veh_no);
                            fofUVNM.clear();
                            fofRV.clear();
                            fofUVNM.write((char*)&listUVD[0],sizeof(listUVD[0]));
                            fofRV.seekg(0,ios::beg);
                            fofRV.read((char*)&listUVT[0],sizeof(listUVT[0]));
                            while (fofRV.eof()==0)
                            {
                                if(strcmp(listUVT[0].veh_no,listUVD[0].veh_no)!=0)
                                {
                                    foftmp.write((char*)&listUVT[0],sizeof(listUVT[0]));
                                }
                                if(fofRV.eof()!=0)
                                break;
                                fofRV.read((char*)&listUVT[0],sizeof(listUVT[0]));
                            }
                            fofRV.close();
                            fofRV1.close();
                            foftmp.close();
                            remove("User_for_Renting_Record.txt");
                            rename("tmp_file.txt","User_for_Renting_Record.txt");
                            cout.width(200);
                            cout.fill('!');
                            cout<<"\n\n";
                            cout<<"Enjoy your ride "<<endl;
                        	break;
                        }
                        else
                        if(ch3==2)
                        {
                            exit(1);//testing 15 userServices() can be used
                        }
                        else
                        {
                            cout<<"PLEASE ENTER A VALID CHOICE\n";
                        }
                    }
                    }
                cout.fill('*');
                cout.width(500);
                cout<<"Name of person :\t"<<listUV[0].name<<endl;
                cout.fill('*');
                cout.width(500);
                cout<<"Mobile Number of person:\t"<<listUV[0].mob_no<<endl;
                cout.fill('*');
                cout.width(500);
                cout<<"Vehicle number is:\t"<<veh_no<<" wheeler"<<endl;
                cout.fill('*');
                cout.width(500);
                cout<<"TOTAL FARE IS WILL BE CALCULATED AT VEHICLE RETURN TIME"<<endl;
                cout<<"Press 1 to confirm , 2 to cancel\n";
                cin>>ch3;
                if(ch3==1)
                {
                	strcpy(UV[0].name,name);
                	strcpy(UV[0].mob_no,mob_no);
                	fofU.write((char*)&UV[0],sizeof(UV[0]));
                    cout<<"Enjoy your ride\n";   
                }
            }
        }
    }
    else
    cout<<"vehicle not found\n";
        break;
        case 2:
        ctr2=0;
        cout<<"please enter your name\n";
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cin.getline(name,30,'\n');
        i=strlen(name);
        for(ctr2=0;ctr2<i;ctr2++)
        {
            name[ctr2]=toupper(name[ctr2]);
        }
        cout<<"Please enter your mobile number\n";
        cin>>mob_no;
        fofCU.clear();
        fofCU.seekg(0,ios::beg);
        while (fofCU.eof()==0)
        {
            fofCU.read((char*)&CU[2],sizeof(CU[0]));
            if(CU[2].name==name&&strcmp(CU[2].mob_no,mob_no)==0)
            {
                ctr2++;
                break;
            }
        }
        if(ctr2!=0)
        {
            strcpy(listRV[0].name,name);
            strcpy(listRV[0].mob_no,mob_no);
            strcpy(RV[0].name,name);
            strcpy(RV[0].mob_no,mob_no);
        }
        else
        {
            cout<<"We could not find your data , press 1 to try again,press 2 to exit\n";
            cin>>ch1;
            if(ch1==1)
            {
                userServices();
            }
            else
            exit(1);
        }
        cout<<"Enter type of your vehicle\n";
        cin>>ty_veh;
        listRV[0].type_of_veh=ty_veh;
        cout<<"Enter vehicle number\n";
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cin.getline(veh_no,20,'\n');
        i=strlen(veh_no);
        for(ctr2=0;ctr2<i;ctr2++)
        {
            veh_no[ctr2]=toupper(veh_no[ctr2]);
        }
        strcpy(listRV[0].veh_no,veh_no);
        cout<<"Your vehicle has been registered successfully\n";
        fofRV.write((char*)&listRV[0],sizeof(listRV[0]));
        fofR.write((char*)&RV[0],sizeof(RV[0]));
        break;
        case 3://returning a vehicle
        cout<<"enter your name\n";
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cin.getline(name,30,'\n');
        i=strlen(name);
		for(ctr2=0;ctr2<i;ctr2++)
        {
            name[ctr2]=toupper(name[ctr2]);
        }
		cout<<"please enter your vehicle number\n";
        cin.getline(veh_no,20,'\n');
        i=strlen(veh_no);
		for(ctr2=0;ctr2<i;ctr2++)
        {
            veh_no[ctr2]=toupper(veh_no[ctr2]);
        }
        fofUVM.clear();
        fofUVM.seekg(0,ios::beg);
        fofUVM.read((char*)&listUVMD[0],sizeof(listUVMD[0]));
        fofUVNM.clear();
        fofUVNM.seekg(0,ios::beg);
        fofUVNM.read((char*)&listUVD[0],sizeof(listUVD[0]));
        while(fofUVNM.eof()==0||fofUVM.eof()==0)
        {
        	if(strcmp(listUVD[0].veh_no,veh_no)==0)
        	{
				cout<<"enter today's date to calculate total fare\n";
				cin>>d2;
				cout<<"enter month\n";
				cin>>m2;
				cout<<"enter year\n";
				cin>>y2;
				days=maxDays(listUVD[0].d,listUVD[0].m,listUVD[0].y,d2,m2,y2);
				cout<<"number of days kept is \t"<<days<<endl;
				ty_veh=listUVD[0].type_of_veh;
				fareC();
				cout<<"name:\t"<<listUVD[0].nameU<<endl;
				cout<<"mob no:\t"<<listUVD[0].mob_noU<<endl;
				cout<<"Veh no:\t"<<listUVD[0].veh_no<<endl;
				cout.width(100);
				cout.fill('*');
				cout<<"total fare is:\t"<<fare<<endl;
				cout<<"press 1 to confirm ,2 to cancel\n";
				cin>>ch2;
				if(ch2==1)
				{
					listUVT[0].type_of_veh=listUVD[0].type_of_veh;
					strcpy(listUVT[0].mob_no,listUVD[0].mob_noO);
					strcpy(listUVT[0].name,listUVD[0].nameO);
					strcpy(listUVT[0].veh_no,listUVD[0].veh_no);
					fofRV.write((char*)&listUVT[0],sizeof(listUVT[0]));
					fofUVNM.clear();
					fofUVNM.seekg(0,ios::beg);
					fofUVNM.read((char*)&listUVD[0],sizeof(listUVD[0]));
					while(fofUVNM.eof()==0)
					{
						if(strcmp(listUVD[0].nameU,name)!=0&&strcmp(listUVD[0].veh_no,veh_no)!=0)
						{
							ftmp1.write((char*)&listUVD[0],sizeof(listUVD[0]));
						}
						fofUVNM.read((char*)&listUVD[0],sizeof(listUVD[0]));
					}
					fofUVNM.close();
					ftmp1.close();
		            remove("user_using_vehicle_no_max_days.txt");
					rename("tmp1.txt","user_using_vehicle_no_max_days.txt");
					break;
				}
				else
				if(ch2==2)
				{
					cout<<"you have opted to cancel the payment\n";
					exit(1);
				}
			}
            else
            if(strcmp(listUVMD[0].veh_no,veh_no)==0)
                {
                cout<<"enter today's date to calculate total fare\n";
				cin>>d2;
				cout<<"enter month\n";
				cin>>m2;
				cout<<"enter year\n";
				cin>>y2;
				days=maxDays(listUVMD[0].d,listUVMD[0].m,listUVMD[0].y,d2,m2,y2);
				cout<<"days is "<<days<<endl;
				ty_veh=listUVD[0].type_of_veh;
				fareC();
                if(days>listUVMD[0].max_days)
                {
                    cout<<"fine added is 10 percent of total fare \n";
                    fare=fare+(0.1*fare);
                }
				cout<<"name:\t"<<listUVMD[0].nameU<<endl;
				cout<<"mob no:\t"<<listUVMD[0].mob_noU<<endl;
				cout<<"Veh no:\t"<<listUVMD[0].veh_no<<endl;
				cout.width(100);
				cout.fill('*');
				cout<<"total fare is:\t"<<fare<<endl;
				cout<<"press 1 to confirm ,2 to cancel\n";
				cin>>ch2;
				if(ch2==1)
				{
					listUVT[0].type_of_veh=listUVMD[0].type_of_veh;
					strcpy(listUVT[0].mob_no,listUVMD[0].mob_noO);
					strcpy(listUVT[0].name,listUVMD[0].nameO);
					strcpy(listUVT[0].veh_no,listUVMD[0].veh_no);
					fofRV.write((char*)&listUVT[0],sizeof(listUVT[0]));
					fofUVM.clear();
					fofUVM.seekg(0,ios::beg);
					fofUVM.read((char*)&listUVMD[0],sizeof(listUVMD[0]));
					while(fofUVM.eof()==0)
					{
						if(strcmp(listUVMD[0].nameU,name)!=0&&strcmp(listUVMD[0].veh_no,veh_no)!=0)
						{
							ftmp2.write((char*)&listUVMD[0],sizeof(listUVMD[0]));
						}
						fofUVM.read((char*)&listUVMD[0],sizeof(listUVMD[0]));
					}
					fofUVM.close();
					ftmp2.close();
					remove("user_using_vehicle_max_days.txt");
					rename("tmp2.txt","user_using_vehicle_max_days.txt");
					break;
				}
				else
				if(ch2==2)
				{
					cout<<"you have opted to cancel the payment\n";
					exit(1);
                }
                }
            
            fofUVNM.read((char*)&listUVD[0],sizeof(listUVD[0]));
             fofUVM.read((char*)&listUVMD[0],sizeof(listUVMD[0]));
		    }
        break;
    default:
    	cout<<"exited due to invalid choice\n";
        break;
    }
}
class Admin:public User
{
    int choice;
    public:
    friend void checkPortal();
    void adminServices();
};
void Admin::adminServices()
{
        char AdmID[]="veh_rental";
        char Admpass[]="ACKKD123"; 
        char ID[20],pass[20];
        cout<<"Enter admin ID\n";
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cin.getline(ID,20,'\n');
        cout<<"Enter password\n";
        cin>>pass;
        while(1)
        {
        if(strcmp(ID,AdmID)==0&&strcmp(pass,Admpass)==0)
        {
            cout<<setw(10)<<setfill('!')<<"login successful\n";
            cout<<"Enter 1 to display all the vehicles available\n";
            cout<<"Enter 2 to display all the users taking vehicles on rent\n";
            cout<<"Enter 3 to remove a vehicle and calculate commission of owner\n";
            cin>>choice;
            switch (choice)
            {
                case 1:
                display();
                exit(1);
                break;
                case 2:
                users();
                exit(1);
                break;
                case 3:
                remove_veh();
                exit(1);
                break;
                default:
                cout<<"Enter a valid choice please\n";
                break;
            }
        }
        }
}
void checkPortal()
{
    Admin a;   
    cout<<"Please enter 1 for admin login , 2 for user portal , 3 to exit\n";
    cin>>ch1;
    if(ch1==1)
    {
        a.adminServices();
        exit(1);
    }
    else
    if(ch1==2)
    {
        a.UserPortal();
    }
    else
    if(ch1==3)
    exit(1);
}

int main()
{
    checkPortal();
    return 1;
}
    
