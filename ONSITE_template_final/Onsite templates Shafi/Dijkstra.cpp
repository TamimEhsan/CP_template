int dist[10001],vis[10001];
vector<pii> graph[10001];
void dijkstra(int src,int n){
  priority_queue<pii, vector<pii>, greater<pii>> cur_dist;
  for(int i=1;i<=n;i++)
    dist[i]=inf;
  for(int i=1;i<=n;i++)
    cur_dist.push( make_pair( dist[i], i));
  dist[src]=0;
  cur_dist.push(make_pair(0, src));
  while(!cur_dist.empty()){
     int centr= cur_dist.top().second;
     cur_dist.pop();
     if(vis[centre])
      continue;
    for(auto itr: graph[centre]){
      if(dist[centre]+ itr.second< dist[itr.first]){
        dist[itr.first]= dist[centre]+ itr.second;
        cur_dist.push( make_pair(dist[itr.first], itr.first));}}
    vis[centre]=1;}}
//floyd warshall
ll g[500][500];
void floyedWarshal(int n){
  //g[i][i] should be zero
  for(int k=0;k<n;k++){
  for(int i=0;i<n;i++){
  for(int j=0;j<n;j++){
    if(g[i][k]<LLONG_MAX&&g[k][j]<LLONG_MAX)
      g[i][j]=min(g[i][j], g[i][k]+ g[k][j]);}}}}
//bellmen-ford
int dist[10001];
struct edge{
  int a,b,cost;
};
vector<edge> graph;
void bell_ford(int src,int n){
   for(int i=1;i<=n;i++)
     dist[i]=inf;
   dist[src]=0;
   for(int i=1;i<n;i++){
     for(int j=0;j<graph.size();j++)
       dist[graph[j].b]=min(dist[graph[j].b],dist[graph[j].a]+graph[j].cost);}}
