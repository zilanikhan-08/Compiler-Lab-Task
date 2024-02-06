#include <bits/stdc++.h>

using namespace std;

char Opreator[]= {'+', '-', '*', '/', '='};
char operatorIdentifier(string str)
{
    bool found = false;
    for(int i=0; i<5; i++)
    {
        for(int j=0; j<str.length(); j++)
        {
            if(Opreator[i]==str[j])
            {
                cout<<Opreator[i];

            }
        }

    }

}


int main ()
{
   int n = 5;
   string eqn;
   cout<<"Enter a String of Character"<<endl;
   getline(cin, eqn);
   char result = operatorIdentifier( eqn );
//   if(result==0)
//   {
//       cout<<"no Operator Found"<<endl;
//   }
   cout<<result<<endl;

    return 0;
}
