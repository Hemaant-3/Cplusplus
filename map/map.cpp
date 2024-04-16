#include<iostream>
#include<unordered_map>
using namespace std;
void counchar(unordered_map<char,int> & mapi, string str){
    for (int i = 0; i < str.length(); i++)
    {
    char ch = str[i];
    mapi[ch]++;
    
    }
    
}
int main()
{
    /*
//creation
unordered_map<string,int> mapping;

//insertion
pair<string,int> p = make_pair("love",25);

pair<string,int> q("hemant",23);

pair<string,int> r;
r.first = "monu";
r.second = 21;

//insertion
mapping.insert(p);
mapping.insert(q);
mapping.insert(r);
mapping["babbr"] = 55;
cout<<mapping.size()<<endl;
//access
cout<<mapping.at("love")<<endl;
cout<<mapping["love"]<<endl;

// searching
cout<<mapping.count("love")<<endl;
if(mapping.find("love")!=mapping.end()){
    cout<<"found"<<endl;
} else{
    cout<<"Not found"<<endl;
}
*/
// only map<string,char> map -> is showing orderd map
string str = "lovebabbar";
unordered_map<char,int> mapi;
counchar(mapi,str);

for(auto i:mapi){
    cout<<i.first<<"->"<<i.second<<endl;
}
return 0;
}