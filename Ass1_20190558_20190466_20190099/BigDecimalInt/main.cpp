#include <bits/stdc++.h>
#include "BigDecimalInt.h"
using namespace std;

int main()
{
    ///current state of the program
    bool state = 1;
    while(state)
    {
        cout<<"Welcome to FCI Calculator\n";
        cout<<"-------------------------\n";
        cout<<"1 - Perform Addition\n";
        cout<<"2 - Perform Subtraction\n";
        cout<<"3 - Exit\n";
        cout<<">>";
        int choice;cin>>choice;
        string a, b;
        switch(choice)
        {
            case 1:
            case 2:
            {
                cin.ignore();
                cout<<">>";
                getline(cin, a);
                BigDecimalInt first(a);
                cout<<"num1 = "<<first<<endl<<">>";
                getline(cin, b);
                BigDecimalInt second(b);
                cout<<"num2 = "<<second<<endl;
                BigDecimalInt result = (choice == 1) ? first+second:first-second;
                cout<<"num1 "<<((choice == 1) ? '+':'-')<<" num2 = "<<result<<endl;
                break;
            }
            case 3:
                state = 0;
                break;
        }

    }

    return 0;
}
