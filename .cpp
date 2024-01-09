/*
better approach:

Complexity Analysis
Time Complexity: O(N3*log(M)), where N = size of the array, M = no. of elements in the set.
Reason: Here, we are mainly using 3 nested loops, and inside the loops there are some operations on the set data structure which take log(M) time complexity.

Space Complexity: O(2 * no. of the quadruplets)+O(N)
Reason: we are using a set data structure and a list to store the quads. This results in the first term. And the second space is taken by the set data structure we are using to store the array elements. At most, the set can contain approximately all the array elements and so the space complexity is O(N).

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        int n=nums.size();
        set<vector<int>>st;

        for (int i=0;i<n;i++){
            for (int j=i+1;j<n;j++){

                set<long long>hashSet;
                for (int k=j+1;k<n;k++){

                    long long sum = nums[i] + nums[j];
                    sum += nums[k];
                    long long fourth = target - sum;

                    if (hashSet.find(fourth)!=hashSet.end()){
                        vector<int>temp={nums[i],nums[j],nums[k],(int)fourth};
                        sort(temp.begin(),temp.end());
                        st.insert(temp);
                    }
                    hashSet.insert(nums[k]);
                }
            }
        }

        vector<vector<int>>ans(st.begin(),st.end());
        return ans;
    }
};

*/

/*
best approach:

Complexity Analysis
Time Complexity: O(N3), where N = size of the array.
Reason: Each of the pointers i and j, is running for approximately N times. And both the pointers k and l combined can run for approximately N times including the operation of skipping duplicates. So the total time complexity will be O(N3). 

Space Complexity: O(no. of quadruplets), This space is only used to store the answer. We are not using any extra space to solve this problem. So, from that perspective, space complexity can be written as O(1).

*/
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        int n=nums.size();
        vector<vector<int>>ans;

        sort(nums.begin(),nums.end());

        for (int i=0;i<n;i++){

            if (i>0 && nums[i]==nums[i-1]){
                continue;
            }

            for (int j=i+1;j<n;j++){

                if (j>i+1 && nums[j]==nums[j-1]){
                    continue;
                }

                int k=j+1, l=n-1;

                while (k<l){

                    long long sum = nums[i];
                    sum += nums[j];
                    sum += nums[k];
                    sum += nums[l];

                    if (sum==target){
                        vector<int>temp={nums[i],nums[j],nums[k],nums[l]};
                        ans.push_back(temp);

                        k++;
                        l--;

                        while (k<l && nums[k]==nums[k-1]){
                            k++;
                        }
                        while (k<l && nums[l]==nums[l+1]){
                            l--;
                        }
                    }
                    else if (sum<target){
                        k++;
                    }
                    else{
                        l--;
                    }
                }
            }
        }
        return ans;
    }
};
