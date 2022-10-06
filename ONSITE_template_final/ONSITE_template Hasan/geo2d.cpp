typedef double Tf; typedef double Ti;
const Tf PI = acos(-1), EPS = 1e-9;
int dcmp(Tf x) {return abs(x)<EPS? 0 :(x<0?-1:1);}
struct PT {
  Ti x, y;
  PT(Ti x = 0, Ti y = 0) : x(x), y(y) {}
  PT operator + (const PT& u) const
            { return PT(x + u.x, y + u.y); }
  PT operator - (const PT& u)
            const { return PT(x - u.x, y - u.y); }
  PT operator * (const long long u)
            const { return PT(x * u, y * u); }
  PT operator * (const Tf u)
            const { return PT(x * u, y * u); }
  PT operator / (const Tf u) const
            { return PT(x / u, y / u); }
  bool operator == (const PT& u) const
       { return dcmp(x-u.x)==0 && dcmp(y-u.y)==0;}
  bool operator != (const PT& u) const
       { return !(*this == u); }
  bool operator < (const PT& u) const
       { return dcmp(x-u.x) < 0 ||
       (dcmp(x-u.x) == 0 && dcmp(y-u.y) < 0);}
  friend istream &operator >> (istream &is, PT &p)
       { return is >> p.x >> p.y; }
  friend ostream &operator << (ostream &os,
         const PT &p) {return os<<p.x<<" "<<p.y; }
};
Ti dot(PT a, PT b) { return a.x*b.x + a.y*b.y; }
Ti cross(PT a, PT b) { return a.x*b.y - a.y*b.x; }
Tf length(PT a) { return sqrt(dot(a, a)); }
Ti sqLength(PT a) { return dot(a, a); }
Tf distance(PT a, PT b) {return length(a-b);}
Tf angle(PT u) { return atan2(u.y, u.x); }
Tf angleBetween(PT a, PT b) { //in range [-PI, PI]
  Tf ans = angle(b) - angle(a);
  return ans <= -PI ? ans + 2*PI :
                    (ans > PI ? ans - 2*PI : ans);
}
PT rotate(PT a, Tf rad) {
  static_assert(is_same<Tf, Ti>::value);
  return PT(a.x * cos(rad) - a.y * sin(rad),
            a.x * sin(rad) + a.y * cos(rad));
}
// Rotate(a, rad) where cos(rad)=co, sin(rad)=si
PT rotatePrecise(PT a, Tf co, Tf si) {
  static_assert(is_same<Tf, Ti>::value);
  return PT(a.x*co - a.y*si, a.y*co + a.x*si);
}
PT rotate90(PT a) { return PT(-a.y, a.x); }
PT scale(PT a, Tf s) {
  static_assert(is_same<Tf, Ti>::value);
  return a / length(a) * s;
}
PT normal(PT a) {
  static_assert(is_same<Tf, Ti>::value);
  Tf l = length(a); return PT(-a.y / l, a.x / l);
}
// returns 1/0/-1 if c is left/on/right of ab
int orient(PT a, PT b, PT c) {
  return dcmp(cross(b - a, c - a));
}
///sort(v.begin(), v.end(),polarComp(O, dir))
struct polarComp {
  PT O, dir;
  polarComp(PT O = PT(0, 0), PT dir = PT(1, 0))
    : O(O), dir(dir) {}
  bool half(PT p) {
    return dcmp(cross(dir, p)) < 0 ||
    (dcmp(cross(dir, p))==0&&dcmp(dot(dir, p))>0);
  }
  bool operator()(PT p, PT q) {
    return make_tuple(half(p-O), 0) <
           make_tuple(half(q-O), cross(p-O, q-O));
  }
};
struct Segment {
  PT a, b;
  Segment() {}
  Segment(PT aa, PT bb) : a(aa), b(bb) {}
}; typedef Segment Line;
struct Circle {
  PT o; Tf r;
  Circle(PT o = PT(0, 0), Tf r = 0) : o(o),r(r) {}
  bool contains(PT p) {
    return dcmp(sqLength(p - o) - r * r) <= 0; }
  PT point(Tf rad) {
    static_assert(is_same<Tf, Ti>::value);
    return PT(o.x+cos(rad)*r, o.y+sin(rad)*r);
  }
  Tf area(Tf rad = PI + PI) { return rad * r *r/2;}
  Tf sector(Tf alpha) {
      return r*r*0.5*(alpha-sin(alpha)); }
};
##################################################
namespace Linear {
bool onSegment(PT p, Segment s) { ///Is p on S?
  return dcmp(cross(s.a - p, s.b - p)) == 0 &&
         dcmp(dot(s.a - p, s.b - p)) <= 0;
}
bool segmentsIntersect(Segment p, Segment q) {
  if(onSegment(p.a,q)||onSegment(p.b,q))return 1;
  if(onSegment(q.a,p)||onSegment(q.b,p))return 1;
  Ti c1 = cross(p.b - p.a, q.a - p.a);
  Ti c2 = cross(p.b - p.a, q.b - p.a);
  Ti c3 = cross(q.b - q.a, p.a - q.a);
  Ti c4 = cross(q.b - q.a, p.b - q.a);
  return dcmp(c1)*dcmp(c2)<0&&dcmp(c3)*dcmp(c4)<0;
}
bool linesParallel(Line p, Line q) {
  return dcmp(cross(p.b - p.a, q.b - q.a)) == 0;
}
//returns if lines (p, p+v) && (q, q+ w) intersect
bool lineLineIntersect(PT p,PT v,PT q,PT w,PT&o) {
  static_assert(is_same<Tf, Ti>::value);
  if(dcmp(cross(v, w)) == 0) return false;
  PT u = p - q; o = p + v*(cross(w,u)/cross(v,w));
  return true;
}
bool lineLineIntersect(Line p, Line q, PT& o) {
  return lineLineIntersect(p.a, p.b - p.a, q.a,
                                    q.b - q.a, o);
}
Tf distancePointLine(PT p, Line l) {
return abs(cross(l.b-l.a, p-l.a)/length(l.b-l.a));
}
Tf distancePointSegment(PT p, Segment s) {
  if(s.a == s.b) return length(p - s.a);
  PT v1 = s.b - s.a, v2 = p - s.a, v3 = p - s.b;
  if(dcmp(dot(v1, v2)) < 0)     return length(v2);
  else if(dcmp(dot(v1, v3))>0)  return length(v3);
  else return abs(cross(v1, v2) / length(v1));
}
Tf distanceSegmentSegment(Segment p, Segment q) {
  if(segmentsIntersect(p, q)) return 0;
  Tf ans = distancePointSegment(p.a, q);
  ans = min(ans, distancePointSegment(p.b, q));
  ans = min(ans, distancePointSegment(q.a, p));
  ans = min(ans, distancePointSegment(q.b, p));
  return ans;
}
PT projectPointLine(PT p, Line l) {
  static_assert(is_same<Tf, Ti>::value);
  PT v = l.b - l.a;
  return l.a + v * ((Tf) dot(v, p-l.a)/dot(v, v));
} }  // namespace Linear
##################################################
typedef vector<PT> Polygon;
namespace Polygonal {
/// cannot be all collinear
Polygon RemoveCollinear(const Polygon& poly) {
  Polygon ret;
  int n = poly.size();
  for(int i = 0; i < n; i++) {
    PT a = poly[i];
    PT b = poly[(i + 1) % n];
    PT c = poly[(i + 2) % n];
    if(dcmp(cross(b-a, c-b))!=0 && (ret.empty() ||
        b != ret.back()))       ret.push_back(b);
  }
  return ret;
}
Tf signedPolygonArea(const Polygon &p) {
  Tf ret = 0;
  for(int i = 0; i < (int) p.size() - 1; i++)
    ret += cross(p[i]-p[0],  p[i+1]-p[0]);
  return ret / 2;
}
///fails if all collinear and remove = TRUE
Polygon convexHull(Polygon p, bool remRedundant) {
  int check = remRedundant ? 0 : -1;
  sort(p.begin(), p.end());
  p.erase(unique(p.begin(), p.end()), p.end());
  int n = p.size(); Polygon ch(n+n);
  int m = 0;    // preparing lower hull
  for(int i = 0; i < n; i++) {
    while(m > 1 && dcmp(cross(ch[m - 1]-ch[m - 2],
                 p[i] - ch[m - 1])) <= check) m--;
    ch[m++] = p[i];
  }
  int k = m;    // preparing upper hull
  for(int i = n - 2; i >= 0; i--) {
    while(m > k && dcmp(cross(ch[m - 1] - ch[m-2],
                 p[i] - ch[m - 2])) <= check) m--;
    ch[m++] = p[i];
  }
  if(n > 1) m--; ch.resize(m);
  return ch;
}
// returns inside = -1, on = 0, outside = 1
int pointInPolygon(const Polygon &p, PT o) {
  using Linear::onSegment; int wn=0, n = p.size();
  for(int i = 0; i < n; i++) {
    int j = (i + 1) % n; if(onSegment(o,
      Segment(p[i], p[j])) || o == p[i]) return 0;
    int k = dcmp(cross(p[j] - p[i], o - p[i]));
    int d1=dcmp(p[i].y-o.y), d2=dcmp(p[j].y-o.y);
    if(k > 0 && d1 <= 0 && d2 > 0) wn++;
    if(k < 0 && d2 <= 0 && d1 > 0) wn--;
  }
  return wn ? -1 : 1;
}
// returns (longest segment, total length)
pair<Tf, Tf> linePolygonIntersection(Line l,
                              const Polygon &p) {
  using Linear::lineLineIntersect;
  int n = p.size(); vector<pair<Tf, int>> ev;
  for(int i=0; i<n; ++i) {
    PT a = p[i], b = p[(i+1)%n], z = p[(i-1+n)%n];
    int ora=orient(l.a,l.b,a), orb =
        orient(l.a,l.b,b), orz=orient(l.a,l.b,z);
    if(!ora) {
      Tf d = dot(a - l.a, l.b - l.a);
      if(orz && orb) {
        if(orz != orb) ev.emplace_back(d, 0);
        //else  // PT Touch
      } else if(orz) ev.emplace_back(d, orz);
        else if(orb) ev.emplace_back(d, orb);
    }
    else if(ora == -orb) {
      PT ins;
      lineLineIntersect(l, Line(a, b), ins);
      ev.emplace_back(dot(ins-l.a, l.b-l.a),0);
    }
  }
  sort(ev.begin(), ev.end());
  Tf ans = 0, len = 0, last = 0, tot = 0;
  bool active = false; int sign = 0;
  for(auto &qq : ev) {
    int tp = qq.second;
    Tf d = qq.first;  ///current Seg is (last, d)
    if(sign) {      ///On Border
      len+=d-last; tot+=d-last; ans=max(ans,len);
      if(tp != sign) active = !active;
      sign = 0;
    }
    else {
      if(active) {  ///Strictly Inside
        len+=d-last;tot+=d-last;ans=max(ans,len);
      }
      if(tp == 0) active=!active; else sign = tp;
    }
    last = d;   if(!active) len = 0;
  }
  ans /= length(l.b-l.a); tot /= length(l.b-l.a);
  return {ans, tot};
} }  // namespace Polygonal
##################################################
namespace Convex {
Polygon minkowskiSum(Polygon A, Polygon B){
  int n = A.size(), m = B.size();
  rotate(A.begin(),
        min_element(A.begin(), A.end()), A.end());
  rotate(B.begin(),
        min_element(B.begin(), B.end()), B.end());
  A.push_back(A[0]); B.push_back(B[0]);
  for(int i = 0; i < n; i++) A[i] = A[i+1] - A[i];
  for(int i = 0; i < m; i++) B[i] = B[i+1] - B[i];
  Polygon C(n+m+1); C[0] = A.back() + B.back();
  merge(A.begin(), A.end()-1, B.begin(),B.end()-1,
     C.begin()+1, polarComp(PT(0, 0), PT(0, -1)));
  for(int i=1; i<C.size(); i++) C[i]=C[i]+C[i-1];
  C.pop_back(); return C;
}
//{min area, min perimeter) rectangle containing p
pair<Tf,Tf>rotatingCalipersBBox(const Polygon &p){
  using Linear::distancePointLine;
  static_assert(is_same<Tf, Ti>::value);
  int n = p.size(); int l = 1, r = 1, j = 1;
  Tf area = 1e100; Tf perimeter = 1e100;
  for(int i = 0; i < n; i++) {
   PT v=(p[(i+1)%n]-p[i])/length(p[(i+1)%n]-p[i]);
    while(dcmp(dot(v, p[r%n] - p[i]) -
              dot(v, p[(r+1)%n] - p[i])) < 0) r++;
    while(j < r || dcmp(cross(v, p[j%n] - p[i]) -
            cross(v, p[(j+1)%n] - p[i])) < 0) j++;
    while(l < j || dcmp(dot(v, p[l%n] - p[i]) -
              dot(v, p[(l+1)%n] - p[i])) > 0) l++;
    Tf w = dot(v,p[r%n]-p[i])-dot(v,p[l%n]-p[i]);
    Tf h = distancePointLine(p[j%n],
                          Line(p[i], p[(i+1)%n]));
    area = min(area, w * h);
    perimeter = min(perimeter, 2 * w + 2 * h);
  } return make_pair(area, perimeter);
}
// returns the left half of u on left on ray ab
Polygon cutPolygon(Polygon u, PT a, PT b) {
  using Linear::lineLineIntersect;
  using Linear::onSegment;
  Polygon ret; int n = u.size();
  for(int i = 0; i < n; i++) {
    PT c = u[i], d = u[(i + 1) % n];
    if(dcmp(cross(b-a, c-a))>=0) ret.push_back(c);
    if(dcmp(cross(b-a, d-c)) != 0) {
      PT t; lineLineIntersect(a, b-a, c, d-c, t);
    if(onSegment(t,Segment(c,d)))ret.push_back(t);
    }
  } return ret;
}
bool pointInTriangle(PT a, PT b, PT c, PT p) {
  return dcmp(cross(b - a, p - a)) >= 0
    && dcmp(cross(c - b, p - b)) >= 0
    && dcmp(cross(a - c, p - c)) >= 0;
}
int pointInConvexPolygon(const Polygon &pt, PT p){
  int n = pt.size(); assert(n >= 3);
  int lo = 1, hi = n - 1;
  while(hi - lo > 1) {
    int mid = (lo + hi) / 2;
    if(dcmp(cross(pt[mid]-pt[0], p - pt[0])) > 0)
        lo = mid;
    else  hi = mid;
  }
  bool in=pointInTriangle(pt[0],pt[lo],pt[hi],p);
  if(!in) return 1;
  if(dcmp(cross(pt[lo]-pt[lo-1],p-pt[lo-1]))==0)
    return 0; if(dcmp(cross(pt[hi]-pt[lo],
    p-pt[lo]))==0) return 0; if(dcmp(cross(pt[hi]-
    pt[(hi+1)%n], p-pt[(hi+1)%n]))==0) return 0;
  return -1;
}
// most extreme Point in the direction u
int extremePoint(const Polygon &poly, PT u) {
  int n = (int) poly.size();
  int a = 0, b = n;
  while(b - a > 1) {
    int c = (a + b) / 2;
    if(dcmp(dot(poly[c]-poly[(c+1)%n], u))>=0 &&
       dcmp(dot(poly[c]-poly[(c-1+n)%n], u))>=0) {
      return c; }

  bool a_up=dcmp(dot(poly[(a+1)%n]-poly[a],u))>=0;
  bool c_up=dcmp(dot(poly[(c+1)%n]-poly[c],u))>=0;
    bool a_above_c=dcmp(dot(poly[a]-poly[c],u))>0;

    if(a_up && !c_up) b = c;
    else if(!a_up && c_up) a = c;
    else if(a_up && c_up) {
      if(a_above_c) b = c; else a = c;
    } else {
      if(!a_above_c) b = c; else a = c;
    }
  }
  if(dcmp(dot(poly[a]-poly[(a+1)%n],u))>0 &&
     dcmp(dot(poly[a]-poly[(a-1+n)%n],u))>0)
    return a;
  return b % n;
}
// return list of segs of p that touch/intersect l
// the i'th segment is (p[i], p[(i + 1)%|p|])
// #1 If a side is collinear, only that returned
// #2 If l goes through p[i], ith segment is added
vector<int> lineConvexPolyIntersection(
                       const Polygon &p, Line l) {
  assert((int) p.size() >= 3); assert(l.a != l.b);
  int n = p.size(); vector<int> ret;
  PT v = l.b - l.a;
  int lf = extremePoint(p, rotate90(v));
  int rt = extremePoint(p, rotate90(v) * Ti(-1));
  int olf = orient(l.a, l.b, p[lf]);
  int ort = orient(l.a, l.b, p[rt]);
  if(!olf || !ort) {
    int idx = (!olf ? lf : rt);
    if(orient(l.a, l.b, p[(idx - 1 + n) % n])==0)
      ret.push_back((idx - 1 + n) % n);
    else  ret.push_back(idx);
    return ret;
  }
  if(olf == ort) return ret;
  for(int i=0; i<2; ++i) {
    int lo = i ? rt : lf, hi = i ? lf : rt;
    int olo = i ? ort : olf;
    while(true) {
      int gap = (hi - lo + n) % n;
      if(gap < 2) break;
      int mid = (lo + gap / 2) % n;
      int omid = orient(l.a, l.b, p[mid]);
      if(!omid) {lo = mid;break;}
      if(omid == olo) lo = mid;
      else hi = mid;
    } ret.push_back(lo);
  } return ret;
}
// [ACW, CW] tangent pair from an external point
constexpr int CW = -1, ACW = 1;
bool isGood(PT u, PT v, PT Q, int dir) {
    return orient(Q, u, v) != -dir; }
PT better(PT u, PT v, PT Q, int dir) {
    return orient(Q, u, v) == dir ? u : v; }
PT pointPolyTangent(const Polygon &pt, PT Q,
                        int dir, int lo, int hi) {
  while(hi - lo > 1) {
    int mid = (lo + hi) / 2;
    bool pvs = isGood(pt[mid], pt[mid-1], Q, dir);
    bool nxt = isGood(pt[mid], pt[mid+1], Q, dir);
    if(pvs && nxt) return pt[mid];
    if(!(pvs || nxt)) {
      PT p1 = pointPolyTangent(pt,Q,dir,mid+1,hi);
      PT p2 = pointPolyTangent(pt,Q,dir,lo,mid-1);
      return better(p1, p2, Q, dir);
    }
    if(!pvs) {
      if(orient(Q,pt[mid],pt[lo])==dir) hi=mid-1;
      else if(better(pt[lo],pt[hi],Q,dir)==pt[lo])
        hi = mid - 1;       else  lo = mid + 1;
    }
    if(!nxt) {
      if(orient(Q,pt[mid],pt[lo])==dir) lo=mid+1;
      else if(better(pt[lo],pt[hi],Q,dir)==pt[lo])
        hi = mid - 1;   else  lo = mid + 1;
    }
  }
  PT ret = pt[lo];
  for(int i = lo + 1; i <= hi; i++)
    ret = better(ret, pt[i], Q, dir);
  return ret;
}
// [ACW, CW] Tangent
pair<PT,PT> pointPolyTangents(
                         const Polygon &pt,PT Q) {
  int n = pt.size();
  PT acw_tan = pointPolyTangent(pt, Q, ACW,0,n-1);
  PT cw_tan = pointPolyTangent(pt, Q, CW, 0, n-1);
  return make_pair(acw_tan, cw_tan);
} }
##################################################
namespace Circular {
// returns intersections in order of ray (l.a,l.b)
vector<PT>circleLineIntersection(Circle c,Line l){
  static_assert(is_same<Tf, Ti>::value);
  vector<PT> ret;
  PT b = l.b - l.a, a = l.a - c.o;
  Tf A = dot(b, b), B = dot(a, b);
  Tf C = dot(a, a) - c.r * c.r, D = B*B - A*C;
  if (D < -EPS) return ret;
  ret.push_back(l.a + b * (-B-sqrt(D + EPS)) / A);
  if (D > EPS)
    ret.push_back(l.a + b * (-B + sqrt(D)) / A);
  return ret;
}
// circle(c.o, c.r) x triangle(c.o,s.a,s.b) (ccw)
Tf circleTriInterArea(Circle c, Segment s){
  using Linear::distancePointSegment;
  Tf OA = length(c.o-s.a), OB = length(c.o-s.b);
  if(dcmp(distancePointSegment(c.o, s) - c.r) >= 0)
    return angleBetween(s.a-c.o,s.b-c.o)*c.r*c.r/2;
  if(dcmp(OA - c.r) <= 0 && dcmp(OB - c.r) <= 0)
    return cross(c.o - s.b, s.a - s.b) / 2.0;
  vector<PT> Sect = circleLineIntersection(c, s);
  return circleTriInterArea(c,Segment(s.a,Sect[0]))
    +circleTriInterArea(c,Segment(Sect[0],Sect[1]))
    + circleTriInterArea(c,Segment(Sect[1],s.b));
}
Tf circlePolyIntersectionArea(Circle c, Polygon p){
  Tf res = 0;
  int n = p.size();
  for(int i = 0; i < n; ++i)
    res +=circleTriInterArea(c,
                   Segment(p[i], p[(i + 1) % n]));
  return abs(res);
}
// locates circle c2 relative to c1: intersect = 0
// inside = -2, inside touch = -1,
// outside touch = 1, outside = 2
int circleCirclePosition(Circle c1, Circle c2) {
  Tf d = length(c1.o - c2.o);
  int in = dcmp(d - abs(c1.r - c2.r)),
      ex = dcmp(d - (c1.r + c2.r));
  return in<0?-2:in==0?-1: ex==0?1: ex>0?2:0;
}
vector<PT> circleCircleInter(Circle c1, Circle c2){
  static_assert(is_same<Tf, Ti>::value);
  vector<PT> ret;
  Tf d = length(c1.o - c2.o);
  if(dcmp(d) == 0) return ret;
  if(dcmp(c1.r + c2.r - d) < 0) return ret;
  if(dcmp(abs(c1.r - c2.r) - d) > 0) return ret;
  PT v = c2.o - c1.o;
  Tf co = (c1.r * c1.r + sqLength(v) - c2.r*c2.r)
                        / (2 * c1.r * length(v));
  Tf si = sqrt(abs(1.0 - co * co));
  PT p1 = scale(rotatePrecise(v,co,-si),c1.r)+c1.o;
  PT p2 = scale(rotatePrecise(v,co,si),c1.r)+c1.o;
  ret.push_back(p1);
  if(p1 != p2) ret.push_back(p2); return ret;
}
Tf circleCircleInterArea(Circle c1, Circle c2) {
  PT AB = c2.o - c1.o; Tf d = length(AB);
  if(d >= c1.r + c2.r) return 0;
  if(d + c1.r <= c2.r) return PI * c1.r * c1.r;
  if(d + c2.r <= c1.r) return PI * c2.r * c2.r;
  Tf alpha1 = acos((c1.r*c1.r + d*d - c2.r*c2.r)
                   / (2.0 * c1.r * d));
  Tf alpha2 = acos((c2.r*c2.r + d*d - c1.r*c1.r)
                   / (2.0 * c2.r * d));
  return c1.sector(2*alpha1)+c2.sector(2*alpha2);
}
// returns tangents from a point p to circle c
vector<PT> pointCircleTangents(PT p, Circle c) {
  static_assert(is_same<Tf, Ti>::value);
  vector<PT> ret;PT u = c.o - p; Tf d = length(u);
  if(d < c.r) ;
  else if(dcmp(d - c.r) == 0) {
    ret = { rotate(u, PI / 2) }; }
  else {
    Tf ang = asin(c.r / d);
    ret = { rotate(u, -ang), rotate(u, ang) };
  } return ret;
}
//returns points on tangents that touches circle c
vector<PT>pointCircleTangencyPoints(PT p,Circle c){
  static_assert(is_same<Tf, Ti>::value);
  PT u = p - c.o; Tf d = length(u);
  if(d < c.r) return {};
  else if(dcmp(d - c.r) == 0)   return {c.o + u};
  else {
    Tf ang = acos(c.r / d); u = u/length(u) * c.r;
    return{c.o+rotate(u,-ang), c.o+rotate(u,ang)};
  }
}
// finds a, b st a[i] on c1, b[i] on c2, Segment
// a[i], b[i] touches c1, c2. if c1, c2 touch at x
// (x, x) is also returned, -1 returned if c1 = c2
int circleCircleTangencyPoints(Circle c1,Circle c2,
                    vector<PT> &a, vector<PT> &b) {
  a.clear(), b.clear(); int cnt = 0;
  if(dcmp(c1.r-c2.r)<0) {swap(c1, c2);swap(a, b);}
  Tf d2 = sqLength(c1.o - c2.o);
  Tf rdif = c1.r - c2.r, rsum = c1.r + c2.r;
  if(dcmp(d2 - rdif * rdif) < 0) return 0;
  if(dcmp(d2)==0 && dcmp(c1.r-c2.r)==0) return -1;
  Tf base = angle(c2.o - c1.o);
  if(dcmp(d2 - rdif * rdif) == 0) {
    a.push_back(c1.point(base));
    b.push_back(c2.point(base));
    cnt++; return cnt;
  }
  Tf ang = acos((c1.r - c2.r) / sqrt(d2));
  a.push_back(c1.point(base + ang));
  b.push_back(c2.point(base + ang)); cnt++;
  a.push_back(c1.point(base - ang));
  b.push_back(c2.point(base - ang)); cnt++;
  if(dcmp(d2 - rsum * rsum) == 0) {
    a.push_back(c1.point(base));
    b.push_back(c2.point(PI + base)); cnt++;
  }
  else if(dcmp(d2 - rsum * rsum) > 0) {
    Tf ang = acos((c1.r + c2.r) / sqrt(d2));
    a.push_back(c1.point(base + ang));
    b.push_back(c2.point(PI + base + ang)); cnt++;
    a.push_back(c1.point(base - ang));
    b.push_back(c2.point(PI + base - ang)); cnt++;
  } return cnt;
} }  // namespace Circular
##################################################
namespace EnclosingCircle{
// returns false if points are collinear
bool inCircle(PT a, PT b, PT c, Circle &p) {
  using Linear::distancePointLine;
  static_assert(is_same<Tf, Ti>::value);
  if(orient(a, b, c) == 0) return false;
  Tf u=length(b-c), v=length(c-a), w=length(a-b);
  p.o = (a * u + b * v + c * w) / (u + v + w);
  p.r = distancePointLine(p.o, Line(a, b));
  return true;
}
// set of points A(x, y) st PA : QA = rp : rq
Circle apolloniusCircle(PT P, PT Q, Tf rp, Tf rq){
  static_assert(is_same<Tf, Ti>::value);
  rq *= rq; rp *= rp; Tf a=rq-rp; assert(dcmp(a));
  Tf g = (rq*P.x-rp*Q.x)/a, h = (rq*P.y-rp*Q.y)/a;
  Tf c = (rq*P.x*P.x - rp*Q.x*Q.x +
          rq*P.y*P.y - rp*Q.y*Q.y)/a;
  PT o(g, h); Tf R = sqrt(g * g + h * h - c);
  return Circle(o, R);
}
// returns false if points are collinear
bool circumCircle(PT a, PT b, PT c, Circle &p) {
  using Linear::lineLineIntersect;
  if(orient(a, b, c) == 0) return false;
  PT d = (a + b) / 2, e = (a + c) / 2;
  PT vd = rotate90(b - a), ve = rotate90(a - c);
  bool f = lineLineIntersect(d, vd, e, ve, p.o);
  if(f) p.r = length(a - p.o);
  return f;
}
/// finds a circle that goes all of p, |p| <= 3.
Circle boundary(const vector<PT> &p) {
  Circle ret; int sz = p.size();
  if(sz == 0)     ret.r = 0;
  else if(sz == 1)  ret.o = p[0], ret.r = 0;
  else if(sz == 2)  ret.o = (p[0] + p[1]) / 2,
                  ret.r = length(p[0] - p[1]) / 2;
  else if(!circumCircle(p[0],p[1],p[2],ret))
                  ret.r = 0;
  return ret;
}
/// Min circle enclosing p[fr.....n-1],
///with points in b on the boundary, |b| <= 3.
Circle welzl(const vector<PT> &p,
                        int fr, vector<PT> &b) {
  if(fr >= (int) p.size() || b.size() == 3)
                            return boundary(b);
  Circle c = welzl(p, fr + 1, b);
  if(!c.contains(p[fr])) {
    b.push_back(p[fr]); c = welzl(p, fr + 1, b);
    b.pop_back();
  } return c;
}
/// MEC of p, using weizl's algo. amortized O(n).
Circle MEC(vector<PT> p) {
  random_shuffle(p.begin(), p.end());
  vector<PT> q; return welzl(p, 0, q);
} }
##################################################
// Given list of segments v, finds a pair (i, j) st
// v[i],v[j] intersects. If none, returns {-1, -1}
namespace IntersectingSegments {
struct Event {
  Tf x; int tp, id;
  bool operator < (const Event &p) const {
    if(dcmp(x-p.x)) return x<p.x; return tp>p.tp;
  }
};
pair<int, int> anyInters(const vector<Segment> &v){
  using Linear::segmentsIntersect;
  static_assert(is_same<Tf, Ti>::value);
  vector<Event> ev;
  for(int i=0; i<v.size(); i++) {
    ev.push_back({min(v[i].a.x, v[i].b.x), +1, i});
    ev.push_back({max(v[i].a.x, v[i].b.x), -1, i});
  }
  sort(ev.begin(), ev.end());
  auto comp = [&v] (int i, int j) {
    Segment p = v[i], q = v[j];
    Tf x=max(min(p.a.x,p.b.x), min(q.a.x, q.b.x));
    auto yvalSegment = [&x](const Line &s) {
      if(dcmp(s.a.x - s.b.x) == 0) return s.a.y;
      return s.a.y + (s.b.y - s.a.y)
            * (x - s.a.x) / (s.b.x - s.a.x);
    };
    return dcmp(yvalSegment(p)-yvalSegment(q))<0;
  };
  multiset<int, decltype(comp)> st(comp);
  typedef decltype(st)::iterator iter;
  auto prev = [&st](iter it) {
    return it == st.begin() ? st.end() : --it;
  };
  auto next = [&st](iter it) {
    return it == st.end() ? st.end() : ++it;
  };
  vector<iter> pos(v.size());
  for(auto &cur : ev) {
    int id = cur.id;
    if(cur.tp == 1) {
      iter nxt = st.lower_bound(id), pre=prev(nxt);
      if(pre != st.end() && segmentsIntersect
         (v[*pre], v[id]))   return {*pre, id};
      if(nxt != st.end() && segmentsIntersect
         (v[*nxt], v[id]))   return {*nxt, id};
      pos[id] = st.insert(nxt, id);
    }
    else {
      iter nxt=next(pos[id]), pre=prev(pos[id]);
      if(pre != st.end() && nxt != st.end() &&
         segmentsIntersect(v[*pre], v[*nxt]))
        return {*pre, *nxt};
      st.erase(pos[id]);
    }
  } return {-1, -1};
} }
##################################################
namespace HalfPlanar {
using Linear::lineLineIntersect;
struct DirLine {
  PT p, v; Tf ang;
  DirLine() {}
  /// Directed line containing point P in the dir v
  DirLine(PT p, PT v) : p(p), v(v) {
    ang = atan2(v.y, v.x); }
  /// Directed Line for ax+by+c >=0
  DirLine(Tf a, Tf b, Tf c) {
    assert(dcmp(a) || dcmp(b));
    p = dcmp(a) ? PT(-c/a, 0) : PT(0,-c/b);
    v = PT(b, -a); ang = atan2(v.y, v.x);
  }
  bool operator<(const DirLine& u) const {
      return ang < u.ang; }
  bool onLeft(PT x) const {
      return dcmp(cross(v, x-p)) >= 0; }
};
// region bounded by the left side of dir lines
// OUTPUT IS UNDEFINED if intersection is unbounded
// O(n log n) for sorting, O(n) afterwards
Polygon halfPlaneIntersection(vector<DirLine> li) {
  int n = li.size(), first = 0, last = 0;
  sort(li.begin(), li.end());
  vector<PT> p(n);
  vector<DirLine> q(n);
  q[0] = li[0];

  for(int i = 1; i < n; i++) {
    while(first < last && !li[i].onLeft(p[last-1]))
        last--;
    while(first < last && !li[i].onLeft(p[first]))
        first++;
    q[++last] = li[i];
    if(dcmp(cross(q[last].v, q[last-1].v)) == 0) {
      last--;
      if(q[last].onLeft(li[i].p)) q[last] = li[i];
    }
    if(first < last)
      lineLineIntersect(q[last-1].p, q[last-1].v,
               q[last].p, q[last].v, p[last - 1]);
  }

  while(first<last && !q[first].onLeft(p[last-1]))
    last--;
  if(last - first <= 1) return {};
  lineLineIntersect(q[last].p, q[last].v,
                q[first].p, q[first].v, p[last]);
return Polygon(p.begin()+first, p.begin()+last+1);
}

// O(n^2 lg n) VoronoiDiagram bounded by INF square
// regions[i] = region with closest =  site[i].
const Tf INF = 1e10;
vector<Polygon> voronoi(vector<PT> site, Tf bsq) {
  int n = site.size();
  vector<Polygon> region(n);
  PT A(-bsq, -bsq), B(bsq, -bsq),
     C(bsq, bsq), D(-bsq, bsq);
  for(int i = 0; i < n; ++i) {
    vector<DirLine> li(n - 1);
    for(int j = 0, k = 0; j < n; ++j) {
      if(i == j) continue;
      li[k++] = DirLine((site[i] + site[j]) / 2,
                     rotate90(site[j] - site[i]));
    }
    li.emplace_back(A,B-A); li.emplace_back(B,C-B);
    li.emplace_back(C,D-C); li.emplace_back(D,A-D);
    region[i] = halfPlaneIntersection(li);
  }
  return region;
} }
