#include<iostream>
using namespace std;

bool isSubString(string s1,string s2)
{
    string mainString="";
    string smallerStr="";
    if(s1.length()>s2.length())
    {
        mainString=s1;
        smallerStr=s2;
    }
    else
    {
        mainString=s2;
        smallerStr=s1;
    }
    string temp="";
    for(int i=0;i<mainString.length()-smallerStr.length()+1;i++)
    {
        if(mainString[i]==smallerStr[0])
        {
            temp=mainString.substr(i,smallerStr.length());
            if (temp==smallerStr)
                return true;
        }
    }
    
    return false;
    
    
}


bool isRotation(string s1, string s2)
{
    /*
        concat a string to itself & see if the other string is a substring of the concatenated string
        If yes then its a rotation else no
    */
    
    s1=s1+s1;
    return isSubString(s1,s2);
    
}

int main ()
{
    cout<<isRotation("lewaterbott","waterbottle")<<endl;
    
}