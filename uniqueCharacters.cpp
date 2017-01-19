#include<iostream>
#include<string>
#include<vector>
using namespace std;


bool isStringUnique(string s)
{
    /*
        take a vector of size 128 since ascii characters can be of only a max of 127 and min 0f 0
        Alternatively u could have used boolean array of size 128
    */
	vector<int>table(128,0);
	/*
	    We go on setting the value of the index to 1 if the char becomes that index,
	    If it is already 1 then ,we have encountered a duplicate.
	    return the control;
 	
        we could also use a map to implement the same.
	*/
	
	for (int i = 0; i < s.length(); i++)
	{
		if (table[s[i]] == 1)
		{
			return false;
		}
		table[s[i]] = 1;
	}
	return true;
}


int main()
{
	string s = "Samurai";
	//Ternary Operation since I find it cool :P
	isStringUnique(s)?cout<<"The String Contains all unique Characters":cout<<"The String has atleast one duplicate Character!";
}