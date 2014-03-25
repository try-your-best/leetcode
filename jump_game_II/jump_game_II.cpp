/*
˼·��һ��ʼ�뵽������DP�������ʱ�����𰸲�֪��̰�ģ�
��ÿ�ζ�ѡ���ڵ�ǰ��Ծ�����£���һ������Ծ����Զ�ĵ㣡
*/
class Solution {
public:
    int jump(int A[], int n) {
        int step_num = 0;//���ﵱǰ�������õ���С��Ծ������
        int last_reached_distance = 0;//Ŀǰ��Ծ�����£����ܵ���������롣
        int next_max_reached_distance = 0;//��һ����Ծ���ܵ���������롣
        for(int i = 0; i < n; i++)
        {
            if(i > last_reached_distance)
            {
                last_reached_distance = next_max_reached_distance;
                step_num++;
            }
            next_max_reached_distance = max(next_max_reached_distance,i+A[i]);
        }
        return step_num;
    }
};
