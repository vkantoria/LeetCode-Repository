class Solution {
 public :
     string multiply( string num1, string num2) {
         string s = "";
         int m = num1.size(), n = num2.size();
         if(num1 == "0" || num2 == "0")
             return "0";
       
        vector <int> res(m + n,0);
         
         for ( int i = m- 1 ; i >= 0 ;  i--) {
             for ( int j = n- 1 ; j >= 0 ; j--) {
                 
                 int mul = (num1[i]- '0' ) * (num2[j]-  '0' );
                 
                 int p1 = i + j;
                 int p2 = i + j + 1 ;
                
                 int sum = mul + res[p2];
                 
                 res[p1] += sum/10;   
                 res[p2] = sum% 10;   
            }
        }
         int i = 0;
         while(res[i] == 0 && i<res.size())
         {
             i++;
             continue;
         }
         while(i<res.size())
         {
            s += res[i] + '0';
             i++;
         }
         return s;

    }
};