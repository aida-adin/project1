#include <iostream>
using namespace std;
void subscription(int[],int,int[],int);
void community(int[],int,int[],int);
void difference(int[],int,int[],int);
void supplement(int[],int,int[],int,int [],int);
void subset(int[],int,int[],int);
int main()
{
 int n,m,i,r;
 int M[r];
 cout<<"menu: \n";
 cout<<"1)subscription\n"<<"2)community\n"<<"3)difference\n"<<"4)supplement\n"<<"5)subset\n";
 cout<<"******************************************\n";
 int t;
cout<<"which item do you choose? ";
cin>>t;
if(t<1||t>5)
{
    cout<<"This item does not exist!";
    return 0;
}
 cout<<"Enter the size of the first set: ";
 cin>>n;
 int a[n];
  cout<<"Elements of the first set:\n";
 for(i=0;i<n;i++)
    cin>>a[i];
 cout<<"Enter the size of the second set: ";
 cin>>m;
 int b[m];
cout<<"Elements of the second set:\n";
 for(i=0;i<m;i++)
    cin>>b[i];
    if(t==4){
        cout<<"Enter the size of the Reference Collection:";
        cin>>r;
        cout<<"Elements of the Reference Collection:\n";
        for(i=0;i<r;i++)
            cin>>M[i];
    }
 switch(t)
 {
     case 1:
         subscription(a,n,b,m);
         break;

     case 2:
        community(a,n,b,m);
        break;

     case 3:
        difference(a,n,b,m);
        break;

     case 4:
       supplement(a,n,b,m,M,r);
       break;

     case 5:
        subset(a,n,b,m);
        break;
 }
return 0;}
void subscription(int a[],int n,int b[],int m){
int p=0,i,j;
int c[n+m];
for(i=0;i<n;i++)
    for(j=0;j<m;j++)
        if(a[i]==b[j])
            {c[p]=a[i];
             p++;
            break;}
if(p==0)
    cout<<"No subscription!";
else
{
    cout<<"subscription:";
    for(i=0;i<p;i++)
        cout<<"\t"<<c[i];
}
   }
void community(int a[],int n,int b[],int m){
int c[n+m];
int z=0,i,j;
for(i=0;i<n;i++){
    c[i]=a[i];
    z++;
}

for(i=0;i<m;i++){
    int f=0;
     for(j=0;j<z;j++)
     if(b[i]==c[j]){
        f=1;
        break;
     }
     if(f==0){
        c[z]=b[i];
        z++;
     }
}
cout<<"community:";
for(i=0;i<z;i++)
    cout<<c[i]<<"\t";
}
void difference(int a[],int n,int b[],int m){
int i,j,f;
cout<<"difference:";
for(i=0;i<n;i++)
{
    f=0;
    for(j=0;j<m;j++)
        if(a[i]==b[j])
    {
        f=1;
        break;
    }
if(f==0)
    cout<<a[i]<<"\t";
}
}

 void supplement(int a[],int n,int b[],int m,int M[],int r){
int i,j,p0=0,p1=0,f1=0,t,p2=0,z=0,p3;
int mot[r];
for(i=0; i<r; i++)
    for(j=0; j<n; j++)
			if(M[i]==a[j])
				p1++;
		if(p1!=n)
            cout<<"the numbers of the first set do not match with the reference set";
		else if(p1==n)
        {
            cout<<"the complement of the first set:\n";
            int mot[r];
            for(i=0;i<r;i++)
            {
                t=0;
                for(j=0;j<n;j++)
                    if(M[i]==a[j])
                    t=1;
                if(t==0)
                   {
                      mot[p0]=M[i];
                      p0++;
                   }
            }
        for(i=0;i<p0;i++)
            cout<<mot[i]<<" ";
        }
        cout<<"\n";
        for(i=0;i<r;i++)
            for(j=0;j<m;j++)
                if(M[i]==b[j])
                    p2++;
            if (p2!=m)
                cout<<"the numbers of the second set do not match with the reference set\n";
                else if(p2==m)
                {
                    cout<<"the complement of the second set:\n";
                    int mot2[r];
                    for(i=0;i<r;i++)
            {
                p3=0;
                for(j=0;j<m;j++)
                    if(M[i]==a[j])
                    p3=1;
                if(p3==0)
                   {
                      mot2[z]=M[i];
                      z++;
                   }
            }
        for(i=0;i<z;i++)
            cout<<mot2[i]<<" ";
        }
                }

void subset(int a[],int n,int b[],int m){
int i,j,p1=0,p2=0;
    for(j=0;j<m;j++)
        for(i=0;i<n;i++)
            if(a[i]==b[j])
                p1++;
    if(p1==n)
        cout<<"the first set is a subset for the second set\n";
    else if(p1==0)
        cout<<"the first set is not a subset for the second set!\n";

    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            if(a[i]==b[j])
               p2++;
    if(p2==m)
        cout<<"the second set is a subset for the first set\n";
    else if(p2==0)
        cout<<"the second set is not a subset for the first set!\n";

}




