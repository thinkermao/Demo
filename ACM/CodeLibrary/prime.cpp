bool prime[];
bool primes[];

//
// 一般线性晒法
//
void make_prime()  {      
	memset(prime, 1, sizeof(prime));
	prime[0]=false;     
	prime[1]=false;     
	int N=31700;      
	for (int i=2;  i<N;  i++)         
	  if (prime[i]) {          
		primes[++cnt ]=i;     
		for (int k=i*i; k<N; k+=i)        
			prime[k]=false;       
	  }      
	return;
}   

#include<iostream>
using namespace std;    
const long N = 200000;   
long prime[N] = {0},num_prime = 0;    
int isNotPrime[N] = {1, 1};   
int main()    
{     
    for(long i = 2 ; i < N ; i ++)       
    {            
		if(!isNotPrime[i])               
	 		prime[num_prime++] = i;  
		//关键处1        
		for(long j = 0; j < num_prime && i * prime[j] <  N; j ++)
    	{               
		    isNotPrime[i * prime[j]] = 1;  
	  		if(i % prime[j] == 0)  //关键处2                  
				break;           
		}        
	}        
	return 0;   
}  