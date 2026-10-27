class Solution:
    import string
    from collections import Counter

    def mostCommonWord(self, paragraph: str, banned: List[str]) -> str:
        para = paragraph.translate(str.maketrans(',', ' '))
        para = para.translate(str.maketrans(' ', ' ', string.punctuation)).lower()
        para = para.split()
        para_count = Counter(para)
        for word in banned:
            if word in para_count:
                para_count.pop(word)
        return para_count.most_common(1)[0][0]
