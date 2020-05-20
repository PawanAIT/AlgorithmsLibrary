struct node
{
	LL maxel;
	LL pos;
	
	node()
	{
		maxel=0LL;
		pos=0LL;
	}
	
	void merge(node lson,node rson)
	{
		if(rson.maxel>lson.maxel)
		{
			maxel=rson.maxel;
			pos=rson.pos;
		}
		else
		{
			maxel=lson.maxel;
			pos=lson.pos;
		}
	}
	
	void assignLeaf(LL value,LL ps)
	{
		maxel=value;
		pos=ps;
	}
	
	node getVal()
	{
		node res;
		res.maxel=maxel;
		res.pos=pos;
		return res;
	}
};

class SegmentTree
{
	public:
		LL N;
		node *tree;
		
		SegmentTree(LL A[],LL N)
		{
			this->N=N;
			tree=new node[4*getSize(N)+1];
			build(A,1,0,N-1);
		}
		
		node get(LL X,LL Y)
		{
			node result=getValue(1,0,N-1,X,Y);
			return result.getVal();
		}
		
		void build(LL A[],LL s,LL low,LL high)
		{
			//cout<<"node index = "<<s<<" low = "<<low<<" high = "<<high<<endl;
			/*if(low>high)
			{
				return;
			}*/
			if(low==high)
			{
				//cout<<" node index="<<s<<" low="<<low<<" high="<<high<<endl;
				tree[s].assignLeaf(A[low],low);
				//cout<<"terminated"<<endl;
				return;
			}
			LL left=(s<<1);
			LL right=left+1;
			LL mid=(high+low)>>1;

			build(A,left,low,mid);
			build(A,right,mid+1,high);

			tree[s].merge(tree[left],tree[right]);
		}
		
		LL getSize(LL N)
		{
			LL sz=1LL;
			while(sz<N)
			{
				sz<<=1LL;
			}
			return sz;
		}
		
		node getValue(LL s,LL low,LL high,LL L,LL R)
		{
			//cout<<"node index = "<<s<<" low = "<<low<<" high = "<<high<<" L = "<<L<<" R = "<<R<<endl;
			if(high==R&&low==L)
			{
				//cout<<"done"<<endl;
				return tree[s];
			}
			LL left=(s<<1);
			LL right=(s<<1)+1;
			LL mid=(high+low)>>1;

			if(L>mid)
			{
				return getValue(right,mid+1,high,L,R);
			}
			if(R<=mid)
			{
				return getValue(left,low,mid,L,R);
			}

			node lson=getValue(left,low,mid,L,mid);
			node rson=getValue(right,mid+1,high,mid+1,R);
			node result;
			result.merge(lson,rson);
			return result;
		}
};
