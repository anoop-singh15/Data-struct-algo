#include<iostream>
#include<limits.h>

using namespace std;


// Things to learn
// 1> Binary exponentiation
// 2> 32 bit integer facts
// 3> int vs long


// 1> Binary exponentiation

// x^8 = x*x*x*x...
// using binary exponentiation x^8= (x*x)^4
// pow(x,n)=pow(x*x,n/2) (n/2 if n is even)
// for odd x^9 = x*(x)^8 = x*(pow(x*x,(n-1)/2))

// 2> 32 integer facts
//  x^-8  pow(x,n) ->  (n<0)
// pow(1/x,-n)

// 3> int vs long
// int range = -2147483648 to 2147483647 
// now if we use pow(1/x,-n) than INT_MIN will exceed int range in positive direction hence we use long 

double solve(double x,long n)
{
    if(n==0)return 1;

    if(n==1)return x;

    if(n<0)
    {
       return  solve(1/x,-n);
    }

    // odd condition
    if(n&1==1)
    {
        return x * solve(x*x,(n-1)/2);
    } 
    return solve(x*x,n/2);
   
 
}

double myPow(double x,int n)
{
  
    if(n==0)return 1;

    if(n==1)return x;

   return  solve(x,n);

    

}

int main()
{
    int n=10;
    int x=2;
    cout<<myPow(x,n);
    return 0;
}