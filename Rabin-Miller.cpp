LL modPow(LL A,LL B,LL C)
{
	LL X=1LL;
	while(B)
	{
		if(B&1)
		{
			X=(X*A)%C;
		}
		A=(A*A)%C;
		B/=2;
	}
	return X%C;
}

bool RabinMiller(LL N,int iterations)
{
	if(N<2)
	return false;
	
	if(N!=2&&N%2==0)
	return false;
	
	LL D=N-1;
	
	while(D%2==0)
	D/=2LL;
	
	for(int i=0;i<iterations;i++)
	{
		LL A=rand()%(N-1)+1;
		LL Temp=D;
		LL X=modPow(A,Temp,N);
		while(Temp!=N-1&&X!=1&&X!=N-1)
		{
			X=(X*X)%N;
			Temp*=2LL;
		}
		
		if(X!=N-1&&Temp%2==0)
		return false;
	}
	return true;
}