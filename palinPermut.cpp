#include<iostream>
#include<map>
using namespace std;




bool isPalinPermut(string s)
{
    /*
        Use maps to append all the characters in to the map using the char as key & occurance as value
        increase the count the number of time each char appear.
    */
        
    map<char,char>tab;
    bool oneException=false;
    for(int i=0;i<s.length();i++)
    {
        //convert all the characters to lower case to treat both upper case & lower case as equal
        s[i]=tolower(s[i]);
        //Do not insert the spacee character into map
        if(s[i]!=' ')
        {
            auto it=tab.find(s[i]);
            if (it==tab.end())
                tab[s[i]]=1;
            else
                tab[s[i]]++;
        }
    }
  /*
    iterate through the map and check each key to have the value 2
    there could be one exception for the char which appears right in the middle.\
    if there are more than one exception
    return false
  */
  for(int i=0;i<s.length();i++)
  {
      
      if (oneException && tab[s[i]]%2!=0)
            return false;
      if (tab[s[i]]%2!=0)
        oneException=true;
  }
  return true;
 
    
}

int main ()
{
    string s="Tact Coa";
    
   cout<< isPalinPermut(s);
    
}