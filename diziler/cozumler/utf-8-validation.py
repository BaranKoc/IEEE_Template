class Solution:

    def validUtf8(self, data: List[int]) -> bool:
        cont_bytes_left = 0
        for byte in data:
            if cont_bytes_left == 0:
                if byte >> 5 == 6:
                    cont_bytes_left = 1
                elif byte >> 4 == 14:
                    cont_bytes_left = 2
                elif byte >> 3 == 30:
                    cont_bytes_left = 3
                elif byte >> 7 != 0:
                    return False
            else:
                if byte >> 6 != 2:
                    return False
                cont_bytes_left -= 1
        return cont_bytes_left == 0
