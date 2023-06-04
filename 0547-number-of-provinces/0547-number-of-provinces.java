class Solution {
    public int findCircleNum(int[][] arr) {
        List<List<Integer>>adj=new ArrayList<>();
        for(int i=0;i<arr.length;i++)adj.add(new ArrayList<Integer>());
        for(int i=0;i<arr.length;i++)
        {
            for(int j=0;j<arr[i].length;j++)
            {
                if(arr[i][j]==1)
                {
                   adj.get(i).add(j);
                   adj.get(j).add(i);     
                }
             
            }
        }
        boolean vis[]=new boolean[arr.length];
        int ans=0;
        for(int i=0;i<arr.length;i++)
        {
            if(vis[i]==false)
            {
                
                fun(adj,i,vis);
                ans+=1;
            }
        }
        return ans;
    }
    void fun(List<List<Integer>>adj,int src,boolean[]vis)
    {
        vis[src]=true;
        for(int i:adj.get(src))
        {
            if(vis[i]==false)
            {
                fun(adj,i,vis);
            }
        }
    }
}