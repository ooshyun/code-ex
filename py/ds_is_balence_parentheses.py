def balancedParenthesesinExpression(expression: str):
    """
    The type of bracket

        squggles = ("{", "}")
        brockets = ("[", "]")
        parens = ("(", ")")

    Algorithm
    -----------
    1. open term
        1.1.1. stack

    2. close term
        1.2.1. pop == a pair of char / empty?
    
    3.return empty?        

    Return
    --------
    True : Balenced
    False: Unbalenced
    """
    basket = (("{","}"), ("[","]"), ("(",")"))
    stack = []
    def _find_open(char: str):
        for i in range(3):
            if basket[i][0] == char:
                return True
        return False
    
    def is_match(x, y):
        for i in range(3):
            if basket[i][0] == x:
                return basket[i][1] == y
        return False
    
    def is_empty(stack):
        return len(stack) < 1
        
    def is_balanced():
        for char in expression:                      
            if  _find_open(char):
                stack.append(char)
            else:
                if is_empty(stack) or (not is_match(stack.pop(-1), char)):
                    return False
        return is_empty(stack)
        
    return is_balanced()
                
def testBalancedParenthesesinExpression():
    expression = '{()[{({})[]()}]}([])'
    print(f"Got {expression}")
    print(f"Balanced? {balancedParenthesesinExpression(expression)}")
    print("-"*10)

    expression = '{()[{({})[]()}]}([]'
    print(f"Got {expression}")
    print(f"Balanced? {balancedParenthesesinExpression(expression)}")
    print("-"*10)
    
    expression = '{()[{({})[]()}]}([])/'
    print(f"Got {expression}")
    print(f"Balanced? {balancedParenthesesinExpression(expression)}")
    print("-"*10)

if __name__=="__main__":
    # 1. Balanced parentheses in expression
    testBalancedParenthesesinExpression()
