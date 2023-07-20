class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> s;
        for(int i=0; i<asteroids.size(); i++){
            if(s.empty() || (s.top()>0 && asteroids[i]>0) || (s.top()<0 && asteroids[i]<0)){
                s.push(asteroids[i]);
            }
            else if(s.top()<0 && asteroids[i]>0) s.push(asteroids[i]);
            else{
                if(abs(s.top()) > abs(asteroids[i])){
                    continue;
                }
                else if(abs(s.top()) == abs(asteroids[i])){
                    s.pop();
                    continue;
                }
                else{
                    while(1){
                        if(s.empty()){
                            s.push(asteroids[i]);
                            break;
                        }
                        if((s.top()>0 && asteroids[i]>0) || (s.top()<0 && asteroids[i]<0)){
                            s.push(asteroids[i]);
                            break;
                        }
                        else if(abs(s.top()) > abs(asteroids[i])){
                            break;
                        }
                        else if(abs(s.top()) == abs(asteroids[i])){
                            s.pop();
                            break;
                        }
                        else s.pop();
                    }
                }
            }
        }
        vector<int> ans;
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};