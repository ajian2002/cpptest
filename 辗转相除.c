//```
int yue(int x, int y)
{
    int r;
    r = x % y;
    if (r != 0)
    {
        x = y;
        y = r;
        yue(x, y);
    }
    else
    {
        return y;
    }
}
//```
