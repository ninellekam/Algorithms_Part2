#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <unistd.h>
#include <string>


string longestCommonPrefix(vector<string>& strs) {
        int i,j;
        string prefix = strs[0];

        for(i=0;i<strs.size();i++)
        {
            for(j=0;j<prefix.length();j++)
            {
                if(strs[i][j] != prefix[j])
                {
                    prefix.erase(j);
                }
            }
        }
        return prefix;
}