#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
bool anagram(string str1, string str2)
{
    if(str1.length()==str2.length())
    {
        sort(str1.begin(), str1.end());
        sort(str2.begin(), str2.end());
        if(str1==str2)
        {
            return true;
        }
    }
    return false;
    
}
int main()
{
    string str1, str2;
    cout<<"enter a string : ";
    cin>>str1;
    cout<<"enter another string : ";
    cin>>str2;
    bool isAnagram = anagram(str1,str2);
    cout<<isAnagram;
}