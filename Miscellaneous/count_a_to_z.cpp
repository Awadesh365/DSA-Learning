vector<ll> letter(26, 0);

for (ll i = 0; i < ans.size(); i++)
{
    char C = ans[i];
    if (C == 'a')
        letter[0]++;
    else if (C == 'z')
        letter[25]++;
    else if (C == 'b')
        letter[1]++;
    else if (C == 'y')
        letter[24]++;
    else if (C == 'c')
        letter[2]++;
    else if (C == 'x')
        letter[23]++;
    else if (C == 'd')
        letter[3]++;
    else if (C == 'w')
        letter[22]++;
    else if (C == 'e')
        letter[4]++;
    else if (C == 'v')
        letter[21]++;
    else if (C == 'f')
        letter[5]++;
    else if (C == 'u')
        letter[20]++;
    else if (C == 'g')
        letter[6]++;
    else if (C == 't')
        letter[19]++;
    else if (C == 'h')
        letter[7]++;
    else if (C == 's')
        letter[18]++;
    else if (C == 'i')
        letter[8]++;
    else if (C == 'r')
        letter[17]++;
    else if (C == 'j')
        letter[9]++;
    else if (C == 'q')
        letter[16]++;
    else if (C == 'k')
        letter[10]++;
    else if (C == 'p')
        letter[15]++;
    else if (C == 'l')
        letter[11]++;
    else if (C == 'o')
        letter[14]++;
    else if (C == 'm')
        letter[12]++;
    else if (C == 'n')
        letter[13]++;
}