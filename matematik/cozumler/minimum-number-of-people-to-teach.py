class Solution:

    def minimumTeachings(self, n: int, languages: List[List[int]], friendships: List[List[int]]) -> int:
        need_to_be_taught = set()
        languages = [set(language) for language in languages]
        for user1, user2 in friendships:
            user1 = user1 - 1
            user2 = user2 - 1
            if not languages[user1] & languages[user2]:
                need_to_be_taught.update([user1, user2])
        if not need_to_be_taught:
            return 0
        language_spoken_by = collections.defaultdict(int)
        for user in need_to_be_taught:
            for language in languages[user]:
                language_spoken_by[language] += 1
        popular_language_count = max(language_spoken_by.values())
        return len(need_to_be_taught) - popular_language_count
