class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) 
    {
        sort(intervals.begin(),intervals.end());

        int size = intervals.size();

        int prev = 0;
        int remove = 0;

        for(int curr=1;curr<size;curr++)
        {
            // if no overlap
            if(intervals[prev][1]<=intervals[curr][0])
            {
                prev = curr;
                continue;
            }

            // overlap
            remove++;

            // shortest end time
            
            // pick curr;
            if(intervals[prev][1]>intervals[curr][1])
            {
                prev = curr;
            }

            // pick prev
            else
            {
                ;
            }
        }

        return remove;
    }
};