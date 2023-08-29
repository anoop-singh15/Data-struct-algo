#include<iostream>
#include<map>
#include<unordered_map>
using namespace std;

int main()
{
    //Create map using library
    unordered_map<string,int>mp;

    // insertion inside map
    // method 1
    pair<string,int>p=make_pair("abc",3);
    mp.insert(p);

    // method 2
    pair<string,int>p2("xyz",4);
    mp.insert(p2);

    // method 3
    mp["abc2"]=5;

    // there is only one insertion for 1 key if m["abc2"]=6 is used again it will overwrite previous
    // 1 time creation 2 time updation -->no duplicate entries
    mp["abc2"]=15;

    // Searching
    cout<<mp["abc2"]<<endl;
    cout<<mp["unknown"]<<endl; //zero  in unknown case  create entry for unknown key

    // to find key
    cout<< mp.at("xyz")<<endl;
    cout<< mp.at("unknown")<<endl; // if used after unknown give 0 without 29 give error

    // size
    cout<<mp.size()<<endl;
    
    // check  entry
    cout<<mp.count("pqr")<<endl; 
    cout<<mp.count("abc2")<<endl; // if key absent 0 ohterwise 1

    // erase function
    mp.erase("abc");
    cout<<mp.size()<<endl;

    // traverse map
    for(auto i:mp)
    {
        cout<< i.first<<" "<<i.second<<endl;
    }

    // iterator 
    unordered_map<string,int> :: iterator it=mp.begin();
    while(it!=mp.end())
    {
        cout<< it->first<<" "<<it->second<<endl;
        it++;
    }
    // collison handling
    // open hashing linked list
    // closed hashing  H(i)=h(i)+f(i)
    // linear addressing f(i)=i
    // quadratic probing f(i)=i^2
    // insertion O(1)
        return 0;
}