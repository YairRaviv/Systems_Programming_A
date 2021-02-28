double Power ( double x, int y){
    double sum=1;
    if(y<0)
    {
          y=-y;
	    for(int i=0; i<y; i++)
	    {
		sum*=x;
	    }
    }
    else
    {
	    for(int i=0; i<y; i++)
	    {
		sum*=x;
	    }
    }
    return sum;
}

double Exponent (int x){
    if(x==0)return 1;
    if(x<0)return (1/(Power(2.71828,x)));
    return Power(2.71828, x);
}
