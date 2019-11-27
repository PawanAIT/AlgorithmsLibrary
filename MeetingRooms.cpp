class Solution {
public:
	int minMeetingRooms(vector<vector<int>>& intervals) {
		vector<int> in, out;
		for (auto x : intervals) {
			in.push_back(x[0]);
			out.push_back(x[1]);
		}
		sort(in.begin(), in.end());
		sort(out.begin(), out.end());
		int i = 0, j = 0;
		int rooms = 0;
		int minrooms = 0;
		while (i < in.size()) {
			if (in[i] < out[j]) {
				i++;
				rooms++;
			}
			else if (in[i] > out[j]) {
				j++;
				rooms--;
			}
			else
				i++, j++;
			minrooms = max(rooms, minrooms);
		}
		return minrooms;
	}
};