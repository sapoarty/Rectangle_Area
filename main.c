#include <stdio.h>
#include <string.h>

char *find_left_up(char *strArr[])
{
    int   n = 0;
    char* curr_arr = "(9 9)";

    while (n < 4)
    {
        if (*(curr_arr + 1) >= *(strArr[n] + 1) && *(curr_arr + 3) >= *(strArr[n] + 3))
            curr_arr = strArr[n];
        n++;
    }
    return (curr_arr);
}

char *find_left_bottom(char *strArr[])
{
    int   n = 0;
    char* curr_arr = "(9 0)";

    while (n < 4)
    {
        if (*(curr_arr + 1) >= *(strArr[n] + 1) && *(curr_arr + 3) <= *(strArr[n] + 3))
            curr_arr = strArr[n];
        n++;
    }
    return (curr_arr);
}

char *find_right_up(char *strArr[])
{
    int   n = 0;
    char* curr_arr = "(0 9)";

    while (n < 4)
    {
        if (*(curr_arr + 1) <= *(strArr[n] + 1) && *(curr_arr + 3) >= *(strArr[n] + 3))
            curr_arr = strArr[n];
        n++;
    }
    return (curr_arr);
}

char *find_right_bottom(char *strArr[])
{
    int   n = 0;
    char* curr_arr = "(0 0)";

    while (n < 4)
    {
        if (*(curr_arr + 1) <= *(strArr[n] + 1) && *(curr_arr + 3) <= *(strArr[n] + 3))
            curr_arr = strArr[n];
        n++;
    }
    return (curr_arr);
}

// Here is the solution where we identify position of all the corners
// But also easier solution is exist with just searching max and min of X and Y
void RectangleArea(char * strArr[], int arrLength) {
    int width;
    int height;
    char *left_up;
    char *left_bottom;
    char *right_up;
    char *right_buttom;
    int n;

    left_up = find_left_up(strArr);
    left_bottom = find_left_bottom(strArr);
    right_up = find_right_up(strArr);
    right_buttom = find_right_bottom(strArr);

    width = *(right_up + 1) - *(left_up + 1);
    height = *(left_bottom + 3) - *(left_up + 3);

    printf("%d\n", width * height);
}

int main(void) {

    // keep this function call here
    char * A[] = {"(1 1)","(1 3)","(3 1)","(3 3)"};
    int arrLength = sizeof(A) / sizeof(*A);
    RectangleArea(A, arrLength);
    return 0;

}