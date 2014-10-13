class Solution {
public:
    string simplifyPath(string path) {
        int count = 1;
        int size = path.size();
        string result;
        while(count < size)
        {
            int end = count;
            while(path[end] != '/' && end < size)
            {
                ++end;
            }
            // if(end == count)
            // {
            //     count = end+1;
            // }
            if(end == count +1)
            {
                if(path[count] != '.')
                {
                    result += "/"+path.substr(count, end - count);
                }
                //count = end+1;
            }
            else if(end == count +2)
            {
                if(path[count] == '.' && path[count+1] == '.')
                {
                    int tmpSize = result.size();
                    while(tmpSize >= 1 && result[tmpSize-1] != '/')
                    {
                        tmpSize--;
                    }
                    if(tmpSize >= 1)
                    {
                    	tmpSize--;
                    }
                    result.resize(tmpSize);
                }
                else
                {
                    result += "/"+path.substr(count, end - count);
                }
                //count = end+1;
            }
            else if (end > count +2)
            {
                result += "/"+path.substr(count, end - count);
            }
            count = end+1;
        }
        if(result.size() == 0)
        {
            result+='/';
        }
        return result;
    }
};
