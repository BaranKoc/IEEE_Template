class Solution:

    def countOfAtoms(self, formula: str) -> str:
        stack, elem, i = ([{}], '', 0)
        while i < len(formula):
            if formula[i].isupper():
                j = i + 1
                while j < len(formula) and formula[j].islower():
                    j += 1
                elem = formula[i:j]
                i = j
                if i == len(formula) or (not formula[i].isdigit() and (not formula[i].islower())):
                    stack[-1][elem] = stack[-1].get(elem, 0) + 1
            elif formula[i].isdigit():
                j = i
                while j < len(formula) and formula[j].isdigit():
                    j += 1
                count = int(formula[i:j])
                stack[-1][elem] = stack[-1].get(elem, 0) + count
                i = j
            elif formula[i] == '(':
                stack.append({})
                i += 1
            elif formula[i] == ')':
                i += 1
                j = i
                while j < len(formula) and formula[j].isdigit():
                    j += 1
                multiplier = int(formula[i:j] or 1)
                top = stack.pop()
                for elem, count in top.items():
                    stack[-1][elem] = stack[-1].get(elem, 0) + count * multiplier
                i = j
        atoms = sorted(stack[0].items())
        return ''.join([atom + (str(count) if count > 1 else '') for atom, count in atoms])
