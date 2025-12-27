// map::lower_bound/upper_bound
#include <iostream>
#include <map>
using namespace std;

int main ()
{
  std::map<char,int> mymap;
  std::map<char,int>::iterator itlow,itup;

  mymap['a']=20;
  mymap['b']=40;
  mymap['c']=60;
  mymap['d']=80;
  mymap['f']=100;

  itlow=mymap.lower_bound ('e');  // itlow points to b
  auto pp = *itlow;
  cout<<pp.first<<" => "<<pp.second<<endl;
  itup=mymap.upper_bound ('d');   // itup points to e (not d!)


  mymap.erase(itlow,itup);        // erases [itlow,itup)

  // print content:
  for(auto &kv: mymap) {
    cout<<kv.first<<" => "<<kv.second<<endl;
  }

  return 0;
}