class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        unordered_map<char, int> mpp;
        for(int i = 0; i<tasks.size(); i++){
            mpp[tasks[i]]++;
        }
        priority_queue<int> pq;
        for(auto it: mpp){
            pq.push(it.second);
        }
        int time = 0;

        while(!pq.empty()){
            vector<int> temp;
            int cycle = n+1;
            int i = 0;
            while(i<cycle && !pq.empty()){
                i++;
                int cnt = pq.top();
                pq.pop();
                cnt--;
                if(cnt>0) temp.push_back(cnt);
                time++;

            }
            for(auto it: temp){
                pq.push(it);
            }

            if(pq.empty()) break;

            time+= cycle - i;

        }
        return time;
    }
};