#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
    char s1[100];
    ifstream fin("Task4.txt");
    fin.getline(s1, 100);
    fin.close();

    string s;
    s = string(s1);

    ofstream fout("Task4.txt");
    fout << s << endl;





    string::iterator bg = s.begin(), en = s.end(), it;
    int ind = s.rfind(" ");
    string key = "";
    it = s.end() - 1;
    while (*it != ' ')
    {
        key = *it + key;
        --it;
    }
    
    while (s.find("  ") != string::npos)
    {
        s.erase(s.find("  "), 1);
    }

    if (*(s.end() - 1) == ' ')
    {
        s.erase(s.end() - 1);
    }
    if (*bg == ' ')
    {
        s.erase(bg);
    }
    if (s.find(".") != string::npos) s.erase(s.find("."), 1);
    s.erase(s.rfind(" "), 1);
    cout << endl;
    fout << "Without spaces: " << s << endl;

    

    int len = key.length();
    ind = -1;

    while (s.find(key, ind + 1) != string::npos)
    {
        ind = s.find(key, ind + 1);
        if (ind > 0 && s[ind - 1] == ' ')
        {
            if (ind < len + s.length() && s[ind + len] == ' ')
                s.erase(ind, len);

        }
        else if (ind == 0)
        {
            if (ind < len + s.length() && s[ind + len] == ' ')
                s.erase(ind, len);

        }

    }
    it = s.begin();
    s.erase(s.length() - key.length()-1, key.length()+1);
    fout << "Delete last word : " << s << endl;




    

    it = s.begin();
    while (it != s.end())
    {
        if (*it == ' ')
            s.erase(it - 1);
        else
            ++it;
    }
    if (it == s.end()) (s.erase(it - 1));
    fout << "Delete last Letter: " << s << endl;
    fout.close();
    return 0;
}