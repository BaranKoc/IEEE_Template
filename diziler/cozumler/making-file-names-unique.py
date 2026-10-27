class Solution:

    def getFolderNames(self, names: List[str]) -> List[str]:
        hashmap = {}
        for name in names:
            modified = name
            if name in hashmap:
                k = hashmap[name]
                while modified in hashmap:
                    k += 1
                    modified = f'{name}({k})'
                hashmap[name] = k
            hashmap[modified] = 0
        return hashmap.keys()
