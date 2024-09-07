// #include<iostream>
// #include<vector>
// #include<algorithm>
// using namespace std;

// vector<int> plusOne(vector<int>& digits) {
//         int s = 0;
//         vector<int> ans;
//         int n = digits.size();

//         for (int i = 0; i<n ; i++){
//             s = s * 10 + digits[i];
//         }
//         cout<<s<<endl;
//         s = s + 1;
//         cout<<s<<endl;
        
//         while(s > 0){
             
//             int res = s % 10;
//             ans.push_back(res);
//             s = s / 10;
//         }
//         reverse(ans.begin(),ans.end());
       
//         return ans;
//         }


// int main(){
//     vector<int>digits ={9,8,7,6,5,4,3,2,1,0};
    

//      vector<int> res = plusOne(digits);
//  for (int i = 0; i < res.size(); i++)
//     {
//         cout<<res[i]<<" ";
//     }
    
// return 0 ;
// }
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> plusOne(vector<int>& digits) {
    // Initialize carry
    int carry = 1;
    
    // Process digits from the end to the beginning
    for (int i = digits.size() - 1; i >= 0; --i) {
        if (carry == 0) break; // No more carry to process
        
        int sum = digits[i] + carry;
        digits[i] = sum % 10; // Update the digit
        carry = sum / 10; // Update the carry
    }

    // If there is still carry left, we need to add a new digit at the beginning
    if (carry > 0) {
        digits.insert(digits.begin(), carry);
    }

    return digits;
}

int main() {
    vector<int> digits = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};

    // Call the function and get the result
    vector<int> res = plusOne(digits);

    // Print the result
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;

    return 0;
}
