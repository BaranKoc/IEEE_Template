class StockPrice {
    map<int, int> stock;
    map<int, int> prices;
    pair<int, int> currentStock = {-1, -1};
public:

    StockPrice() {

    }

    void update(int timestamp, int price) {

        if(timestamp >= currentStock.first) {
            currentStock = {timestamp, price};
        }

        if(stock.find(timestamp) != stock.end()) {

            int old_price = stock[timestamp];

            prices[old_price]--;
            if(prices[old_price] == 0) prices.erase(old_price);
        }

        prices[price]++;
        stocks[timestamp] = price;

    }

    int current() {
        return currentStock.second;
    }

    int maximum() {
			return prices.rbegin()->first;
    }

    int minimum() {
        return prices.begin()->first;
    }
};
