int cycle(int n) {
    if (n % 2 == 0 || n % 5 == 0)
        return -1;
  
    int m = 0, n_div = 10;

    do
    {
        m += 1;
        n_div = (n_div % n) * 10;
        if (n_div == 10)
            return m;
    } while (true);
}
