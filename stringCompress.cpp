#include<iostream>
using namespace std;

string compressString(string s)
{
    int count=0;
    string result="";
    /*
        save the first character in a variable called prev,]
        Increase the count, everytime it appears.
        If the char changes concate the prev char with count in result string & reset the count to 0
        then set the new char into prev & do the same till the end of the string.
    */
    char prev=s[0];
    for(int i=0;i<s.length();i++)
    {
        if (prev!=s[i])
            {
                result=result+prev+to_string(count);
                prev=s[i];
                count=0;
            }
        count++; 
    }
    //Last char and its count
    result=result+prev+to_string(count);
   
    //if compressed string is larger than the original string  we return the original string
    if (s.length()>result.length())
        s=result;
   return s;
    
    
}



int main()
{
    string s="aaaaabbbbbccccd";
    cout<<compressString(s);
    
}