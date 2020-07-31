#include <stdio.h>                                                                        
#include <math.h>
#include <algorithm>
using namespace std;
 
int p,q;
 
void input(){
  printf("소수 2개 입력 ");
  scanf("%d %d", &p, &q);
}
 
int piFunc(){
  return (p-1)*(q-1);
}
 
int gcd(int a, int b){ // 유클리드 gcd alg.
  if(a<b) swap(a,b);
  if(b==0) return a;
  else return gcd(b, a%b);
}
 
int eFunc(int piN){ // pi와 서로소 e선택
  //gcd return 값이 1이면 서로소
  for(int i=2; i<piN; i++){
    if(gcd(piN,i) == 1)
      return i;
  }
  return 0;
}
 
int dFunc(int e, int piN){  //(e*d)mod piN =1 만족하는 d
  for(int i=2; i<piN; i++){
    if((piN+1) == (e * i))
      return i;
  }
  return 0;
}
 
int Encrypt(int M, int e, int N){
  int temp = pow(M,e);
  return temp % N;
}
 
int Decrypt(int C, int d, int N){
  int temp = pow(C,d);
  return temp % N;
}
 
int main(void){
  //소수 입력 p,q, N = p*q
  input();
  int N = p*q;
  //파이(N) = (p-1)*(q-1)
  int piN = piFunc();
  //파이(N)과 서로소 e
  int e = eFunc(piN);
  //(e*d)modN = 1 만족하는 d
  int d = dFunc(e, piN);
 
  printf("공개키(%d. %d) 개인키(%d, %d)\n", N,e, N,d);   
  
  //보낼 메시지                                                                         
  int M;                                                                                
  printf("보낼 메시지 : ");                                                               
  scanf("%d", &M);                                                                       
  printf("---\n");                                                                 
                                                                                                  
  //암호화 C = M의 e제곱 mod N                                                            
  int C = Encrypt(M, e, N);                                                               
  printf("Encrypted Message : %d\n", C);                                                
  printf("---\n");                                                                             
                                                                                       
  //복호화 M = C의 d제곱 mod N                                                            
  int dM = Decrypt(C, d, N);                                                              
  printf("Dencrypted Message : %d\n", dM);                           
                                                                                                               
  return 0;                                                                         
}
 
