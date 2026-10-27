class Solution
{
public:

    int lcm(int a, int b)
    {
        if(a==b)
            return a;
        if(a > b)
        {
            int count = 1;
            while(true)
            {
                if((a*count)%b==0)
                    return a*count;
                count++;
            }
        }
        int count = 1;
        while(true)
        {
            if((b*count)%a==0)
                return b*count;
            count++;
        }
        return -1;
    }

    int nthMagicalNumber(int n, int a, int b)
    {
        long long int comm = lcm(a,b);
        long long int first = (((comm*2) - comm) / a) - 1;
        long long int second = (((comm*2) - comm) / b) - 1;

        long long int landmark = (n / (first + second + 1)) * comm;
        long long int offset = n % (first + second + 1);

        long long int p = landmark, q = landmark;
        long long int ans = landmark;
        for(int i=1;i<=offset;i++)
        {
            if(p+a < q+b)
            {
                ans = p+a;
                p = p+a;
            }
            else
            {
                ans = q+b;
                q = q+b;
            }
        }

        return (ans%1000000007);
    }
};
