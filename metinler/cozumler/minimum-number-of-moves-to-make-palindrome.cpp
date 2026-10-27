class Solution {
public:
	int minMovesToMakePalindrome(string s) {
		int len = s.length();
		string strArr = s;
		int steps = 0;
		int l = 0, r = len-1;

		while(l < r){
			if(strArr[l] == strArr[r]){
				l++; r--;
			}else{
				int k = r;
				k = findKthIndexMatchingwithLthIndex(strArr, l, k);

				if(k == l){
					swap(strArr[l], strArr[l+1]);
					steps++;
				}else{
					while(k < r){
						swap(strArr[k], strArr[k+1]);
						steps++;
						k++;
					}
					l++; r--;
				}
			}

		}
		return steps;
	}

	int findKthIndexMatchingwithLthIndex(string strArr, int l, int k){
		while(k > l){
			if(strArr[k] == strArr[l]){  return k;  }
			k--;
		}
		return k;
	}
};
