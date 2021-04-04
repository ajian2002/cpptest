//快排
void strqsort(char *before[PATH_MAX], int now[], int l, int r)
{
    int j = l, k = r;
    if (l < r)
    {
        int temp = now[l];
        while (l != r)
        {
            while (l < r && strcmp(before[now[r]], before[temp]) >= 0)
                r--;
            //p[l] = p[r];
            now[l] = now[r];
            while (l < r && strcmp(before[now[l]], before[temp]) <= 0)
                l++;
            //p[r] = p[l];
            now[r] = now[l];
        }
        if (r == l)
            now[r] = temp;

        strqsort(before, now, r + 1, k);
        strqsort(before, now, j, r - 1);
    }
}