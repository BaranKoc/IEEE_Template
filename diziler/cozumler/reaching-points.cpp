class Solution
{
public:

    bool reachingPoints_recursive(int sx, int sy, int tx, int ty)
    {
        if (sx > tx ||  sy > ty)
        {
            return false;
        }

        if (sx == tx && sy == ty)
        {
            return true;
        }

        bool canReach = reachingPoints_recursive(sx, sx+sy, tx, ty);
        if (!canReach)
        {
            canReach = reachingPoints_recursive(sx+sy, sy, tx, ty);
        }

        return canReach;
    }

    bool reachingPoints_internal(int sx, int sy, int tx, int ty)
    {
        if (sx > tx || sy > ty)
        {
            return false;
        }
        else if (sx == tx && sy == ty)
        {
            return true;
        }

        while (tx > sx && ty > sy)
        {
            if (tx > ty)
            {

                tx = tx % ty;
            }
            else
            {

                ty = ty % tx;
            }
        }

        if ((tx == sx) && ((ty - sy) % sx == 0) )
        {
            return true;
        }
        else if ((ty == sy) && ((tx - sx) % sy == 0))
        {
            return true;
        }

        return false;
    }

    bool reachingPoints(int sx, int sy, int tx, int ty)
    {

        return reachingPoints_internal(sx, sy, tx, ty);
    }
};
