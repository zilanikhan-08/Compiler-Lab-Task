#include<bits/stdc++.h>

using namespace std;

 double average(int arr[], int s)
{
   if(s == 0)
   {
       return 0;
   }

   int Sum = 0;
   for(int i=0; i<s; i++)
   {
       Sum += arr[i];
   }

   double result = Sum/s;

   return result;
}

double factorial(int n)
{
    if(n<0)
    {
        cout<<"Wrong Input"<<endl;
        return 0;
    }

    double result = 1;
    for(int i=1; i<=n; i++)
    {
        result*= i;
    }

    return result;
}

int main()
{
    int NumberOfElements;
    int Number;
    double Factorial;
    cout<<"Enter Number of Elements"<<endl;
    cin>>NumberOfElements;
    int testArray[NumberOfElements];
    cout<<"Enter all "<<NumberOfElements<<" Elements"<<endl;
    for(int i=0; i<NumberOfElements; i++)
    {
        cin>>testArray[i];
    }
    cout<<endl;
    double Average =  average(testArray,NumberOfElements);
    cout<<"Average = "<< Average<<endl;




    sort(testArray,testArray+NumberOfElements,greater<int>());
    cout<<"Maximum Value= "<< testArray[0] <<";  Minimum Value= "<<testArray[NumberOfElements-1]<<endl;



    cin>>Number;
    Factorial= factorial(Number);
    cout<< Factorial<<endl;



    int f;
    cout<<"Enter Size of Your First Name:"<<endl;
    cin>> f;
    char FirstName[f];
    cout<<"Enter Your First Name"<<endl;
     for(int i=0; i<f; i++)
    {
        cin>>FirstName[i];
    }
    int l;
    cout<<"Enter Size of Your Last Name:"<<endl;
    cin>> l;
    char LastName[l];
    cout<<"Enter Your Last Name"<<endl;
     for(int i=0; i<l; i++)
    {
        cin>>LastName[i];
    }
    cout << "Full Name is " << FirstName <<" "<<LastName<< endl;

return 0;
}
