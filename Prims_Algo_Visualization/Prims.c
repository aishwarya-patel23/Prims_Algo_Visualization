#include <stdio.h>

int main()
{
    int cost[10][10], visited[10] = {0}, min_val, minimum_cost = 0,n;
    int a, b, u, v, i, j, number_of_Edges = 1;
    printf("Enter the number of nodes:\n");
    scanf("%d", &n);
    printf("Enter the cost matrix:\n");
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            scanf("%d",&cost[i][j]);
            if(cost[i][j]==0){
                cost[i][j]=999;
            }
        }
    }
	visited[1]=1;
    while(number_of_Edges<n){
        for(i=1,min_val=999;i<=n;i++){
            for(j=1;j<=n;j++){
                if(cost[i][j]<min_val){
                    if(visited[i]!=0){
                        min_val = cost[i][j];
                        a = u = i;
                        b = v = j;
                    }
                }
            }
        }
        if(visited[u] == 0 || visited[v] == 0){
            printf("\n Edge %d:(%d %d) cost:%d", number_of_Edges++,a,b,min_val);
            minimum_cost+=min_val;
            visited[b]=1;
        }
        cost[a][b] = cost[b][a] = 999;
    }
    printf("\nTotal cost=%d",minimum_cost);
    return 0;
}