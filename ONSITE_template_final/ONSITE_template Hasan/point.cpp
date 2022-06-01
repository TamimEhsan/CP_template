template<class T>
class vector2d{
private:
public:
    T x,y;
    vector2d(){x=y=0;}
    vector2d(T x,T y):x(x),y(y){}
    vector2d operator+(T a){
        return {x+a,y+a};
    }
    vector2d operator+(vector2d v){return {x+v.x,y+v.y};}
    vector2d operator-(){return {-x,-y};}
    vector2d operator-(T a){return{x-a,y-a};}
    vector2d operator-(vector2d v){return {x-v.x,y-v.y};}
    vector2d operator*(T a){return {x*a,y*a};}
    vector2d operator*(vector2d v)//complex multiplication
    {return {x*v.x-y*v.y,x*v.y+y*v.x};}
    vector2d& operator*=(vector2d v)//complex multiplication
    {   T tx=x*v.x-y*v.y;
        T ty=x*v.y+y*v.x;
        x=tx;
        y=ty;
        return *this;}
    vector2d& operator+=(vector2d v)
    {   x+=v.x;
        y+=v.y;
        return *this;}
    vector2d& operator-=(vector2d v){
        x-=v.x;
        y-=v.y;
        return *this;}
    vector2d& operator*=(T a){
        x*=a;
        y*=a;
        return *this;}
    vector2d& operator/=(T a){
        x/=a;
        y/=a;
        return *this;}
    T abs(){
        return sqrt(x*x+y*y);}
    T abs2(){
        return x*x+y*y;}
    vector2d operator/(T a){return {x/a,y/a};}
    vector2d operator/(vector2d v)//complex division
    {
        return ((*this)*vector2d(v.x,-v.y))/v.abs2();}
    T dot(vector2d v){
        return x*v.x+y*v.y;}
    vector2d<T> rotate(double angle)//counterclockwise rotation
    {   double cs=cos(angle);
        double sn=sin(angle);
        return {x*cs-y*sn,x*sn+y*cs};}
    vector2d<T> rot90()//counterclockwise 90 degree rotation to work with integer points
    {return {-y,x};}
    T cross(vector2d b)
    {return x*b.y-y*b.x;}
};

//finds transform such that p1->p3,p2->p4
//to find transform of another point r,evaluate a*r+b;
template<class T>
pair<vector2d<T>,vector2d<T> > findLinearTransform
(vector2d<T> p1,vector2d<T> p2,vector2d<T> p3,vector2d<T> p4)
{
    vector2d<T> a=(p3-p4)/(p1-p2);
    vector2d<T> b=p3-a*p1;
    return {a,b};}
template<class T>
T abs(vector2d<T> v)
{
    return sqrt(v.x*v.x+v.y*v.y);}
template<class T>
T angle(vector2d<T> a,vector2d<T> b)
{
    return acos(a.dot(b)/(abs(a)*abs(b)));
}
template <class T>
ostream& operator<<(ostream& stream,const vector2d<T>& v)
{
    stream<<'('<<v.x<<' '<<v.y<<')';
    return stream;
}
template <class T>
istream& operator>>(istream& stream,vector2d<T>& v)
{
    stream>>v.x>>v.y;
    return stream;
}
/********************************************/
