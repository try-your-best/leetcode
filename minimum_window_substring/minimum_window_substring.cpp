/*
˼·���� expect[i] ����ϣ��ȥͳ���ַ���T���ַ�i�ĸ�����Ȼ����
��cur[i]ȥͳ����S�ĵ�ǰ�Ӵ��а���T�е��ַ�i�ĸ�����curSize �����Ӵ�����
T���ַ��ĸ�������� curSize == T.size() ��˵���Ӵ�����T�����е��ַ���
ά��һ�����ڣ����贰�ڵ���ʼ�ͽ�����start��end��end�ȴ������ұ���
���󴰿ڣ�ֱ��curSize == T.size()��Ȼ��������start��С���ڣ��ڴ˹����в��ϼ���
��С�Ӵ���ֱ��curSize < T.size()��Ȼ��ʼ��һ�����󴰿ڣ�
ע�� T�е��ַ����������ظ��ģ��� aab�� S��aabb�������aab��
���Ӷ� O(n)
���Լ��뵽��O(n^2)
�ο���http://huntfor.iteye.com/blog/2083485
*/



class Solution {
public:
    string minWindow(string S, string T) {
        int tSize = T.size();
        vector<int> expect(256);
        for(int i = 0; i < tSize; ++i)
        {
            expect[T[i]]++;
        }
        int curSize = 0;
        int strSize = S.size();
        vector<int> cur(256);
        int lastStart = 0;
        int minStart = 0;
        int minEnd = 0;
        int minLen = INT_MAX;
        for(int i = 0; i < strSize; i++)
        {
            if(expect[S[i]] > 0)
            {
                if(cur[S[i]] < expect[S[i]])
                {
                    ++curSize;
                }
                cur[S[i]]++;
                if(curSize == tSize)
                {
                    int tmpStart = lastStart;
                    while(curSize == tSize)
                    {
                        if(minLen > i-tmpStart+1)
                        {
                            minStart = tmpStart;
                            minEnd = i;
                            minLen = i-tmpStart+1;
                        }
                        if( expect[S[tmpStart]] == 0)
                        {
                            ++tmpStart;
                        }
                        else
                        {
                            --cur[S[tmpStart]];
                            if(cur[S[tmpStart]] < expect[S[tmpStart]])
                            {
                                lastStart = ++tmpStart;
                                curSize--;
                            }
                            else
                            {
                            	++tmpStart;
                            }
                        }
                    }
                }
            }
        }
        if(minLen == INT_MAX)
        {
            return string();
        }
        else
        {
            return S.substr(minStart, minEnd-minStart+1);
        }
    }
};
