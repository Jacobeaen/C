#include <stdio.h>
#include <math.h>

struct Point {
        int x;
        int y;
};

double lenght(struct Point p)
{
    return sqrt(p.x*p.x + p.y*p.y);
}

void midle(struct Point p)
{
    printf("x: %.2lf, y: %.2lf", p.x / 2.0, p.y / 2.0);
}

void setCoord(struct Point *p, int x, int y)
{
    p->x = x;
    p->y = y;
}

int main(void)
{
    int x, y;
    printf("Enter point coords:\n");
    scanf("%d %d", &x, &y);

    struct Point point;

    setCoord(&point, x, y);
    printf("Length: %.2lf\n", lenght(point));
    printf("Middle: ");
    midle(point);

    return 0;
}