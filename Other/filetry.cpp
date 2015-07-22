#include<fstream>
#include<iostream>
using namespace std;
main()
{
  fstream fin("infile.txt",ios::in);
  if(!fin){
    cout<<"File open error!\n";
  }
  char c;
  while((c=fin.get())!=EOF)cout<<c;    //注意结束条件的判断
  fin.close();
}
