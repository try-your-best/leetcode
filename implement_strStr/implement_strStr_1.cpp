#include<iostream>
#include<cstring>
#include<fstream>
using namespace std;

//void ComputePrefix(const char *pattern, int next[]) 
//{
//    const int m = strlen(pattern);
//    next[0] = -1;
//    next[1] = 0;
//    for (int i = 1; i < m; i++) 
//    {
//        for(int j = 0; j < i; j++)
//        {
//            if(strncmp(pattern, pattern+i-j, j+1) == 0)
//            {
//                next[i] = j+1; 
//            }
//        }
//    }
//}


void ComputePrefix(const char *pattern, int prefix_value[]) 
{
    const int pattern_len = strlen(pattern);
    prefix_value[0] = -1;
    prefix_value[1] = 0;
    int cnd = 0;
    int posi = 2;
    while(posi <= pattern_len)
    {
        if(pattern[posi-1] == pattern[cnd])
        {
            cnd = cnd + 1;
            prefix_value[posi] = cnd;
            posi++;
        }
        else if(cnd > 0)
        {
            cnd = prefix_value[cnd];
        }
        else
        {
            prefix_value[posi] = 0;
            posi++;
        }
    }
     
}

int KMP(const char* text, const char* pattern)
{
    int text_len = strlen(text);
    int pattern_len = strlen(pattern);
    int *prefix_value = new int[pattern_len+1]();
    ComputePrefix(pattern, prefix_value);
    int last_prefix_value = 0;
    for(int i = 0; i < text_len; i++)
    {
        int text_index = i+last_prefix_value;
        int j = last_prefix_value;//已匹配的信息不再重新匹配！
        for(; j < pattern_len; j++)
        {
            if(text_index < text_len && text[text_index] == pattern[j])
            {
                text_index++;
            }
            else
            {
                break;
            }
        }
        if(j == pattern_len)
        {
            delete[] prefix_value;
            return i;
        }
        else if(j > 0)
        {
             i += j-prefix_value[j]-1;// 
             last_prefix_value = prefix_value[j];
        }
    }
    delete[] prefix_value;
    return -1;
}
void Print(int A[], int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << A[i] <<" ";
    }
    cout << endl;
}

void Test()
{
//    char* text = "BBC ABCDAB ABCDABCDABDE";
    char* text = "BBC ABCDAB ABCDABCDABDE";
    char* pattern = "ABCDABD";
    int next[8] = {0};
    ComputePrefix(pattern, next);
    Print(next, 8);
    cout << KMP(text, pattern) << endl;
}

void Test1()
{
    char* text = "a";
    char* pattern = "a";
    cout << KMP(text, pattern) << endl;
}

void Test2()
{
    ifstream fin("file.in");
    string text;
    string pattern;
    fin >> text;
    fin >> pattern;
    cout << text.length() << endl;
    cout << pattern.length() << endl;
    cout << KMP(text.c_str(), pattern.c_str()) << endl;
}

int main()
{
    Test1();
    return 0;
}

