
def coin_change(n, coins):
    """Finds minimum change for n"""
    
    min_coins = [0] * (n+1)

    for i in range(1, n+1):
        if i in coins:
            min_coins[i] = 1
        else:
            possible = []
            for c in coins:
                if i - c > 0:
                    possible.append(1 + min_coins[i - c])
            min_coins[i] = min(possible)

    return min_coins[n]
    

if __name__ == "__main__":
    n = 35
    coins = [1, 5, 10]

    print(f"n={n}, coins={coins}")
    print(f"{coin_change(n, coins)} coin(s)")
