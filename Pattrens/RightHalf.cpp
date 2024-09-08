#include<iostream>

using namespace std;

int main()
{

    int r = 01;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < i+1; j++)
        {
            cout<<r<<" ";
            r++;
        }
        cout<<endl;
        
    }
    

}