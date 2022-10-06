int dist[10001],vis[10001];
vector<pii> graph[10001];
void dijkstra(int src,int n)
{
     priority_queue<pii,vector<pii>,greater<pii>> cur_dist;
     for(int i=1;i<=n;i++)
         dist[i]=inf;
     for(int i=1;i<=n;i++)
         cur_dist.push(make_pair(dist[i],i));
     dist[src]=0;
     cur_dist.push(make_pair(0,src));
     while(!cur_dist.empty()){
           int centre=cur_dist.top().second;
           cur_dist.pop();
           if(vis[centre])
              continue;
           for(auto itr: graph[centre]){
               if(dist[centre]+itr.second<dist[itr.first]){
                  dist[itr.first]=dist[centre]+itr.second;
                  cur_dist.push(make_pair(dist[itr.first],itr.first));
                 }
           }
           vis[centre]=1;
     }
}
