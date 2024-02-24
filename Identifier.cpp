#include <bits/stdc++.h>

using namespace std;

int isValidIdentifier(string str)
{


       if(str[0]=='0' ||str[0]=='1' ||str[0]=='2' || str[0]=='3' ||str[0]=='4' ||str[0]=='5' || str[0]=='6' || str[0]=='7' || str[0]=='8' || str[0]=='9')
       {
            return 0;
       }
       else
       {
        bool flag = 0;
        for(int i=0;i<str.length();i++)
            {
                if(str[i]=='!'||str[i]=='@'||str[i]=='#'||str[i]=='$'||str[i]=='%'||str[i]=='^'||str[i]=='&'||str[i]=='*')
                {
                    flag=1;
                    break;
                }
            }
            if(!flag)
            {
               if(str.length()>1)
               {
                // if(str[0]=='A'||str[0]=='B'||str[0]=='C'||str[0]=='D'||str[0]=='E'||str[0]=='F'||str[0]=='G'||str[0]=='H'||str[0]=='I'||str[0]=='J'||str[0]=='K'||str[0]=='L'||str[0]=='M'||str[0]=='N'||str[0]=='O'||str[0]=='P'||str[0]=='Q'||str[0]=='R'||str[0]=='S'||str[0]=='T'||str[0]=='U'||str[0]=='V'||str[0]=='X'||str[0]=='Y'||str[0]=='Z')
               if(str[0] >= 'A' && str[0] <= 'Z')
               {
                   return 2;
               }
               else
               {
                 return 1;
               }
               }
               else
               {
                return 1;
               }

            }

       }

}

int main() {
    string input_string;
    cout << "Enter a string: ";
    getline(cin, input_string);
    int result = isValidIdentifier(input_string);
    cout<< result<<endl;
        if(isValidIdentifier(input_string)==2)
        {
            cout<<"Camel Case Convention is Prefered.";
        }

    return 0;
}
