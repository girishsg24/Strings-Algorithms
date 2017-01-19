#include<iostream>
#include<map>
using namespace std;


string merge(string s1,string s2)
{
   string result="";
   int s1Length=s1.length();
   int s2Length=s2.length();
   int i=0, j=0;
   for(;i<s1Length && j<s2Length;)
   {
       if (s1[i]<s2[j])
       {
            result=result+s1[i];
            i++;
            
       }
       else
       {
            result=result+s2[j];
            j++; 
       }
       
   }
   
   if(i<s1Length)
   {
        result=result+s1.substr(i,s1.length()-i); 
   }
   else if(j<s2Length)
   {
        result=result+s2.substr(j,s2.length()-j);   
   }
   
   return result;
    
}


string mergeSort(string s)
{
    if (s.length()<2)
        return s;
        
    string s1=s.substr(0,s.length()/2);
    string s2=s.substr(s.length()/2,s.length());
    s1=mergeSort(s1);
    s2=mergeSort(s2);
   return merge(s1,s2);
}


bool isPermut(string s1, string s2)
{
    /*
        Sort the strings & compare them to be same
    */
    s1=mergeSort(s1);
    s2=mergeSort(s2);
    if(s1==s2)
        return true;
    return false;
    
}


main()
{
   string string1="BATMAN";
   string string2="MANTAB";
   cout<<isPermut(string1,string2);
    
}
