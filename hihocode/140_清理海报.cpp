/*************************************************************************
	> File Name: 140_清理海报.cpp
	> Author: 
	> Mail: 
	> Created Time: 四  3/ 9 14:02:51 2017
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<vector>
#include<set>

using namespace std;

vector< vector<int> > graph(1010);
vector< set<int> > cando(1010);
vector< set<int> > cnt(1010);
struct rectangle
{
    int x1, x2, y1, y2;
}rec[1010];

bool overlap(int i, int j) 
{
    if(rec[i].x1 >= rec[i].x2 || rec[i].y1 >= rec[i].y2 || rec[j].x1 >= rec[j].x2 || rec[j].y1 >= rec[i].y2)
        return false;
    bool flag = rec[i].x2 <= rec[j].x1 || rec[j].x2 <= rec[i].x1 || rec[i].y2 <= rec[j].y1 || rec[j].y2 <= rec[i].y1;
    flag = !flag;
    if(flag){
        if(rec[i].x1 > rec[j].x1 && rec[i].y1 > rec[j].y1) cando[i].insert(1);
        if(rec[i].x1 > rec[j].x1 && rec[i].y2 < rec[j].y2) cando[i].insert(2);
        if(rec[i].x2 < rec[j].x2 && rec[i].y2 < rec[j].y2) cando[i].insert(3);
        if(rec[i].x2 < rec[j].x2 && rec[i].y1 > rec[j].y1) cando[i].insert(4);
    }
    return flag;
}

void count(int n)
{
    for(int i = n-1; i >= 0; i--){
        cnt[i].insert(i);
        for(int j = 0; j < graph[i].size(); j++){
            cnt[i].insert(graph[i][j]);
            cnt[i].insert(cnt[ graph[i][j] ].begin(), cnt[ graph[i][j] ].end());
        }
    }
}

void init(int w, int h, int n)
{
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(overlap(i, j)){
                graph[i].push_back(j);
            }
        }
    }
    count(n);
}

int main()
{
    int w, h, n;
    freopen("in.txt", "r", stdin);
    scanf("%d%d%d", &w, &h, &n);
    for(int i = 0; i < n; i++)
        scanf("%d%d%d%d", &rec[i].x1, &rec[i].y1, &rec[i].x2, &rec[i].y2);
    init(w, h, n);
    int ans = 1, k = n;
    for(int i = 0; i < n; i++){
        if(cando[i].size() < 4 && cnt[i].size() > ans){
            ans = cnt[i].size();
            k = i + 1;
        }
    }
    printf("%d %d", ans, k);
    return 0;
}

