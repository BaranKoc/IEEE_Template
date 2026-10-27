class Solution {
public:

    bool isUpper(char ch) {
        return ch >= 65 && ch <= 90;
    }

    bool isLower(char ch) {
        return ch >= 97 && ch <= 122;
    }

    bool isLetter(char ch) {
        return isUpper(ch) || isLower(ch);
    }

    bool isNumber(char ch) {
        return ch >= 48 && ch <= 57;
    }

    void addKey(map<string, long int>& count, string key, long int value) {
        if(count.find(key) != count.end()) {
            count[key] = count[key] + value;
        }
        else {
            count[key] = value;
        }
    }

    string buildName(string formula, int& i) {
        string name = "";
        name.push_back(formula[i]);
        if(isUpper(formula[i])) {
            return name;
        }
        if(i == formula.length()-1) {
            return name;
        }
        while(isLower(formula[i-1])) {
            name.push_back(formula[i-1]);
            i--;
        }
        name.push_back(formula[i-1]);
        i--;
        reverse(name.begin(), name.end());
        return name;
     }

    long int buildCount(string formula, int& i, vector<long int>& stack) {
        long int num = formula[i] - '0';
        long int place = 1;
        if(i == 0) {
            return num;
        }
        while(isNumber(formula[i-1])) {
            place = place * 10;
            num = (formula[i-1]-'0') * place + num;
            i--;
        }
        return num;
    }

    string countOfAtoms(string formula) {
        string ans;
        map<string, long int> count;
        vector<long int> stack;
        long int factor = 1;
        string name = "";
        long int num = -1;

        int i = formula.length()-1;
        while (i >= 0) {

            if(formula[i] == ')') {
                if(i+1 <= formula.length()-1 && isNumber(formula[i+1])) {
                    stack.push_back(num);
                    factor = factor * num;
                    num = -1;
                }
                else {
                    stack.push_back(1);
                }
            }

            else if(formula[i] == '(') {
                factor = factor / stack.back();
                stack.pop_back();
            }

            else if(isLetter(formula[i])) {
                name = buildName(formula, i);
                if(num == -1) {
                    addKey(count, name, 1 * factor);
                }
                else {
                    addKey(count, name, num * factor);
                }
                num = -1;
            }
            else if(isNumber(formula[i])) {
                num = buildCount(formula, i, stack);
            }
            i--;
        }

        map<string, long int>::iterator it;
        for (it = count.begin(); it != count.end(); it++)
        {
            ans = ans + it->first;
            if(it->second != 1) {
                ans = ans + to_string(it->second);
            }
        }
        return ans;
    }
};
