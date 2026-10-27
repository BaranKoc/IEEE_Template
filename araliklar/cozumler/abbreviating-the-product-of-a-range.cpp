class Solution {
public:
    string abbreviateProduct(int left, int right) {

        double upper = 1;

        long long lower = 1L;

        long long Offset = 1e12;

        long long cutOffset = 1e5;

        double product = 0.0;

        int trailing = 0;

        for(int i=left;i<=right;i++)
        {

            product +=  log10(i);

            upper *= i;
            lower *= i;

            while(upper>=Offset)upper/=10;

            while(lower%10==0)lower/=10,trailing++;

            lower %= Offset;
        }

        int digitLength = (int)product + 1 - trailing;

        while(upper>=cutOffset)upper/=10;
        lower %= cutOffset;

        int upperInt = upper;

        if(digitLength<=10)
        {

            string result(digitLength,'0');
            string upperStr = to_string(upperInt);
            string lowerStr = to_string(lower);

            for(int i=0;i<upperStr.length() && digitLength >0; i++,digitLength--)
                result[i] = upperStr[i];

            for(int k=1;!lowerStr.empty() && digitLength >0; digitLength--,k++)
            {
                result[result.length()-k] = lowerStr.back();
                lowerStr.pop_back();
            }

            return result + "e" + to_string(trailing);
        }
        else
        {

           string result = to_string(lower);
           return to_string(upperInt) + "..." + string(5-result.size(),'0') + result  + "e" + to_string(trailing);
        }
    }
};
