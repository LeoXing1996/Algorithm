#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define m 10
#define n 11
typedef struct{
    int route[10][2];
    int front;
    int rear;
    int size;
}queue;

void init(queue*);
void EnQueue(queue*, int, int);
void DeQueue(queue*, int*, int*);
int bfs();
char Maze[m][n]={"#S######.#",
                 "......#..#",
                 ".#.##.##.#",
                 ".#........",
                 "##.##.####",
                 "....#....#",
                 ".#######.#",
                 "....#.....",
                 ".####.###.",
                 "....#...G#"};

int move[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};    //右 下 左 上

int main(){
    int count;
    count = bfs();
    printf("%d", count);
    //getchar();
    return 0;
}

int bfs(){
    int count[m][n-1];
    int start_x=0;
    int start_y=1;
    // int end_x=9;
    // int end_y=8;
    queue q;
    init(&q);
    count[start_x][start_y]=0;
    EnQueue(&q, start_x, start_y);
    while(q.front!=q.rear){
        int x, y;
        DeQueue(&q, &x, &y);
        Maze[x][y] = '#';
        for(int i=0; i<4; ++i){
            int dx=x+move[i][0];
            int dy=y+move[i][1];
            if(dx>=0 && dx<m && dy>=0 && dy<n-1 && Maze[dx][dy]!='#'){
                EnQueue(&q, dx, dy);
                count[dx][dy] = count[x][y]+1;
                if(Maze[dx][dy]=='G')
                    return count[dx][dy];
            }
        }
    }
}

void init(queue* q){
    q->front=0;
    q->rear=0;
    q->size=10;
}

void EnQueue(queue* q, int x, int y){
    q->route[q->rear][0] = x;
    q->route[q->rear][1] = y;
    q->rear = (q->rear+1+q->size) % q->size;
}

void DeQueue(queue* q, int* x, int* y){
    *x=q->route[q->front][0];
    *y=q->route[q->front][1];
    q->front = (q->front+1+q->size) % q->size;
}