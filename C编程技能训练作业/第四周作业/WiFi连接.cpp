#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
 
class Point{
public:
    double x, y;
    Point(double x = 0, double y = 0) : x(x), y(y) {}
};
 
int n, m;
vector<Point> points;
vector<Point> router;
 
 
double getDist(const Point &p1, const Point &p2){
    double x = p1.x - p2.x;
    double y = p1.y - p2.y;
    return sqrt(x * x + y * y);
}
 
 
int getNearestRouter(const Point &p){
    int nearest = 0;
    double dist = getDist(p, router[nearest]);
    for (int i = 1; i < m; i++){
        double d = getDist(p, router[i]);
        if (d < dist){
            nearest = i;
            dist = d;
        }
    }
    return nearest;
}
 
int countConnections2(Point &start, Point &end){
    Point s = start;
    double stepX, stepY;
    if (start.x == end.x){
        stepX = 0;
        stepY = 0.5;
    }
    else{
        double k = (end.y - start.y) / (end.x - start.x);
        stepX = 0.5;
        stepY = stepX * k;
    }
    int res = -1;
    int nearest = -1;  //没有序号为 -1 的路由器
    while (s.x <= end.x){
        int nextN = getNearestRouter(s);
        if (nextN != nearest){
            res++;
            nearest = nextN;
        }
        s.x += stepX;
        s.y += stepY;
    }
    return res;
}
 
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i ++){
        Point temp;
        cin >> temp.x >> temp.y;
        points.push_back(temp);
    }
    for (int i = 0; i < m; i ++){
        Point temp;
        cin >> temp.x >> temp.y;
        router.push_back(temp);
    }
    int k;
    cin >> k;
    while (k --){
        int start, end;
        cin >> start >> end;
        start--;
        end--;
        
        if (points[start].x < points[end].x)
            cout << countConnections2(points[start], points[end]) << endl;  //左侧
        else if (points[start].x == points[end].x){
            if (points[start].y < points[end].y)
                cout << countConnections2(points[start], points[end]) << endl;  // 正下方
            else
                cout << countConnections2(points[end], points[start]) << endl;  //正上方
        }
        else
            cout << countConnections2(points[end], points[start]) << endl;  //右侧
    }
    return 0;
}