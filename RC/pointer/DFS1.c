#include <stdio.h>
#include <math.h>

typedef long long LL;

typedef struct source_t {
    LL x;
    LL y;
    int visited;
} source_t;

#define MAX_SOURCE_CNT 1001

typedef struct source_arr_t {
    source_t arr[MAX_SOURCE_CNT];
    int len;
} source_arr_t;

#define MAX_STACK_LEN 100

typedef struct stack_t {
    int arr[MAX_STACK_LEN];
    int top;
} stack_t;

void push(stack_t *stack, int elt) {
    stack->arr[stack->top++] = elt;
}

int pop(stack_t *stack) {
    return stack->arr[--stack->top];
}

int top(const stack_t *stack) {
    return stack->arr[stack->top - 1];
}

double distance(const source_t *p1, const source_t *p2) {
    return sqrt(pow((double)(p1->x - p2->x), 2) + pow((double)(p1->y - p2->y), 2));
}

double norm(const source_t *point) {
    return sqrt(pow((double)(point->x), 2) + pow((double)(point->y), 2));
}

double dfsHelper(source_arr_t *source, stack_t *stack, double *water, double *time, int cur) {
    static double maxTime = -1;

    // 1. Visit
    source_t *ref = &source->arr[cur];
    double dist = distance(ref, (source->arr + top(stack)));
    *water += -dist + 1000;
    *time += dist * 2 + 60;
    ref->visited = 1;

    // 0. Push Stack
    push(stack, cur);

    double remain = 10000 - norm(ref);
    if (remain <= *water) {
        if (maxTime == -1 || *time + remain * 2 < maxTime) maxTime = *time + remain * 2;
    } else {
        // 2. Recursion
        for (int i = 0; i < source->len; i++) {
            if (source->arr[i].visited) continue;
            if (distance(ref, source->arr + i) > *water) continue;
            dfsHelper(source, stack, water, time, i);
        }
    }

    // 3. Recurse
    pop(stack);
    *time -= dist * 2 + 60;
    *water += dist - 1000;
    return maxTime;
}

int main() {
    int N;
    scanf("%d", &N);


    source_arr_t sourceArr;
    sourceArr.arr[0].x = 0;
    sourceArr.arr[0].y = 0;
    sourceArr.arr[0].visited = 0;
    sourceArr.len = 1;

    for (int i = 0; i < N; i++) {
        LL x, y;
        scanf("%lld %lld", &x, &y);
        sourceArr.arr[sourceArr.len].x = x;
        sourceArr.arr[sourceArr.len].y = y;
        sourceArr.arr[sourceArr.len++].visited = 0;
    }

    double water = 0;
    double time = 0;

    stack_t stack;

    double maxTime = dfsHelper(&sourceArr, &stack, &water, &time, 0);

    if (maxTime != -1) printf("%lf\n", maxTime - 60);
    else printf("x\n");

    return 0;
}