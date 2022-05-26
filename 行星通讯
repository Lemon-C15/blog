#include <bits/stdc++.h>
using namespace std;
 
struct Point{
    int x, y ,z;
    Point(){};
    Point(int a, int b ,int c){x = a;y = b;z = c;}
    bool operator == (Point &temp ){
    return x == temp.x && y == temp.y && z == temp.z;
    }
}p[5000 + 10];
 
//map<Point,int> mp;
 
int main(){
    int n;
    int tot = 0;
    scanf("%d",&n);
    int ex,ey,ez;
    scanf("%d %d %d",&ex,&ey,&ez);
    for(int i = 2;i <= n ;i ++){
        int x , y ,z;
        scanf("%d %d %d",&x,&y,&z);
        x -= ex ,y -= ey ,z -= ez;
        if(x < 0){
            x = -x;
            y = -y;
            z = -z;
        }else if(x == 0){
            if(y < 0){
                y = -y;
                z = -z;
            }
        }else if(y < 0){
            if(z < 0){
                z = -z;
            }
        }
        int gcd = __gcd(__gcd(abs(x),abs(y)),abs(z));
        x /= gcd,y/=gcd,z/=gcd;
        Point temp;
        temp.x = x , temp.y = y, temp.z = z;
        
        if(tot == 0){
        p[++tot] = (Point){x,y,z};
        }
        else{
            int flag = 0;
            for(int j = 1;j <= tot;j ++ ){
                if((Point){x,y,z} == p[j]) flag ++;
            }
            if(!flag)p[tot++] =(Point){x,y,z};
        }
    }
    printf("%d",tot);
}
