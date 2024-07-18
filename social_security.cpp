#include <iostream>
#include<string.h>
using namespace std;

struct date
{
    int year,month,day;
};

struct information
{
    long int num_insurance;
    string name_insurance;
};

class insurance
{
    private:
        date d[100];
        information info[100];
        date current_date;
        date history;
    public:
        void get_information(int n)
        {
           int i;
            for( i=0;i<n;i++)
                {cout<<"pleas enter the name: ";
                cin.ignore();
                getline(cin,info[i].name_insurance);
                cout<<"pleas enter the insurance number: :";
                cin>>info[i].num_insurance;
                cout<<"pleas enter the year of entry: ";
                cin>>d[i].year;
                cout<<"pleas enter the month of entry: ";
                cin>>d[i].month;
                cout<<"pleas enter the day of entry: ";
                cin>>d[i].day;
        }}

        void print(int n)
        {   int i;
            for(i=0;i<n;i++){
                history.day=0;
                history.month=0;
                history.year=0;"\n";
                cout<<"name: "<<info[i].name_insurance<<"\ninsurance number: "<<info[i].num_insurance<<"\n";
                cout<<"insurance date: \nyear: "<<d[i].year<<"\tmonth: "<<d[i].month<<"\tday: "<<d[i].day<<"\n";
                history.day=current_date.day-d[i].day;
                if(history.day<1)
                {
                    history.month--;
                    history.day+=30;
                }
                history.month+=(current_date.month-d[i].month);
                if(history.month<1)
                {
                    history.year--;
                    history.month+=12;
                }
                history.year+=(current_date.year-d[i].year);
                cout<<"insurance history: \nyear: "<<history.year<<"\tmonth: "<<history.month<<"\tday: "<<history.day<<"\n";
                cout<<endl;
            }
        }
        void get_current_date()
        {
            cout<<"pleas enter current date:\nyear: ";
            cin>>current_date.year;
            cout<<"month: ";
            cin>>current_date.month;
            cout<<"day: ";
            cin>>current_date.day;
        }
};
int main()
{
    int n;
    cout<<"pleas enter the number of person: ";
    cin>>n;
    insurance insu;
    insu.get_current_date();
    insu.get_information(n);
    insu.print(n);
    return 0;}