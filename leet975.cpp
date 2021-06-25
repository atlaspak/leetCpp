enum class TriState
{
    NotCalculated,
    Odd,
    Even,
    Pass,
    Fail
};

struct Node {
    int value;
    int index;
    TriState state;

    Node(int val, int i, TriState st):
     value(val),
     index(i),
     state(st)
     {}

     bool operator<(Node& second)
     {
         return value < second.value;
     }
};

class Solution {
public:
    int oddEvenJumps(vector<int>& arr) 
    {
        list<Node> nodeList;
        for(int i = 0; i < arr.size(); i++)
        {
            nodeList.emplace_back(
                arr[i],
                i,
                TriState::NotCalculated
            );
        }
        
        nodeList.sort();
        
        for(list_iterator<Node>::reverse_iterator rit=nodeList.rbegin(); rit!=nodeList.rend;++rit)
        {
            if(rit->)
        }

        return 0;
    }
};
