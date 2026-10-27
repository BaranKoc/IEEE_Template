class Solution {
public:
    string maximumBinaryString(string binary) {
        int n = binary.size();
        int z_count=0;
        int z_index=-1;
        for(int i=n-1;i>=0;i--) {
         if(binary[i]=='0') {
             z_count++;
             z_index = i;
             binary[i] = '1';
         }
        }
        if(z_index!=-1)
        {
            binary[z_index+z_count-1] = '0';

        }
        return binary;
    }
};
