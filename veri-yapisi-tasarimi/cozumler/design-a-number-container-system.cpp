class NumberContainers {
public:
    map<int, int> indexToNumber;
    map<int, set<int>>numberToIndex;
    NumberContainers() {}

    void change(int index, int number) {

        if (!indexToNumber.count(index)) {
            numberToIndex[number].insert(index);
            indexToNumber[index] = number;
        }
        else {

            int num = indexToNumber[index];

            numberToIndex[num].erase(index);
            if (numberToIndex[num].empty()) numberToIndex.erase(num);

            numberToIndex[number].insert(index);
            indexToNumber[index] = number;
        }
    }

    int find(int number) {
        if (!numberToIndex.count(number)) return -1;

        return *numberToIndex[number].begin();
    }
};
