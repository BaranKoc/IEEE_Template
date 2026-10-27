import sortedcontainers as sc

class MovieRentingSystem:

    def __init__(self, n: int, entries: List[List[int]]):
        self.rented = sc.SortedList()
        self.movies = {}
        self.movie_and_shop_to_price = {}
        for shop, movie, price in entries:
            if movie not in self.movies:
                self.movies[movie] = sc.SortedList()
            self.movies[movie].add((price, shop))
            self.movie_and_shop_to_price[movie, shop] = price

    def search(self, movie: int) -> List[int]:
        if movie not in self.movies:
            return []
        return [x[1] for x in self.movies[movie][:5]]

    def rent(self, shop: int, movie: int) -> None:
        my_price = self.movie_and_shop_to_price[movie, shop]
        self.rented.add((my_price, shop, movie))
        self.movies[movie].remove((my_price, shop))

    def drop(self, shop: int, movie: int) -> None:
        my_price = self.movie_and_shop_to_price[movie, shop]
        self.rented.remove((my_price, shop, movie))
        self.movies[movie].add((my_price, shop))

    def report(self) -> List[List[int]]:
        return [x[1:] for x in self.rented[:5]]
