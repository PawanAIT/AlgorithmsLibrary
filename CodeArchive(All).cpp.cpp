/* UBC CODEARCHIVE 2013
Geometry
  General 2D geometry ........................................................ ?
  Polygon cutting ............................................................ ?
  Point in polygon ........................................................... ?
  Arbitrary polygon intersection (highly unreliable) ......................... ?
  Triangle area from three medians ........................................... ?
  Rectangle in rectangle ..................................................... ?
  Closest pair ............................................................... ?
  General Line Segment Sweep (Bentley-Ottmann algorithm) ..................... ?
  Area of intersection of two circles ........................................ ?
  Circles tangents ........................................................... ?
  Circular Arc Length ........................................................ ?
  Circular boundary traversal ................................................ ?
  Circular obstacles visibility graph construction ........................... ?
  2D Convex hulls (Graham's scan, monotone chain, orthogonal, circles) ....... ?
  General 3D geometry (including CCW 3D axis rotation) ....................... ?
  3D convex hulls (slow and quick) ........................................... ?
  Arbitrary-Dimension Minimum Enclosing Ball ................................. ?

Math and Number Theory
  Rational Numbers ........................................................... ?
  Extended GCD ............................................................... ?
  Extended GCD in canonical form ............................................. ?
  Chinese remainder theorem .................................................. ?
  Linear Diophantine Equation Solver ......................................... ?
  Legendre symbol ............................................................ ?
  Modular Exponentiation ..................................................... ?
  Discrete Log ............................................................... ?
  Polynomial GCD ............................................................. ?
  Polynomial root ............................................................ ?
  Pythagorean triples ........................................................ ?
  Farey sequences ............................................................ ?
  Conic section solver ....................................................... ?
  Adaptive Simpsons Integrator ............................................... ?

Linear algebra
  Simplex  ................................................................... ?
  Linear algebra (go Matthew!) ............................................... ?
  Matrix determinant ......................................................... ?
  FFT ........................................................................ ?

Strings
  Suffix array ............................................................... ?
  Suffix tree ................................................................ ?
  Palindrome substrings ...................................................... ?
  KMP string matching ........................................................ ?
  Z-value string matching .................................................... ?
  Aho Corasick ............................................................... ?

Graph theory
  Array-based undirected sparse graph ........................................ ?
  Maximum flow ............................................................... ?
  Maximum bipartite matching ................................................. ?
  Maximum weight bipartite matchings ......................................... ?
  General matching (entirely almost not completely unbroken) ................. ?
  Biconnected components & 2-edge connected components ....................... ?
  Euler path ................................................................. ?
  Bart's 2-Sat ............................................................... ?
  All pairs min cut .......................................................... ?
  Minpath-Vertex cover ....................................................... ?
  Strongly connected components .............................................. ?
  Number of spanning trees ................................................... ?
  Bridge detection ........................................................... ?
  Articulation vertex ........................................................ ?
  Directed MST ............................................................... ?
  K-th shortest path ......................................................... ?
  Gomory-Hu tree (All pairs max-flow) ........................................ ?

Trees
  KD-tree .................................................................... ?
  Binary Indexed Tree ........................................................ ?
  Range Query Tree (operation = min) ......................................... ?
  Splay Tree ................................................................. ?
  Link-cut Tree .............................................................. ?

Miscellaneous
  MinQueue ................................................................... ?
  Poker ...................................................................... ?
  Josephus ring survivor ..................................................... ?
  Day of week ................................................................ ?
  Roman numerals ............................................................. ?
  Rubiks cube ................................................................ ?
  Reconstruction of a set from its pairwise sums ............................. ?
  Calendar ................................................................... ?
  Friend/enemy ............................................................... ?
  Expression evaluation/Recursive Descent Parser ............................. ?
  N-Queens problem (formula) ................................................. ?
IDEAS (aka Bart's guide to solving any ACM problem) .......................... ?
THEOREMS ..................................................................... ?
*/
ios::sync_with_stdio(0); // faster iostream, but unsyncs with cstdio
#include <bits/stdtr1c++.h> // if using g++, this includes ALL headers.
////////////////////////////////////////////////////////////////////////////////
// General 2D geometry, Polygon cutting, Point in polygon
////////////////////////////////////////////////////////////////////////////////
const int INF = 0x3f3f3f3f; const int MINF = 0xc0c0c0c0;
const ld EPS = 1e-9; const ld PI = acos(-1.L);
ld cp(const pt &a, const pt &b) { return a.real()*b.imag() - b.real()*a.imag();}
ld dp(const pt &a, const pt &b) { return a.real()*b.real() + a.imag()*b.imag();}
inline ld sgn(const ld& x) { return abs(x) < EPS ? 0 : x/abs(x); }
inline bool cmp_lex(const pt& a, const pt& b)
{ return a.real() < b.real() || (a.real() == b.real() && a.imag() < b.imag()); }
inline bool cmp_lex_i(const pt &a, const pt &b)
{ return a.imag() < b.imag() || (a.imag() == b.imag() && a.real() < b.real()); }

// handles ALL cases, change occurences of <= to < to exclude endpoints
bool seg_x_seg(pt a1, pt a2, pt b1, pt b2){
  //if (a1==a2 || b1==b2) return false; // uncomment to exclude endpoints
  int s1 = sgn(cp(a2 - a1, b1 - a1)), s2 = sgn(cp(a2 - a1, b2 - a1));
  int s3 = sgn(cp(b2 - b1, a1 - b1)), s4 = sgn(cp(b2 - b1, a2 - b1));
  if(!s1 && !s2 && !s3) { // collinear
    if (cmp_lex(a2, a1)) swap(a1,a2); if (cmp_lex(b2, b1)) swap(b1, b2);
    return !cmp_lex(b2, a1) && !cmp_lex(a2, b1);
    //return cmp_lex(a1, b2) && cmp_lex(b1, a2);//uncomment to exclude endpoints
  } return s1*s2 <= 0 && s3*s4 <= 0; }

inline pt line_inter(const pt &a, const pt &b, const pt &c, const pt &d){
  return a + cp(c - a, d - c)/cp(b - a, d - c) * (b - a); }

// Projection of (a -> p) to vector (a -> b), SIGNED - positive in front
inline ld proj_dist(const pt &a, const pt &b, const pt &p){
  return dp(b - a, p - a) / abs(b - a); }

// SIGNED distance. Pt on the right of vector (a -> b) will be NEGATIVE.
inline ld lp_dist(const pt &a, const pt &b, const pt &p){
  return cp(b - a, p - a) / abs(b - a); }

// Line segment (a, b) to pt p distance.
inline ld lsp_dist(const pt &a, const pt &b, const pt &p){
  return dp(b - a, p - a) > 0 && dp(a - b, p - b) > 0 ?
    abs(cp(b - a, p - a) / abs(b - a)) : min(abs(a - p), abs(b - p)); }

// Closest pt on line segment (a, b) to pt p.
inline pt lsp_closest(const pt &a, const pt &b, const pt &p){
  if (dp(b - a, p - a) > 0 && dp(a - b, p - b) > 0)
    return abs(cp(b - a, p - a))<EPS ? p : line_inter(a, b, p, p+(a-b)*pt(0,1));
  return abs(a - p) < abs(b - p) ? a : b; }

// Area of a polygon (convex or concave). Always non-negative.
ld area(pol v){ ld out=0;
  for(int i = v.size()-1, j = 0; j < v.size(); i = j++) out += cp(v[i], v[j]);
  return abs(out)/2; }

// orientation does not matter
pt centroid(const pol &v) {
  pt res; ld A=0; int n = v.size();
  for(int i=n-1,j=0;j<n;i=j++) A+=cp(v[i],v[j]), res+=(v[i]+v[j])*cp(v[i],v[j]);
  return abs(A) < EPS ? res : res/3.L/A; }

// Left of the vector (a -> b) will be cut off. Convex polygons tested UVa 10117
pol cut_polygon(const pol &v, const pt &a, const pt &b) { pol out;
  for(int i = v.size() - 1, j = 0; j < v.size(); i = j++) {
    if(cp(b-a, v[i]-a) < EPS) out.push_back(v[i]);
    if(sgn(cp(b-a, v[i]-a)) * sgn(cp(b-a, v[j]-a)) < 0) {
      pt p = line_inter(a, b, v[i], v[j]);
      if(!out.size() || abs(out.back() - p) > EPS) out.push_back(p); } }
  while(out.size() && abs(out[0] - out.back()) < EPS) out.pop_back();
  return out; }

inline bool on_segment(const pt &a, const pt &b, const pt &p){
  return abs(cp(b-a, p-a)) < EPS && dp(b-a, p-a) > 0 && dp(a-b, p-b) > 0; }

// Checks if p lies on the boundary of a polygon v.
inline bool on_boundary(const pol &v, const pt &p){ bool res = false;
  for(int i=v.size()-1,j=0;j<v.size();i=j++) res |= on_segment(v[i], v[j], p);
  return res; }

// orientation does not matter !!!
bool pt_in_polygon(const pol &v, const pt &p){ if(on_boundary(v,p)) return true;
  ld res = 0; for(int i = v.size() - 1, j = 0; j < v.size(); i = j++)
    res += atan2(cp(v[i] - p, v[j] - p), dp(v[i] - p, v[j] - p));
  return abs(res) > 1; } // will be either 2*PI or 0
////////////////////////////////////////////////////////////////////////////////
// Arbitrary polygon intersection. Returns intersection. O(n^2 log n)
////////////////////////////////////////////////////////////////////////////////
typedef pair<pt, int> ppi; // Tested on convex polygons UVa 137, 10321
vector<pol> pol_inter(pol v1, pol v2){
  int n[2] = { v1.size(), v2.size() }, N = n[0] + n[1];
  if(n[0] > n[1]) return pol_inter(v2, v1);
  vector<pol> out; if(n[0] < 3) return out;
  bool same = (n[0] == n[1]);
  for (int i=0; i < n[0]; i++) if (v1[i] != v2[i]) same = false;
  if (same) { out.push_back(v1); return out; }

  vector<ppi> xs[N]; // xs[i] = sorted list of (intersection, j) for each j
  int idx[N][N];     // idx[i][j] = index into xs[i] s.t. xs[i][idx].second == j
  memset(idx, 0, sizeof idx);
  int id, pvnx[N][2];// ids for the current edge, previous edge, and next edge
  // Find intersections, break edges into segments that are in both polygons
  for (int k=0; k < 2; k++) { // Try both polygons
    for (int i=n[k]-1, j=0; j < n[k]; i=j++) { // for each edge
      int id = k*n[0]+i; vector<ppi> &p = xs[id];
      pvnx[id][0] = k*n[0] + (i+n[k]-1)%n[k], pvnx[id][1] = k*n[0] + (i+1)%n[k];

      for (int ii=n[1-k]-1, jj=0; jj < n[1-k]; ii=jj++) // Find intersections
        if (abs(cp(v1[i] - v1[j], v2[ii] - v2[jj])) > EPS &&
            seg_x_seg(v1[i], v1[j], v2[ii], v2[jj]))
          p.push_back(ppi(line_inter(v1[i],v1[j],v2[ii],v2[jj]),(1-k)*n[0]+ii));
      // sort along the edge (so pvnx ids make sense)
      if (v1[i]<v1[j]) sort(p.begin(),p.end()); else sort(p.rbegin(), p.rend());
      // add in "intersections" with pv and nx edges of current polygon
      if (!p.size() || abs(p[0].first - v1[i]) > EPS)
          p.insert(p.begin(), ppi(v1[i], pvnx[id][0]));
      if (abs(p.back().first-v1[j]) > EPS) p.push_back(ppi(v1[j], pvnx[id][1]));

      int last = idx[id][p[0].second] = 0; // Fill in idx and remove duplicates
      for (int l=1; l < p.size(); l++) {
        if (abs(p[l].first - p[last].first) > EPS) p[++last] = p[l];// new point
        idx[id][p[l].second] = last; }
      p.resize(last+1);
      // Make sure we begin and end with a segment that's in the intersection
      if(!pt_in_polygon(v2, (p[last-1].first+p[last].first)/2.L)) p.pop_back();
      if (p.size() > 1 && !pt_in_polygon(v2, (p[0].first + p[1].first)/2.L)) {
          p.erase(p.begin()); for(int l=0; l<N; l++) idx[id][l]--; } }
    swap(v1, v2); }

  // BFS over all segments that are in both polygons and find closed loops
  bool vis[N][N]; memset(vis, 0, sizeof vis);
  for (int k=0; k<2; k++) { // Try both polygons
    for (int i=0; i < v1.size(); i++) { // for each edge
      int id = k*n[0]+i;
      // every 2nd segment is in both polygons
      for (int l=0; l+1 < xs[id].size(); l+=2) if (!vis[id][l]) {
        pol p; int cid = id, cl = l; // id and index for current segment
        do { vis[cid][cl] = vis[cid][cl^1] = true;
          p.push_back(xs[cid][cl].first);
          int nid = xs[cid][cl^=1].second; // id of edge the other endpoint hits
          if (xs[nid].size() < 2) {// no segment to follow, stay on this polygon
            nid = pvnx[cid][cl!=0];// cl==0->go to previous edge, else next edge
            cl = cl==0 ? xs[nid].size()-1 : 0;
          } else cl = idx[nid][cid];
          cid = nid;
        } while (!vis[cid][cl] && xs[cid].size() > 1);
        out.push_back(p); } }
    swap(v1, v2); }
  return out; }
////////////////////////////////////////////////////////////////////////////////
// Triangle area from three medians
////////////////////////////////////////////////////////////////////////////////
ld triAreaFromMedians(ld ma, ld mb, ld mc) { // Tested UVa 10347
    ld x = (ma + mb + mc)/2, a = x * (x - ma) * (x - mb) * (x - mc);
    return a < 0.0 ? -1.0 : sqrt(a) * 4.0 / 3.0; }
////////////////////////////////////////////////////////////////////////////////
// Rectangle in rectangle
////////////////////////////////////////////////////////////////////////////////
bool contains(ll W, ll H, ll w, ll h) { // tan(t) = (Hw-Wh)/(Ww-Hh)
  if ((w <= W && h <= H) || (w <= H && h <= W)) return true;
  if ((W <= w && W <= h) || (H <= w && H <= h)) return false;
  ll kc = H*w - W*h,   km = w*w - h*h,   xc = w * kc,   yc = W * km - h * kc;
  return xc*xc + yc*yc >= km*km * w*w; }
////////////////////////////////////////////////////////////////////////////////
// Closest pair in n*log(n). Returns the pair. Assumes v.size() >= 2.
////////////////////////////////////////////////////////////////////////////////
pair<pt, pt> closest_pair(vector<pt> v) { // Tested UVa 10245, 11378
  sort(v.begin(), v.end(), cmp_lex);
  ld best = 1e99; int low = 0; pair<pt, pt> bestpair;
  set<pt, bool(*)(const pt&,const pt&)> help(cmp_lex_i);
  for(int i = 0; i < v.size(); i++){
    while(low < i && (v[i] - v[low]).real() > best) help.erase(v[low++]);
    for(__typeof(help.end()) it = help.lower_bound(v[i] - pt(1e99, best));
	    it != help.end() && (*it - v[i]).imag() < best; it++)
      if (abs(*it - v[i]) < best)
        best = abs(*it - v[i]), bestpair = make_pair(*it, v[i]);
    help.insert(v[i]); }
  return bestpair; }
////////////////////////////////////////////////////////////////////////////////
// General Line Segment Sweep (Bentley-Ottmann algorithm)
////////////////////////////////////////////////////////////////////////////////
// O((N + K) log N) intersections, O((N + K) N log N) area, perimeter
// Tested: SPOJ NKMARS, VCIRCLES, POJ 1177
// SHOULD HANDLE: - multiple intersections at a point, collinear segments
// WARNING: Assumes no vertical lines exist. Rotate input such that this is true
// WARNING: completely VERTICAL (in z-direction) POLYGONS if doing 3D
// USAGE: SEGS = 0; add_seg(A, B, polygon_id); line_sweep();
int SEGS;  // # of segments
struct seg_t { ld m, c, x2; int id;
  inline ld gety(const ld& x) const {
    if(m > 1e98) return c; // marker segment
    return c + m * x;
  } } segarr[MAXN + 1];
bool ycmp_post; pt now; // position of sweep line
struct ycmp { bool operator() (const int& a, const int& b) const {
  const ld y1 = segarr[a].gety(now.real()), y2 = segarr[b].gety(now.real());
  if (abs(y1 - y2) > EPS) return y1 < y2;
  if (abs(segarr[a].m - segarr[b].m) > EPS) {
    if (ycmp_post) return segarr[a].m + EPS < segarr[b].m;
    return segarr[a].m - EPS > segarr[b].m;
  } return a < b; } };
typedef set<int, ycmp> line_set; typedef line_set::iterator line_itr;
line_set state; // y-ordered list of current lines
map<pt, vi, bool(*)(const pt&,const pt&)> events(cmp_lex);//list of new segments
// find intersection of 2 line segments if within range
inline bool intersect(int i, int j, pt& I) {
  const seg_t &si = segarr[i], &sj = segarr[j];
  if (abs(si.m - sj.m) < EPS) return false; // parallel
  ld x = (sj.c - si.c) / (si.m - sj.m);
  if (x - EPS > si.x2 || x - EPS > sj.x2) return false;
  I = pt(x, si.gety(x)); return true; }
inline void seg_add(int i) {
  ycmp_post = true; // for insertion // assert(state.find(i) == state.end());
  line_itr curr = state.insert(i).first, prev = curr, next = curr;
  --prev; ++next; pt I; // assert(i == *curr);
  if(next != state.end()) // bottom exist
    if(intersect(*curr, *next, I) && I.real() > now.real()) events[I];
  if(curr != state.begin()) // top exist
    if(intersect(*prev, *curr, I) && I.real() > now.real()) events[I]; }
// delete FIRST segments with (xnow, y), returns segment id or -1 if fail
inline int seg_del() {
  ycmp_post = false; // for deletion
  segarr[MAXN].m = 1e99; segarr[MAXN].c = now.imag() - EPS;
  line_itr curr = state.lower_bound(MAXN);
  if (curr == state.end()) return -1;
  const int i = *curr;
  if (segarr[i].gety(now.real()) - now.imag() > EPS) return -1;
  line_itr prev = curr, next = curr; --prev; ++next; pt I;
  if (curr != state.begin() && next != state.end())
    if (intersect(*prev, *next, I) && I.real() > now.real()) events[I];
  state.erase(curr);
  return i; }
// USER DEFINED: calculate the area when there are these active polygons
// A, B, C, D is a ccw quadrilateral that is inside each of the active polygons
ld calc_area(const set<int> &active, pt A, pt B, pt C, pt D);
inline ld find_area(const ld& xprev) {
  int a = -1, b; set<int> active; ld area = 0;
  for(line_itr it = state.begin(); it != state.end(); ++it) { b = *it;
    if(a == -1) { active.insert(segarr[b].id); a = b; continue; } // first seg
    const seg_t &sa = segarr[a], &sb = segarr[b]; // counter-clockwise
    pt A(xprev, sa.gety(xprev)), B(now.real(), sa.gety(now.real())),
      C(now.real(), sb.gety(now.real())), D(xprev, sb.gety(xprev));
    area += calc_area(active, A, B, C, D);
    if (active.count(segarr[b].id)) active.erase(segarr[b].id);
    else active.insert(segarr[b].id);
    a = b; } return area; }
ld line_sweep() { // O( (N + K) log N ), K = # intersects
  pt prev; ld area = 0;
  while(!events.empty()) {
    now = events.begin()->first; vi U;
    swap(U, events.begin()->second); // STL efficient
    events.erase(events.begin());
    if(abs(prev.real() - now.real()) > EPS) {
      // USER-DEFINED: area += find_area(prev.real());
    }
    while(true) { int i = seg_del(); if(i == -1) break; U.push_back(i); }
    // USER-DEFINED: U contains ids of intersecting segments at x=now.real()
    // for(int i = 0; i < U.size(); ++i)
    // for(int j = i + 1; j < U.size(); ++j)
    // report_intersection(U[i], U[j]);
    for(vi::iterator it = U.begin(); it != U.end(); ++it)
      if(segarr[*it].x2 - EPS > now.real()) seg_add(*it);
    prev = now; } // assert(state.empty());
  return area; }
// this function is for initialization; id denotes which polygon
void add_seg(pt A, pt B, const int& id) {
  if(cmp_lex(B, A)) swap(A, B); events[A].push_back(SEGS); events[B];
  segarr[SEGS].m = (A.imag() - B.imag()) / (A.real() - B.real());
  segarr[SEGS].c = A.imag() - segarr[SEGS].m * A.real();
  segarr[SEGS].x2 = B.real(); segarr[SEGS].id = id; ++SEGS; }
////////////////////////////////////////////////////////////////////////////////
// Circle-circle intersection (TESTED UVa 453)
////////////////////////////////////////////////////////////////////////////////
// Return number of intersections. Circles must not be identical.
int cc_inter(pt p1, ld r1, pt p2, ld r2, pt &i1, pt &i2) {
  ld dq=norm(p1-p2), rq=r1*r1-r2*r2; pt c=(p1+p2)*0.5L + (p2-p1)*rq*0.5L/dq;
  ld dt=2.0*dq*(r1*r1+r2*r2)-dq*dq-rq*rq;
  if(dt < -EPS) return 0; if(dt < EPS) { i1=i2=c; return 1; }
  dt=sqrt(dt)*0.5/dq; i1=c+(p2-p1)*pt(0,1)*dt; i2=c-(p2-p1)*pt(0,1)*dt;
  return 2; }
////////////////////////////////////////////////////////////////////////////////
// Area of intersection of 2 circles (UNTESTED)
////////////////////////////////////////////////////////////////////////////////
ld cc_area(pt p1, ld r1, pt p2, ld r2) { if(r2 < r1) swap(p1, p2), swap(r1, r2);
  ld d = abs(p2 - p1), dA, dB, tx, ty;
  if (d + r1 < r2 + EPS) return r1*r1*PI;      if (d >= r1 + r2) return 0;
  dA = tx = (d*d + r1*r1 - r2*r2)/d/2, dB = d-dA, ty = sqrt(r1*r1-tx*tx);
  return r1*r1*acos(dA/r1) - dA*sqrt(r1*r1-dA*dA)
       + r2*r2*acos(dB/r2) - dB*sqrt(r2*r2-dB*dB); }
////////////////////////////////////////////////////////////////////////////////
// Circles tangents
////////////////////////////////////////////////////////////////////////////////
// Given two circles, find all tangent angles.
// returns four angles for the first circle.
inline vector<ld> get_tangents(pt p1, ld r1, pt p2, ld r2) {
  pt v = p2 - p1;                  // vector from p1 to p2
  ld d = abs(v);                   // distance between centers
  ld a = acos((r1 - r2)/d);        // outer tangent's angle relative to c1 -> c2
  ld b = acos((r1 + r2)/d);        // inner .......
  ld s = atan2(v.imag(), v.real());// basis angle relative to the circle1
  vector <ld> out; out.push_back(s + a), out.push_back(s - a);
  out.push_back(s + b), out.push_back(s - b); return out; }
ld good_angle(ld a){ return fmod(fmod(a, 2*PI) + 2*PI, 2*PI); }
ld ang_dist(ld a1, ld a2){
  ld d = fmod(abs(a1 - a2), 2*PI); return min(d, 2*PI - d); }

pair<pt, pt> circle_tangent(ld r1, ld r2, ld d, int k) { // use the fcn below
  ld dr = (k & 2) ? (-r1-r2) : (r2-r1); ld t = asin(dr / d);
  pt p1=polar(r1, PI/2+t), p2=polar(r2, PI/2+t); if(k&2) p2*=-1; p2+=pt(d,0);
  if(k&1){ p1=pt(p1.real(),-p1.imag()); p2=pt(p2.real(),-p2.imag()); }
  return make_pair(p1, p2); }
// tested 2008wf conveyor; tangent of 2 circles; CAUTION: INTERSECTION IS BAD
// k=0 top-top, k=1 bot-bot, k=2 top-bot, k=3 bot-top. Also works for points.
pair<pt, pt> circle_tangent(pt p1, ld r1, pt p2, ld r2, int k) {
  // translate/rotate so c1 at (0,0), c2 at x-axis
  pt d = p2-p1; pair<pt, pt> p = circle_tangent(r1, r2, abs(d), k); d /= abs(d);
  p.first *= d; p.second *= d; p.first += p1; p.second += p1; return p; }
////////////////////////////////////////////////////////////////////////////////
// Circular Arc Length (UNTESTED)
////////////////////////////////////////////////////////////////////////////////
ld arc_length(pt p, ld r, pt p1, pt p2, bool ccw) { 
  ld a1=arg(p1-p), a2=arg(p2-p); return fmod((ccw?a2-a1:a1-a2)+2*PI, 2*PI)*r; }
////////////////////////////////////////////////////////////////////////////////
// Circular boundary traversal
////////////////////////////////////////////////////////////////////////////////
int vis[128], done[128][128], ind[128][128], sz[128], cnt, n;
pt c[128];
ld out[128][128], in[128][128], r[128], x, y;
void dfs(int now){ if(vis[now]) return;
  vis[now] = 1; for(int i = 0; i < n; i++)
		  if(!vis[i] && abs(c[now] - c[i]) < r[now] + r[i]) dfs(i);}
int main(){
  int t; cin >> t;
  while(t-- && cin >> n){
    for(int i = 0; i < n && cin >> x >> y >> r[i]; i++) c[i] = pt(x, y);
    memset(vis, 0, sizeof(vis)), memset(sz, 0, sizeof(sz));
    memset(done, 0, sizeof(done));
    for(int i = 0; i < n; i++)
      for(int j = 0; j < n; j++){
        ld d = abs(c[i] - c[j]);
        if(i != j && abs(r[i] - r[j]) < d && d < r[i] + r[j]){
          pt v = c[j] - c[i];
          ld cosa = (r[i]*r[i] + d*d - r[j]*r[j])/(2*r[i]*d);
          ld sina = sqrt(1 - cosa*cosa);
          v *= pt(cosa, -sina); // v is direction to intersection
          v /= abs(v), v *= r[i];
          pt inter = v + c[i]; // now inter is the intersection pt;
          bool good = true;
          for(int k = 0; k < n; k++) good &= (abs(inter - c[k]) + EPS > r[k]);
          if(good){  // only if not inside a circle
            out[i][sz[i]] = atan2(v.imag(), v.real());
            if(out[i][sz[i]] < 0) out[i][sz[i]] += 2*PI;
            ind[i][sz[i]] = j;
            v = c[i] - c[j];
            cosa = (r[j]*r[j] + d*d - r[i]*r[i])/(2*r[j]*d);
            sina = sqrt(1 - cosa*cosa);
            v *= pt(cosa, sina); // the other turn
            in[i][sz[i]++] = atan2(v.imag(), v.real());
            if(in[i][sz[i] - 1] < 0) in[i][sz[i] - 1] += 2*PI; } } }
    cnt = 1;
    for(int i = 0; i < n; i++){
      if(sz[i] && !vis[i]) cnt--, dfs(i);
      for(int j = 0; j < sz[i]; j++)
        if(!done[i][j]){
          cnt++;
          ld angle = in[i][j] - EPS;
          int now = ind[i][j];
          while(true){
            ld best = 1e99;
            int p = -1;
            for(int k = 0; k < sz[now]; k++){
              ld dif = out[now][k] - angle; if(dif < 0) dif += PI*2;
              if(dif < best) best = dif, p = k;
            }
            if(done[now][p]) break;
            done[now][p] = 1;
            angle = in[now][p] - EPS;
            now = ind[now][p]; } } }
    cout << cnt - 1 << endl; } } // number of components??
////////////////////////////////////////////////////////////////////////////////
// Circular obstacles visibility graph construction (N^3 ?)
////////////////////////////////////////////////////////////////////////////////
vector < vector < pair < int, ld > > >
build_graph(const vector < pair < pt, ld > > &data){
  vector < ld > angle(4*data.size()*data.size(), 0), temp;
  for(int i = 0; i < (int)data.size(); i++)
    for(int j = 0; j < (int)data.size(); j++)
      if(i != j){
	temp = get_tangents(data[i].first, data[i].second,
			    data[j].first, data[j].second);
	for(int k = 0; k < 4; k++)
	  angle[4*i*data.size() + 4*j + k] = temp[k]; } // i -> j
  vector < pt > pnts;
  for(int i = 0; i < (int)angle.size(); i++){
    pt p = data[i/(4*data.size())].first;
    ld r =  data[i/(4*data.size())].second;
    ld a = angle[i];
    pnts.push_back(p + r*pt(cos(a), sin(a))); }
  vector < vector < pair < int, ld > > > out(pnts.size());
  // do the distances between pts on same circle
  for(int i = 0; i < (int)angle.size(); i += 4*data.size()){ // for each circle
    int id = i/(4*data.size()); // circle #
    vector < pair < ld, int > > help;
    for(int j = 0; j < (int)data.size()*4; j++)
      help.push_back(make_pair(good_angle(angle[i + j]), i + j));
    sort(help.begin(), help.end());
    for(int a = help.size() - 1, b = 0; b < (int)help.size(); a = b++)
      out[help[a].second].push_back(make_pair(
       help[b].second, data[id].second*ang_dist(help[a].first, help[b].first))),
      out[help[b].second].push_back(make_pair(
       help[a].second,data[id].second*ang_dist(help[a].first, help[b].first)));}
  // do the distances between different circles, whenever possible...
  for(int i = 0; i < (int)data.size(); i++)
    for(int j = i + 1; j < (int)data.size(); j++)
      for(int k = 0; k < 4; k++){
	int ii = 4*i*data.size() + 4*j + k;
	int jj = 4*j*data.size() + 4*i + (k^1^((k&2) >> 1));
	bool good = true; // check is line if far enough from each circle
	for(int kk = 0; kk < (int)data.size() && good; kk++)
	  good &= (lsp_dist(pnts[ii], pnts[jj], data[kk].first) + EPS >=
		   data[kk].second);
	if(good){
	  out[ii].push_back(make_pair(jj, abs(pnts[ii] - pnts[jj])));
	  out[jj].push_back(make_pair(ii, abs(pnts[ii] - pnts[jj]))); } }
  return out; }
////////////////////////////////////////////////////////////////////////////////
// 2D convex hull (TESTED SPOJ BSHEEP, UVA 11096)
////////////////////////////////////////////////////////////////////////////////
// Works with duplicate points but no guarantees on which point will be used
pol chull(pol p) { // change <= 0 to < 0 to find collinear convex hull points
  sort(p.begin(), p.end(), cmp_lex_i); int top=0, bot=1; pol ch(2*p.size());
  for (int i=0, d=1; i < p.size() && i >= 0; i += d) {
    while (top > bot && cp(ch[top-1]-ch[top-2], p[i]-ch[top-2]) <= 0) top--;
    ch[top++] = p[i]; if (i == p.size()-1) d = -1, bot = top;
  } ch.resize(max(1, top-1)); return ch; }
////////////////////////////////////////////////////////////////////////////////
// Orthogonal Convex Hull (all edges are parallel to x or y axis)
////////////////////////////////////////////////////////////////////////////////
vpii orthinc(const vpii& points, bool up) {
  // lexicographical sort
  vpii chain; chain.pb(points.front()); int maxy = points.front().second;
  for (int i = 1; i < points.size(); ++i) {
    if (up) { if(points[i].second <= maxy) continue; }
    else { if (points[i].second >= maxy) continue; }
    if (points[i].first != chain.back().first)
      chain.push_back(pii(points[i].first, maxy));
    else chain.pop_back();
    chain.push_back(points[i]); maxy = points[i].second; } return chain; }
// runs orthogonal convex hull; point ordering may be modified
vpii orthogonal_convex_hull(vpii& points) {
  vpii hull;  sort(points.begin(), points.end());
  vpii h1 = orthinc(points, true), h2 = orthinc(points, false);
  reverse(points.begin(), points.end());
  vpii h3 = orthinc(points, true), h4 = orthinc(points, false);
  hull.insert(hull.end(), h1.begin(), h1.end()); // use swap
  hull.insert(hull.end(), h3.rbegin(), h3.rend());
  hull.insert(hull.end(), h4.begin(), h4.end());
  hull.insert(hull.end(), h2.rbegin(), h2.rend());
  return hull; }
////////////////////////////////////////////////////////////////////////////////
// Convex hull of circles (Tested on UVa)
////////////////////////////////////////////////////////////////////////////////
const ld far = 1e10; // can't be too big or precision error
pt center[MAXN]; ld radius[MAXN]; int V; // # of circles
// true if circle1 is in circle2
bool c_in_c(pt c1, ld r1, pt c2, ld r2) {
  ld d = abs(c1 - c2); return r1 - EPS <= r2 && d + r1 - EPS <= r2; }
// convex hull of circles
ld solve() { // find lowest point; and biggest circle
  pt lowest(far, far);
  // need 2nd point because we may touch the first circle TWICE
  int first = -1, second = -1;
  for (int i = 0; i < V; ++i) { pt low = center[i] - pt(0, radius[i]);
    if (cmp_lex_i(low, lowest)) { lowest = low; first = i; }
    else if (abs(low - lowest) < EPS &&
      c_in_c(center[first], radius[first], center[i], radius[i])) first=i; }
  ld perim = 0; pt left(-far, lowest.imag()), right(far, lowest.imag());
  pt A = left, B = lowest; int i = first;
  while (true) { // tangents are A-B and C-D, B and C lies on the same circle
    pt C = A, D = B; int next = i; ld next_angle = 1e9;
    for (int j = 0; j < V; ++j) { if (i == j) continue;
      // check if inside current circle
      if(c_in_c(center[j], radius[j], center[i], radius[i])) continue;
      // bot-bot since we are doing counter clockwise
      // tangent.first lies on first circle etc.
      seg t = circle_tangent(center[i],radius[i],center[j],radius[j],1);
      ld angle = atan2(cp(B-A, t.second-t.first), dp(B-A, t.second-t.first));
      if (angle < -EPS) angle += PI * 2;
      if (angle + EPS < next_angle) { next_angle = angle; next = j;
	C = t.first; D = t.second; } }
    if (next == i) { perim += radius[i] * PI * 2; break; }
    if (i == first && second == -1) second = next;
    else if (i == first && second == next) { // done, calculate last angle
      perim += radius[i] * next_angle; break; }
    else perim += radius[i] * next_angle;
    perim += abs(C - D); A = C; B = D; i = next; } return perim; }
////////////////////////////////////////////////////////////////////////////////
// General 3D geometry
////////////////////////////////////////////////////////////////////////////////
struct p3d{ ld x,y,z; p3d(ld xx=0, ld yy=0, ld zz=0) : x(xx), y(yy), z(zz) {} };
ld abs(const p3d &v){ return sqrt(v.x*v.x + v.y*v.y + v.z*v.z); }
ostream &operator<<(ostream &os, const p3d &p){
  return os << "(" << p.x << "," << p.y << "," << p.z << ")"; }
p3d operator+(const p3d&a,const p3d&b){ return p3d(a.x+b.x,a.y+b.y,a.z+b.z); }
p3d operator-(const p3d&a,const p3d&b){ return p3d(a.x-b.x,a.y-b.y,a.z-b.z); }
p3d operator*(const ld &s, const p3d &v){ return p3d(s*v.x, s*v.y, s*v.z); }
p3d operator/(const p3d&v, const ld &s){ return p3d(v.x/s, v.y/s, v.z/s); }
inline ld dot(const p3d &a, const p3d &b){ return a.x*b.x + a.y*b.y + a.z*b.z; }
inline p3d cross(const p3d &a, const p3d &b){
  return p3d(a.y*b.z - a.z*b.y, a.z*b.x - a.x*b.z, a.x*b.y - a.y*b.x); }
inline ld dist(const p3d &s, const p3d &p) {
  return (p.x-s.x)*(p.x-s.x) + (p.y-s.y)*(p.y-s.y) + (p.z-s.z)*(p.z-s.z); }
// plane/line intersection. p - pt on plane, n - normal, a1 -> a2 : line
inline p3d pl_inter(const p3d &p, const p3d &n, const p3d &a1, const p3d &a2){
  return a1 + dot(p - a1, n)/dot(n, a2 - a1)*(a2 - a1); }
////////////////////////////////////////////////////////////////////////////////
// CCW 3D rotation about arbitrary axis; tested on 2009 pacnw D but pray anyway
////////////////////////////////////////////////////////////////////////////////
inline p3d rotate(const p3d& p /*pt*/, const p3d& u /*axis*/, const ld& angle) {
  ld c = cos(angle), s = sin(angle), t = 1 - cos(angle);  return p3d(
    p.x*(t*u.x*u.x + c) + p.y*(t*u.x*u.y - s*u.z) + p.z*(t*u.x*u.z + s*u.y),
    p.x*(t*u.x*u.y + s*u.z) + p.y*(t*u.y*u.y + c) + p.z*(t*u.y*u.z - s*u.x),
    p.x*(t*u.x*u.z - s*u.y) + p.y*(t*u.y*u.z + s*u.x) + p.z*(t*u.z*u.z + c)); }
////////////////////////////////////////////////////////////////////////////////
// Slow 3D convex hull
////////////////////////////////////////////////////////////////////////////////
struct face{int p1, p2, p3; face(int a, int b, int c) {p1=a, p2=b, p3=c;}};
int t, n; p3d data[1024];

bool above(const face &f, const p3d p){
  p3d normal = cross(data[f.p2] - data[f.p1], data[f.p3] - data[f.p2]);
  return dot(normal, p - data[f.p1]) > EPS; }

ld area(const face &f){
  return abs(cross(data[f.p2] - data[f.p1], data[f.p3] - data[f.p1])); }

ld volume(const face &f){
  p3d normal = cross(data[f.p2] - data[f.p1], data[f.p3] - data[f.p2]);
  normal = normal / abs(normal);
  ld h = dot(normal, data[f.p1]);
  return area(f)*h/6; }

int main(){ // outputs area/volume of the CH in 3D
  cin >> t;
  while(t-- && cin >> n){
    for(int i = 0; i < n; i++) cin >> data[i].x >> data[i].y >> data[i].z;
    for(int i = n - 1; i >= 0; i--) data[i] = data[i] - data[0];
    for(int i = 1; i < n; i++)
      if(abs(data[i] - data[0]) > EPS){ swap(data[i], data[1]); break; }
    for(int i = 2; i < n; i++)
      if(abs(cross(data[1] - data[0], data[i] - data[0])) > EPS){
        swap(data[i], data[2]); break; }
    for(int i = 3; i < n; i++){
      p3d normal = cross(data[1] - data[0], data[2] - data[0]);
      if(abs(dot(normal, data[0] - data[i])) > EPS){
        swap(data[i], data[3]); break; } }
    vector < face > f; f.push_back(face(0, 1, 2)); f.push_back(face(2, 1, 0));
    for(int i = 3; i < n; i++){
      vector < face > next; set < int > edge;
      for(int j = 0; j < (int)f.size(); j++) // remove the faces
        if(above(f[j], data[i])){
	  edge.insert((f[j].p1 << 10) |  f[j].p2);
	  edge.insert((f[j].p2 << 10) |  f[j].p3);
	  edge.insert((f[j].p3 << 10) |  f[j].p1);
        }else next.push_back(f[j]);
      for(__typeof(edge.begin()) it = edge.begin(); it != edge.end(); it++)
	if(!edge.count( ((*it & 1023) << 10) | (*it >> 10) ) )
	  next.push_back(face(*it >> 10, *it & 1023, i));
      f = next; }
    ld ar = 0; ld vo = 0;
    for(int i = 0; i < (int)f.size(); i++) ar += area(f[i]), vo += volume(f[i]);
    cout.setf(ios::fixed), cout.precision(4);
    cout << ar/2 << " " << vo << endl; }
  return 0; }
////////////////////////////////////////////////////////////////////////////////
// Faster 3D convex hull
////////////////////////////////////////////////////////////////////////////////
typedef list<pair<face, si> > face_list;
ld dist(const face &f, const p3d p) {p3d normal = cross(data[f.p2] - data[f.p1],
		  data[f.p3] - data[f.p2]); return dot(normal, p - data[f.p1]);}
vector<face> faces; vector<bool> gone; // if this face is deleted
vector<vi> vis; // visible points
map<pii, int> adj; // adjacent faces

void add_face(const face& f) {
int i=faces.size();faces.push_back(f);vis.push_back(vi());gone.push_back(false);
 adj[pii(f.p1, f.p2)] = i; adj[pii(f.p2, f.p3)] = i; adj[pii(f.p3, f.p1)] = i; }
void del_face(int i) { gone[i] = true; vis[i].clear(); }
void partition(int off, const vi& p) {
  for(int i = 0; i < p.size(); ++i) for(int f = off; f < faces.size(); ++f) {
      if(gone[f]) continue;
      if(above(faces[f], data[p[i]])) { vis[f].push_back(p[i]); break; } } }
void convex_hull_clean_input() { random_shuffle(data, data + N);
  for (int i = N - 1; i >= 0; i--) data[i] = data[i] - data[0];
  for (int i = 1; i < N; i++)
    if (abs(data[i]-data[0]) > EPS) {swap(data[i], data[1]); break;}
  for (int i = 2; i < N; i++)
    if (abs(cross(data[1] - data[0], data[i] - data[0])) > EPS){
      swap(data[i], data[2]); break; }
  for (int i = 3; i < N; i++) {
    p3d normal = cross(data[1] - data[0], data[2] - data[0]);
    if (abs(dot(normal, data[0] - data[i])) > EPS) {
      swap(data[i], data[3]); break; } } }
vector<face> quick_hull() {
  convex_hull_clean_input();
  faces.clear(); gone.clear(); vis.clear(); adj.clear();
  add_face(face(0, 1, 2)); add_face(face(2, 1, 0));
  vi points; vector<face> ret;
  // handle coplanar starting points
  for(int i = 3; i < N; ++i) { vis[0].push_back(i); vis[1].push_back(i); }
  for(int f = 0; f < faces.size(); ++f) {
    if(vis[f].size() == 0) { continue; } if(gone[f]) continue;
    ld maxdist = EPS; int p = -1; // select furthest point
    for(int i = 0; i < vis[f].size(); ++i) {
      ld z = dist(faces[f], data[vis[f][i]]);
      if(z > maxdist) { maxdist = z; p = vis[f][i]; } }
    points.clear(); set<pii> edges; si done; done.insert(f);
    queue<int> q; q.push(f);
    while(!q.empty()) { int n = q.front(); q.pop(); const face& ff = faces[n];
      if(!above(ff, data[p])) continue;
      for(int v = 0; v < vis[n].size(); ++v) {
	if(vis[n][v] != p) points.push_back(vis[n][v]); }
      edges.insert(pii(ff.p1, ff.p2)); edges.insert(pii(ff.p2, ff.p3));
      edges.insert(pii(ff.p3, ff.p1)); si neib;
      neib.insert(adj[pii(ff.p1, ff.p3)]); neib.insert(adj[pii(ff.p2, ff.p1)]);
      neib.insert(adj[pii(ff.p3, ff.p2)]); del_face(n);
      for(si::iterator s = neib.begin(); s != neib.end(); ++s) {
	if(done.find(*s) != done.end()) continue; if(gone[*s]) continue;
	done.insert(*s); q.push(*s); } }
    int off = faces.size();
    for(set<pii>::iterator it = edges.begin(); it != edges.end(); it++) {
      if(!edges.count(pii(it->second, it->first))) {
	add_face(face(it->first, it->second, p)); } }
    partition(off, points); }
  for(int f = 0; f < faces.size(); ++f) {if(!gone[f]) ret.push_back(faces[f]); }
  return ret; }
////////////////////////////////////////////////////////////////////////////////
// Arbitrary-Dimension Minimum Enclosing Ball   TESTED UVa 10005(2D), 10095(3D)
////////////////////////////////////////////////////////////////////////////////
// adapted from http://www.inf.ethz.ch/personal/gaertner/miniball.html
// Usage:
// 0. pray your soul remains intact after using black magic
// 1. create pt p(D) and set values in p[i] - DON'T FORGET THE D IN pt p(D)
// 2. add pt to Miniball mb with mb.add(p)
// 3. after adding all pts call mb.build() - WARNING: CALL THIS ONLY ONCE
// 4. coordinates of centre are in mb.c_c[d]
// 5. *SQUARED* radius of circle/ball/thing is in mb.c_r2
#define SQR(x) ((x)*(x))
const int D = 3; const ld EPS = 1e-9;
typedef vector<ld> pt;
typedef list<pt>::iterator It;
struct Miniball {
  list<pt> L; It end; int m; pt c_c; ld c_r2;
  vector<pt> c; pt q0; vector<ld> r2, z, f; vector<vector<ld> > v, a;
  Miniball() : m(0), v(D+1,vector<ld>(D)), a(D+1,vector<ld>(D)), c(D+1,pt(D,0)),
    q0(D), r2(D+1), z(D+1), f(D+1), end(L.begin()) { c_c=c[0], c_r2=-1; }
  void add(pt &p) { L.push_back(p); }
  void move_to_front(It i) { m--; if (end==i) end++; L.splice(L.begin(),L,i); }
  void mtf_mb(It i) { end=L.begin(); if (m==D+1) return;
    for (It k=L.begin(),j;(j=k++)!=i;) { ld e = get_e(j);
      if (e > 0 && push(*j)) mtf_mb(j), move_to_front(j); } }
  void pivot_mb(It i) {
    It t=++L.begin(), pivot; mtf_mb(t); ld max_e, old_r2=-1;
    do { if((max_e=max_excess(t,i,pivot)) > 0) {
      if ((t=end)==pivot) ++t;
      old_r2=c_r2; push(*pivot); mtf_mb(end); move_to_front(pivot); }
    } while (max_e > 0 && c_r2 > old_r2); }
  ld max_excess(It j,It i,It& pivot) { ld max_e=0,e;
    for (; j!=i;++j) if ((e=get_e(j)) > max_e) max_e=e,pivot=j; return max_e; }
  ld get_e(It j) { ld e=-c_r2; for (int i=0;i<D;++i) e+=SQR((*j)[i]-c_c[i]);
    return e; }
  bool push(const pt& p) { int i, j; if (!m) c[0]=q0=p, r2[0]=0; else {
      for (i=0;i<D;++i) v[m][i]=p[i]-q0[i];
      for (i=1;i<m;++i) { a[m][i]=0;
        for (j=0;j<D;++j) a[m][i]+=v[i][j]*v[m][j];
        a[m][i]*=(2/z[i]); }
      for (i=1;i<m;++i) for (j=0;j<D;++j) v[m][j]-=a[m][i]*v[i][j];
      z[m]=0; for (j=0;j<D;++j) z[m]+=2*SQR(v[m][j]);
      if (z[m] < c_r2*EPS) return false;
      ld e=-r2[m-1]; for (i=0;i<D;++i) e+=SQR(p[i]-c[m-1][i]);
      f[m]=e/z[m];
      for (i=0;i<D;++i) c[m][i]=c[m-1][i]+f[m]*v[m][i];
      r2[m]=r2[m-1]+e*f[m]/2;
    } c_c=c[m]; c_r2=r2[m]; m++; return true; }
  void build(){ pivot_mb(L.end()); } };
////////////////////////////////////////////////////////////////////////////////
// Rational Numbers
////////////////////////////////////////////////////////////////////////////////
struct rational_t { ll nu, de;
  rational_t(const ll &n = 0, const ll &d = 1) {
    ll g = gcd(abs(n), abs(d)); nu = n / g; de = d / g;
    if (de < 0) { nu = -nu; de = -de; }
  }
  rational_t operator+(const rational_t& b) const
  { return rational_t( nu*b.de+de*b.nu, de*b.de ); }
  rational_t operator-(const rational_t& b) const
  { return rational_t( nu*b.de-de*b.nu, de*b.de ); }
  rational_t operator-() { return rational_t(-nu, de); }
  rational_t operator*(const rational_t& b) const
  { return rational_t( nu*b.nu, de*b.de ); }
  rational_t operator/(const rational_t& b) const
  { return rational_t( nu*b.de, de*b.nu ); }
  bool operator == (const rational_t & b) const {return nu * b.de == b.nu * de;}
  bool operator == (const int &k) const { return nu == k * de; }
  bool operator < (const rational_t& b) const { return nu * b.de < b.nu * de; }
};
////////////////////////////////////////////////////////////////////////////////
// Extended GCD
////////////////////////////////////////////////////////////////////////////////
// Find x,y such that ax + by = d = gcd(a,b)
//   * a^-1 (mod m): if (egcd(a,m,x,y) == 1) return (x+m)%m; else ERROR;
ll egcd(ll a, ll b, ll& x, ll &y) {
  if (!b) {x = 1; y = 0; return a;}//to ensure d>=0: x=sgn(a);y=0;return abs(a);
  ll d = egcd(b, a%b, y, x); y -= x * (a/b);
  return d; }
////////////////////////////////////////////////////////////////////////////////
// Extended GCD in canonical form
////////////////////////////////////////////////////////////////////////////////
// Assuming a != 0, find smallest y >= 0 such that ax + by = c (if possible)
bool canon_egcd(ll a, ll b, ll c, ll& x, ll& y) {
  ll d = egcd(a, b, x, y), z = abs(a/d);
  if (c%d) return false;
  y = (y*(c/d)%z + z)%z, x = (c - b*y)/a;
  return true; }
////////////////////////////////////////////////////////////////////////////////
// Chinese remainder theorem
////////////////////////////////////////////////////////////////////////////////
// z % m1 == a1, z % m2 == a2, 0 <= a1 < m1, 0 <= a2 < m2
// Return true and 0 <= A < M if possible, false otherwise
bool chin_rem(ll a1, ll m1, ll a2, ll m2, ll& A, ll& M) {
  ll X1, X2, d = egcd(m1, m2, X1, X2);
  if (a1 % d != a2 % d) return false;
  M = m1/d*m2, A = ((X1*m1%M*(a2/d) + X2*m2%M*(a1/d) + a1%d)%M + M)%M;
  return true; }
////////////////////////////////////////////////////////////////////////////////
// Linear Diophantine Equation Solver
////////////////////////////////////////////////////////////////////////////////
// Linear Diophantine Equation Solver for any number of variables
// Author: Adam Beacham & Howard Cheng
// Given the linear equation with integer coefficients a[i]:
//    a[0]*x_0 + a[1]*x_1 + . . . + a[n-1]*x_n-1 = c
// It is assumed that no coefficient is 0.
// Determines whether integer solutions exist.  If they do,
// provides a specific solution for the variables in the array sol.
// (sol is viewed as an n-dimensional vector).
// Then bas[0], bas[1], . . ., bas[n-1] are basis vectors for the integer
// solutions for the homogeneous equation:
//    a[0]*x_0 + a[1]*x_1 + . . . + a[n-1]*x_n-1 = 0
// (Each bas[i] is an n-vector).
// Thus, all solutions are given by:
//  (x_0, . . ., x_n-1) = sol + t_0*bas[0] + . . . + t_{n-1}*bas[n-1]
// where t_0, . . ., t_{n-1} are arbitrary integers.
ll gcd_solve(ll a[MAX_VAR], int numV, ll sol[MAX_VAR],
              ll bas[MAX_VAR-1][MAX_VAR]){
  ll ret, d, v, i;
  if( numV == 2 ) {
    ret = egcd(a[0],a[1],sol[0],sol[1]);
    bas[0][0] = a[1]/ret;
    bas[0][1] = -a[0]/ret;
  } else if( numV > 2 ) {
    d = gcd_solve(a,numV-1,sol,bas);
    ret = egcd(d,a[numV-1],v,sol[numV-1]);
    for( i=0; i<numV-1; i++ ) {
      bas[numV-2][i] = a[numV-1]/ret * sol[i];
      sol[i] *= v;
    }
    bas[numV-2][numV-1] = -d/ret;
  } return ret; }
bool diophantine(ll a[MAX_VAR], int numV, ll c, ll sol[MAX_VAR],
                ll bas[MAX_VAR-1][MAX_VAR]){
  assert(numV > 1); int i,j,d,q;
  for( i=0; i<numV; i++ ) assert( a[i] != 0 );
  for( i=0; i<numV-1; i++ ) for( j=0; j<numV; j++ )
      bas[i][j] = 0;
  d = gcd_solve(a,numV,sol,bas);
  if( c % d == 0 ) {
    q = c/d;
    for( i=0; i<numV; i++ ) sol[i] *= q;
    return true;
  } return false; }
////////////////////////////////////////////////////////////////////////////////
// Legendre symbol
////////////////////////////////////////////////////////////////////////////////
// There exists x, s.t. x^2=a(mod p) (p prime) iff L(a, p)>=0
// note L(a, p) * L(b, p) = L(a*b, p)
inline int legendre( int a, int p ) {
  return (a%p)?(modpow(a, (p-1)/2, p ) == 1 ? 1 : -1):0;}
////////////////////////////////////////////////////////////////////////////////
// Modular Exponentiation
////////////////////////////////////////////////////////////////////////////////
ll modpow(ll a, ll p, ll M) { // assumes M > 1
  ll r; for (r = 1; p; a = (a*a)%M, p /= 2) if (p%2) r = (r*a)%M; return r; }
////////////////////////////////////////////////////////////////////////////////
// Discrete Log
////////////////////////////////////////////////////////////////////////////////
// returns smallest x such that a^x == b (mod M) or -1 if
// no such x exists. O(sqrt(M)*log(sqrt(M))), faster if using hashing.
struct HLL{size_t operator()(const ll a)const{return(int)(a^(a>>32));}}; // hash
ll modlog(ll a, ll b, ll M) {
  ll s = (ll)sqrt(M), p, i;
  while (s*s < M) ++s;
  map<ll, ll> H;
  for (i = 0, p = 1; i < s; ++i, p = (p*a)%M)
    if (!H.count(p))
      H[p] = i;
  for (i = 0, p = modpow(a, M-1-s, M); i < s; ++i, b = (b*p)%M)
    if (H.count(b))
      return i*s+H[b];
  return -1;}
////////////////////////////////////////////////////////////////////////////////
// Polynomial GCD
////////////////////////////////////////////////////////////////////////////////
// returns a, b such that ax = by in the field we're talking about
inline void solve(int x, int y, int& a, int& b);
// polynomial coefficients are in decreasing order of exponents
inline vi operator % (const vi& p, const vi& q) {
  vi copy = p; int diff = (int)p.size() - (int)q.size(), a, b;
  for (int i = 0; i <= diff; ++i) { solve(q[0], copy[i], a, b);
    for (int j = 0; j < p.size(); ++j) copy[j] *= b;
    for (int j = 0; j < q.size(); ++j) copy[i+j] -= a*q[j]; }
  return remove_leading_zero(copy); } // 00002342 -> 2343; 0 -> 0
vi gcd(const vi &p, const vi &q){return q.size()==1 && !q[0] ? p : gcd(q,p%q);}
////////////////////////////////////////////////////////////////////////////////
// Polynomial Root
////////////////////////////////////////////////////////////////////////////////
pol ruffini(const pol &p, pt r){ // returns p(x)/(x-r)
  int deg = (int)p.size()-1; pol ret(deg); ret[deg-1] = p[deg];
  for (int i = deg-2; i >= 0; --i) ret[i] = p[i+1] + ret[i+1]*r;
  return ret; } // if want remainder: p[0] + ret[0]*r
pol poly_roots(pol poly) { // poly[i] is the coefficient for x^i
  const int NUM_ITR = 25; // change as needed
  const ld tol = 1E-12; // change as needed
  pol ret; pt init_guess = 1; // initial guess
  while (poly.size() > 1) {
    int deg = poly.size() - 1; pt curr = init_guess, val, fd, sd;
    for (int itr = 0; itr <= NUM_ITR; itr++) { val = fd = sd = 0;
      for (int i = poly.size()-1; i >= 0; i--) {
	val *= curr; val += poly[i];
	if (i > 0) fd *= curr; fd += ((ld) i) * poly[i];
	if (i > 1) sd *= curr; sd += ((ld) (i * (i-1))) * poly[i]; }
      if (abs(val) < tol) break;
      pt g = fd/val; pt h = g*g - sd/val;
      pt disc = ((ld)(deg - 1))*(((ld) deg)*h-g*g);
      pt dp = g + sqrt(disc); pt dn = g - sqrt(disc);
      if (abs(dn)<abs(dp)) curr-=((ld) deg)/dp; else curr-=((ld) deg)/dn; }
    if (abs(val) < tol){ ret.pb(curr); poly = ruffini(poly,curr); }
    else init_guess *= -2; } // change as needed
  return ret; }
////////////////////////////////////////////////////////////////////////////////
// Pythagorean triples
////////////////////////////////////////////////////////////////////////////////
typedef struct { int a, b, c; } ptrip;
int gen_triples(int n, ptrip *res) {
  int a, b, p, q, cnt = 0;
  for (p = 2; p*p < n; p++) {
    for (q = 1+p%2; q < p && p*p+q*q < n; q += 2) {
      if (gcd(p,q)!=1) continue;
      a = p*p-q*q;
      b = 2*p*q;
      if (a < b) { res[cnt].a = a; res[cnt].b = b; }
      else       { res[cnt].a = b; res[cnt].b = a; }
      res[cnt++].c = p*p+q*q;
    } } return cnt; }
////////////////////////////////////////////////////////////////////////////////
// Farey Sequences
////////////////////////////////////////////////////////////////////////////////
vpii farey(int n){
  vpii res; int a = 0, b = 1, c = 1, d = n, k; res.push_back(make_pair(0,1));
  while(c<n){ k = (n+b)/d,swap(a,c),swap(b,d),c = k*a-c,d = k*b-d;
              res.push_back(make_pair(a,b)); }
  if(n==1)res.push_back(make_pair(1,1)); return res; }
////////////////////////////////////////////////////////////////////////////////
// Conic section solver
////////////////////////////////////////////////////////////////////////////////
// - Can determine LINE (2), CIRCLE (3), PARABOLA (3), ELLIPSE (4).
// - Assume the points are given as (x1,y1), (x2,y2), ...
// - First row represents variables
// (1) LINE (2 points)
// Eq: c1*x + c2*y + c3 = 0
//   |[[x  y  1] |
//   | [x1 y1 1] | = 0
//   | [x2 y2 1]]|
//
// (2) CIRCLE (3 points)
// Eq: c1*(x^2+y^2) + c2*x + c3*y + c4 = 0
//   |[[x^2+y^2     x   y   1] |
//   | [x1^2+y1^2   x1  y1  1] | = 0
//   | [x2^2+y2^2   x2  y2  1] |
//   | [x3^2+y3^2   x3  y3  1]]|
// --Circle is *undefined* when c1 == 0
// --Solve to standard equation (x-x1)^2+(y-y1)^2=r^2 to check for
//   other undefined cases. (like r^2 < 0).
//
// (3) PARABOLA (3 points)
// Eq: (Type 1 -- up-down)    c1*x^2 + c2*x + c3*y + c4 = 0
//   |[[x^2  x   y   1] |
//   | [x1^2 x1  y1  1] | = 0
//   | [x2^2 x2  y2  1] |
//   | [x3^2 x3  y3  1]]|
//
// Eq: (Type 2 -- left-right) c1*y^2 + c2*x + c3*y + c4 = 0
//   |[[y^2   x   y   1] |
//   | [y1^2  x1  y1  1] | = 0
//   | [y2^2  x2  y2  1] |
//   | [y3^2  x3  y3  1]]|
//
// (4) ELLIPSE (4 points)
// Eq: c1*x^2 + c2*y^2 + c3*x + c4*y + c5 = 0
//   |[[x^2   y^2    x   y   1] |
//   | [x1^2  y1^2   x1  y1  1] |
//   | [x2^2  y2^2   x2  y2  1] | = 0
//   | [x3^2  y3^2   x3  y3  1] |
//   | [x4^2  y4^2   x4  y4  1]]|
// --Ellipse is *undefined* when c1==0 OR c2==0
// --Let D   := c3*c3/4.0/c1 + c4*c4/4.0/c2 - c5;
//   and ax1 := D/c1, ax2 := D/c2;
// --Ellipse is *undefined* if ax1 <= 0 OR ax2 <= 0
// --Otherwise, can represent by  x^2/ax1 + y^2/ax2 = 1
// --AREA of ellipse = Pi*sqrt(ax1)*sqrt(ax2)
////////////////////////////////////////////////////////////////////////////////
// Adaptive Simpsons Integrator (TESTED on SPOJ VCIRCLES - not the latest version trololol)
////////////////////////////////////////////////////////////////////////////////
//usage: f - function to be integrated, simfull - sim(l,r)
ld sim(ld l, ld r) { return (f(l) + f(r) + 4*f((l+r)/2)) * (r-l) / 6; }
ld adaptive_sim(ld l, ld r, ld simfull) { ld m = (l+r)/2;
  ld siml = sim(l,m), simr = sim(m,r);    ld cor = (siml+simr-simfull)/15;
  if (abs(cor) < EPS) return siml + simr + cor;
  return adaptive_sim(l,m,siml) + adaptive_sim(m,r,simr); }
////////////////////////////////////////////////////////////////////////////////
// Simplex
////////////////////////////////////////////////////////////////////////////////
// Simon Lo's (TESTED)
//   Simplex algorithm on augmented matrix a of dimension (m+1)x(n+1)
//	 first m rows describe constraints, last row describes objective function.
//   returns 1 if feasible, 0 if not feasible, -1 if unbounded
//   returns solution in b[] in original var order, max(f) in ret
//   form: maximize sum_j(a_mj*x_j)-a_mn s.t. sum_j(a_ij*x_j)<=a_in
//   in standard form.
//   To convert into standard form:
//   1. if exists equality constraint, then replace by both >= and <=
//   2. if variable x doesn't have nonnegativity constraint, then replace by
//      difference of 2 variables like x1-x2, where x1>=0, x2>=0
//   3. for a>=b constraints, convert to -a<=-b
//	 4. turn minimizing condition into maximizing by multiplying -1 to obj.func.
//   note: watch out for -0.0 in the solution, algorithm may cycle
//   EPS = 1e-7 may give wrong answer, 1e-10 is better
//   On average, simplex is O( m * log n). If there are many equations and few
//   variables, its more efficient to use the dual:
//   normal: max c^T*x, s.t. Ax <= b <---> dual: min b^T*y, s.t. A^T*y >= c.
void pivot(int m,int n,ld a[MAXM][MAXN],
           int B[MAXM],int N[MAXN],int r,int c) {
  int i,j;
  swap(N[c],B[r]);
  a[r][c]=1/a[r][c];
  for(j=0;j<=n;j++) if(j!=c) a[r][j]*=a[r][c];
  for(i=0;i<=m;i++)
    if(i!=r) {
      for(j=0;j<=n;j++) if(j!=c) a[i][j]-=a[i][c]*a[r][j];
      a[i][c] = -a[i][c]*a[r][c];
    }
}
int feasible(int m,int n,ld a[MAXM][MAXN],int B[MAXM],int N[MAXN]) {
  int r,c,i;
  ld p,v;
  while(1) {
    for(p=INF,i=0; i<m; i++) if(a[i][n]<p) p=a[r=i][n];
    if(p>-EPS) return 1;
    for(p=0,i=0; i<n; i++) if(a[r][i]<p) p=a[r][c=i];
    if(p>-EPS) return 0;
    p = a[r][n]/a[r][c];
    for(i=r+1; i<m; i++)
      if(a[i][c]>EPS) {
        v = a[i][n]/a[i][c];
        if(v<p) r=i,p=v;
      }
    pivot(m,n,a,B,N,r,c);
  } }
int simplex(int m,int n,ld a[MAXM][MAXN],ld b[MAXN],ld& ret) {
  int B[MAXM],N[MAXN],r,c,i;
  ld p,v;
  for(i=0; i<n; i++) N[i]=i;
  for(i=0; i<m; i++) B[i]=n+i;
  if(!feasible(m,n,a,B,N)) return 0;
  while(1) {
    for(p=0,i=0; i<n; i++) if(a[m][i]>p) p=a[m][c=i];
    if(p<EPS) {
      for(i=0; i<n; i++) if(N[i]<n) b[N[i]]=0;
      for(i=0; i<m; i++) if(B[i]<n) b[B[i]]=a[i][n];
      ret = -a[m][n];
      return 1;
    }
    for(p=INF,i=0; i<m; i++)
      if(a[i][c]>EPS) {
        v = a[i][n]/a[i][c];
        if(v<p) p=v,r=i;
      }
    if(p==INF) return -1;
    pivot(m,n,a,B,N,r,c); } }
////////////////////////////////////////////////////////////////////////////////
// Linear algebra (go Matthew!)
////////////////////////////////////////////////////////////////////////////////
// Should support Gaussian Elimination, finding determinant,
// feasibility testing, maximization LP, constructing dual, etc.
// -- gaussian(sys) : Use Gaussian Jordan elimination to solve a system
// -- det(M) : Use Gaussian Jordan elimination to find the determinant
// -- gauss_sol(M, x) : returns a vector of boolean denoting free
//    variables. In x, return the assignment if all free variables are 0.
#define ISZERO(x) (fabs(x) < EPS)
#define ISPOS(x) ( x > EPS )
void pivot(vvd& A, int r, int c) { // A is A|b
  int m = A.size(), n = A[0].size();
  ld tmp = A[r][c];
  for (int i = 0; i < n; ++i) A[r][i]/=tmp;
  for (int i = 0; i < m; ++i)
    if (i != r) {
      ld k = A[i][c];
      for(int j = 0; j < n; ++j)
        A[i][j] -= A[r][j]*k;
    }
}
bool gaussian(vvd& A) {
  int m = A.size(), n = A[0].size() - 1;
  vector<bool> used(m, 0);
  for (int c = 0; c < n; ++c)
    for (int r = 0; r < m; ++r)
      if (!used[r] && !ISZERO(A[r][c]) ) {pivot(A, r, c); used[r] = true; }
  for (int r = 0; r < m; ++r) if(!used[r] && !ISZERO(A[r].back())) return false;
  return true;
}
// Return the assignment to each x. Free variables are always 0
vector<bool> gauss_sol(const vvd& coef, vd&x) {
  int m = coef.size(), n = coef[0].size()-1;
  vector<bool> ret(n, 0);
  for (int i = 0; i < n; ++i) {
    x[i]=0;
    if (ret[i]) continue;
    int cnt = 0;
    for (int j = 0; j < m; ++j) // Exactly one 1
      if ( !ISZERO(coef[j][i]) ) ++cnt;
    if (cnt != 1) { ret[i] = true; continue; }
    for (int j = 0; j < m; ++j)
      if (ISZERO( coef[j][i] - 1 ) ) {
        x[i] = coef[j].back();
        for (int k = i+1; k < n; ++k)
          if (!ISZERO( coef[j][k] )) ret[k] = true;
        break;
      }
  }
  return ret; }
////////////////////////////////////////////////////////////////////////////////
// Matrix determinant
////////////////////////////////////////////////////////////////////////////////
ld det(vvd& A) { // Find the determinant by gauss. elim., destroys matrix.
  if (A.size() != A[0].size()) return 0;
  int n = A.size(), j;
  ld ret = 1;
  for (int i = 0; i < n; ++i) {
    for (j = i; j < n; ++j) if (!ISZERO( A[j][i] )) {
      if (j != i) { A[j].swap(A[i]); ret = ret * -1; }
      ret = ret * A[i][i]; pivot(A, i, i);
      break;
    }
    if (j == n) return 0;
  }
  return ret; }
////////////////////////////////////////////////////////////////////////////////
// Stupid determinant
////////////////////////////////////////////////////////////////////////////////
const int NN = 5;
// Finds determinant of a NN by NN matrix
// Given a square matrix mat, finds the determinant of the sub-matrix
// using all rows R >= r, and not use any column C where (cmsk&(1<<C))
ld determinant( ld mat[NN][NN], int cmsk, int r ){
  if ( r == NN ) return 1;
  ld s = -1, d=0;
  for (int i=0; i<NN; i++) if ( ~cmsk&(1<<i) )
    d += (s*=-1)*mat[r][i] * determinant( mat, cmsk|(1<<i), r+1 );
  return d; }
////////////////////////////////////////////////////////////////////////////////
// FFT
////////////////////////////////////////////////////////////////////////////////
// *** Fast Fourier Transform (Recursive) ***
typedef complex<ld> Complex;
// Forward Transform - Make sure you have enough leading zeros
// when using this, add n leading zeros to a vector of length n
vector<Complex> rfft(vector<Complex> a, int sign=1){
  if(a.size() == 1) return a;
  Complex wn = exp(Complex(0, sign*2*PI/a.size()));
  Complex w(1, 0);
  vector<Complex> a0, a1, y0, y1, y(a.size());
  for(unsigned i = 0; i < a.size(); i += 2) a0.push_back(a[i]);
  for(unsigned i = 1; i < a.size(); i += 2) a1.push_back(a[i]);
  y0 = rfft(a0, sign);
  y1 = rfft(a1, sign);
  for(unsigned k = 0; k < a.size()/2; k++){
    y[k] = y0[k] + w*y1[k];
    y[k + a.size()/2] = y0[k] - w*y1[k];
    w = w*wn;
  }
  return y;
}
// Inverse Transform - this time you don't care about adding zeros, but
//    make sure to normalize the number.  FFT actually multiplies polynomials
vector<Complex> ifft(vector<Complex> a){
  vector<Complex> out = rfft(a, -1);
  for(unsigned i = 0; i < out.size(); i++) out[i] /= out.size();
  return out;
}
// *** Fast Fourier Transform (Iterative) ***
// Reverse-bitmasking adder. rev(a,n) returns REV(REV(a)+1)
inline int rev(int a, int n){
  int msk = n/2, cnt=0;
  while ( a&msk ) { cnt++; a<<=1; }
  a &= msk-1;
  a |= msk;
  while ( cnt-- ) a >>= 1;
  return a;
}
// Compute in V the fourier transform of v
// forw=1: forward, forw=-1: inverse
void FFT( vector<Complex> &v, vector<Complex> &V, int forw=1 ){
  Complex om,w,u,t;
  int n = v.size(), a=0;
  V.resize(n);
  for (int k=0; k<n; k++, a=rev(a,n))
    V[a] = v[k] / ld(forw>0? 1.0:n);
  for (int m=2; m<=n; m<<=1) {
    om = polar( (ld)1.0, forw*2*PI/m );
    for (int k=0; k<n; k+=m) {
      w = 1;
      for (int j=0; j<m/2; j++, w*=om) {
        u = V[k + j];
        t = w * V[k + j + m/2];
        V[k + j] = u + t;
        V[k + j + m/2] = u - t;
      } } } }
// *** BigInt multiply using FFT ***
// Multiply two numbers a and b, define low-order first (eg. 123={3,2,1})
vector<int> multiply( vector<int> &a, vector<int> &b ){
  int nd = max(a.size(),b.size());
  int n  = 1<<int(ceil(log2(nd*2.0)));
  vector<Complex> av(n,0), bv(n,0), cv;
  for (unsigned i=0; i<a.size(); i++) av[i] = a[i];
  for (unsigned i=0; i<b.size(); i++) bv[i] = b[i];
  FFT( bv, cv ); // FFT transform
  FFT( av, bv );
  for (int i=0; i<n; i++) av[i] = bv[i]*cv[i];
  FFT( av, cv, -1 ); // reverse FFT
  // Evaluation at x=10
  vector<int> c(n);
  int acc = 0, sz=1;
  for (int i=0; i<n; i++, acc/=10) {
    acc += int(cv[i].real()+0.5);
    c[i] = acc%10;
    if ( c[i] ) sz = i+1;
  }
  c.resize(sz);
  return c; }
////////////////////////////////////////////////////////////////////////////////
// Suffix array - O(L lg^2 L) construction (TESTED on L.A. 2755)
////////////////////////////////////////////////////////////////////////////////
//suffix[i] = idx of suffix s[i..L] in list of sorted suffixes
#define mp make_pair
struct suff_array {
  const int L; string s; int i, skip, lvl;
  vector<vi> P; vector<pair<pii,int> > M;
  suff_array(const string &s) : L(s.size()), s(s), P(1, vi(L, 0)), M(L) {
    for (i = 0; i < L; i++) P[0][i] = int(s[i]);
    for (skip = 1, lvl = 1; skip < L; skip *= 2, lvl++) {
      P.push_back(vi(L, 0));
      for (int i = 0; i < L; i++)
	      M[i] = mp(mp(P[lvl-1][i], i+skip<L ? P[lvl-1][i + skip] : -1000), i);
      sort(M.begin(), M.end());
      for (int i = 0; i < L; i++)
	      P[lvl][M[i].second] = (i > 0 && M[i].first == M[i-1].first) ?\
	                            P[lvl][M[i-1].second] : i; }
  }
  const vector<int>& get_sarray() { return P.back(); }
  //returns len of longest common prefix of s[i...L-1] and s[j...L-1], O(lg L)
  int lcp(int i, int j) {
    int len = 0; if (i == j) return L - i;
    for (int k = P.size() - 1; k >= 0 && i < L && j < L; k--)
      if (P[k][i] == P[k][j]) { i += 1 << k; j += 1 << k; len += 1 << k;}
    return len;
  }
}; //! code adapted from the Stanford Team Notebook
////////////////////////////////////////////////////////////////////////////////
// Suffix Array - O(N) construction, TESTED (SWERC09J)
////////////////////////////////////////////////////////////////////////////////
//sa[i] is the starting index of the ith suffix in the sorted suffix array
//inv[i] is the ranking of s[i..L] in the sorted suffix array, inverse of sa
//lcp[i] is the lcp of suffix i-1 and i in the sorted suffix array, lcp[0] = 0
struct suff_arr {
  // integer rep, suffix array, inverse array, adjacent lcp
  vi t, sa, inv, lcp; int N;
  suff_arr(const string& s) : N(s.size()) {
    sa.resize(N); t.resize(N + 3); lcp.resize(N); inv.resize(N);
    for (int i = 0; i < N; i++) t[i] = s[i];
    if (N < 3) { if (N == 2) { sa[(t[0] > t[1])] = 1; } }
    else build(t, sa, N, 128);
    genHeight(); }
  void build(vi& T, vi& sa, int n, int K) {
    int n0 = (n + 2) / 3, n1 = (n + 1) / 3, n2 = n / 3, n02 = n0 + n2;
    vi r(n02 + 3), sa12(n02 + 3), r0(n0), sa0(n0);
    for (int i = 0, j = 0; i < n + n0 - n1; i++) if (i % 3 != 0) r[j++] = i;
    pass(r, sa12, T, 2, n02, K);
    pass(sa12, r, T, 1, n02, K);
    pass(r, sa12, T, 0, n02, K);
    int name = 0, c0 = -1, c1 = -1, c2 = -1;
    for (int i = 0; i < n02; i++) {
      if (T[sa12[i]] != c0 || T[sa12[i] + 1] != c1 || T[sa12[i] + 2] != c2) {
        name++;
        c0 = T[sa12[i]]; c1 = T[sa12[i] + 1]; c2 = T[sa12[i] + 2];
      }
      r[(sa12[i] % 3 == 1 ? 0 : n0) + sa12[i] / 3] = name;
    }
    if (name < n02) {
      build(r, sa12, n02, name);
      for (int i = 0; i < n02; r[sa12[i]] = ++i); //semicolon
    } else for (int i = 0; i < n02; sa12[r[i] - 1] = i++); //semicolon
    for (int i = 0, j = 0; i < n02; i++) 
      if (sa12[i] < n0) r0[j++] = 3 * sa12[i];
    pass(r0, sa0, T, 0, n0, K);
    for (int p = 0, t = n0 - n1, k = 0; k < n; k++) {
      int i = sa12[t] < n0 ? (sa12[t]*3+1) : ((sa12[t]-n0)*3+2), j = sa0[p];
      if (sa12[t] < n0 ? leq(T[i], r[sa12[t] + n0], 0, T[j], r[j / 3], 0)
          : leq(T[i], T[i+1], r[sa12[t]-n0+1], T[j], T[j + 1], r[j/3 + n0])) {
        sa[k] = i;
        if (++t == n02) for (k++; p < n0; sa[k++] = sa0[p++]); //semicolon
      } else {
        sa[k] = j;
        if (++p == n0)
          for (k++; t < n02; sa[k++] = sa12[t] < n0 ? (sa12[t++] * 3 + 1)
              : ((sa12[t++] - n0) * 3 + 2));
      } } }
  bool leq(int a1, int a2, int a3, int b1, int b2, int b3) {
    return a1 < b1 || a1==b1 && a2 < b2 || a1 == b1 && a2 == b2 && a3 <= b3; }
  void pass(vi& a, vi& b, vi& r, int off, int n, int k) {
    vi c(k + 1);
    for (int i = 0; i < n; c[r[a[i++] + off]]++);
    for (int i = 1; i <= k; i++) c[i] += c[i - 1];
    for (int i = 0; i < n; c[r[a[i++] + off]]--);
    for (int i = 0; i < n; b[c[r[a[i] + off]]++] = a[i++]); }
  void genHeight() {
    for (int i = 0; i < N; i++) inv[sa[i]] = i;
    for (int i = 0, h = 0; i < N; i++)
      if (inv[i] > 0) {
        int j = sa[inv[i] - 1];
        while (i + h < N && j + h < N && t[i + h] == t[j + h]) h++;
        lcp[inv[i]] = h;
        if (h > 0) h--;
      } }
}; //from Antony at UCF
////////////////////////////////////////////////////////////////////////////////
// Suffix tree
////////////////////////////////////////////////////////////////////////////////
// Set _A to smallest in alphabet, or to 0 and fit alphabet in [0,ALPHA_SIZE)
const int ALPHA_SIZE=26; char _A='a', _$=_A+ALPHA_SIZE;
int DIM1=(int)sqrt(ALPHA_SIZE+1), DIM2=ceil((ALPHA_SIZE+1.0)/DIM1);
struct edge; typedef vector<vector<edge*> > vve;
struct edge {
  string &s; int begin, end; vve child; edge *sfxlink, *parent;
  edge(string &ss, int b=0, int e=0) : s(ss), begin(b), end(e) {
    parent=NULL, sfxlink=NULL; }
  inline edge* get_child(char c) { int id=c-_A;
    if(!child.size() || !child[id/DIM2].size()) return NULL;
    return child[id/DIM2][id%DIM2]; }
  edge* set_child(char c, edge *chld){ int id=c-_A;
    if(!child.size()) child=vve(DIM1);
    if(!child[id/DIM2].size()) child[id/DIM2] = vector<edge*>(DIM2,(edge*)NULL);
    chld->parent=this; return child[id/DIM2][id%DIM2] = chld; }
  ~edge() {
    for(int i=0; i<child.size(); i++) for (int j=0; j<child[i].size(); j++)
	  delete child[i][j];
    child.clear(); } };
// assumptions: e->parent is a root or has a suffix link; pe != 0, pe <= diff
void get_suffix(edge *&e, int &ep, int sp){ // s[e->begin + ep] == s[sp]
  if((e = e->parent)->sfxlink) e = e->sfxlink, ep += (e->end - e->begin);
  else ep--; //root
}
void walk_down(edge *&e, int &ep, int sp){
  while(ep > e->end - e->begin){
    ep -= (e->end - e->begin);
    e = e->get_child(e->s[sp - ep]);
  } }
// don't worry about anything above this function except setting _A
edge *build_tree(string &s){ // assume non-zero length for s
  edge *t=new edge(s), *cur=t->set_child(s[0], new edge(s, 0, 1<<30));
  for(int phase=1, pos=1, f=1; phase<s.size(); phase++, pos++){
    edge **need_sfxlink=NULL;
    while(true){
      if(f) get_suffix(cur, pos, phase);
      f = 1; walk_down(cur, pos, phase);
      if(cur->end == (1<<30) && pos + cur->begin == phase) continue;
      if((cur->end - cur->begin > pos && s[cur->begin + pos] == s[phase]) ||
	     (cur->end - cur->begin == pos && cur->get_child(s[phase]))){
	       if(need_sfxlink) *need_sfxlink = cur, need_sfxlink = NULL;
	       f = 0; break;
      }
      if(cur->end - cur->begin > pos){
        edge *parent = cur->parent;
	    edge *oedge = new edge(s, cur->begin, cur->begin + pos);
	    if(need_sfxlink) *need_sfxlink = oedge, need_sfxlink = NULL;
        cur->begin = oedge->end;
	    oedge->set_child(s[oedge->end], cur);
	    need_sfxlink = &oedge->sfxlink; // need to set the other child...
	    parent->set_child(s[oedge->begin], oedge);
	    oedge->set_child(s[phase], new edge(s, phase, 1<<30));
	    cur = oedge;
      } else {
	    cur->set_child(s[phase], new edge(s, phase, 1<<30));
	    if(need_sfxlink) *need_sfxlink = cur, need_sfxlink = NULL;
      }
      if(cur->parent == NULL) { f = 0; break; }
    }
  }
  return t;
}
edge *get_state(edge *tree, int &pos, char ch){
  if(!tree) return NULL;
  if(pos < tree->end){   // inside edge
    if(pos < tree->s.size() && ch == tree->s[pos]) pos++;
    else tree = NULL;
  }else{                 // right on leaf
    if(tree->get_child(ch))
      tree = tree->get_child(ch), pos = tree->begin + 1;
    else tree = NULL;
  } return tree;
}
bool hasSuffix(string s, string suffix) { // trivial function as example.
  s += _$; suffix += _$;
  edge *tree = build_tree(s); int pos=0;
  for (int i=0; i < suffix.size(); i++)
    if (!(tree=get_state(tree, pos, suffix[i]))) return false;
  return pos == s.size(); } // matched at [pos-s.size(),pos)
////////////////////////////////////////////////////////////////////////////////
// Palindrome substrings in O(n)
////////////////////////////////////////////////////////////////////////////////
int lengths[2*MAXN-1]; // length of palindrome centred at s[i] is lengths[2*i]
void find_pals(const string& s) {
  lengths[0] = 1, lengths[1] = 0;
  for (int d, i = 1; i+2 < 2*s.length(); i += d) {
    int& p = lengths[i];
    int left = (i - p - 1)/2, right = (i + p + 1)/2;
    while (0 <= left && right < s.length() && s[left] == s[right])
        --left, ++right, p += 2;
    for (d = 1; lengths[i-d] < p-d; ++d)
        lengths[i+d] = lengths[i-d];
    lengths[i+d] = p-d; } }
////////////////////////////////////////////////////////////////////////////////
// KMP string matching - O(n+m)
////////////////////////////////////////////////////////////////////////////////
// t is the string to search in, p is the substring to search for
void kmp_init(string p, int* fail) {
  for (int i=0, j=-1, m=p.size(); ; ++i, ++j) {
	fail[i] = j; if (i == m) return;
	while (j>=0 && p[i]!=p[j]) j = fail[j];
} } // fail[i] = len of longest proper suffix that's also a prefix in s[0...i-1]
vector<int> kmp_match(string t, string p) {
  int n=t.size(),m=p.size(),fail[m+1]; kmp_init(p,fail); vector<int> matches;
  for (int i=0, j=0; ; ++i, ++j) {
    if (j == m) matches.push_back(i-j), j = fail[j];
    if (i == n) return matches;
    while (j>=0 && t[i]!=p[j]) j = fail[j];
} return matches; }
////////////////////////////////////////////////////////////////////////////////
// Z-value string matching - O(n+m), tested on WF2012-D, SPOJ QUERYSTR
////////////////////////////////////////////////////////////////////////////////
//z[i]- len of the longest substring at s[i] that is a prefix of s.
//i.e. s[0..z[i]] == s[i...i+z[i]]
//for string matching: prepend query str to beginning of the str being searched
//over and look for z[i] >= query.length(). the match is s[i...i+query.length()]
void build_zval(const string& s) { //INITIALIZE AND MEMSET z[M+N] BEFORE CALLING
	int L = 0, R = 0; int n = s.size(); z[0] = n;
	for (int i = 1; i < n; i++) {
		if (i > R) { L = R = i;
      while (R < n && s[R-L] == s[R]) R++;
			z[i] = R-L; R--;
		} else {
			if (z[i-L] < R-i+1) z[i] = z[i-L];
      else { L = i; while (R < n && s[R-i] == s[R]) R++; z[i] = R-L; R--;}
    } } }
////////////////////////////////////////////////////////////////////////////////
// Aho Corasick ; bfs to build suffix/failure links on existing trie.
////////////////////////////////////////////////////////////////////////////////
// Watch out for duplicated queries! Build your own trie on input data first.
// Set index to NONZERO id of pattern that ends in that node.
// Initialize all ptrs to 0. Remember destructor and to delete stuff.
struct node { node* l[26], *failure, *suffix; int index; };
void build_links(node* root) { queue<node*> que; que.push(root);
  while (!que.empty()) { node* p = que.front(); que.pop();
    for (int i=0; i<26; ++i) if (p->l[i]) { node* q = p->failure;
      while (q && !q->l[i]) q = q->failure;
      if (q) { p->l[i]->failure = q->l[i];
        p->l[i]->suffix = (q->l[i]->index ? q->l[i] : q->l[i]->suffix);
      } else p->l[i]->failure = p->l[i]->suffix = root;
    que.push(p->l[i]); } } }
set<int> get_matches(string &s, node* root) { set<int> ids; node* cur = root;
  for (int i=0; i < s.size(); i++) { int c=s[i]-'a';
    while(cur != root && !cur->l[c]) cur = cur->failure;
    if (cur->l[c]) cur = cur->l[c];
    node* dict = cur; while (dict != root) {
      if (dict->index) id.insert(dict->index); dict = dict->suffix; } }
  return ids; }
////////////////////////////////////////////////////////////////////////////////
// Array-based undirected sparse graph : the reverse of edge i is i^1
////////////////////////////////////////////////////////////////////////////////
int first[N]; // first[node] is the first edge in the adjacency list of node
int next[M];  // next[i] is the next edge in the same adjacency list as edge i
int ep[M];    // ep[i] and ep[i^1] are the start and end nodes of edge i

memset(first, -1, sizeof first); // edges are input as pairs of endpoints
for(int i=0; i<2*m; ++i) cin >> ep[i], next[i] = first[ep[i]], first[ep[i]] = i;
////////////////////////////////////////////////////////////////////////////////
// Maximum flow (HOUOUIN KYOUMA EDITION!!!!)
////////////////////////////////////////////////////////////////////////////////
int vis[N],par[N],first[N],next[2*M],ep[2*M],m,e;
ll pot[N],dist[N],flo[2*M],cap[2*M],cost[2*M];

void init() { m = 0; memset(first,-1,sizeof first); memset(flo,0,sizeof flo); }
void add_edge(int a, int b, ll c=1, ll p=0) { //a,b - nodes, c, p - cap, price
  next[m] = first[ep[m]=a], first[ep[m]] = m, cap[m] = c, cost[m++] =  p;
  next[m] = first[ep[m]=b], first[ep[m]] = m, cap[m] = 0, cost[m++] = -p; }

// Max flow without costs, USAGE: 1) init(); 2) add edges, 3) ll flow=0; and 4)
// for (ll del=INF; del; del/=2) while (ll df=mf_update(s, t, del)) flow+=df;
// Then if you want to extract a min cut: for (e = 0; e < m; ++e)
// if (par[ep[e]] != -1 && par[ep[e^1]] == -1) cut.push_back(e);
ll mf_update(int s, int t, ll del=1) {
  ll df[N]; queue<ll> q;
  memset(par, -1, sizeof par), q.push(s), par[s] = -2, df[s] = INF;
  while (!q.empty()) { ll cf, v, u = q.front(); q.pop();
    for (e = first[u]; e != -1; e = next[e])
      if (par[v=ep[e^1]] == -1 && (cf = cap[e]-flo[e]) >= del)
        q.push(v), par[v] = e, df[v] = min(df[u], cf); }
  if (par[t] == -1) return 0;
  for (int i = t; i != s; i = ep[e])
    e = par[i], flo[e] += df[t], flo[e^1] -= df[t];
  return df[t]; }

// Minimum cost maximum flow, assuming there are no negative cost cycles
// USAGE: 1) init(); 2) add edges, 3) memset(pot,0) OR mcf_pot_init(numV) and 4)
// ll price=0,flow=0; while (ll df = mcf_update(s, t, price, numV)) flow += df;
void mcf_pot_init(int n) { // If all costs >= 0: memset(pot, 0, sizeof pot); }
  memset(pot, INF, sizeof pot); pot[s] = 0;
  for (int k = 1; k < n; ++k) for (e = 0; e < m; ++e)
    if (cap[e]) pot[ep[e^1]] = min(pot[ep[e^1]], pot[ep[e]] + cost[e]);
}
ll mcf_update(int s, int t, ll &price, int n) {
  memset(vis, 0, sizeof vis); memset(dist, INF, sizeof dist); dist[s] = 0;
  for (int u = s; u != -1; ) { vis[u] = 1; // do Dijkstra
    for (e = first[u]; e != -1; e = next[e]) { int v = ep[e^1];
      if (flo[e] < cap[e] && dist[v] > dist[u] + cost[e] + pot[u] - pot[v])
   	    dist[v] = dist[u] + cost[e] + pot[u] - pot[v], par[v] = e; }
    u = -1; ll best = INF;
    for (int i = 0; i < n; ++i) if (!vis[i] && best>dist[i]) best=dist[u=i]; }
  if (dist[t] >= INF) return 0; ll df = INF;
  for (int i = t; i != s; i = ep[e])
    e = par[i], df = min(df, cap[e] - flo[e]);
  for (int i = t; i != s; i = ep[e])
    e = par[i], flo[e] += df, flo[e^1] -= df, price += df*cost[e];
  for (int i = 0; i < n; ++i) pot[i] = min(INF, pot[i] + dist[i]);
  return df; }

// Minimum cost circulation by cycle cancelling (SLOW)
// To get min cost max flow with negative cycles, do max flow followed by mcc
ll mcc_update(ll &price, int n) {
  memset(dist, 0, sizeof dist); int t = -1;
  for (int u, v, k = 1; k <= n; ++k) for (e = 0; e < m; ++e)
    if (flo[e] < cap[e] && dist[v=ep[e^1]] > dist[u=ep[e]] + cost[e])
      { dist[v] = dist[u] + cost[e], par[v] = e; if (k == n) t = u; }
  if (t == -1) return 0; ll df = INF;
  for (int i = 2; i < n; ++i) t = ep[par[t]];
  for (int i = t, j = 0; i != t || !j; i = ep[e], ++j)
    e = par[i], df = min(df, cap[e] - flo[e]);
  for (int i = t, j = 0; i != t || !j; i = ep[e], ++j)
    e = par[i], flo[e] += df, flo[e^1] -= df, price += df*cost[e];
  return df; }
////////////////////////////////////////////////////////////////////////////////
// Maximum bipartite matching: O(m^2*n) where m and n are sizes of partitions
////////////////////////////////////////////////////////////////////////////////
bool adjmat[M][N], seen[N]; int matchL[M], matchR[N], m, n;
bool bpm(int u) { // Can we find augmenting path starting from u
  for(int v = 0; v < n; v++) if(adjmat[u][v] && !seen[v]) {
    seen[v] = true;
    if(matchR[v] == -1 || bpm(matchR[v]) ) {
      matchL[u] = v, matchR[v] = u;
      return true;
    }
  } return false; }
int main() {
  memset(matchL, -1, sizeof matchL); memset(matchR, -1, sizeof matchR);
  // Read input, set m, n, and populate adjmat here
  int cnt = 0;
  for(int i = 0; i < m; i++) {
    memset(seen, 0, sizeof seen);
    if( bpm(i) ) cnt++; // matchL[i] is the match
  } return 0; }
////////////////////////////////////////////////////////////////////////////////
// Maximum weight bipartite matching (hungarian) - TESTED
////////////////////////////////////////////////////////////////////////////////
//usage: set w to be weights between two sets, n, m - their sizes, run wmatch
int w[N][N], ml[N], mr[N], lbl[N], lbr[N], s[N], slack[N], par[N]; // Yury's
int wmatch(int n, int m){ // assume n <= m;
  int i, j, k, done, al, next, out = 0;
  for(i=0;i<n;i++)for(j=0,lbl[i]=0,ml[i]=-1;j<m;j++) lbl[i]=max(lbl[i],w[i][j]);
  for(i = 0; i < m; i++) lbr[i] = 0, mr[i] = -1;
  for(i=0;i<n;i++) for(j = 0; j < m; j++) if(w[i][j] == lbl[i] && mr[j] == -1)
    { ml[i] = j, mr[j] = i; break; }
  for(i = 0; i < n; i++) if(ml[i] == -1){
    for(j=0;j<m;j++) s[j]=(j==i), slack[j]=(lbl[i]+lbr[j]-w[i][j]), par[j] = -1;
    for(done = 0; !done;){
      for(j = 0, al = INF; j < m; j++) if(par[j] == -1) al = min(al, slack[j]);
      for(j = 0, lbl[j] -= s[j]*al; j < m; ++j, lbl[j] -= s[j]*al)
	if(par[j] != -1) lbr[j] += al; else slack[j] -= al;
      for(j = 0; j < m; j++) if(!slack[j] && par[j] == -1){
	for(k=0;k<n;k++) if(s[k]&&(lbl[k]+lbr[j]==w[k][j])){ par[j] = k; break;}
	if(mr[j] == -1){ done = 1;
	do{ next=ml[par[j]], mr[j]=par[j], ml[par[j]]=j, j=next;}while(j != -1);
	}else for(k = 0, s[mr[j]] = 1; k < m; k++)
	  slack[k] = min(slack[k], lbl[mr[j]] + lbr[k] - w[mr[j]][k]); break; }}}
  for(i = 0; i < n; i++) out += w[i][ml[i]]; return out; }
////////////////////////////////////////////////////////////////////////////////
// General Matching
////////////////////////////////////////////////////////////////////////////////
// Tested on UVa 11439. Time complexity: O(VEalpha(V,E))
// SEVERELY BROKEN: USE AND PRAY. TESTED TWICE.
int pp[MAXN];
int f(int x) { return x == pp[x] ? x : (pp[x] = f(pp[x])); }
void u(int x, int y) {pp[x] = y;} // Broken Union-Find

vi graph[MAXN];
int p[MAXN], m[MAXN], d[MAXN], c1[MAXN], c2[MAXN], n;
int q[2*MAXN], *qf, *qb; //queue

// least common ancestor
int v[MAXN];
int lca(int x, int y, int r) { int i = f(x), j = f(y);
  while (i != j && v[i] != 2 && v[j] != 1) { v[i] = 1; v[j] = 2;
    if (i != r) i = f(p[i]); if (j != r) j = f(p[j]); }
  int b = i, z = j; if (v[j] == 1) swap(b, z);
  for (i = b; i != z; i = f(p[i])) v[i] = -1; v[z] = -1; return b; }

void path(int r, int x){ if (r == x) return;
  if (d[x] == 0){ path(r, p[p[x]]); int i=p[x], j=p[p[x]]; m[i]=j; m[j]=i; }
  else if (d[x] == 1) { path(m[x], c1[x]); path(r, c2[x]);
    int i = c1[x], j = c2[x]; m[i] = j; m[j] = i; } }

void shrink_one_side(int x, int y, int b){
  for(int i=f(x); i!=b; i=f(p[i])){u(i, b);if(d[i]==1)c1[i]=x,c2[i]=y,*qb++=i;}}

bool BFS(int r) { for (int i = 0; i<n; ++i) pp[i] = i;
  memset(v, -1, sizeof(v)); memset(d, -1, sizeof(d)); d[r] = 0;
  qf = qb = q; *qb++ = r;
  while (qf < qb) for (int x = *qf++, i = 0, y = graph[x][0];
		       i < (int)graph[x].size(); ++i, y = graph[x][i])
      if (m[y] != y && f(x) != f(y)) { if (d[y] == -1) {
	  if (m[y] == -1) { path(r, x); m[x] = y; m[y] = x; return true; }
	  else { p[y] = x; p[m[y]] = y; d[y] = 1; d[m[y]] = 0; *qb++ = m[y]; }
	} else if (d[f(y)] == 0) {
	  int b = lca(x, y, r);
	  shrink_one_side(x, y, b); shrink_one_side(y, x, b); } }
  return false; }

int match() { memset(m, -1, sizeof(m)); int c = 0;
  for (int i=0; i< n; ++i) if (m[i] == -1) { if (BFS(i)) c++; else m[i] = i; }
  return c; }
////////////////////////////////////////////////////////////////////////////////
// Biconnected components & 2-edge connected components
////////////////////////////////////////////////////////////////////////////////
// Note that component excludes bridges
int cutvertex[MAXN],low[MAXN],number[MAXN],parent[MAXN],I;
vi a[MAXN]; // adjacency list
vpii bridge; vector<vpii> component; //biconn-cmps
stack<pii> s; stack<int> roots, verts;
bool inS[MAXN]; vvi tecomp;  //2-edge conn cmps
void biconnected(int u){
  low[u] = number[u] = ++I; int child = 0;
  roots.push(u); verts.push(u); inS[u] = true;
  for (int i = 0; i < a[u].size(); i++) {
    int v = a[u][i];
    if (!number[v]) {
      s.push(make_pair(u,v)); parent[v] = u, child++;
      biconnected(v); low[u] = min(low[u], low[v]);
      if(parent[u]!=-1 && low[v]>=number[u]) cutvertex[u] = 1;
      if(low[v]>number[u]) bridge.push_back(make_pair(u,v)), s.pop();
      else if(low[v]==number[u]) {
	component.resize(component.size()+1);
	while(s.top()!=make_pair(u,v) && s.top() != make_pair(v,u))
	  component.back().push_back(s.top()), s.pop();
	component.back().push_back(make_pair(u,v)); s.pop(); } }
    else if(number[v]<number[u] && v!=parent[u]){
      low[u] = min(low[u], number[v]), s.push(make_pair(u,v));
      while (number[roots.top()] > number[v]) roots.pop(); } }
  if (u == roots.top()) { tecomp.push_back(vi());
    while (true) {
      int w = verts.top(); verts.pop(); inS[w] = false;
      tecomp.back().push_back(w); if (u == w) break; }
    roots.pop(); }
  if(parent[u]==-1 && child>=2) cutvertex[u]=1; }
void doit(int n) {
  I = 0; component.clear(),bridge.clear(),tecomp.clear();
  memset(number,0,sizeof(number));
  memset(cutvertex,0,sizeof(cutvertex));
  memset(parent,0,sizeof(parent));
  memset(inS,0,sizeof(inS));
  for(int i=0; i < n; i++) if(!number[i]) parent[i]=-1, biconnected(i); }
////////////////////////////////////////////////////////////////////////////////
// Euler path O(E). Returns in reverse order. Watch out for stack overflow.
////////////////////////////////////////////////////////////////////////////////
list<int> ans; // Usage: ans.clear(), euler(start_node, ans.begin());
void euler(int c, list<int>::iterator it) { for(int i = 0; i < n; i++)
  if(deg[c][i]) { deg[c][i]--; deg[i][c]--; /*remove second if directed graph*/
    euler(i, ans.insert(it, i)); } }
////////////////////////////////////////////////////////////////////////////////
// Bart's 2-Sat
////////////////////////////////////////////////////////////////////////////////
// Fill nc[i],yc[i] with the consequences of setting node [i] to no & yes
// respectively, of the form (other_node, set_to).  For example:
// If I have a statement (!a | b) then yc[a] has (b,1), nc[b] has (a,0)
// If I have a statement (a|b) then nc[a] has (b,1) and nc[b] has (a,1) ... etc.
// Set n to the number of interesting variables
// Then run twosat().  Returns 0 if it is not satisfiable, 1 if it is.
// ass[i]&1 is the truth value of i.
int n; vector<set<pair<int, bool> > > yc, nc;
int ass[MAXN];    //bit 1: true/false  bit 2: sure/unsure  bit 3: unset
vector<int> vis;
bool assign(int node, int at) {
  if(ass[node]==at) return 1;
  if(at&2) {   // trying to assign it for sure
    if(ass[node]&2) {
      if((at&1)!=(ass[node]&1)) return 0;
      return 1;     }
    ass[node]=4;   }
  if(ass[node]&2) return 1; // assigned for sure
  if(!(ass[node]&4)) {  // assigned tentatively
    if(((at&1) != (ass[node]&1)) && !assign(node, at|2)) return 0;
    return 1;   } else {  // unassigned
    if(!(at&2)) vis.push_back(node);
    ass[node] = at;
    set<pair<int,bool> > &s=((at&1)?yc:nc)[node];
    for(set<pair<int, bool> >::iterator i = s.begin(); i!=s.end(); ++i) {
      if(ass[node] != at) return 1;  // if I've been reassigned, stop now
      if(!assign(i->first, i->second | (at&2))) return 0;     }  }
  return 1; }
bool twosat() {
  for(int i=0; i < n; i++) ass[i]=4;
  for(int i=0; i < n; i++) if(!(ass[i]&2)) {
    vis.clear();
    if(!assign(i,0)) return 0;
    for(int j=0; j < vis.size(); j++) ass[vis[j]] |= 2;   }
  return 1; }  // ass[i]&1 is the truth value of i.
////////////////////////////////////////////////////////////////////////////////
// All pairs min cut
////////////////////////////////////////////////////////////////////////////////
int data[256][256],dist[256],done[256],ans,best, ind, a, b, c, n, m, t, test=1;
int main(){
  scanf("%d", &t);
  while(t-- && scanf("%d%d", &n, &m) == 2){
    memset(data, 0, sizeof(data));
    while(m-- && scanf("%d%d%d", &a, &b, &c) == 3)
      data[a - 1][b - 1] += c, data[b - 1][a - 1] += c;
    ans = 2000000000;
    while(n > 1){
      memset(dist, 0, sizeof(dist));
      memset(done, 0, sizeof(done));
      for(int i = 0; i < n; i++){
	best = ind = -1;
	for(int j = 0; j < n; j++) if(!done[j] && dist[j] > best)
	  best = dist[j], ind = j;
	if(i + 2 == n) a = ind;
	if(i + 1 == n) b = ind, ans = min(ans, best);
	done[ind] = 1;
	for(int j = 0; j < n; j++) dist[j] += data[ind][j];  }
      if(a > b) swap(a,b);
      for(int i=0;i<n; i++) data[a][i] += data[b][i], data[i][a] += data[i][b];
      for(int i=0;i<n; i++) data[b][i]=data[n-1][i], data[i][b] = data[i][n-1];
      n--;     }
    printf("Case #%d: %d\n", test++, ans); } }
////////////////////////////////////////////////////////////////////////////////
// Minpath-Vertex cover
////////////////////////////////////////////////////////////////////////////////
// The graph must be directed, acyclic.
// Split each vertex into in- and out- halves.
// Set up a bipartite graph, connecting each
// out-vertex to the corresponding in-vertices,
// according to the original edges.
// Now run BPM. { Take any in-vertex that has nothing matching to it.
// { Now trace the path by following the matching. Repeat. } Repeat.}
////////////////////////////////////////////////////////////////////////////////
// Strongly connected components
////////////////////////////////////////////////////////////////////////////////
int scc[N], nsc, low[N], num[N], mn, st[N], sz, adj[N][N], n;
void dfs(int p) { low[p] = num[p] = mn++; st[sz++] = p;
  for (int i = 0; i < n; ++i) if (adj[p][i] && scc[i] == -1) {
    if (num[i] == -1) dfs(i); low[p] = min(low[p], low[i]); }
  if (low[p] == num[p]) { while(scc[p] != nsc) scc[st[--sz]] = nsc; ++nsc; } }
// Set up adj and n first; memset num and scc to -1
// then after get_scc() you can read scc array and nsc variable
void get_scc() {
  nsc = mn = sz = 0; for (int i = 0; i < n; ++i) if (num[i] == -1) dfs(i); }
////////////////////////////////////////////////////////////////////////////////
// Number of spanning trees
////////////////////////////////////////////////////////////////////////////////
// found by determinant of any cofactor of matrix L, where
// L[i][i] = out-degree(v[i]),
// L[i][j] = -1 if i!=j and v[i]->v[j] adjacent,
// L[i][j] = 0 otherwise
// One cofactor example: omit first row and column
////////////////////////////////////////////////////////////////////////////////
// Bridge detection, tested UVa 796
////////////////////////////////////////////////////////////////////////////////
const int MX = 10000; int color[MX], p[MX], t_edges[MX], d[MX], L[MX], f[MX];
enum { WHITE, BLACK, GRAY }; int gtime, N; vi adj[MX]; vpii bridges;
void dfs_visit_bridge(int u) {
  color[u] = GRAY; gtime++; d[u] = L[u] = gtime;
  for(int e = 0; e < adj[u].size(); e++) {
    int v = adj[u][e]; if(v == p[u]) continue;
    if(color[v] == WHITE){p[v] = u; dfs_visit_bridge(v); L[u] = min(L[u], L[v]);
      if(L[v] > d[u]) {	int a = min(u, v), b = max(u, v);
        bridges.push_back(make_pair(a, b)); }
  } else if(d[v] < d[u]) { L[u] = min(L[u], d[v]); } }
  color[u] = BLACK; gtime++; f[u] = gtime;
}
void find_bridge_edges() {
  for(int u = 0; u < N; u++) { color[u] = WHITE; p[u] = -1; t_edges[u] = 0; }
  bridges.clear(); gtime = 0;
  for(int u = 0; u < N; u++) { if(color[u] == WHITE) dfs_visit_bridge(u); } }
////////////////////////////////////////////////////////////////////////////////
// Articulation vertex, tested UVa 315
////////////////////////////////////////////////////////////////////////////////
const int MX=1000;int N;int color[MX],p[MX],t_edges[MX],f[MX],d[MX],L[MX],gtime;
enum { WHITE, BLACK, GRAY }; vi adj[MX]; bool separating[MX];
void dfs_visit_separable(int u) {
  color[u] = GRAY; gtime++; d[u] = L[u] = gtime;
  for(int e = 0; e < adj[u].size(); e++) {
    int v = adj[u][e]; if(v == p[u]) continue;
    if(color[v] == WHITE) { p[v] = u; t_edges[u]++; dfs_visit_separable(v);
      L[u] = min(L[u],L[v]); if(L[v] >= d[u]) { separating[u] = true; }
    } else if(d[v] < d[u]) { L[u] = min(L[u],d[v]); } }
  color[u] = BLACK; gtime++; f[u] = gtime;
}
void find_separating_vertices() {
  for(int u = 0; u < N; u++) {
    color[u]=WHITE;p[u]=-1;t_edges[u]=0;separating[u]=false; }
  gtime = 0; for(int u = 0; u < N; u++) {
    if(color[u] == WHITE) { dfs_visit_separable(u);
      if(t_edges[u] <= 1) separating[u] = false; } } }
////////////////////////////////////////////////////////////////////////////////
// Directed MST, Tested on UVa 11183
////////////////////////////////////////////////////////////////////////////////
const int D=1024;int n,parent[D],rank[D],par[D],cur_cost[D];
bool seen[D],seen2[D];vpii graph[D],graphr[D];
int find_and_break_cycle(int x) {
  int ans = 0, y = x; while (true) {
    memset(seen2, 0, sizeof(seen2)); // find if a cycle exists
    for(;!seen2[y]&&y>0;y=par[y])par[y]=find(par[y]),seen2[y]=true,seen[y]=true;
    if (y == 0) break; // no cycle
    memset(seen2,0,sizeof(seen2)); // compress into pseudonode
    for(;!seen2[y] ;y=par[y]) merge(y, par[y]), seen2[y]=true;
    memset(seen2, 0, sizeof(seen2)); // find the best way to break the cycle
    int node = -1, node_index = -1, best = 1000000, y_root = find(y);
    for (int i = 1; i < n; ++i) {
      if (find(i) != y_root) continue;
      for (int j = 0, t = graphr[i].size(); j < t; ++j) {
	if (find(graphr[i][j].second) == y_root) continue;
	graphr[i][j].first = graphr[i][j].first - cur_cost[i];
	if (graphr[i][j].first < best) {
	  node = i, node_index = j, best = graphr[i][j].first;	} } }
    if (node == -1) return -1; // failed for a reason that I don't know
    // update the cur_cost
    cur_cost[y_root]=best; par[y_root]=find(graphr[node][node_index].second);
    for (int i = 1; i < n; ++i) if (find(i) == y_root) cur_cost[i] = best;
    ans += best; y = y_root; } // update ans and check if created a new cycle
  return ans; }

// the MST is rooted at vertex 0
int directed_MST() {
  int ans = 0;
  memset(cur_cost, INF, sizeof(cur_cost));
  // use minimum incoming edge
  for (int i = 1; i < n; ++i) {
    for (int j = 0, t = graphr[i].size(); j < t; ++j) {
      if (graphr[i][j].first < cur_cost[i]) {
	cur_cost[i] = graphr[i][j].first;
	par[i] = graphr[i][j].second;  } } ans += cur_cost[i]; }

  memset(seen, 0, sizeof(seen));
  for (int i = 1; i < n; ++i) {
    if (!seen[find(i)]) {
      int temp = find_and_break_cycle(find(i));
      if (temp == -1) return -1; else ans += temp; }}
  return ans;}
// Usage:
// read in the directed graph
// graph = adjacency list, graphr = adjacency list of reverser graph
// make sure graph is connected first and initialize union-find
// find() and merge(),  rank[] and parent[] are for union find
// ans = directed_MST() (the MST is rooted at node 0)
// n = number of nodes
////////////////////////////////////////////////////////////////////////////////
// K-th shortest path
////////////////////////////////////////////////////////////////////////////////
typedef unsigned long long ull; typedef vector<int> vi; typedef deque<int> di;
int N, M, K, A, B, SRC, SNK; int adj[50][50];
int best[50], from[50]; // reverse dijkstra answers
// do dijkstra backwards; seen is nodes to avoid. O(N^2)
void rev_dijkstra(ull seen) { for(int i = 0; i < N; i++) { best[i] = INF; }
  best[SNK] = 0; while(1) {
    int curr = -1; for(int i = 0; i < N; i++) {
      if(seen & (1ull << i)) continue; if(best[i] == INF) continue;
      if(curr == -1 || best[i] < best[curr]) curr = i; }
    if(curr == -1) return;  seen |= (1ull << curr);
    for(int j = 0; j < N; j++) { if(seen & (1ull << j)) continue; // seen before
      if(adj[j][curr] == INF) continue; int nc=best[curr]+adj[j][curr]; // cost
      if(best[j] > nc) best[j] = nc, from[j] = curr; } } }

// gets the lexicographically smallest shortest path. O(N^2)
bool get_lex_shortest(int start, di& path) {
  int i = start, cost = best[start]; path.clear();
  while(i != SNK) { int n = INF; path.push_back(i);
    for(int j = 0; j < N; j++) if(best[j] + adj[i][j] == cost) {n = j;break;}
    if(n == INF) { cerr << " ERROR!" << endl; return false; }
    cost -= adj[i][n]; i = n; } // adjust cost
  path.push_back(SNK);  return true; }

// no of states < K * N
struct state { int branch[50]; int node;
  int dij_cost; di dij_path; // dijkstra
  int best_cost; di best_path; }; // cache the dfs
vector<state> gstate;

// update the dijkstra thingy. O(N^2)
void update_state(int s, ull seen) {
  int tmp[50], i = gstate[s].node;
  for(int j = 0; j < N; j++) {  // remove edges and recurse
    if(gstate[s].branch[j] < 0) continue; tmp[j] = adj[i][j]; adj[i][j] = INF; }
  rev_dijkstra(seen); // dijkstra O(N^2)
  gstate[s].dij_cost = best[i];
  if(best[i] < INF) { // update path.. if there is
    get_lex_shortest(i, gstate[s].dij_path);    // O(N^2) for finding path
    gstate[s].dij_path.pop_front();  }
  for(int j = 0; j < N; j++) {  // put back edges O(N)
    if(gstate[s].branch[j] < 0) continue;  adj[i][j] = tmp[j];  }
  gstate[s].best_cost = INF; }  // invalidate current

// get best state; there are O(K * N) states
bool find_next(int s, ull seen, di& path, int& cost) {
  int i = gstate[s].node;
  if(gstate[s].best_cost < INF) {
    cost = gstate[s].best_cost;
    path = gstate[s].best_path;
    return cost < INF; }
  cost = INF;
  if(i == SNK) return false; // first test case
  for(int j = 0; j < N; j++) {   // remove edges and recurse
    if(gstate[s].branch[j] < 0) continue;
    int n = gstate[s].branch[j]; int tmpcost; di tmppath; // recurse
    if(find_next(n, seen | (1ull << i), tmppath, tmpcost)) {
      tmpcost += adj[i][j];
      if(tmpcost < cost ||
	 (cost < INF && tmpcost == cost && tmppath[0] < path[0])) {
	cost = tmpcost;
	path = tmppath; } } }
  if(cost > gstate[s].dij_cost || (cost < INF && cost == gstate[s].dij_cost
      && gstate[s].dij_path[0] < path[0])) // from dijkstra get the best
    cost = gstate[s].dij_cost, path = gstate[s].dij_path;
  path.push_front(i); gstate[s].best_cost = cost; gstate[s].best_path = path;
  return cost < INF; }

// apply the path given from state s; a path is at most length N. O(N ^ 2)
int apply_path(int s, di& path, ull seen) {
  int i = gstate[s].node;
  if(i == SNK) return s;
  if(path.front() != i) cerr << " wrong state !" << endl;
  path.pop_front();
  gstate[s].best_cost = INF; // invalidate current node
  int j = path.front();
  if(gstate[s].branch[j] >= 0)
    return apply_path(gstate[s].branch[j], path, seen | (1ull << i));
  // add a new state
  int ns = gstate.size();
  state next;
  next.best_cost = INF;
  next.node = path.front();
  gstate.push_back(next);
  gstate[s].branch[j] = ns;
  memset(gstate[ns].branch, -1, sizeof(gstate[ns].branch));
  update_state(s, seen);
  return apply_path(ns, path, seen | (1ull << i)); }

int main() { while(1) {
    scanf("%d %d %d %d %d", &N, &M, &K, &A, &B);
    if(N == 0 && M == 0 && K == 0 && A == 0 && B == 0) break;
    SRC = --A; SNK = --B;
    for(int i = 0; i < N; i++)
      for(int j = 0; j < N; j++)
	adj[i][j] = INF;
    for(int i = 0; i < M; i++) {
      int a, b, cost;
      scanf("%d %d %d", &a, &b, &cost);
      adj[--a][--b] = cost; }

    // initial state
    state initial;
    initial.node = SRC;
    initial.best_cost = INF;
    memset(initial.branch, -1, sizeof(initial.branch));
    gstate.clear();
    gstate.reserve(200 * 50);
    gstate.push_back(initial);
    update_state(0, 0ull);

    // O(K^2 * N^3)
    di trace;
    bool ok = true;
    for(int k = 0; k < K; k++) {
      int cost = INF;
      di path;
      if(!find_next(0, 0ull, path, cost)) {
	ok = false;
	break;  }
      if(k == K - 1) trace = path;
      apply_path(0, path, 0ull); }
    if(!ok) cout << "None" << endl;
    else { for(int i = 0; i < trace.size(); i++) {
	if(i > 0) cout << "-";
	cout << trace[i] + 1; }
      cout << endl; } } }
////////////////////////////////////////////////////////////////////////////////
// Gomory-Hu tree (Tested on UVA 11594)
////////////////////////////////////////////////////////////////////////////////
// All-pairs maximum flow for UNDIRECTED flow network.
// Usage: init graph/cap, build_tree(), then max_flow(i,j) for mf from i to j
typedef int Weight;

// !!!!!!!! following must be initialized by user !!!!!!!!!!!
vi graph[MAXN]; Weight capacity[MAXN][MAXN];
int n; // # of vertices
// !!!!!!!!
vi ghtree[MAXN]; vector<Weight> ghweight[MAXN];
int p[MAXN], prev[MAXN]; Weight w[MAXN], flow[MAXN][MAXN];
Weight max_memo[MAXN][MAXN]; //dp table, initialize to -1
#define REP(i,n) for(int i=0;i<(int)n;++i)
#define FOR(i,c) for(int i=0;i!=(c).size();++i)
#define RESIDUE(s,t) (capacity[s][t]-flow[s][t])
void build_tree() {
  REP(i,MAXN) w[i] = 0;
  memset(p, 0, sizeof(p));
  for (int s=1; s < n; ++s) {
    int t = p[s];
    memset(flow, 0, sizeof(flow));
    Weight total = 0;
    while (true) {
      queue<int> q; q.push(s);
      memset(prev, -1, sizeof(prev)); prev[s] = s;
      while (!q.empty() && prev[t] < 0) {
        int u = q.front(); q.pop();
        FOR(e,graph[u]) if (prev[graph[u][e]]<0 && RESIDUE(u, graph[u][e])>0)
          prev[graph[u][e]] = u, q.push(graph[u][e]);
      }
      if (prev[t] < 0) break;
      Weight inc = INF;
      for (int j=t; prev[j]!=j; j=prev[j]) inc = min(inc, RESIDUE(prev[j], j));
      for (int j=t; prev[j]!=j; j=prev[j])
	flow[prev[j]][j] += inc, flow[j][prev[j]] -= inc;
      total += inc; }
    w[s] = total;
    REP(u, n) if (u != s && prev[u] != -1 && p[u] == t) p[u] = s;
    if (prev[p[t]] != -1) p[s] = p[t], p[t] = s, w[s] = w[t], w[t] = total; }
  REP(i, MAXN) ghtree[i].clear(), ghweight[i].clear();
  REP(s, n) if (s != p[s]) {
    ghtree[s].push_back(p[s]); ghtree[p[s]].push_back(s);
    ghweight[s].push_back(w[s]); ghweight[p[s]].push_back(w[s]); }
  memset(max_memo, -1, sizeof(max_memo)); }
Weight max_flow(int u, int t, int p = -1) {
  if (max_memo[u][t] != -1) return max_memo[u][t]; if (u == t) return INF-1;
  Weight d = INF; FOR(e, ghtree[u]) if (ghtree[u][e] != p) {
    Weight ans = max_flow(ghtree[u][e], t, u);
    if (ans < INF) ans = min(ans,ghweight[u][e]);
    d = min(d, ans); } if (d < INF) max_memo[u][t] = max_memo[t][u] = d;
  return d; }
////////////////////////////////////////////////////////////////////////////////
// Arbitrary Dimensional KD-Tree
////////////////////////////////////////////////////////////////////////////////
//usage: 1) set dim 2) initialize tree with kd_tree tree(MAXN) 3) call add_point
//for each pt to be added, 3) tree.init() 4) for each query, call tree.query(pt)
//the result is stored in tree.best_pt and tree.best_dist (squared min dist).
const int dim = 3;
struct kd_node { double x[dim]; kd_node *left, *right; };
struct comp_idx { int idx; comp_idx(int idx) : idx(idx) {}
  const bool operator()(const kd_node& l, const kd_node &r) const {
    return l.x[idx] < r.x[idx]; } };
inline double dist(kd_node *a, kd_node *b) { double d = 0;
	for (int i = 0; i < dim; i++) d += pow(a->x[i] - b->x[i], 2);
	return d; } 
struct kd_tree { vector<kd_node> tree;
  kd_node *best_pt, *root; double best_dist2; int cnt;
  kd_tree(int n) { cnt=0; tree.resize(n); }
  kd_node* make_tree(kd_node *t, int len, int i) {
    if (!len) return 0;
    nth_element(t, t + len/2, t + len, comp_idx(i));
    kd_node *n = t + len/2; i = (i + 1) % dim;
    n->left = make_tree(t, n-t, i); n->right = make_tree(n+1, t+len-(n+1), i);
    return n; }   
  void nearest(kd_node *root, kd_node *nd, int i) {
    double d, dx, dx2; if (!root) return;
    d = dist(root, nd), dx = root->x[i] - nd->x[i], dx2 = dx * dx;
    if (!best_pt || d < best_dist2) { best_dist2 = d, best_pt = root; }
    if (fabs(best_dist2) < EPS) return;
    nearest(dx > 0 ? root->left : root->right, nd, (i + 1) % dim);
    if (dx2 >= best_dist2) return;
    nearest(dx > 0 ? root->right : root->left, nd, (i + 1) % dim); }  
  void add_point(double pt[dim]) { cnt++;
    for (int i = 0; i < dim; i++) tree[cnt].x[i] = pt[i]; }
  double query(double pt[dim]) { kd_node p; best_dist2 = 1e99, best_pt = NULL;
    for (int i = 0; i < dim; i++) p.x[i] = pt[i];
    nearest(root, &p, 0); return sqrt(best_dist2); }
  void init() { root = make_tree(&tree[0], cnt, 0); }
}; //based off kd-tree from rosetta code
////////////////////////////////////////////////////////////////////////////////
//  KD-Tree (Yury)
////////////////////////////////////////////////////////////////////////////////
//specialized kd-tree for 2d range-inserts and point queries.
//usage: getv(p) gets the value of pt p in the tree, update(val, bl, tr) changes 
//vals of pts in the rect [bl.x, tr.x)*[bl.y, tr.y) to max(curr_val, val)
inline pt sw(const pt &p){ return pt(p.imag(), p.real()); }
struct myKD{ //O(n lg^2 n) construction, use nth_element for O(nlgn) complexity
  myKD *left, *right; int value; pt split, minx, maxx, miny, maxy;
  myKD(vector<pt> &v){
    value = 0, minx = miny = pt(INF, INF), maxx = maxy = pt(-INF, -INF);
    if((int)v.size() == 1){left=right=0; minx=maxx=miny = maxy = v[0]; return;}
    sort(v.begin(), v.end(), cmp_lex), split = v[v.size()/2];
    vector <pt> vl, vr;
    for(int i = 0; i < (int)v.size(); i++){
      if(cmp_lex(v[i],minx))minx = v[i]; if(cmp_lex(maxx,v[i]))maxx = v[i];
      if(cmp_lex_i(v[i],miny))miny = v[i]; if(cmp_lex_i(maxy,v[i]))maxy = v[i];
      if(cmp_lex(v[i], split)) vl.push_back(sw(v[i]));
      else vr.push_back(sw(v[i]));
    } left = new myKD(vl), right = new myKD(vr); }
  ~myKD(){ if(left) delete left; if(right) delete right; }
  int getv(const pt &p){
    if(!left) return value;
    if(cmp_lex(p, split)) return max(value, left->getv(sw(p)));
    return max(value, right->getv(sw(p)));
  }
  void update(int val,const pt&l,const pt&r,const pt&d,const pt&u){
    if(!cmp_lex(minx, r) || !cmp_lex_i(miny, u)
       || cmp_lex(maxx, l) || cmp_lex_i(maxy, d)) return;
    if(cmp_lex(maxx,r)&&cmp_lex_i(maxy,u)
       &&!cmp_lex(minx,l)&&!cmp_lex_i(miny,d))value=max(value,val);
    else if(left) left->update(val, sw(d), sw(u), sw(l), sw(r)),
		    right->update(val, sw(d), sw(u), sw(l), sw(r));
  }
  void update(int val, const pt &bl, const pt &tr){
    update(val, pt(bl.real(), -INF), pt(tr.real(), -INF),
	   pt(-INF, bl.imag()), pt(-INF, tr.imag()));
  } };
////////////////////////////////////////////////////////////////////////////////
// Binary Indexed Tree (operation=add)
// simplified range query for group operations (associative & invertible)
////////////////////////////////////////////////////////////////////////////////
// valid positions are [1..MAXN], commented lines are hints for a 2D BIT
// MODES OF USE: point-insert range-query OR range-insert point-query
struct BITree { ll freq[MAXN+1]; BITree() { memset(freq, 0, sizeof freq); }
  void insert(int x, ll cnt=1) {
    for ( ; x <= MAXN; x += x & -x) freq[x] += cnt;
      //for (int y = argy; y <= MAXN; y += y & -y) freq[x][y] += cnt;
  }
  ll query(int x) { ll sum = 0;
    for ( ; x; x -= x & -x) sum += freq[x];
      //for (int y = argy; y; y -= y & -y) sum += freq[x][y];
    return sum; }
  void insert_range(int xl,int xr,ll cnt=1) {insert(xl,cnt); insert(xr+1,-cnt);}
  ll query_range(int xl, int xr) { return query(xr) - query(xl-1); }
  int get_nth(ll n) { int x = 1<<30; // assumes non-negative frequencies
    for (int step = x>>1; step; step >>= 1)
      if (x-step > MAXN || freq[x-step] >= n) x -= step; else n -= freq[x-step];
    return x; } };
////////////////////////////////////////////////////////////////////////////////
// Range Query Tree (operation=min, works for any associative binary operation)
////////////////////////////////////////////////////////////////////////////////
// stores binary tree in [1..2*MAXN-1], the leaves are [MAXN..2*MAXN-1]
// assumes MAXN is a power of 2. functions act on [x..y]
struct RQTree { int a[2*MAXN]; RQTree() { memset(a, INF, sizeof a); }
  int update(int x, int y, int i=1, int l=0, int r=MAXN-1) {
    if (y<l || r<x || l==r) return a[i]; int m = (l+r)/2;
    return a[i] = min(update(x,y,2*i,l,m), update(x,y,2*i+1,m+1,r)); }
  void insert(int x, int v) { a[MAXN+x] = v; update(x,x); }
  int query(int x, int y, int i=1, int l=0, int r=MAXN-1) {
    if (y<l || r<x) return INF; if (x<=l && r<=y) return a[i]; int m = (l+r)/2;
    return min(query(x,y,2*i,l,m), query(x,y,2*i+1,m+1,r)); } };
////////////////////////////////////////////////////////////////////////////////
// Amortized Range Tree for storing a union of intervals
////////////////////////////////////////////////////////////////////////////////
// insert(x,y,v) increments each of count[x...y] by v and returns the number of
// positive counts. WARNING: all counts must stay >= 0, MAXN must be power of 2
int a[2*MAXN],p[2*MAXN]; void init() {memset(a,0,sizeof a);memset(p,0,sizeof p);}
int insert(int x, int y, int v, int i=1, int l=0, int r=MAXN-1) {
  if (y<l || r<x) return 0; int m = (l+r)/2;
  if (x<=l && r<=y) { a[i] += v;
    if (a[i]<0) insert(l,r,a[i],2*i,l,m), insert(l,r,a[i],2*i+1,m+1,r), a[i]=0;
    return p[i] = a[i] ? r-l+1 : (l==r ? 0 : p[2*i]+p[2*i+1]); }
  if (  a[i]  ) insert(l,r,a[i],2*i,l,m), insert(l,r,a[i],2*i+1,m+1,r), a[i]=0;
  int ret = insert(x,y,v,2*i,l,m) + insert(x,y,v,2*i+1,m+1,r);
  p[i] = p[2*i]+p[2*i+1]; return ret; }
////////////////////////////////////////////////////////////////////////////////
// Splay Tree (tested SPOJ CERC07S, TWIST, ORDERSET, GSS6, SEQ2; POJ 3580)
////////////////////////////////////////////////////////////////////////////////
//! TODO: splay deepest node
// cnt is some property (eg. count) that propagates upwards
// the reverse thingy reverses an entire subtree
struct node { node *l, *r, *p; ll id, key, val, cnt; bool rev;
  node(ll i=0, ll k=0, ll v=0);
  inline int dir() { return this == p->l; }
  inline void set_cld(node* c, bool left) { (left?l:r) = c; c->p = this; }
} _null, *null, *root, *data[MAXN];
node::node(ll i, ll k, ll v) { id=i; key=k; val=v; cnt=1; rev=0; 
  if (!null) { null=&_null; null->cnt=0; } l=r=p=null; }
//%%== Code for upwards propagating property (eg. count)
void update(node* x) { if (x != null) { x->cnt = 1 + x->l->cnt + x->r->cnt; } }
//%%== Code for downward lazy propagating property (eg. reverse subtree, add)
void rev(node* x) { if (x != null) { x->rev ^= 1; swap(x->l, x->r); } }
void fix(node* x) { if (x->rev) { rev(x->l); rev(x->r); x->rev=0; } }
//%%== Core splay tree code (rotate, splay, delete)
inline void rot(node* x) { node *p = x->p; fix(p), fix(x); bool d = x->dir();
  p->set_cld(d ? x->r : x->l, d); p->p->set_cld(x, p->dir()); x->set_cld(p, !d);
  update(p); update(x); if (p == root) root = x; }
// splays node x until it is a child of node to
void splay(node* x, node* to = null) { if (x == null) return; while(x->p != to) 
  if(x->p->p==to) rot(x); else (x->dir()==x->p->dir()?rot(x->p):rot(x)),rot(x);}
void del(node* x){ splay(x); x = x->r; while (fix(x), x->l != null) x = x->l;
  if (x==null) x = root->l; else { splay(x, root); x->set_cld(root->l, 1); }
  x->p = null; update(root = x); }
//%%== BST code (lb, find, insert) (does NOT work with reverse thingy)
node* lb(ll k, node* c = root) { if (c == null) return c; 
  if(c->key >= k){ node* l=lb(k,c->l); return l==null?c:l; } return lb(k,c->r);} 
node* find(ll k) { node* c=lb(k); if (c->key!=k) c=null; splay(c); return c; }
void insert(node* x) { node *c=root,*p; if(c==null){root=x;return;} ll k=x->key;
  while(c!=null) p=c, c=(p->key>k?p->l:p->r); p->set_cld(x,p->key>k); splay(x);}
//%%== Utility code (rank, nth order statistic) (requires count maintained)
int rank(node* x) { splay(x); return x->l->cnt; }
node* nth(int n) { node* c = root; while(c != null) { fix(c); int l=c->l->cnt;
  if (n==l) break; if (n < l) c = c->l; else n = n-l-1, c = c->r; } return c; }
////////////////////////////////////////////////////////////////////////////////
// Link-cut tree: O(lg n) for all ops, TESTED (DYNALCA, DYNACON1, and more)
////////////////////////////////////////////////////////////////////////////////
// link(p, q) - makes the *root* p a child of the node q. if p is not a root,
//              makeroot will be called and lca(p, q) will be changed.
// cut(p) - deletes the edge connecting p to its parent
// cut(p, q) - delete the edge connecting p to q (or on the path from p to q)
// pathAggregate(p, q) - returns the sum of weights on the path from p to q.
//					             this operation can be min, adding a constant, etc.
// pathUpdate(p, q) - increase value of all nodes between x and y inc. by c.
// lca(p, q) - returns lca of nodes p and q.
// findroot(p) - returns the root of node p's tree
struct LinkCutTree {
  vector<int> l, r, p, pp, val, sum, carry, size, flip;
	int null;
	void init(int n) {
		vector<int>* v[] = {&l, &r, &p, &pp, &size, &val, &sum, &carry, &flip};
		int ival[] = {null=n, null, null, null, 1, 0, 0, 0, 0};
		for (int i = 0; i < 9; i++) { v[i]->clear(); v[i]->resize(n+1, ival[i]); }
		size[null] = 0; }
  inline int access(int x) {
    if(r[splay(x)] != null) r[pp[r[x]] = x] = p[r[x]] = null;
    for(int w=x; update(w)>=0 && splay(w=pp[x]) != null; splay(r[p[x]=w]=x))
      if(r[w] != null) p[r[pp[r[w]]=w]] = null;
    return x; }
  void makeroot(int x) { access(x); flip[x] ^= 1; push(x); }
  int findroot(int x) {
    for(access(x); l[x] != null; x = l[x]); //semicolon here
    return access(x); }
  int pathAggregate(int x) { return sum[access(x)]; }
  int pathAggregate(int x, int y) { makeroot(x); return pathAggregate(y); }
  void cut(int x) { l[x] = p[l[access(x)]] = null; }
  void cut(int x, int y) { makeroot(y); cut(x); }
  void link(int x, int y) { makeroot(x); l[p[access(y)]=access(x)] = y; }
  void pathUpdate(int x, int y, int c) {
    int z = lca(x,y);
    if(x != z) carry[x] += c;
    if(y != z) carry[y] += c;
    val[z] += c; }
  inline int splay(int x) {
    for(push(x); p[x] != null; lift(x))
      if(l[l[p[p[x]]]] == x || r[r[p[p[x]]]] == x) lift(p[x]);
      else lift(x);
    return x; }
  void push(int x) {
    if(flip[x]==1) {
      swap(l[x], r[x]);
      flip[x]^=1; flip[l[x]]^=1; flip[r[x]]^=1;
    }
    val[x] += carry[x];
    carry[l[x]] += carry[x]; carry[r[x]] += carry[x];
    carry[x] = 0; }
  int update(int x) {
    if(x == null) return x;
    size[x] = size[l[x]] + size[r[x]] + 1;
    sum[x] = val[x]+sum[l[x]]+sum[r[x]] + carry[x]*size[x];
    return x; }
  int lca(int x, int y) {
    access(x); access(y); splay(x);
    return access(pp[x]==null?x:pp[x]); }
  void lift(int x) {
    if(p[x] == null) return;
    push(p[x]); push(x); push(l[x]); push(r[x]);
    pp[x] = pp[p[x]]; pp[p[x]] = null;
    int* a=&l[0], *b=&r[0];
    if(r[p[x]]==x) {a=&r[0]; b=&l[0];}
    a[p[x]] = b[x]; b[x] = p[x]; p[x] = p[p[x]];
    if(p[x] != null) {
      if(a[p[x]] == b[x]) a[p[x]] = x;
      else b[p[x]] = x; }
    if(a[b[x]] != null) p[a[b[x]]] = b[x];
    update(l[b[x]]); update(r[b[x]]);
    update(p[update(b[x])] = x); } }; // from Antony at UCF.
////////////////////////////////////////////////////////////////////////////////
// MinQueue
////////////////////////////////////////////////////////////////////////////////
template <class type>
struct min_stack : public stack<type> {
  stack<type> mins; //vals stored in stack inherited from the STL stack
  int mins_top() { return (mins.empty() ? INF : mins.top()); }
  void push(int x) { mins.push(min(x, mins_top())); stack<type>::push(x); }
  int pop() { mins.pop(); int x=stack<type>::top();
    stack<type>::pop(); return x; }
  int minimum() { return mins_top(); } };
//Has all standard queue operations, as well as a minimum function, which gives
//the minimum element in the queue in O(1) time. Similar for min_stack above.
template <class type> //Application: Sliding window RMQs
struct min_queue { min_stack<type> in, out;
  void refill() { if (out.empty()) while (!in.empty()) out.push(in.pop()); }
  void push(int x) { in.push(x); }
  int pop() { refill(); return out.pop(); }
  int front() { refill(); return out.top(); }
  bool empty() { return in.empty() && out.empty(); }
  int minimum() { return min(in.minimum(), out.minimum()); } };
////////////////////////////////////////////////////////////////////////////////
// Poker (TESTED on UVA 10315)
////////////////////////////////////////////////////////////////////////////////
int pokerEval(int c[]) {//c[i]=13*suit+val. suits->0-3, vals->0-12 w/ Ace = 12
  int i,j,s=0,f=1,vc[13],sc[5],sv[5],sw[5];
  for(i=0;i<13;i++) vc[i]=0;
  for(i=0;i<5;i++) { sc[i]=sv[i]=0; f&=c[i]/13==c[0]/13; vc[c[i]%13]++; }
  for(i=12;i>=0;i--) { sc[j=vc[i]]++; sw[j]=sv[j]; sv[j]=i; if (j==1) s=s*13+i;}
  if (sc[4]) return 7000000+sv[4]*30940+sv[1];
  if (sc[2]&&sc[3]) return 6000000+sv[3]*30927+sv[2]*14;
  if (sc[3]) return 3000000+sv[3]*30927+s;
  if (sc[2]) return sc[2]*1000000+max(sv[2],sw[2])*30758+min(sv[2],sw[2])*182+s;
  if (s==349674) return 90258+1000000*(f?8:4);
  if (s==368714&&f) return 9000000+s;
  int st=(s-121186)%30941==0;
  return s+(st&&f?8:st?4:f?5:0)*1000000; }
////////////////////////////////////////////////////////////////////////////////
// Josephus ring survivor (n: # of people, starting at 0, killing every m'th)
////////////////////////////////////////////////////////////////////////////////
int survive[MAXN]; void josephus(int n, int m) {
  survive[1] = 0; for(int i = 2; i <= n; ++i) survive[i] = (m+survive[i-1])%i; }
////////////////////////////////////////////////////////////////////////////////
// Day of week
////////////////////////////////////////////////////////////////////////////////
int dow( int m, int d, int y ) { // 0 = sunday
  y-=m<3; return(y+y/4-y/100+y/400+"-bed=pen+mad."[m]+d)%7; }
int dow_julian( int m, int d, int y ) {
  y-=m<3; return(y+y/4+5+"-bed=pen+mad."[m]+d)%7; }
////////////////////////////////////////////////////////////////////////////////
// Roman numerals. The 2 functions are independent, global variables are common.
////////////////////////////////////////////////////////////////////////////////
string roman[13] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
int arab[13] = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
map<string, int> dict;
map<int, string> nums;
string to_roman(int n) {
  if (n <= 0) return "";
  if (nums.count(n)) return nums[n];
  for (int j=0; j<13; j++)
    if (n >= arab[j]) {
      string res = roman[j] + to_roman(n-arab[j]);
      dict[res] = n;
      return nums[n] = res;
    }
  return ""; }
int to_arabic(string key) {
  if (!key.size()) return 0;
  if (dict.count(key)) return dict[key];
  for (int j=0; j<13; j++)
    if (key.substr(0, roman[j].size()) == roman[j]) {
      int res = arab[j] + to_arabic(key.substr(roman[j].size()));
      nums[res] = key;
      return dict[key] = res;
    }
  return dict[key] = -1; }
////////////////////////////////////////////////////////////////////////////////
// Rubik's cube
////////////////////////////////////////////////////////////////////////////////
// Each cube must be represented by a 9 by 12 character
// array, with the faces numbered as follows.
//     0123456789AB   Rotate(Cube c, int f) rotates face f
//    0...+-+......   90 degrees clockwise.
//    1...|4|......
//    2...+-+......     +-----+          +-----+
//    3+-++-++-++-+     |  ^  |  rotate  |     |
//    4|0||1||2||3|     |  |  |  ----->  | *-->|
//    5+-++-++-++-+     |  *  |   cw 90  |     |
//    6...+-+......     +-----+          +-----+
//    7...|5|......   Rotating 90 degrees counter-clockwise
//    8...+-+......   may be done by calling Rotate 3 times
//
//    isSolved(Cube c) returns 1 if each face contains the
//    same characters, and 0 otherwise
//    printCube(Cube c) is provided to see cube c.
typedef struct{ char g[9][12]; } Cube;
int cx[6] = {4,4,4,4,1,7}; int cy[6] = {1,4,7,10,4,4};
int rx[6][4][3] = {{{0,1,2}, {5,4,3}, {6,7,8}, {3,4,5}},
                   {{2,2,2}, {5,4,3}, {6,6,6}, {3,4,5}},
                   {{2,1,0}, {5,4,3}, {8,7,6}, {3,4,5}},
                   {{5,4,3}, {8,8,8}, {3,4,5}, {0,0,0}},
                   {{3,3,3}, {3,3,3}, {3,3,3}, {3,3,3}},
                   {{5,5,5}, {5,5,5}, {5,5,5}, {5,5,5}}};
int ry[6][4][3] = {{{3,3,3}, {11,11,11}, {3,3,3}, {3,3,3}},
                   {{3,4,5}, {2,2,2}, {5,4,3}, {6,6,6}},
                   {{5,5,5}, {5,5,5}, {5,5,5}, {9,9,9}},
                   {{8,8,8}, {3,4,5}, {0,0,0}, {5,4,3}},
                   {{0,1,2}, {3,4,5}, {6,7,8}, {9,10,11}},
                   {{11,10,9}, {8,7,6}, {5,4,3}, {2,1,0}}};
int isSolved(Cube c){
  int i, x, y;
  for(i = 0; i < 6; i++)
    for(x = cx[i]-1; x <= cx[i]+1; x++)
      for(y = cy[i]-1; y <= cy[i]+1; y++)
	if(c.g[x][y] != c.g[cx[i]][cy[i]]) return 0;
  return 1;
}
Cube Rotate(Cube c, int f){
  char t[3][3]; int i, j, x = cx[f], y = cy[f];
  for(i = 0; i < 3; i++) for(j = 0; j < 3; j++)
    t[i][j] = c.g[x+i-1][y+j-1];
  for(i = 0; i < 3; i++) for(j = 0; j < 3; j++)
    c.g[x+i-1][y+j-1]=t[2-j][i];
  for(i = 0; i < 3; i++) t[0][i] = c.g[rx[f][0][i]][ry[f][0][i]];
  for(j = 0; j < 3; j++) for(i = 0; i < 3; i++)
    c.g[rx[f][j  ][i]][ry[f][j  ][i]] =
    c.g[rx[f][j+1][i]][ry[f][j+1][i]];
  for(i = 0; i < 3; i++) c.g[rx[f][j][i]][ry[f][j][i]] = t[0][i];
  return c;
}
void printCube(Cube c){
  for(int i = 0; i < 9; i++){
    for(int j = 0; j < 12; j++)
      printf("%c", c.g[i][j] ? c.g[i][j] : ' ');
    printf("\n"); } }
////////////////////////////////////////////////////////////////////////////////
// Reconstruction of a set from its pairwise sums
////////////////////////////////////////////////////////////////////////////////
// returns empty vector on failure // UVa 10202, SRM 182 1000
vector<int> algo(int least, multiset<int> seq) {
  vector<int> ans(1,least);
  while(seq.size()) {
    ans.push_back(*seq.begin()-least);
    for(int i=0; i+1<ans.size(); ++i) {
      if(seq.find(ans[i]+ans.back())==seq.end()) return vector<int>(0);
      seq.erase(seq.find(ans[i]+ans.back()));
    }
  }
  return ans;
}
vector<int> reverse(multiset<int> &seq) {
  vector<int> ans;
  set<int> used;
  int i=2; __typeof( seq.begin() ) it=seq.begin();
  ++it; ++it;
  int s0=*seq.begin(), s1=*++seq.begin();
  for(; (i*(i-1))/2<=seq.size() && i<seq.size(); ++i, ++it) {
    int least = -(*it-s0-s1)/2;
    if(least<0) continue;
    if((-(*it-s0-s1))&1) continue;
    if(used.count(least)) continue;
    used.insert(least);
    vector<int> a2=algo(least, seq);
    if(ans.size() && a2.size()) return vector<int>(0);
    if(a2.size()) ans=a2;
  }
  return ans; }
////////////////////////////////////////////////////////////////////////////////
// Calendar
////////////////////////////////////////////////////////////////////////////////
int mmm[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
map < string, int > sm;
int get_loc_cnt(int day, int month, bool leap){
  if(leap) mmm[1]++;
  int out = 0;
  for(int i = 0; i < month; i++) out += mmm[i];
  out += day;
  if(leap) mmm[1]--;
  return out;
}
bool leap(int year, bool old){
  if(old) return !(year%4);
  return !(year%400) || (!(year%4) && year%100);
}
int get_cnt(int day, int month, int year, int old){
  int out = 0;
  for(int i = 242; i < year; i++) out += 365 + leap(i, old);
  return out + get_loc_cnt(day, month, leap(year, old));
}
int year, month, day;
void get_date(int cnt, bool old){
  year =  242;
  month = 0;
  while(cnt >= 365 + leap(year, old)){
    cnt -= 365 + leap(year, old);
    year++;
  }
  while(cnt >= mmm[month] + (month == 1 && leap(year, old))){
    cnt -= mmm[month] + (month == 1 && leap(year, old));
    month++;
  }
  day = cnt;
}
string mn[12]={"January", "February", "March", "April", "May", "June",
	       "July", "August","September", "October", "November", "December"};
string wd[7]={"Monday", "Tuesday", "Wednesday", "Thursday", "Friday",
	      "Saturday", "Sunday"};
string a, c;
int b, d;
int main(){
  for(int i = 0; i < 12; i++) sm[mn[i]] = i;
  while(cin >> a >> b >> c >> d && a != "#"){
    int o = get_cnt(b - 1, sm[c], d, true);
    int n = get_cnt(b - 1, sm[c], d, false); // - 1;
    if(wd[(o + 5)%7] == a){
      get_date(o, false);
      cout << a << " " << day + 1 << " " << mn[month] << " " << year << endl;
    }else{
      get_date(n, true);
      cout << a << " " << day + 1 << "* " << mn[month] << " " << year << endl;
    }
  }
  return 0; }
////////////////////////////////////////////////////////////////////////////////
// Recursive Descent Parser
////////////////////////////////////////////////////////////////////////////////
// Write things in Left recursive order, and do this mechanically again
double values[256];
double eval_expr(const char* strg, const char* &next);
double eval_number(const char* strg, const char* &next) {
  if (*strg == '(') {
    double result = eval_expr(strg+1, next);
    ++next; // This is the ')'
    return result;
  }
  // This is just for 10932
  if (*strg >= 'a' && *strg <= 'z') {
    next = strg+1;
    return values[*strg];
  }
  // End for special code
  char* dummy;
  double result = strtod(strg, &dummy);
  next = dummy;
  return result;
}
double eval_factor(const char* strg, const char* &next) {
  double acc = eval_number(strg, next);
  while(*next) {
    if (*next == '*') acc *= eval_number(next+1, next);
    else if (*next == '/') acc /= eval_number(next+1, next);
    else return acc;
  } // No need to return anything
  return acc;
}
double eval_expr(const char* strg, const char* &next) {
  double acc = eval_factor(strg, next);
  while(*next) {
    if (*next == '+') acc += eval_factor(next+1, next);
    else if (*next == '-') acc -= eval_factor(next+1, next);
    else return acc;
  } // Don't return anything....
  return acc;
}
double eval(const string& strg, int idx = 0) {
  const char* dummy;
  return eval_expr(strg.c_str()+idx, dummy);
}
int main() {
  string input;
  cout.setf(ios::fixed, ios::floatfield);
  cout.precision(2);
  while(getline(cin, input)) {
    if (input.size() >= 2 && input[1] == '=')
      values[ input[0] ] = eval(input, 2);
    else
      cout << eval(input) << endl;
  }
  return 0; }
////////////////////////////////////////////////////////////////////////////////
// N-Queens problem (formula)
////////////////////////////////////////////////////////////////////////////////
vector < int > get_queens(int n){ // WARNING: there is no solution for n = 2, 3
  if(n == 1) return vector < int > (1, 1);
  int r = n%12; vector < int > out;
  for(int i = 2; i <= n; i += 2) out.push_back(i);
  if(r == 3 || r == 9)
    for(int i = 0; i + 1 < (int)out.size(); i++) swap(out[i], out[i + 1]);
  int s = out.size();
  for(int i = 1; i <= n; i += 2) out.push_back(i);
  if(r == 8) for(int i = s; i + 1 < n; i += 2) swap(out[i], out[i + 1]);
  if(r == 2){
    swap(out[s], out[s + 1]); // 1 <-> 3
    for(int i = s + 2; i + 1 < n; i++) swap(out[i], out[i + 1]);
  }
  if(r == 3 || r == 9) for(int k = 0; k < 2; k++)
    for(int i = s; i + 1 < n; i++) swap(out[i], out[i + 1]);
  return out; }
////////////////////////////////////////////////////////////////////////////////
// IDEAS (aka Bart's guide to solving any ACM problem)
////////////////////////////////////////////////////////////////////////////////
/*
Max Flow (min cost)
Bipartite Matching (max weighted)
Hamiltonian Path
Euler Path
Bidirectional Search
Linear Programming (Simplex)
2-SAT
Strongly Connected Components
Articulation Points (Bridge Detection)
Knuth-Morris-Pratt String Matching
Topological Sort
Work backward from the end
Work forward from the front
Binary search on the answer
Some subproblem is greedy / simple (e.g. cannot be directed iff
bridges)
If you need to come up with the lexocographically least list of
something, try adding the smallest possible and see if you can still make the
list; then try the next smallest; etc.
"Invert" an array, as in Longest Increasing Subsequence, such that
a[i]=j means b[j]=i where b is a inverse
Markov Chains
Make it O(output)
Random search
And if all else fails... hope the input data sucks

Data Structures:
Tournament Tree
Trie
STL: vector, map, set, deque
Graph

Basic:
Dynamic Programming
Shortest Path: Bellman Ford, Dijkstra, BFS, DFS, FW, NOT most DP
Work in ints if you can, don't if you can't
Work in long longs if you're worried about bounds on ints
Have a base case for your recursion
Remember a seen[] array for your BFS
If you're going to try to cover all cases on your own, come up with
    as many as you can, then get a teammate to find more, then get the
    last teammate to find more.

Dynamic Programming:
Backpacker
Coin Changer
Refactor the DP ("What's the length of my LIS at this point?" ->
    "What's the first point that gives me this LIS length?")
Be careful, when doing iterative, to do things in the right order
If you're 'doing loop detection' or 'dealing with loops' in your DP,
    it's almost certainly wrong.  Honestly.  Really.  Believe me.
Need the Nth something?  Find how many somethings there are using DP,
    and subtract off until you find the Nth.

Brute Force:
Bidirectional Search
Split & Merge
Iterative Deepening
n*2^n DP

Geometric:
Convex Hull
Quad Tree
Simplex
Voronoi Diagrams
Rotating Calipers
////////////////////////////////////////////////////////////////////////////////
// THEOREMS
////////////////////////////////////////////////////////////////////////////////
BURNSIDE'S LEMMA:
   Let G be a finite group that acts on a set X. Then the number of orbits is
   equal to the average number of points fixed by an element of G.
CATALAN NUMBER: 1/(n+1)*nCr(2n, n) = nCr(2n, n)-nCr(2n, n-1), c_14 = 2674440
   = # of balanced paranthesis expression of length 2n
   = # of binary trees with n+1 leaves
   = # of non-isomorphic full binary trees where n vertices have children
CAYLEY'S FORMULA:
   # of trees on n labeled vertices is n^{n-2}.
   # of span trees in bipartite graph with p,q vertices is q^{p-1}*p^{q-1}
   # of span trees on K_n with degrees d_1,d_2,... for vertex 1,2,... is
   (n-2)! / ( (d_1-1)! (d_2-1)! (d_3-1)!... )
CHAPMAN-KOLMOGOROV EQN: For a Markov chain, let 0 < k < n, then
   p_{ij}^n = \sum_{all states s} p_{is}^k * p_{sj}^{n-k}
CONIC SECTIONS: ax^2 + bxy + cy^2 + dx + ey + f = 0
   b^2 - 4ac: >0 for hyperbola, = 0 for parabola, < 0 for ellipse
   a + c, b^2 - 4ac: invariant under rotations, translations
   (f invariant under rotations around (0,0) only)
   tangent at point (x0,y0) on curve:
   a*x0*x + b*(x0*y+y0*x)/2 + c*y0*y + d*(x+x0)/2 + e*(y+y0)/2 + f = 0
   angle from +x axis to major axis of ellipse (modulo pi):
   theta = atan2(b,c-a)/2; if (b*sin(2*theta) < 0) theta += PI/2;
CRAMER'S RULE: The solution to a linear system Ax = b is given by
   x_i = |Ai|/|A|, where Ai is A with column i replaced by b.
DERANGEMENTS: n! * (1 - 1/1! + 1/2! - 1/3! + .. + (-1)^n / n!)
EDGE COVER: Get maximum matching, add edges(greedy)until all vertices covered
GENERATING FUNCTION (GF):
   Ordinary GF: a_0 + a_1 x + a_2 x^2 + a_3 x^3 + ... (combinations)
   Exponential GF: a_0 + a_1/1! x + a_2/2! x^2 + a_3/3! x^3 + ... (perm)
   (expansion for e^x, e^{-x}, e^{kx} are often useful)
GREAT CIRCLE DISTANCE:
   R*acos(sin(phi1)sin(phi2)+cos(phi1)cos(phi2)cos(delta_lambda))
HALL'S THEOREM:
   Let S = {S1, S2, ... } be a collection of finite sets. A transversal for S
   is a set X = {x1, x2, ...} of distinct elements (where |X| = |S|) with the
   property that for all i, x_i belongs to S_i. The marriage condition for S:
   for any subcollection T in S, |T| <= |union of all sets in T|.
   There exists an transversal X iff S meets the marriage condition.
HAVEL-HAKIMI ALGORITHM:
   input: a degree sequence S; output: can produce graph?
   S = sequence(d1,d2,d3...) di >= di+1
   1 if di >= n fail
   2 if odd number of odd degress fail
   3 if di < 0 fail
   4 if all di = 0 success
   5 reorder S into non-increasing
   6 let k=d1
   7 remove d1 from S
   8 subtract 1 from first k terms of S (connect?)
   9 goto 3
   Note: not always connected
HOOK LENGTH FORMULA (number of Young tableaux):
   = (# of boxes)! / prod_{all boxes} hook(box) 
   where hook(box) = # boxes to right + # boxes below + 1
INTEGER SEQUENCES:
   Integer partitions: f(n,k) = f(n-k,k) + f(n,k-1)
       sum over all k: f(60) = 966467, f(77) = 10619863
   1st Stirling number: number of permutations on n elements with k cycles
       [n k] = [n-1 k-1] + (n-1) [n-1 k]. Note sum_k [n k] = n!
   2nd Stirling number: number of ways to partition n items into k sets
       {n k} = k{n-1 k} + {n-1 k-1}
   Bell number = # of ways to partition n items into sets,
       B_n = sum_k {n k} = sum_k (n choose k) B_k, B_8 = 4140, B_12 = 4213597
KONIG'S THEOREM:
   In any bipartite graph, max matching = min vertex cover
   (Note: |max independent set| + |max matching| =  number of vertices,
   because complement of vertex cover is independent set)
   Vertex cover: BFS from unmatched vertices, follow augmenting paths, keep
   visited array, all vertices odd distance away are in max vertex cover.
KUMMER'S THEOREM: integers a, b, prime p
   p^t divides binom(a+b,a) iff t<=# of carries in the addition a+b in base p
LAGRANGE INTERPOLATION: Given (x1, y1), ..., (xn, yn), interpolate
   p(x) = \sum_{i=1}^n { yi * \prod_{j!=i} [(x-xi)/(xi-xj)] }
LOWEST COMMON ANCESTOR IN TREE: N nodes, create arrays E[2N], L[2N], H[N].
   E contains indices in an Euler path starting from the root of the tree.
   L[i] = depth(E[i]), H[i] is earliest index j such that E[j] = i.
   If H[a]<H[b], then LCA(a,b) = E[ (argmin_{H[a]<=i<=H[b]} L[i]) ].
LUCAS THEOREM: integers a, b, prime p
   a = (a_k a_{k-1}...a_1 a_0), b = (b_k b_{k-1}...b_1 b_0) in base p
   /a\ ----- /a_k\ /a_{k-1}\     /a_1\ /a_0\
   \b/ ----- \b_k/ \b_{k-1}/ ... \b_1/ \b_0/  mod p
MILLER-RABIN: For odd 2<n<2^61, let n-1=d*2^s with odd d. n is composite iff
   for some prime a<min(n,24): (a^d)%n!=1 && for all 0<=r<s, (a^(d*2^r))%n!=n-1
MIN MEAN COST CYCLE:
   Let G be a graph with n vertices, v be a vertex, k be an integer in [0, n-1]
   and d_k(v) be the min cost of a length k walk ending at v. Then among cycles
   in G, the min mean cost per edge is min_v(max_k(( d_n(v) - d_k(v))/(n - k) ))
MOORE'S K-NIM:
   Write binary expansions of pile sizes, for every position check that sum of
   digits across all pile expansions is divisible by k+1. If this holds for
   all positions, 2nd player wins. Otherwise, 1st player wins.
PICK'S THM: Area = boundary / 2 + interior - 1
PISANO PERIOD: Period of Fibonacci numbers mod n; Pisano period <= 6n
PLANAR GRAPHS:
   V-E+F=2 (so E, F are O(V)); also vertex with minimum degree has degree <=5
   5-coloring a planar graph: (O(n^2) time)
   1) Find vertex v_0 with least degree (<=5)
   2) 5-color the rest of the graph, while building connected components
   3) If all 5 neighbours of v_0 have different colours, find two vertices in
   different connected components and change color of one of those
QUADRATURE (SIMPSONS): int(f, a, b) = (b-a)/6 * [f(a) + 4f((a+b)/2) + f(b)]
RATIONAL ROOT THEOREM:
   Let p = a0 + a1*x + ... + an * x^n, a0 != 0, an != 0. Then all rational
   root of p takes the form x = +/-(r/q), where r|a0, q|an, (r, q) = 1.
READING FROM FILE: freopen("something.in", "r", stdin);
SOLID ANGLE:
   omega is solid angle subtended by vectors a, b, c
   tan(omega/2) = det(a,b,c)/(|a||b||c|+dot(a,b)|c|+dot(a,c)|b|+dot(b,c)|a|)
   cone with apex angle 2*theta, solid angle subtended is 2*PI*(1-cos(theta))
STIRLING'S FORMULA (often can use log(n!)):
   sqrt(2PI*n)*pow(n/e,n)*exp(1/(12*n+1))<n!<sqrt(2PI*n)*pow(n/e,n)*exp(1/12*n)
SUM OF SQUARES FUNCTION (CIRCLE LATTICE POINTS):
   r_2(n) = # of ways for [n=sum of 2 squares] (with 0s, signs different, n>=1)
       =0 if n has any prime factor of the form 4k+3 with odd multiplicity
   else=4*\prod{b_i+1}, b_is = multiplicities of prime factors of the form 4k+1
   # of lattice points on circle of radius R with integer center N(R)=r_2(R^2)
SYLVESTER MATRIX:
   Let p=p0 + p1*x +...+ pn*x^n, q=q0 + q1*x +...+ qn * x^n, r = gcd(p, q).
   Define a (n+m)x(n+m) matrix S where first row = (pn, ... p1, p0, 0, ... 0).
   The second row is first row shifted right by once, and so forth.
   The (n+1) row = (qm, ... q1, q1, 0, ... 0). The (n+2)th row is shifted to
   the right by once and so forth. In this case: deg(r) = m + n - rank(S)
TOTIENT FUNCTION:
   if (gcd(a,b) == 1) { a^-1 = a^(phi(b)-1) (mod b), phi(a,b) = phi(a)*phi(b) }
   phi(p^a) = (p-1) * p^(a-1)
TRIANGLE AREA: side lengths = (a, b, c), a>=b>=c,
   A = \frac{1}{4}\sqrt{(a+(b+c)) (c-(a-b)) (c+(a-b)) (a+(b-c))}
USEFUL IDENTITIES:
   log(1 - x)                 =  -\sum_{i=1}^{\infty} x^n/n
   \sum_{i=1}^n i^2	 	     =	n * (n+1) * (2n+1) / 6
   \sum_{i=1}^n i^3	  	     =	[n * (n+1) / 2]^2
   \sum_{i=1}^n nCr(n, i)	 =	0
   \sum_{i=1}^n nCr(i, k) 	 =	nCr(n+1, k+1)
   \sum_{i=1}^n nCr(k+i, i)	 =	nCr(n+k+1, n)
WARNSDORFF'S RULE: (applicable to brute-force search for Hamiltonian paths)
   Choose the square among those immediately accessible by the knight move that
   would give the fewest possible moves following the move to that square
*/
