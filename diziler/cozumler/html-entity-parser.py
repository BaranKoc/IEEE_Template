class Solution:

    def entityParser(self, text: str) -> str:
        d = {'&quot;': '"', '&apos;': "'", '&amp;': '&', '&gt;': '>', '&lt;': '<', '&frasl;': '/'}
        ans = ''
        i = 0
        while i < len(text):
            bag = ''
            if i + 1 < len(text) and text[i] == '&' and (text[i + 1] != '&'):
                for j in range(i, len(text)):
                    if text[j] == ';':
                        bag += text[j]
                        break
                    else:
                        bag += text[j]
                if bag not in d:
                    ans += bag
                else:
                    ans += d[bag]
                i += len(bag)
            else:
                ans += text[i]
                i += 1
        return ans
