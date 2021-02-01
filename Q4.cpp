
#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>

using namespace std;
#define MAX_MATCHES 100

static const char alphanum[] = "01";//string kümesi

int stringLength = sizeof(alphanum) - 1;

char genRandom()
{

    return alphanum[rand() % stringLength];
}

//Array to store matched indexes
int FOUND[MAX_MATCHES];
//variable to store last index in FOUND array
static int l = 0;

//Partial match table
void kmp_table(string B, int *T )
{
    int pos = 2;
    int cnd = 0;
    int length = B.length();
 
    T[0] = -1;
    T[1] = 0;
 
 while( pos < length){
        if(B[pos-1] == B[cnd])
        {   T[pos] = cnd + 1;
            cnd++;
            pos++;
        }else if( cnd > 0){
        cnd = T[cnd];
        }else{
            T[pos] = 0;
            pos++;
         }
 }
}

//Search function
void kmp_search(string A, string B)
{
 
    int m = 0; 
    int i = 0;
    int sizeA = A.length();
    int sizeB = B.length();
 
    int *T = new int[sizeof(int) * sizeB];//lps
 
    kmp_table(B, T);
 
 while( (m + i) < sizeA)
 {
  if (B[i] == A[m + i]) 
  {
            if (i == (sizeB - 1))
            {
             //Add the start index of match in the FOUND table
             FOUND[l++] = m;
              }
    
            i++;
}
   else{
            if (T[i] > -1)
            {
                m = m + i - T[i];
                i = T[i];
            }else{
                m = m + 1;
                i = 0;
            }
        }
 }
 
 delete(T);
}

int main()
{
    string A;
    string B;
 

    int n;
    int m;
    
    cout<<"Lütfen A nın boyutunu giriniz:\n";
    cin>>n;
    cout<<"\n";
    cout<<"Lütfen B nin boyutunu giriniz:\n";
    cin>>m;


    srand(time(0));
   
    //Anın boyutu kadar içine random sayı at
    for(unsigned int i = 0; i < n; ++i)
    {
        A += genRandom();

    }
    //B nin boyutu kadar içine random sayı at.
    for(unsigned int i = 0; i < m; ++i)
    {
        B += genRandom();

    }

    cout<<"A= "<<A<<"\n";
    cout<<"B= "<<B<<"\n";

    kmp_search(A,B);
    
     for (int i = 0 ; i < l; i++){
         cout<<"Pattern found at "<< FOUND[i] <<endl    ; 
         
     }
     cout<<l<<" tane eşleşme bulundu!";



    return 0;
}