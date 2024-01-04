//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

string encode(string src);    
 
int main() {
	
	int T;
	cin>>T;
	while(T--)
	{
		string str;
		cin>>str;
		
		cout<<encode(str)<<endl;
	}
	return 0;
}
// } Driver Code Ends


/*You are required to complete this function */

string encode(string src)
{     
  //Your code here 
  string ans = "";
  
  char currCh = src[0];
  int cnt = 1;
  for(int i = 1; i < src.length(); i++){
      if(src[i] == currCh){
          cnt++;
      }
      else{
          ans += currCh + to_string(cnt);
          currCh = src[i];
          cnt = 1;
      }
  }
  ans += currCh + to_string(cnt);
  return ans;
}     
