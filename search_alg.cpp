#include <iostream>
#include <vector>

using namespace std;

vector<int> patternMatch(string txt, string ptrn);
vector<int> BMarrayMatch(string pattern, int begin, int end);
vector<int> BM(string txt, string ptrn, vector <int> p, int begin);
vector<int> KMParrayMatch(string ptrn);
vector<int> KMP(string ptrn, string txt, vector <int> p);
int main()
{
    int a;
    string txt, ptrn;
    vector<int> wyn;
    string menu = "Menu:\n"
                  "1. Naiwny\n"
                  "2. BM\n"
                  "3. KMP\n"
    ;
    cout<<menu;
    cin>>a;
    cout<<"Text: "<<endl;
    cin>> txt;
    cout<<"Pattern: "<<endl;
    cin>> ptrn;
    switch(a)
    {
        case 1:
            {
                wyn = patternMatch(txt, ptrn);
                for(int i = 0; i < wyn.size(); i++)
                {
                    cout<< wyn[i]<<endl;
                }
            }
        break;
        case 2:
            {
                vector <int> p = BMarrayMatch(ptrn,'a','z' );
                wyn = BM(txt,ptrn, p, 'a');
                for(int i = 0; i < wyn.size(); i++)
                {
                    cout<< wyn[i]<<endl;
                }
            }
        break;
        case 3:
            {
                vector <int> p = KMParrayMatch(ptrn);
                wyn = KMP(ptrn,txt, p);
                for(int i = 0; i < wyn.size(); i++)
                {
                    cout<< wyn[i]<<endl;
                }
            }
        break;

    }
    return 0;
}

vector<int> patternMatch(string txt, string ptrn )
{
    vector<int> result;
    for(int i = 0; i <= txt.length() - ptrn.length(); i++)
    {
        int j = 0;
        for(j = 0; txt[i+j] == ptrn[j] and j <  ptrn.length(); j++)
        {}
        if (j == ptrn.length())
        {
            result.push_back(i);
        }

    }
    return result;
}

vector<int> BMarrayMatch(string pattern, int begin, int end)
{
    vector<int> p;
    for(int i = 0; i <= end - begin; i++ )
    {
        p.push_back(-1);
    }
    for(int i = 0; i < pattern.length(); i++)
    {
        p[pattern[i] - begin] = i;
    }
    return p;
}

vector<int> BM(string txt, string ptrn, vector <int> p, int begin)
{
    vector<int> wyn;
    int i = 0;
    while(i<= txt.length() - ptrn.length())
    {
        int j = ptrn.length() -1;
        for( j; j > -1 and ptrn[j] == txt[j+i]; j--)
        {}
        if(j == -1)
        {
            wyn.push_back(i);
            i++;
        }
        else
        {
            i += max(1, j - p[txt[i+j] - begin]);
        }

    }
    return wyn;

}
vector<int> KMParrayMatch(string ptrn)
{
    vector <int> p;
    p.push_back(0);
    p.push_back(0);
//    p[0]=0;
//    p[1]=0;
    int t = 0;
    int i = 1;
    for(i; i < ptrn.length(); i++)
    {
        while(t > 0 && ptrn[t] != ptrn[i])
        {
            t = p[t];
        }
        if(ptrn[t] == ptrn[i])
            {
                t++;
            }
        p.push_back(t);
    }
    return p;
}
vector<int> KMP(string ptrn, string txt, vector <int> p)
{
    vector<int> wyn;
    int i = 0;
    int j = 0;
    while(i < txt.length() - ptrn.length() + 1)
    {
        while(ptrn[j] == txt[i + j] and j<ptrn.length())
        {
            j++;
        }
        if(j == ptrn.length())
        {
            wyn.push_back(i);
        }
        i+=max(1, j - p[j]);
        j = p[j];
    }
    return wyn;
}
