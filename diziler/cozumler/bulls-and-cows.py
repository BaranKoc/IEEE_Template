class Solution:

    def getHint(self, secret: str, guess: str) -> str:
        bulls = cows = 0
        secretCopy = list(secret)
        guessCopy = list(guess)
        for i in range(len(secret)):
            if secret[i] == guess[i]:
                bulls += 1
                secretCopy.pop(secretCopy.index(secret[i]))
                guessCopy.pop(guessCopy.index(guess[i]))
        secretCounter = Counter(secretCopy)
        guessCounter = Counter(guessCopy)
        dif = secretCounter - (secretCounter - guessCounter)
        cows = dif.total()
        return f'{bulls}A{cows}B'
