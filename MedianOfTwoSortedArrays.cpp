class Solution {
public:
	double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
		if (a.size() > b.size())
			return findMedianSortedArrays(b, a);
        
		int low = 0, high = a.size();
		int medianNumber = (a.size() + b.size() + 1) / 2;
		bool odd = (a.size() + b.size()) % 2;
		while (low <= high) {
			int midx = (low + high) / 2;
			int midy = medianNumber - midx;

			int leftx = midx == 0 ? INT_MIN : a[midx - 1];
			int rightx = midx == a.size() ? INT_MAX : a[midx];

			int lefty = midy == 0 ? INT_MIN : b[midy - 1];
			int righty = midy == b.size() ? INT_MAX : b[midy];
			int leftMax = max(leftx, lefty);
			int rightMin = min(rightx, righty);

			if (leftMax <= rightMin) {
				if (odd)
					return leftMax;
				else
					return 1.0 * (leftMax + rightMin) / 2.0;
			}
			if (leftx > righty)
				high = midx - 1;
			else
				low = midx + 1;
		}
		return -1;
	}
};