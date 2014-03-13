//˼·���������˽���Ŀ2Sum��˼·���ο���ָoffer��Ŀ41����
//Ҫ�����н�������������͵ĸ��Ӷ���O(nlog(n))��
//Ȼ�������ͷ��ʼÿ��ѡ��һԪ�� num[i]��Ȼ����2Sum�� num[i+1...high] ���д����ҵ�������ֵ�����С�ĺ͡�
//2Sum�ĸ��Ӷ���O(n), ����3SumClosest�ĸ��Ӷ���O(n^2)��ע�ⲻ��O(n^2 * logn)����Ϊ������������˳��ġ�
//��Ȼ��2Sum����ܱ�֤�ҵ����ʵĽ⣬Ŀǰȱ���ϸ����ѧ֤��������Ѱ���С�����
//��򵥵�������3��ѭ�������Ӷ�ΪO(n^3)
class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        int len = num.size();
        int sum = 0;
        sort(num.begin(), num.end());
        int closest = 0x7fffffff; //ע�⣬��Ҫ�Ѹòο������ŵ�forѭ���ڣ�
        for(int i = 0; i < len - 2; i++)
        {
            int low = i + 1;
            int high = len - 1;
            int expectation = target - num[i];
            while(low < high)
            {
                int diff = expectation - num[low] - num[high];
                if(abs(closest) > abs(diff))
                {
                    closest = diff;
                    sum = target - diff;
                }
                if(diff == 0)
                {
                    return sum;
                }
                else if(diff > 0)//��ǰ��sum̫С
                {
                    low++;
                }
                else //��ǰ��sum̫��
                {
                    high--;
                }
            }
        }
        return sum;
    }
};
