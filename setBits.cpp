int setBits (int n)
{
    int counter = 0, itr = 0;
    while (n != 0 && itr < 32)
        counter += (n >> itr++) & 1;
    return counter;
}