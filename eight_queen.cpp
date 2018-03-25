#include <cstdio>

int ans = 0;
int q[9] = {-1};
bool n[9] = {false};
int ld[9];
int rd[9];

bool check(int pos, int depth){
    int i;
    int cld = depth - pos;
    int crd = depth + pos;
    for(i=1; i<depth; i++){
        if(ld[i] == cld || rd[i] == crd)
            return false;
    }
    return true;
}

void dfsqueen(int depth)
{
	int i;
	if (depth == 9)
    {
			ans++;
			return;
	}

	for (i=1; i<9; i++)
	{
	    if(!n[i] && check(i, depth)){
            n[i] = true;
            ld[depth] = depth - i;
            rd[depth] = depth + i;
            q[depth] = i;
            dfsqueen(depth+1);
            n[i] = false;
	    }
	}
    return;
}

int main()
{
    dfsqueen(1);
    printf("%d",ans);
	return 0;
}
