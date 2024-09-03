#include<iostream>
#include<string>

using namespace std;

void solution(string &str, int index){
    
    if(index>=str.length()){
        cout<<str<<" ";
        return;
    }
    for(int j = index ;j<str.length();j++)
    {
        swap(str[index],str[j]);
         solution(str,index+1);
        // swap(str[index],str[j]);
    }

}

int main(){
    string str = "raj";
    int index = 0;

    solution(str,index);

    return 0;

}