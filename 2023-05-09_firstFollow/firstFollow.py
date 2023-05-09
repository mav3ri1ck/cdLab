# Given Grammar
grammar = {
    "A": ["aAbA"],
    "B": ["bBaB"],
}


# Dictionaries to store first and follow for each symbol 
first = {}
follow = {}


# Check if concerned symbol is terminal or not
def isTerminal(symbol):
    return symbol.islower()


# Calculate the first for a given symbol
def compute_first(symbol):
    # If isLower then terminal, so print terminal as first
    # If isUpper then non-terminal, call first(non-terminal)
    if isTerminal(symbol):
        return set(symbol);


    # Set to store all the terminals present in first[symbol]
    first_set = set()


    # For every rule present in the array of rules for the symbol
    # Check if the first symbol in the rule is a terminal
    # That is calculate the first(sub_symbol)
    # Update first_set to be first_set union sub_first_set
    # if 'epsilon' is present in first(sub_symbol), calculate first for next sub_symbol
    # else break
    for rule in grammar[symbol]:
        for sub_symbol in rule:
            sub_first_set = compute_first(sub_symbol)
            first_set.update(sub_first_set)

            if 'epsilon' not in sub_first_set:
                break
    return first_set



# Calculate the follow for a given symbol
def compute_follow(symbol):
    # Initialize follow_set to be a new empty set
    follow_set = set()

    # For Start Symbol, add $ to follow(S)
    if symbol == "S":
        follow_set.add("$")
    

    # For left_symbol(the non-terminal), and its right_rules(productions) 
    for left_symbol, right_rules in grammar.items():

        # For each production in productions
        for right_rule in right_rules:

            # If the non-terminal(symbol) for which follow is computed
            # is present on the right side of any production
            # get the index of the symbol
            if symbol in right_rule:
                symbol_index = right_rule.index(symbol)

                # If the index is not at the end, compute first of (index+1)
                if symbol_index < len(right_rule)-1:
                    sub_follow_set = compute_first(right_rule[symbol_index + 1])

                    # If epsilon present in set, find first(left_symbol)
                    if "epsilon" in sub_follow_set:
                        sub_follow_set.remove("epsilon")
                        sub_follow_set.update(compute_follow(left_symbol))
                    
                    # follow_set = follow_set union sub_follow_set
                    follow_set.update(sub_follow_set)
                else:
                    follow_set.update(compute_follow(left_symbol))
    return follow_set

    

# Fill up the first dictionary
for symbol in grammar.keys():
    first[symbol] = compute_first(symbol)


# Fill up the first dictionary
for symbol in grammar.keys():
    follow[symbol] = compute_follow(symbol)



print(first)
print(follow)