Problem Link : https://tinyurl.com/24ed2zy6

Brute Force Approach:

 TC : O(N^2)
  
class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.length();
        int minPenality = INT_MAX;
        int minHour = INT_MAX;

    for(int i=0;i<n;i++){
        // current penality 
    int j=i-1;
    int penality = 0;

    while(j>=0)
    {
        if(customers[j] == 'N'){
            penality++;
        }
        j--;
    }
 j=i;
// shop closed customer comes
    while(j<n)
    {
        if(customers[j] == 'Y'){
            penality++;
        }
        j++;

    }

    if(penality < minPenality){
   minPenality = penality;
   minHour = i;
    }
    }

//try closing at nth hours 
// 0 to n-1 - 'N' then penality
int nthHourPenality = count(begin(customers),end(customers),'N');
if(nthHourPenality < minPenality){
    minPenality = nthHourPenality;
    minHour = n; 
}
return minHour;
    }
};

--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

  Efficient Solution : 
  TC : O(N) 
SC :  O(N) 

class Solution {
public:
    int bestClosingTime(string customers) {
     int n = customers.length();
  vector<int> prefixN(n+1, 0);
        prefixN[0] = 0;
            
        vector<int> suffixY(n+1, 0);
        suffixY[n] = 0;

     for(int i=1;i<=n;i++)
     {
         if(customers[i-1] == 'N'){
             prefixN[i] = prefixN[i-1] + 1;
         }
         else{
           prefixN[i] = prefixN[i-1]; 
         }
     }

// suffix 
for(int i=n-1;i>=0;i--)
{
    if(customers[i] =='Y')
{
    suffixY[i]= suffixY[i+1] + 1;
}
else{
    suffixY[i] = suffixY[i+1];
}
}

int minPenality = INT_MAX;
int minHours = INT_MAX;
for(int i=0;i<=n;i++)
{
  int currentPenality = prefixN[i]+suffixY[i];
  if(currentPenality < minPenality){
      minPenality = currentPenality;
      minHours = i;
  }
}
return minHours;
    }
};
