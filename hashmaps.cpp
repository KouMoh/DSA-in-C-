#include<bits/stdc++.h>
using namespace std;

int main() {
    map<string,int> m;

    pair<string,int> p = make_pair("Amul",3);
    m.insert(p);

    pair<string,int> p2= make_pair("Kushal",2);
    m.insert(p2);

    m["Ary"]=1;
    m["Ary"]=2;

    cout<<m["Ary"]<<endl;

    cout<<m.at("Amul")<<endl;

    cout<<m["Tora"]<<endl;
    cout<<m.at("Tora")<<endl;

    cout<<m.size()<<endl;

    cout<<m.count("Amul")<<endl;

    map<string,int> :: iterator it= m.begin();

    while(it!=m.end()){
        cout<<it->first<<" "<<it->second<<endl;
        it++;
    }

    return 0;
}