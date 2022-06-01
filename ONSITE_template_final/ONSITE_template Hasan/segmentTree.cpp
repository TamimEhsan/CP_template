///lazy propagation
template<class T>
class SegTree{
    T* sgt;
    ///combine must clear out any unpropagated value
    T (*combine)(T,T);
    T (*propagate)(T to,T from,int);
    int n;
public:
    SegTree(int sz,T(*combine)(T,T),T(*propagate)(T,T,int),T* data=NULL)
    {
        this->combine=combine;
        this->propagate=propagate;
        n=sz;
        sgt=new T[4*sz];
        if(data!=NULL)
            build(1,0,n-1,data);
    }
    void build(int v,int vl,int vr,T* data)
    {
        if(vl==vr)
        {
            sgt[v]=data[vl];
            return;
        }
        int mid=(vl+vr)/2;
        build(2*v,vl,mid,data);
        build(2*v+1,mid+1,vr,data);
        sgt[v]=combine(sgt[2*v],sgt[2*v+1]);
    }
    void update(int v,int vl,int vr,int l,int r,T unp)
    {
        if(vl==l&&vr==r)
        {
            sgt[v]=propagate(sgt[v],unp,r-l+1);
            return;
        }
        int mid=(vl+vr)/2;
        sgt[2*v]=propagate(sgt[2*v],sgt[v],mid-vl+1);
        sgt[2*v+1]=propagate(sgt[2*v+1],sgt[v],vr-mid);
        if(r<=mid)
            update(2*v,vl,mid,l,r,unp);
        else if(l>mid)
            update(2*v+1,mid+1,vr,l,r,unp);
        else
        {
            update(2*v,vl,mid,l,mid,unp);
            update(2*v+1,mid+1,vr,mid+1,r,unp);
        }
        sgt[v]=combine(sgt[2*v],sgt[2*v+1]);
    }
    void update(int l,int r,T unp)
    {
        update(1,0,n-1,l,r,unp);
    }
    T query(int v,int vl,int vr,int l,int r)
    {
        if(vl==l&&vr==r)
        {
            return sgt[v];
        }
        int mid=(vl+vr)/2;
        sgt[2*v]=propagate(sgt[2*v],sgt[v],mid-vl+1);
        sgt[2*v+1]=propagate(sgt[2*v+1],sgt[v],vr-mid);
        sgt[v]=combine(sgt[2*v],sgt[2*v+1]);
        if(r<=mid)
            return query(2*v,vl,mid,l,r);
        else if(l>mid)
            return query(2*v+1,mid+1,vr,l,r);
        else
            return combine(query(2*v,vl,mid,l,mid),query(2*v+1,mid+1,vr,mid+1,r));
    }
    T query(int l,int r)
    {
        return query(1,0,n-1,l,r);
    }
    ~SegTree()
    {
        if(n!=0&&sgt!=NULL)
            delete[] sgt;
    }
};
