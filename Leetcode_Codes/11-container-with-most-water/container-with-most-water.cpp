class Solution {
public:
    int maxArea(vector<int>& height) {
        // here a, b is location on the array

        int x1 = 0,x2 = height.size()-1; //location on the array
        int y1, y2;//height of the container/array val
        int max_area = 0;// keep track of max water stored
        while(x1 < x2){
            y1= height[x1];
            y2= height[x2];
            int area = min_area(x1,x2,y1,y2);
            
            // record and update max area
            if(area > max_area)max_area = area;

            // increments
            //note::cover == case 
            if(y1<= y2) x1++;
            else if(y1 > y2) x2--;
        }

        return max_area;
    }
    int min_area(int x1,int x2, int y1, int y2){
        // fix y to one which is smallest as we find the max possibe area without any slants
        int b;
        if(y1<= y2)b= y1;
        else b = y2;
        int l = x2-x1;
        int area = l * b;
        return area;
    }
};