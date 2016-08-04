class Solution {
public:
    string simplifyPath(string path) {
        vector<string> tmp;
        for(auto i=path.begin(); i!=path.end(); )
        {
             i++;
             auto j=find(i, path.end(), '/');
             string dir = string(i,j);
             if(!dir.empty() && dir!=".")
             {
                   if(dir=="..")
                   {
                   if(!tmp.empty())
                   tmp.pop_back();
                   }
                   else tmp.push_back(dir);
             }
             i = j;
        }
        stringstream out;
        if(tmp.empty())
             out<<"/";
        else{
            for(int i=0; i<tmp.size(); i++)
            out<<'/'<<tmp[i];
        }
        return out.str();
    }
};
