class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses,
                                     vector<vector<int>>& prerequisites,
                                     vector<vector<int>>& queries) {

        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);

        for (auto &it : prerequisites) {
            adj[it[0]].push_back(it[1]);
            indegree[it[1]]++;
        }

        queue<int> q;

        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }

        // pre[v][u] = true if u is a prerequisite of v
        vector<vector<bool>> pre(numCourses, vector<bool>(numCourses, false));

        while (!q.empty()) {

            int node = q.front();
            q.pop();

            for (auto nxt : adj[node]) {

                // node is a direct prerequisite
                pre[nxt][node] = true;

                // all prerequisites of node become prerequisites of nxt
                for (int i = 0; i < numCourses; i++) {
                    if (pre[node][i])
                        pre[nxt][i] = true;
                }

                indegree[nxt]--;

                if (indegree[nxt] == 0)
                    q.push(nxt);
            }
        }

        vector<bool> ans;

        for (auto &q : queries) {
            ans.push_back(pre[q[1]][q[0]]);
        }

        return ans;
    }
};