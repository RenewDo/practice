#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

bool lessSame(string ch, string str)
{
	 int ch_l = ch.size();
	 int str_l = str.size();
	 if(ch_l > str_l)
		 return false;
	 else
	 {
		 for(int i=0; i<ch_l; i++)
		 {
			 if(ch[i] != str[i])
				 return false;
		 }
		 return true;
	 }
}

int main()
{
    string line;
	string command[7] = {"reset what",    /*reset*/
		                 "board fault",    /*reset board*/
	                     "where to add",   /*board add*/
	                     "no board at all",/*board delet*/
	                     "impossible",     /*reboot backplane*/
	                     "install first",  /*backplane abort*/
	                     "unkown command"  /*else*/};
	while(getline(cin, line))
	{
		  int flag = 0; 
		  stringstream istream(line);
		  vector<string> word;
		  string s;
		  while(istream>>s)
			    word.push_back(s);
		  if(word.size()>2 || word.empty())
		  {
			  cout<<command[6]<<endl;
			  continue;
		  }
		  if(word[0].at(0)=='r')
		  {
              if(word.size()==1)
			  {
				  if(lessSame(word[0], "reset"))
				  {
					  cout<<command[0]<<endl;
					  continue;
				  }
			  }
			  else 
			  {
				  if(lessSame(word[0], "reset") && (!lessSame(word[0], "reboot")))
				  {
					  if(lessSame(word[1], "board")) //reset board
					  {
						   cout<<command[1]<<endl;
					       continue;
					  }
				  }
				  else if(lessSame(word[0], "reboot") && (!lessSame(word[0], "reset")))
				  {
					  if(lessSame(word[1], "backplane")) //reboot backplane
					  {
						   cout<<command[4]<<endl;
					       continue;
					  }
				  }
				  else if(lessSame(word[0], "reboot") &&lessSame(word[0], "reset"))
				  {
					  if(lessSame(word[1], "board")&& (!lessSame(word[1], "backplane")))
					  {
						   cout<<command[1]<<endl;
					       continue;
					  }
					  else if(lessSame(word[1], "backplane")  &&(!lessSame(word[1], "board")))
					  {
						   cout<<command[4]<<endl;
					       continue;
					  }
				  }
			  }
		  }
		  else if(word[0].at(0)=='b')
		  {
			  if(word.size() == 2)
			  {
				  if(lessSame(word[0], "backplane") &&(!lessSame(word[0], "board")))
				  {
					       cout<<command[5]<<endl;
					       continue;
				  }
				  else if(lessSame(word[0], "board") && (!lessSame(word[0], "backplane")))
				  {
					  if(lessSame(word[1], "delet"))
					  {
						     cout<<command[3]<<endl;
					         continue;
					  }
					  else if(lessSame(word[1], "add"))
					  {
						     cout<<command[2]<<endl;
					         continue;
					  }
				  }
				  else if(lessSame(word[0], "backplane") && lessSame(word[0], "board"))
				  {
					  if(lessSame(word[1], "delet"))
					  {
						     cout<<command[3]<<endl;
					         continue;
					  }
					  else if(word[1].size()>1)
					  {
						  if(lessSame(word[1], "add"))
						  { 
							    cout<<command[2]<<endl;
					            continue;
						  }
						  else if(lessSame(word[1], "abort"))
						  {
							      cout<<command[5]<<endl;
					              continue;
						  }
					  }
				  }
			  }
		  }
		  cout<<command[6]<<endl;
	}
	return 0;
}
