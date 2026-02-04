class Solution {
public:
    long long maxSumTrionic(vector<int>& nums) {
        // max sum is what we need
        // first find trionic sequences
        // Since we need sum of sequence we cn avoid few elements in first increasing and second increasing but need to take all elements in decreasng sequence.

        int n = nums.size();
        int l = 0, p,q, r;
        long long psum, qsum, rsum, crsum;

        long long ans = LLONG_MIN;

        while (l < n) {
            psum = 0;
            p = l;
            while (p < n-1 && nums[p] < nums[p+1]) {
                psum = max(psum+nums[p], 0LL + nums[p]);
                p++;
            }

            if (p==l || p==n-1) {
                l = p+1;
                continue;
            }

            q = p;
            qsum = 0;
            while (q < n-1 && nums[q] > nums[q+1]) {
                qsum += nums[q];
                q++;
            }

            if (q==p || q==n-1) {
                l = q+1;
                continue;
            }

            r = q;
            rsum = LLONG_MIN;
            crsum = nums[r];
            while (r < n-1 && nums[r] < nums[r+1]) {
                crsum += nums[r+1];
                rsum = max(rsum, crsum); 
                r++;
            }

            if (q==r) {
                l = r+1;
                continue;
            }

            // if (r == q+1) {
            //     rsum += nums[r];
            // } else {
            //     crsum += nums[r];
            //     rsum = max(rsum, crsum);
            // }

            ans = max(ans, psum+qsum+rsum);
            // cout << l << " " << p << " " << q << " " << r << endl;
            // cout << psum << " " << qsum << " " << rsum << endl;
            l = q;
        }
        return ans;
    }
};