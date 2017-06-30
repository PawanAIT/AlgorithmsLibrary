//Bitch Please ! :P 
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<
int,
null_type,
less_equal<int>, //less for set less_equal for multiset 
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;
ordered_set X;
int get(int n){
	return *X.find_by_order(n);
}
int main()
{
	int n,temp;
	scanf("%d",&n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d",&temp);
		X.insert(temp);
		printf("%.1f\n",i%2==0 ?get(i/2)*1.0:(get(i/2)+get(i/2+1))/2.0);

	}
	return 0;
}