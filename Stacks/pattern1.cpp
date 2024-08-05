// concept 1
// NGR, NGL, NSR, NSL

#include <iostream>
#include <vector>
#include <stack>
using namespace std;
// BRUTE FORCE LAME

/*
int n;
vector<int> arr;
vector<int> arr1;
int greater;
int main(){
    
    for(int i=0;i<n;i++){   
        for(int j=i+1;j<n;j++){
            if(arr[j]>arr[i]){
                int greater = arr[j];
                arr1.push_back(greater);
                greater =0;
                if(j==n) arr1.push_back(-1);
                break;
            }

            else continue;
        }
    }   
}*/


//ACTUAL METHOD STACK

    //NGR
    // start from the end of the array
    // push elements onto the stack
    // if the stack is empty, push -1 as the greater element
    // if the top element is greater, then push that top element onto the input array
    // if the top element is smaller, keep popping it until you encounter a greater element
    // finally the output array will have all NGE after reversing it

int arr[];
vector<int> v;
stack<int> st;
int n;

int main(){

    // NGR
    for(int i =n-1;i>0;i--){

        if(st.empty()) v.push_back(-1);

        else if(!st.empty() && st.top()>arr[i]){
            v.push_back(st.top());
        }

        else if(!st.empty() && st.top()<=arr[i]){
            while(!st.empty() && st.top()<=arr[i]) st.pop();

            if(st.empty()) v.push_back(-1);
            else v.push_back(st.top());
        }
        
        st.push(arr[i]);
    }

   reverse(v.begin(),v.end());


   //NGL
   // we will start from the start of the array
   //if stack is empty, return -1
   // if the stack's top is not greater than the element, we will move further to the left after popping the top until we 
   // get an element greater than the ith element 
   
   for(int i=0;i<n-1;i++){

        if(st.empty()) v.push_back(-1);

        else if (!st.empty() && st.top() > arr[i]){
            v.push_back(arr[i]);
        }

        else if(!st.empty() && st.top() <= arr[i]){
            while(!st.empty() && st.top() <= arr[i]){
                st.pop();
            }

            if(st.empty()) v.push_back(-1);

            else v.push_back(st.top());
        }

        st.push(arr[i]);
   }
    
}