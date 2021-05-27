class MyCalendar {
public:


    MyCalendar() 
    {
        root = nullptr;
    }
    
    bool book(int start, int end) 
    {   
		//To avoid last day collision "end" should be decreased by one 
        end--;
		
        if(root)
        {
            Node* current = root;
            while(current)
            {
				//smaller values goes to left
				if(end < current->start)
                {
                    //go to left
                    if(current->left)
                    {
                        current = current->left;
                    }
                    else
                    {
                        current->left = new Node(start, end);
                        return true;
                    }
                }
				//bigger values to the right
                else if(start > current->end)
                {
                    //go to right
                    if(current->right)
                    {
                        current = current->right;
                    }
                    else
                    {
                        current->right = new Node(start, end);
                        return true;
                    }
                }
				//new value is colliding with an existing one
                else
                {
                    return false;
                }
            }
        }
        else
        {
			//first node addition
            root = new Node(start, end);
            return true;
        }
		
		//dead code won't hit but compiler wants it
        return false;
    }
private:
    class Node
    {
    public:
        int start;
        int end;
        Node* left;
        Node* right;
        
        Node(int start, int end)
            : start(start)
            , end(end)
            , left(nullptr)
            , right(nullptr)
        {
        }
    };
    
    Node* root;
};
