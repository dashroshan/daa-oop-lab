namespace asc
{
    void sortInt(int *a, int n)
    {
        for (int i = 0; i < n; i++)
            for (int j = 1; j < n; j++)
            {
                if (a[j - 1] > a[j])
                {
                    int t = a[j - 1];
                    a[j - 1] = a[j];
                    a[j] = t;
                }
            }
    }
}