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
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(!node)
            return NULL;
        map<int, UndirectedGraphNode*> visit;  //for old
        map<int, UndirectedGraphNode*> create;  //for new
        queue<UndirectedGraphNode*> q;
        q.push(node);
        UndirectedGraphNode* first = new UndirectedGraphNode(node->label);
        visit.insert(pair<int, UndirectedGraphNode*>(node->label, node));
        create.insert(pair<int, UndirectedGraphNode*>(node->label, first));
        while(!q.empty())
        {
            UndirectedGraphNode * cur = q.front();
            q.pop();
            for(int i = 0;i < (cur->neighbors).size();i++)
            {
                if(visit.find((cur->neighbors)[i]->label) == visit.end())
                {
                    UndirectedGraphNode* temp = new UndirectedGraphNode(cur->neighbors[i]->label);
                    create[cur->label]->neighbors.push_back(temp);
                    visit.insert(pair<int, UndirectedGraphNode*>((cur->neighbors)[i]->label, (cur->neighbors)[i]));
                    create.insert(pair<int, UndirectedGraphNode*>(temp->label, temp));
                    q.push((cur->neighbors)[i]);
                }
                else
                {
                    create[cur->label]->neighbors.push_back(create[(cur->neighbors)[i]->label]);
                }
            }
        }
        return first;
    }
};