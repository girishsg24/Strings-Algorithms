#include<iostream>
#include<string>
#include<stdlib.h>
#include<cmath>
using namespace std;

bool isOneEditAway(string s1, string s2)
{
    
	bool oneCh = false;
	/*
	    Firstly I would check if the lengths are same if yes then compare them
	    return instantly since zero edits were required.
	    
	    Next i'd check if the diff in length is greater than 
	    
	*/
	int length = s1.length() - s2.length();
	if ((length==0)&& (s1==s2))return true;
	if(abs(length)>=2)return false;
	/*
	    Check for diff =0 but not same strings.
	    There can only be one exception.
	    so we iterate and compare each char, allow one exception but nothing more than one.
	*/
	if (length == 0)
	{
		for (int i = 0; i < s1.length(); i++)
		{

			if (s1[i] != s2[i])
			{
				if (oneCh)
				{
					
					return false;
				}

				oneCh = true;
			}
		}
	}
	else
	{
	    /*
	        if length diff is 1.
	        We iterate and compare each char but halt the increment of longest string once we hit an exception.
	        Even if the next char fails & becomes the second exception we fail it.
	   */
		string len1, len2;
		if (s1.length() > s2.length())
		{
			len1 = s1;
			len2 = s2;
		}
		else
		{
			len2= s1;
			len1 = s2;
		}
		//j has to stay intact
		for (int i = 0,j=0;j<s2.length();)
		{
			if (len1[i] != len2[j])
			{
				if (oneCh)
				{
					
					return false;
				}
				oneCh = true;
				i++;
			}
			else
			{
				i++;
				j++;
			}
		}
	}
	return true;
}


int main ()
{
    /*
        pale, ple true
        pale, pales true
        pale,bake false
        pale,bale true
    
    */
	string s1 = "pale";
	string s2 = "bale";
    cout<<isOneEditAway(s1,s2);
    
}