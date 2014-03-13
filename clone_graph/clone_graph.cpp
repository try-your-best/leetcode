/*
思路：利用图的遍历(BFS)和map容器将整个图映射一遍。
然后在遍历map容器构造各自节点的邻居节点(neighbors);
注意细节。思路方向是对的，可惜编译3次才消除语法错误。
*/

/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    void BFS(UndirectedGraphNode *p_node, map<UndirectedGraphNode*, UndirectedGraphNode*>& map_old_to_new)
    {
        if(p_node == NULL)
            return;
        queue<UndirectedGraphNode*> nodes;
        set<int> labels;
        nodes.push(p_node);
        labels.insert(p_node->label); //保证每个节点只访问一次！
        while(!nodes.empty())
        {
            p_node = nodes.front();
            UndirectedGraphNode* p_new_node = new UndirectedGraphNode(p_node->label);
            map_old_to_new[p_node] = p_new_node; //建立映射！
            nodes.pop();
            int len = p_node->neighbors.size();
            for(int i = 0; i < len; i++)
            {
                if(labels.count((p_node->neighbors)[i]->label) == 0)
                {
                    nodes.push((p_node->neighbors)[i]);
                    labels.insert((p_node->neighbors)[i]->label); //保证每个节点只访问一次！
                }
            }
        }
    }
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(node == NULL)
            return NULL;
        map<UndirectedGraphNode*, UndirectedGraphNode*> map_old_to_new;
        BFS(node, map_old_to_new);
		//遍历map容器的节点。
        for(map<UndirectedGraphNode*, UndirectedGraphNode*>::iterator iter = map_old_to_new.begin(); iter != map_old_to_new.end(); iter++)
        {
            int len = (iter->first)->neighbors.size();
            for(int i = 0; i < len; i++)
            {
                iter->second->neighbors.push_back(map_old_to_new[(iter->first->neighbors)[i]]);
            }
        }
        return map_old_to_new[node];
    }
};
