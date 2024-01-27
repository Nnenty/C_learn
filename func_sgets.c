char *s_gets(char *arr, int size)
{
    char *ret_val;
    int i = 0;

    ret_val = fgets(arr, size, stdin);
    if (ret_val)
    {
        while (arr[i] != '\n' && arr[i] != '\0')
        {
            i++;
        }
    }
    if (arr[i] == '\n')
    {
        arr[i] = '\0';
    }
    else
    {
        while (getchar() != '\n')
        {
            continue;
        }
    }
    return ret_val;
}
