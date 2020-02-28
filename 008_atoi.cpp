class Solution {
public:
int myAtoi(string str)
{
    int negative = 0, res = 0, i = 0;
    while (true)
    {
        if (str[i] == ' ')
            i++;
        else
            break;
    }
    if (str[i] == '-')
    {
        negative = 1;
        i++;
    }else if (str[i] == '+')
    {
        i++;
    }
    else if (!(str[i] - '0' >= 0 && '9' - str[i] >= 0))
        return 0;
    vector<int> v;
    while (str[i] - '0' >= 0 && '9' - str[i] >= 0)
    {
        int temp = str[i++] - '0';
        if (negative)
            temp = -temp;
        v.push_back(temp);
    }
    while (!v.empty())
    {
        if ((res > INT_MAX / 10) || (res == INT_MAX / 10 && v.front() > 7))
            return INT_MAX;
        if ((res < INT_MIN / 10) || (res == INT_MIN / 10 && v.front() < -8))
            return INT_MIN;
        res = res * 10 + v.front();
        v.erase(v.begin());
    }
    return res;
}
};