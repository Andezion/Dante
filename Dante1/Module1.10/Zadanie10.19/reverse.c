int reverse_vector(int *tab, int size)
{
    if (tab == NULL || size < 1)
    {
        return 1;
    }

    for (int i = 0; i < size / 2; i++)
    {
        int temp = *(tab + i);
        *(tab + i) = *(tab + size - i - 1);
        *(tab + size - i - 1) = temp;
    }

    return 0;
}
