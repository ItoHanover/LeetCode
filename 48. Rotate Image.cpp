class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
    
        int front = 0;
        int rear = n-1;
    
        while(front < rear)
        {
            int range = rear - front;
            for(int i=0 ; i< range; ++i)
            {
                swap(matrix[front][front+i], matrix[front+i][rear]);
                swap(matrix[front][front+i], matrix[rear][rear-i]);
                swap(matrix[front][front+i], matrix[rear-i][front]);
            }
            front++;
            rear--;
        }
    
    }
};