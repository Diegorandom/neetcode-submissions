class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(), piles.end());

        int lp = 1, rp = piles.back();                 // CHANGED: speed range, not index range
        while (lp < rp) {                              // CHANGED: standard binary search loop
            int mid = lp + (rp - lp) / 2;              // CHANGED: mid is candidate speed k
            int k = mid;
            long long counter = 0;                     // CHANGED: total hours needed
            bool viable = true;

            for (int i = 0; i < (int)piles.size(); i++) {   // CHANGED: check all piles
                counter += (piles[i] + k - 1) / k;          // CHANGED: integer ceil division
                if (counter > h) {                          // CHANGED: prune early
                    viable = false;
                    break;
                }
            }

            if (viable) {
                rp = mid;                               // CHANGED: try smaller speed
            } else {
                lp = mid + 1;                           // CHANGED: need bigger speed
            }
        }
        return lp;                                      // CHANGED: minimum viable speed
    }
};