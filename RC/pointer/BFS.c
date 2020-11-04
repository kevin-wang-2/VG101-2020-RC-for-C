#include <stdio.h>

typedef struct Point {
    int x, y;
} Point;

int main() {
    int width, height;
    scanf("%d %d", &width, &height);
    getchar();

    char graph[50][50];
    for (int i = 0; i < height; i++) {
        scanf("%[^\n]\n", graph[i]);
    }

    int x, y;
    scanf("%d %d", &x, &y);

    char identifier = graph[x][y];
    char closed[50][50] = {0};

    Point queue[255];
    int front = 0, rear = 0;

    queue[rear].x = x;
    queue[rear++].y = y;

    while (rear != front) {
        Point cur = queue[(front++) % 255];
        graph[cur.x][cur.y] = '#';

        if (cur.x - 1 >= 0 && closed[cur.x - 1][cur.y] == 0 && graph[cur.x - 1][cur.y] == identifier) {
            queue[rear % 255].x = cur.x - 1;
            queue[(rear++) % 255].y = cur.y;
            closed[cur.x - 1][cur.y] = 1;
        }
        if (cur.y - 1 >= 0 && closed[cur.x][cur.y - 1] == 0 && graph[cur.x][cur.y - 1] == identifier) {
            queue[rear % 255].x = cur.x;
            queue[(rear++) % 255].y = cur.y - 1;
            closed[cur.x][cur.y - 1] = 1;
        }
        if (cur.x + 1 < height && closed[cur.x + 1][cur.y] == 0 && graph[cur.x + 1][cur.y] == identifier) {
            queue[rear % 255].x = cur.x + 1;
            queue[(rear++) % 255].y = cur.y;
            closed[cur.x + 1][cur.y] = 1;
        }
        if (cur.y + 1 < width && closed[cur.x][cur.y + 1] == 0 && graph[cur.x][cur.y + 1] == identifier) {
            queue[rear % 255].x = cur.x;
            queue[(rear++) % 255].y = cur.y + 1;
            closed[cur.x][cur.y + 1] = 1;
        }
    }

    for (int i = 0; i < height; i++) printf("%s\n", graph[i]);
}