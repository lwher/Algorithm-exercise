/*
	计算几何部分模板汇总
	实现以重载运算符为基础 每个部分只写1~2个函数 
*/
#define eps 1e-9
struct point(){
	double x,y;
};

//求平面两点间的距离
double dist(point a,point b){
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

//向量相减
point operator -(const point &a,const point &b){
	point c;c.x=a.x-b.x;c.y=a.y-b.y;
	return c;
}

//向量叉积
double operator *(const point &a,const point &b){
	return a.y*b.x-a.x*b.y;
}

//向量点积  注意：此处符号与叉积相同，可自行修改 
double operator *(const point &a,const point &b){
	return a.x*b.x+a.y*b.y;
}

//判断 A -> B -> C的拐弯方向  =0 共线，<0 向左，>0 向右  
double Turnto(point A,point B,point C){
	return (C-A)*(B-A); 
}

/*判断点是否在线段上
1、判断其是否在该线段所在的直线上(该点指向线段两个端点的向量共线)
2、判断该点指向线段两个端点的向量点积是否是负数 
*/

//判断两条线段是否相交 
struct line{
	point a,b;
};
bool quick_check(line A,line B){ //矩形快速排斥
	if(max(A.a.x,A.b.x)<min(B.a.x,B.b.x) ||
	min(A.a.x,A.b.x)>max(B.a.x,B.b.x) ||
	max(A.a.y,A.b.y)<min(B.a.y,B.b.y) ||
	min(A.a.y,A.b.y)>max(B.a.y,B.b.y)) return 0;
	else return 1; 
}
bool isInter(line A,line B){ //0:两条线段不相交 1:相交 
	if(!quick_check(A,B)) return 0;
	if(Turnto(A.a,A.b,B.a)*Turnto(A.a,A.b,B.b)<eps && 
	Turnto(B.a,B.b,A.a)*Turnto(B.a,B.b,A.b)<eps) return 1;
	else return 0;  
}

//判断线段是否与直线相交，只需直线是否跨立线段即可
bool isInter(line A,line B){ // A为直线 B为线段 
	if(Turnto(A.a,A.b,B.a)*Turnto(A.a,A.b,B.b)<eps) return 1;
	else return 0;
}

//判断两条直线是否相交，只要判断是不是平行的就好(重合根据情况考虑)
bool isInter(line A,line B){//A,B均为直线
	if(fabs((A.a-A.b)*(B.a-B.b))<eps) return 0;
	else return 1; 
}

//求两条直线的交点
point Get_InterPoint(line A,line B){
	double k1,k2,k3;point Ans;
	k1=(A.b-A.a)*(B.a-A.a);
	k2=(B.b-A.a)*(A.b-A.a);
	k3=k1/(k1+k2);
	Ans.x=B.a.x+(B.b.x-B.a.x)*k3;
	Ans.y=B.a.y+(B.b.y-B.a.y)*k3;
	return Ans;
}

//对于一条两个端点都是整点的线段，该线段上除了端点的整点数 on = gcd(detX,detY)-1
//给定一个整点多边形的每个顶点（顺时针或逆时针顺序），求其边界上的整点数
int gcd(int a,int b){
	return (b==0)?a:gcd(b,a%b);
} 
int getOn(int tot,const point P[]){//tot:顶点数 P：按一定顺序排放的顶点 
	int res=tot;
	for(int i=1;i<tot;i++){
		res+=gcd(abs(P[i+1].x-P[i].x),abs(P[i+1].y-P[i].y))-1;
	}
	res+=gcd(abs(P[1].x-P[tot].x),abs(P[1].y-P[tot].y))-1;
	return res;
}

//对于给定的任意多边形，可以用三角剖分+向量叉积的方法求其面积
int getS(int tot,const point P[]){
	double res=0;
	for(int i=1;i<tot;i++) res+=P[i]*P[i+1];
	res+=P[tot]*p[1];
	res=fabs(res)*0.5;
	return res;
} 

//Pick定理：存在某个顶点多边形，设其边界上的整点数为on,面积为S，则其内部的整点数为 in = ( S * 2 + 2 - on ) / 2; 

//向量旋转 把一个向量A逆时针旋转alp的弧度
point rotate(const point &A, double alp){
	point res;
	double sinalp = sin(alp), cosalp = cos(alp);
	res.x = A.x * cosalp - A.y * sinalp;
	res.y = A.x * sinalp + A.y * cosalp;
	return res;
}

//求两圆交点
struct circle{
	double x,y,r;
};
void getpoint(circle a,circle b,point &A,point &B){//传入两个圆和两个点，最后答案为A,B 
      double d,k;point t;
      d=dist(a,b);//圆心距 
      k=(a.r*a.r+d*d-b.r*b.r)/(2.000*d*a.r);// k cos
      k=acos(k);// k-> 弧度
      t.x=(b.x-a.x)/d;t.y=(b.y-a.y)/d;
      A.x=a.x+a.r*(t.x*cos(k)-t.y*(sin(k)));A.y=a.y+a.r*(t.y*cos(k)+t.x*sin(k));
      B.x=a.x+a.r*(t.x*cos(k)+t.y*(sin(k)));B.y=a.y+a.r*(t.y*cos(k)-t.x*sin(k));
} 

