#include<iostream>
#include<string>
using namespace std;

void urlify(string& S)
{
    
    int noSpaces=0, Slength=0;
    //Run a for loop to determine the actual size of the string without the extended provided space
    for(int i=0;i<S.length();i++)
    {
        if(S[i+1]==' '&& S[i+2]==' ')
            break;
        if (S[i]==' ')
        noSpaces++; 
    //To determine the string end positon, use Slength variable    
        Slength++;    
    }
    cout<<noSpaces<<endl;
    //This is the last postion of the urlified string
    int newLength=Slength+2*noSpaces;
    for(int i=newLength,j=Slength;j>=0;j--)
    {
        /*
            we copy the characters for sLength position till 0
            if we encounter a space we add %20 and then move ahead
        */
        
        
        if(S[j]==' ')
        {
            S[i]='0';
            S[i-1]='2';
            S[i-2]='%';
            i=i-3;
        }
        else
        {
            S[i]=S[j];
            i--;
        }
        
    }
}


int main ()
{
    string S="Mr John Smith            "; 
    urlify(S);
    cout<<S<<endl;
   
}

