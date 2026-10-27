class Solution:
    MOD = 10 ** 9 + 7

    def knightDialer(self, n: int) -> int:
        cur_pos = [1] * 10
        for jump in range(2, n + 1):
            new_pos = [0] * 10
            new_pos[0] = (cur_pos[6] + cur_pos[4]) % self.MOD
            new_pos[1] = (cur_pos[6] + cur_pos[8]) % self.MOD
            new_pos[2] = (cur_pos[7] + cur_pos[9]) % self.MOD
            new_pos[3] = (cur_pos[4] + cur_pos[8]) % self.MOD
            new_pos[4] = (cur_pos[0] + cur_pos[3] + cur_pos[9]) % self.MOD
            new_pos[5] = 0
            new_pos[6] = (cur_pos[0] + cur_pos[1] + cur_pos[7]) % self.MOD
            new_pos[7] = (cur_pos[2] + cur_pos[6]) % self.MOD
            new_pos[8] = (cur_pos[1] + cur_pos[3]) % self.MOD
            new_pos[9] = (cur_pos[2] + cur_pos[4]) % self.MOD
            cur_pos = new_pos
        total_count = sum(cur_pos) % self.MOD
        return total_count
