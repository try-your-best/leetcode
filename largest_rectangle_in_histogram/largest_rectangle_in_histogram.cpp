/*
�����ϵ������
�����ǣ��������߶��������ģ�������ǳ�������ģ����ʱ�����ѹջ��ѹ�����������±꣩��
���ֶԵ�ǰ����ĸ߶ȴ���ջ������ĸ߶ȡ�������ʼ��ջ�������������ֱ����ǰ�����
�߶ȴ���ջ������ĸ߶ȡ����е�����������������кͣ�
���Ӷ� O(n)
http://www.cnblogs.com/lichen782/p/leetcode_Largest_Rectangle_in_Histogram.html
*/

class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        vector<int> tmpHeight(height);
        tmpHeight.push_back(0);
        stack<int> indexs;
        int i = 0; 
        int maxArea = 0;
        while(i < tmpHeight.size())
        {
            if(indexs.empty() || tmpHeight[i] >= tmpHeight[indexs.top()])
            {
                indexs.push(i++);
            }
            else
            {
                int tmp = indexs.top();
                indexs.pop();
                maxArea = max(maxArea, tmpHeight[tmp] * (indexs.empty()? i : i - indexs.top() -1));
            }
        }
        return maxArea;
    }
};
